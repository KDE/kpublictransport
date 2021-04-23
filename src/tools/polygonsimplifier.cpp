/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "polygonsimplifier.h"

#include <osm/geomath.h>

#include <QDebug>
#include <QPolygonF>

#include <clipper.hpp>

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

static ClipperLib::Path qPolygonToClipperPath(const QPolygonF &poly)
{
    ClipperLib::Path result;
    result.reserve(poly.size());
    std::transform(poly.begin(), poly.end(), std::back_inserter(result), [](auto p) {
        return ClipperLib::IntPoint(p.x() * 10'000'000.0, p.y() * 10'000'000);
    });
    return result;
}

static QPolygonF clipperPathToQPolygon(const ClipperLib::Path &path)
{
    QPolygonF result;
    result.reserve(path.size() + 1);
    std::transform(path.begin(), path.end(), std::back_inserter(result), [](auto p) {
        return QPointF(p.X / 10'000'000.0, p.Y / 10'000'000.0);
    });
    if (!result.empty() && !result.isClosed()) {
        result.push_back(result.front());
    }
    return result;
}

QPolygonF PolygonSimplifier::offset(const QPolygonF &poly, double distance)
{
    if (poly.empty()) {
        return {};
    }

    // convert meter distance to 100 nano-degree, the unit used by the polygon offset algorithm
    const auto bbox = poly.boundingRect();
    const auto bboxWidth = OSM::distance(bbox.center().y(), bbox.left(), bbox.center().y(), bbox.right());
    const auto delta = bbox.width() / bboxWidth * distance * 10'000'000.0;

    ClipperLib::ClipperOffset co;
    co.AddPath(qPolygonToClipperPath(poly), ClipperLib::jtMiter, ClipperLib::etClosedPolygon);
    ClipperLib::Paths result;
    co.Execute(result, delta);
    return clipperPathToQPolygon(result[0]);
}
