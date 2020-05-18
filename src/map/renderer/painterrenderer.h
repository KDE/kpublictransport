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

#ifndef KOSMINDOORMAP_PAINTERRENDERER_H
#define KOSMINDOORMAP_PAINTERRENDERER_H

#include <osm/datatypes.h>

#include <QPainter>

class QPaintDevice;

namespace KOSMIndoorMap {

class LabelItem;
class PolygonItem;
class PolylineItem;
class SceneGraph;
class View;

/** QPainter-based renderer of a SceneGraph.
 *  Trying to keep this somewhat backend-agnostic to possibly implement a 3D renderer in the future.
 */
class PainterRenderer
{
public:
    explicit PainterRenderer();
    ~PainterRenderer();

    void setPaintDevice(QPaintDevice *device);
    void render(const SceneGraph &sg, View *view);

private:
    void beginRender();
    void renderBackground(const QColor &bgColor);
    void renderPolygon(PolygonItem *item);
    void renderPolyline(PolylineItem *item);
    void renderLabel(LabelItem *item);
    void endRender();

    QPaintDevice *m_device = nullptr;
    QPainter m_painter;
    View *m_view = nullptr;
};

}

#endif // KOSMINDOORMAP_PAINTERRENDERER_H
