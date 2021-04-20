/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "geojson_p.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QPointF>
#include <QPolygonF>

using namespace KPublicTransport;

static QPointF readPointCoordinates(const QJsonArray &coords)
{
    if (coords.size() != 2) {
        return {};
    }

    return {coords.at(0).toDouble(), coords.at(1).toDouble()};
}

QPointF GeoJson::readPoint(const QJsonObject &obj)
{
    const auto type = obj.value(QLatin1String("type")).toString();
    if (type != QLatin1String("Point")) {
        return {};
    }

    const auto coordinates = obj.value(QLatin1String("coordinates")).toArray();
    return readPointCoordinates(coordinates);
}

static QPolygonF readPolygonCoordinates(const QJsonArray &coords)
{
    QPolygonF poly;
    poly.reserve(coords.size());
    for (const auto &pointV : coords) {
        const auto point = pointV.toArray();
        poly.push_back(readPointCoordinates(point));
    }
    return poly;
}

static QPolygonF readOuterPolygonCoordinates(const QJsonArray &coordinates)
{
    if (coordinates.empty()) {
        return {};
    }
    return readPolygonCoordinates(coordinates.at(0).toArray());
}

QPolygonF GeoJson::readLineString(const QJsonObject &obj)
{
    const auto type = obj.value(QLatin1String("type")).toString();
    if (type != QLatin1String("LineString")) {
        return {};
    }

    const auto coordinates = obj.value(QLatin1String("coordinates")).toArray();
    return readPolygonCoordinates(coordinates);
}

QPolygonF GeoJson::readOuterPolygon(const QJsonObject &obj)
{
    const auto type = obj.value(QLatin1String("type")).toString();
    if (type == QLatin1String("Polygon")) {
        return readOuterPolygonCoordinates(obj.value(QLatin1String("coordinates")).toArray());
    } else if (type == QLatin1String("MultiPolygon")) {
        const auto coordinates = obj.value(QLatin1String("coordinates")).toArray();
        QPolygonF poly;
        for (const auto &polyV : coordinates) {
            auto subPoly = readOuterPolygonCoordinates(polyV.toArray());
            poly = poly.empty() ? std::move(subPoly) : poly.united(subPoly);
        }
        return poly;
    }

    return {};
}

std::vector<QPolygonF> GeoJson::readOuterPolygons(const QJsonObject &obj)
{
    const auto type = obj.value(QLatin1String("type")).toString();
    if (type == QLatin1String("Polygon")) {
        return {readOuterPolygonCoordinates(obj.value(QLatin1String("coordinates")).toArray())};
    } else if (type == QLatin1String("MultiPolygon")) {
        const auto coordinates = obj.value(QLatin1String("coordinates")).toArray();
        std::vector<QPolygonF> polys;
        polys.reserve(coordinates.size());
        for (const auto &polyV : coordinates) {
            polys.push_back(readOuterPolygonCoordinates(polyV.toArray()));
        }
        return polys;
    }

    return {};
}

static QJsonArray writePoint(const QPointF &p)
{
    return QJsonArray({ p.x(), p.y() });
}

QJsonObject GeoJson::writeLineString(const QPolygonF &lineString)
{
    QJsonObject obj;
    obj.insert(QLatin1String("type"), QLatin1String("LineString"));

    QJsonArray coords;
    for (const auto &p : lineString) {
        coords.push_back(writePoint(p));
    }
    obj.insert(QLatin1String("coordinates"), coords);
    return obj;
}

QJsonObject GeoJson::writePolygon(const QPolygonF &polygon)
{
    QJsonObject obj;
    obj.insert(QLatin1String("type"), QLatin1String("Polygon"));

    QJsonArray coords;
    for (const auto &p : polygon) {
        coords.push_back(writePoint(p));
    }
    QJsonArray polyArray;
    polyArray.push_back(coords);
    obj.insert(QLatin1String("coordinates"), polyArray);
    return obj;
}

QJsonObject GeoJson::writePolygons(const std::vector<QPolygonF> &polygons)
{
    if (polygons.empty()) {
        return {};
    }
    if (polygons.size() == 1) {
        return writePolygon(polygons[0]);
    }

    QJsonObject obj;
    obj.insert(QLatin1String("type"), QLatin1String("MultiPolygon"));

    QJsonArray multiPolys;
    for (const auto &polygon : polygons) {
        QJsonArray coords;
        for (const auto &p : polygon) {
            coords.push_back(writePoint(p));
        }
        QJsonArray polyArray;
        polyArray.push_back(coords);
        multiPolys.push_back(polyArray);
    }
    obj.insert(QLatin1String("coordinates"), multiPolys);
    return obj;
}
