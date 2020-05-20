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

#ifndef KOSMINDOORMAP_SCENECONTROLLER_H
#define KOSMINDOORMAP_SCENECONTROLLER_H

#include <vector>

#include "../style/mapcssresult.h"

class QPolygonF;
class QString;

namespace OSM {
class DataSet;
class Element;
class Node;
class Relation;
}

namespace KOSMIndoorMap {

class MapCSSStyle;
class SceneGraph;
class SceneGraphItem;
class View;

/** Creates/updates the scene graph based on a given style sheet and view. */
class SceneController
{
public:
    explicit SceneController();
    ~SceneController();

    void setDataSet(const OSM::DataSet *dataSet);
    void setStyleSheet(const MapCSSStyle *styleSheet);
    void setView(const View *view);

    /** Creates or updates @p sg based on the currently set style and view settings.
     *  When possible, provide the scene graph of the previous run to re-use scene graph elements that didn't change.
     */
    void updateScene(SceneGraph &sg) const;

private:
    QPolygonF createPolygon(OSM::Element e) const;
    QPainterPath createPath(OSM::Element e) const;

    void applyGenericStyle(const MapCSSDeclaration *decl, SceneGraphItem *item) const;
    void applyPenStyle(const MapCSSDeclaration *decl, QPen &pen) const;
    void applyCasingPenStyle(const MapCSSDeclaration *decl, QPen &pen) const;
    void applyFontStyle(const MapCSSDeclaration *decl, QFont &font) const;

    void addItem(SceneGraph &sg, OSM::Element e, SceneGraphItem *item) const;

    const OSM::DataSet *m_dataSet = nullptr;
    const MapCSSStyle *m_styleSheet = nullptr;
    const View *m_view = nullptr;
    mutable MapCSSResult m_styleResult;
};

}

#endif // KOSMINDOORMAP_SCENECONTROLLER_H
