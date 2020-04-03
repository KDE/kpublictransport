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

#ifndef OSM_ZTILE_H
#define OSM_ZTILE_H

#include <array>
#include <cstdint>

namespace OSM {
class BoundingBox;

/** Tile in a quad tree made up out of z-order curve positions. */
class ZTile
{
public:
    constexpr ZTile() = default;
    constexpr inline ZTile(uint64_t _z, uint8_t _depth)
        : z(_z)
        , depth(_depth)
    {}

    constexpr inline bool operator<(ZTile other) const
    {
        return depth == other.depth ? z < other.z : depth > other.depth;
    }
    constexpr inline bool operator==(ZTile other) const
    {
        return depth == other.depth && z == other.z;
    }

    /** tile size in 1e7-th degrees **/
    constexpr inline uint32_t size() const
    {
        return (1 << depth) - 1;
    }

    BoundingBox boundingBox() const;
    bool intersects(BoundingBox bbox) const;
    bool intersects(ZTile other) const;

    /** The parent tile in a quad tree. */
    ZTile parent() const;
    /** Split into four sub-tiles on one level below. */
    std::array<ZTile, 4> quadSplit() const;


    uint64_t z = 0;
    uint8_t depth = 0;
};

/** The smallest tile entirely containing the given bounding box. */
ZTile ztileFromBoundingBox(BoundingBox bbox);

}

#endif // OSM_ZTILE_H
