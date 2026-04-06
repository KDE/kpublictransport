/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFSVEHICLETYPES_H
#define KPUBLICTRANSPORT_GBFSVEHICLETYPES_H

#include "gbfsvehicletype.h"

#include <KPublicTransport/RentalVehicle>

#include <QString>

#include <vector>

class QJsonObject;

namespace KPublicTransport {

class GBFSService;
/** GBFS v2.1 vehicle types data parsing. */
class GBFSVehicleTypes
{
public:
    explicit GBFSVehicleTypes(const GBFSService &feed);
    ~GBFSVehicleTypes();

    [[nodiscard]] RentalVehicleType vehicleType(QStringView typeId) const;

private:
    std::vector<RentalVehicleType> m_vehicleTypes;
};

}

#endif // KPUBLICTRANSPORT_GBFSVEHICLETYPES_H
