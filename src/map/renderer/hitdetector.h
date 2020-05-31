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
};

}

#endif // KOSMINDOORMAP_HITDETECTOR_H
