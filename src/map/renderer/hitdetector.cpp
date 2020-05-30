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

#include "hitdetector.h"

#include "../scene/scenegraph.h"
#include "../scene/scenegraphitem.h"
#include "view.h"

using namespace KOSMIndoorMap;

const SceneGraphItem* HitDetector::itemAt(QPointF pos, const SceneGraph& sg, const View* view) const
{
    const auto scenePos = view->mapScreenToScene(pos);

    for (auto it = sg.items().rbegin(); it != sg.items().rend(); ++it) {
        if ((*it).payload->inSceneSpace() && (*it).payload->boundingRect().contains(scenePos)) {
            if (!itemContainsPoint((*it), scenePos, view)) {
                continue;
            }
            return &(*it);
        }
        // TODO HUD space elements
    }

    return nullptr;
}

std::vector<const SceneGraphItem*> HitDetector::itemsAt(QPointF pos, const SceneGraph &sg, const View *view) const
{
    std::vector<const SceneGraphItem*> result;
    const auto scenePos = view->mapScreenToScene(pos);

    for (const auto &item : sg.items()) {
        if (item.payload->inSceneSpace() && item.payload->boundingRect().contains(scenePos)) {
            if (!itemContainsPoint(item, scenePos, view)) {
                continue;
            }
            result.push_back(&item);
        }
        // TODO HUD space elements
    }

    return result;
}

bool HitDetector::itemContainsPoint(const SceneGraphItem &item, QPointF scenePos, const View *view) const
{
    if (const auto i = dynamic_cast<PolygonItem*>(item.payload.get())) {
        return itemContainsPoint(i, scenePos);
    }
    if (const auto i = dynamic_cast<MultiPolygonItem*>(item.payload.get())) {
        return itemContainsPoint(i, scenePos);
    }

    // TODO
    return true;
}

bool HitDetector::itemContainsPoint(const MultiPolygonItem *item, QPointF scenePos) const
{
    return item->path.contains(scenePos);
}

bool HitDetector::itemContainsPoint(const PolygonItem *item, QPointF scenePos) const
{
    return item->polygon.containsPoint(scenePos, Qt::OddEvenFill);
}
