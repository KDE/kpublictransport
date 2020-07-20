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

#ifndef KOSMINDOORMAP_MARBLEGEOMETRYASSEMBLER_H
#define KOSMINDOORMAP_MARBLEGEOMETRYASSEMBLER_H

#include <osm/datatypes.h>
#include <osm/datasetmergebuffer.h>

#include <unordered_map>

namespace KOSMIndoorMap {

/** Re-assemble broken up geometry in Marble vector tiles. */
class MarbleGeometryAssembler
{
public:
    MarbleGeometryAssembler();
    ~MarbleGeometryAssembler();

    /** Set the dataset to merge into.
     *  Has to be called before the first call to merge().
     */
    void setDataSet(OSM::DataSet *dataSet);

    /** Merge @p mergeBuffer into @p dataSet.
     *  Data not mergable at this point (e.g. due to missing connecting tiles)
     *  remains in @p mergeBuffer.
     */
    void merge(OSM::DataSetMergeBuffer *mergeBuffer);
    /** Processes remaining elements that couldn't be merged. */
    void finalize();

private:
    void mergeNodes(OSM::DataSetMergeBuffer *mergeBuffer);
    void mergeWays(std::vector<OSM::Way> &ways);
    void mergeRelations(OSM::DataSetMergeBuffer *mergeBuffer);

    void mergeWay(OSM::Way &way, OSM::Way &otherWay) const;
    void mergeLine(OSM::Way &way, OSM::Way &otherWay) const;
    std::vector<OSM::Id> mergeArea(OSM::Way &way, OSM::Way &otherWay) const;
    /**
     * @returns @c true when @p path has been completely processed, @c false otherwise
     */
    bool mergeAreaSection(std::vector<OSM::Id> &assembledPath, std::vector<OSM::Id> &path, const std::vector<OSM::Id>::iterator &pathBegin, std::vector<OSM::Id> &otherPath) const;

    void mergeRelation(OSM::Relation &relation, const OSM::Relation &otherRelation) const;

    template <typename Elem>
    OSM::Id takeMxOid(Elem &elem) const;

    const OSM::Node* nodeForId(OSM::Id id) const;
    OSM::Way* wayForId(OSM::Id id) const;

    OSM::DataSet *m_dataSet = nullptr;
    OSM::TagKey m_mxoidKey;
    OSM::TagKey m_typeKey;
    std::unordered_map<OSM::Id, OSM::Id> m_wayIdMap;
    std::unordered_map<OSM::Id, OSM::Id> m_relIdMap;

    std::vector<OSM::Way> m_pendingWays;
};

}

#endif // KOSMINDOORMAP_MARBLEGEOMETRYASSEMBLER_H
