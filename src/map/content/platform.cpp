/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "platform.h"

using namespace KOSMIndoorMap;

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

static bool conflictIfPresent(OSM::Element lhs, OSM::Element rhs)
{
    return lhs && rhs && lhs != rhs;
}

static bool equalIfPresent(OSM::Element lhs, OSM::Element rhs)
{
    return lhs && rhs && lhs == rhs;
}

bool Platform::isSame(const Platform &lhs, const Platform &rhs)
{
    // TODO check for mode conflicts
    if (conflictIfPresent(lhs.m_stopPoint, rhs.m_stopPoint)
     || conflictIfPresent(lhs.m_edge, rhs.m_edge)
     || conflictIfPresent(lhs.m_area, rhs.m_area)
     || conflictIfPresent(lhs.m_track, rhs.m_track)
     || (!lhs.m_name.isEmpty() && !rhs.m_name.isEmpty() && lhs.m_name != rhs.m_name))
    {
        return false;
    }

    if (equalIfPresent(lhs.m_stopPoint, rhs.m_stopPoint)
     || equalIfPresent(lhs.m_edge, rhs.m_edge)
     || equalIfPresent(lhs.m_area, rhs.m_area)
     || equalIfPresent(lhs.m_track, rhs.m_track))
    {
        return true;
    }

    return false; // TODO name based comparison and track/stop <-> edge distance check
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
    p.lines = lhs.lines.isEmpty() ? rhs.lines : lhs.lines;
    p.sections = lhs.sections.empty() ? rhs.sections : lhs.sections;

    return p;
}
