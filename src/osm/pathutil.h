/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_PATHUTIL_H
#define OSM_PATHUTIL_H

#include "datatypes.h"

#include <vector>

namespace OSM {

class Element;

/** Appends the nodes referenced by @p nodesBegin and @pnodesEnd into @p nodes.
 *  This would typically be iterators on OSM::Way::nodes.
 */
template <typename Iter>
static void appendNodesFromWay(const DataSet &dataSet, std::vector<const Node*> &nodes, const Iter& nodeBegin, const Iter &nodeEnd)
{
    nodes.reserve(nodes.size() + std::distance(nodeBegin, nodeEnd));
    for (auto it = nodeBegin; it != nodeEnd; ++it) {
        if (auto node = dataSet.node((*it))) {
            nodes.push_back(node);
        }
    }
}

/** Assemble a continuous path into @p path from the given @p ways. */
void assemblePath(const DataSet &dataSet, std::vector<const Way*> &&ways, std::vector<const Node*> &path);
void assemblePath(const DataSet &dataSet, const std::vector<OSM::Element> &ways, std::vector<const Node*> &path);

}

#endif // OSM_PATHUTIL_H
