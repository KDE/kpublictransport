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

#include "linemetadata.h"
#include "linemetadata_data.cpp"
#include "datatypes/lineutil_p.h"

#include <osm/datatypes.h>
#include <osm/ztile.h>

#include <QColor>
#include <QDebug>
#include <QString>
#include <QUrl>

using namespace KPublicTransport;

static QString lookupName(uint16_t index)
{
    return QString::fromUtf8(line_name_stringtab + index);
}

static QString lookupLogo(uint16_t index)
{
    return QString::fromUtf8(line_logo_stringtab + index);
}

LineMetaData::LineMetaData() = default;
LineMetaData::LineMetaData(const LineMetaDataContent *dd)
    : d(dd)
{
}

LineMetaData::~LineMetaData() = default;
LineMetaData::LineMetaData(const LineMetaData&) = default;
LineMetaData& LineMetaData::operator=(const LineMetaData&) = default;

bool LineMetaData::isNull() const
{
    return d == nullptr;
}

QString LineMetaData::name() const
{
    return lookupName(d->nameIdx);
}

QColor LineMetaData::color() const
{
    return d && d->color.argb() ? QColor(d->color.argb()) : QColor();
}

QUrl LineMetaData::logoUrl() const
{
    if (!d) {
        return {};
    }
    const auto logoName = lookupLogo(d->logoIdx);
    return logoName.isEmpty() ? QUrl() : QUrl(QLatin1String("https://commons.wikimedia.org/wiki/Special:Redirect/file/") + logoName);
}

Line::Mode LineMetaData::mode() const
{
    if (!d) {
        return Line::Unknown;
    }
    switch (d->mode) {
        case LineMetaDataContent::Tramway:
            return Line::Tramway;
        case LineMetaDataContent::RapidTransit:
            return Line::RapidTransit;
        case LineMetaDataContent::Subway:
            return Line::Metro;
    };
    return Line::Unknown;
}

QUrl LineMetaData::modeLogoUrl() const
{
    if (!d) {
        return {};
    }
    const auto logoName = lookupLogo(d->productLogoIdx);
    return logoName.isEmpty() ? QUrl() : QUrl(QLatin1String("https://commons.wikimedia.org/wiki/Special:Redirect/file/") + logoName);
}

LineMetaData LineMetaData::find(double latitude, double longitude, const QString &name, Line::Mode mode)
{
    OSM::Coordinate coord(latitude, longitude);

    // overall quad tree parameters
    constexpr const auto depthCount = sizeof(line_data_depthOffsets) / sizeof(LineMetaDataQuadTreeDepthIndex);
    static_assert(depthCount > 1, "quad tree depth information error");
    constexpr const uint8_t maxDepth = line_data_depthOffsets[0].depth;
    constexpr const uint8_t minDepth = line_data_depthOffsets[depthCount - 1].depth;
    static_assert(maxDepth > minDepth, "quad tree depth error");
    static_assert(minDepth > 1, "quad tree depth error");

    // walk through the quad tree bottom up, looking for a tile containing the line we are looking for
    OSM::ZTile tile(coord.z() >> (2 * minDepth), minDepth);
    for (uint8_t d = minDepth; d <= maxDepth; ++d, tile = tile.parent()) {
        // determining quad tree offsets for the current depth
        const auto depthOffsetIt = std::lower_bound(std::begin(line_data_depthOffsets), std::end(line_data_depthOffsets), d);
        if (depthOffsetIt == std::end(line_data_depthOffsets) || (*depthOffsetIt).depth != d) {
            continue; // depth level isn't populated at all (yes, this can happen)
        }
        const auto treeBegin = std::begin(line_data_zquadtree) + (*depthOffsetIt).offset;
        const auto treeEnd = (depthOffsetIt + 1) == std::end(line_data_depthOffsets) ?
                std::end(line_data_zquadtree) :
                std::begin(line_data_zquadtree) + (*(depthOffsetIt + 1)).offset;

        // look up the tile for the given coordinate at depth d
        const auto treeIt = std::lower_bound(treeBegin, treeEnd, tile.z);
        if (treeIt == treeEnd || (*treeIt).z != tile.z) {
            continue; // tile doesn't exist at this depth
        }

        // iterate over the bucket of this tile and look for the line
        // we have to handle two cases: single lines and buckets of lines
        if ((*treeIt).lineIdx >= line_data_count) {
            auto bucketIt = line_data_bucketTable + (*treeIt).lineIdx - line_data_count;
            while ((*bucketIt) != -1) {
                const auto d = line_data + (*bucketIt);
                if (LineUtil::isSameLineNameStrict(lookupName(d->nameIdx), name) && LineUtil::isCompatibleMode(LineMetaData(d).mode(), mode)) {
                    return LineMetaData(d);
                }
                ++bucketIt;
            }
        } else {
            const auto d = line_data + (*treeIt).lineIdx;
            if (LineUtil::isSameLineNameStrict(lookupName(d->nameIdx), name) && LineUtil::isCompatibleMode(LineMetaData(d).mode(), mode)) {
                return LineMetaData(d);
            }
        }
    }

    return {};
}
