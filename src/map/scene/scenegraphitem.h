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

#ifndef KOSMINDOORMAP_SCENEGRAPHITEM_H
#define KOSMINDOORMAP_SCENEGRAPHITEM_H

#include <QBrush>
#include <QColor>
#include <QFont>
#include <QPainterPath>
#include <QPen>
#include <QPolygonF>
#include <QString>

namespace KOSMIndoorMap {

/** Base class for scene graph items. */
class SceneGraphItem
{
public:
    virtual ~SceneGraphItem();

    /** See MapCSS spec: "Within a layer, first all fills are rendered, then all casings, then all strokes, then all icons and labels." .*/
    enum RenderPhase : uint8_t {
        NoPhase = 0,
        FillPhase = 1,
        CasingPhase = 2,
        StrokePhase = 4,
        LabelPhase = 8,
    };
    /** Returns in which phase this item needs to be rendered (can be multiple). */
    virtual uint8_t renderPhases() const = 0;

    /** Bounding box of this item in scene coordinates.
     *  Performance trumps precision here, so estimating this slightly larger rather than computing it expensively makes sense.
     */
    virtual QRectF boundingRect() const = 0;

    /** Is this item drawn in scene coordinates (as oposed to HUD coordinates)? */
    bool inSceneSpace() const;
    /** Is this item drawn in HUD coordinates (as oposed to scene coordinates)? */
    bool inHUDSpace() const;

    // TODO we probably don't need the full 32bit for those
    int layer = 0;
    int z = 0;
};


/** A path/way/line item in the scenegraph. */
class PolylineItem : public SceneGraphItem
{
public:
    uint8_t renderPhases() const override;
    QRectF boundingRect() const override;

    QPolygonF path;
    QPen pen = Qt::NoPen;
    QPen casingPen = Qt::NoPen;
};


/** Base item for filled polygons. */
class PolygonBaseItem : public SceneGraphItem
{
public:
    uint8_t renderPhases() const override;

    QBrush brush = Qt::NoBrush;
    QPen pen = Qt::NoPen;
};


/** A single filled polygon. */
class PolygonItem : public PolygonBaseItem
{
public:
    QRectF boundingRect() const override;

    QPolygonF polygon;
};


/** Multi-polygon item, used for polygons with "holes" in them. */
class MultiPolygonItm : public PolygonBaseItem
{
public:
    QRectF boundingRect() const override;

    QPainterPath path;
};

/** A text or item label */
class LabelItem : public SceneGraphItem
{
public:
    uint8_t renderPhases() const override;
    QRectF boundingRect() const override;

    QPointF pos;
    QString text;
    QColor color;
    QFont font;
    mutable QRectF bbox;
    bool hasFineBbox = false;
};


}

#endif // KOSMINDOORMAP_SCENEGRAPHITEM_H
