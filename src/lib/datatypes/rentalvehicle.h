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
 *  - free floating or dock-based rental bikes, with or without electric assistance
 *  - car sharing (but not ride sharing)
 *  - electric (kick) scooters
 *  - electric motorcycles (scooters)
 *
 *  @see GBFS: https://github.com/NABSA/gbfs/blob/v2.1-RC/gbfs.md#vehicle_typesjson-added-in-v21-rc
 *  @see MDS: https://github.com/openmobilityfoundation/mobility-data-specification/blob/master/provider/README.md#vehicle-types
 */
class KPUBLICTRANSPORT_EXPORT RentalVehicle
{
    KPUBLICTRANSPORT_GADGET(RentalVehicle)
public:
    /** Type of vehicle. */
    enum VehicleType {
        Unknown,
        Bicycle, ///< human-powered bicylce
        Pedelec, ///< bicycle with electric assistance
        ElectricKickScooter, ///< "e scooter", electrically assisted kick scooters, not to be confused with motorcycle-like scooters
        ElectricScooter [[deprecated("use ElectricKickScooter")]] = ElectricKickScooter,
        ElectricMoped, ///< motorcycle-like electric scooters
        Car, ///< electrical- or combustion-powered car
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
