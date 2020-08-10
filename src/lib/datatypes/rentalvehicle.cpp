/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "rentalvehicle.h"
#include "datatypes_p.h"
#include "json_p.h"

using namespace KPublicTransport;

namespace KPublicTransport {
class RentalVehicleNetworkPrivate : public QSharedData
{
public:
    QString name;
};

class RentalVehicleStationPrivate : public QSharedData
{
public:
    int availableVehicles = -1;
    int capacity = -1;
    RentalVehicleNetwork network;
};

class RentalVehiclePrivate : public QSharedData
{
public:
    RentalVehicle::VehicleType type = RentalVehicle::Unknown;
    KPublicTransport::RentalVehicleNetwork network;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(RentalVehicleNetwork)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleNetwork, QString, name, setName)

bool RentalVehicleNetwork::isValid() const
{
    return !d->name.isEmpty();
}

/** Checks if two instances refer to the same network. */
bool RentalVehicleNetwork::isSame(const RentalVehicleNetwork &lhs, const RentalVehicleNetwork &rhs)
{
    return lhs.name() == rhs.name();
}

QJsonObject RentalVehicleNetwork::toJson(const RentalVehicleNetwork &network)
{
    return Json::toJson(network);
}

RentalVehicleNetwork RentalVehicleNetwork::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<RentalVehicleNetwork>(obj);
}

KPUBLICTRANSPORT_MAKE_GADGET(RentalVehicleStation)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleStation, int, availableVehicles, setAvailableVehicles)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleStation, int, capacity, setCapacity)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleStation, RentalVehicleNetwork, network, setNetwork)

bool RentalVehicleStation::isValid() const
{
    return d->network.isValid() || d->capacity >= 0 || d->availableVehicles >= 0;
}

bool RentalVehicleStation::isSame(const RentalVehicleStation &lhs, const RentalVehicleStation &rhs)
{
    return RentalVehicleNetwork::isSame(lhs.network(), rhs.network());
}

QJsonObject RentalVehicleStation::toJson(const RentalVehicleStation &station)
{
    return Json::toJson(station);
}

RentalVehicleStation RentalVehicleStation::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<RentalVehicleStation>(obj);
}

KPUBLICTRANSPORT_MAKE_GADGET(RentalVehicle)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, RentalVehicle::VehicleType, type, setType)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, RentalVehicleNetwork, network, setNetwork)

QJsonObject RentalVehicle::toJson(const RentalVehicle &vehicle)
{
    auto obj = Json::toJson(vehicle);
    if (vehicle.network().isValid()) {
        obj.insert(QStringLiteral("network"), RentalVehicleNetwork::toJson(vehicle.network()));
    }
    return obj;
}

RentalVehicle RentalVehicle::fromJson(const QJsonObject &obj)
{
    auto v = Json::fromJson<RentalVehicle>(obj);
    v.setNetwork(RentalVehicleNetwork::fromJson(obj.value(QLatin1String("network")).toObject()));
    return v;
}

#include "moc_rentalvehicle.cpp"
