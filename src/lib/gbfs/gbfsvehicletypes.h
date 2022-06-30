/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFSVEHICLETYPES_H
#define KPUBLICTRANSPORT_GBFSVEHICLETYPES_H

#include <QString>

#include <vector>

class QJsonObject;

namespace KPublicTransport {

class GBFSService;

/** GBFS v2.1 vehicle type entry. */
class GBFSVehicleType
{
public:
    QString typeId;
    QString name;
    enum FormFactor {
        UndefinedFormFactor,
        Bicycle,
        Car,
        Moped,
        Scooter,
        Other,
    };
    FormFactor formFactor = UndefinedFormFactor;
    enum PropulsionType {
        UndefinedPropulsion,
        Human,
        ElectricAssist,
        Electric,
        Combustion,
    };
    PropulsionType propulsionType = UndefinedPropulsion;

    static GBFSVehicleType fromJson(const QJsonObject &obj);
};

/** GBFS v2.1 vehicle types data parsing. */
class GBFSVehicleTypes
{
public:
    explicit GBFSVehicleTypes(const GBFSService &feed);
    ~GBFSVehicleTypes();

    GBFSVehicleType vehicleType(QStringView typeId) const;

private:
    std::vector<GBFSVehicleType> m_vehicleTypes;
};

}

#endif // KPUBLICTRANSPORT_GBFSVEHICLETYPES_H
