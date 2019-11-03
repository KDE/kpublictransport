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

#ifndef KPUBLICTRANSPORT_LOCATIONREQUEST_H
#define KPUBLICTRANSPORT_LOCATIONREQUEST_H

#include "kpublictransport_export.h"

#include <QMetaType>
#include <QSharedDataPointer>

class QJsonObject;

namespace KPublicTransport {

class LocationRequestPrivate;

/** Describes a location search.
 *  Either a geo coordinate or a name must be specified as search criteria.
 */
class KPUBLICTRANSPORT_EXPORT LocationRequest
{
    Q_GADGET
    Q_PROPERTY(float latitude READ latitude WRITE setLatitude)
    Q_PROPERTY(float longitude READ longitude WRITE setLongitude)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QStringList backends READ backendIds WRITE setBackendIds)

public:
    LocationRequest();
    LocationRequest(LocationRequest&&) noexcept;
    LocationRequest(const LocationRequest&);
    ~LocationRequest();
    LocationRequest& operator=(const LocationRequest&);

    /** Returns @c true if this is a default-constructed object without any request parameters. */
    bool isEmpty() const;

    /** Latitude of the location to search. */
    float latitude() const;
    /** Sets the latitude of the location to search. */
    void setLatitude(float lat);
    /** Longitude of the location to search. */
    float longitude() const;
    /** Sets the longitude of the location to search. */
    void setLongitude(float lon);
    /** Search by geo coordinate. */
    void setCoordinate(float lat, float lon);
    /** Returns true if a valid geo coordinate has been set. */
    bool hasCoordinate() const;

    /** The name of the location to search. */
    QString name() const;
    /** Search by name or name fragment. */
    void setName(const QString &name);
    // TODO select full name or name fragment mode for auto-completion

    /** Unique string representation used for caching results. */
    QString cacheKey() const;

    /** Identifiers of the backends that should be queried.
     *  @see setBackendIds()
     */
    QStringList backendIds() const;
    /** Set identifiers of backends that should be queried.
     *  Settings this is only needed when you want explicit control over this, leaving
     *  this empty picks suitable backends automatically.
     */
    void setBackendIds(const QStringList &backendIds);

    ///@cond internal
    static QJsonObject toJson(const LocationRequest &req);
    ///@endcond
private:
    QExplicitlySharedDataPointer<LocationRequestPrivate> d;
};

}

Q_DECLARE_METATYPE(KPublicTransport::LocationRequest)

#endif // KPUBLICTRANSPORT_LOCATIONREQUEST_H
