/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "pathutil.h"
#include "element.h"

#include <cassert>

using namespace OSM;

static OSM::Id appendNextPath(const DataSet &dataSet, std::vector<const Node*> &nodes, OSM::Id startNode, std::vector<const Way*> &ways)
{
    if (ways.empty()) {
        return {};
    }

    for (auto it = std::next(ways.begin()); it != ways.end(); ++it) {
        if ((*it)->nodes.empty()) {
            continue;
        }
        if ((*it)->nodes.front() == startNode) {
            appendNodesFromWay(dataSet, nodes, (*it)->nodes.begin(), (*it)->nodes.end());
            const auto lastNodeId = (*it)->nodes.back();
            ways.erase(it);
            return lastNodeId;
        }
        // path segments can also be backwards
        if ((*it)->nodes.back() == startNode) {
            appendNodesFromWay(dataSet, nodes, (*it)->nodes.rbegin(), (*it)->nodes.rend());
            const auto lastNodeId = (*it)->nodes.front();
            ways.erase(it);
            return lastNodeId;
        }
    }

    return {};
}

void OSM::assemblePath(const DataSet &dataSet, std::vector<const Way*> &&ways, std::vector<const Node*> &path)
{
    for (auto it = ways.begin(); it != ways.end();) {
        if ((*it)->nodes.empty()) {
            ++it;
            continue;
        }
        appendNodesFromWay(dataSet, path, (*it)->nodes.begin(), (*it)->nodes.end());
        const auto startNode = (*it)->nodes.front();
        auto lastNode = (*it)->nodes.back();

        do {
            lastNode = appendNextPath(dataSet, path, lastNode, ways);
        } while (lastNode && lastNode != startNode);

        it = ways.erase(it);
    }
}

void OSM::assemblePath(const OSM::DataSet &dataSet, const std::vector<OSM::Element> &ways, std::vector<const Node*> &path)
{
    std::vector<const OSM::Way*> w;
    w.reserve(ways.size());
    for (auto e : ways) {
        if (e.type() == OSM::Type::Way) {
            w.push_back(e.way());
        }
    }
    assemblePath(dataSet, std::move(w), path);
}
