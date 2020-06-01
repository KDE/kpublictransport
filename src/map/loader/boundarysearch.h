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

#ifndef KOSMINDOORMAP_BOUNDARYSEARCH_H
#define KOSMINDOORMAP_BOUNDARYSEARCH_H

#include <osm/datatypes.h>

#include <unordered_set>

namespace KOSMIndoorMap {

/** Given a coordinate, this searches for the area that should be displayed on the map,
 *  so that the train station or airport at that coordinate is fully displayed.
 */
class BoundarySearch
{
public:
    /** Initialize a search around @p coord. */
    void init(OSM::Coordinate coord);
    /** Seach in the (incrementally updated) @p dataSet for the bounding box. */
    OSM::BoundingBox boundingBox(const OSM::DataSet &dataSet);

private:
    /** Grow @p bbox by @p meters. */
    OSM::BoundingBox growBoundingBox(const OSM::BoundingBox &bbox, double meters) const;
    /** Clamp @p bbox to be at most @p meters in size. */
    OSM::BoundingBox clampBoundingBox(const OSM::BoundingBox &bbox, double meters) const;

    OSM::Coordinate m_center;

    OSM::BoundingBox m_bbox;
    std::unordered_set<OSM::Id> m_relevantIds;
};

}

#endif // KOSMINDOORMAP_BOUNDARYSEARCH_H
