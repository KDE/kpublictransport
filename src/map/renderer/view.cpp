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

#include "view.h"

#include <osm/geomath.h>

#include <QTransform>

#include <cmath>

using namespace KOSMIndoorMap;

static constexpr const double SceneWorldSize = 256.0; // size of the scene when containing the full world
static constexpr const double LatitudeLimit = 85.05112879806592; // invtan(sinh(pi)) + radToDeg
static constexpr const auto MaxZoomFactor = 21; // 2^MaxZoomFactor subdivisions of the scene space

View::View(QObject *parent)
    : QObject(parent)
{
}

View::~View() = default;

QPointF View::mapGeoToScene(OSM::Coordinate coord) const
{
    const auto lat = qBound(-LatitudeLimit, coord.latF(), LatitudeLimit);
    return QPointF(
        (coord.lonF() + 180.0) / 360.0 * SceneWorldSize,
        SceneWorldSize / (2.0 * M_PI) * (M_PI - std::log(std::tan((M_PI / 4.0) + ((OSM::degToRad(lat) / 2.0)))))
    );
}

QRectF View::mapGeoToScene(OSM::BoundingBox box) const
{
    const auto p1 = mapGeoToScene(box.min);
    const auto p2 = mapGeoToScene(box.max);
    return QRectF(QPointF(p1.x(), p2.y()), QPointF(p2.x(), p1.y()));
}

OSM::Coordinate View::mapSceneToGeo(QPointF p) const
{
    return OSM::Coordinate(
        OSM::radToDeg(std::atan(std::sinh(M_PI * (1 - 2 * (p.y() / SceneWorldSize))))),
        (p.x() / SceneWorldSize) * 360.0 - 180.0
    );
}

OSM::BoundingBox View::mapSceneToGeo(const QRectF &box) const
{
    const auto c1 = mapSceneToGeo(box.bottomLeft());
    const auto c2 = mapSceneToGeo(box.topRight());
    return OSM::BoundingBox(c1, c2);
}

int View::screenHeight() const
{
    return m_screenSize.height();
}

int View::screenWidth() const
{
    return m_screenSize.width();
}

void View::setScreenSize(QSize size)
{
    if (size.width() <= 0.0 || size.height() <= 0.0 || size == m_screenSize) {
        return;
    }

    const auto dx = (double)size.width() / (double)screenWidth();
    const auto dy = (double)size.height() / (double)screenHeight();
    m_screenSize = size;

    m_viewport.setWidth(m_viewport.width() * dx);
    m_viewport.setHeight(m_viewport.height() * dy);
    constrainViewToScene();
    Q_EMIT transformationChanged();
}

int View::level() const
{
    return m_level;
}

void View::setLevel(int level)
{
    if (m_level == level) {
        return;
    }

    m_level = level;
    emit floorLevelChanged();
}

double View::zoomLevel() const
{
    const auto dx = m_viewport.width() / (screenWidth() / SceneWorldSize) / 360.0;
    return - std::log2(dx);
}

void View::setZoomLevel(double zoom, QPointF screenCenter)
{
    auto z = std::pow(2.0, - std::min(zoom, (double)MaxZoomFactor));
    const auto dx = ((screenWidth() / SceneWorldSize) * 360.0 * z) - m_viewport.width();
    const auto dy = ((screenHeight() / SceneWorldSize) * 360.0 * z) - m_viewport.height();

    const auto centerScene = mapScreenToScene(screenCenter);
    if (!m_viewport.contains(centerScene)) {
        return; // invalid input
    }

    const auto xr = (centerScene.x() - m_viewport.x()) / m_viewport.width();
    const auto yr = (centerScene.y() - m_viewport.y()) / m_viewport.height();

    m_viewport.adjust(-xr * dx, -yr * dy, (1-xr) * dx, (1-yr) * dy);
    constrainViewToScene();
    emit transformationChanged();
}

QRectF View::viewport() const
{
    return m_viewport;
}

void View::setViewport(const QRectF &viewport)
{
    m_viewport = viewport;
    constrainViewToScene();
}

QRectF View::sceneBoundingBox() const
{
    return m_bbox;
}

void View::setSceneBoundingBox(OSM::BoundingBox bbox)
{
    setSceneBoundingBox(mapGeoToScene(bbox));
}

void View::setSceneBoundingBox(const QRectF &bbox)
{
    if (m_bbox == bbox) {
        return;
    }
    m_bbox = bbox;

    // scale to fit horizontally
    m_viewport = bbox;
    const auto screenAspectRatio = (double)screenWidth() / (double)screenHeight();
    m_viewport.setHeight(m_viewport.width() / screenAspectRatio);

    // if necessary, scale to fit vertically
    if (m_viewport.height() > m_bbox.height()) {
        const auto dy = (double)m_bbox.height() / (double)m_viewport.height();
        m_viewport.setHeight(m_viewport.height() * dy);
        m_viewport.setWidth(m_viewport.width() * dy);
    }

    Q_EMIT transformationChanged();
}


QPointF View::mapSceneToScreen(QPointF scenePos) const
{
    return sceneToScreenTransform().map(scenePos);
}

QRectF View::mapSceneToScreen(const QRectF &sceneRect) const
{
    return QRectF(mapSceneToScreen(sceneRect.topLeft()), mapSceneToScreen(sceneRect.bottomRight()));
}

QPointF View::mapScreenToScene(QPointF screenPos) const
{
    // TODO this can be implemented more efficiently
    return sceneToScreenTransform().inverted().map(screenPos);
}

double View::mapScreenDistanceToSceneDistance(double distance) const
{
    const auto p1 = mapScreenToScene(m_viewport.center());
    const auto p2 = mapScreenToScene(m_viewport.center() + QPointF(1.0, 0));
    // ### does not consider rotations, needs to take the actual distance between p1 and p2 for that
    return std::abs(p2.x() - p1.x()) * distance;
}

void View::panScreenSpace(QPoint offset)
{
    auto dx = offset.x() * (m_viewport.width() / screenWidth());
    auto dy = offset.y() * (m_viewport.height() / screenHeight());
    m_viewport.adjust(dx, dy, dx, dy);
    constrainViewToScene();
}

QTransform View::sceneToScreenTransform() const
{
    QTransform t;
    t.scale(screenWidth() / (m_viewport.width()), screenHeight() / (m_viewport.height()));
    t.translate(-m_viewport.x(), -m_viewport.y());
    return t;
}

void View::zoomIn(QPointF screenCenter)
{
    setZoomLevel(zoomLevel() + 1, screenCenter);
}

void View::zoomOut(QPointF screenCenter)
{
    setZoomLevel(zoomLevel() - 1, screenCenter);
}

void View::constrainViewToScene()
{
    // ensure we don't scale smaller than the bounding box
    const auto s = std::min(m_viewport.width() / m_bbox.width(), m_viewport.height() / m_bbox.height());
    if (s > 1.0) {
        m_viewport.setWidth(m_viewport.width() / s);
        m_viewport.setHeight(m_viewport.height() / s);
    }

    // ensure we don't pan outside of the bounding box
    if (m_bbox.left() < m_viewport.left() && m_bbox.right() < m_viewport.right()) {
        const auto dx = std::min(m_viewport.left() - m_bbox.left(), m_viewport.right() - m_bbox.right());
        m_viewport.adjust(-dx, 0, -dx, 0);
    } else if (m_bbox.right() > m_viewport.right() && m_bbox.left() > m_viewport.left()) {
        const auto dx = std::min(m_bbox.right() - m_viewport.right(), m_bbox.left() - m_viewport.left());
        m_viewport.adjust(dx, 0, dx, 0);
    }

    if (m_bbox.top() < m_viewport.top() && m_bbox.bottom() < m_viewport.bottom()) {
        const auto dy = std::min(m_viewport.top() - m_bbox.top(), m_viewport.bottom() - m_bbox.bottom());
        m_viewport.adjust(0, -dy, 0, -dy);
    } else if (m_bbox.bottom() > m_viewport.bottom() && m_bbox.top() > m_viewport.top()) {
        const auto dy = std::min(m_bbox.bottom() - m_viewport.bottom(), m_bbox.top() - m_viewport.top());
        m_viewport.adjust(0, dy, 0, dy);
    }
}

double View::mapMetersToScene(double meters) const
{
    // ### this fails for distances above 180° due to OSM::distance wrapping around
    // doesn't matter for our use-case though, we are looking at much much smaller areas
    const auto d = OSM::distance(mapSceneToGeo(QPointF(m_viewport.left(), m_viewport.center().y())), mapSceneToGeo(QPointF(m_viewport.right(), m_viewport.center().y())));
    const auto scale = m_viewport.width() / d;
    return meters * scale;
}

double View::mapMetersToScreen(double meters) const
{
    const auto d = OSM::distance(mapSceneToGeo(QPointF(m_viewport.left(), m_viewport.center().y())), mapSceneToGeo(QPointF(m_viewport.right(), m_viewport.center().y())));
    const auto r = meters / d;
    return r * m_screenSize.width();
}

double View::mapScreenToMeters(int pixels) const
{
    const auto d = OSM::distance(mapSceneToGeo(QPointF(m_viewport.left(), m_viewport.center().y())), mapSceneToGeo(QPointF(m_viewport.right(), m_viewport.center().y())));
    const auto r = (double)pixels / (double)m_screenSize.width();
    return d * r;
}

double View::panX() const
{
    const auto r = (m_viewport.left() - m_bbox.left()) / m_bbox.width();
    return panWidth() * r;
}

double View::panY() const
{
    const auto r = (m_viewport.top() - m_bbox.top()) / m_bbox.height();
    return panHeight() * r;
}

double View::panWidth() const
{
    const auto r = m_bbox.width() / m_viewport.width();
    return screenWidth() * r;
}

double View::panHeight() const
{
    const auto r = m_bbox.height() / m_viewport.height();
    return screenHeight() * r;
}

void View::panTopLeft(double x, double y)
{
    m_viewport.moveLeft(m_bbox.x() + m_bbox.width() * (x / panWidth()));
    m_viewport.moveTop(m_bbox.y() + m_bbox.height() * (y / panHeight()));
    constrainViewToScene();
}
