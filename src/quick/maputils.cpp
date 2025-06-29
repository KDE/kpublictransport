/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "maputils.h"

#include <KPublicTransport/Stopover>

#include <cmath>

using namespace KPublicTransport;
using namespace Qt::Literals;

QJSValue MapUtils::polyline(const KPublicTransport::JourneySection &jny) const
{
    const auto path = jny.path();
    if (path.isEmpty()) {
        QJSValue result = m_engine->newArray();
        int i = 0;

        result.setProperty(i++, coordinate(jny.from().latitude(), jny.from().longitude()));
        for (const auto &s : jny.intermediateStops()) {
            if (!s.stopPoint().hasCoordinate()) {
                continue;
            }

            result.setProperty(i++, coordinate(s.stopPoint().latitude(), s.stopPoint().longitude()));
        }
        result.setProperty(i++, coordinate(jny.to().latitude(), jny.to().longitude()));
        return result;
    }

    return polyline(path);
}

QJSValue MapUtils::polyline(const KPublicTransport::PathSection &pathSection) const
{
    const auto path = pathSection.path();
    QJSValue result = m_engine->newArray(path.size());
    int i = 0;
    for (const auto &p : path) {
        result.setProperty(i++, coordinate(p.y(), p.x()));
    }
    return result;
}

QJSValue MapUtils::polyline(const KPublicTransport::Path &path) const
{
    QJSValue result = m_engine->newArray();
    int i = 0;
    for (const auto &section : path.sections()) {
        const auto path = section.path();
        for (const auto &p : path) {
            result.setProperty(i++, coordinate(p.y(), p.x()));
        }
    }
    return result;
}

QJSValue MapUtils::coordinate(double lat, double lon) const
{
    return m_engine->toScriptValue(Coordinate{lat, lon});
}

QRectF MapUtils::boundingBox(const KPublicTransport::Journey &jny)
{
    QRectF bbox;
    for (const auto &section : jny.sections()) {
        bbox |= boundingBox(section);
    }
    return bbox;
}

QRectF MapUtils::boundingBox(const KPublicTransport::JourneySection &jny)
{
    double minLat = std::numeric_limits<double>::max();
    double minLon = std::numeric_limits<double>::max();
    double maxLat = std::numeric_limits<double>::lowest();
    double maxLon = std::numeric_limits<double>::lowest();

    const auto path = jny.path();
    for (const auto &pathSec : path.sections()) {
        const auto bbox = pathSec.path().boundingRect();
        minLat = std::min(minLat, bbox.bottom());
        minLon = std::min(minLon, bbox.left());
        maxLat = std::max(maxLat, bbox.top());
        maxLon = std::max(maxLon, bbox.right());
    }

    for (const auto &s : jny.intermediateStops()) {
        minLat = std::min(s.stopPoint().latitude(), minLat);
        minLon = std::min(s.stopPoint().longitude(), minLon);
        maxLat = std::max(s.stopPoint().latitude(), maxLat);
        maxLon = std::max(s.stopPoint().longitude(), maxLon);
    }

    for (const auto &s : { jny.from(), jny.to() }) {
        minLat = std::min(s.latitude(), minLat);
        minLon = std::min(s.longitude(), minLon);
        maxLat = std::max(s.latitude(), maxLat);
        maxLon = std::max(s.longitude(), maxLon);
    }

    return QRectF(QPointF(minLon, minLat), QPointF(maxLon, maxLat));
}

QRectF MapUtils::boundingBox(const KPublicTransport::Path &path)
{
    double minLat = std::numeric_limits<double>::max();
    double minLon = std::numeric_limits<double>::max();
    double maxLat = std::numeric_limits<double>::lowest();
    double maxLon = std::numeric_limits<double>::lowest();

    for (const auto &pathSec : path.sections()) {
        const auto p = pathSec.path();
        if (p.isEmpty()) {
            continue;
        }
        const auto bbox = p.boundingRect();
        minLat = std::min(minLat, bbox.bottom());
        minLon = std::min(minLon, bbox.left());
        maxLat = std::max(maxLat, bbox.top());
        maxLon = std::max(maxLon, bbox.right());
    }

    return QRectF(QPointF(minLon, minLat), QPointF(maxLon, maxLat));
}

QRectF MapUtils::boundingBox(const KPublicTransport::PathSection &pathSection)
{
    return pathSection.path().boundingRect();
}

QJSValue MapUtils::center(const QRectF &bbox) const
{
    return coordinate(bbox.center().y(), bbox.center().x());
}

[[nodiscard]] constexpr inline double degToRad(double deg)
{
    return deg / 180.0 * M_PI;
}

[[nodiscard]] static QPointF mercatorProject(double lat, double lon, double zoom)
{
    const auto x = (256.0 / (2.0 * M_PI)) * std::pow(2.0, zoom) * (degToRad(lon) + M_PI);
    const auto y = (256.0 / (2.0 * M_PI)) * std::pow(2.0, zoom) * (M_PI - std::log(std::tan(M_PI / 4.0 + degToRad(lat) / 2.0)));
    return QPointF(x, y);
}

double MapUtils::zoomLevel(const QRectF &bbox, double width, double height)
{
    const auto p1 = mercatorProject(bbox.bottomLeft().y(), bbox.bottomLeft().x(), 1.0);
    const auto p2 = mercatorProject(bbox.topRight().y(), bbox.topRight().x(), 1.0);

    const auto zx = std::log2((width / (p2.x() - p1.x())));
    const auto zy = std::log2((height / (p2.y() - p1.y())));
    const auto z = std::min(zx, zy);

    return z >= 1.0 && z <= 22.0 ? z : 5.0;
}

#include "moc_maputils.cpp"
