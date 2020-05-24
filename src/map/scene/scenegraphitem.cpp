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

#include "scenegraphitem.h"

#include <QDebug>
#include <QFontMetrics>

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
    if (bbox.isValid()) {
        return bbox;
    }

    QFontMetricsF fm(font);
    bbox = QRectF(QPointF(0, 0), QPointF(fm.maxWidth() * text.size(), fm.lineSpacing() * text.size()));
    bbox.moveCenter(pos);
    return bbox;
}
