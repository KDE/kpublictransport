/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GEOJSON_P_H
#define KPUBLICTRANSPORT_GEOJSON_P_H

#include "kpublictransport_export.h"

class QJsonObject;
class QPointF;
class QPolygonF;

namespace KPublicTransport {

/** GeoJSON utilities.
 *  @internal only exported for unit tests
 */
namespace GeoJson
{
    /** Coordinate of a point geometry object. */
    KPUBLICTRANSPORT_EXPORT QPointF readPoint(const QJsonObject &obj);

    /** Outer path of a polygon or multi-polygon geometry object. */
    QPolygonF readOuterPolygon(const QJsonObject &obj);
}

}

#endif // KPUBLICTRANSPORT_GEOJSON_P_H
