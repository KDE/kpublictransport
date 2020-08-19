/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef KPUBLICTRANSPORT_LOCATION_H
#define KPUBLICTRANSPORT_LOCATION_H

#include "datatypes.h"
#include "rentalvehicle.h"

class QJsonArray;
class QJsonObject;
class QJsonValue;
class QTimeZone;
template <typename K, typename T> class QHash;

namespace KPublicTransport {

class LocationPrivate;

/** A location. */
class KPUBLICTRANSPORT_EXPORT Location
{
    KPUBLICTRANSPORT_GADGET(Location)
public:
    /** Type of location. */
    enum Type {
        Place = 0, ///< a location that isn't of any specific type
        Stop = 1, ///< a public transport stop (train station, bus stop, etc)
        RentedVehicleStation = 2, ///< a pick-up/drop-off point for dock-based rental bike/scooter systems
    };
    Q_ENUM(Type)
    Q_DECLARE_FLAGS(Types, Type)
    Q_FLAG(Types)

    /** Location type. */
    KPUBLICTRANSPORT_PROPERTY(Type, type, setType)

    /** Human-readable name of the location. */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)
    /** Latitude of the location, in degree, NaN if unknown. */
    KPUBLICTRANSPORT_PROPERTY(float, latitude, setLatitude)
    /** Longitude of the location, in degree, NaN if unknown. */
    KPUBLICTRANSPORT_PROPERTY(float, longitude, setLongitude)

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

    /** Rental vehicle dock information, if applicable for this location. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::RentalVehicleStation, rentalVehicleStation, setRentalVehicleStation)

public:
    void setCoordinate(float latitude, float longitude);
    bool hasCoordinate() const;

    /** Returns @c true if this is an default-constructed location object not specifying any location. */
    bool isEmpty() const;

    /** The timezone this location is in, if known. */
    QTimeZone timeZone() const;
    void setTimeZone(const QTimeZone &tz);

    /** Location identifiers. */
    QString identifier(const QString &identifierType) const;
    void setIdentifier(const QString &identifierType, const QString &id);
    QHash<QString, QString> identifiers() const;

    /** Checks if to instances refer to the same location (which does not necessarily mean they are exactly equal). */
    static bool isSame(const Location &lhs, const Location &rhs);
    /** Checks if two location names refer to the same location. */
    static bool isSameName(const QString &lhs, const QString &rhs);

    /** Merge two departure instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    static Location merge(const Location &lhs, const Location &rhs);

    /** Compute the distance between two geo coordinates, in meters. */
    static int distance(float lat1, float lon1, float lat2, float lon2);
    /** Computes the distance in meters between two locations.
     *  Returns MAX_INT if one of the arguments has no coordinates set.
     */
    static int distance(const Location &lhs, const Location &rhs);

    /** Serializes one Location object to JSON. */
    static QJsonObject toJson(const Location &loc);
    /** Serializes an array of Location objects to JSON. */
    static QJsonArray toJson(const std::vector<Location> &locs);
    /** Deserialize a Location object from JSON. */
    static Location fromJson(const QJsonObject &obj);
    /** Dezerializes an array Location objects from JSON. */
    static std::vector<Location> fromJson(const QJsonArray &a);

};

}

Q_DECLARE_OPERATORS_FOR_FLAGS(KPublicTransport::Location::Types)
Q_DECLARE_METATYPE(KPublicTransport::Location)

#endif // KPUBLICTRANSPORT_LOCATION_H
