/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFS_H
#define KPUBLICTRANSPORT_GBFS_H

class QStringView;

namespace KPublicTransport {

/** General GBFS utilities. */
namespace GBFS
{
    /** Types of GBFS files.
     *  @see https://github.com/NABSA/gbfs/blob/master/gbfs.md#files
     */
    enum FileType {
        Discovery,
        SystemInformation,
        StationInformation,
        StationStatus,
        FreeBikeStatus,
        Versions,
        VehicleTypes,
        GeofencingZones,
        SystemHours,
        SystemCalendar,
        SystemRegions,
        SystemPricingPlans,
        SystemAlerts,
        Unknown, // keep last
    };

    const char* keyNameForType(FileType type);
    FileType typeForKeyName(QStringView v);
}

}

#endif // KPUBLICTRANSPORT_GBFS_H
