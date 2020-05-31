/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "scenegeometry.h"

#include <QDebug>
#include <QLineF>
#include <QPainterPath>
#include <QPolygonF>

#include <cmath>

using namespace KOSMIndoorMap;

double SceneGeometry::polylineLength(const QPolygonF &poly)
{
    if (poly.size() <= 1) {
        return 0.0;
    }

    double lineLength = 0.0;
    QPointF p1 = poly.at(0);
    for (auto it = std::next(poly.begin()); it != poly.end(); ++it) {
        lineLength += QLineF(p1, *it).length();
        p1 = *it;
    }
    return lineLength;
}

QPointF SceneGeometry::polylineMidPoint(const QPolygonF &poly)
{
    const auto lineLength = polylineLength(poly);
    if (lineLength <= 0.0) {
        return {};
    }

    double length = 0.0;
    auto p1 = poly.at(0);
    for (auto it = std::next(poly.begin()); it != poly.end(); ++it) {
        const QLineF line(p1, *it);
        const auto l = line.length();

        if (length + l < lineLength / 2.0) {
            length += l;
        } else {
            const auto r = ((length + l) - lineLength / 2.0) / l;
            return line.pointAt(1 - r);
        }

        p1 = *it;
    }

    return {};
}

double SceneGeometry::polylineMidPointAngle(const QPolygonF &path)
{
    const auto lineLength = polylineLength(path);
    if (lineLength <= 0.0) {
        return 0.0;
    }

    double length = 0.0;
    auto p1 = path.at(0);
    for (auto it = std::next(path.begin()); it != path.end(); ++it) {
        const QLineF line(p1, *it);
        const auto l = line.length();

        if (length + l < lineLength / 2.0) {
            length += l;
        } else {
            const auto r = ((length + l) - lineLength / 2.0) / l;
            auto a = - std::remainder(line.angle(), 360.0);
            if (a < -90.0 || a > 90.0) {
                a += 180.0;
            }
            return a;
        }

        p1 = *it;
    }

    return 0.0;
}

/* the algorithm in here would be pretty simple (see https://en.wikipedia.org/wiki/Polygon#Centroid)
 * if it weren't for numeric stability. We need something that keeps sufficient precision (~7 digits)
 * in the range of +/- m * n² for n being the largest coordinate value, and m the polygon size.
 * To help with that we:
 * - move the polygon bbox center to 0/0. This works as we usually only look at very small areas.
 * - scale the value by the bbox size, to enable the use of 64bit integers for the intermediate values.
 * - use 64 bit integers for the intermediate values, as those contain squares of the coordinates
 *   and thus become very large. As we don't use divisions on the intermediate values, integers work for this.
 */
QPointF SceneGeometry::polygonCentroid(const QPolygonF &poly)
{
    if (poly.size() < 3) {
        return {};
    }

    const auto bbox = poly.boundingRect();
    const auto offset = bbox.center();
    const auto scale = 1.0e6 / std::max(bbox.width(), bbox.height());

    int64_t a = 0.0;
    int64_t cx = 0.0;
    int64_t cy = 0.0;

    for (int i = 0; i < poly.size(); ++i) {
        const auto p1 = poly.at(i) - offset;
        const int64_t x1 = p1.x() * scale;
        const int64_t y1 = p1.y() * scale;

        const auto p2 = poly.at((i + 1) % poly.size()) - offset;
        const int64_t x2 = p2.x() * scale;
        const int64_t y2 = p2.y() * scale;

        a += (x1 * y2) - (x2 * y1);
        cx += (x1 + x2) * (x1 * y2 - x2 * y1);
        cy += (y1 + y2) * (x1 * y2 - x2 * y1);
    }

    if (a == 0) {
        return {};
    }

    cx /= 3 * a;
    cy /= 3 * a;

    return QPointF((double)cx / scale, (double)cy / scale) + offset;
}

void SceneGeometry::outerPolygonFromPath(const QPainterPath &path, QPolygonF &poly)
{
    if (path.isEmpty()) {
        return;
    }

    poly.clear();
    poly.reserve(path.elementCount());
    poly.push_back(path.elementAt(0));
    for (int i = 1; i < path.elementCount(); ++i) {
        const auto e = path.elementAt(i);
        if (e.type != QPainterPath::LineToElement) {
            return;
        }
        poly.push_back(e);
    }
}

double SceneGeometry::distanceToLine(const QLineF &line, QPointF p)
{
    const auto len = line.length();
    if (len == 0.0) {
        return QLineF(line.p1(), p).length();
    }

    // project p on a line extending the line segment given by @p line, and clamp to that to the segment
    const auto r = qBound(0.0, QPointF::dotProduct(p - line.p1(), line.p2() - line.p1()) / (len*len), 1.0);
    const auto intersection = line.p1() + r * (line.p2() - line.p1());
    return QLineF(intersection, p).length();

}
