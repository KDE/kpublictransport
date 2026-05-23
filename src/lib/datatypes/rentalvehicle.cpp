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
static bool operator<(const RentalVehicleType &lhs, const RentalVehicleType &rhs)
{
    return lhs.id() < rhs.id();
}
static bool operator<(const RentalVehicleType &lhs, QStringView rhs)
{
    return lhs.id() < rhs;
}
static bool operator==(const RentalVehicleType &lhs, QStringView rhs)
{
    return lhs.id() == rhs;
}

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
    [[nodiscard]] RentalVehicleType vehicleType(QStringView id) const
    {
        auto it = std::lower_bound(vehicleTypes.begin(), vehicleTypes.end(), id);
        return it != vehicleTypes.end() && (*it).id() == id ? (*it) : RentalVehicleType();
    }

    void addVehicleType(const RentalVehicleType &vt)
    {
        const auto it = std::lower_bound(vehicleTypes.begin(), vehicleTypes.end(), vt);
        if (it == vehicleTypes.end() || (*it).id() != vt.id()) {
            vehicleTypes.insert(it, vt);
        }
    }

    int availableVehicles = -1;
    int capacity = -1;
    RentalVehicleNetwork network;
    std::vector<RentalVehicleType> vehicleTypes;
    std::vector<std::pair<std::vector<QString>, int>> capacities;
    std::unordered_map<QString, int> availabilities;
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

struct {
    const char *name;
    RentalVehicleType::FormFactor formFactor;
    RentalVehicleType::PropulsionType propulsionType;
} static constexpr const legacy_type_map[] = {
    { "Bicycle", RentalVehicleType::FormFactor::Bicycle, RentalVehicleType::PropulsionType::Human },
    { "Pedelec", RentalVehicleType::FormFactor::Bicycle, RentalVehicleType::PropulsionType::ElectricAssist },
    { "ElectricKickScooter", RentalVehicleType::FormFactor::ScooterStanding, RentalVehicleType::PropulsionType::Electric },
    { "ElectricMoped", RentalVehicleType::FormFactor::Moped, RentalVehicleType::PropulsionType::Electric },
    { "Car", RentalVehicleType::FormFactor::Car, RentalVehicleType::PropulsionType::Undefined },
};

[[nodiscard]] static RentalVehicleType legacyVehicleType(QStringView name)
{
    const auto it = std::ranges::find_if(legacy_type_map, [name](const auto &m) {
        return name == QLatin1StringView(m.name);
    });
    RentalVehicleType vt;
    if (it != std::end(legacy_type_map)) {
        vt.setFormFactor((*it).formFactor);
        vt.setPropulsionType((*it).propulsionType);
    }
    return vt;
}

KPUBLICTRANSPORT_MAKE_GADGET(RentalVehicleType)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, RentalVehicleType::FormFactor, formFactor, setFormFactor)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, RentalVehicleType::PropulsionType, propulsionType, setPropulsionType)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, double, maxRangeMeters, setMaxRangeMeters)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, int, riderCapacity, setRiderCapcatiry)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, double, co2EmissionPerKm, setCo2EmissionPerKm)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicleType, RentalVehicleType::ReturnConstraint, returnConstraint, setReturnConstraint)

QString RentalVehicleType::id() const
{
    if (!d->id.isEmpty() || d->formFactor == RentalVehicleType::FormFactor::Undefined) {
        return d->id;
    }

    // make sure we always have an id, for RentalVehicleStation to use this as a key
    return "generic:"_L1 + QLatin1StringView(GBFSVehicleType::toString(d->formFactor)) + '-'_L1 + QLatin1StringView(GBFSVehicleType::toString(d->propulsionType));
}

void RentalVehicleType::setId(const QString &value)
{
    d.detach();
    d->id = value;
}

QString RentalVehicleType::typeIconName() const
{
    return RentalVehicleType::typeIconName(d->formFactor, d->propulsionType);
}

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

QString RentalVehicleType::label() const
{
    switch (d->formFactor) {
        case RentalVehicleType::FormFactor::Undefined:
            break;
        case RentalVehicleType::FormFactor::Bicycle:
            return i18nc("rental vehicle type", "Rented bike");
        case RentalVehicleType::FormFactor::Moped:
            return i18nc("rental vehicle type", "Rented moped");
        case RentalVehicleType::FormFactor::ScooterStanding:
            return i18nc("rental vehicle type", "Rented kick scooter");
        case RentalVehicleType::FormFactor::Car:
            return i18nc("rental vehicle type", "Rented car");
        case RentalVehicleType::FormFactor::CargoBicycle:
            return i18nc("rental vehicle type", "Rented cargo bike");
        case RentalVehicleType::FormFactor::ScooterSeated: // TODO
        case RentalVehicleType::FormFactor::Other:
            return i18nc("rental vehicle type", "Rented vehicle");
    }

    return {};
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

QJsonArray RentalVehicleType::toJson(const std::vector<RentalVehicleType> &vehicleTypes)
{
    return Json::toJson(vehicleTypes);
}

RentalVehicleType RentalVehicleType::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<RentalVehicleType>(obj);
}

std::vector<RentalVehicleType> RentalVehicleType::fromJson(const QJsonArray &array)
{
    return Json::fromJson<RentalVehicleType>(array);
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

QList<RentalVehicleType> RentalVehicleStation::supportedVehicleTypes() const
{
    QList<RentalVehicleType> res = availableVehicleTypes();
    for (const auto &c : d->capacities) {
        for (const auto &id : c.first) {
            if (!res.contains(id)) {
                res.push_back(d->vehicleType(id));
            }
        }
    }
    return res;
}

QList<RentalVehicleType> RentalVehicleStation::availableVehicleTypes() const
{
    QList<RentalVehicleType> res;
    for (auto it = d->availabilities.begin(); it != d->availabilities.end(); ++it) {
        if ((*it).second <= 0) {
            continue;
        }
        res.push_back(d->vehicleType((*it).first));
    }
    return res;
}

int RentalVehicleStation::capacityByType(const RentalVehicleType &type) const
{
    for (const auto &c : d->capacities) {
        if (std::ranges::binary_search(c.first, type.id())) {
            return c.second;
        }
    }
    return -1;
}

void RentalVehicleStation::setCapacity(const std::vector<RentalVehicleType> &types, int capacity)
{
    if (types.empty()) {
        return;
    }

    d.detach();
    for (const auto &vt : types) {
        d->addVehicleType(vt);
    }

    std::vector<QString> ids;
    ids.reserve(types.size());
    std::ranges::transform(types, std::back_inserter(ids), [](const auto &vt) { return vt.id(); });
    std::ranges::sort(ids);

    d->capacities.erase(std::remove_if(d->capacities.begin(), d->capacities.end(), [&ids](const auto &c) {
        return std::ranges::includes(c.first, ids) || std::ranges::includes(ids, c.first);
    }), d->capacities.end());

    d->capacities.emplace_back(ids, capacity);
}

int RentalVehicleStation::availableVehiclesByType(const RentalVehicleType &type) const
{
    const auto it = d->availabilities.find(type.id());
    return it != d->availabilities.end() ? (*it).second : -1;
}

void RentalVehicleStation::setAvailableVehicles(const RentalVehicleType &type, int count)
{
    d.detach();
    d->addVehicleType(type);
    d->availabilities[type.id()] = count;
}

QString RentalVehicleStation::iconName() const
{
    for (const auto &c : d->capacities) {
        if (c.second >= 0) {
            return d->vehicleType(c.first.front()).typeIconName();
        }
    }
    for (auto it = d->availabilities.begin(); it != d->availabilities.end(); ++it) {
        if ((*it).second >= 0) {
            return d->vehicleType((*it).first).typeIconName();
        }
    }
    return RentalVehicleType::typeIconName(RentalVehicleType::FormFactor::Bicycle, RentalVehicleType::PropulsionType::Human);
}

bool RentalVehicleStation::isSame(const RentalVehicleStation &lhs, const RentalVehicleStation &rhs)
{
    return RentalVehicleNetwork::isSame(lhs.network(), rhs.network());
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
    if (!station.d->vehicleTypes.empty()) {
        obj.insert("vehicleTypes"_L1, RentalVehicleType::toJson(station.d->vehicleTypes));
    }
    if (!station.d->capacities.empty()) {
        QJsonArray capsArray;
        for (const auto &c : station.d->capacities) {
            QJsonObject capObj;
            QJsonArray types;
            std::ranges::copy(c.first, std::back_inserter(types));
            capObj.insert("vehicleTypes"_L1, types);
            capObj.insert("count"_L1, c.second);
            capsArray.push_back(std::move(capObj));
        }
        obj.insert("capacitiesByType"_L1, capsArray);
    }
    if (!station.d->availabilities.empty()) {
        QJsonObject availObj;
        for (auto it = station.d->availabilities.begin(); it != station.d->availabilities.end(); ++it) {
            availObj.insert((*it).first, (*it).second);
        }
        obj.insert("availabilitiesByType"_L1, availObj);
    }
    return obj;
}

RentalVehicleStation RentalVehicleStation::fromJson(const QJsonObject &obj)
{
    auto station = Json::fromJson<RentalVehicleStation>(obj);
    station.setNetwork(RentalVehicleNetwork::fromJson(obj.value("network"_L1).toObject()));
    station.d->vehicleTypes = RentalVehicleType::fromJson(obj.value("vehicleTypes"_L1).toArray());

    const auto capsByType = obj.value("capacitiesByType"_L1);
    if (capsByType.isArray()) {
        const auto caps = capsByType.toArray();
        for (const auto capV : caps) {
            const auto capObj = capV.toObject();
            const auto idsArray = capObj.value("vehicleTypes"_L1).toArray();
            std::vector<QString> ids;
            ids.reserve(idsArray.size());
            std::ranges::transform(idsArray, std::back_inserter(ids), [](const auto &v) { return v.toString(); });
            station.d->capacities.emplace_back(std::move(ids), capObj.value("count"_L1).toInt(-1));
        }
    } else if (capsByType.isObject()) {
        // backward compat
        const auto capsObj = capsByType.toObject();
        for (auto it = capsObj.begin(); it != capsObj.end(); ++it) {
            const auto vt = legacyVehicleType(it.key());
            station.d->addVehicleType(vt);
            station.d->capacities.emplace_back(std::vector<QString>{vt.id()}, it.value().toInt(-1));
        }
    }

    const auto availObj = obj.value("availabilitiesByType"_L1).toObject();
    for (auto it = availObj.begin(); it != availObj.end(); ++it) {
        const auto id = it.key();
        const auto hasType = std::ranges::find_if(station.d->vehicleTypes, [id](const auto &vt) { return vt.id() == id; }) != station.d->vehicleTypes.end();
        if (hasType) {
            station.d->availabilities[id] = it.value().toInt(-1);
        } else {
            const auto vt = legacyVehicleType(id);
            station.d->addVehicleType(vt);
            station.d->availabilities[vt.id()] = it.value().toInt(-1);
        }
    }

    return station;
}

KPUBLICTRANSPORT_MAKE_GADGET(RentalVehicle)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, int, remainingRange, setRemainingRange)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, RentalVehicleNetwork, network, setNetwork)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, RentalVehicleType, vehicleType, setVehicleType)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, QUrl, webBookingUrl, setWebBookingUrl)
KPUBLICTRANSPORT_MAKE_PROPERTY(RentalVehicle, QUrl, appBookingUrl, setAppBookingUrl)

QString RentalVehicle::vehicleTypeIconName() const
{
    return d->vehicleType.typeIconName();
}

QString RentalVehicle::label() const
{
    return d->vehicleType.label();
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
        v.setVehicleType(legacyVehicleType(type));
    }
    return v;
}

#include "moc_rentalvehicle.cpp"
