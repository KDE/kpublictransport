/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_SCENEGEOMETRY_H
#define KOSMINDOORMAP_SCENEGEOMETRY_H

#include "kosmindoormap_export.h"

class QLineF;
class QPainterPath;
class QPointF;
class QPolygonF;

namespace KOSMIndoorMap {

/** Geometry related functions.
 *  @internal only exported for unit tests
 */
namespace SceneGeometry
{
    /** Centroid of a polygon.
     *  @see https://en.wikipedia.org/wiki/Polygon#Centroid
     */
    KOSMINDOORMAP_EXPORT QPointF polygonCentroid(const QPolygonF &poly);

    /** Returns the lengths of the given polyline. */
    double polylineLength(const QPolygonF &poly);

    /** Returns the point at equal distance between the ends on the given polygon. */
    KOSMINDOORMAP_EXPORT QPointF polylineMidPoint(const QPolygonF &poly);

    /** Rotation angle for a label placed at the middle of @p path. */
    KOSMINDOORMAP_EXPORT double polylineMidPointAngle(const QPolygonF &path);

    /** Returns the outer polygon of a painter path.
     *  @note This is not generic, but makes assumptions about the painter path
     *  structure that happen to hold of OSM input data.
     */
    void outerPolygonFromPath(const QPainterPath &path, QPolygonF &poly);

    /** Computes the distance of the given line to the given point. */
    KOSMINDOORMAP_EXPORT double distanceToLine(const QLineF &line, QPointF p);
}

}

#endif // KOSMINDOORMAP_SCENEGEOMETRY_H
