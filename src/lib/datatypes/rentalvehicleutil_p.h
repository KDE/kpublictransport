/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_RENTALVEHICLEUTIL_P_H
#define KPUBLICTRANSPORT_RENTALVEHICLEUTIL_P_H

#include <KPublicTransport/RentalVehicle>

#include "gbfs/gbfsvehicletypes.h"

namespace KPublicTransport {

class RentalVehicle;
class RentalVehicleNetwork;
class RentalVehicleStation;

/** Internal helpers for rental vehicles. */
namespace RentalVehicleUtil
{
    RentalVehicleNetwork merge(const RentalVehicleNetwork &lhs, const RentalVehicleNetwork &rhs);
    RentalVehicleStation merge(const RentalVehicleStation &lhs, const RentalVehicleStation &rhs);
    RentalVehicle merge(const RentalVehicle &lhs, const RentalVehicle &rhs);

    [[nodiscard]] RentalVehicle::VehicleType fromGbfsVehicleType(const GBFSVehicleType &vehicle);
}

}

#endif // KPUBLICTRANSPORT_RENTALVEHICLEUTIL_H
