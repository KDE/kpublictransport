/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_JOURNEYREQUEST_H
#define KPUBLICTRANSPORT_JOURNEYREQUEST_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Datatypes>
#include <KPublicTransport/IndividualTransport>
#include <KPublicTransport/Journey>

#include <QMetaType>
#include <QSharedDataPointer>
#include <QVariant>

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
    /** Retrieve path details for the journeys.
     *  @note This is only an optimization hint for backends, not a guarantee
     *  that all results will contain this information.
     */
    KPUBLICTRANSPORT_PROPERTY(bool, includePaths, setIncludePaths)

    /** Access modes. */
    Q_PROPERTY(QVariantList accessModes READ accessModesVariant WRITE setAccessModesVariant)
    /** Egress modes. */
    Q_PROPERTY(QVariantList egressModes READ egressModesVariant WRITE setEgressModesVariant)

    /** Line modes. */
    Q_PROPERTY(QVariantList lineModes READ lineModesVariant WRITE setLineModesVariant)

    /** Individual transport modes for direct connections.
     *  Only considered when, modes contains JourneySection::IndividualTransport.
     */
    Q_PROPERTY(QVariantList individualTransportModes READ individualTransportModesVariant WRITE setIndividualTransportModesVariant)
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
    [[nodiscard]] bool isValid() const;

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
    [[nodiscard]] QStringList backendIds() const;
    /** Set identifiers of backends that should be queried.
     *  Settings this is only needed when you want explicit control over this, leaving
     *  this empty picks suitable backends automatically.
     */
    void setBackendIds(const QStringList &backendIds);

    /** Requested access modes.
     *  That is individual transport modes on the first (access) leg of the journey.
     *  Default: walking
     */
    [[nodiscard]] const std::vector<IndividualTransport>& accessModes() const;
    /** Sets the requested access modes. */
    void setAccessModes(std::vector<IndividualTransport> &&accessModes);

    /** Requested egress modes.
     *  That is, individual transport modes for the last (egress) leg of the journey.
     *  Default: walking
     */
    [[nodiscard]] const std::vector<IndividualTransport>& egressModes() const;
    /** Sets the requested egress modes. */
    void setEgressModes(std::vector<IndividualTransport> &&egressModes);

    /** Requested line modes.
     *  That is, the possible types of public transport lines to consider for public
     *  transports sections of the journey.
     *  Default: all
     */
    [[nodiscard]] const std::vector<Line::Mode>& lineModes() const;
    /** Sets the requested line modes.
     *  An empty list is considered as all modes being allowed.
     *  @note This relies on backends actually supporting this and is thus does not
     *  provide any guarantee that the results wont contain other modes as well.
     */
    void setLineModes(std::vector <Line::Mode> &&modes);

    /** Requested individual transport modes.
     *  Individual transport modes for direct journeys.
     */
    [[nodiscard]] const std::vector<IndividualTransport>& individualTransportModes() const;
    /** Sets individual transport modes considered for direct journeys. */
    void setIndividualTransportModes(std::vector<IndividualTransport> &&modes);

    /** Unique string representation used for caching results. */
    [[nodiscard]] QString cacheKey() const;

    ///@cond internal
    [[nodiscard]] static QJsonObject toJson(const JourneyRequest &req);
    ///@endcond
private:
    friend class AbstractBackend;
    friend class JourneyReply;
    friend class JourneyReplyPrivate;
    friend class Manager;
    friend class JourneyRequestTest;

    [[nodiscard]] Q_DECL_HIDDEN QVariantList accessModesVariant() const;
    Q_DECL_HIDDEN void setAccessModesVariant(const QVariantList &accessModesVariant);
    [[nodiscard]] Q_DECL_HIDDEN QVariantList egressModesVariant() const;
    Q_DECL_HIDDEN void setEgressModesVariant(const QVariantList &egressModesVariant);
    [[nodiscard]] Q_DECL_HIDDEN QVariantList lineModesVariant() const;
    Q_DECL_HIDDEN void setLineModesVariant(const QVariantList &modes);
    [[nodiscard]] Q_DECL_HIDDEN QVariantList individualTransportModesVariant() const;
    Q_DECL_HIDDEN void setIndividualTransportModesVariant(const QVariantList &modes);

    [[nodiscard]] Q_DECL_HIDDEN RequestContext context(const AbstractBackend *backend) const;
    [[nodiscard]] Q_DECL_HIDDEN const std::vector<RequestContext>& contexts() const;
    Q_DECL_HIDDEN void setContext(const AbstractBackend *backend, RequestContext &&context);
    Q_DECL_HIDDEN void purgeLoops(const JourneyRequest &baseRequest);

    /** Check that the given request parameters are semantically sane, and fix that if needed. */
    void validate() const;
};

}

Q_DECLARE_METATYPE(KPublicTransport::JourneyRequest)

#endif // KPUBLICTRANSPORT_JOURNEYREQUEST_H
