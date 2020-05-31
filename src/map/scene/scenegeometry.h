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

#ifndef KOSMINDOORMAP_SCENEGEOMETRY_H
#define KOSMINDOORMAP_SCENEGEOMETRY_H

class QLineF;
class QPainterPath;
class QPointF;
class QPolygonF;

namespace KOSMIndoorMap {

/** Geometry related functions. */
namespace SceneGeometry
{
    /** Centroid of a polygon.
     *  @see https://en.wikipedia.org/wiki/Polygon#Centroid
     */
    QPointF polygonCentroid(const QPolygonF &poly);

    /** Returns the lengths of the given polyline. */
    double polylineLength(const QPolygonF &poly);

    /** Returns the point at equal distance between the ends on the given polygon. */
    QPointF polylineMidPoint(const QPolygonF &poly);

    /** Rotation angle for a label placed at the middle of @p path. */
    double polylineMidPointAngle(const QPolygonF &path);

    /** Returns the outer polygon of a painter path.
     *  @note This is not generic, but makes assumptions about the painter path
     *  structure that happen to hold of OSM input data.
     */
    void outerPolygonFromPath(const QPainterPath &path, QPolygonF &poly);

    /** Computes the distance of the given line to the given point. */
    double distanceToLine(const QLineF &line, QPointF p);
}

}

#endif // KOSMINDOORMAP_SCENEGEOMETRY_H
