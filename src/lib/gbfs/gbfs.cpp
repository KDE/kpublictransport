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
} static constexpr const file_info_map[] = {
    { "gbfs" },
    { "system_information" },
    { "station_information" },
    { "station_status" },
    { "free_bike_status" },
    { "gbfs_versions" },
    { "vehicle_types" },
    { "geofencing_zones" },
    { "system_hours" },
    { "system_calendar" },
    { "system_regions" },
    { "system_pricing_plans" },
    { "system_alerts" },
};

static_assert((sizeof(file_info_map) / sizeof(file_info_map[0])) == GBFS::Unknown, "");

const char* GBFS::keyNameForType(GBFS::FileType type)
{
    return file_info_map[type].fileName;
}

GBFS::FileType GBFS::typeForKeyName(QStringView v)
{
    const auto s = v.toUtf8();
    for (auto it = std::begin(file_info_map); it != std::end(file_info_map); ++it) {
        if (std::strcmp((*it).fileName, s.constData()) == 0) {
            return static_cast<GBFS::FileType>(std::distance(std::begin(file_info_map), it));
        }
    }

    return GBFS::Unknown;
}
