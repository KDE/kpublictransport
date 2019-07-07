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

#ifndef KPUBLICTRANSPORT_ABSTRACTBACKEND_H
#define KPUBLICTRANSPORT_ABSTRACTBACKEND_H

#include "reply.h"

#include <QFlags>
#include <QPolygonF>

class QNetworkAccessManager;

namespace KPublicTransport {

class DepartureReply;
class DepartureRequest;
class JourneyReply;
class JourneyRequest;
class Location;
class LocationReply;
class LocationRequest;

/** Abstract base class for transport provider backends. */
class AbstractBackend
{
    Q_GADGET
public:
    AbstractBackend();
    virtual ~AbstractBackend();

    /** Identifier for this backend.
     *  Use e.g. for distinguishing backend-specific cache locations etc.
     */
    QString backendId() const;
    void setBackendId(const QString &id);

    /** Checks if this location has been filtered by the network configuration. */
    bool isLocationExcluded(const Location &loc) const;
    /** Same as the above but just checking one specific geo coordinate. */
    bool isCoordinateExcluded(float lat, float lon) const;
    void setGeoFilter(const QPolygonF &poly);

    /** Called after all settings have been set on this backend. */
    virtual void init();

    enum Capability {
        NoCapability = 0,
        Secure = 1, ///< uses transport encryption
        CanQueryNextJourney = 2, ///< supports querying for later journeys
        CanQueryPreviousJourney = 4, ///< supports query for earlier journeys
    };
    Q_DECLARE_FLAGS(Capabilities, Capability)

    /** Returns the capabilities of this backend. */
    virtual Capabilities capabilities() const;
    /** Checks if this backend has @p capability. */
    inline bool hasCapability(Capability capability) const { return capabilities() & capability; };

    /** Type of query.
     *  @see needsLocationQuery
     */
    enum class QueryType {
        Departure,
        Journey
    };
    /** Returns whether or not a location query has to be performed for the given
     *  Location before doing departure or journey queries for it.
     */
    virtual bool needsLocationQuery(const Location &loc, QueryType type) const;

    /** Perform a journey query.
     *  @return @c true if performing an async operation, @c false otherwise.
     */
    virtual bool queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const;

    /** Perform a departure query.
     *  @return @c true if performing an async operation, @c false otherwise.
     */
    virtual bool queryDeparture(const DepartureRequest &request, DepartureReply *reply, QNetworkAccessManager *nam) const;

    /** Perform a location query.
     *  @return @c true if performing an async operation, @c false otherwise.
     */
    virtual bool queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const;

protected:
    /** Helper function to call non-public Reply API. */
    template <typename T, typename ...Args> inline static void addResult(T *reply, Args&&... args)
    {
        reply->addResult(std::forward<Args>(args)...);
    }

    inline static void addError(Reply *reply, Reply::Error error, const QString &errorMsg)
    {
        reply->addError(error, errorMsg);
    }

    QVariant journeyContext(const JourneyRequest &request) const;
    void setNextJourneyContext(JourneyReply *reply, const QVariant &data) const;
    void setPreviousJourneyContext(JourneyReply *reply, const QVariant &data) const;

private:
    Q_DISABLE_COPY(AbstractBackend)
    QString m_backendId;
    QPolygonF m_geoFilter;
};

}

Q_DECLARE_OPERATORS_FOR_FLAGS(KPublicTransport::AbstractBackend::Capabilities)

#endif // KPUBLICTRANSPORT_ABSTRACTBACKEND_H
