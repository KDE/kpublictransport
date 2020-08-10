/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_RENTALVEHICLE_H
#define KPUBLICTRANSPORT_RENTALVEHICLE_H

#include "datatypes.h"

namespace KPublicTransport {

class RentalVehicleNetworkPrivate;

/** A vehicle sharing system/network.
 *  Typically one operator/area, needing an account/app for that operator to rent vehicles.
 *
 *  @see https://github.com/NABSA/gbfs/blob/master/gbfs.md#system_informationjson
 */
class KPUBLICTRANSPORT_EXPORT RentalVehicleNetwork
{
    KPUBLICTRANSPORT_GADGET(RentalVehicleNetwork)
    /** Human-visible name of this network. */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)

    /** Not an empty/default constructed object. */
    Q_PROPERTY(bool isValid READ isValid)

public:
    bool isValid() const;

    /** Checks if two instances refer to the same network. */
    static bool isSame(const RentalVehicleNetwork &lhs, const RentalVehicleNetwork &rhs);

    /** Serializes one object to JSON. */
    static QJsonObject toJson(const RentalVehicleNetwork &network);
    /** Deserialize an object from JSON. */
    static RentalVehicleNetwork fromJson(const QJsonObject &obj);
};

class RentalVehicleStationPrivate;

/** Additional information for a vehicle renting station, attached to Location objects.
 *  This is typically needed for dock-based bike sharing systems.
 *
 *  @see https://github.com/NABSA/gbfs/blob/master/gbfs.md#station_informationjson
 *  @see https://github.com/NABSA/gbfs/blob/master/gbfs.md#station_statusjson
 */
class KPUBLICTRANSPORT_EXPORT RentalVehicleStation
{
    KPUBLICTRANSPORT_GADGET(RentalVehicleStation)
    /** Number of available (rentable) vehicles at this station. */
    KPUBLICTRANSPORT_PROPERTY(int, availableVehicles, setAvailableVehicles)
    /** Number of dock positions at this station.
     *  If capacity == availableVehicles no vehicles can be returned at this station.
     */
    KPUBLICTRANSPORT_PROPERTY(int, capacity, setCapacity)

    /** Sharing network operator. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::RentalVehicleNetwork, network, setNetwork)

    /** Not an empty/default constructed object. */
    Q_PROPERTY(bool isValid READ isValid)

public:
    bool isValid() const;

    /** Checks if two instances refer to the same station. */
    static bool isSame(const RentalVehicleStation &lhs, const RentalVehicleStation &rhs);

    /** Serializes one object to JSON. */
    static QJsonObject toJson(const RentalVehicleStation &station);
    /** Deserialize an object from JSON. */
    static RentalVehicleStation fromJson(const QJsonObject &obj);
};

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
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::RentalVehicleNetwork, network, setNetwork)

public:
    /** Serializes one object to JSON. */
    static QJsonObject toJson(const RentalVehicle &vehicle);
    /** Deserialize an object from JSON. */
    static RentalVehicle fromJson(const QJsonObject &obj);
};

}

Q_DECLARE_METATYPE(KPublicTransport::RentalVehicleNetwork)
Q_DECLARE_METATYPE(KPublicTransport::RentalVehicleStation)
Q_DECLARE_METATYPE(KPublicTransport::RentalVehicle)

#endif // KPUBLICTRANSPORT_RENTALVEHICLE_H
