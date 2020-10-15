/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_PAINTERRENDERER_H
#define KOSMINDOORMAP_PAINTERRENDERER_H

#include "kosmindoormap_export.h"

#include <KOSMIndoorMap/SceneGraphItem>

class QPainter;

namespace KOSMIndoorMap {

class SceneGraph;
class View;

/** QPainter-based renderer of a SceneGraph.
 *  Trying to keep this somewhat backend-agnostic to possibly implement a 3D renderer in the future.
 */
class KOSMINDOORMAP_EXPORT PainterRenderer
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
