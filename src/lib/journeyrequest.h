/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_JOURNEYREQUEST_H
#define KPUBLICTRANSPORT_JOURNEYREQUEST_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Datatypes>
#include <KPublicTransport/Journey>

#include <QMetaType>
#include <QSharedDataPointer>

#include <vector>

class QDateTime;

namespace KPublicTransport {

class AbstractBackend;
class JourneyReply;
class JourneyRequestPrivate;
class Location;
class Manager;
class RequestContext;

/** Describes a journey search.
 *  By default journeys departing now are searched.
 */
class KPUBLICTRANSPORT_EXPORT JourneyRequest
{
    KPUBLICTRANSPORT_GADGET(JourneyRequest)

    /** The starting point of the journey search. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Location, from, setFrom)
    /** The journey destination. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Location, to, setTo)
    /** Date/time at which the journey should start/end. */
    KPUBLICTRANSPORT_PROPERTY(QDateTime, dateTime, setDateTime)

    /** Modes of transportation that should be considered for this query.
     *  Only transit modes matter (public transport, rented vehicles, etc),
     *  values for tranfers/waits/etc are ignored.
     */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::JourneySection::Modes, modes, setModes)
    /** The maximum amount of expected results.
     *  @note This is only an optimization hint for backends, not a guarantee
     *  that all results comply with this constraint.
     */
    KPUBLICTRANSPORT_PROPERTY(int, maximumResults, setMaximumResults)
    /** Retrieve intermediate stops for the queried journeys as well.
     *  @note This is only an optimization hint for backends, not a guarantee
     *  that all results will contain this information.
     */
    KPUBLICTRANSPORT_PROPERTY(bool, includeIntermediateStops, setIncludeIntermediateStops)

public:
    enum DateTimeMode {
        Arrival, ///< dateTime() represents the desired arriva time.
        Departure ///< dateTime() represents the desired departure time.
    };
    Q_ENUM(DateTimeMode)
    /** Controls whether to search for journeys starting or ending at the given time. */
    KPUBLICTRANSPORT_PROPERTY(DateTimeMode, dateTimeMode, setDateTimeMode)

    Q_PROPERTY(QStringList backends READ backendIds WRITE setBackendIds)

    /** Download graphic assets such as line logos for the data requested here.
     *  Default: @c false
     */
    KPUBLICTRANSPORT_PROPERTY(bool, downloadAssets, setDownloadAssets)

public:
    /** Search a journey from @p from to @p to. */
    JourneyRequest(const Location &from, const Location &to);

    /** Returns @c true if this is a valid request, that is, it has enough parameters set to perform a query. */
    bool isValid() const;

    /** Set the desired departure time.
     *  This is mutually exclusive to setting a desired arrival time.
     */
    void setDepartureTime(const QDateTime &dt);
    /** Sets the desired arrival time.
     *  This is mutually exclusive to setting a desired departure time.
     */
    void setArrivalTime(const QDateTime &dt);

    /** Identifiers of the backends that should be queried.
     *  @see setBackendIds()
     */
    QStringList backendIds() const;
    /** Set identifiers of backends that should be queried.
     *  Settings this is only needed when you want explicit control over this, leaving
     *  this empty picks suitable backends automatically.
     */
    void setBackendIds(const QStringList &backendIds);

    /** Unique string representation used for caching results. */
    QString cacheKey() const;

    ///@cond internal
    static QJsonObject toJson(const JourneyRequest &req);
    ///@endcond
private:
    friend class AbstractBackend;
    friend class JourneyReply;
    friend class JourneyReplyPrivate;
    friend class Manager;
    Q_DECL_HIDDEN RequestContext context(const AbstractBackend *backend) const;
    Q_DECL_HIDDEN const std::vector<RequestContext>& contexts() const;
    Q_DECL_HIDDEN void setContext(const AbstractBackend *backend, RequestContext &&context);
    Q_DECL_HIDDEN void purgeLoops(const JourneyRequest &baseRequest);
};

}

Q_DECLARE_METATYPE(KPublicTransport::JourneyRequest)

#endif // KPUBLICTRANSPORT_JOURNEYREQUEST_H
