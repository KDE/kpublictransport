/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_HITDETECTOR_H
#define KOSMINDOORMAP_HITDETECTOR_H

#include <vector>

class QPointF;

namespace KOSMIndoorMap {

class LabelItem;
class MultiPolygonItem;
class PolygonItem;
class PolylineItem;
class SceneGraph;
class SceneGraphItem;
class View;

/** Picking hit detector.
 *  Ie. find scene graph items at a given screen position.
 */
class HitDetector
{
public:
    /** Highest (in z-order) item at the given screen position. */
    const SceneGraphItem* itemAt(QPointF pos, const SceneGraph &sg, const View *view) const;

    /** All items (in z-order) at the given screen position. */
    std::vector<const SceneGraphItem*> itemsAt(QPointF pos, const SceneGraph &sg, const View *view) const;

private:
    /** Precise bounds check for @p item. */
    bool itemContainsPoint(const SceneGraphItem &item, QPointF screenPos, const View *view) const;
    bool itemContainsPoint(const MultiPolygonItem *item, QPointF scenePos) const;
    bool itemContainsPoint(const PolygonItem *item, QPointF scenePos) const;
    bool itemContainsPoint(const PolylineItem *item, QPointF scenePos, const View *view) const;
    bool itemContainsPoint(const LabelItem *item, QPointF screenPos, const View *view) const;

    float itemFillAlpha(const SceneGraphItem *item) const;
};

}

#endif // KOSMINDOORMAP_HITDETECTOR_H
