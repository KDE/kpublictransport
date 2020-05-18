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

#include <QTransform>

#include <cmath>

using namespace KOSMIndoorMap;

View::View() = default;
View::~View() = default;

static constexpr inline double degToRad(double deg)
{
    return deg / 180.0 * M_PI;
}

static constexpr const double SceneSize = 256.0;
static constexpr const double LatitudeLimit = 85.05112879806592; // invtan(sinh(pi)) + radToDeg

QPointF View::mapGeoToScene(OSM::Coordinate coord) const
{
    const auto lat = qBound(-LatitudeLimit, coord.latF(), LatitudeLimit);
    return QPointF(
        SceneSize / (2.0 * M_PI) * (degToRad(coord.lonF()) + M_PI),
        SceneSize / (2.0 * M_PI) * (M_PI - std::log(std::tan((M_PI / 4.0) + ((degToRad(lat) / 2.0)))))
    );
}

QRectF View::mapGeoToScene(OSM::BoundingBox box) const
{
    const auto p1 = mapGeoToScene(box.min);
    const auto p2 = mapGeoToScene(box.max);
    return QRectF(QPointF(p1.x(), p2.y()), QPointF(p2.x(), p1.y()));
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
    const auto dx = (double)size.width() / (double)screenWidth();
    const auto dy = (double)size.height() / (double)screenHeight();
    m_screenSize = size;

    m_viewport.setWidth(m_viewport.width() * dx);
    m_viewport.setHeight(m_viewport.height() * dy);
}

QString View::level() const
{
    return m_level;
}

void View::setLevel(const QString &level)
{
    m_level = level;
}

double View::zoomLevel() const
{
    const auto dx = (m_viewport.width()) / (screenWidth() / 256.0) / 360.0;
    return - std::log2(dx);
}

QRectF View::viewport() const
{
    return m_viewport;
}

void View::setViewport(const QRectF &viewport)
{
    m_viewport = viewport;
    // TODO clamp to bbox
}

void View::setSceneBoundingBox(OSM::BoundingBox bbox)
{
    setSceneBoundingBox(mapGeoToScene(bbox));
}

void View::setSceneBoundingBox(const QRectF &bbox)
{
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
}


QPointF View::sceneToScreen(QPointF scenePos) const
{
    return sceneToScreenTransform().map(scenePos);
}

void View::panScreenSpace(QPoint offset)
{
    auto dx = offset.x() * (m_viewport.width() / screenWidth());
    auto dy = offset.y() * (m_viewport.height() / screenHeight());
    m_viewport.adjust(dx, dy, dx, dy);
}

QTransform View::sceneToScreenTransform() const
{
    QTransform t;
    t.scale(screenWidth() / (m_viewport.width()), screenHeight() / (m_viewport.height()));
    t.translate(-m_viewport.x(), -m_viewport.y());
    return t;
}

void View::zoomIn()
{
    auto dx = 0.25 * m_viewport.width();
    auto dy = 0.25 * m_viewport.height();
    m_viewport.adjust(dx, dy, -dx, -dy);
    qDebug() << zoomLevel();
}

void View::zoomOut()
{
    auto dx = 0.5 * m_viewport.width();
    auto dy = 0.5 * m_viewport.height();
    m_viewport.adjust(-dx, -dy, dx, dy);
    qDebug() << zoomLevel();
}
