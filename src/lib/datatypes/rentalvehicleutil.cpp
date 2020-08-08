/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "rentalvehicleutil_p.h"
#include "rentalvehicle.h"

using namespace KPublicTransport;

RentalVehicle RentalVehicleUtil::merge(const RentalVehicle &lhs, const RentalVehicle &rhs)
{
    // TODO
    return lhs.type() == RentalVehicle::Unknown ? rhs : lhs;
}
