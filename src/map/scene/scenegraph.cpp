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

#include "scenegraph.h"

#include <QDebug>
#include <QGuiApplication>
#include <QPalette>

using namespace KOSMIndoorMap;

SceneGraph::SceneGraph() = default;
SceneGraph::SceneGraph(SceneGraph&&) = default;
SceneGraph::~SceneGraph() = default;
SceneGraph& SceneGraph::operator=(SceneGraph &&other) = default;

void SceneGraph::addItem(SceneGraphItem &&item)
{
    m_items.push_back(std::move(item));
}

void SceneGraph::zSort()
{
    std::stable_sort(m_items.begin(), m_items.end(), SceneGraph::zOrderCompare);
    recomputeLayerIndex();
}

bool SceneGraph::zOrderCompare(const SceneGraphItem &lhs, const SceneGraphItem &rhs)
{
    /* The MapCSS spec says we have to render in the following order:
     * - Objects with lower layer should always be rendered first.
     * - Within a layer, first all fills are rendered, then all casings, then all strokes, then all icons and labels.
     * - Within each of those categories, objects are ordered according to z-index.
     * - If all of the above are equal, the order is undefined.
     */
    if (lhs.level == rhs.level) {
        if (lhs.layer == rhs.layer) {
            return lhs.payload->z < rhs.payload->z;
        }
        return lhs.layer < rhs.layer;
    }
    return lhs.level < rhs.level;
}

void SceneGraph::beginSwap()
{
    std::swap(m_items, m_previousItems);
    m_items.clear();
    std::sort(m_previousItems.begin(), m_previousItems.end(), SceneGraph::itemPoolCompare);
    m_layerOffsets.clear();
}

void SceneGraph::endSwap()
{
    m_previousItems.clear();
}

QColor SceneGraph::backgroundColor() const
{
    return m_bgColor;
}

void SceneGraph::setBackgroundColor(const QColor &bg)
{
    m_bgColor = bg;
}

void SceneGraph::recomputeLayerIndex()
{
    m_layerOffsets.clear();
    if (m_items.empty()) {
        return;
    }

    auto prevLayer = m_items.front().layer;
    auto prevIndex = 0;
    for (auto it = m_items.begin(); it != m_items.end();) {
        it = std::upper_bound(it, m_items.end(), prevLayer, [](const auto &lhs, const auto &rhs) {
            return lhs < rhs.layer;
        });
        const auto nextIndex = std::distance(m_items.begin(), it);
        m_layerOffsets.push_back(std::make_pair(prevIndex, nextIndex));
        prevIndex = nextIndex;
        if (it != m_items.end()) {
            prevLayer = (*it).layer;
        }
    }
}

void SceneGraph::itemsAt(QPointF pos)
{
    // ### temporary for testing
    for (const auto &item : m_items) {
        if (item.payload->inSceneSpace() && item.payload->boundingRect().contains(pos)) {
            qDebug() << item.element.url();
            for (auto it = item.element.tagsBegin(); it != item.element.tagsEnd(); ++it) {
                qDebug() << "    " << (*it).key << (*it).value;
            }
        }
        // TODO HUD space elements
    }
}

const std::vector<SceneGraph::LayerOffset>& SceneGraph::layerOffsets() const
{
    return m_layerOffsets;
}

SceneGraph::SceneGraphItemIter SceneGraph::itemsBegin(SceneGraph::LayerOffset layer) const
{
    return m_items.begin() + layer.first;
}

SceneGraph::SceneGraphItemIter SceneGraph::itemsEnd(SceneGraph::LayerOffset layer) const
{
    return m_items.begin() + layer.second;
}

std::size_t SceneGraph::itemCount() const
{
    return m_items.size();
}

bool SceneGraph::itemPoolCompare(const SceneGraphItem &lhs, const SceneGraphItem &rhs)
{
    if (lhs.element.type() == rhs.element.type()) {
        if (lhs.element.id() == rhs.element.id()) {
            return lhs.level < rhs.level;
        }
        return lhs.element.id() < rhs.element.id();
    }
    return lhs.element.type() < rhs.element.type();
}
