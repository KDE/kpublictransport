/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "rentalvehicle.h"
#include "datatypes_p.h"
#include "individualtransport.h"
#include "json_p.h"

#include <KLocalizedString>

#include <QColor>
#include <QMetaEnum>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

namespace KPublicTransport {
class RentalVehicleNetworkPrivate : public QSharedData
{
public:
    QString name;
    QUrl url;
    RentalVehicle::VehicleTypes vehicleTypes = RentalVehicle::Unknown;
    QColor brandColor;
};

class RentalVehicleStationPrivate : public QSharedData
{
public:
    int availableVehicles = -1;
    int capacity = -1;
    RentalVehicleNetwork network;
    std::vector<int> capacities;
    std::vector<int> availabilities;
    QUrl webBookingUrl;
    QUrl appBookingUrl;
};

class RentalVehiclePrivate : public QSharedData
{
public:
    RentalVehicle::VehicleType type = RentalVehicle::Unknown;
    int remainingRange = -1;
    KPublicTransport::RentalVehicleNetwork network;
    QUrl webBookingUrl;
    QUrl appBookingUrl;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(RentalVehicleNetwork)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleNetwork, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleNetwork, QUrl, url, setUrl)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleNetwork, RentalVehicle::VehicleTypes, vehicleTypes, setVehicleTypes)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleNetwork, QColor, brandColor, setBrandColor)

bool RentalVehicleNetwork::hasBrandColor() const
{
    return d->brandColor.isValid();
}

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
    auto obj = Json::toJson(network);
    if (network.d->vehicleTypes == RentalVehicle::Unknown) {
        obj.remove("vehicleTypes"_L1);
    }
    return obj;
}

RentalVehicleNetwork RentalVehicleNetwork::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<RentalVehicleNetwork>(obj);
}

KPUBLICTRANSPORT_MAKE_GADGET(RentalVehicleStation)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleStation, int, availableVehicles, setAvailableVehicles)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleStation, int, capacity, setCapacity)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleStation, RentalVehicleNetwork, network, setNetwork)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleStation, QUrl, webBookingUrl, setWebBookingUrl)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleStation, QUrl, appBookingUrl, setAppBookingUrl)

bool RentalVehicleStation::isValid() const
{
    return d->network.isValid() || d->capacity >= 0 || d->availableVehicles >= 0;
}

RentalVehicle::VehicleTypes RentalVehicleStation::supportedVehicleTypes() const
{
    RentalVehicle::VehicleTypes types = {};
    const auto me = QMetaEnum::fromType<RentalVehicle::VehicleType>();
    for (auto i = 0; i < me.keyCount() && i < (int)d->capacities.size(); ++i) {
        if (d->capacities[i] >= 0) {
            types |= (RentalVehicle::VehicleType)me.value(i);
        }
    }
    return types | availableVehicleTypes();
}

RentalVehicle::VehicleTypes RentalVehicleStation::availableVehicleTypes() const
{
    RentalVehicle::VehicleTypes types = {};
    const auto me = QMetaEnum::fromType<RentalVehicle::VehicleType>();
    for (auto i = 0; i < me.keyCount() && i < (int)d->availabilities.size(); ++i) {
        if (d->availabilities[i] >= 0) {
            types |= (RentalVehicle::VehicleType)me.value(i);
        }
    }
    return types;
}

int RentalVehicleStation::capacity(RentalVehicle::VehicleType type) const
{
    const auto me = QMetaEnum::fromType<RentalVehicle::VehicleType>();
    for (auto i = 0; i < me.keyCount() && i < (int)d->capacities.size(); ++i) {
        if (me.value(i) == type) {
            return d->capacities[i];
        }
    }
    return -1;
}

void RentalVehicleStation::setCapacity(RentalVehicle::VehicleType type, int capacity)
{
    const auto me = QMetaEnum::fromType<RentalVehicle::VehicleType>();
    for (auto i = 0; i < me.keyCount(); ++i) {
        if (me.value(i) != type) {
            continue;
        }
        d->capacities.resize(std::max(d->capacities.size(), (std::size_t)(i + 1)), -1);
        d->capacities[i] = capacity;
        return;
    }
}

int RentalVehicleStation::availableVehicles(RentalVehicle::VehicleType type) const
{
    const auto me = QMetaEnum::fromType<RentalVehicle::VehicleType>();
    for (auto i = 0; i < me.keyCount() && i < (int)d->availabilities.size(); ++i) {
        if (me.value(i) == type) {
            return d->availabilities[i];
        }
    }
    return -1;
}

void RentalVehicleStation::setAvailableVehicles(RentalVehicle::VehicleType type, int count)
{
    const auto me = QMetaEnum::fromType<RentalVehicle::VehicleType>();
    for (auto i = 0; i < me.keyCount(); ++i) {
        if (me.value(i) != type) {
            continue;
        }
        d->availabilities.resize(std::max(d->availabilities.size(), (std::size_t)(i + 1)), -1);
        d->availabilities[i] = count;
        return;
    }
}

QString RentalVehicleStation::iconName() const
{
    const auto me = QMetaEnum::fromType<RentalVehicle::VehicleType>();
    for (auto i = 0; i < me.keyCount() && i < (int)d->capacities.size(); ++i) {
        if (d->capacities[i] >= 0) {
            return RentalVehicle::vehicleTypeIconName((RentalVehicle::VehicleType)me.value(i));
        }
    }
    return RentalVehicle::vehicleTypeIconName(RentalVehicle::Bicycle);
}

bool RentalVehicleStation::isSame(const RentalVehicleStation &lhs, const RentalVehicleStation &rhs)
{
    return RentalVehicleNetwork::isSame(lhs.network(), rhs.network());
}

static QJsonValue typeVectorToJson(const std::vector<int> &v)
{
    if (v.empty()) {
        return {};
    }
    QJsonObject obj;
    const auto me = QMetaEnum::fromType<RentalVehicle::VehicleType>();
    for (auto i = 0; i < me.keyCount() && i < (int)v.size(); ++i) {
        if (v[i] < 0) {
            continue;
        }
        obj.insert(QLatin1String(me.key(i)), v[i]);
    }
    return obj.isEmpty() ? QJsonValue() : obj;
}

QJsonObject RentalVehicleStation::toJson(const RentalVehicleStation &station)
{
    auto obj = Json::toJson(station);
    if (station.d->capacity < 0) {
        obj.remove("capacity"_L1);
    }
    if (station.d->availableVehicles < 0) {
        obj.remove("availableVehicles"_L1);
    }
    if (station.network().isValid()) {
        obj.insert("network"_L1, RentalVehicleNetwork::toJson(station.network()));
    }
    auto v = typeVectorToJson(station.d->capacities);
    if (v.isObject()) {
        obj.insert("capacitiesByType"_L1, v);
    }
    v = typeVectorToJson(station.d->availabilities);
    if (v.isObject()) {
        obj.insert("availabilitiesByType"_L1, v);
    }
    return obj;
}

static std::vector<int> typeVectorFromJson(const QJsonValue &v)
{
    std::vector<int> out;
    const auto obj = v.toObject();
    if (obj.isEmpty()) {
        return out;
    }

    const auto me = QMetaEnum::fromType<RentalVehicle::VehicleType>();
    for (auto i = 0; i < me.keyCount(); ++i) {
        const auto it = obj.find(QLatin1String(me.key(i)));
        if (it == obj.end()) {
            continue;
        }
        out.resize(i + 1, -1);
        out[i] = it.value().toInt();
    }

    return out;
}

RentalVehicleStation RentalVehicleStation::fromJson(const QJsonObject &obj)
{
    auto station = Json::fromJson<RentalVehicleStation>(obj);
    station.setNetwork(RentalVehicleNetwork::fromJson(obj.value(QLatin1String("network")).toObject()));
    station.d->capacities = typeVectorFromJson(obj.value(QLatin1String("capacitiesByType")));
    station.d->availabilities = typeVectorFromJson(obj.value(QLatin1String("availabilitiesByType")));
    return station;
}

KPUBLICTRANSPORT_MAKE_GADGET(RentalVehicle)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, RentalVehicle::VehicleType, type, setType)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, int, remainingRange, setRemainingRange)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, RentalVehicleNetwork, network, setNetwork)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, QUrl, webBookingUrl, setWebBookingUrl)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, QUrl, appBookingUrl, setAppBookingUrl)

QString RentalVehicle::vehicleTypeIconName(VehicleType type)
{
    switch (type) {
        case RentalVehicle::Unknown:
            break;
        case RentalVehicle::Bicycle:
        case RentalVehicle::Pedelec: // TODO
            return IndividualTransport::modeIconName(IndividualTransport::Bike);
        case RentalVehicle::ElectricMoped:
            return u"qrc:///org.kde.kpublictransport/assets/images/motorcycle.svg"_s;
        case RentalVehicle::ElectricKickScooter:
            return u"qrc:///org.kde.kpublictransport/assets/images/scooter.svg"_s;
        case RentalVehicle::Car:
            return IndividualTransport::modeIconName(IndividualTransport::Car);
    }
    return u"question"_s;
}

QString RentalVehicle::vehicleTypeIconName() const
{
    return vehicleTypeIconName(type());
}

QString RentalVehicle::label() const
{
    switch (type()) {
        case RentalVehicle::Unknown:
            break;
        case RentalVehicle::Bicycle:
        case RentalVehicle::Pedelec:
            return i18nc("rental vehicle type", "Rented bike");
        case RentalVehicle::ElectricMoped:
            return i18nc("rental vehicle type", "Rented moped");
        case RentalVehicle::ElectricKickScooter:
            return i18nc("rental vehicle type", "Rented kick scooter");
        case RentalVehicle::Car:
            return i18nc("rental vehicle type", "Rented car");
    }

    return {};
}

QJsonObject RentalVehicle::toJson(const RentalVehicle &vehicle)
{
    auto obj = Json::toJson(vehicle);
    if (vehicle.d->remainingRange < 0) {
        obj.remove(QLatin1String("remainingRange"));
    }
    if (vehicle.network().isValid()) {
        obj.insert(QLatin1String("network"), RentalVehicleNetwork::toJson(vehicle.network()));
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
