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

/** Static information about a public transport line as stored in .rodata. */
struct LineMetaDataContent
{
    uint16_t nameIdx;
    uint32_t color; // TODO could be 24 bit
};

/** z-index to line meta data index mapping. */
struct LineMetaDataZIndex
{
    uint32_t z;
    uint16_t lineIdx;
};

}


#endif // KPUBLICTRANSPORT_LINEMETADATA_P_H

