/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_SCENEGRAPH_H
#define KOSMINDOORMAP_SCENEGRAPH_H

#include "kosmindoormap_export.h"

#include "scenegraphitem.h"

#include <osm/element.h>

#include <QColor>

#include <memory>
#include <vector>

class QPointF;

namespace KOSMIndoorMap {

class SceneGraphItem;

/** Scene graph of the currently displayed level. */
class KOSMINDOORMAP_EXPORT SceneGraph
{
public:
    explicit SceneGraph();
    SceneGraph(const SceneGraph&) = delete;
    SceneGraph(SceneGraph&&);
    ~SceneGraph();

    SceneGraph& operator=(const SceneGraph&) = delete;
    SceneGraph& operator=(SceneGraph &&other);

    /** Clears all data from the scene graph. */
    void clear();

    // scene builder interface
    void beginSwap();
    void addItem(SceneGraphItem &&item);
    template <typename T>
    std::unique_ptr<SceneGraphItemPayload> findOrCreatePayload(OSM::Element e, int level);
    void zSort();
    void endSwap();

    // dirty state tracking
    int zoomLevel() const;
    void setZoomLevel(int zoom);
    int currentFloorLevel() const;
    void setCurrentFloorLevel(int level);

    /** Canvas background color. */
    QColor backgroundColor() const;
    void setBackgroundColor(const QColor &bg);

    // renderer interface
    typedef std::pair<std::size_t, std::size_t> LayerOffset;
    const std::vector<LayerOffset>& layerOffsets() const;

    typedef std::vector<SceneGraphItem>::const_iterator SceneGraphItemIter;
    SceneGraphItemIter itemsBegin(LayerOffset layer) const;
    SceneGraphItemIter itemsEnd(LayerOffset layer) const;

    // hit detector interface
    const std::vector<SceneGraphItem>& items() const;

private:
    void recomputeLayerIndex();

    static bool itemPoolCompare(const SceneGraphItem &lhs, const SceneGraphItem &rhs);
    static bool zOrderCompare(const SceneGraphItem &lhs, const SceneGraphItem &rhs);

    std::vector<SceneGraphItem> m_items;
    std::vector<SceneGraphItem> m_previousItems;
    std::vector<std::pair<std::size_t, std::size_t>> m_layerOffsets;
    QColor m_bgColor;

    int m_zoomLevel = 0;
    int m_floorLevel = 0;
};


template<typename T>
std::unique_ptr<SceneGraphItemPayload> SceneGraph::findOrCreatePayload(OSM::Element e, int level)
{
    SceneGraphItem ref;
    ref.element = e;
    ref.level = level;
    auto it = std::lower_bound(m_previousItems.begin(), m_previousItems.end(), ref, SceneGraph::itemPoolCompare);
    for (;it != m_previousItems.end() && (*it).element.type() == e.type() && (*it).element.id() == e.id() && (*it).level == level && (*it).payload; ++it) {
        if (dynamic_cast<T*>((*it).payload.get())) {
            return std::move((*it).payload);
        }
    }
    return std::make_unique<T>();
}

}

#endif // KOSMINDOORMAP_SCENEGRAPH_H
