/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "rentalvehicleutil_p.h"
#include "rentalvehicle.h"

#include "logging.h"

using namespace KPublicTransport;

RentalVehicleType RentalVehicleUtil::merge(const RentalVehicleType &lhs, const RentalVehicleType &rhs)
{
    // TODO
    return lhs.formFactor() == RentalVehicleType::FormFactor::Undefined ? rhs : lhs;
}

RentalVehicleNetwork RentalVehicleUtil::merge(const RentalVehicleNetwork &lhs, const RentalVehicleNetwork &rhs)
{
    // TODO
    return lhs.isValid() ? lhs : rhs;
}

RentalVehicleStation RentalVehicleUtil::merge(const RentalVehicleStation &lhs, const RentalVehicleStation &rhs)
{
    auto s = lhs;
    s.setNetwork(RentalVehicleUtil::merge(lhs.network(), rhs.network()));
    s.setCapacity(std::max(lhs.capacity(), rhs.capacity()));
    s.setAvailableVehicles(std::max(lhs.availableVehicles(), rhs.availableVehicles()));
    return s;
}

RentalVehicle RentalVehicleUtil::merge(const RentalVehicle &lhs, const RentalVehicle &rhs)
{
    auto v = lhs;
    v.setNetwork(RentalVehicleUtil::merge(lhs.network(), rhs.network()));
    v.setVehicleType(RentalVehicleUtil::merge(lhs.vehicleType(), rhs.vehicleType()));
    return v;
}

RentalVehicle::VehicleType RentalVehicleUtil::fromGbfsVehicleType(const RentalVehicleType &vehicle)
{
    static constexpr struct {
        RentalVehicleType::FormFactor formFactor;
        RentalVehicleType::PropulsionType propulsion;
        RentalVehicle::VehicleType type;
    } const type_map[] = {
        { RentalVehicleType::FormFactor::Undefined, RentalVehicleType::PropulsionType::Undefined, RentalVehicle::Unknown },
        { RentalVehicleType::FormFactor::Bicycle, RentalVehicleType::PropulsionType::Human, RentalVehicle::Bicycle },
        { RentalVehicleType::FormFactor::Bicycle, RentalVehicleType::PropulsionType::ElectricAssist, RentalVehicle::Pedelec },
        { RentalVehicleType::FormFactor::ScooterStanding, RentalVehicleType::PropulsionType::Electric, RentalVehicle::ElectricKickScooter },
        { RentalVehicleType::FormFactor::ScooterStanding, RentalVehicleType::PropulsionType::ElectricAssist, RentalVehicle::ElectricKickScooter },
        { RentalVehicleType::FormFactor::ScooterStanding, RentalVehicleType::PropulsionType::Undefined, RentalVehicle::ElectricKickScooter },
        { RentalVehicleType::FormFactor::Moped, RentalVehicleType::PropulsionType::Electric, RentalVehicle::ElectricMoped },
        { RentalVehicleType::FormFactor::Moped, RentalVehicleType::PropulsionType::Undefined, RentalVehicle::ElectricMoped },
        { RentalVehicleType::FormFactor::Car, RentalVehicleType::PropulsionType::Electric, RentalVehicle::Car },
        { RentalVehicleType::FormFactor::Car, RentalVehicleType::PropulsionType::Combustion, RentalVehicle::Car },
        { RentalVehicleType::FormFactor::Car, RentalVehicleType::PropulsionType::CombustionDiesel, RentalVehicle::Car },
        { RentalVehicleType::FormFactor::Car, RentalVehicleType::PropulsionType::Hybrid, RentalVehicle::Car },
    };

    for (const auto &map : type_map) {
        if (map.formFactor == vehicle.formFactor() && map.propulsion == vehicle.propulsionType()) {
            return map.type;
        }
    }

    qCDebug(Log) << "unhandled vehicle type:" << vehicle.formFactor() << vehicle.propulsionType();
    return RentalVehicle::Unknown;
}
