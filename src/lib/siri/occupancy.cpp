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
    { "crushedStandingRoomOnly", Load::High },
    { "empty", Load::Low },
    { "fewSeatsAvailable", Load::Medium },
    { "full", Load::Full },
    { "manySeatsAvailable", Load::Low },
    { "notAcceptingPassengers", Load::Full },
    { "noData", Load::Unknown },
    { "seatsAvailable", Load::Medium }, // deprecated in SIRI 2.1
    { "standingAvailable", Load::High }, // deprecated in SIRI 2.1
    { "standingRoomOnly", Load::High },
};

Load::Category Siri::fromOccupancyEnum(QStringView occupancyEnumName)
{
    const auto it = std::lower_bound(std::begin(occupancy_map), std::end(occupancy_map), occupancyEnumName, [](const auto &lhs, auto rhs) {
        return QLatin1StringView(lhs.name) < rhs;
    });
    if (it == std::end(occupancy_map) || QLatin1StringView((*it).name) != occupancyEnumName) {
        return Load::Unknown;
    }
    return (*it).occupancy;
}
