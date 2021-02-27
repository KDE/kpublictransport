/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_STOPOVERREQUEST_H
#define KPUBLICTRANSPORT_STOPOVERREQUEST_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Datatypes>

#include <QMetaType>
#include <QSharedDataPointer>

#include <vector>

class QDateTime;

namespace KPublicTransport {

class AbstractBackend;
class Location;
class RequestContext;
class StopoverRequestPrivate;

/** Describes an arrival or departure search.
 *  By default this search departures starting now, from the given Location.
 */
class KPUBLICTRANSPORT_EXPORT StopoverRequest
{
    KPUBLICTRANSPORT_GADGET(StopoverRequest)

    /** The location at which to search for departures/arrivals. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Location, stop, setStop)
    /** Date/time at which the search should start.
     *  Default: now
     */
    KPUBLICTRANSPORT_PROPERTY(QDateTime, dateTime, setDateTime)

public:
    /** Query departures or arrivals? */
    enum Mode {
        QueryArrival, ///< Search for arrivals.
        QueryDeparture ///< Search for departures.
    };
    Q_ENUM(Mode)

    /** Controls whether to search for arrivals or departures.
     *  Default is QueryDeparture.
     */
    KPUBLICTRANSPORT_PROPERTY(Mode, mode, setMode)

    Q_PROPERTY(QStringList backends READ backendIds WRITE setBackendIds)

    /** Enable downloading of graphic assets such as line logos for the data requested here.
     *  Default: @c false
     */
    KPUBLICTRANSPORT_PROPERTY(bool, downloadAssets, setDownloadAssets)

public:
    /** Search for arrival/departures to/from @p stop. */
    explicit StopoverRequest(const Location &stop);

    /** Returns @c true if this is a valid request, ie. this is complete enough to perform a query. */
    bool isValid() const;

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
    static QJsonObject toJson(const StopoverRequest &req);
    ///@endcond
private:
    friend class AbstractBackend;
    friend class StopoverReply;
    friend class StopoverReplyPrivate;
    friend class Manager;
    Q_DECL_HIDDEN RequestContext context(const AbstractBackend *backend) const;
    Q_DECL_HIDDEN const std::vector<RequestContext>& contexts() const;
    Q_DECL_HIDDEN void setContext(const AbstractBackend *backend, RequestContext &&context);
    Q_DECL_HIDDEN void purgeLoops(const StopoverRequest &baseRequest);
};
}

Q_DECLARE_METATYPE(KPublicTransport::StopoverRequest)

#endif // KPUBLICTRANSPORT_STOPOVERREQUEST_H
