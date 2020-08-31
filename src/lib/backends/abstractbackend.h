/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_ABSTRACTBACKEND_H
#define KPUBLICTRANSPORT_ABSTRACTBACKEND_H

#include "reply.h"
#include "requestcontext_p.h"

#include <KPublicTransport/Attribution>

#include <QFlags>
#include <QJsonObject>
#include <QPolygonF>
#include <QTimeZone>
#include <QVariant>

class QNetworkAccessManager;
class QNetworkReply;
class QNetworkRequest;

namespace KPublicTransport {

class JourneyReply;
class JourneyRequest;
class Location;
class LocationReply;
class LocationRequest;
class StopoverReply;
class StopoverRequest;
class VehicleLayoutReply;
class VehicleLayoutRequest;

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
    void setGeoFilter(const QPolygonF &poly);

    /** Static timezone for all times used by and provided by the backend.
     *  Set to invalid if the backend supports multiple timezones.
     */
    QTimeZone timeZone() const;
    void setTimeZone(const QTimeZone &tz);

    /** Supported languages.
     *  This matters for backends that require us to ask for humand readable strings
     *  in a specific language (as opposed to providing all possible translations by default).
     *  The first language in QLocale::uiLanguages found in this list should be requested.
     *  @see preferredLanguage()
     */
    QStringList supportedLanguages() const;
    void setSupportedLanguages(const QStringList &langs);

    /** Returns the language that should be requested.
     *  This is essentially the first language in QLocale::uiLanguages that is also found
     *  in the list of supported languages, if that's not the case the first supported
     *  language of the backend, or if that's not set, English by default.
     */
    QString preferredLanguage() const;

    /** Called after all settings have been set on this backend. */
    virtual void init();

    enum Capability {
        NoCapability = 0,
        Secure = 1, ///< uses transport encryption
        CanQueryNextJourney = 2, ///< supports querying for later journeys
        CanQueryPreviousJourney = 4, ///< supports query for earlier journeys
        CanQueryNextDeparture = 8, ///< supports querying for later departures
        CanQueryPreviousDeparture = 16, ///< supports query for earlier departures
        CanQueryArrivals = 32, ///< supports querying arrival stopovers at a given location
    };
    Q_DECLARE_FLAGS(Capabilities, Capability)

    /** Returns the capabilities of this backend. */
    virtual Capabilities capabilities() const;
    /** Checks if this backend has @p capability. */
    inline bool hasCapability(Capability capability) const { return capabilities() & capability; };

    /** Returns the static attribution information for this backend. */
    Attribution attribution() const;
    /** Sets the static attribution information for this backend. */
    void setAttribution(const Attribution &attr);

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
    virtual bool queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const;

    /** Perform a location query.
     *  @return @c true if performing an async operation, @c false otherwise.
     */
    virtual bool queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const;

    /** Perform a vehicle layout query.
     *  @return @c true if performing an async operation, @c false otherwise.
     */
    virtual bool queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const;

protected:
    /** Helper function to call non-public Reply API. */
    template <typename T, typename ...Args> inline static void addResult(T *reply, Args&&... args)
    {
        reply->addResult(std::forward<Args>(args)...);
    }

    template <typename T> inline void addError(T *reply, Reply::Error error, const QString &errorMsg) const
    {
        reply->addError(this, error, errorMsg);
    }

    static void addAttributions(Reply *reply, std::vector<Attribution> &&attributions);

    template <typename ReqT> inline QVariant requestContext(const ReqT &request) const
    {
        return request.context(this).backendData;
    }

    template <typename RepT> inline void setNextRequestContext(RepT *reply, const QVariant &data) const
    {
        reply->setNextContext(this, data);
    }
    template <typename RepT> inline void setPreviousRequestContext(RepT *reply, const QVariant &data) const
    {
        reply->setPreviousContext(this, data);
    }

    /** Check if network logging is enabled.
     *  Done automatically in logRequest/logReply, but can be useful for backends if producing
     *  the necessary input is expensive.
     */
    bool isLoggingEnabled() const;

    template <typename ReqT>
    void logRequest(const ReqT &request, const QNetworkRequest &netRequest, const QByteArray &postData = {}) const
    {
        if (!isLoggingEnabled()) {
            return;
        }

        logRequest(ReqT::staticMetaObject.className() + 18, ReqT::toJson(request), netRequest, postData);
    }

    template <typename RepT>
    void logReply(RepT *reply, QNetworkReply *netReply, const QByteArray &data) const
    {
        if (!isLoggingEnabled()) {
            return;
        }

        logReply(reply->metaObject()->className() + 18, netReply, data);
    }

private:
    Q_DISABLE_COPY(AbstractBackend)
    QString logDir() const;
    void logRequest(const char *typeName, const QJsonObject &requestData, const QNetworkRequest &netRequest, const QByteArray &postData) const;
    void logReply(const char *typeName, QNetworkReply *netReply, const QByteArray &data) const;

    QString m_backendId;
    QPolygonF m_geoFilter;
    Attribution m_attribution;
    QTimeZone m_timeZone;
    QStringList m_supportedLanguages;
};

}

Q_DECLARE_OPERATORS_FOR_FLAGS(KPublicTransport::AbstractBackend::Capabilities)

#endif // KPUBLICTRANSPORT_ABSTRACTBACKEND_H
