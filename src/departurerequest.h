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

#include <QSharedDataPointer>

class QDateTime;

namespace KPublicTransport {

class DepartureRequestPrivate;
class Location;

/** Describes an arrival or departure search.
 *  By default this search departures starting now, from the given Location.
 */
class KPUBLICTRANSPORT_EXPORT DepartureRequest
{
public:
    DepartureRequest();
    /** Search for arrival/departures to/from @p stop. */
    explicit DepartureRequest(const Location &stop);
    DepartureRequest(DepartureRequest&&) noexcept;
    DepartureRequest(const DepartureRequest&);
    ~DepartureRequest();
    DepartureRequest& operator=(const DepartureRequest&);

    /** The location at which to look for departures. */
    Location stop() const;

    /** Date/time at which the search should start. */
    QDateTime dateTime() const;
    /** Set the starting time for the search. */
    void setDateTime(const QDateTime &dt);

    /** Query departures or arrivals? */
    enum Mode {
        QueryArrival, ///< Search for arrivals.
        QueryDeparture ///< Search for departures.
    };
    /** Returns whether to search for arrivals or departures. */
    Mode mode() const;
    /** Set whether to search for arrivals or departures. */
    void setMode(Mode mode);

private:
    QExplicitlySharedDataPointer<DepartureRequestPrivate> d;
};
}

#endif // KPUBLICTRANSPORT_DEPARTUREREQUEST_H
