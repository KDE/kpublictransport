/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "rentalvehicle.h"
#include "datatypes_p.h"
#include "json_p.h"

using namespace KPublicTransport;

namespace KPublicTransport {
class RentalVehiclePrivate : public QSharedData
{
public:
    RentalVehicle::VehicleType type = RentalVehicle::Unknown;
    QString network;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(RentalVehicle)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, RentalVehicle::VehicleType, type, setType)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, QString, network, setNetwork)

QJsonObject RentalVehicle::toJson(const RentalVehicle &vehicle)
{
    return Json::toJson(vehicle);
}

RentalVehicle RentalVehicle::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<RentalVehicle>(obj);
}

#include "moc_rentalvehicle.cpp"
