/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_RENTALVEHICLE_H
#define KPUBLICTRANSPORT_RENTALVEHICLE_H

#include "datatypes.h"

namespace KPublicTransport {

class RentalVehiclePrivate;

/** An individual rental vehicle used on a JourneySection, ie. a vehicle you don't own yourself but have to drive yourself.
 *  This can be:
 *  - free floating or dock-based rental bikes
 *  - car sharing (but not ride sharing)
 *  - electric scooters
 */
class KPUBLICTRANSPORT_EXPORT RentalVehicle
{
    KPUBLICTRANSPORT_GADGET(RentalVehicle)
public:
    /** Type of vehicle. */
    enum VehicleType {
        Unknown,
        Bicycle,
        ElectricScooter,
        Car,
    };
    Q_ENUM(VehicleType)

    /** Vehicle type. */
    KPUBLICTRANSPORT_PROPERTY(VehicleType, type, setType)

    /** Sharing network operator. */
    KPUBLICTRANSPORT_PROPERTY(QString, network, setNetwork)

public:
    /** Serializes one object to JSON. */
    static QJsonObject toJson(const RentalVehicle &vehicle);
    /** Deserialize an object from JSON. */
    static RentalVehicle fromJson(const QJsonObject &obj);
};

}

Q_DECLARE_METATYPE(KPublicTransport::RentalVehicle)

#endif // KPUBLICTRANSPORT_RENTALVEHICLE_H
