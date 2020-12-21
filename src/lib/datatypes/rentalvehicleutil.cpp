/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "rentalvehicleutil_p.h"
#include "rentalvehicle.h"

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
