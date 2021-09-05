/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_RENTALVEHICLE_H
#define KPUBLICTRANSPORT_RENTALVEHICLE_H

#include "datatypes.h"

namespace KPublicTransport {

class RentalVehicleNetwork;
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
        Unknown = 0,
        Bicycle = 1, ///< human-powered bicylce
        Pedelec = 2, ///< bicycle with electric assistance
        ElectricKickScooter = 4, ///< "e scooter", electrically assisted kick scooters, not to be confused with motorcycle-like scooters
        ElectricScooter [[deprecated("use ElectricKickScooter")]] = ElectricKickScooter,
        ElectricMoped = 8, ///< motorcycle-like electric scooters
        Car = 16, ///< electrical- or combustion-powered car
    };
    Q_ENUM(VehicleType)
    Q_DECLARE_FLAGS(VehicleTypes, VehicleType)
    Q_FLAG(VehicleTypes)

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

Q_DECLARE_OPERATORS_FOR_FLAGS(RentalVehicle::VehicleTypes)

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

    /** Supported vehicle types at this station. */
    Q_PROPERTY(KPublicTransport::RentalVehicle::VehicleTypes supportedVehicleTypes READ supportedVehicleTypes STORED false)
    /** Available vehicle types at this station. */
    Q_PROPERTY(KPublicTransport::RentalVehicle::VehicleTypes availableVehicleTypes READ availableVehicleTypes STORED false)

public:
    bool isValid() const;
    RentalVehicle::VehicleTypes supportedVehicleTypes() const;
    RentalVehicle::VehicleTypes availableVehicleTypes() const;

    /** Capacity for a given vehicle type. */
    Q_INVOKABLE int capacity(KPublicTransport::RentalVehicle::VehicleType type) const;
    /** Set the capacity for a specific vehicle type. */
    void setCapacity(RentalVehicle::VehicleType type, int capacity);

    /** Available vehicles for a given vehicle type. */
    Q_INVOKABLE int availableVehicles(KPublicTransport::RentalVehicle::VehicleType type) const;
    /** Sets the number of available vehicles for a given vehicle type. */
    void setAvailableVehicles(RentalVehicle::VehicleType type, int count);

    /** Checks if two instances refer to the same station. */
    static bool isSame(const RentalVehicleStation &lhs, const RentalVehicleStation &rhs);

    /** Serializes one object to JSON. */
    static QJsonObject toJson(const RentalVehicleStation &station);
    /** Deserialize an object from JSON. */
    static RentalVehicleStation fromJson(const QJsonObject &obj);
};

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
    /** Supported vehicle types by this network. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::RentalVehicle::VehicleTypes, vehicleTypes, setVehicleTypes)

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
}

Q_DECLARE_METATYPE(KPublicTransport::RentalVehicleNetwork)
Q_DECLARE_METATYPE(KPublicTransport::RentalVehicleStation)
Q_DECLARE_METATYPE(KPublicTransport::RentalVehicle)

#endif // KPUBLICTRANSPORT_RENTALVEHICLE_H
