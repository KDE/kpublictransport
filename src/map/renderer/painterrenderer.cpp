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

#include "painterrenderer.h"
#include "view.h"

#include "../scene/scenegraph.h"

#include <QDebug>
#include <QElapsedTimer>
#include <QFontMetricsF>
#include <QGuiApplication>
#include <QPainter>

using namespace KOSMIndoorMap;

PainterRenderer::PainterRenderer() = default;
PainterRenderer::~PainterRenderer() = default;

void PainterRenderer::setPaintDevice(QPaintDevice *device)
{
    m_device = device;
}

void PainterRenderer::render(const SceneGraph &sg, View *view)
{
    QElapsedTimer frameTimer;
    frameTimer.start();

    m_view = view;
    beginRender();
    renderBackground(sg.m_bgColor);

    for (const auto &layerOffsets : sg.m_layerOffsets) {
        const auto layerBegin = sg.m_items.begin() + layerOffsets.first;
        const auto layerEnd = sg.m_items.begin() + layerOffsets.second;
        //qDebug() << "rendering layer" << (*layerBegin)->layer;

        // select elements currently in view
        m_renderBatch.clear();
        m_renderBatch.reserve(layerOffsets.second - layerOffsets.first);
        const QRectF screenRect(QPointF(0, 0), QSizeF(m_view->screenWidth(), m_view->screenHeight()));
        for (auto it = layerBegin; it != layerEnd; ++it) {
            if ((*it)->inSceneSpace() && m_view->viewport().intersects((*it)->boundingRect())) {
                m_renderBatch.push_back((*it).get());
            }
            if ((*it)->inHUDSpace()) {
                auto bbox = (*it)->boundingRect();
                bbox.moveCenter(m_view->sceneToScreen(bbox.center()));
                if (screenRect.intersects(bbox)) {
                    m_renderBatch.push_back((*it).get());
                }
            }
        }

        for (auto phase : {SceneGraphItem::FillPhase, SceneGraphItem::CasingPhase, SceneGraphItem::StrokePhase, SceneGraphItem::LabelPhase}) {
            beginPhase(phase);
            for (const auto item : m_renderBatch) {
                if ((item->renderPhases() & phase) == 0) {
                    continue;
                }

                if (auto i = dynamic_cast<PolygonItem*>(item)) {
                    renderPolygon(i, phase);
                } else if (auto i = dynamic_cast<PolylineItem*>(item)) {
                    renderPolyline(i);
                } else if (auto i = dynamic_cast<LabelItem*>(item)) {
                    renderLabel(i);
                } else {
                    qCritical() << "Unsupported scene graph item!";
                }
            }
        }
    }

    endRender();
    m_view = nullptr;

    qDebug() << "rendering took:" << frameTimer.elapsed() << "ms for" << sg.m_items.size() << "items on" << sg.m_layerOffsets.size() << "layers";
}

void PainterRenderer::beginRender()
{
    m_painter.begin(m_device);
    m_painter.setRenderHint(QPainter::HighQualityAntialiasing);
}

void PainterRenderer::renderBackground(const QColor &bgColor)
{
    m_painter.fillRect(0, 0, m_view->screenWidth(), m_view->screenHeight(), bgColor);
}

void PainterRenderer::beginPhase(SceneGraphItem::RenderPhase phase)
{
    switch (phase) {
        case SceneGraphItem::NoPhase:
            Q_UNREACHABLE();
        case SceneGraphItem::FillPhase:
            m_painter.setPen(Qt::NoPen);
            m_painter.setTransform(m_view->sceneToScreenTransform());
            m_painter.setClipRect(m_view->viewport());
            break;
        case SceneGraphItem::CasingPhase:
        case SceneGraphItem::StrokePhase:
            m_painter.setBrush(Qt::NoBrush);
            m_painter.setTransform(m_view->sceneToScreenTransform());
            m_painter.setClipRect(m_view->viewport());
            break;
        case SceneGraphItem::LabelPhase:
            m_painter.setTransform({});
            break;
    }
}

void PainterRenderer::renderPolygon(PolygonItem *item, SceneGraphItem::RenderPhase phase)
{
    if (phase == SceneGraphItem::FillPhase) {
        m_painter.setBrush(item->brush);
        m_painter.drawPolygon(item->polygon);
    } else {
        m_painter.setPen(item->pen);
        m_painter.drawPolygon(item->polygon);
    }
}

void PainterRenderer::renderPolyline(PolylineItem *item)
{
    auto p = item->pen;
    p.setWidthF(p.widthF() * 0.000009009009009009); // TODO proper map projection and distance to scene size conversion
    m_painter.setPen(p);
    m_painter.drawPolyline(item->path);
}

void PainterRenderer::renderLabel(KOSMIndoorMap::LabelItem *item)
{
    m_painter.setPen(item->color);
    m_painter.setFont(item->font);

    if (!item->hasFineBbox) {
        QFontMetricsF fm(item->font);
        item->bbox = fm.boundingRect(item->text);
        item->bbox.moveCenter(item->pos);
        item->bbox.adjust(-2, 0, 2, 0); // TODO why do we need this to have the full text visible??
        item->hasFineBbox = true;
    }

    auto box = item->bbox;
    box.moveCenter(m_view->sceneToScreen(item->pos));
    m_painter.drawText(box.bottomLeft(), item->text);
}

void PainterRenderer::endRender()
{
    m_painter.end();
}
