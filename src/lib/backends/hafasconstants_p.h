/*
    SPDX-FileCopyrightText: Ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_HAFAS_CONSTANTS_P_H
#define KPUBLICTRANSPORT_HAFAS_CONSTANTS_P_H

#include <QLatin1StringView>

using namespace Qt::Literals;

namespace KPublicTransport {

constexpr inline const auto HAFAS_RT_ENTRY_DISABLED = "text.realtime.stop.entry.disabled"_L1;
constexpr inline const auto HAFAS_RT_EXIT_DISABLED = "text.realtime.stop.exit.disabled"_L1;
constexpr inline const auto HAFAS_RT_ENTRY_EXIT_DISABLED = "text.realtime.stop.entry.exit.disabled"_L1;

constexpr inline const auto HAFAS_RT_STOP_CANCELLED = "text.realtime.stop.cancelled"_L1;
constexpr inline const auto HAFAS_RT_JOURNEY_CANCELLED = "text.realtime.journey.cancelled"_L1;

}

#endif
