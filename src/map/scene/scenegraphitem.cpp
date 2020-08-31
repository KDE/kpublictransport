/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "scenegraphitem.h"

#include <QDebug>

using namespace KOSMIndoorMap;

SceneGraphItemPayload::~SceneGraphItemPayload() = default;

bool SceneGraphItemPayload::inSceneSpace() const
{
    return renderPhases() & (FillPhase | StrokePhase | CasingPhase);
}

bool SceneGraphItemPayload::inHUDSpace() const
{
    return renderPhases() & LabelPhase;
}


uint8_t PolylineItem::renderPhases() const
{
    return (pen.style() != Qt::NoPen ? StrokePhase : NoPhase) | (casingPen.style() != Qt::NoPen ? CasingPhase : NoPhase);
}

QRectF PolylineItem::boundingRect() const
{
    return path.boundingRect(); // TODO do we need to cache this?
}


uint8_t PolygonBaseItem::renderPhases() const
{
    return (pen.style() == Qt::NoPen ? NoPhase : StrokePhase) | (brush.style() == Qt::NoBrush ? NoPhase : FillPhase);
}

QRectF PolygonItem::boundingRect() const
{
    return polygon.boundingRect(); // TODO do we need to cache this?
}

QRectF MultiPolygonItem::boundingRect() const
{
    return path.boundingRect(); // TODO do we need to cache this?
}


uint8_t LabelItem::renderPhases() const
{
    return LabelPhase;
}

QRectF LabelItem::boundingRect() const
{
    QRectF bbox;
    if (!text.text().isEmpty()) {
        bbox = QRectF(QPointF(0.0, 0.0), text.size());
    }
    if (!icon.isNull()) {
        bbox.setHeight(bbox.height() + iconSize.height());
        bbox.setWidth(std::max(bbox.width(), iconSize.width()));
    }

    bbox.moveCenter(pos);
    const auto shieldSize = std::max(frameWidth, haloRadius) + casingWidth;
    bbox.adjust(-shieldSize, -shieldSize, shieldSize, shieldSize);
    return bbox;
}
