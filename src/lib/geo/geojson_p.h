/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GEOJSON_P_H
#define KPUBLICTRANSPORT_GEOJSON_P_H

class QJsonObject;
class QPointF;
class QPolygonF;

namespace KPublicTransport {

/** GeoJSON utilities. */
namespace GeoJson
{
    /** Coordinate of a point geometry object. */
    QPointF readPoint(const QJsonObject &obj);

    /** Reads a line string object. */
    QPolygonF readLineString(const QJsonObject &obj);

    /** Outer path of a polygon or multi-polygon geometry object. */
    QPolygonF readOuterPolygon(const QJsonObject &obj);

    /** Creates a line string object. */
    QJsonObject writeLineString(const QPolygonF &lineString);

    /** Create a polygon object. */
    QJsonObject writePolygon(const QPolygonF &polygon);
}

}

#endif // KPUBLICTRANSPORT_GEOJSON_P_H
