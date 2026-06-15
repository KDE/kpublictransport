/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GEOJSON_P_H
#define KPUBLICTRANSPORT_GEOJSON_P_H

#include <vector>

class QJsonObject;
class QPointF;
class QPolygonF;
class QRectF;

namespace KPublicTransport {

/** GeoJSON utilities. */
namespace GeoJson
{
    /** Coordinate of a point geometry object. */
    QPointF readPoint(const QJsonObject &obj);

    /** Reads a line string object. */
    QPolygonF readLineString(const QJsonObject &obj);

    /** Outer path of a polygon or multi-polygon geometry object.
     *  Multiple outer polygons are united.
     */
    QPolygonF readOuterPolygon(const QJsonObject &obj);
    /** Outer paths of a polygon or multi-polygon geometry object. */
    std::vector<QPolygonF> readOuterPolygons(const QJsonObject &obj);

    /** Compute bounding rect for the given geometry.
     *  This is vastly more efficient than reading the actual out geometry
     *  and determining the bounding rect from that.
     */
    [[nodiscard]] QRectF boundingRect(const QJsonObject &geometry);

    /** Creates a line string object. */
    QJsonObject writeLineString(const QPolygonF &lineString);

    /** Create a polygon object. */
    QJsonObject writePolygon(const QPolygonF &polygon);
    /** Create a multi-polygon object. */
    QJsonObject writePolygons(const std::vector<QPolygonF> &polygons);
}

}

#endif // KPUBLICTRANSPORT_GEOJSON_P_H
