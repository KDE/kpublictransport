/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "platformfinder.h"

#include <loader/mapdata.h>

using namespace KOSMIndoorMap;

PlatformFinder::PlatformFinder()
{
    m_collator.setLocale(QLocale());
    m_collator.setNumericMode(true);
    m_collator.setIgnorePunctuation(true);
    m_collator.setCaseSensitivity(Qt::CaseInsensitive);
}

PlatformFinder::~PlatformFinder() = default;

std::vector<Platform> PlatformFinder::find(const MapData *data)
{
    m_data = data;
    resolveTagKeys();

    for (auto it = m_data->m_levelMap.begin(); it != m_data->m_levelMap.end(); ++it) {
        for (const auto &e : (*it).second) {
            if (e.type() == OSM::Type::Node) {
                continue;
            }
            const auto railway = e.tagValue(m_tagKeys.railway);
            if (railway == "platform") {
                const auto names = QString::fromUtf8(e.tagValue("local_ref", "ref")).split(QLatin1Char(';'));
                for (const auto &name : names) {
                    Platform platform;
                    platform.setArea(e);
                    platform.setName(name);
                    platform.setLevel(qRound((*it).first.numericLevel() / 10.0) * 10);
                    // we delay merging of platforms, as those without track names would
                    // otherwise cobble together two distinct edges when merged to early
                    m_platformAreas.push_back(std::move(platform));
                }
            }
            else if (railway == "platform_edge" && e.type() == OSM::Type::Way) {
                Platform platform;
                platform.setEdge(e);
                platform.setName(QString::fromUtf8(e.tagValue("local_ref", "ref")));
                platform.setLevel(qRound((*it).first.numericLevel() / 10.0) * 10);
                addPlatform(std::move(platform));
            }
            else if (!railway.isEmpty() && e.type() == OSM::Type::Way) {
                OSM::for_each_node(m_data->dataSet(), *e.way(), [&](const auto &node) {
                    if (!OSM::contains(m_data->boundingBox(), node.coordinate)) {
                        return;
                    }
                    if (OSM::tagValue(node, m_tagKeys.railway) == "buffer_stop") {
                        return;
                    }

                    const auto pt = OSM::tagValue(node, m_tagKeys.public_transport);
                    if (pt == "stop_point" || pt == "stop_position") {
                        Platform platform;
                        platform.setStopPoint(OSM::Element(&node));
                        platform.setTrack(e);
                        platform.setLevel(qRound((*it).first.numericLevel() / 10.0) * 10);
                        platform.setName(QString::fromUtf8(platform.stopPoint().tagValue("local_ref", "ref", "name")));

                        if (railway == "rail" || railway == "light_rail") {
                            platform.mode = Platform::Rail;
                        } else if (railway == "subway") {
                            platform.mode = Platform::Subway;
                        } else if (railway == "tram") {
                            platform.mode = Platform::Tram;
                        } else {
                            return;
                        }

                        addPlatform(std::move(platform));
                    }
                });
            }
        }
    }

    OSM::for_each(m_data->dataSet(), [this](OSM::Element e) {
        const auto route = e.tagValue(m_tagKeys.route);
        if (route.isEmpty() || route == "tracks") {
            return;
        }
        scanRoute(e, e);
    }, OSM::IncludeRelations);

    for (auto &p : m_platformAreas) {
        addPlatformArea(std::move(p));
    }
    m_platformAreas.clear();

    finalizeResult();
    return std::move(m_platforms);
}

void PlatformFinder::resolveTagKeys()
{
    m_tagKeys.public_transport = m_data->dataSet().tagKey("public_transport");
    m_tagKeys.railway = m_data->dataSet().tagKey("railway");
    m_tagKeys.route = m_data->dataSet().tagKey("route");
}

void PlatformFinder::scanRoute(OSM::Element e, OSM::Element route)
{
    switch (e.type()) {
        case OSM::Type::Null:
            return;
        case OSM::Type::Node:
            scanRoute(*e.node(), route);
            break;
        case OSM::Type::Way:
            OSM::for_each_node(m_data->dataSet(), *e.way(), [this, route](const OSM::Node &node) {
                scanRoute(node, route);
            });
            break;
        case OSM::Type::Relation:
            OSM::for_each_member(m_data->dataSet(), *e.relation(), [this, route](OSM::Element e) {
                scanRoute(e, route);
            });
            break;
    }
}

void PlatformFinder::scanRoute(const OSM::Node& node, OSM::Element route)
{
    const auto pt = OSM::tagValue(node, m_tagKeys.public_transport);
    if (pt.isEmpty()) {
        return;
    }

    for (auto &p : m_platforms) {
        if (p.stopPoint().id() == node.id) {
            const auto l = QString::fromUtf8(route.tagValue("ref")).split(QLatin1Char(';'));
            for (const auto &lineName : l) {
                if (lineName.isEmpty()) {
                    continue;
                }
                const auto it = std::lower_bound(p.lines.begin(), p.lines.end(), lineName, m_collator);
                if (it == p.lines.end() || (*it) != lineName) {
                    p.lines.insert(it, lineName);
                }
            }
            break;
        }
    }
}

void PlatformFinder::addPlatform(Platform &&platform)
{
    for (Platform &p : m_platforms) {
        if (Platform::isSame(p, platform, m_data->dataSet())) {
            p = Platform::merge(p, platform);
            return;
        }
    }

    m_platforms.push_back(std::move(platform));
}

void PlatformFinder::addPlatformArea(Platform &&platform)
{
    bool found = false;
    for (Platform &p : m_platforms) {
        if (Platform::isSame(p, platform, m_data->dataSet())) {
            p = Platform::merge(p, platform);
            found = true;
        }
    }

    if (!found) {
        m_platforms.push_back(std::move(platform));
    }
}

void PlatformFinder::finalizeResult()
{
    m_platforms.erase(std::remove_if(m_platforms.begin(), m_platforms.end(), [](const auto &p) { return !p.isValid(); }), m_platforms.end());

    std::sort(m_platforms.begin(), m_platforms.end(), [this](const auto &lhs, const auto &rhs) {
        if (lhs.mode == rhs.mode) {
            if (lhs.name() == rhs.name()) {
                return lhs.stopPoint().id() < rhs.stopPoint().id();
            }
            return m_collator.compare(lhs.name(), rhs.name()) < 0;
        }
        return lhs.mode < rhs.mode;
    });
}
