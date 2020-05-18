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

#ifndef KOSMINDOORMAP_SCENEGRAPH_H
#define KOSMINDOORMAP_SCENEGRAPH_H

#include <QColor>

#include <memory>
#include <vector>

namespace KOSMIndoorMap {

class SceneGraphItem;

/** Scene graph of the currently displayed level. */
class SceneGraph
{
public:
    explicit SceneGraph();
    SceneGraph(const SceneGraph&) = delete;
    SceneGraph(SceneGraph&&);
    ~SceneGraph();

    SceneGraph& operator=(const SceneGraph&) = delete;
    SceneGraph& operator=(SceneGraph &&other);

    void addItem(SceneGraphItem *item);
    void zSort();

    std::vector<std::unique_ptr<SceneGraphItem>> m_items;
    QColor m_bgColor;
};

}

#endif // KOSMINDOORMAP_SCENEGRAPH_H
