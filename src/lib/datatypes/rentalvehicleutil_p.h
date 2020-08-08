/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_RENTALVEHICLEUTIL_P_H
#define KPUBLICTRANSPORT_RENTALVEHICLEUTIL_P_H

namespace KPublicTransport {

class RentalVehicle;

/** Internal helpers for rental vehicles. */
namespace RentalVehicleUtil
{
    RentalVehicle merge(const RentalVehicle &lhs, const RentalVehicle &rhs);
}

}

#endif // KPUBLICTRANSPORT_RENTALVEHICLEUTIL_H
