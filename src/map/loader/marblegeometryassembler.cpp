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

/** Compare two coordinate while accounting for floating point noise. */
static bool fuzzyEquals(OSM::Coordinate lhs, OSM::Coordinate rhs)
{
    return std::abs((int32_t)lhs.latitude - (int32_t)rhs.latitude) < 10 && std::abs((int32_t)lhs.longitude - (int32_t)rhs.longitude) < 10;
}

void MarbleGeometryAssembler::merge(OSM::DataSet *dataSet, OSM::DataSetMergeBuffer *mergeBuffer)
{
    m_wayIdMap.clear();
    m_mxoidKey = dataSet->tagKey("mx:oid");

    mergeNodes(dataSet, mergeBuffer);
    mergeWays(dataSet, mergeBuffer);
    mergeRelations(dataSet, mergeBuffer);

    mergeBuffer->clear();
}

void MarbleGeometryAssembler::mergeNodes(OSM::DataSet *dataSet, OSM::DataSetMergeBuffer *mergeBuffer)
{
    // nodes we just take as-is, they are not split/renamed; at worst we get a few extra for split geometry
    if (dataSet->nodes.empty()) {
        dataSet->nodes = std::move(mergeBuffer->nodes);
        std::sort(dataSet->nodes.begin(), dataSet->nodes.end());
    } else {
        dataSet->nodes.reserve(dataSet->nodes.size() + mergeBuffer->nodes.size());
        std::move(mergeBuffer->nodes.begin(), mergeBuffer->nodes.end(), std::back_inserter(dataSet->nodes));
    }
    std::sort(dataSet->nodes.begin(), dataSet->nodes.end());
}

void MarbleGeometryAssembler::mergeWays(OSM::DataSet *dataSet, OSM::DataSetMergeBuffer *mergeBuffer)
{
    // for ways we do:
    // 1. restore the original id
    // 2. if a way with that id already exists, we merge with the geometry of the existing one

    for (auto &way : mergeBuffer->ways) {
        if (way.id > 0) { // not a synthetic id
            dataSet->addWay(std::move(way));
            continue;
        }

        const OSM::Id mxoid = takeMxOid(way);
        if (mxoid <= 0) { // shouldn't happen?
            dataSet->addWay(std::move(way));
            continue;
        }

        m_wayIdMap[way.id] = mxoid;
        way.id = mxoid;

        const auto it = std::lower_bound(dataSet->ways.begin(), dataSet->ways.end(), way);
        if (it != dataSet->ways.end() && (*it).id == way.id) {
            mergeWay(dataSet, *it, way);
        } else {
            dataSet->ways.insert(it, std::move(way));
        }
    }
}

void MarbleGeometryAssembler::mergeWay(const OSM::DataSet *dataSet, OSM::Way &way, const OSM::Way &otherWay) const
{
    // for merging two ways:
    // - non-synthetic nodes remain unchanged, ways can only be merged on synthetic nodes
    // - synthetic nodes are duplicated in both sets, we need to merge them by coordinate comparison
    // - synthetic nodes can be removed, and so can edges between two adjacent synthetic nodes
    // - closed polygons at least have one shared edge (possibly multiple adjacent or non-adjacent ones)
    // - lines can only be merged at the beginning or the end, a line crossing the same boundary multiple times would be split at every boundary intersection
    // - we can assume polygon orientation is preserved by the splitting

    if (!way.isClosed() && !otherWay.isClosed()) {
        mergeLine(dataSet, way, otherWay);
    } else {
        mergeArea(dataSet, way, otherWay);
    }
}

void MarbleGeometryAssembler::mergeLine(const OSM::DataSet *dataSet, OSM::Way &way, const OSM::Way &otherWay) const
{
    const auto begin1 = nodeForId(dataSet, way.nodes.front());
    const auto end1 = nodeForId(dataSet, way.nodes.back());
    const auto begin2 = nodeForId(dataSet, otherWay.nodes.front());
    const auto end2 = nodeForId(dataSet, otherWay.nodes.back());
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
    }
}

void MarbleGeometryAssembler::mergeArea(const OSM::DataSet* dataSet, OSM::Way &way, const OSM::Way &otherWay) const
{
    // TODO
}

void MarbleGeometryAssembler::mergeRelations(OSM::DataSet *dataSet, OSM::DataSetMergeBuffer *mergeBuffer)
{
    // for relations we do:
    // 1. restore the original id
    // 2. replace all member ids with the restored ids for ways/relations
    // 3. if a relations with the restored id already exists, merge with its content

    for (auto &rel : mergeBuffer->relations) {
        for (auto &member : rel.members) {
            if (member.id >= 0) { // not a synthetic id
                continue;
            }

            if (member.type == OSM::Type::Way) {
                const auto it = m_wayIdMap.find(member.id);
                if (it != m_wayIdMap.end()) {
                    member.id = (*it).second;
                }
            }
        }

        // ### temporary scaffolding
        dataSet->addRelation(std::move(rel));
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

const OSM::Node* MarbleGeometryAssembler::nodeForId(const OSM::DataSet *dataSet, OSM::Id id) const
{
    const auto it = std::lower_bound(dataSet->nodes.begin(), dataSet->nodes.end(), id);
    if (it != dataSet->nodes.end() && (*it).id == id) {
        return &(*it);
    }
    return nullptr;
}