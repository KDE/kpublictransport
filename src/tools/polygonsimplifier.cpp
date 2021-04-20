/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "polygonsimplifier.h"

#include <osm/geomath.h>

#include <QDebug>
#include <QPolygonF>

static QPolygonF douglasPeucker(const QPolygonF::const_iterator &begin, const QPolygonF::const_iterator &end, double threshold)
{
    QPolygonF result;
    if (std::distance(begin, end) < 3) {
        std::copy(begin, end, std::back_inserter(result));
        return result;
    }

    double maxDistance = 0.0;
    auto maxDistIt = std::next(begin);
    for (auto it = maxDistIt; it != end; ++it) {
        const auto d = OSM::distance(OSM::Coordinate((*begin).y(), (*begin).x()), OSM::Coordinate((*std::prev(end)).y(), (*std::prev(end)).x()), OSM::Coordinate((*it).y(), (*it).x()));
        if (d > maxDistance) {
            maxDistance = d;
            maxDistIt = it;
        }
    }

    if (maxDistance >= threshold) {
        result += douglasPeucker(begin, std::next(maxDistIt), threshold);
        result.pop_back();
        result += douglasPeucker(maxDistIt, end, threshold);
        return result;
    }

    return QPolygonF(QVector<QPointF>({*begin, (*std::prev(end))}));
}

QPolygonF PolygonSimplifier::douglasPeucker(const QPolygonF &poly, double threshold)
{
    auto result = douglasPeucker(poly.begin(), poly.end(), threshold);
    qDebug() << "got" << poly.size() << "dropped" << poly.size() - result.size() << "remaining" << result.size();

    // if the polygon itself is smaller than the threshold, the result can deteriorate into
    // an area-less structure, take the bounding rect in that case
    if (result.size() < 4) {
        qDebug() << "  result deteriorated, taking bounding rect instead";
        const auto bbox = poly.boundingRect();
        return QPolygonF({ bbox.topLeft(), bbox.topRight(), bbox.bottomRight(), bbox.bottomLeft(), bbox.topLeft() });
    }

    return result;
}
