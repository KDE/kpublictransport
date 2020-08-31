/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
