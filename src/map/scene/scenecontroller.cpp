/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "scenecontroller.h"
#include "logging.h"
#include "render-logging.h"

#include "iconloader_p.h"
#include "penwidthutil_p.h"
#include "scenegeometry_p.h"
#include "../style/mapcssdeclaration_p.h"
#include "../style/mapcssstate_p.h"
#include "../style/mapcssresult_p.h"

#include <KOSMIndoorMap/MapData>
#include <KOSMIndoorMap/MapCSSStyle>
#include <KOSMIndoorMap/OverlaySource>
#include <KOSMIndoorMap/SceneGraph>
#include <KOSMIndoorMap/View>

#include <osm/element.h>
#include <osm/datatypes.h>

#include <QDebug>
#include <QElapsedTimer>
#include <QGuiApplication>
#include <QPalette>

namespace KOSMIndoorMap {
class SceneControllerPrivate
{
public:
    const MapData *m_data = nullptr;
    const MapCSSStyle *m_styleSheet = nullptr;
    const View *m_view = nullptr;
    std::vector<OverlaySource> m_overlaySources;
    mutable std::vector<OSM::Element> m_hiddenElements;

    MapCSSResult m_styleResult;
    QColor m_defaultTextColor;
    QFont m_defaultFont;
    QPolygonF m_labelPlacementPath;
    IconLoader m_iconLoader;

    OSM::TagKey m_layerTag;
    OSM::TagKey m_typeTag;

    bool m_dirty = true;
    bool m_overlay = false;
};
}

using namespace KOSMIndoorMap;

SceneController::SceneController() : d(new SceneControllerPrivate) {}
SceneController::~SceneController() = default;

void SceneController::setDataSet(const MapData *data)
{
    d->m_data = data;
    if (d->m_data) {
        d->m_layerTag = data->dataSet().tagKey("layer");
        d->m_typeTag = data->dataSet().tagKey("type");
    } else {
        d->m_layerTag = {};
        d->m_typeTag = {};
    }
    d->m_dirty = true;
}

void SceneController::setStyleSheet(const MapCSSStyle *styleSheet)
{
    d->m_styleSheet = styleSheet;
    d->m_dirty = true;
}

void SceneController::setView(const View *view)
{
    d->m_view = view;
    d->m_dirty = true;
}

void SceneController::setOverlaySources(std::vector<OverlaySource> &&overlays)
{
    d->m_overlaySources = std::move(overlays);
    d->m_dirty = true;
}

void SceneController::overlaySourceUpdated()
{
    // TODO we could potentially do this more fine-grained?
    d->m_dirty = true;
}

void SceneController::updateScene(SceneGraph &sg) const
{
    QElapsedTimer sgUpdateTimer;
    sgUpdateTimer.start();

    // check if we are set up completely yet (we can't rely on a defined order with QML)
    if (!d->m_view || !d->m_styleSheet) {
        return;
    }

    // check if the scene is dirty at all
    if (sg.zoomLevel() == (int)d->m_view->zoomLevel() && sg.currentFloorLevel() == d->m_view->level() && !d->m_dirty) {
        return;
    }
    sg.setZoomLevel(d->m_view->zoomLevel());
    sg.setCurrentFloorLevel(d->m_view->level());
    d->m_dirty = false;

    sg.beginSwap();
    updateCanvas(sg);

    if (!d->m_data) { // if we don't have map data yet, we just need to get canvas styling here
        sg.endSwap();
        return;
    }

    // find all intermediate levels below or above the currently selected "full" level
    auto it = d->m_data->m_levelMap.find(MapLevel(d->m_view->level()));
    if (it == d->m_data->m_levelMap.end()) {
        return;
    }

    auto beginIt = it;
    if (beginIt != d->m_data->m_levelMap.begin()) {
        do {
            --beginIt;
        } while (!(*beginIt).first.isFullLevel() && beginIt != d->m_data->m_levelMap.begin());
        ++beginIt;
    }

    auto endIt = it;
    for (++endIt; endIt != d->m_data->m_levelMap.end(); ++endIt) {
        if ((*endIt).first.isFullLevel()) {
            break;
        }
    }

    // collect elements that the overlay want to hide
    d->m_hiddenElements.clear();
    for (const auto &overlaySource : d->m_overlaySources) {
        overlaySource.hiddenElements(d->m_hiddenElements);
    }
    std::sort(d->m_hiddenElements.begin(), d->m_hiddenElements.end());

    // for each level, update or create scene graph elements, after a some basic bounding box check
    const auto geoBbox = d->m_view->mapSceneToGeo(d->m_view->sceneBoundingBox());
    for (auto it = beginIt; it != endIt; ++it) {
        for (auto e : (*it).second) {
            if (OSM::intersects(geoBbox, e.boundingBox()) && !std::binary_search(d->m_hiddenElements.begin(), d->m_hiddenElements.end(), e)) {
                updateElement(e, (*it).first.numericLevel(), sg);
            }
        }
    }

    // update overlay elements
    d->m_overlay = true;
    for (const auto &overlaySource : d->m_overlaySources) {
        overlaySource.forEach(d->m_view->level(), [this, &geoBbox, &sg](OSM::Element e, int floorLevel) {
            if (OSM::intersects(geoBbox, e.boundingBox()) && e.type() != OSM::Type::Null) {
                updateElement(e, floorLevel, sg);
            }
        });
    }
    d->m_overlay = false;

    sg.zSort();
    sg.endSwap();

    qCDebug(RenderLog) << "updated scenegraph took" << sgUpdateTimer.elapsed() << "ms";
}

void SceneController::updateCanvas(SceneGraph &sg) const
{
    sg.setBackgroundColor(QGuiApplication::palette().color(QPalette::Base));
    d->m_defaultTextColor = QGuiApplication::palette().color(QPalette::Text);
    d->m_defaultFont = QGuiApplication::font();

    MapCSSState state;
    state.zoomLevel = d->m_view->zoomLevel();
    state.floorLevel = d->m_view->level();
    d->m_styleSheet->evaluateCanvas(state, d->m_styleResult);
    for (auto decl : d->m_styleResult.declarations()) {
        switch (decl->property()) {
            case MapCSSDeclaration::FillColor:
                sg.setBackgroundColor(decl->colorValue());
                break;
            case MapCSSDeclaration::TextColor:
                d->m_defaultTextColor = decl->colorValue();
                break;
            default:
                break;
        }
    }
}

void SceneController::updateElement(OSM::Element e, int level, SceneGraph &sg) const
{
    MapCSSState state;
    state.element = e;
    state.zoomLevel = d->m_view->zoomLevel();
    state.floorLevel = d->m_view->level();
    d->m_styleSheet->evaluate(state, d->m_styleResult);

    if (d->m_styleResult.hasAreaProperties()) {
        PolygonBaseItem *item = nullptr;
        std::unique_ptr<SceneGraphItemPayload> baseItem;
        if (e.type() == OSM::Type::Relation && e.tagValue(d->m_typeTag) == "multipolygon") {
            baseItem = sg.findOrCreatePayload<MultiPolygonItem>(e, level);
            auto i = static_cast<MultiPolygonItem*>(baseItem.get());
            if (i->path.isEmpty()) {
                i->path = createPath(e, d->m_labelPlacementPath);
            } else if (d->m_styleResult.hasLabelProperties()) {
                SceneGeometry::outerPolygonFromPath(i->path, d->m_labelPlacementPath);
            }
            item = i;
        } else {
            baseItem = sg.findOrCreatePayload<PolygonItem>(e, level);
            auto i = static_cast<PolygonItem*>(baseItem.get());
            if (i->polygon.isEmpty()) {
                i->polygon = createPolygon(e);
            }
            d->m_labelPlacementPath = i->polygon;
            item = i;
        }

        double lineOpacity = 1.0;
        double fillOpacity = 1.0;
        initializePen(item->pen);
        for (auto decl : d->m_styleResult.declarations()) {
            applyGenericStyle(decl, item);
            applyPenStyle(e, decl, item->pen, lineOpacity, item->penWidthUnit);
            switch (decl->property()) {
                case MapCSSDeclaration::FillColor:
                    item->brush.setColor(decl->colorValue());
                    item->brush.setStyle(Qt::SolidPattern);
                    break;
                case MapCSSDeclaration::FillOpacity:
                    fillOpacity = decl->doubleValue();
                    break;
                default:
                    break;
            }
        }
        finalizePen(item->pen, lineOpacity);
        if (item->brush.style() == Qt::SolidPattern && fillOpacity < 1.0) {
            auto c = item->brush.color();
            c.setAlphaF(c.alphaF() * fillOpacity);
            item->brush.setColor(c);
        }
        if (item->brush.color().alphaF() == 0.0) {
            item->brush.setStyle(Qt::NoBrush);
        }

        addItem(sg, e, level, std::move(baseItem));
    } else if (d->m_styleResult.hasLineProperties()) {
        auto baseItem = sg.findOrCreatePayload<PolylineItem>(e, level);
        auto item = static_cast<PolylineItem*>(baseItem.get());
        if (item->path.isEmpty()) {
            item->path = createPolygon(e);
        }

        double lineOpacity = 1.0;
        double casingOpacity = 1.0;
        initializePen(item->pen);
        initializePen(item->casingPen);
        for (auto decl : d->m_styleResult.declarations()) {
            applyGenericStyle(decl, item);
            applyPenStyle(e, decl, item->pen, lineOpacity, item->penWidthUnit);
            applyCasingPenStyle(e, decl, item->casingPen, casingOpacity, item->casingPenWidthUnit);
        }
        finalizePen(item->pen, lineOpacity);
        finalizePen(item->casingPen, casingOpacity);

        d->m_labelPlacementPath = item->path;
        addItem(sg, e, level, std::move(baseItem));
    }

    if (d->m_styleResult.hasLabelProperties()) {
        QString text;
        auto textDecl = d->m_styleResult.declaration(MapCSSDeclaration::Text);
        if (!textDecl) {
            textDecl = d->m_styleResult.declaration(MapCSSDeclaration::ShieldText);
        }

        if (textDecl) {
            if (!textDecl->keyValue().isEmpty()) {
                text = QString::fromUtf8(e.tagValue(textDecl->keyValue().constData(), QLocale()));
            } else {
                text = textDecl->stringValue();
            }
        }

        const auto iconDecl = d->m_styleResult.declaration(MapCSSDeclaration::IconImage);

        if (!text.isEmpty() || iconDecl) {
            auto baseItem = sg.findOrCreatePayload<LabelItem>(e, level);
            auto item = static_cast<LabelItem*>(baseItem.get());
            item->text.setText(text);
            item->font = d->m_defaultFont;
            item->color = d->m_defaultTextColor;

            if (item->pos.isNull()) {
                if (d->m_styleResult.hasAreaProperties()) {
                    item->pos = SceneGeometry::polygonCentroid(d->m_labelPlacementPath);
                } else if (d->m_styleResult.hasLineProperties()) {
                    item->pos = SceneGeometry::polylineMidPoint(d->m_labelPlacementPath);
                }
                if (item->pos.isNull()) {
                    item->pos = d->m_view->mapGeoToScene(e.center()); // node or something failed above
                }
            }

            double textOpacity = 1.0;
            double shieldOpacity = 1.0;
            IconData iconData;
            for (auto decl : d->m_styleResult.declarations()) {
                applyGenericStyle(decl, item);
                applyFontStyle(decl, item->font);
                switch (decl->property()) {
                    case MapCSSDeclaration::TextColor:
                        item->color = decl->colorValue();
                        break;
                    case MapCSSDeclaration::TextOpacity:
                        textOpacity = decl->doubleValue();
                        break;
                    case MapCSSDeclaration::ShieldCasingColor:
                        item->casingColor = decl->colorValue();
                        break;
                    case MapCSSDeclaration::ShieldCasingWidth:
                        item->casingWidth = decl->doubleValue();
                        break;
                    case MapCSSDeclaration::ShieldColor:
                        item->shieldColor = decl->colorValue();
                        break;
                    case MapCSSDeclaration::ShieldOpacity:
                        shieldOpacity = decl->doubleValue();
                        break;
                    case MapCSSDeclaration::ShieldFrameColor:
                        item->frameColor = decl->colorValue();
                        break;
                    case MapCSSDeclaration::ShieldFrameWidth:
                        item->frameWidth = decl->doubleValue();
                        break;
                    case MapCSSDeclaration::TextPosition:
                        if (decl->textFollowsLine() && d->m_labelPlacementPath.size() > 1) {
                            item->angle = SceneGeometry::polylineMidPointAngle(d->m_labelPlacementPath);
                        }
                        break;
                    case MapCSSDeclaration::TextOffset:
                        item->offset = decl->doubleValue();
                        break;
                    case MapCSSDeclaration::MaxWidth:
                        item->text.setTextWidth(decl->intValue());
                        break;
                    case MapCSSDeclaration::IconImage:
                        if (!decl->keyValue().isEmpty()) {
                            iconData.name = QString::fromUtf8(e.tagValue(decl->keyValue().constData()));
                        } else {
                            iconData.name = decl->stringValue();
                        }
                        break;
                    case MapCSSDeclaration::IconHeight:
                        item->iconSize.setHeight(decl->doubleValue()); // TODO percent sizes
                        break;
                    case MapCSSDeclaration::IconWidth:
                        item->iconSize.setWidth(decl->doubleValue()); // TODO percent sizes
                        break;
                    case MapCSSDeclaration::IconColor:
                    {
                        const auto alpha = iconData.color.alphaF();
                        iconData.color = decl->colorValue().rgb();
                        iconData.color.setAlphaF(alpha);
                        break;
                    }
                    case MapCSSDeclaration::IconOpacity:
                        iconData.color.setAlphaF(decl->doubleValue());
                        break;
                    case MapCSSDeclaration::TextHaloColor:
                        item->haloColor = decl->colorValue();
                        break;
                    case MapCSSDeclaration::TextHaloRadius:
                        item->haloRadius = decl->doubleValue();
                        break;
                    default:
                        break;
                }
            }
            if (item->color.isValid() && textOpacity < 1.0) {
                auto c = item->color;
                c.setAlphaF(c.alphaF() * textOpacity);
                item->color = c;
            }
            if (item->shieldColor.isValid() && shieldOpacity < 1.0) {
                auto c = item->shieldColor;
                c.setAlphaF(c.alphaF() * shieldOpacity);
                item->shieldColor = c;
            }
            if (!iconData.name.isEmpty() && iconData.color.alphaF() > 0.0) {
                if (!iconData.color.isValid()) {
                    iconData.color = d->m_defaultTextColor;
                }
                item->icon = d->m_iconLoader.loadIcon(iconData);
            }
            if (!item->icon.isNull()) {
                const auto iconSourceSize = item->icon.availableSizes().at(0);
                const auto aspectRatio = (double)iconSourceSize.width() / (double)iconSourceSize.height();
                if (item->iconSize.width() <= 0.0 && item->iconSize.height() <= 0.0) {
                    item->iconSize = iconSourceSize;
                } else if (item->iconSize.width() <= 0.0) {
                    item->iconSize.setWidth(item->iconSize.height() * aspectRatio);
                } else if (item->iconSize.height() <= 0.0) {
                    item->iconSize.setHeight(item->iconSize.width() / aspectRatio);
                }
            }

            if (!item->text.text().isEmpty()) {
                QTextOption opt;
                opt.setAlignment(Qt::AlignHCenter);
                opt.setWrapMode(item->text.textWidth() > 0.0 ? QTextOption::WordWrap : QTextOption::NoWrap);
                item->text.setTextOption(opt);
                item->text.prepare({}, item->font);

                // discard labels that are longer than the line they are aligned with
                if (d->m_styleResult.hasLineProperties() && d->m_labelPlacementPath.size() > 1 && item->angle != 0.0) {
                    const auto sceneLen = SceneGeometry::polylineLength(d->m_labelPlacementPath);
                    const auto sceneP1 = d->m_view->viewport().topLeft();
                    const auto sceneP2 = QPointF(sceneP1.x() + sceneLen, sceneP1.y());
                    const auto screenP1 = d->m_view->mapSceneToScreen(sceneP1);
                    const auto screenP2 = d->m_view->mapSceneToScreen(sceneP2);
                    const auto screenLen = screenP2.x() - screenP1.x();
                    if (screenLen < item->text.size().width()) {
                        item->text = {};
                    }
                }
            }

            if (!item->icon.isNull() || !item->text.text().isEmpty()) {
                addItem(sg, e, level, std::move(baseItem));
            }
        }
    }
}

QPolygonF SceneController::createPolygon(OSM::Element e) const
{
    const auto path = e.outerPath(d->m_data->dataSet());
    QPolygonF poly;
    poly.reserve(path.size());
    for (auto node : path) {
        poly.push_back(d->m_view->mapGeoToScene(node->coordinate));
    }
    return poly;
}

// @see https://wiki.openstreetmap.org/wiki/Relation:multipolygon
QPainterPath SceneController::createPath(const OSM::Element e, QPolygonF &outerPath) const
{
    assert(e.type() == OSM::Type::Relation);
    outerPath = createPolygon(e);
    QPainterPath path;
    path.addPolygon(outerPath); // assemble the outer polygon, which can be represented as a set of unsorted lines here even

    for (const auto &mem : e.relation()->members) {
        const bool isInner = std::strcmp(mem.role().name(), "inner") == 0;
        if (mem.type() != OSM::Type::Way || !isInner) {
            continue;
        }
        if (auto way = d->m_data->dataSet().way(mem.id)) {
            const auto subPoly = createPolygon(OSM::Element(way));
            QPainterPath subPath;
            subPath.addPolygon(subPoly);
            path = path.subtracted(subPath);
        }
    }

    return path;
}

void SceneController::applyGenericStyle(const MapCSSDeclaration *decl, SceneGraphItemPayload *item) const
{
    if (decl->property() == MapCSSDeclaration::ZIndex) {
        item->z = decl->intValue();
    }
}

void SceneController::applyPenStyle(OSM::Element e, const MapCSSDeclaration *decl, QPen &pen, double &opacity, Unit &unit) const
{
    switch (decl->property()) {
        case MapCSSDeclaration::Color:
            pen.setColor(decl->colorValue());
            break;
        case MapCSSDeclaration::Width:
            pen.setWidthF(PenWidthUtil::penWidth(e, decl, unit));
            break;
        case MapCSSDeclaration::Dashes:
            pen.setDashPattern(decl->dashesValue());
            break;
        case MapCSSDeclaration::LineCap:
            pen.setCapStyle(decl->capStyle());
            break;
        case MapCSSDeclaration::LineJoin:
            pen.setJoinStyle(decl->joinStyle());
            break;
        case MapCSSDeclaration::Opacity:
            opacity = decl->doubleValue();
            break;
        default:
            break;
    }
}

void SceneController::applyCasingPenStyle(OSM::Element e, const MapCSSDeclaration *decl, QPen &pen, double &opacity, Unit &unit) const
{
    switch (decl->property()) {
        case MapCSSDeclaration::CasingColor:
            pen.setColor(decl->colorValue());
            break;
        case MapCSSDeclaration::CasingWidth:
            pen.setWidthF(PenWidthUtil::penWidth(e, decl, unit));
            break;
        case MapCSSDeclaration::CasingDashes:
            pen.setDashPattern(decl->dashesValue());
            break;
        case MapCSSDeclaration::CasingLineCap:
            pen.setCapStyle(decl->capStyle());
            break;
        case MapCSSDeclaration::CasingLineJoin:
            pen.setJoinStyle(decl->joinStyle());
            break;
        case MapCSSDeclaration::CasingOpacity:
            opacity = decl->doubleValue();
            break;
        default:
            break;
    }
}

void SceneController::applyFontStyle(const MapCSSDeclaration *decl, QFont &font) const
{
    switch (decl->property()) {
        case MapCSSDeclaration::FontFamily:
            font.setFamily(decl->stringValue());
            break;
        case MapCSSDeclaration::FontSize:
            if (decl->unit() == MapCSSDeclaration::Pixels) {
                font.setPixelSize(decl->doubleValue());
            } else {
                font.setPointSizeF(decl->doubleValue());
            }
            break;
        case MapCSSDeclaration::FontWeight:
            font.setBold(decl->isBoldStyle());
            break;
        case MapCSSDeclaration::FontStyle:
            font.setItalic(decl->isItalicStyle());
            break;
        case MapCSSDeclaration::FontVariant:
            font.setCapitalization(decl->capitalizationStyle());
            break;
        case MapCSSDeclaration::TextDecoration:
            font.setUnderline(decl->isUnderlineStyle());
            break;
        case MapCSSDeclaration::TextTransform:
            font.setCapitalization(decl->capitalizationStyle());
            break;
        default:
            break;
    }
}

void SceneController::initializePen(QPen &pen) const
{
    pen.setColor(Qt::transparent);

    // default according to spec
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setStyle(Qt::SolidLine);
}

void SceneController::finalizePen(QPen &pen, double opacity) const
{
    if (pen.color().isValid() && opacity < 1.0) {
        auto c = pen.color();
        c.setAlphaF(c.alphaF() * opacity);
        pen.setColor(c);
    }

    if (pen.color().alphaF() == 0.0) {
        pen.setStyle(Qt::NoPen); // so the renderer can skip this entirely
    }

    // normalize dash pattern, as QPainter scales that with the line width
    if (pen.widthF() > 0.0 && !pen.dashPattern().isEmpty()) {
        auto dashes = pen.dashPattern();
        std::for_each(dashes.begin(), dashes.end(), [pen](double &d) { d /= pen.widthF(); });
        pen.setDashPattern(std::move(dashes));
    }
}

void SceneController::addItem(SceneGraph &sg, OSM::Element e, int level, std::unique_ptr<SceneGraphItemPayload> &&payload) const
{
    SceneGraphItem item;
    item.element = e;
    item.level = level;
    item.payload = std::move(payload);

    // get the OSM layer, if set
    if (!d->m_overlay) {
        const auto layerStr = e.tagValue(d->m_layerTag);
        if (!layerStr.isEmpty()) {
            bool success = false;
            const auto layer = layerStr.toInt(&success);
            if (success) {

                // ### Ignore layer information when it matches the level
                // This is very wrong according to the specification, however it looks that in many places
                // layer and level tags aren't correctly filled, possibly a side-effect of layer pre-dating
                // level and layers not having been properly updated when retrofitting level information
                // Strictly following the MapCSS rendering order yields sub-optimal results in that case, with
                // relevant elements being hidden.
                //
                // Ideally we find a way to detect the presence of that problem, and only then enabling this
                // workaround, but until we have this, this seems to produce better results in all tests.
                if (level != layer * 10) {
                    item.layer = layer;
                }
            } else {
                qCWarning(Log) << "Invalid layer:" << e.url() << layerStr;
            }
        }
    } else {
        item.layer = std::numeric_limits<int>::max();
    }

    sg.addItem(std::move(item));
}
