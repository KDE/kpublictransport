/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_JOURNEYUTIL_P_H
#define KPUBLICTRANSPORT_JOURNEYUTIL_P_H

class QDateTime;

namespace KPublicTransport {

class Journey;

/** Internal utility functions for dealing with journeys. */
namespace JourneyUtil
{
    /** Departure time of the first transport section (overall departure time, if there is none).
     *  Unlike the overall departure time, this guarantees a stable order in the face of merging journeys.
     */
    QDateTime firstTransportDeparture(const Journey &jny);

    /** Less than comparison on first transport departure time. */
    bool firstTransportDepartureLessThan(const Journey &lhs, const Journey &rhs);
    /** Equal comparison on first transport departure time. */
    bool firstTransportDepartureEqual(const Journey &lhs, const Journey &rhs);
}

}

#endif // KPUBLICTRANSPORT_JOURNEYUTIL_P_H
