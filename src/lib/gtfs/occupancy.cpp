/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "occupancy.h"

using namespace KPublicTransport;

struct {
    const char *name;
    Load::Category occupancy;
} constexpr inline const occupancy_map[] = {
    { "CRUSHED_STANDING_ROOM_ONLY", Load::High },
    { "EMPTY", Load::Low },
    { "FEW_SEATS_AVAILABLE", Load::Medium },
    { "FULL", Load::Full },
    { "MANY_SEATS_AVAILABLE", Load::Low },
    { "NOT_ACCEPTING_PASSENGERS", Load::Full },
    { "NO_DATA_AVAILABLE", Load::Unknown },
    { "STANDING_ROOM_ONLY", Load::High },
};

Load::Category Gtfs::fromOccupancyStatus(QStringView occupancyStatus)
{
    const auto it = std::lower_bound(std::begin(occupancy_map), std::end(occupancy_map), occupancyStatus, [](const auto &lhs, auto rhs) {
        return QLatin1StringView(lhs.name) < rhs;
    });
    if (it == std::end(occupancy_map) || QLatin1StringView((*it).name) != occupancyStatus) {
        return Load::Unknown;
    }
    return (*it).occupancy;
}
