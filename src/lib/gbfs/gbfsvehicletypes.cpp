/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsvehicletypes.h"

#include "gbfs.h"
#include "gbfsreader.h"
#include "gbfsservice.h"
#include "gbfsstore.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace KPublicTransport;

namespace KPublicTransport {
static bool operator<(const GBFSVehicleType &lhs, const GBFSVehicleType &rhs)
{
    return lhs.typeId < rhs.typeId;
}
static bool operator<(const GBFSVehicleType &lhs, QStringView rhs)
{
    return lhs.typeId < rhs;
}
}

template <typename T>
struct value_map_entry
{
    const char *name;
    T value;
};

static constexpr const value_map_entry<GBFSVehicleType::FormFactor> form_factor_map[] = {
    { "bicycle", GBFSVehicleType::Bicycle },
    { "car", GBFSVehicleType::Car },
    { "moped", GBFSVehicleType::Moped },
    { "scooter", GBFSVehicleType::Scooter },
    { "other", GBFSVehicleType::Other },
};

static constexpr const value_map_entry<GBFSVehicleType::PropulsionType> propulsion_map[] = {
    { "human", GBFSVehicleType::Human },
    { "electric_assist", GBFSVehicleType::ElectricAssist },
    { "electric", GBFSVehicleType::Electric },
    { "combustion", GBFSVehicleType::Combustion },
};

template <typename T, std::size_t N>
static T lookupValue(const value_map_entry<T>(&map)[N], QStringView name)
{
    for (const auto &entry : map) {
        if (name.compare(QLatin1String(entry.name), Qt::CaseInsensitive) == 0) {
            return entry.value;
        }
    }
    qDebug() << "unknown value:" << name;
    return {};
}

// some services don't prove a vehicle_types file but use somewhat descriptive fixed values
// try to support that as well to the extend possible
struct fallback_entry {
    GBFSVehicleType::FormFactor formFactor;
    GBFSVehicleType::PropulsionType propulsionType;
};
static constexpr const value_map_entry<fallback_entry> fallback_type_map[] = {
    { "bike", { GBFSVehicleType::Bicycle, GBFSVehicleType::Human } },
    { "moped", { GBFSVehicleType::Moped, GBFSVehicleType::UndefinedPropulsion } },
    { "scooter", { GBFSVehicleType::Scooter, GBFSVehicleType::UndefinedPropulsion } },
    { "ebike", { GBFSVehicleType::Bicycle, GBFSVehicleType::ElectricAssist } },
    { "electric_moped", { GBFSVehicleType::Moped, GBFSVehicleType::Electric } },
};

GBFSVehicleType GBFSVehicleType::fromJson(const QJsonObject &obj)
{
    GBFSVehicleType v;
    v.typeId = obj.value(QLatin1String("vehicle_type_id")).toString();
    v.name = obj.value(QLatin1String("name")).toString();
    v.formFactor = lookupValue(form_factor_map, obj.value(QLatin1String("form_factor")).toString());
    v.propulsionType = lookupValue(propulsion_map, obj.value(QLatin1String("propulsion_type")).toString());
    return v;
}

GBFSVehicleTypes::GBFSVehicleTypes(const GBFSService &feed)
{
    GBFSStore store(feed.systemId);
    const auto doc = store.loadData(GBFS::VehicleTypes);
    const auto types = GBFSReader::dataValue(doc, QLatin1String("vehicle_types")).toArray();

    m_vehicleTypes.reserve(types.size());
    for (const auto &typeVal : types) {
        auto v = GBFSVehicleType::fromJson(typeVal.toObject());
        if (!v.typeId.isEmpty()) {
            m_vehicleTypes.push_back(std::move(v));
        }
    }

    std::sort(m_vehicleTypes.begin(), m_vehicleTypes.end());
    qDebug() << "Found" << m_vehicleTypes.size() << "vehicle types.";
}

GBFSVehicleTypes::~GBFSVehicleTypes() = default;

GBFSVehicleType GBFSVehicleTypes::vehicleType(QStringView typeId) const
{
    if (typeId.empty()) {
        return {};
    }

    const auto it = std::lower_bound(m_vehicleTypes.begin(), m_vehicleTypes.end(), typeId);
    if (it != m_vehicleTypes.end() && (*it).typeId == typeId) {
        return (*it);
    }

    // fallback for non-compliant services without vehicle_types file
    if (m_vehicleTypes.empty()) {
        for (const auto &val : fallback_type_map) {
            if (QLatin1String(val.name) == typeId) {
                GBFSVehicleType v;
                v.formFactor = val.value.formFactor;
                v.propulsionType = val.value.propulsionType;
                return v;
            }
        }
        qDebug() << "unknown fallback vehicle type:" << typeId;
    }

    return {};
}
