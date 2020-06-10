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

#include "marblegeometryassembler.h"

using namespace KOSMIndoorMap;

enum { NodeMatchDistance = 11 }; // in 1e7th of a degree

/** Compare two coordinate while accounting for floating point noise. */
static bool fuzzyEquals(OSM::Coordinate lhs, OSM::Coordinate rhs)
{
    return std::abs((int32_t)lhs.latitude - (int32_t)rhs.latitude) <= NodeMatchDistance && std::abs((int32_t)lhs.longitude - (int32_t)rhs.longitude) <= NodeMatchDistance;
}

void MarbleGeometryAssembler::merge(OSM::DataSet *dataSet, OSM::DataSetMergeBuffer *mergeBuffer)
{
    m_dataSet = dataSet;
    m_wayIdMap.clear();
    m_relIdMap.clear();
    m_pendingWays.clear();
    m_mxoidKey = dataSet->tagKey("mx:oid");

    mergeNodes(mergeBuffer);
    mergeWays(mergeBuffer);
    mergeRelations(mergeBuffer);

    mergeBuffer->clear();
    std::swap(m_pendingWays, mergeBuffer->ways); // ways we have to try again
    m_dataSet = nullptr;
}

void MarbleGeometryAssembler::finalize(OSM::DataSet *dataSet, OSM::DataSetMergeBuffer *mergeBuffer)
{
    for (auto &way : mergeBuffer->ways) {
        dataSet->addWay(std::move(way));
    }
}

void MarbleGeometryAssembler::mergeNodes(OSM::DataSetMergeBuffer *mergeBuffer)
{
    // nodes we just take as-is, they are not split/renamed; at worst we get a few extra for split geometry
    if (m_dataSet->nodes.empty()) {
        m_dataSet->nodes = std::move(mergeBuffer->nodes);
        std::sort(m_dataSet->nodes.begin(), m_dataSet->nodes.end());
    } else {
        m_dataSet->nodes.reserve(m_dataSet->nodes.size() + mergeBuffer->nodes.size());
        std::move(mergeBuffer->nodes.begin(), mergeBuffer->nodes.end(), std::back_inserter(m_dataSet->nodes));
    }
    std::sort(m_dataSet->nodes.begin(), m_dataSet->nodes.end());
}

void MarbleGeometryAssembler::mergeWays(OSM::DataSetMergeBuffer *mergeBuffer)
{
    // for ways we do:
    // 1. restore the original id
    // 2. if a way with that id already exists, we merge with the geometry of the existing one

    for (auto &way : mergeBuffer->ways) {
        if (way.id > 0) { // not a synthetic id
            m_dataSet->addWay(std::move(way));
            continue;
        }

        const OSM::Id mxoid = takeMxOid(way);
        if (mxoid <= 0) { // shouldn't happen?
            m_dataSet->addWay(std::move(way));
            continue;
        }

        const auto syntheticId = way.id;
        way.id = mxoid;

        const auto it = std::lower_bound(m_dataSet->ways.begin(), m_dataSet->ways.end(), way);
        if (it != m_dataSet->ways.end() && (*it).id == way.id) {
            mergeWay(*it, way);

            if (way.nodes.empty()) {
                // way was fully merged
                m_wayIdMap[syntheticId] = mxoid;
            } else {
                // defer to later (ie. more tiles loaded)
                way.id = syntheticId;
                OSM::setTagValue(way, m_mxoidKey, QString::number(mxoid));
                m_pendingWays.push_back(std::move(way));
            }

        } else {
            m_wayIdMap[syntheticId] = mxoid;
            m_dataSet->ways.insert(it, std::move(way));
        }
    }
}

void MarbleGeometryAssembler::mergeWay(OSM::Way &way, OSM::Way &otherWay) const
{
    // for merging two ways:
    // - non-synthetic nodes remain unchanged, ways can only be merged on synthetic nodes
    // - synthetic nodes are duplicated in both sets, we need to merge them by coordinate comparison
    // - synthetic nodes can be removed, and so can edges between two adjacent synthetic nodes
    // - closed polygons at least have one shared edge (possibly multiple adjacent or non-adjacent ones)
    // - lines can only be merged at the beginning or the end, a line crossing the same boundary multiple times would be split at every boundary intersection
    // - we can assume polygon orientation is preserved by the splitting

    if (!way.isClosed() && !otherWay.isClosed()) {
        mergeLine(way, otherWay);
    } else {
        way.nodes = mergeArea(way, otherWay);
    }
}

void MarbleGeometryAssembler::mergeLine(OSM::Way &way, OSM::Way &otherWay) const
{
    const auto begin1 = nodeForId(way.nodes.front());
    const auto end1 = nodeForId(way.nodes.back());
    const auto begin2 = nodeForId(otherWay.nodes.front());
    const auto end2 = nodeForId(otherWay.nodes.back());
    if (!begin1 || !end1 || !begin2 || !end2) {
        qDebug() << "failed to find way nodes!?" << begin1 << end1 << begin2 << end2;;
        return;
    }

    // TODO drop the extra synthetic nodes
    way.nodes.reserve(way.nodes.size() + otherWay.nodes.size());
    if (fuzzyEquals(end1->coordinate, begin2->coordinate)) {
        std::copy(otherWay.nodes.begin(), otherWay.nodes.end(), std::back_inserter(way.nodes));
    } else if (fuzzyEquals(end1->coordinate, end2->coordinate)) {
        std::copy(otherWay.nodes.rbegin(), otherWay.nodes.rend(), std::back_inserter(way.nodes));
    } else if (fuzzyEquals(begin1->coordinate, end2->coordinate)) {
        way.nodes.insert(way.nodes.begin(), otherWay.nodes.begin(), otherWay.nodes.end());
    } else if (fuzzyEquals(begin1->coordinate, begin2->coordinate)) {
        way.nodes.insert(way.nodes.begin(), otherWay.nodes.rbegin(), otherWay.nodes.rend());
    } else {
        qDebug() << "unable to merge line:" << begin1->coordinate << end1->coordinate << begin2->coordinate << end2->coordinate;
        return;
    }

    otherWay.nodes.clear(); // for the caller to notice we succeeded here
}

std::vector<OSM::Id> MarbleGeometryAssembler::mergeArea(OSM::Way &way, OSM::Way &otherWay) const
{
    // sanity checks for assumptions below
    if (way.nodes.size() < 3 || otherWay.nodes.size() < 3 || !way.isClosed() || !otherWay.isClosed()) {
        qWarning() << "got invalid polygons!";
        return way.nodes;
    }

    // "open" the closed polygons (otherwise we have to special-case the closing edges in both ways below)
    way.nodes.pop_back();
    otherWay.nodes.pop_back();

    std::vector<OSM::Id> nodes;
    mergeAreaSection(nodes, way.nodes, way.nodes.begin(), otherWay.nodes);

    // re-close the polygon
    if (!nodes.empty()) {
        nodes.push_back(nodes.front());
    }

    // if otherWay is still populated we failed to find a connecting node
    // this can happen in a number of cases, such as the same area entering a tile
    // twice but its connecting part still being in an not yet loaded tile
    // we defer processing those to later, so just re-close the polygon here
    if (!otherWay.nodes.empty()) {
        otherWay.nodes.push_back(otherWay.nodes.front());
    }
    return nodes;
}

bool MarbleGeometryAssembler::mergeAreaSection(std::vector<OSM::Id> &assembledPath, std::vector<OSM::Id> &path, const std::vector<OSM::Id>::iterator &pathBegin, std::vector<OSM::Id> &otherPath) const
{
    for (auto nodeIt = pathBegin; nodeIt != path.end(); ++nodeIt) {
        if ((*nodeIt) >= 0) { // not synthetic
            continue;
        }
        const auto node = nodeForId(*nodeIt);
        if (!node) { // should not happen?
            qDebug() << "could not find node" << (*nodeIt);
            continue;
        }

        // TODO orientation change?
        // synthetic node, find a matching one in the other way and splice in that way
        for (auto otherNodeIt = otherPath.begin(); otherNodeIt != otherPath.end(); ++otherNodeIt) {
            if ((*otherNodeIt) >= 0) {
                continue;
            }

            const auto otherNode = nodeForId(*otherNodeIt);
            if (!otherNode) {
                qDebug() << "could not find node" << (*otherNodeIt);
                continue;
            }

            if (!fuzzyEquals(node->coordinate, otherNode->coordinate)) {
                continue;
            }

            // found a matching synthetic node, continue in the other path
            std::copy(pathBegin, nodeIt, std::back_inserter(assembledPath));
            nodeIt = path.erase(pathBegin, ++nodeIt);
            if (nodeIt == path.end()) {
                nodeIt = path.begin();
            }
            otherNodeIt = otherPath.erase(otherNodeIt);
            if (otherNodeIt == otherPath.end()) {
                otherNodeIt = otherPath.begin();
            }
            // if otherPath was completely consumed, it would have switched back to us with its closing edge
            // so add the remaining part of path here
            if (mergeAreaSection(assembledPath, otherPath, otherNodeIt, path)) {
                qDebug() << "      processing trailing path";
                std::copy(nodeIt, path.end(), std::back_inserter(assembledPath));
                std::copy(path.begin(), nodeIt, std::back_inserter(assembledPath));
                path.clear();
            }
            return false;
        }

    }

    // copy the final segment
    std::copy(pathBegin, path.end(), std::back_inserter(assembledPath));
    path.erase(pathBegin, path.end());

    // wrap around when starting in the middle (can happen on the secondary path)
    if (!path.empty()) {
        return mergeAreaSection(assembledPath, path, path.begin(), otherPath);
    }

    return path.empty();
}

void MarbleGeometryAssembler::mergeRelations(OSM::DataSetMergeBuffer *mergeBuffer)
{
    // for relations we do:
    // 1. restore the original id
    // 2. replace all member ids with the restored ids for ways/relations
    // 3. if a relations with the restored id already exists, merge with its content

    for (auto &rel : mergeBuffer->relations) {
        const OSM::Id mxoid = takeMxOid(rel);
        if (mxoid <= 0) { // shouldn't happen?
            m_dataSet->addRelation(std::move(rel));
            continue;
        }

        m_relIdMap[rel.id] = mxoid;
        rel.id = mxoid;

        for (auto &member : rel.members) {
            if (member.id >= 0) { // not a synthetic id
                continue;
            }

            if (member.type == OSM::Type::Way) {
                const auto it = m_wayIdMap.find(member.id);
                if (it != m_wayIdMap.end()) {
                    member.id = (*it).second;
                }
            } else if (member.type == OSM::Type::Relation) {
                const auto it = m_relIdMap.find(member.id);
                if (it != m_relIdMap.end()) {
                    member.id = (*it).second;
                }
            }
        }

        const auto it = std::lower_bound(m_dataSet->relations.begin(), m_dataSet->relations.end(), rel);
        if (it != m_dataSet->relations.end() && (*it).id == rel.id) {
            mergeRelation(*it, rel);
        } else {
            m_dataSet->relations.insert(it, std::move(rel));
        }
    }
}

void MarbleGeometryAssembler::mergeRelation(OSM::Relation& relation, const OSM::Relation& otherRelation) const
{
    for (auto &otherMember : otherRelation.members) {
        const auto it = std::find(relation.members.begin(), relation.members.end(), otherMember);
        if (it == relation.members.end()) {
            relation.members.push_back(otherMember);
        }
    }
}

template<typename Elem>
OSM::Id MarbleGeometryAssembler::takeMxOid(Elem &elem) const
{
    const auto it = std::lower_bound(elem.tags.begin(), elem.tags.end(), m_mxoidKey, [](const auto &lhs, const auto &rhs) { return lhs.key < rhs; });
    if (it != elem.tags.end() && (*it).key == m_mxoidKey) {
        bool result = false;
        const OSM::Id id = (*it).value.toLongLong(&result);
        if (result) {
            elem.tags.erase(it);
            return id;
        }
    }
    return {};
}

const OSM::Node* MarbleGeometryAssembler::nodeForId(OSM::Id id) const
{
    const auto it = std::lower_bound(m_dataSet->nodes.begin(), m_dataSet->nodes.end(), id);
    if (it != m_dataSet->nodes.end() && (*it).id == id) {
        return &(*it);
    }
    return nullptr;
}
