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
#include "scenegraphitem.h"

#include <qalgorithms.h>
#include <QGuiApplication>
#include <QPalette>

using namespace KOSMIndoorMap;

SceneGraph::SceneGraph() = default;
SceneGraph::SceneGraph(SceneGraph&&) = default;
SceneGraph::~SceneGraph() = default;
SceneGraph& SceneGraph::operator=(SceneGraph &&other) = default;

void SceneGraph::addItem(SceneGraphItem *item)
{
    m_items.push_back(std::unique_ptr<SceneGraphItem>(item));
}

void SceneGraph::zSort()
{
    std::stable_sort(m_items.begin(), m_items.end(), [](const auto &lhs, const auto &rhs) { return lhs->z < rhs->z; });
}
