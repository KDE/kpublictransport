/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_MAPUTILS_H
#define KPUBLICTRANSPORT_MAPUTILS_H

#include <KPublicTransport/Journey>
#include <KPublicTransport/Path>

#include <QQmlEngine>

namespace KPublicTransport {

class Coordinate
{
    Q_GADGET
    QML_ANONYMOUS
    Q_PROPERTY(double latitude MEMBER latitude)
    Q_PROPERTY(double longitude MEMBER longitude)

public:
    double latitude;
    double longitude;
};

/** Helper methods for showing journey data on QtLocation maps. */
class MapUtils
{
    Q_GADGET
public:
    /** Coordinate array for consumption by QtLocation.MapPolyline,
     *  representing the the journey section @p jny.
     */
    Q_INVOKABLE [[nodiscard]] QJSValue polyline(const KPublicTransport::JourneySection &jny) const;
    /** Coordinate array for consumption by QtLocation.MapPolyline,
     *  representing the the path @p path.
     */
    Q_INVOKABLE [[nodiscard]] QJSValue polyline(const KPublicTransport::Path &path) const;
    /** Coordinate array for consumption by QtLocation.MapPolyline,
     *  representing the the path section @p pathSection.
     */
    Q_INVOKABLE [[nodiscard]] QJSValue polyline(const KPublicTransport::PathSection &pathSection) const;

    /** Bounding box of journey @p jny. */
    Q_INVOKABLE [[nodiscard]] static QRectF boundingBox(const KPublicTransport::Journey &jny);
    /** Bounding box of journey section @p jny. */
    Q_INVOKABLE [[nodiscard]] static QRectF boundingBox(const KPublicTransport::JourneySection &jny);
    /** Bounding box of path @p path. */
    Q_INVOKABLE [[nodiscard]] static QRectF boundingBox(const KPublicTransport::Path &path);
    /** Bounding box of path section @p pathSection. */
    Q_INVOKABLE [[nodiscard]] static QRectF boundingBox(const KPublicTransport::PathSection &pathSection);

    /** Center coordinate of bounding box @bbox,
     *  for consumption by QtLocation.Map.
     */
    Q_INVOKABLE [[nodiscard]] QJSValue center(const QRectF &bbox) const;
    /** Zoom level to fit @p bbox into a window of size @p width x @p height. */
    Q_INVOKABLE [[nodiscard]] static double zoomLevel(const QRectF &bbox, double width, double height);

    QQmlEngine *m_engine = nullptr;

private:
    [[nodiscard]] QJSValue coordinate(double lat, double lon) const;
};

}

#endif
