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
#include <QPolygonF>

using namespace KOSMIndoorMap;

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
