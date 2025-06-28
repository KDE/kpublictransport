/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LOCATIONREQUEST_H
#define KPUBLICTRANSPORT_LOCATIONREQUEST_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Datatypes>
#include <KPublicTransport/Location>

#include <QMetaType>
#include <QSharedDataPointer>

class QJsonObject;

namespace KPublicTransport {

class LocationRequestPrivate;

/** Describes a location search.
 *  Either a geo coordinate, a name or an address must be specified as search criteria.
 */
class KPUBLICTRANSPORT_EXPORT LocationRequest
{
    KPUBLICTRANSPORT_GADGET(LocationRequest)
    /** Location object containing the search parameters. */
    Q_PROPERTY(KPublicTransport::Location location READ location WRITE setLocation)
    // TODO deprecated those?
    Q_PROPERTY(double latitude READ latitude WRITE setLatitude STORED false)
    Q_PROPERTY(double longitude READ longitude WRITE setLongitude STORED false)
    Q_PROPERTY(QString name READ name WRITE setName STORED false)
    Q_PROPERTY(QStringList backends READ backendIds WRITE setBackendIds)

    /** When searching by coordinate, the expected maximum distance of the results in meters.
     *  @note This is only an optimization hint for backends, not a guarantee
     *  that all results comply with this constraint.
     */
    KPUBLICTRANSPORT_PROPERTY(int, maximumDistance, setMaximumDistance)
    /** The maximum amount of expected results.
     *  @note This is only an optimization hint for backends, not a guarantee
     *  that all results comply with this constraint.
     */
    KPUBLICTRANSPORT_PROPERTY(int, maximumResults, setMaximumResults)
    /** The type of locations you are interested in.
     *  @note This is only an optimization hint for backends, not a guarantee
     *  that all results comply with this constraint.
     */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Location::Types, types, setTypes)

public:
    /** Create a LocationRequest from @p locaction.
     *  Whatever fields set in @p location will be used for the search request.
     */
    LocationRequest(const Location &locaction);

    /** Returns @c true if this is a valid request, that is it has enough parameters set to perform a query. */
    [[nodiscard]] bool isValid() const;

    [[nodiscard]] Location location() const;
    void setLocation(const Location &location);

    /** Latitude of the location to search. */
    [[nodiscard]] double latitude() const;
    /** Sets the latitude of the location to search. */
    void setLatitude(double lat);
    /** Longitude of the location to search. */
    [[nodiscard]] double longitude() const;
    /** Sets the longitude of the location to search. */
    void setLongitude(double lon);
    /** Search by geo coordinate. */
    void setCoordinate(double lat, double lon);
    /** Returns true if a valid geo coordinate has been set. */
    [[nodiscard]] bool hasCoordinate() const;

    /** The name of the location to search. */
    [[nodiscard]] QString name() const;
    /** Search by name or name fragment. */
    void setName(const QString &name);
    // TODO select full name or name fragment mode for auto-completion

    /** Unique string representation used for caching results. */
    [[nodiscard]] QString cacheKey() const;

    /** Identifiers of the backends that should be queried.
     *  @see setBackendIds()
     */
    [[nodiscard]] QStringList backendIds() const;
    /** Set identifiers of backends that should be queried.
     *  Settings this is only needed when you want explicit control over this, leaving
     *  this empty picks suitable backends automatically.
     */
    void setBackendIds(const QStringList &backendIds);

    ///@cond internal
    static QJsonObject toJson(const LocationRequest &req);
    ///@endcond
};

}

Q_DECLARE_METATYPE(KPublicTransport::LocationRequest)

#endif // KPUBLICTRANSPORT_LOCATIONREQUEST_H
