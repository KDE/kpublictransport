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
#include "../scene/scenegraphitem.h"

#include <QDebug>
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
    m_view = view;
    beginRender();
    renderBackground(sg.m_bgColor);

    for (const auto &item : sg.m_items) {
        if (auto i = dynamic_cast<PolygonItem*>(item.get())) {
            renderPolygon(i);
        } else if (auto i = dynamic_cast<PolylineItem*>(item.get())) {
            renderPolyline(i);
        } else if (auto i = dynamic_cast<LabelItem*>(item.get())) {
            renderLabel(i);
        } else {
            qCritical() << "Unsupported scene graph item!";
        }
    }

    endRender();
    m_view = nullptr;
}

void PainterRenderer::beginRender()
{
    m_painter.begin(m_device);
    m_painter.setRenderHint(QPainter::HighQualityAntialiasing);
    m_painter.setTransform(m_view->sceneToScreenTransform());
}

void PainterRenderer::renderBackground(const QColor &bgColor)
{
    m_painter.fillRect(0, 0, m_view->screenWidth(), m_view->screenHeight(), bgColor);
}

void PainterRenderer::renderPolygon(PolygonItem *item)
{
    m_painter.setPen(item->pen);
    m_painter.setBrush(item->brush);
    m_painter.drawPolygon(item->polygon);
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
    m_painter.save();
    m_painter.setTransform({});
    m_painter.setPen(item->color);

    QFontMetricsF fm(QGuiApplication::font());
    auto bbox = fm.boundingRect(item->text);
    bbox.moveCenter(m_view->sceneToScreen(item->pos));
    bbox.adjust(-2, 0, 2, 0); // TODO why do we need this to have the full text visible??
    m_painter.drawText(bbox, item->text);
    m_painter.restore();
}

void PainterRenderer::endRender()
{
    m_painter.end();
}
