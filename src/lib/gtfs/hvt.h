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

#ifndef KPUBLICTRANSPORT_GTFS_HVT_H
#define KPUBLICTRANSPORT_GTFS_HVT_H

#include <KPublicTransport/Line>

namespace KPublicTransport {
/** GTFS utilities. */
namespace Gtfs {

/** Hierarchical vehicle type (HVT) mapping.
 *  @see https://developers.google.com/transit/gtfs/reference/#routestxt
 *  @see https://developers.google.com/transit/gtfs/reference/extended-route-types
 */
namespace Hvt
{
    /** Maps the numerical HVT value to a Line::Mode mode. */
    Line::Mode typeToMode(int hvt);
}

}
}

#endif // KPUBLICTRANSPORT_GTFS_HVT_H
