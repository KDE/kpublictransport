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

#include "scenegeometry.h"
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
#include <QElapsedTimer>
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
    QElapsedTimer sgUpdateTimer;
    sgUpdateTimer.start();

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

    // for each level, update or create scene graph elements
    for (auto it = beginIt; it != endIt; ++it) {
        for (auto e : (*it).second) {
            updateElement(e, (*it).first.numericLevel(), sg);
        }
    }

    sg.zSort();

    qDebug() << "updated scenegraph took" << sgUpdateTimer.elapsed() << "ms";
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
            i->path = createPath(e, m_labelPlacementPath);
            item = i;
        } else {
            auto i = new PolygonItem;
            i->polygon = createPolygon(e);
            m_labelPlacementPath = i->polygon;
            item = i;
        }

        double lineOpacity = 1.0;
        double fillOpacity = 1.0;
        initializePen(item->pen);
        for (auto decl : m_styleResult.declarations()) {
            applyGenericStyle(decl, item);
            applyPenStyle(decl, item->pen, lineOpacity);
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

        addItem(sg, e, level, item);
    } else if (m_styleResult.hasLineProperties()) {
        auto item = new PolylineItem;
        item->path = createPolygon(e);

        double lineOpacity = 1.0;
        double casingOpacity = 1.0;
        initializePen(item->pen);
        initializePen(item->casingPen);
        for (auto decl : m_styleResult.declarations()) {
            applyGenericStyle(decl, item);
            applyPenStyle(decl, item->pen, lineOpacity);
            applyCasingPenStyle(decl, item->casingPen, casingOpacity);
        }
        finalizePen(item->pen, lineOpacity);
        finalizePen(item->casingPen, casingOpacity);

        m_labelPlacementPath = item->path;
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
            item->color = m_defaultTextColor;

            if (m_styleResult.hasAreaProperties()) {
                item->pos = SceneGeometry::polygonCentroid(m_labelPlacementPath);
            } else if (m_styleResult.hasLineProperties()) {
                // TODO compute placement at half distance along the path
            }
            if (item->pos.isNull()) {
                item->pos = m_view->mapGeoToScene(e.center()); // node or something failed above
            }

            double textOpacity = 1.0;
            double shieldOpacity = 1.0;
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
                            item->angle = SceneGeometry::angleForPath(m_labelPlacementPath);
                        }
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

// @see https://wiki.openstreetmap.org/wiki/Relation:multipolygon
QPainterPath SceneController::createPath(const OSM::Element e, QPolygonF &outerPath) const
{
    assert(e.type() == OSM::Type::Relation);
    outerPath = createPolygon(e);
    QPainterPath path;
    path.addPolygon(outerPath); // assemble the outer polygon, which can be represented as a set of unsorted lines here even

    for (const auto &mem : e.relation()->members) {
        const bool isInner = mem.role == QLatin1String("inner");
        if (mem.type != OSM::Type::Way || !isInner) {
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

void SceneController::applyGenericStyle(const MapCSSDeclaration *decl, SceneGraphItem *item) const
{
    if (decl->property() == MapCSSDeclaration::ZIndex) {
        item->z = decl->intValue();
    }
}

void SceneController::applyPenStyle(const MapCSSDeclaration *decl, QPen &pen, double &opacity) const
{
    switch (decl->property()) {
        case MapCSSDeclaration::Color:
            pen.setColor(decl->colorValue());
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
            opacity = decl->doubleValue();
            break;
        default:
            break;
    }
}

void SceneController::applyCasingPenStyle(const MapCSSDeclaration *decl, QPen &pen, double &opacity) const
{
    switch (decl->property()) {
        case MapCSSDeclaration::CasingColor:
            pen.setColor(decl->colorValue());
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
}

void SceneController::addItem(SceneGraph &sg, OSM::Element e, int level, SceneGraphItem *item) const
{
    item->element = e;
    item->level = level;

    // get the OSM layer, if set
    const auto layerStr = e.tagValue(QLatin1String("layer"));
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
                item->layer = layer;
            }
        } else {
            qWarning() << "Invalid layer:" << e.url() << layerStr;
        }
    }

    sg.addItem(item);
}
