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

#ifndef KPUBLICTRANSPORT_DEPARTUREREQUEST_H
#define KPUBLICTRANSPORT_DEPARTUREREQUEST_H

#include "kpublictransport_export.h"

#include <QMetaType>
#include <QSharedDataPointer>

#include <vector>

class QDateTime;

namespace KPublicTransport {

class AbstractBackend;
class DepartureRequestPrivate;
class Location;
class RequestContext;

/** Describes an arrival or departure search.
 *  By default this search departures starting now, from the given Location.
 */
class KPUBLICTRANSPORT_EXPORT DepartureRequest
{
    Q_GADGET
    Q_PROPERTY(KPublicTransport::Location stop READ stop WRITE setStop)
    Q_PROPERTY(QDateTime dateTime READ dateTime WRITE setDateTime)
    Q_PROPERTY(Mode mode READ mode WRITE setMode)
    Q_PROPERTY(QStringList backends READ backendIds WRITE setBackendIds)
    Q_PROPERTY(bool downloadAssets READ downloadAssets WRITE setDownloadAssets)

public:
    DepartureRequest();
    /** Search for arrival/departures to/from @p stop. */
    explicit DepartureRequest(const Location &stop);
    DepartureRequest(DepartureRequest&&) noexcept;
    DepartureRequest(const DepartureRequest&);
    ~DepartureRequest();
    DepartureRequest& operator=(const DepartureRequest&);

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
    static QJsonObject toJson(const DepartureRequest &req);
    ///@endcond
private:
    friend class AbstractBackend;
    friend class DepartureReply;
    friend class DepartureReplyPrivate;
    friend class Manager;
    Q_DECL_HIDDEN RequestContext context(const AbstractBackend *backend) const;
    Q_DECL_HIDDEN const std::vector<RequestContext>& contexts() const;
    Q_DECL_HIDDEN void setContext(const AbstractBackend *backend, RequestContext &&context);
    Q_DECL_HIDDEN void purgeLoops(const DepartureRequest &baseRequest);

    QExplicitlySharedDataPointer<DepartureRequestPrivate> d;
};
}

Q_DECLARE_METATYPE(KPublicTransport::DepartureRequest)

#endif // KPUBLICTRANSPORT_DEPARTUREREQUEST_H
