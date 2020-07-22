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
#include "../scene/scenegeometry.h"
#include "view.h"

#include <QBrush>

using namespace KOSMIndoorMap;

const SceneGraphItem* HitDetector::itemAt(QPointF pos, const SceneGraph& sg, const View* view) const
{
    auto items = itemsAt(pos, sg, view);
    if (items.empty()) {
        return nullptr;
    }
    if (items.size() == 1) {
        return items[0];
    }

    // multiple candidates
    // (1) top element is non-transparent, use that:
    const auto top = items.back();
    qDebug() << top->element.url() << itemFillAlpha(top);
    if (itemFillAlpha(top) >= 0.5f) {
        return top;
    }

    // (2) in presence of transparency, use the smallest item at this position
    std::sort(items.begin(), items.end(), [](auto lhs, auto rhs) {
        const auto lhsBbox = lhs->payload->boundingRect();
        const auto rhsBbox = rhs->payload->boundingRect();
        return (lhsBbox.width() * lhsBbox.height()) < (rhsBbox.width() * rhsBbox.height());
    });
    return items.front();
}

std::vector<const SceneGraphItem*> HitDetector::itemsAt(QPointF pos, const SceneGraph &sg, const View *view) const
{
    std::vector<const SceneGraphItem*> result;
    for (const auto &item : sg.items()) {
        if (item.payload->renderPhases() == SceneGraphItemPayload::NoPhase || !item.payload->boundingRect().contains(view->mapScreenToScene(pos))) {
            continue;
        }
        if (!itemContainsPoint(item, pos, view)) {
            continue;
        }
        result.push_back(&item);
    }

    return result;
}

bool HitDetector::itemContainsPoint(const SceneGraphItem &item, QPointF screenPos, const View *view) const
{
    if (const auto i = dynamic_cast<PolygonItem*>(item.payload.get())) {
        return itemContainsPoint(i, view->mapScreenToScene(screenPos));
    }
    if (const auto i = dynamic_cast<MultiPolygonItem*>(item.payload.get())) {
        return itemContainsPoint(i, view->mapScreenToScene(screenPos));
    }
    if (const auto i = dynamic_cast<PolylineItem*>(item.payload.get())) {
        return itemContainsPoint(i, view->mapScreenToScene(screenPos), view);
    }
    if (const auto i = dynamic_cast<LabelItem*>(item.payload.get())) {
        return itemContainsPoint(i, screenPos, view);
    }

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

bool HitDetector::itemContainsPoint(const PolylineItem *item, QPointF scenePos, const View *view) const
{
    if (item->path.size() < 2) {
        return false;
    }

    const auto lineWidth = view->mapMetersToScene(item->pen.widthF())
        + view->mapScreenDistanceToSceneDistance(item->casingPen.widthF());

    double dist = std::numeric_limits<double>::max();
    // TODO do we need to wrap around here for closed lines?
    for (auto it = std::next(item->path.begin()); it != item->path.end(); ++it) {
        QLineF line(*std::prev(it), *it);
        dist = std::min(dist, SceneGeometry::distanceToLine(line, scenePos));
    }

    return dist <= lineWidth;
}

bool HitDetector::itemContainsPoint(const LabelItem *item, QPointF screenPos, const View *view) const
{
    auto hitBox = item->bbox;
    hitBox.moveCenter(view->mapSceneToScreen(hitBox.center()));
    return hitBox.contains(screenPos);
}

float HitDetector::itemFillAlpha(const SceneGraphItem *item) const
{
    if (const auto i = dynamic_cast<PolygonItem*>(item->payload.get())) {
        return i->brush.color().alphaF();
    }
    if (const auto i = dynamic_cast<MultiPolygonItem*>(item->payload.get())) {
        return i->brush.color().alphaF();
    }
    return 1.0f;
}
