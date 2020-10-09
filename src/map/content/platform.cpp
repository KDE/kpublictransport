/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "platform.h"

#include <osm/geomath.h>
#include <osm/pathutil.h>

#include <QRegularExpression>

using namespace KOSMIndoorMap;

bool PlatformSection::isValid() const
{
    return !name.isEmpty() && position;
}


Platform::Platform() = default;
Platform::~Platform() = default;

bool Platform::isValid() const
{
    return !m_name.isEmpty() && position().isValid() && m_mode != Unknown;
}

QString Platform::name() const
{
    return m_name;
}

void Platform::setName(const QString &name)
{
    m_name = name;
}

int Platform::level() const
{
    return hasLevel() ? m_level : 0;
}

bool Platform::hasLevel() const
{
    return m_level != std::numeric_limits<int>::min();
}

void Platform::setLevel(int level)
{
    m_level = level;
}

OSM::Coordinate Platform::position() const
{
    return OSM::coalesce(m_stopPoint, m_area).center();
}

OSM::Element Platform::stopPoint() const
{
    return m_stopPoint;
}

void Platform::setStopPoint(OSM::Element stop)
{
    m_stopPoint = stop;
}

OSM::Element Platform::edge() const
{
    return OSM::coalesce(m_edge, m_stopPoint);
}

void Platform::setEdge(OSM::Element edge)
{
    m_edge = edge;
}

OSM::Element Platform::area() const
{
    return OSM::coalesce(m_area, m_edge, m_stopPoint);
}

void Platform::setArea(OSM::Element area)
{
    m_area = area;
}

const std::vector<OSM::Element>& Platform::track() const
{
    return m_track;
}

void Platform::setTrack(std::vector<OSM::Element> &&track)
{
    m_track = std::move(track);
}

std::vector<OSM::Element>&& Platform::takeTrack()
{
    return std::move(m_track);
}

const std::vector<PlatformSection>& Platform::sections() const
{
    return m_sections;
}

void Platform::setSections(std::vector<PlatformSection> &&sections)
{
    m_sections = std::move(sections);
}

std::vector<PlatformSection>&& Platform::takeSections()
{
    return std::move(m_sections);
}

Platform::Mode Platform::mode() const
{
    return m_mode;
}

void Platform::setMode(Platform::Mode mode)
{
    m_mode = mode;
}

static bool conflictIfPresent(OSM::Element lhs, OSM::Element rhs)
{
    return lhs && rhs && lhs != rhs;
}

static bool equalIfPresent(OSM::Element lhs, OSM::Element rhs)
{
    return lhs && rhs && lhs == rhs;
}

static bool isSubPath(const std::vector<const OSM::Node*> &path, const OSM::Way &way)
{
    return std::all_of(way.nodes.begin(), way.nodes.end(), [&path](OSM::Id node) {
        return std::find_if(path.begin(), path.end(), [node](auto n) { return n->id == node; }) != path.end();
    });
}

static constexpr const auto MAX_TRACK_TO_EDGE_DISTANCE = 4.5; // meters
static constexpr const auto MAX_SECTION_TO_EDGE_DISTANCE = 5.0;

static double maxSectionDistance(const std::vector<const OSM::Node*> &path, const std::vector<PlatformSection> &sections)
{
    auto dist = std::numeric_limits<double>::lowest();
    for (const auto &section : sections) {
        dist = std::max(dist, OSM::distance(path, section.position.center()));
    }
    return dist;
}

double Platform::maxSectionDistance(const Platform &p, const std::vector<PlatformSection> &sections, const OSM::DataSet &dataSet)
{
    if (auto elem = OSM::coalesce(p.m_edge, p.m_area)) {
        return ::maxSectionDistance(elem.outerPath(dataSet), sections);
    }
    if (!p.m_track.empty()) {
        std::vector<const OSM::Node*> path;
        OSM::assemblePath(dataSet, p.m_track, path);
        return ::maxSectionDistance(path, sections);
    }
    return std::numeric_limits<double>::lowest();
}

static const OSM::Way* outerWay(OSM::Element &multiPolygon, const OSM::DataSet &dataSet)
{
    // ### this assumes multi-polygons are structured in the way the Marble generator normalizes them!
    for (const auto &mem : multiPolygon.relation()->members) {
        if (mem.type() == OSM::Type::Way && (std::strcmp(mem.role().name(), "outer") == 0)) {
            return dataSet.way(mem.id);
        }
    }
    return nullptr;
}

static bool isConnectedGeometry(OSM::Element lhs, OSM::Element rhs, const OSM::DataSet &dataSet)
{
    if (lhs == rhs) { return false; }
    const OSM::Way *lway = nullptr;
    const OSM::Way *rway = nullptr;

    switch (lhs.type()) {
        case OSM::Type::Null:
        case OSM::Type::Node:
            return false;
        case OSM::Type::Way:
            lway = lhs.way();
            break;
        case OSM::Type::Relation:
            lway  = outerWay(lhs, dataSet);
            break;

    }
    switch (rhs.type()) {
        case OSM::Type::Null:
        case OSM::Type::Node:
            return false;
        case OSM::Type::Way:
            rway = rhs.way();
            break;
        case OSM::Type::Relation:
            rway = outerWay(rhs, dataSet);
            break;
    }
    if (!lway || !rway) {
        return false;
    }

    if (!lway->isClosed() && !rway->isClosed()) {
        return lway->nodes.front() == rway->nodes.front()
            || lway->nodes.back() == rway->nodes.front()
            || lway->nodes.front() == rway->nodes.back()
            || lway->nodes.back() == rway->nodes.back();
    }
    if (lway->isClosed() && lway->nodes.size() > 2 && rway->isClosed() && rway->nodes.size() > 2) {
        // ### this assumes multi-polygons are structured in the way the Marble generator normalizes them!
        bool found = false;
        for (std::size_t i = 0; i < lway->nodes.size() && !found; ++i) {
            const auto n1 = lway->nodes[i];
            const auto n2 = lway->nodes[(i + 1) % lway->nodes.size()];
            for (std::size_t j = 0; j < rway->nodes.size() && !found; ++j) {
                found = ((n1 == rway->nodes[j]) && (n2 == rway->nodes[(j + 1) % rway->nodes.size()]))
                     || ((n2 == rway->nodes[j]) && (n1 == rway->nodes[(j + 1) % rway->nodes.size()]));
            }
        }
        return found;
    }

    return false;
}

static bool isConnectedWay(const std::vector<OSM::Element> &lhs, const std::vector<OSM::Element> &rhs, const OSM::DataSet &dataSet)
{
    return std::any_of(lhs.begin(), lhs.end(), [&](auto lway) {
        return std::any_of(rhs.begin(), rhs.end(), [&](auto rway) {
            return isConnectedGeometry(lway, rway, dataSet);
        });
    });
}

static bool isOverlappingWay(const std::vector<OSM::Element> &lhs, const std::vector<OSM::Element> &rhs)
{
    return std::any_of(lhs.begin(), lhs.end(), [&](auto lway) {
        return std::any_of(rhs.begin(), rhs.end(), [&](auto rway) {
            return lway == rway;
        });
    });
}

bool Platform::isSame(const Platform &lhs, const Platform &rhs, const OSM::DataSet &dataSet)
{
    const auto isConnectedEdge = isConnectedGeometry(lhs.m_edge, rhs.m_edge, dataSet);
    const auto isConnectedTrack = isConnectedWay(lhs.m_track, rhs.m_track, dataSet);
    const auto isOverlappingTrack = isOverlappingWay(lhs.m_track, rhs.m_track);
    const auto isConnectedArea = isConnectedGeometry(lhs.m_area, rhs.m_area, dataSet);

    if ((conflictIfPresent(lhs.m_stopPoint, rhs.m_stopPoint) && lhs.m_track != rhs.m_track && !isConnectedTrack)
     || (conflictIfPresent(lhs.m_edge, rhs.m_edge) && !isConnectedEdge)
     || (conflictIfPresent(lhs.m_area, rhs.m_area) && !isConnectedArea)
     || (!lhs.m_track.empty() && !rhs.m_track.empty() && !isOverlappingTrack && !isConnectedTrack)
     || (lhs.hasLevel() && rhs.hasLevel() && lhs.level() != rhs.level())
     || (lhs.m_mode != Unknown && rhs.m_mode != Unknown && lhs.m_mode != rhs.m_mode))
    {
        return false;
    }

    // we can accept conflicting names if one of them is likely a station name instead of a platform name
    if (!lhs.m_name.isEmpty() && !rhs.m_name.isEmpty() && lhs.m_name != rhs.m_name) {
        if (isPlausibleName(lhs.name()) && isPlausibleName(rhs.name())) {
            return false;
        }
    }

    // edge has to be part of area, but on its own that doesn't mean equallity
    if (!isConnectedArea && !isConnectedEdge) {
        if ((lhs.m_area && rhs.m_edge.type() == OSM::Type::Way && !isSubPath(lhs.m_area.outerPath(dataSet), *rhs.m_edge.way()))
        || (rhs.m_area && lhs.m_edge.type() == OSM::Type::Way && !isSubPath(rhs.m_area.outerPath(dataSet), *lhs.m_edge.way()))) {
            return false;
        }
    }

    // matching edge, point or track is good enough, matching area however isn't
    if (equalIfPresent(lhs.m_stopPoint, rhs.m_stopPoint)
     || equalIfPresent(lhs.m_edge, rhs.m_edge) || isConnectedEdge
     || isOverlappingTrack)
    {
        return true;
    }

    if (!isConnectedEdge) {
        // track/stop and area/edge elements do not share nodes, so those we need to match by spatial distance
        if (lhs.m_edge && rhs.m_stopPoint) {
            return OSM::distance(lhs.m_edge.outerPath(dataSet), rhs.position()) < MAX_TRACK_TO_EDGE_DISTANCE;
        }
        if (rhs.m_edge && lhs.m_stopPoint) {
            return OSM::distance(rhs.m_edge.outerPath(dataSet), lhs.position()) < MAX_TRACK_TO_EDGE_DISTANCE;
        }
    }

    if (!isConnectedArea) {
        if (lhs.m_area && rhs.m_stopPoint) {
            return OSM::distance(lhs.m_area.outerPath(dataSet), rhs.position()) < MAX_TRACK_TO_EDGE_DISTANCE;
        }
        if (rhs.m_area && lhs.m_stopPoint) {
            return OSM::distance(rhs.m_area.outerPath(dataSet), lhs.position()) < MAX_TRACK_TO_EDGE_DISTANCE;
        }
    }

    // free-floating sections: edge, area or track is within a reasonable distance
    if (!lhs.m_name.isEmpty() && lhs.m_name == rhs.m_name && !isConnectedArea && !isConnectedEdge) {
        auto d = maxSectionDistance(lhs, rhs.sections(), dataSet);
        if (d >= 0.0) {
            return d < MAX_SECTION_TO_EDGE_DISTANCE;
        }
        d = maxSectionDistance(rhs, lhs.sections(), dataSet);
        if (d >= 0.0) {
            return d < MAX_SECTION_TO_EDGE_DISTANCE;
        }
    }

    return isConnectedArea || isConnectedEdge || isConnectedTrack;
}

static bool compareSection(const PlatformSection &lhs, const PlatformSection &rhs)
{
    if (lhs.name == rhs.name) {
        return lhs.position < rhs.position;
    }
    return lhs.name < rhs.name;
}

void Platform::appendSection(std::vector<PlatformSection> &sections, const Platform &p, PlatformSection &&sec, std::vector<const OSM::Node*> &edgePath, const OSM::DataSet &dataSet)
{
    if (sections.empty() || sections.back().name != sec.name) {
        sections.push_back(std::move(sec));
    }

    // check which one is closer
    if (edgePath.empty()) {
        if (p.m_edge) {
            edgePath = p.m_edge.outerPath(dataSet);
        } else if (!p.m_track.empty()) {
            OSM::assemblePath(dataSet, p.m_track, edgePath);
        }
    }
    const auto dist1 = OSM::distance(edgePath, sections.back().position.center());
    const auto dist2 = OSM::distance(edgePath, sec.position.center());
    if (dist2 < dist1) {
        sections.back() = std::move(sec);
    }
}

static std::vector<OSM::Element> mergeWays(const std::vector<OSM::Element> &lhs, const std::vector<OSM::Element> &rhs)
{
    std::vector<OSM::Element> w = lhs;
    for (auto e : rhs) {
        if (std::find(w.begin(), w.end(), e) == w.end()) {
            w.push_back(e);
        }
    }
    return w;
}

Platform Platform::merge(const Platform &lhs, const Platform &rhs, const OSM::DataSet &dataSet)
{
    Platform p;
    p.m_name = preferredName(lhs.name(), rhs.name());
    p.m_stopPoint = OSM::coalesce(lhs.m_stopPoint, rhs.m_stopPoint);
    p.m_edge = OSM::coalesce(lhs.m_edge, rhs.m_edge);
    p.m_area = OSM::coalesce(lhs.m_area, rhs.m_area);
    p.m_track = mergeWays(lhs.m_track, rhs.m_track);
    p.m_level = lhs.hasLevel() ? lhs.m_level : rhs.m_level;

    // TODO
    p.m_mode = std::max(lhs.m_mode, rhs.m_mode);
    p.lines = lhs.lines.isEmpty() ? std::move(rhs.lines) : std::move(lhs.lines);

    std::vector<const OSM::Node*> edgePath;
    std::vector<PlatformSection> sections;
    auto lsec = lhs.sections();
    auto rsec = rhs.sections();
    std::sort(lsec.begin(), lsec.end(), compareSection);
    std::sort(rsec.begin(), rsec.end(), compareSection);
    for (auto lit = lsec.begin(), rit = rsec.begin(); lit != lsec.end() || rit != rsec.end();) {
        if (rit == rsec.end()) {
            appendSection(sections, p, std::move(*lit++), edgePath, dataSet);
            continue;
        }
        if (lit == lsec.end()) {
            appendSection(sections, p, std::move(*rit++), edgePath, dataSet);
            continue;
        }
        if (compareSection(*lit, *rit)) {
            appendSection(sections, p, std::move(*lit++), edgePath, dataSet);
            continue;
        }
        if (compareSection(*rit, *lit)) {
            appendSection(sections, p, std::move(*rit++), edgePath, dataSet);
            continue;
        }

        // both are equal
        if ((*lit).position == (*rit).position) {
            appendSection(sections, p, std::move(*lit++), edgePath, dataSet);
            ++rit;
            continue;
        }

        // both are equal but differ in distance: will be handled in appendSection in the next iteration
        appendSection(sections, p, std::move(*lit++), edgePath, dataSet);
    }
    p.setSections(std::move(sections));

    return p;
}

bool Platform::isPlausibleName(const QString &name)
{
    static QRegularExpression exp(QStringLiteral("^(\\d{1,3}[a-z]?|[A-Z])$"));
    return exp.match(name).hasMatch();
}

QString Platform::preferredName(const QString &lhs, const QString &rhs)
{
    if (lhs.isEmpty()) {
        return rhs;
    }
    if (rhs.isEmpty()) {
        return lhs;
    }

    if (isPlausibleName(lhs)) {
        return lhs;
    }
    if (isPlausibleName(rhs)) {
        return rhs;
    }

    return lhs.size() <= rhs.size() ? lhs: rhs;
}
