/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFSVEHICLETYPE_H
#define KPUBLICTRANSPORT_GBFSVEHICLETYPE_H

#include <KPublicTransport/RentalVehicle>

#include <QString>

class QJsonObject;

namespace KPublicTransport {

namespace GBFSVehicleType {
    [[nodiscard]] RentalVehicleType::FormFactor toFormFactor(QStringView formFactor);
    [[nodiscard]] RentalVehicleType::PropulsionType toPropulsionType(QStringView propulsionType);
    [[nodiscard]] RentalVehicleType::ReturnConstraint toReturnConstraint(QStringView returnConstraint);

    [[nodiscard]] const char* toString(RentalVehicleType::FormFactor formFactor);
    [[nodiscard]] const char* toString(RentalVehicleType::PropulsionType propulsionType);
    [[nodiscard]] const char* toString(RentalVehicleType::ReturnConstraint returnConstraint);

    [[nodiscard]] RentalVehicleType fromGbfs(const QJsonObject &obj);
}

}

#endif
