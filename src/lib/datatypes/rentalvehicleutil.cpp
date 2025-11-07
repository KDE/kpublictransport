/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "rentalvehicleutil_p.h"
#include "rentalvehicle.h"

#include "logging.h"

using namespace KPublicTransport;

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
    v.setType(std::max(lhs.type(), rhs.type()));
    return v;
}

RentalVehicle::VehicleType RentalVehicleUtil::fromGbfsVehicleType(const GBFSVehicleType &vehicle)
{
    static constexpr struct {
        GBFSVehicleType::FormFactor formFactor;
        GBFSVehicleType::PropulsionType propulsion;
        RentalVehicle::VehicleType type;
    } const type_map[] = {
        { GBFSVehicleType::UndefinedFormFactor, GBFSVehicleType::UndefinedPropulsion, RentalVehicle::Unknown },
        { GBFSVehicleType::Bicycle, GBFSVehicleType::Human, RentalVehicle::Bicycle },
        { GBFSVehicleType::Bicycle, GBFSVehicleType::ElectricAssist, RentalVehicle::Pedelec },
        { GBFSVehicleType::Scooter, GBFSVehicleType::Electric, RentalVehicle::ElectricKickScooter },
        { GBFSVehicleType::Scooter, GBFSVehicleType::ElectricAssist, RentalVehicle::ElectricKickScooter },
        { GBFSVehicleType::Scooter, GBFSVehicleType::UndefinedPropulsion, RentalVehicle::ElectricKickScooter },
        { GBFSVehicleType::Moped, GBFSVehicleType::Electric, RentalVehicle::ElectricMoped },
        { GBFSVehicleType::Moped, GBFSVehicleType::UndefinedPropulsion, RentalVehicle::ElectricMoped },
        { GBFSVehicleType::Car, GBFSVehicleType::Electric, RentalVehicle::Car },
        { GBFSVehicleType::Car, GBFSVehicleType::Combustion, RentalVehicle::Car },
    };

    for (const auto &map : type_map) {
        if (map.formFactor == vehicle.formFactor && map.propulsion == vehicle.propulsionType) {
            return map.type;
        }
    }

    qCDebug(Log) << "unhandled vehicle type:" << vehicle.formFactor << vehicle.propulsionType;
    return RentalVehicle::Unknown;
}
