/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_SIRI_MODE_H
#define KPUBLICTRANSPORT_SIRI_MODE_H

#include <KPublicTransport/Line>

#include <internal/instance_counter.h>

#include <QMetaEnum>

class QJsonArray;
class QJsonObject;

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
            return submodeEnumKeyLookup<Type>(s); \
        } \
        return {}; \
    } \
    static constexpr VehicleMode modeForSubmode(Type) { return VehicleMode::ModeValue; } \
    static void fromModeSubmode(decltype(_submode_counter(detail::num<>())) n, Line::Mode mode, std::vector<Mode> &result) \
    { \
        fromModeSubmode(n.prev(), mode, result); \
        fromModeSubmodeImpl<Type>(mode, result); \
    } \

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

    Mode(VehicleMode mode, std::optional<Submode> submode = {})
        : m_mode(mode)
        , m_submode(submode)
    {
    }

    /** Create a SIRI mode from its string representation.
     *  This also works with either one of the arguments missing.
     */
    [[nodiscard]] static Mode fromString(QStringView mode, QStringView subMode);

    /** Convert a SIRI mode enum to its string representation. */
    template <typename T>
    [[nodiscard]] static const char* toString(T mode);

    /** Returns the set of SIRI (sub)modes that match one of our modes. */
    [[nodiscard]] static std::vector<Mode> fromMode(Line::Mode);
    [[nodiscard]] static std::vector<Mode> fromModes(const std::vector<Line::Mode> &modes);

    [[nodiscard]] VehicleMode mode() const { return m_mode; }
    [[nodiscard]] bool hasSubmode() const { return m_submode.has_value(); }
    [[nodiscard]] std::optional<Submode> submode() const { return m_submode; }

    /** SIRI string representation of the mode. */
    [[nodiscard]] const char* modeString() const;
    [[nodiscard]] const char* submodeString() const;
    /** SIRI type name of the submode in use. */
    [[nodiscard]] const char* submodeTypeName() const;

    /** Convert SIRI mode to our mode enum. */
    [[nodiscard]] Line::Mode toMode() const;

    std::strong_ordering operator<=>(const Mode &other) const;
    bool operator==(const Mode &other) const { return operator<=>(other) == std::strong_ordering::equal; }

    /** Returns @c true if this mode is a less specific parent of @p other. */
    [[nodiscard]] bool contains(const Mode &other) const;

    /** Loads SIRI modes from a JSON object.
     *  For use in e.g. OJP backend configuration.
     */
    [[nodiscard]] static Mode fromJson(const QJsonObject &json);
    [[nodiscard]] static std::vector<Mode> fromJson(const QJsonArray &json);

    /** Compute the intersection of two mode sets.
     *  @note both inputs are assumed to be ordered.
     */
    [[nodiscard]] static std::vector<Mode> intersection(const std::vector<Mode> &modes1, const std::vector<Mode> &modes2);

private:
    template <typename T>
    [[nodiscard]] static std::optional<Submode> submodeEnumKeyLookup(QStringView key);
    template <typename T>
    static void fromModeSubmodeImpl(Line::Mode mode, std::vector<Mode> &result);

    static constexpr detail::num<0> _submode_counter(detail::num<0>) { return {}; }
    static constexpr std::optional<Submode> submodeFromString(detail::num<0>, QStringView, VehicleMode) { return {}; }
    static constexpr void fromModeSubmode(detail::num<0>, Line::Mode, std::vector<Mode>&) {};

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

    VehicleMode m_mode = VehicleMode::unknown;
    std::optional<Submode> m_submode;
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
