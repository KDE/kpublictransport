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

using namespace Qt::Literals;
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
}

// some services don't prove a vehicle_types file but use somewhat descriptive fixed values
// try to support that as well to the extend possible
struct {
    const char *name;
    RentalVehicleType::FormFactor formFactor;
    RentalVehicleType::PropulsionType propulsionType;
} static constexpr const fallback_type_map[] = {
    { "bike", RentalVehicleType::FormFactor::Bicycle, RentalVehicleType::PropulsionType::Human },
    { "moped", RentalVehicleType::FormFactor::Moped, RentalVehicleType::PropulsionType::Undefined },
    { "scooter", RentalVehicleType::FormFactor::ScooterStanding, RentalVehicleType::PropulsionType::Undefined },
    { "ebike", RentalVehicleType::FormFactor::Bicycle, RentalVehicleType::PropulsionType::ElectricAssist },
    { "electric_moped", RentalVehicleType::FormFactor::Moped, RentalVehicleType::PropulsionType::Electric },
};

GBFSVehicleTypes::GBFSVehicleTypes(const QJsonDocument &doc)
{
    const auto types = GBFSReader::dataValue(doc, QLatin1String("vehicle_types")).toArray();

    m_vehicleTypes.reserve(types.size());
    for (const auto &typeVal : types) {
        auto v = GBFSVehicleType::fromGbfs(typeVal.toObject());
        if (!v.id().isEmpty()) {
            m_vehicleTypes.push_back(std::move(v));
        }
    }

    std::sort(m_vehicleTypes.begin(), m_vehicleTypes.end());
    qDebug() << "Found" << m_vehicleTypes.size() << "vehicle types.";
}

GBFSVehicleTypes::~GBFSVehicleTypes() = default;

RentalVehicleType GBFSVehicleTypes::vehicleType(QStringView typeId) const
{
    if (typeId.empty()) {
        return {};
    }

    const auto it = std::lower_bound(m_vehicleTypes.begin(), m_vehicleTypes.end(), typeId);
    if (it != m_vehicleTypes.end() && (*it).id() == typeId) {
        return (*it);
    }

    // fallback for non-compliant services without vehicle_types file
    if (m_vehicleTypes.empty()) {
        for (const auto &val : fallback_type_map) {
            if (QLatin1String(val.name) == typeId) {
                RentalVehicleType v;
                v.setFormFactor(val.formFactor);
                v.setPropulsionType(val.propulsionType);
                return v;
            }
        }
        qDebug() << "unknown fallback vehicle type:" << typeId;
    }

    return {};
}
