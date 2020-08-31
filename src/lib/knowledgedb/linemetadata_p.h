/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LINEMETADATA_P_H
#define KPUBLICTRANSPORT_LINEMETADATA_P_H

#include <cstdint>

namespace KPublicTransport {

#pragma pack(push)
#pragma pack(1)

/** Static color structure. */
struct Color
{
    explicit constexpr inline Color() = default;
    explicit constexpr inline Color(uint32_t rgb)
        : colorRed(rgb >> 16)
        , colorGreen(rgb >> 8)
        , colorBlue(rgb)
    {}

    enum : uint8_t { Invalid = 0x01 };

    uint8_t colorRed = Invalid;
    uint8_t colorGreen = Invalid;
    uint8_t colorBlue = Invalid;

    constexpr inline uint32_t argb() const
    {
        if (colorRed == Invalid && colorGreen == Invalid && colorRed == Invalid) {
            return 0;
        }
        return 0xff000000 | colorRed << 16 | colorGreen << 8 | colorBlue;
    }
};

/** Static informaytion about a public transport line as stored in .rodata. */
struct LineMetaDataContent
{
    enum Mode : uint16_t {
        Tramway,
        Subway,
        RapidTransit
    };

    constexpr inline LineMetaDataContent(uint16_t _nameIdx, uint16_t _logoIdx, uint16_t _prodLogoIdx, Mode _mode, Color _col)
        : nameIdx(_nameIdx)
        , mode(_mode)
        , logoIdx(_logoIdx)
        , productLogoIdx(_prodLogoIdx)
        , color(_col)
    {}

    uint16_t nameIdx : 14;
    Mode mode : 2;
    uint16_t logoIdx;
    uint16_t productLogoIdx;

    Color color;
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
