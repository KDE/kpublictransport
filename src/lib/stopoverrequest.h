/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_STOPOVERREQUEST_H
#define KPUBLICTRANSPORT_STOPOVERREQUEST_H

#include "kpublictransport_export.h"

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
    Q_GADGET
    Q_PROPERTY(KPublicTransport::Location stop READ stop WRITE setStop)
    Q_PROPERTY(QDateTime dateTime READ dateTime WRITE setDateTime)
    Q_PROPERTY(Mode mode READ mode WRITE setMode)
    Q_PROPERTY(QStringList backends READ backendIds WRITE setBackendIds)
    Q_PROPERTY(bool downloadAssets READ downloadAssets WRITE setDownloadAssets)

public:
    StopoverRequest();
    /** Search for arrival/departures to/from @p stop. */
    explicit StopoverRequest(const Location &stop);
    StopoverRequest(StopoverRequest&&) noexcept;
    StopoverRequest(const StopoverRequest&);
    ~StopoverRequest();
    StopoverRequest& operator=(const StopoverRequest&);

    /** Returns @c true if this is a valid request, ie. this is complete enough to perform a query. */
    bool isValid() const;

    /** The location at which to look for departures. */
    Location stop() const;
    /** Sets the location at which to look for departures/arrivals. */
    void setStop(const Location &stop);

    /** Date/time at which the search should start. */
    QDateTime dateTime() const;
    /** Set the starting time for the search. */
    void setDateTime(const QDateTime &dt);

    /** Query departures or arrivals? */
    enum Mode {
        QueryArrival, ///< Search for arrivals.
        QueryDeparture ///< Search for departures.
    };
    Q_ENUM(Mode)

    /** Returns whether to search for arrivals or departures. */
    Mode mode() const;
    /** Set whether to search for arrivals or departures. */
    void setMode(Mode mode);

    /** Identifiers of the backends that should be queried.
     *  @see setBackendIds()
     */
    QStringList backendIds() const;
    /** Set identifiers of backends that should be queried.
     *  Settings this is only needed when you want explicit control over this, leaving
     *  this empty picks suitable backends automatically.
     */
    void setBackendIds(const QStringList &backendIds);

    /** Download graphic assets such as line logos for the data requested here. */
    bool downloadAssets() const;
    /** Enable downloading of graphic assets.
     *  Default: @c false
     */
    void setDownloadAssets(bool downloadAssets);

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

    QExplicitlySharedDataPointer<StopoverRequestPrivate> d;
};
}

Q_DECLARE_METATYPE(KPublicTransport::StopoverRequest)

#endif // KPUBLICTRANSPORT_STOPOVERREQUEST_H
