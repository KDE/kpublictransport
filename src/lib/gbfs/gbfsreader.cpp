/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsreader.h"

#include "gbfsvehicletypes.h"

#include <KPublicTransport/RentalVehicle>

#include <QColor>
#include <QJsonArray>
#include <QJsonDocument>
#include <QLocale>

#include <cmath>

using namespace Qt::Literals;
using namespace KPublicTransport;

static double readDouble(const QJsonValue &v)
{
    if (v.isDouble()) {
        return v.toDouble(NAN);
    }
    if (v.isString()) {
        bool valid = false;
        const auto d = v.toString().toDouble(&valid);
        return valid ? d : NAN;
    }
    return NAN;
}

double GBFSReader::readLatitude(const QJsonObject &obj)
{
    return readDouble(obj.value("lat"_L1));
}

double GBFSReader::readLongitude(const QJsonObject &obj)
{
    return readDouble(obj.value("lon"_L1));
}

QJsonObject GBFSReader::dataObject(const QJsonDocument &doc)
{
    auto obj = doc.object();
    const auto it = obj.find("data"_L1);
    if (it == obj.end() || !(*it).isObject()) {
        return obj;
    }
    return (*it).toObject();
}

QJsonValue GBFSReader::dataValue(const QJsonDocument &doc, QLatin1String name)
{
    return dataObject(doc).value(name);
}

QString GBFSReader::readLocalizedString(const QJsonObject &obj, QLatin1String key)
{
    const auto v = obj.value(key);
    if (!v.isArray()) {
        return v.toString();
    }
    const auto texts = v.toArray();
    if (texts.isEmpty()) {
        return {};
    }

    const auto findLang = [texts](QStringView lang) {
        for (const auto &textV : texts) {
            const auto textObj = textV.toObject();
            if (textObj.value("language"_L1).toString() == lang) {
                return textObj.value("text"_L1).toString();
            }
        }
        return QString();
    };

    const auto langs = QLocale().uiLanguages();
    for (const auto &lang : langs) {
        auto res = findLang(lang);
        if (!res.isEmpty()) {
            return res;
        }
        const auto idx = lang.indexOf('-'_L1);
        if (idx > 0) {
            res = findLang(lang.left(idx));
            if (!res.isEmpty()) {
                return res;
            }
        }
    }

    auto res = findLang(u"en");
    return res.isEmpty() ? texts.at(0).toObject().value("text"_L1).toString() : res;
}

RentalVehicleNetwork GBFSReader::readSystemInformation(const QJsonObject &sysInfo)
{
    RentalVehicleNetwork network;
    network.setName(GBFSReader::readLocalizedString(sysInfo, "name"_L1));
    network.setUrl(QUrl(sysInfo.value("url"_L1).toString()));
    if (const auto c = sysInfo.value("brand_assets"_L1).toObject().value("color"_L1).toString(); !c.isEmpty()) {
        network.setBrandColor(QColor::fromString(c));
    }
    return network;
}

template <typename T>
static void readRentalUris(const QJsonObject &obj, T &rental)
{
    const auto rental_uris = obj.value("rental_uris"_L1).toObject();
    rental.setWebBookingUrl(QUrl(rental_uris.value("web"_L1).toString()));
#ifdef Q_OS_ANDROID
    rental.setAppBookingUrl(QUrl(rental_uris.value("android"_L1).toString()));
#elif defined(Q_OS_IOS)
    rental.setAppBookingUrl(QUrl(rental_uris.value("ios"_L1).toString()));
#endif
}

RentalVehicleStation GBFSReader::readStationInformation(const QJsonObject &station, const GBFSVehicleTypes &vehicleTypes)
{
    RentalVehicleStation s;
    s.setCapacity(station.value("capacity"_L1).toInt(-1));
    // legacy pre GBFS v3
    const auto vehicleCapacities = station.value("vehicle_capacity"_L1).toObject();
    for (auto it = vehicleCapacities.begin(); it != vehicleCapacities.end(); ++it) {
        s.setCapacity({vehicleTypes.vehicleType(it.key())}, it.value().toInt(-1));
    }
    // GBFS v3 capcaities
    const auto vehicleTypesCapacity = station.value("vehicle_types_capacity"_L1).toArray();
    for (const auto &capV : vehicleTypesCapacity) {
        const auto capObj = capV.toObject();
        const auto ids = capObj.value("vehicle_type_ids"_L1).toArray();
        std::vector<RentalVehicleType> vts;
        vts.reserve(ids.size());
        std::ranges::transform(ids, std::back_inserter(vts), [&vehicleTypes](const auto &id) { return vehicleTypes.vehicleType(id.toString()); });
        s.setCapacity(vts, capObj.value("count"_L1).toInt(-1));
    }
    readRentalUris(station, s);
    return s;
}

void GBFSReader::readStationStatus(const QJsonObject &stat, RentalVehicleStation &s, const GBFSVehicleTypes &vehicleTypes)
{
    if (const auto num = stat.value("num_vehicles_available"_L1); num.isDouble()) {
        s.setAvailableVehicles(num.toInt(-1));
    } else {
        // legacy, before GBFS v3
        s.setAvailableVehicles(stat.value("num_bikes_available"_L1).toInt(-1));
    }
    const auto availableVehicleTypes = stat.value("vehicle_types_available"_L1).toArray();
    for (const auto &v : availableVehicleTypes) {
        const auto obj = v.toObject();
        const auto type = vehicleTypes.vehicleType(obj.value("vehicle_type_id"_L1).toString());
        s.setAvailableVehicles(type, obj.value("count"_L1).toInt(-1));
    }

    if (s.capacity() < 0) {
        if (const auto num = stat.value("num_docks_available"_L1).toInt(-1); num >= 0) {
            s.setCapacity(num + std::max(0, s.availableVehicles()));
        }
    }
}

RentalVehicle GBFSReader::readVehicleStatus(const QJsonObject &vehicle, const GBFSVehicleTypes &vehicleTypes)
{
    RentalVehicle v;

    auto vehicleTypeId = vehicle.value("vehicle_type_id"_L1).toString();
    if (vehicleTypeId.isEmpty()) { // non-compliant format used eg. by Lime
        vehicleTypeId = vehicle.value("vehicle_type"_L1).toString();
    }
    const auto vehicleType = vehicleTypes.vehicleType(vehicleTypeId);
    v.setVehicleType(vehicleType);

    const auto range = vehicle.value("current_range_meters"_L1).toInt();
    if (range > 0) { // there's too many reporting 0 for unknown that we can assume 0 means actually empty...
        v.setRemainingRange(range);
    }

    readRentalUris(vehicle, v);

    return v;
}
