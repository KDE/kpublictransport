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

#include "scenecontroller.h"
#include "logging.h"
#include "render-logging.h"

#include "overlaysource.h"
#include "scenegeometry.h"
#include "scenegraph.h"

#include "../loader/mapdata.h"
#include "../renderer/view.h"
#include "../style/mapcssdeclaration.h"
#include "../style/mapcssstyle.h"
#include "../style/mapcssstate.h"

#include <osm/element.h>
#include <osm/datatypes.h>

#include <QDebug>
#include <QElapsedTimer>
#include <QGuiApplication>
#include <QPalette>

using namespace KOSMIndoorMap;

SceneController::SceneController() = default;
SceneController::~SceneController() = default;

void SceneController::setDataSet(const MapData *data)
{
    m_data = data;
    if (m_data) {
        m_layerTag = data->dataSet().tagKey("layer");
        m_typeTag = data->dataSet().tagKey("type");
    } else {
        m_layerTag = {};
        m_typeTag = {};
    }
    m_dirty = true;
}

void SceneController::setStyleSheet(const MapCSSStyle *styleSheet)
{
    m_styleSheet = styleSheet;
    m_dirty = true;
}

void SceneController::setView(const View *view)
{
    m_view = view;
    m_dirty = true;
}

void SceneController::setOverlaySources(std::vector<OverlaySource> &&overlays)
{
    m_overlaySources = std::move(overlays);
    m_dirty = true;
}

void SceneController::overlaySourceUpdated()
{
    // TODO we could potentially do this more fine-grained?
    m_dirty = true;
}

static bool isTaglessNode(OSM::Element e)
{
    return e.type() == OSM::Type::Node && std::distance(e.tagsBegin(), e.tagsEnd()) == 0;
}

void SceneController::updateScene(SceneGraph &sg) const
{
    QElapsedTimer sgUpdateTimer;
    sgUpdateTimer.start();

    // check if we are set up completely yet (we can't rely on a defined order with QML)
    if (!m_view || !m_styleSheet) {
        return;
    }

    // check if the scene is dirty at all
    if (sg.zoomLevel() == (int)m_view->zoomLevel() && sg.currentFloorLevel() == m_view->level() && !m_dirty) {
        return;
    }
    sg.setZoomLevel(m_view->zoomLevel());
    sg.setCurrentFloorLevel(m_view->level());
    m_dirty = false;

    sg.beginSwap();
    updateCanvas(sg);

    if (!m_data) { // if we don't have map data yet, we just need to get canvas styling here
        sg.endSwap();
        return;
    }

    // find all intermediate levels below or above the currently selected "full" level
    auto it = m_data->m_levelMap.find(MapLevel(m_view->level()));
    if (it == m_data->m_levelMap.end()) {
        return;
    }

    auto beginIt = it;
    if (beginIt != m_data->m_levelMap.begin()) {
        do {
            --beginIt;
        } while (!(*beginIt).first.isFullLevel() && beginIt != m_data->m_levelMap.begin());
        ++beginIt;
    }

    auto endIt = it;
    for (++endIt; endIt != m_data->m_levelMap.end(); ++endIt) {
        if ((*endIt).first.isFullLevel()) {
            break;
        }
    }

    // for each level, update or create scene graph elements, after a some basic bounding box check
    const auto geoBbox = m_view->mapSceneToGeo(m_view->sceneBoundingBox());
    for (auto it = beginIt; it != endIt; ++it) {
        for (auto e : (*it).second) {
            // tag-less nodes cannot practically result in visual effects, so we can skip MapCSS evaluation for them
            // this cuts CSS eval cost in half
            // (in theory you could have a label set on them, but that makes no sense)
            if (OSM::intersects(geoBbox, e.boundingBox()) && !isTaglessNode(e)) {
                updateElement(e, (*it).first.numericLevel(), sg);
            }
        }
    }

    // update overlay elements
    m_overlay = true;
    for (const auto &overlaySource : m_overlaySources) {
        overlaySource.forEach(m_view->level(), [this, &geoBbox, &sg](OSM::Element e, int floorLevel) {
            if (OSM::intersects(geoBbox, e.boundingBox()) && e.type() != OSM::Type::Null && !isTaglessNode(e)) {
                updateElement(e, floorLevel, sg);
            }
        });
    }
    m_overlay = false;

    sg.zSort();
    sg.endSwap();

    qCDebug(RenderLog) << "updated scenegraph took" << sgUpdateTimer.elapsed() << "ms";
}

void SceneController::updateCanvas(SceneGraph &sg) const
{
    sg.setBackgroundColor(QGuiApplication::palette().color(QPalette::Base));
    m_defaultTextColor = QGuiApplication::palette().color(QPalette::Text);
    m_defaultFont = QGuiApplication::font();

    m_styleSheet->evaluateCanvas(m_styleResult);
    for (auto decl : m_styleResult.declarations()) {
        switch (decl->property()) {
            case MapCSSDeclaration::FillColor:
                sg.setBackgroundColor(decl->colorValue());
                break;
            case MapCSSDeclaration::TextColor:
                m_defaultTextColor = decl->colorValue();
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
    state.zoomLevel = m_view->zoomLevel();
    m_styleSheet->evaluate(state, m_styleResult);

    if (m_styleResult.hasAreaProperties()) {
        PolygonBaseItem *item = nullptr;
        std::unique_ptr<SceneGraphItemPayload> baseItem;
        if (e.type() == OSM::Type::Relation && e.tagValue(m_typeTag) == "multipolygon") {
            baseItem = sg.findOrCreatePayload<MultiPolygonItem>(e, level);
            auto i = static_cast<MultiPolygonItem*>(baseItem.get());
            if (i->path.isEmpty()) {
                i->path = createPath(e, m_labelPlacementPath);
            } else if (m_styleResult.hasLabelProperties()) {
                SceneGeometry::outerPolygonFromPath(i->path, m_labelPlacementPath);
            }
            item = i;
        } else {
            baseItem = sg.findOrCreatePayload<PolygonItem>(e, level);
            auto i = static_cast<PolygonItem*>(baseItem.get());
            if (i->polygon.isEmpty()) {
                i->polygon = createPolygon(e);
            }
            m_labelPlacementPath = i->polygon;
            item = i;
        }

        double lineOpacity = 1.0;
        double fillOpacity = 1.0;
        initializePen(item->pen);
        for (auto decl : m_styleResult.declarations()) {
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
    } else if (m_styleResult.hasLineProperties()) {
        auto baseItem = sg.findOrCreatePayload<PolylineItem>(e, level);
        auto item = static_cast<PolylineItem*>(baseItem.get());
        if (item->path.isEmpty()) {
            item->path = createPolygon(e);
        }

        double lineOpacity = 1.0;
        double casingOpacity = 1.0;
        initializePen(item->pen);
        initializePen(item->casingPen);
        for (auto decl : m_styleResult.declarations()) {
            applyGenericStyle(decl, item);
            applyPenStyle(e, decl, item->pen, lineOpacity, item->penWidthUnit);
            applyCasingPenStyle(e, decl, item->casingPen, casingOpacity, item->casingPenWidthUnit);
        }
        finalizePen(item->pen, lineOpacity);
        finalizePen(item->casingPen, casingOpacity);

        m_labelPlacementPath = item->path;
        addItem(sg, e, level, std::move(baseItem));
    }

    if (m_styleResult.hasLabelProperties()) {
        QString text;
        auto textDecl = m_styleResult.declaration(MapCSSDeclaration::Text);
        if (!textDecl) {
            textDecl = m_styleResult.declaration(MapCSSDeclaration::ShieldText);
        }

        if (textDecl) {
            if (!textDecl->keyValue().isEmpty()) {
                text = QString::fromUtf8(e.tagValue(textDecl->keyValue().constData(), QLocale()));
            } else {
                text = textDecl->stringValue();
            }
        }

        const auto iconDecl = m_styleResult.declaration(MapCSSDeclaration::IconImage);

        if (!text.isEmpty() || iconDecl) {
            auto baseItem = sg.findOrCreatePayload<LabelItem>(e, level);
            auto item = static_cast<LabelItem*>(baseItem.get());
            item->text = text;
            item->hasFineBbox = false;
            item->bbox = {};
            item->font = m_defaultFont;
            item->color = m_defaultTextColor;

            if (item->pos.isNull()) {
                if (m_styleResult.hasAreaProperties()) {
                    item->pos = SceneGeometry::polygonCentroid(m_labelPlacementPath);
                } else if (m_styleResult.hasLineProperties()) {
                    item->pos = SceneGeometry::polylineMidPoint(m_labelPlacementPath);
                }
                if (item->pos.isNull()) {
                    item->pos = m_view->mapGeoToScene(e.center()); // node or something failed above
                }
            }

            double textOpacity = 1.0;
            double shieldOpacity = 1.0;
            IconData iconData;
            for (auto decl : m_styleResult.declarations()) {
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
                        if (decl->textFollowsLine() && m_labelPlacementPath.size() > 1) {
                            item->angle = SceneGeometry::polylineMidPointAngle(m_labelPlacementPath);
                        }
                        break;
                    case MapCSSDeclaration::TextOffset:
                        item->offset = decl->doubleValue();
                        break;
                    case MapCSSDeclaration::MaxWidth:
                        item->maxWidth = decl->intValue();
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
                    iconData.color = m_defaultTextColor;
                }
                item->icon = m_iconLoader.loadIcon(iconData);
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
            addItem(sg, e, level, std::move(baseItem));
        }
    }
}

QPolygonF SceneController::createPolygon(OSM::Element e) const
{
    const auto path = e.outerPath(m_data->dataSet());
    QPolygonF poly;
    poly.reserve(path.size());
    for (auto node : path) {
        poly.push_back(m_view->mapGeoToScene(node->coordinate));
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
        auto wayIt = std::lower_bound(m_data->dataSet().ways.begin(), m_data->dataSet().ways.end(), mem.id);
        if (wayIt == m_data->dataSet().ways.end() || (*wayIt).id != mem.id) {
            continue;
        }

        const auto subPoly = createPolygon(OSM::Element(&(*wayIt)));
        QPainterPath subPath;
        subPath.addPolygon(subPoly);
        path = path.subtracted(subPath);
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
            pen.setWidthF(penWidth(e, decl, unit));
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
            pen.setWidthF(penWidth(e, decl, unit));
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

double SceneController::penWidth(OSM::Element e, const MapCSSDeclaration *decl, Unit &unit) const
{
    // literal value, possibly with a unit
    if (decl->keyValue().isEmpty()) {
        if (decl->unit() != MapCSSDeclaration::NoUnit) {
            unit = decl->unit() == MapCSSDeclaration::Meters ? Unit::Meter : Unit::Pixel;
        }
        return decl->doubleValue();
    }

    // referenced value from a tag value
    // see https://wiki.openstreetmap.org/wiki/Map_Features/Units
    double unitConversionFactor = 1.0;
    const auto value = e.tagValue(decl->keyValue().constData()).constData();
    const auto valueLen = std::strlen(value);

    char* numEnd;
    const auto num = std::strtod(value, &numEnd);
    while (numEnd < value + valueLen) {
        if (std::isspace(*numEnd)) {
            ++numEnd;
        }

        // there is an explicit unit suffix;
        if (std::strcmp(numEnd, "ft") == 0) {
            unitConversionFactor = 0.3048;
        }

        break;
    }
    // no explicit unit, use default unit for this tag
    if (numEnd == value + valueLen) {
        if (std::strcmp(decl->keyValue().constData(), "gauge") == 0) {
            unitConversionFactor = 0.001;
        }
    }

    unit = Unit::Meter;
    return num * unitConversionFactor;
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
}

void SceneController::addItem(SceneGraph &sg, OSM::Element e, int level, std::unique_ptr<SceneGraphItemPayload> &&payload) const
{
    SceneGraphItem item;
    item.element = e;
    item.level = level;
    item.payload = std::move(payload);

    // get the OSM layer, if set
    if (!m_overlay) {
        const auto layerStr = e.tagValue(m_layerTag);
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
