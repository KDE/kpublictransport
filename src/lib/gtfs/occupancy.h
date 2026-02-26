/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GTFS_OCCUPANCY_H
#define KPUBLICTRANSPORT_GTFS_OCCUPANCY_H

#include <KPublicTransport/Load>

namespace KPublicTransport {

namespace Gtfs {

/** Convert a GTFS-RT OccupancyStatus enum value to our own occupancy representation. */
Load::Category fromOccupancyStatus(QStringView occupancyStatus);

}
}

#endif
