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

#ifndef KPUBLICTRANSPORT_JOURNEYREQUEST_H
#define KPUBLICTRANSPORT_JOURNEYREQUEST_H

#include "kpublictransport_export.h"

#include <QSharedDataPointer>

#include <vector>

class QDateTime;

namespace KPublicTransport {

class AbstractBackend;
class JourneyReply;
class JourneyRequestPrivate;
class JourneyRequestContext;
class Location;

/** Describes a journey search.
 *  By default journeys departing now are searched.
 */
class KPUBLICTRANSPORT_EXPORT JourneyRequest
{
public:
    JourneyRequest();
    /** Search a journey from @p from to @p to. */
    JourneyRequest(const Location &from, const Location &to);
    JourneyRequest(JourneyRequest&&) noexcept;
    JourneyRequest(const JourneyRequest &);
    ~JourneyRequest();
    JourneyRequest& operator=(const JourneyRequest&);

    /** Returns @c true if this is a default-constructed object without any request parameters. */
    bool isEmpty() const;

    /** The starting point of the journey search. */
    Location from() const;
    /** Set the starting point for the journey. */
    void setFrom(const Location &from);
    /** The journey destination. */
    Location to() const;
    /** Set the destination of the journey. */
    void setTo(const Location &to);

    /** Date/time at which the journey should start/end. */
    QDateTime dateTime() const;
    enum DateTimeMode {
        Arrival, ///< dateTime() represents the desired arriva time.
        Departure ///< dateTime() represents the desired departure time.
    };
    /** Returns whether to search for journeys starting or ending at the given time. */
    DateTimeMode dateTimeMode() const;
    /** Set the desired departure time.
     *  This is mutually exclusive to setting a desired arrival time.
     */
    void setDeparutreTime(const QDateTime &dt);
    /** Sets the desired arrival time.
     *  This is mutually exclusive to setting a desired departure time.
     */
    void setArrivalTime(const QDateTime &dt);

private:
    friend class JourneyReply;
    Q_DECL_HIDDEN JourneyRequestContext context(const AbstractBackend *backend) const;
    Q_DECL_HIDDEN const std::vector<JourneyRequestContext>& contexts() const;
    Q_DECL_HIDDEN void setContext(const AbstractBackend *backend, JourneyRequestContext &&context);

    QExplicitlySharedDataPointer<JourneyRequestPrivate> d;
};

}

#endif // KPUBLICTRANSPORT_JOURNEYREQUEST_H
