/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mode.h"

#include <QMetaEnum>

using namespace Qt::Literals;
using namespace KPublicTransport;

template <typename ModeT>
struct ModeMap {
    ModeT siriMode;
    Line::Mode mode;
};

template <typename T>
static constexpr const T mode_map = {};

// complete mapping between SIRI modes and our modes
static constexpr const ModeMap<Siri::Mode::VehicleMode> vehilce_mode_map[] = {
    { Siri::Mode::VehicleMode::air, Line::Air },
    { Siri::Mode::VehicleMode::bus, Line::Bus },
    { Siri::Mode::VehicleMode::cableway, Line::AerialLift },
    { Siri::Mode::VehicleMode::water, Line::Ferry },
    { Siri::Mode::VehicleMode::funicular, Line::Funicular },
    { Siri::Mode::VehicleMode::lift, Line::AerialLift },
    { Siri::Mode::VehicleMode::rail, Line::Train },
    { Siri::Mode::VehicleMode::snowAndIce, Line::Unknown },
    { Siri::Mode::VehicleMode::metro, Line::Metro },
    { Siri::Mode::VehicleMode::taxi, Line::Taxi },
    { Siri::Mode::VehicleMode::tram, Line::Tramway },
    { Siri::Mode::VehicleMode::trolleybus, Line::Bus },
    { Siri::Mode::VehicleMode::monorail, Line::Train },
    { Siri::Mode::VehicleMode::coach, Line::Coach },
    { Siri::Mode::VehicleMode::carpool, Line::RideShare },
    { Siri::Mode::VehicleMode::other, Line::Unknown },
    { Siri::Mode::VehicleMode::unknown, Line::Unknown },
};

// partial maps between SIRI submodes and our modes, only containing deviations from the default
template<>
constexpr const ModeMap<Siri::Mode::BusSubmode> mode_map<Siri::Mode::BusSubmode>[] = {
    { Siri::Mode::BusSubmode::demandAndResponseBus, Line::Taxi },
};

template<>
constexpr const ModeMap<Siri::Mode::MetroSubmode> mode_map<Siri::Mode::MetroSubmode>[] = {
    { Siri::Mode::MetroSubmode::urbanRailway, Line::RapidTransit },
};

template <>
constexpr const ModeMap<Siri::Mode::RailSubmode> mode_map<Siri::Mode::RailSubmode>[] = {
    { Siri::Mode::RailSubmode::local, Line::LocalTrain },
    { Siri::Mode::RailSubmode::highSpeedRail, Line::LongDistanceTrain },
    { Siri::Mode::RailSubmode::suburbanRailway, Line::RapidTransit },
    { Siri::Mode::RailSubmode::regionalRail, Line::LocalTrain },
    { Siri::Mode::RailSubmode::longDistance, Line::LongDistanceTrain },
    { Siri::Mode::RailSubmode::international, Line::LongDistanceTrain },
    { Siri::Mode::RailSubmode::sleeperRailService, Line::LongDistanceTrain },
    { Siri::Mode::RailSubmode::nightRail, Line::LongDistanceTrain },
    { Siri::Mode::RailSubmode::airportLinkRail, Line::RapidTransit },
    { Siri::Mode::RailSubmode::railShuttle, Line::Shuttle },
};

template <>
constexpr const ModeMap<Siri::Mode::WaterSubmode> mode_map<Siri::Mode::WaterSubmode>[] = {
    { Siri::Mode::WaterSubmode::postBoat, Line::Boat },
    { Siri::Mode::WaterSubmode::airportBoatLink, Line::Boat },
    { Siri::Mode::WaterSubmode::sightseeingService, Line::Boat },
    { Siri::Mode::WaterSubmode::schoolBoat, Line::Boat },
    { Siri::Mode::WaterSubmode::riverBus, Line::Boat },
    { Siri::Mode::WaterSubmode::canalBarge, Line::Boat },
};

template <typename T>
[[nodiscard]] static T modeFromString(QStringView mode)
{
    auto me = QMetaEnum::fromType<T>();
    bool ok = false;
    const auto m = static_cast<T>(me.keyToValue(mode.toUtf8().constData(), &ok));
    return ok ? m : T::unknown;
}

template <typename T, std::size_t N>
[[nodiscard]] static std::optional<Line::Mode> toModeImpl(const ModeMap<T>(&modeMap)[N],  T mode)
{
    const auto it = std::ranges::find_if(modeMap, [mode](const auto &m) { return m.siriMode == mode; });
    if (it == std::end(modeMap)) {
        return {};
    }
    return (*it).mode;
}

template <typename T>
[[nodiscard]] static std::optional<Line::Mode> submodeToMode(T mode)
{
    if constexpr (requires(T) {{ mode_map<T>[0] };}) {
        return toModeImpl(mode_map<T>, mode);
    }
    return {};
}

Line::Mode Siri::Mode::fromString(QStringView mode, QStringView subMode)
{
    const auto siriMode = modeFromString<Siri::Mode::VehicleMode>(mode);
    const auto it = std::ranges::find_if(vehilce_mode_map, [siriMode](const auto &m) { return m.siriMode == siriMode; });
    const auto baseMode = (it == std::end(vehilce_mode_map)) ? Line::Unknown : (*it).mode;

    std::optional<Submode> siriSubmode = submodeFromString(_submode_counter(detail::num<>()), subMode, siriMode);
    if (siriSubmode) {
        if (auto m = std::visit([](auto &&m) -> std::optional<Line::Mode> { return submodeToMode(m); }, *siriSubmode); m) {
            return *m;
        }
        if (baseMode == Line::Unknown) {
            const auto siriBaseMode = std::visit([](auto &&m) -> VehicleMode { return modeForSubmode(m); }, *siriSubmode);
            const auto it = std::ranges::find_if(vehilce_mode_map, [siriBaseMode](const auto &m) { return m.siriMode == siriBaseMode; });
            if (it != std::end(vehilce_mode_map)) {
                return (*it).mode;
            }
        }
    }

    if (baseMode == Line::Unknown && (!mode.isEmpty() || !subMode.isEmpty())) {
        qDebug() << "unable to resolve SIRI mode:" << mode << subMode;
    }
    return baseMode;
}

#include "moc_mode.cpp"
