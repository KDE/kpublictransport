/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LOCATION_H
#define KPUBLICTRANSPORT_LOCATION_H

#include "datatypes.h"
#include <QVariant>

class QJsonArray;
class QJsonObject;
class QTimeZone;
template <typename K, typename T> class QHash;

namespace KPublicTransport {

class LocationPrivate;
class Equipment;
class RentalVehicle;
class RentalVehicleStation;
class StopInformation;

/** A location.
 *  This can be a train station, a bus stop, a rental vehicle dock, a free-floating vehicle position,
 *  an elevator or escalator, etc.
 */
class KPUBLICTRANSPORT_EXPORT Location
{
    KPUBLICTRANSPORT_GADGET(Location)

public:
    /** Type of location. */
    enum Type {
        Place = 0, ///< a location that isn't of any specific type
        Stop = 1, ///< a public transport stop (train station, bus stop, etc)
        RentedVehicleStation = 2, ///< a pick-up/drop-off point for dock-based rental bike/scooter systems
        RentedVehicle = 4, ///< a free-floating rental bike/scooter
        Equipment = 8, ///< elevator/escalator
        CarpoolPickupDropoff = 16, ///< a pickup or dropoff location for a carpool trip
        Address = 32 ///< postal addresses
    };
    Q_ENUM(Type)
    Q_DECLARE_FLAGS(Types, Type)
    Q_FLAG(Types)

    /** Location type. */
    KPUBLICTRANSPORT_PROPERTY(Type, type, setType)

    /** Human-readable name of the location. */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)
    /** Latitude of the location, in degree, NaN if unknown. */
    KPUBLICTRANSPORT_PROPERTY(double, latitude, setLatitude)
    /** Longitude of the location, in degree, NaN if unknown. */
    KPUBLICTRANSPORT_PROPERTY(double, longitude, setLongitude)

    /** Street address of the location, if known. */
    KPUBLICTRANSPORT_PROPERTY(QString, streetAddress, setStreetAddress)
    /** Postal code of the location, if known. */
    KPUBLICTRANSPORT_PROPERTY(QString, postalCode, setPostalCode)
    /** Locality/city of the location, if known. */
    KPUBLICTRANSPORT_PROPERTY(QString, locality, setLocality)
    /** Region (as in ISO 3166-2) of the location, if known. */
    KPUBLICTRANSPORT_PROPERTY(QString, region, setRegion)
    /** Country of the location as ISO 3166-1 alpha 2 code, if known. */
    KPUBLICTRANSPORT_PROPERTY(QString, country, setCountry)

    Q_PROPERTY(bool hasCoordinate READ hasCoordinate STORED false)

    /** OSM floor level of this location.
     *  Not set by default.
     */
    KPUBLICTRANSPORT_PROPERTY(int, floorLevel, setFloorLevel)
    /** Indicates whether the floor level is set. */
    Q_PROPERTY(bool hasFloorLevel READ hasFloorLevel STORED false)

    /** Location type specific data.
     *  Depending on the location type this can be e.g. a RentalVehicleStation or an Equipment instance.
     */
    KPUBLICTRANSPORT_PROPERTY(QVariant, data, setData)

    /** Stop information, if applicable for this location. */
    Q_PROPERTY(KPublicTransport::StopInformation stopInformation READ stopInformation STORED false)
    /** Rental vehicle dock information, if applicable for this location. */
    Q_PROPERTY(KPublicTransport::RentalVehicleStation rentalVehicleStation READ rentalVehicleStation STORED false)
    /** Rental vehicle information, if applicable for this location. */
    Q_PROPERTY(KPublicTransport::RentalVehicle rentalVehicle READ rentalVehicle STORED false)
    /** Equipment information, if applicable for this location. */
    Q_PROPERTY(KPublicTransport::Equipment equipment READ equipment STORED false)

    /** Icon representing the location type.
     *  Can be a qrc: URL or an XDG icon name.
     */
    Q_PROPERTY(QString iconName READ iconName STORED false)

    /** Identifier types set on this location. */
    Q_PROPERTY(QStringList identifierTypes READ identifierTypes STORED false)

public:
    void setCoordinate(double latitude, double longitude);
    [[nodiscard]] bool hasCoordinate() const;
    [[nodiscard]] bool hasFloorLevel() const;

    /** Returns @c true if this is an default-constructed location object not specifying any location. */
    [[nodiscard]] bool isEmpty() const;

    /** The timezone this location is in, if known. */
    [[nodiscard]] QTimeZone timeZone() const;
    void setTimeZone(const QTimeZone &tz);

    /** Location identifiers. */
    [[nodiscard]] QString identifier(QAnyStringView identifierType) const;
    Q_INVOKABLE [[nodiscard]] QString identifier(const QString &identifierType) const { return identifier(QAnyStringView(identifierType)); }
    [[nodiscard]] QString identifier(QLatin1StringView identifierType) const { return identifier(QAnyStringView(identifierType)); }
    void setIdentifier(const QString &identifierType, const QString &id);
    [[nodiscard]] bool hasIdentifier(QAnyStringView identifierType) const;
    [[nodiscard]] QStringList identifierTypes() const;

    /** Checks if to instances refer to the same location (which does not necessarily mean they are exactly equal). */
    [[nodiscard]] static bool isSame(const Location &lhs, const Location &rhs);
    /** Checks if two location names refer to the same location. */
    [[nodiscard]] static bool isSameName(const QString &lhs, const QString &rhs);

    /** Merge two departure instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    [[nodiscard]] static Location merge(const Location &lhs, const Location &rhs);

    /** Compute the distance between two geo coordinates, in meters. */
    [[nodiscard]] static double distance(double lat1, double lon1, double lat2, double lon2);
    /** Computes the distance in meters between two locations.
     *  Returns NAN if one of the arguments has no coordinates set.
     */
    [[nodiscard]] static double distance(const Location &lhs, const Location &rhs);

    [[nodiscard]] StopInformation stopInformation() const;
    [[nodiscard]] RentalVehicleStation rentalVehicleStation() const;
    [[nodiscard]] RentalVehicle rentalVehicle() const;
    [[nodiscard]] KPublicTransport::Equipment equipment() const;

    [[nodiscard]] QString iconName() const;

    /** Serializes one Location object to JSON. */
    [[nodiscard]] static QJsonObject toJson(const Location &loc);
    /** Serializes an array of Location objects to JSON. */
    [[nodiscard]] static QJsonArray toJson(const std::vector<Location> &locs);
    /** Deserialize a Location object from JSON. */
    [[nodiscard]] static Location fromJson(const QJsonObject &obj);
    /** Dezerializes an array Location objects from JSON. */
    [[nodiscard]] static std::vector<Location> fromJson(const QJsonArray &a);

};

Q_DECLARE_OPERATORS_FOR_FLAGS(Location::Types)

}

Q_DECLARE_METATYPE(KPublicTransport::Location)

#endif // KPUBLICTRANSPORT_LOCATION_H
