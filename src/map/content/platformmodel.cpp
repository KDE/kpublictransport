/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "platformmodel.h"

#include <KOSMIndoorMap/MapData>

#include <QCollator>
#include <QPointF>

using namespace KOSMIndoorMap;

QCollator PlatformModel::m_collator;

PlatformModel::PlatformModel(QObject* parent) :
    QAbstractListModel(parent)
{
    m_collator.setLocale(QLocale());
    m_collator.setNumericMode(true);
    m_collator.setIgnorePunctuation(true);
    m_collator.setCaseSensitivity(Qt::CaseInsensitive);
}

PlatformModel::~PlatformModel() = default;

MapData* PlatformModel::mapData() const
{
    return m_data;
}

void PlatformModel::setMapData(MapData* data)
{
    // ### do not check for m_data != data, this does not actually change!
    beginResetModel();
    m_platforms.clear();
    m_data = data;
    populateModel();
    endResetModel();
    emit mapDataChanged();
    matchPlatforms();
}

bool PlatformModel::isEmpty() const
{
    return rowCount() == 0;
}

int PlatformModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_platforms.size();
}

QVariant PlatformModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return {};
    }

    const auto &platform = m_platforms[index.row()];
    switch (role) {
        case Qt::DisplayRole:
            return platform.name();
        case CoordinateRole:
            return QPointF(platform.position().lonF(), platform.position().latF());
        case ElementRole:
            return QVariant::fromValue(platform.stopPoint());
        case LevelRole:
            return platform.level();
        case TransportModeRole:
            return platform.mode;
        case LinesRole:
            return platform.lines;
        case ArrivalPlatformRole:
            return index.row() == m_arrivalPlatformRow;
        case DeparturePlatformRole:
            return index.row() == m_departurePlatformRow;
    }

    return {};
}

QHash<int, QByteArray> PlatformModel::roleNames() const
{
    auto n = QAbstractListModel::roleNames();
    n.insert(CoordinateRole, "coordinate");
    n.insert(ElementRole, "osmElement");
    n.insert(LevelRole, "level");
    n.insert(TransportModeRole, "mode");
    n.insert(LinesRole, "lines");
    n.insert(ArrivalPlatformRole, "isArrivalPlatform");
    n.insert(DeparturePlatformRole, "isDeparturePlatform");
    return n;
}

void PlatformModel::populateModel()
{
    if (!m_data) {
        return;
    }

    const auto railwayKey = m_data->dataSet().tagKey("railway");
    m_ptKey = m_data->dataSet().tagKey("public_transport");
    if (m_ptKey.isNull() && railwayKey.isNull()) {
        return;
    }

    for (auto it = m_data->m_levelMap.begin(); it != m_data->m_levelMap.end(); ++it) {
        for (const auto &e : (*it).second) {
            if (e.type() == OSM::Type::Node || e.type() == OSM::Type::Relation) {
                continue;
            }
            const auto railway = e.tagValue(railwayKey);
            if (!railway.isEmpty()) {
                OSM::for_each_node(m_data->dataSet(), *e.way(), [&](const auto &node) {
                    if (!OSM::contains(m_data->boundingBox(), node.coordinate)) {
                        return;
                    }
                    if (OSM::tagValue(node, railwayKey) == "buffer_stop") {
                        return;
                    }

                    const auto pt = OSM::tagValue(node, m_ptKey);
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

    const auto routeKey = m_data->dataSet().tagKey("route");
    OSM::for_each(m_data->dataSet(), [this, routeKey](OSM::Element e) {
        const auto route = e.tagValue(routeKey);
        if (route.isEmpty() || route == "tracks") {
            return;
        }
        scanRoute(e, e);
    }, OSM::IncludeRelations);

    qDebug() << m_platforms.size() << "platforms found";
}

void PlatformModel::scanRoute(OSM::Element e, OSM::Element route)
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

void PlatformModel::scanRoute(const OSM::Node& node, OSM::Element route)
{
    const auto pt = OSM::tagValue(node, m_ptKey);
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

void PlatformModel::addPlatform(Platform &&platform)
{
    if (platform.name().isEmpty()) {
        return;
    }

    auto it = std::lower_bound(m_platforms.begin(), m_platforms.end(), platform, comparePlatform);
    if (it != m_platforms.end() && (*it).stopPoint().id() == platform.stopPoint().id()) {
        // already present
        return;
    }

    // look for other stops on the same track we can merge with (and that might have better names)
    const auto newRef = platform.stopPoint().tagValue("local_ref", "ref");
    for (auto &p : m_platforms) {
        if (p.track() == platform.track()) {
            const auto oldRef = p.stopPoint().tagValue("local_ref", "ref");
            if (oldRef.isEmpty() && !newRef.isEmpty()) {
                p = platform;
                std::sort(m_platforms.begin(), m_platforms.end(), comparePlatform);
                return;
            } else if (newRef.isEmpty()) {
                return;
            }
        }
    }

    m_platforms.insert(it, std::move(platform));
}

bool PlatformModel::comparePlatform(const Platform &lhs, const Platform &rhs)
{
    if (lhs.mode == rhs.mode) {
        if (lhs.name() == rhs.name()) {
            return lhs.stopPoint().id() < rhs.stopPoint().id();
        }
        return m_collator.compare(lhs.name(), rhs.name()) < 0;
    }
    return lhs.mode < rhs.mode;
}

void PlatformModel::setArrivalPlatform(const QString &name, Platform::Mode mode)
{
    m_arrivalPlatform.setName(name);
    m_arrivalPlatform.mode = mode;
    matchPlatforms();
}

void PlatformModel::setDeparturePlatform(const QString &name, Platform::Mode mode)
{
    m_departurePlatform.setName(name);
    m_departurePlatform.mode = mode;
    matchPlatforms();
}

int PlatformModel::arrivalPlatformRow() const
{
    return m_arrivalPlatformRow;
}

int PlatformModel::departurePlatformRow() const
{
    return m_departurePlatformRow;
}

void PlatformModel::matchPlatforms()
{
    m_arrivalPlatformRow = matchPlatform(m_arrivalPlatform);
    m_departurePlatformRow = matchPlatform(m_departurePlatform);
    emit platformIndexChanged();
    if (m_arrivalPlatformRow >= 0) {
        emit dataChanged(index(m_arrivalPlatformRow, 0), index(m_arrivalPlatformRow, 0));
    }
    if (m_departurePlatformRow >= 0) {
        emit dataChanged(index(m_departurePlatformRow, 0), index(m_departurePlatformRow, 0));
    }
}

int PlatformModel::matchPlatform(const Platform &platform) const
{
    if (platform.name().isEmpty()) {
        return -1;
    }

    int i = 0;
    for (const auto &p : m_platforms) {
        if (p.name() == platform.name() && p.mode == platform.mode) { // TODO this needs to be a bit more complex to also handle platform section
            return i;
        }
        ++i;
    }
    return -1;
}

#include "moc_platformmodel.cpp"
