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

#ifndef KPUBLICTRANSPORT_LINEMETADATA_P_H
#define KPUBLICTRANSPORT_LINEMETADATA_P_H

#include <cstdint>

namespace KPublicTransport {

#pragma pack(push)
#pragma pack(1)

/** Static informaytion about a public transport line as stored in .rodata. */
struct LineMetaDataContent
{
    uint16_t nameIdx;
    uint16_t logoIdx;
    uint16_t productLogoIdx;
    uint8_t colorRed;
    uint8_t colorGreen;
    uint8_t colorBlue;

    constexpr inline uint32_t color() const
    {
        return 0xff000000 | colorRed << 16 | colorGreen << 8 | colorBlue;
    }
};

/** Quad tree depth map entries. */
struct LineMetaDataQuadTreeDepthIndex
{
    uint8_t depth;
    uint16_t offset;
};

inline bool operator<(LineMetaDataQuadTreeDepthIndex lhs, uint8_t rhs)
{
    return lhs.depth > rhs;
}

/** z-index to line meta data index mapping. */
struct LineMetaDataZIndex
{
    uint32_t z;
    uint16_t lineIdx;
};

static_assert(sizeof(LineMetaDataZIndex) == 6, "size of quad tree entry changed!");
static_assert(sizeof(LineMetaDataZIndex) % alignof(LineMetaDataZIndex) == 0, "alignment of quad tree entry introduces padding");

inline bool operator<(LineMetaDataZIndex lhs, uint32_t rhs)
{
    return lhs.z < rhs;
}

#pragma pack(pop)

}

#endif // KPUBLICTRANSPORT_LINEMETADATA_P_H
