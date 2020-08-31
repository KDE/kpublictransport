/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "ztile.h"
#include "datatypes.h"

using namespace OSM;

OSM::BoundingBox ZTile::boundingBox() const
{
    const OSM::Coordinate min(z << (2 * depth));
    const OSM::Coordinate max(min.latitude + size(), min.longitude + size());
    return OSM::BoundingBox(min, max);
}

bool ZTile::intersects(OSM::BoundingBox bbox) const
{
    return OSM::intersects(boundingBox(), bbox);
}

bool ZTile::intersects(ZTile other) const
{
    const auto commonDepth = std::max(depth, other.depth);
    const auto z1 = z >> (2 * (commonDepth - depth));
    const auto z2 = other.z >> (2 * (commonDepth - other.depth));
    return z1 == z2;
}

ZTile ZTile::parent() const
{
    return ZTile{z >> 2, (uint8_t)(depth + 1)};
}

std::array<ZTile, 4> ZTile::quadSplit() const
{
    if (depth == 0) {
        return {};
    }

    const uint8_t subDepth = depth - 1;
    const uint64_t subZ = z << 2;

    return { ZTile{ subZ, subDepth }, ZTile{ subZ + 1, subDepth }, ZTile{ subZ + 2, subDepth }, ZTile { subZ + 3, subDepth } };
}

ZTile OSM::ztileFromBoundingBox(OSM::BoundingBox bbox)
{
    uint64_t zMin = bbox.min.z();
    uint64_t zMax = bbox.max.z();

    ZTile tile;

    while (zMin != zMax) {
        zMin >>= 2;
        zMax >>= 2;
        ++tile.depth;
    }
    tile.z = zMin;
    return tile;
}
