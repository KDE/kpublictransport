/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_SCENECONTROLLER_H
#define KOSMINDOORMAP_SCENECONTROLLER_H

#include "kosmindoormap_export.h"

#include "scenegraphitem.h"

#include <memory>
#include <vector>

class QPolygonF;
class QString;

namespace OSM {
class Element;
}

namespace KOSMIndoorMap {

class MapData;
class MapCSSDeclaration;
class MapCSSStyle;
class OverlaySource;
class SceneControllerPrivate;
class SceneGraph;
class View;

/** Creates/updates the scene graph based on a given style sheet and view. */
class KOSMINDOORMAP_EXPORT SceneController
{
public:
    explicit SceneController();
    ~SceneController();

    void setDataSet(const MapData *data);
    void setStyleSheet(const MapCSSStyle *styleSheet);
    void setView(const View *view);
    void setOverlaySources(std::vector<OverlaySource> &&overlays);
    /** Overlay dirty state tracking. */
    void overlaySourceUpdated();

    /** Creates or updates @p sg based on the currently set style and view settings.
     *  When possible, provide the scene graph of the previous run to re-use scene graph elements that didn't change.
     */
    void updateScene(SceneGraph &sg) const;

private:
    void updateCanvas(SceneGraph &sg) const;
    void updateElement(OSM::Element e, int level, SceneGraph &sg) const;

    QPolygonF createPolygon(OSM::Element e) const;
    QPainterPath createPath(OSM::Element e, QPolygonF &outerPath) const;

    void applyGenericStyle(const MapCSSDeclaration *decl, SceneGraphItemPayload *item) const;
    void applyPenStyle(OSM::Element e, const MapCSSDeclaration *decl, QPen &pen, double &opacity, Unit &unit) const;
    void applyCasingPenStyle(OSM::Element e, const MapCSSDeclaration *decl, QPen &pen, double &opacity, Unit &unit) const;
    void applyFontStyle(const MapCSSDeclaration *decl, QFont &font) const;

    void initializePen(QPen &pen) const;
    void finalizePen(QPen &pen, double opacity) const;

    void addItem(SceneGraph &sg, OSM::Element e, int level, std::unique_ptr<SceneGraphItemPayload> &&payload) const;

    std::unique_ptr<SceneControllerPrivate> d;
};

}

#endif // KOSMINDOORMAP_SCENECONTROLLER_H
