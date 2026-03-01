/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
