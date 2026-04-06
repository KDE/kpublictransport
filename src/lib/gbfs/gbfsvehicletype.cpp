/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsvehicletype.h"

#include "gbfsreader.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace Qt::Literals;
using namespace KPublicTransport;

template <typename T>
struct value_map_entry
{
    const char *name;
    T value;
};

static constexpr const value_map_entry<RentalVehicleType::FormFactor> form_factor_map[] = {
    { "bicycle", RentalVehicleType::FormFactor::Bicycle },
    { "car", RentalVehicleType::FormFactor::Car },
    { "cargo_bicycle", RentalVehicleType::FormFactor::CargoBicycle },
    { "moped", RentalVehicleType::FormFactor::Moped },
    { "scooter_seating", RentalVehicleType::FormFactor::ScooterSeated },
    { "scooter_standing", RentalVehicleType::FormFactor::ScooterStanding },
    { "other", RentalVehicleType::FormFactor::Other },
};

static constexpr const value_map_entry<RentalVehicleType::FormFactor> form_factor_legacy_map[] = {
    { "scooter", RentalVehicleType::FormFactor::ScooterStanding },
};

static constexpr const value_map_entry<RentalVehicleType::PropulsionType> propulsion_map[] = {
    { "human", RentalVehicleType::PropulsionType::Human },
    { "electric_assist", RentalVehicleType::PropulsionType::ElectricAssist },
    { "electric", RentalVehicleType::PropulsionType::Electric },
    { "combustion", RentalVehicleType::PropulsionType::Combustion },
    { "combustion_diesel", RentalVehicleType::PropulsionType::CombustionDiesel },
    { "hybrid", RentalVehicleType::PropulsionType::Hybrid },
    { "hydrogen_fuel_cell",  RentalVehicleType::PropulsionType::HydrogenFuelCell },
    { "plug_in_hybrid", RentalVehicleType::PropulsionType::PlugInHybrid },
};

static constexpr const value_map_entry<RentalVehicleType::ReturnConstraint> return_contraint_map[] = {
    { "free_floating", RentalVehicleType::ReturnConstraint::FreeFloating },
    { "roundtrip_station", RentalVehicleType::ReturnConstraint::RoundtripStation },
    { "any_station", RentalVehicleType::ReturnConstraint::AnyStation },
    { "hybrid", RentalVehicleType::ReturnConstraint::Hybrid },
};

template <typename T, std::size_t N>
static std::optional<T> lookupValue(const value_map_entry<T>(&map)[N], QStringView name)
{
    const auto it = std::ranges::find_if(map, [name](const auto &entry) {
        return name.compare(QLatin1StringView(entry.name), Qt::CaseInsensitive) == 0;
    });
    return it == std::end(map) ? std::optional<T>() : (*it).value;
}

template <typename T, std::size_t N>
static const char* valueToString(const value_map_entry<T>(&map)[N], T value)
{
    const auto it = std::ranges::find_if(map, [value](const auto &m) { return m.value == value; });
    return it != std::end(map) ? (*it).name : nullptr;
}

RentalVehicleType::FormFactor GBFSVehicleType::toFormFactor(QStringView formFactor)
{
    if (const auto ff = lookupValue(form_factor_map, formFactor); ff) {
        return *ff;
    }
    return lookupValue(form_factor_legacy_map, formFactor).value_or(RentalVehicleType::FormFactor::Undefined);
}

RentalVehicleType::PropulsionType GBFSVehicleType::toPropulsionType(QStringView propulsionType)
{
    return lookupValue(propulsion_map, propulsionType).value_or(RentalVehicleType::PropulsionType::Undefined);
}

RentalVehicleType::ReturnConstraint GBFSVehicleType::toReturnConstraint(QStringView returnConstraint)
{
    return lookupValue(return_contraint_map, returnConstraint).value_or(RentalVehicleType::ReturnConstraint::Undefined);
}

const char* GBFSVehicleType::toString(RentalVehicleType::FormFactor formFactor)
{
    return valueToString(form_factor_map, formFactor);
}

const char* GBFSVehicleType::toString(RentalVehicleType::PropulsionType propulsionType)
{
    return valueToString(propulsion_map, propulsionType);
}

const char* GBFSVehicleType::toString(RentalVehicleType::ReturnConstraint returnConstraint)
{
    return valueToString(return_contraint_map, returnConstraint);
}

RentalVehicleType GBFSVehicleType::fromGbfs(const QJsonObject &obj)
{
    RentalVehicleType vt;
    vt.setId(obj.value("vehicle_type_id"_L1).toString());
    vt.setName(GBFSReader::readLocalizedString(obj, "name"_L1));
    vt.setFormFactor(GBFSVehicleType::toFormFactor(obj.value("form_factor"_L1).toString()));
    vt.setPropulsionType(GBFSVehicleType::toPropulsionType(obj.value("propulsion_type"_L1).toString()));
    vt.setMaxRangeMeters(obj.value("max_range_meters"_L1).toDouble(NAN));
    vt.setRiderCapcatiry(obj.value("rider_capacity"_L1).toInt(-1));
    vt.setCo2EmissionPerKm(obj.value("g_CO2_km"_L1).toDouble(NAN));
    vt.setReturnConstraint(GBFSVehicleType::toReturnConstraint(obj.value("return_constraint"_L1).toString()));
    return vt;
}
