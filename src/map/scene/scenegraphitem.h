/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_SCENEGRAPHITEM_H
#define KOSMINDOORMAP_SCENEGRAPHITEM_H

#include <osm/element.h>

#include <QBrush>
#include <QColor>
#include <QFont>
#include <QIcon>
#include <QPainterPath>
#include <QPen>
#include <QPolygonF>
#include <QStaticText>
#include <QString>

#include <memory>

namespace KOSMIndoorMap {

class SceneGraphItemPayload;

/** Unit for geometry sizes. */
enum class Unit : uint8_t {
    Pixel,
    Meter,
};

/** Scene graph item description and handle for its content.
 *  This is a minimal and cheap part that can be used allocation-free,
 *  and it holds the expensive polymorphic parts (geometry, materials) depending on the
 *  type of this is item.
 *  This split allows to use this part for searching/sorting/indexing.
 */
class SceneGraphItem
{
public:
    /** The OSM::Element this item refers to. */
    OSM::Element element;

    int level = 0;
    int layer = 0;

    std::unique_ptr<SceneGraphItemPayload> payload;
};

/** Payload base class for scene graph items. */
class SceneGraphItemPayload
{
public:
    virtual ~SceneGraphItemPayload();

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

    int z = 0;
};


/** A path/way/line item in the scenegraph. */
class PolylineItem : public SceneGraphItemPayload
{
public:
    uint8_t renderPhases() const override;
    QRectF boundingRect() const override;

    QPolygonF path;
    QPen pen;
    QPen casingPen;
    Unit penWidthUnit = Unit::Meter;
    Unit casingPenWidthUnit = Unit::Pixel;
};


/** Base item for filled polygons. */
class PolygonBaseItem : public SceneGraphItemPayload
{
public:
    uint8_t renderPhases() const override;

    QBrush brush = Qt::NoBrush;
    QPen pen;
    Unit penWidthUnit = Unit::Pixel;
};


/** A single filled polygon. */
class PolygonItem : public PolygonBaseItem
{
public:
    QRectF boundingRect() const override;

    QPolygonF polygon;
};


/** Multi-polygon item, used for polygons with "holes" in them. */
class MultiPolygonItem : public PolygonBaseItem
{
public:
    QRectF boundingRect() const override;

    QPainterPath path;
};

/** A text or item label */
class LabelItem : public SceneGraphItemPayload
{
public:
    uint8_t renderPhases() const override;
    QRectF boundingRect() const override;

    QPointF pos;
    QColor color;
    QFont font;
    QStaticText text;

    QIcon icon;
    QSizeF iconSize;

    double casingWidth = 0.0;
    QColor casingColor = Qt::transparent;
    double frameWidth = 0.0;
    QColor frameColor = Qt::transparent;
    QColor shieldColor = Qt::transparent;

    double angle = 0.0;
    double offset = 0.0;

    QColor haloColor = Qt::transparent;
    double haloRadius = 0.0;
};


}

#endif // KOSMINDOORMAP_SCENEGRAPHITEM_H
