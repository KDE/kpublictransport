/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfs.h"

#include <QStringView>

#include <cstring>
#include <iterator>

using namespace KPublicTransport;

struct {
    const char *fileName;
    GBFS::FileType type;
} static constexpr const file_info_map[] = {
    // ### keep the first part matching the enum order
    { "gbfs", GBFS::Discovery },
    { "system_information", GBFS::SystemInformation },
    { "station_information", GBFS::StationInformation },
    { "station_status", GBFS::StationStatus },
    { "free_bike_status", GBFS::FreeBikeStatus },
    { "gbfs_versions", GBFS::Versions },
    { "vehicle_types", GBFS::VehicleTypes },
    { "geofencing_zones", GBFS::GeofencingZones },
    { "system_hours", GBFS::SystemHours },
    { "system_calendar", GBFS::SystemCalendar },
    { "system_regions", GBFS::SystemRegions },
    { "system_pricing_plans", GBFS::SystemPricingPlans },
    { "system_alerts", GBFS::SystemAlerts },

    // typos observed in the wild
    { "vehicles_types", GBFS::VehicleTypes },
    { "system regions", GBFS::SystemRegions },
};

const char* GBFS::keyNameForType(GBFS::FileType type)
{
    return file_info_map[type].fileName;
}

GBFS::FileType GBFS::typeForKeyName(QStringView v)
{
    const auto s = v.toUtf8();
    for (auto it = std::begin(file_info_map); it != std::end(file_info_map); ++it) {
        if (std::strcmp((*it).fileName, s.constData()) == 0 || (s.endsWith(".json") && std::strncmp((*it).fileName, s.constData(), s.size() - 5) == 0)) {
            return (*it).type;
        }
    }

    return GBFS::Unknown;
}
