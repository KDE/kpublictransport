/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "rentalvehicle.h"
#include "datatypes_p.h"
#include "individualtransport.h"
#include "json_p.h"
#include "rentalvehicleutil_p.h"

#include "gbfs/gbfsreader.h"
#include "gbfs/gbfsvehicletypes.h"

#include <KLocalizedString>

#include <QColor>
#include <QMetaEnum>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

namespace KPublicTransport {
class RentalVehicleTypePrivate : public QSharedData
{
public:
    RentalVehicleType::FormFactor formFactor = RentalVehicleType::FormFactor::Undefined;
    RentalVehicleType::PropulsionType propulsionType = RentalVehicleType::PropulsionType::Undefined;
    QString id; // TODO id set?
    QString name;
    double maxRangeMeters = NAN;
    double co2EmissionPerKm = NAN;
    int riderCapacity = -1;
    RentalVehicleType::ReturnConstraint returnConstraint = RentalVehicleType::ReturnConstraint::Undefined;
};

class RentalVehicleNetworkPrivate : public QSharedData
{
public:
    QString name;
    QUrl url;
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
    int remainingRange = -1;
    KPublicTransport::RentalVehicleNetwork network;
    KPublicTransport::RentalVehicleType vehicleType;
    QUrl webBookingUrl;
    QUrl appBookingUrl;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(RentalVehicleType)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, QString, id, setId)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, RentalVehicleType::FormFactor, formFactor, setFormFactor)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, RentalVehicleType::PropulsionType, propulsionType, setPropulsionType)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, double, maxRangeMeters, setMaxRangeMeters)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, int, riderCapacity, setRiderCapcatiry)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, double, co2EmissionPerKm, setCo2EmissionPerKm)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, RentalVehicleType::ReturnConstraint, returnConstraint, setReturnConstraint)

QString RentalVehicleType::typeIconName(RentalVehicleType::FormFactor formFactor, [[maybe_unused]] RentalVehicleType::PropulsionType propulsionType)
{
    // TODO propulsionType variants
    switch (formFactor) {
        case RentalVehicleType::FormFactor::Undefined:
            break;
        case RentalVehicleType::FormFactor::CargoBicycle: // TODO
        case RentalVehicleType::FormFactor::Bicycle:
            return IndividualTransport::modeIconName(IndividualTransport::Bike);
        case RentalVehicleType::FormFactor::Moped:
            return u"qrc:///org.kde.kpublictransport/assets/images/motorcycle.svg"_s;
        case RentalVehicleType::FormFactor::Other: // TODO?
        case RentalVehicleType::FormFactor::ScooterSeated: // TODO
        case RentalVehicleType::FormFactor::ScooterStanding:
            return u"qrc:///org.kde.kpublictransport/assets/images/scooter.svg"_s;
        case RentalVehicleType::FormFactor::Car:
            return IndividualTransport::modeIconName(IndividualTransport::Car);
    }
    return u"question"_s;
}

QJsonObject RentalVehicleType::toJson(const RentalVehicleType &vehicleType)
{
    auto obj = Json::toJson(vehicleType);
    if (vehicleType.d->riderCapacity < 0) {
        obj.remove("riderCapacity"_L1);
    }
    if (vehicleType.d->returnConstraint == ReturnConstraint::Undefined) {
        obj.remove("returnConstraint"_L1);
    }
    return obj;
}

RentalVehicleType RentalVehicleType::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<RentalVehicleType>(obj);
}


KPUBLICTRANSPORT_MAKE_GADGET(RentalVehicleNetwork)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleNetwork, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleNetwork, QUrl, url, setUrl)
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
    for (auto i = 0; i < me.keyCount() && i < (int)d->availabilities.size(); ++i) {
        if (d->availabilities[i] >= 0) {
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
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, int, remainingRange, setRemainingRange)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, RentalVehicleNetwork, network, setNetwork)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, RentalVehicleType, vehicleType, setVehicleType)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, QUrl, webBookingUrl, setWebBookingUrl)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, QUrl, appBookingUrl, setAppBookingUrl)

RentalVehicle::VehicleType RentalVehicle::type() const
{
    return RentalVehicleUtil::fromGbfsVehicleType(d->vehicleType);
}

void RentalVehicle::setType(RentalVehicle::VehicleType value)
{
    struct {
        RentalVehicle::VehicleType type;
        RentalVehicleType::FormFactor formFactor;
        RentalVehicleType::PropulsionType propulsionType;
    } static constexpr const type_map[] = {
        { RentalVehicle::Bicycle, RentalVehicleType::FormFactor::Bicycle, RentalVehicleType::PropulsionType::Human },
        { RentalVehicle::Pedelec, RentalVehicleType::FormFactor::Bicycle, RentalVehicleType::PropulsionType::ElectricAssist },
        { RentalVehicle::ElectricKickScooter, RentalVehicleType::FormFactor::ScooterStanding, RentalVehicleType::PropulsionType::Electric },
        { RentalVehicle::ElectricMoped, RentalVehicleType::FormFactor::Moped, RentalVehicleType::PropulsionType::Electric },
        { RentalVehicle::Car, RentalVehicleType::FormFactor::Car, RentalVehicleType::PropulsionType::Undefined },
    };

    const auto it = std::ranges::find_if(type_map, [value](const auto &m) { return m.type == value; });
    if (it == std::end(type_map)) {
        d->vehicleType = {};
    }
    d->vehicleType.setFormFactor((*it).formFactor);
    d->vehicleType.setPropulsionType((*it).propulsionType);
}

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
    return RentalVehicleType::typeIconName(d->vehicleType.formFactor(), d->vehicleType.propulsionType());
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
        obj.remove("remainingRange"_L1);
    }
    if (vehicle.network().isValid()) {
        obj.insert("network"_L1, RentalVehicleNetwork::toJson(vehicle.network()));
    }
    obj.insert("vehicleType"_L1, RentalVehicleType::toJson(vehicle.d->vehicleType));
    return obj;
}

RentalVehicle RentalVehicle::fromJson(const QJsonObject &obj)
{
    auto v = Json::fromJson<RentalVehicle>(obj);
    v.setNetwork(RentalVehicleNetwork::fromJson(obj.value("network"_L1).toObject()));
    if (const auto vtObj = obj.value("vehicleType"_L1).toObject(); !vtObj.isEmpty()) {
        v.setVehicleType(RentalVehicleType::fromJson(vtObj));
    } else if (const auto type = obj.value("type"_L1).toString(); !type.isEmpty()) {
        // backward compat
        v.setType(static_cast<RentalVehicle::VehicleType>(QMetaEnum::fromType<RentalVehicle::VehicleType>().keyToValue(type.toUtf8().constData())));
    }
    return v;
}

#include "moc_rentalvehicle.cpp"
