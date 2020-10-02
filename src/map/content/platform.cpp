/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "platform.h"

#include <osm/geomath.h>

using namespace KOSMIndoorMap;

bool PlatformSection::isValid() const
{
    return !name.isEmpty() && position;
}


Platform::Platform() = default;
Platform::~Platform() = default;

bool Platform::isValid() const
{
    return !m_name.isEmpty() && position().isValid() && hasLevel();
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
    return m_stopPoint.center();
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
    return m_edge ? m_edge : m_stopPoint;
}

void Platform::setEdge(OSM::Element edge)
{
    m_edge = edge;
}

OSM::Element Platform::area() const
{
    return m_area ? m_area : edge();
}

void Platform::setArea(OSM::Element area)
{
    m_area = area;
}

OSM::Element Platform::track() const
{
    return m_track;
}

void Platform::setTrack(OSM::Element track)
{
    m_track = track;
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

static constexpr const auto MAX_TRACK_TO_EDGE_DISTANCE = 2.5; // meters

bool Platform::isSame(const Platform &lhs, const Platform &rhs, const OSM::DataSet &dataSet)
{
    // TODO check for mode conflicts
    if (conflictIfPresent(lhs.m_stopPoint, rhs.m_stopPoint)
     || conflictIfPresent(lhs.m_edge, rhs.m_edge)
     || conflictIfPresent(lhs.m_area, rhs.m_area)
     || conflictIfPresent(lhs.m_track, rhs.m_track)
     || (lhs.hasLevel() && rhs.hasLevel() && lhs.level() != rhs.level())
     || (!lhs.m_name.isEmpty() && !rhs.m_name.isEmpty() && lhs.m_name != rhs.m_name))
    {
        return false;
    }

    // edge has to be part of area, but on its own that doesn't mean equallity
    if ((lhs.m_area && rhs.m_edge.type() == OSM::Type::Way && !isSubPath(lhs.m_area.outerPath(dataSet), *rhs.m_edge.way()))
     || (rhs.m_area && lhs.m_edge.type() == OSM::Type::Way && isSubPath(rhs.m_area.outerPath(dataSet), *lhs.m_edge.way()))) {
        return false;
    }

    // matching edge, point or track is good enough, matching area however isn't
    if (equalIfPresent(lhs.m_stopPoint, rhs.m_stopPoint)
     || equalIfPresent(lhs.m_edge, rhs.m_edge)
     || equalIfPresent(lhs.m_track, rhs.m_track))
    {
        return true;
    }

    // track/stop and area/edge elements do not share nodes, so those we need to match by spatial distance
    if (lhs.m_edge && rhs.m_stopPoint) {
        return OSM::distance(lhs.m_edge.outerPath(dataSet), rhs.position()) < MAX_TRACK_TO_EDGE_DISTANCE;
    }
    if (rhs.m_edge && lhs.m_stopPoint) {
        return OSM::distance(rhs.m_edge.outerPath(dataSet), lhs.position()) < MAX_TRACK_TO_EDGE_DISTANCE;
    }

    if (lhs.m_area && rhs.m_stopPoint) {
        return OSM::distance(lhs.m_area.outerPath(dataSet), rhs.position()) < MAX_TRACK_TO_EDGE_DISTANCE;
    }
    if (rhs.m_area && lhs.m_stopPoint) {
        return OSM::distance(rhs.m_area.outerPath(dataSet), lhs.position()) < MAX_TRACK_TO_EDGE_DISTANCE;
    }

    return false;
}

Platform Platform::merge(const Platform &lhs, const Platform &rhs)
{
    Platform p;
    p.m_name = lhs.m_name.isEmpty() ? rhs.m_name : lhs.m_name;
    p.m_stopPoint = lhs.m_stopPoint ? lhs.m_stopPoint : rhs.m_stopPoint;
    p.m_edge = lhs.m_edge ? lhs.m_edge : rhs.m_edge;
    p.m_area = lhs.m_area ? lhs.m_area : rhs.m_area;
    p.m_track = lhs.m_track ? lhs.m_track : rhs.m_track;
    p.m_level = lhs.hasLevel() ? lhs.m_level : rhs.m_level;

    // TODO
    p.mode = std::max(lhs.mode, rhs.mode);
    p.lines = lhs.lines.isEmpty() ? std::move(rhs.lines) : std::move(lhs.lines);

    auto sections = lhs.sections();
    sections.insert(sections.end(), rhs.sections().begin(), rhs.sections().end());
    p.setSections(std::move(sections));

    return p;
}
