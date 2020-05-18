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

void SceneController::setDataSet(const OSM::DataSet *dataSet)
{
    m_dataSet = dataSet;
}

void SceneController::setStyleSheet(const MapCSSStyle *styleSheet)
{
    m_styleSheet = styleSheet;
}

void SceneController::setView(const View *view)
{
    m_view = view;
}

static bool containsLevel(const QString &currentLevel, const QString &desiredLevel)
{
    if (desiredLevel.isEmpty() || (currentLevel.isEmpty() && desiredLevel == QLatin1String("0"))) {
        return true;
    }

    if (currentLevel.contains(QLatin1Char(';')) && currentLevel.split(QLatin1Char(';')).contains(desiredLevel)) {
        return true;
    }

    return currentLevel == desiredLevel;
}

void SceneController::updateScene(SceneGraph &sg) const
{
    sg.m_bgColor = QGuiApplication::palette().color(QPalette::Base);

    sg.m_items.clear(); // TODO reuse what is still valid

    auto defaultTextColor = QGuiApplication::palette().color(QPalette::Text);
    m_styleSheet->evaluateCanvas(m_styleResult);
    for (auto decl : m_styleResult.declarations()) {
        switch (decl->property()) {
            case MapCSSDeclaration::FillColor:
                sg.m_bgColor = decl->colorValue();
                break;
            case MapCSSDeclaration::TextColor:
                defaultTextColor = decl->colorValue();
                break;
            default:
                break;
        }
    }

    OSM::for_each(*m_dataSet, [this, &sg, defaultTextColor](auto e) {
        const auto l = e.tagValue("level");
        if (!containsLevel(l, m_view->level())) {
            return;
        }

        MapCSSState state;
        state.element = e;
        state.zoomLevel = m_view->zoomLevel();
        m_styleSheet->evaluate(state, m_styleResult);

        if (m_styleResult.hasAreaProperties()) {
            auto item = new PolygonItem;
            item->polygon = createPolygon(e);
            for (auto decl : m_styleResult.declarations()) {
                applyGenericStyle(decl, item);
                applyPenStyle(decl, item->pen);
                switch (decl->property()) {
                    case MapCSSDeclaration::FillColor:
                        item->brush.setColor(decl->colorValue());
                        item->brush.setStyle(Qt::SolidPattern);
                        break;
                    default:
                        break;
                }
            }
            addItem(sg, e, item);
        } else if (m_styleResult.hasLineProperties()) {
            auto item = new PolylineItem;
            item->path = createPolygon(e);
            // default according to spec
            item->pen.setCapStyle(Qt::FlatCap);
            item->pen.setJoinStyle(Qt::RoundJoin);

            for (auto decl : m_styleResult.declarations()) {
                applyGenericStyle(decl, item);
                applyPenStyle(decl, item->pen);
            }

            addItem(sg, e, item);
        }

        if (m_styleResult.hasLabelProperties()) {
            QString text;
            const auto textDecl = m_styleResult.declaration(MapCSSDeclaration::Text);
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
                item->pos = m_view->mapGeoToScene(e.center()); // TODO center() is too simple for concave polygons
                item->color = defaultTextColor;

                for (auto decl : m_styleResult.declarations()) {
                    applyGenericStyle(decl, item);
                    switch (decl->property()) {
                        case MapCSSDeclaration::TextColor:
                            item->color = decl->colorValue();
                            break;
                        default:
                            break;
                    }
                }
                addItem(sg, e, item);
            }
        }
    });

    sg.zSort();
}

QPolygonF SceneController::createPolygon(OSM::Element e) const
{
    if (e.type() == OSM::Type::Relation && e.tagValue("type") == QLatin1String("multipolygon")) {
        return createMultiPolygon(e.relation());
    }
    return createPolygon(e.outerPath(*m_dataSet));
}

QPolygonF SceneController::createMultiPolygon(const OSM::Relation* rel) const
{
    QPolygonF poly;

    for (const auto &mem : rel->members) {
        if (mem.type != OSM::Type::Way || (mem.role != QLatin1String("outer") && mem.role != QLatin1String("inner"))) {
            continue;
        }
        auto wayIt = std::lower_bound(m_dataSet->ways.begin(), m_dataSet->ways.end(), mem.id);
        if (wayIt == m_dataSet->ways.end() || (*wayIt).id != mem.id) {
            continue;
        }

        const auto subPoly = createPolygon(OSM::Element(&(*wayIt)));
        if (mem.role == QLatin1String("inner")) {
            poly = poly.subtracted(subPoly);
        } else {
            poly = poly.united(subPoly);
        }
    }

    return poly;
}

QPolygonF SceneController::createPolygon(const std::vector<const OSM::Node*> &path) const
{
    QPolygonF poly;
    poly.reserve(path.size());
    for (auto node : path) {
        poly.push_back(m_view->mapGeoToScene(node->coordinate));
    }
    return poly;
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
        default:
            break;
    }
}

void SceneController::addItem(SceneGraph &sg, OSM::Element e, SceneGraphItem *item) const
{
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
