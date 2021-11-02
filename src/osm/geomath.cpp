/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "geomath.h"

#include <QLineF>

#include <limits>

using namespace OSM;

// see https://en.wikipedia.org/wiki/Haversine_formula
double OSM::distance(double lat1, double lon1, double lat2, double lon2)
{
    constexpr const auto earthRadius = 6371000.0; // in meters

    const auto d_lat = degToRad(lat1 - lat2);
    const auto d_lon = degToRad(lon1 - lon2);

    const auto a = pow(sin(d_lat / 2.0), 2) + cos(degToRad(lat1)) * cos(degToRad(lat2)) * pow(sin(d_lon / 2.0), 2);
    return 2.0 * earthRadius * atan2(sqrt(a), sqrt(1.0 - a));
}

double OSM::distance(Coordinate coord1, Coordinate coord2)
{
    return distance(coord1.latF(), coord1.lonF(), coord2.latF(), coord2.lonF());
}

double OSM::distance(OSM::Coordinate l1, OSM::Coordinate l2, OSM::Coordinate p)
{
    QLineF line(l1.lonF(), l1.latF(), l2.lonF(), l2.latF());
    const auto len = line.length();
    if (len == 0.0) {
        return OSM::distance(l1, p);
    }

    // project p on a line extending the line segment given by @p l1 and @p l2, and clamp to that to the segment
    QPointF pf(p.lonF(), p.latF());
    const auto r = qBound(0.0, QPointF::dotProduct(pf - line.p1(), line.p2() - line.p1()) / (len*len), 1.0);
    const auto intersection = line.p1() + r * (line.p2() - line.p1());
    return OSM::distance(OSM::Coordinate(intersection.y(), intersection.x()), p);
}

double OSM::distance(const std::vector<const OSM::Node*> &path, OSM::Coordinate coord)
{
    if (path.empty()) {
        return std::numeric_limits<double>::max();
    }

    if (path.size() == 1) {
        return distance(path[0]->coordinate, coord);
    }

    auto dist = std::numeric_limits<double>::max();
    OSM::Id firstNode = 0;
    for (auto it = path.begin(); it != std::prev(path.end()) && it != path.end(); ++it) {
        const auto nextIt = std::next(it);
        if (firstNode == 0) { // starting a new loop
            firstNode = (*it)->id;
        }

        // compute distance between line segment and coord
        dist = std::min(dist, OSM::distance((*it)->coordinate, (*nextIt)->coordinate, coord));

        if ((*nextIt)->id == firstNode) { // just closed a loop, so this is not a line on the path
            firstNode = 0;
            ++it;
        }
    }
    return dist;
}
