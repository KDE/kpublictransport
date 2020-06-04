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
    void merge(OSM::DataSet *dataSet, OSM::DataSetMergeBuffer *mergeBuffer);

private:
    void mergeNodes(OSM::DataSet *dataSet, OSM::DataSetMergeBuffer *mergeBuffer);
    void mergeWays(OSM::DataSet *dataSet, OSM::DataSetMergeBuffer *mergeBuffer);
    void mergeRelations(OSM::DataSet *dataSet, OSM::DataSetMergeBuffer *mergeBuffer);

    void mergeWay(const OSM::DataSet *dataSet, OSM::Way &way, OSM::Way &otherWay) const;
    void mergeLine(const OSM::DataSet *dataSet, OSM::Way &way, const OSM::Way &otherWay) const;
    std::vector<OSM::Id> mergeArea(const OSM::DataSet *dataSet, OSM::Way &way, OSM::Way &otherWay) const;
    void mergeAreaSection(const OSM::DataSet *dataSet, std::vector<OSM::Id> &assembledPath, std::vector<OSM::Id> &path, const std::vector<OSM::Id>::const_iterator &pathBegin, std::vector<OSM::Id> &otherPath) const;

    template <typename Elem>
    OSM::Id takeMxOid(Elem &elem) const;

    const OSM::Node* nodeForId(const OSM::DataSet *dataSet, OSM::Id id) const;

    OSM::TagKey m_mxoidKey;
    std::unordered_map<OSM::Id, OSM::Id> m_wayIdMap;
};

}

#endif // KOSMINDOORMAP_MARBLEGEOMETRYASSEMBLER_H
