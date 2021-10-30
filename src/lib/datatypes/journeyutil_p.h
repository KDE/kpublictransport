/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_JOURNEYUTIL_P_H
#define KPUBLICTRANSPORT_JOURNEYUTIL_P_H

class QDateTime;
class QTimeZone;

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

    /** Reinterpret all floating times as times with the given timezone. */
    void applyTimeZone(Journey &jny, const QTimeZone &tz);
}

}

#endif // KPUBLICTRANSPORT_JOURNEYUTIL_P_H
