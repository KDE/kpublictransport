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

#include "../scene/scenegraphitem.h"

#include <osm/datatypes.h>

class QPainter;

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

    void setPainter(QPainter *painter);
    void render(const SceneGraph &sg, View *view);

private:
    void beginRender();
    void beginPhase(SceneGraphItemPayload::RenderPhase phase);
    void renderBackground(const QColor &bgColor);
    void renderPolygon(PolygonItem *item, SceneGraphItemPayload::RenderPhase phase);
    void renderMultiPolygon(MultiPolygonItem *item, SceneGraphItemPayload::RenderPhase phase);
    void renderPolyline(PolylineItem *item, SceneGraphItemPayload::RenderPhase phase);
    void renderLabel(LabelItem *item);
    void renderForeground(const QColor &bgColor);
    void endRender();

    double mapToSceneWidth(double width, Unit unit) const;

    QPainter *m_painter = nullptr;
    View *m_view = nullptr;

    std::vector<SceneGraphItemPayload*> m_renderBatch; // member rather than function-local to preserve allocations
};

}

#endif // KOSMINDOORMAP_PAINTERRENDERER_H
