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

#ifndef KOSMINDOORMAP_VIEW_H
#define KOSMINDOORMAP_VIEW_H

#include <osm/datatypes.h>

#include <QObject>
#include <QRectF>
#include <QSize>

class QTransform;

namespace KOSMIndoorMap {

/** View transformations and transformation manipulation.
 *  There are three different coordinate systems involved here:
 *  - The geographic world coordinates of the OSM input data.
 *    This uses OSM::Coordinate.
 *  - The scene coordinates which have a the Web Mercator projection applied (see https://en.wikipedia.org/wiki/Mercator_projection).
 *    This uses QPointF ranging from 0x0 to 256x256
 *  - The screen coordinates (ie. visible pixels on screen).
 *    This uses QPoint.
 *  Further, there's also three slight variations of those in use here:
 *  - "HUD" coordinates: elements that follow the scene coordinates for their positioning,
 *    but the screen coordinates regarding scaling and rotation. This is used for map labels.
 *  - Geographic distances. This is needed to display things in a fixed width in meters in the scene,
 *    or to compute the map scale. Note that this only works due to the relatively high zoom levels,
 *    so that earth curvature or map projection effects are negligible.
 *  - "pan space": same transform as screen space, but with the origin at the origin of the scene bounding box
 *    This is useful for implementing scene-wide panning and showing scroll bars.
 */
class View : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double panX READ panX NOTIFY transformationChanged)
    Q_PROPERTY(double panY READ panY NOTIFY transformationChanged)
    Q_PROPERTY(double panWidth READ panWidth NOTIFY transformationChanged)
    Q_PROPERTY(double panHeight READ panHeight NOTIFY transformationChanged)
    Q_PROPERTY(int floorLevel READ level WRITE setLevel NOTIFY floorLevelChanged)
public:
    explicit View(QObject *parent = nullptr);
    ~View();

    /** Map a geographic coordinate to a scene coordinate, ie. apply the mercator projection. */
    QPointF mapGeoToScene(OSM::Coordinate coord) const;
    QRectF mapGeoToScene(OSM::BoundingBox box) const;
    /** Map a scene coordinate to a geographic one, ie. apply the inverse mercator projection. */
    OSM::Coordinate mapSceneToGeo(QPointF p) const;

    /** Screen-space sizes, ie the size of the on-screen area used for displaying. */
    int screenWidth() const;
    int screenHeight() const;
    void setScreenSize(QSize size);

    /** The transformation to apply to scene coordinate to get to the view on screen. */
    QTransform sceneToScreenTransform() const;

    /** The (floor) level to display.
     *  @see MapLevel.
     */
    int level() const;
    void setLevel(int level);

    /** OSM-compatible zoom level, ie. the 2^level-th subdivision of the scene space. */
    double zoomLevel() const;

    /** The sub-rect of the scene bounding box currently displayed.
     *  Specified in scene coordinates.
     */
    QRectF viewport() const;
    void setViewport(const QRectF &viewport);

    /** The bounding box of the scene.
     *  The viewport cannot exceed this area.
     */
    QRectF sceneBoundingBox() const;
    void setSceneBoundingBox(OSM::BoundingBox bbox);
    void setSceneBoundingBox(const QRectF &bbox);

    /** Converts a point in scene coordinates to screen coordinates. */
    QPointF mapSceneToScreen(QPointF scenePos) const;
    /** Converts a rectanble in scene coordinates to screen coordinates. */
    QRectF mapSceneToScreen(const QRectF &sceneRect) const;
    /** Converts a point in screen coordinates to scene coordinates. */
    QPointF mapScreenToScene(QPointF screenPos) const;
    /** Converts a distance in screen coordinates to a distance in scene coordinates. */
    double mapScreenDistanceToSceneDistance(double distance) const;

    /** Returns how many units in scene coordinate represent the distance of @p meters in the current view transformation. */
    double mapMetersToScene(double meters) const;
    void panScreenSpace(QPoint offset);
    Q_INVOKABLE void zoomIn(QPointF center);
    Q_INVOKABLE void zoomOut(QPointF center);

    /** Position of the viewport in pan coordinates. */
    double panX() const;
    double panY() const;
    /** Size of the pan-able area in screen coordinates. */
    double panWidth() const;
    double panHeight() const;

    /** Move the viewport to the pan coordinates @p x and @p y. */
    Q_INVOKABLE void panTopLeft(double x, double y);

Q_SIGNALS:
    void transformationChanged();
    void floorLevelChanged();

private:
    /** Ensure we stay within the bounding box with the viewport, call after viewport modification. */
    void constrainViewToScene();

    QRectF m_bbox;
    QRectF m_viewport;
    QSize m_screenSize;
    int m_level = 0;
};

}

#endif // KOSMINDOORMAP_VIEW_H
