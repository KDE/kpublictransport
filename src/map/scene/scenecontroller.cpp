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

#include "scenegraph.h"
#include "scenegraphitem.h"

#include "../loader/mapdata.h"
#include "../renderer/view.h"
#include "../style/mapcssdeclaration.h"
#include "../style/mapcssstyle.h"
#include "../style/mapcssstate.h"

#include <osm/element.h>
#include <osm/datatypes.h>

#include <QDebug>
#include <QGuiApplication>
#include <QPalette>

using namespace KOSMIndoorMap;

SceneController::SceneController() = default;
SceneController::~SceneController() = default;

void SceneController::setDataSet(const MapData *data)
{
    m_data = data;
}

void SceneController::setStyleSheet(const MapCSSStyle *styleSheet)
{
    m_styleSheet = styleSheet;
}

void SceneController::setView(const View *view)
{
    m_view = view;
}

void SceneController::updateScene(SceneGraph &sg) const
{
    sg.clear(); // TODO reuse what is still valid
    updateCanvas(sg);

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

    for (auto it = beginIt; it != endIt; ++it) {
        for (auto e : (*it).second) {
            updateElement(e, (*it).first.numericLevel(), sg);
        }
    }

    sg.zSort();
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
        PolygonBaseItem *item;
        if (e.type() == OSM::Type::Relation && e.tagValue("type") == QLatin1String("multipolygon")) {
            auto i = new MultiPolygonItm;
            i->path = createPath(e);
            item = i;
        } else {
            auto i = new PolygonItem;
            i->polygon = createPolygon(e);
            item = i;
        }

        double fillOpacity = 1.0;
        for (auto decl : m_styleResult.declarations()) {
            applyGenericStyle(decl, item);
            applyPenStyle(decl, item->pen);
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
        if (item->brush.style() == Qt::SolidPattern && fillOpacity < 1.0) {
            auto c = item->brush.color();
            c.setAlphaF(c.alphaF() * fillOpacity);
            item->brush.setColor(c);
        }

        addItem(sg, e, level, item);
    } else if (m_styleResult.hasLineProperties()) {
        auto item = new PolylineItem;
        item->path = createPolygon(e);
        // default according to spec
        item->pen.setCapStyle(Qt::FlatCap);
        item->pen.setJoinStyle(Qt::RoundJoin);
        item->casingPen.setCapStyle(Qt::FlatCap);
        item->casingPen.setJoinStyle(Qt::RoundJoin);

        for (auto decl : m_styleResult.declarations()) {
            applyGenericStyle(decl, item);
            applyPenStyle(decl, item->pen);
            applyCasingPenStyle(decl, item->casingPen);
        }

        addItem(sg, e, level, item);
    }

    if (m_styleResult.hasLabelProperties()) {
        QString text;
        auto textDecl = m_styleResult.declaration(MapCSSDeclaration::Text);
        if (!textDecl) {
            textDecl = m_styleResult.declaration(MapCSSDeclaration::ShieldText);
        }

        if (textDecl) {
            if (!textDecl->keyValue().isEmpty()) {
                text = e.tagValue(textDecl->keyValue().constData());
            } else {
                text = textDecl->stringValue();
            }
        }

        if (!text.isEmpty()) {
            auto item = new LabelItem;
            item->text = text;
            item->font = m_defaultFont;
            item->pos = m_view->mapGeoToScene(e.center()); // TODO center() is too simple for concave polygons
            item->color = m_defaultTextColor;

            for (auto decl : m_styleResult.declarations()) {
                applyGenericStyle(decl, item);
                applyFontStyle(decl, item->font);
                switch (decl->property()) {
                    case MapCSSDeclaration::TextColor:
                        item->color = decl->colorValue();
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
                    case MapCSSDeclaration::ShieldFrameColor:
                        item->frameColor = decl->colorValue();
                        break;
                    case MapCSSDeclaration::ShieldFrameWidth:
                        item->frameWidth = decl->doubleValue();
                        break;
                    default:
                        break;
                }
            }
            addItem(sg, e, level, item);
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

QPainterPath SceneController::createPath(const OSM::Element e) const
{
    assert(e.type() == OSM::Type::Relation);
    QPainterPath path;

    // some multi-polygons in OSM have inner elements preceeding outer elements
    // we remember those in here until we saw the first outer element.
    // we cannot just sort this, as complex nested constructs are possible as well
    // @see https://wiki.openstreetmap.org/wiki/Relation:multipolygon
    QPainterPath subtractBuffer;

    for (const auto &mem : e.relation()->members) {
        const bool isOuter = mem.role == QLatin1String("outer");
        const bool isInner = mem.role == QLatin1String("inner");
        if (mem.type != OSM::Type::Way || (!isOuter && !isInner)) {
            continue;
        }
        auto wayIt = std::lower_bound(m_data->dataSet().ways.begin(), m_data->dataSet().ways.end(), mem.id);
        if (wayIt == m_data->dataSet().ways.end() || (*wayIt).id != mem.id) {
            continue;
        }

        const auto subPoly = createPolygon(OSM::Element(&(*wayIt)));
        if (isInner) {
            if (!path.isEmpty()) {
                QPainterPath subPath;
                subPath.addPolygon(subPoly);
                path = path.subtracted(subPath);
            } else {
                subtractBuffer.addPolygon(subPoly);
            }
        } else {
            path.addPolygon(subPoly);
            if (!subtractBuffer.isEmpty()) {
                path = path.subtracted(subtractBuffer);
                subtractBuffer.clear();
            }
        }
    }

    return path;
}

void SceneController::applyGenericStyle(const MapCSSDeclaration *decl, SceneGraphItem *item) const
{
    if (decl->property() == MapCSSDeclaration::ZIndex) {
        item->z = decl->intValue();
    }
}

void SceneController::applyPenStyle(const MapCSSDeclaration *decl, QPen &pen) const
{
    switch (decl->property()) {
        case MapCSSDeclaration::Color:
            pen.setColor(decl->colorValue());
            if (pen.style() == Qt::NoPen) {
                pen.setStyle(Qt::SolidLine);
            }
            break;
        case MapCSSDeclaration::Width:
            pen.setWidthF(decl->doubleValue());
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
            // TODO
        default:
            break;
    }
}

void SceneController::applyCasingPenStyle(const MapCSSDeclaration *decl, QPen &pen) const
{
    switch (decl->property()) {
        case MapCSSDeclaration::CasingColor:
            pen.setColor(decl->colorValue());
            if (pen.style() == Qt::NoPen) {
                pen.setStyle(Qt::SolidLine);
            }
            break;
        case MapCSSDeclaration::CasingWidth:
            pen.setWidthF(decl->doubleValue());
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
            // TODO
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
            font.setPointSizeF(decl->doubleValue()); // TODO unit support
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

void SceneController::addItem(SceneGraph &sg, OSM::Element e, int level, SceneGraphItem *item) const
{
    item->level = level;

    // get the OSM layer, if set
    const auto layerStr = e.tagValue(QLatin1String("layer"));
    if (!layerStr.isEmpty()) {
        bool success = false;
        const auto layer = layerStr.toInt(&success);
        if (success) {
            item->layer = layer;
        } else {
            qWarning() << "Invalid layer:" << e.url() << layerStr;
        }
    }

    sg.addItem(item);
}
