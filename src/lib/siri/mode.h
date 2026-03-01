/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_SIRI_MODE_H
#define KPUBLICTRANSPORT_SIRI_MODE_H

#include <KPublicTransport/Line>

#include <internal/instance_counter.h>

#include <QMetaEnum>

namespace KPublicTransport {
namespace Siri {

#define SIRI_SUBMODE_ENUM(Type, ModeValue) \
Q_ENUM(Type) \
private: \
    static constexpr auto _submode_counter(detail::num<decltype(_submode_counter(detail::num<>()))::value + 1> n) \
        -> decltype(n) { return {}; } \
    static std::optional<Submode> submodeFromString(decltype(_submode_counter(detail::num<>())) n, QStringView s, VehicleMode mode) \
    { \
        if (mode != VehicleMode::ModeValue ) { \
            if (auto sm = submodeFromString(n.prev(), s, mode); sm) { return sm; } \
        }\
        if (mode == VehicleMode::ModeValue || mode == VehicleMode::unknown) { \
            return enumKeyToString<Type>(s); \
        } \
        return {}; \
    } \
    static constexpr VehicleMode modeForSubmode(Type) { return VehicleMode::ModeValue; }

/** SIRI mode of transport enums.
 *
 *  @note The enums here also act as string tables, so their exact spelling matters
 *  and has to match the SIRI standard.
 */
class Mode {
    Q_GADGET
public:
    enum class VehicleMode {
        air,
        bus,
        cableway,
        water,
        funicular,
        lift,
        rail,
        snowAndIce,
        metro,
        taxi,
        tram,
        trolleybus,
        monorail,
        coach,
        carpool,
        other,
        unknown,
    };
    Q_ENUM(VehicleMode)

    enum class AirSubmode {
        internationalFlight,
        domesticFlight,
        intercontinentalFlight,
        domesticScheduledFlight,
        shuttleFlight,
        intercontinentalCharterFlight,
        internationalCharterFlight,
        roundTripCharterFlight,
        sightseeingFlight,
        helicopterService,
        domesticCharterFlight,
        SchengenAreaFlight,
        airshipService,
        shortHaulInternationalFlight,
    };

    enum class BusSubmode {
        localBus,
        regionalBus,
        expressBus,
        nightBus,
        postBus,
        specialNeedsBus,
        mobilityBus,
        mobilityBusForRegisteredDisabled,
        sightseeingBus,
        shuttleBus,
        highFrequencyBus,
        dedicatedLaneBus,
        schoolBus,
        schoolAndPublicServiceBus,
        railReplacementBus,
        demandAndResponseBus,
        airportLinkBus,
    };

    enum class CoachSubmode {
        internationalCoach,
        nationalCoach,
        shuttleCoach,
        regionalCoach,
        specialCoach,
        schoolCoach,
        sightseeingCoach,
        touristCoach,
        commuterCoach,
    };

    enum class MetroSubmode {
        metro,
        tube,
        urbanRailway,
    };

    enum class RailSubmode {
        local,
        highSpeedRail,
        suburbanRailway,
        regionalRail,
        interregionalRail,
        longDistance,
        international,
        sleeperRailService,
        nightRail,
        carTransportRailService,
        touristRailway,
        airportLinkRail,
        railShuttle,
        replacementRailService,
        specialTrain,
        crossCountryRail,
        rackAndPinionRailway,
    };

    enum class TramSubmode {
        cityTram,
        localTram,
        regionalTram,
        sightseeingTram,
        shuttleTram,
        trainTram,
    };

    enum class WaterSubmode {
        internationalCarFerry,
        nationalCarFerry,
        regionalCarFerry,
        localCarFerry,
        internationalPassengerFerry,
        nationalPassengerFerry,
        regionalPassengerFerry,
        localPassengerFerry,
        postBoat,
        trainFerry,
        roadFerryLink,
        airportBoatLink,
        highSpeedVehicleService,
        highSpeedPassengerService,
        sightseeingService,
        schoolBoat,
        cableFerry,
        riverBus,
        scheduledFerry,
        shuttleFerryService,
        canalBarge,
    };

    enum class TelecabinSubmode {
        telecabin,
        cableCar,
        lift,
        chairLift,
        dragLift,
        telecabinLink,
    };

    enum class FunicularSubmode {
        funicular,
        streetCableCar,
    };

    enum class TaxiSubmode {
        communalTaxi,
        charterTaxi,
        waterTaxi,
        railTaxi,
        bikeTaxi,
        blackCab,
        miniCab,
    };

    /** Convert SIRI mode names to our mode enum.
     *  This also works with either one of the arguments missing.
     */
    [[nodiscard]] static Line::Mode fromString(QStringView mode, QStringView subMode);

    /** Convert a SIRI mode enum to its string representation. */
    template <typename T>
    [[nodiscard]] static const char* toString(T mode);

private:
    using Submode = std::variant<
        AirSubmode,
        BusSubmode,
        CoachSubmode,
        MetroSubmode,
        RailSubmode,
        TramSubmode,
        WaterSubmode,
        TelecabinSubmode,
        FunicularSubmode,
        TaxiSubmode
    >;

    template <typename T>
    [[nodiscard]] static std::optional<Submode> enumKeyToString(QStringView key)
    {
        auto me = QMetaEnum::fromType<T>();
        bool ok = false;
        const auto m = static_cast<T>(me.keyToValue(key.toUtf8().constData(), &ok));
        if (ok) {
            return m;
        }
        return {};
    }

    static constexpr detail::num<0> _submode_counter(detail::num<0>) { return {}; }
    static constexpr std::optional<Submode> submodeFromString(detail::num<0>, QStringView, VehicleMode) { return {}; }

    SIRI_SUBMODE_ENUM(AirSubmode, air)
    SIRI_SUBMODE_ENUM(BusSubmode, bus)
    SIRI_SUBMODE_ENUM(CoachSubmode, coach)
    SIRI_SUBMODE_ENUM(MetroSubmode, metro)
    SIRI_SUBMODE_ENUM(RailSubmode, rail)
    SIRI_SUBMODE_ENUM(TramSubmode, tram)
    SIRI_SUBMODE_ENUM(WaterSubmode, water)
    SIRI_SUBMODE_ENUM(TelecabinSubmode, cableway)
    SIRI_SUBMODE_ENUM(FunicularSubmode, funicular)
    SIRI_SUBMODE_ENUM(TaxiSubmode, taxi)

    // TODO hold a pair of VehicleMode | std::variant<SubModes...>
    // TODO add isSet/toString functions
    // TODO set operators
    // TODO line to mode set static function
};

#undef SIRI_SUBMODE_ENUM

template <typename T>
const char* Mode::toString(T mode)
{
    return QMetaEnum::fromType<T>().valueToKey(std::to_underlying(mode));
}

}
}

#endif
