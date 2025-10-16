/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_JOURNEYUTIL_P_H
#define KPUBLICTRANSPORT_JOURNEYUTIL_P_H

#include "kpublictransport_export.h"

class QDateTime;
class QUrl;
class QTimeZone;

namespace KPublicTransport {

class Journey;
class JourneySection;

/** Internal utility functions for dealing with journeys. */
namespace JourneyUtil
{
    /** Departure time of the first transport section (overall departure time, if there is none).
     *  Unlike the overall departure time, this guarantees a stable order in the face of merging journeys.
     */
    [[nodiscard]] QDateTime firstTransportDeparture(const Journey &jny);

    /** Less than comparison on first transport departure time. */
    [[nodiscard]] bool firstTransportDepartureLessThan(const Journey &lhs, const Journey &rhs);
    /** Equal comparison on first transport departure time. */
    [[nodiscard]] bool firstTransportDepartureEqual(const Journey &lhs, const Journey &rhs);

    /** Reinterpret all floating times as times with the given timezone. */
    void applyTimeZone(Journey &jny, const QTimeZone &tz);

    /** Propagate location-based timezone information from corresponding stop point locations.
     *  @internal only exported for KPublicTransportOnboard
     */
    KPUBLICTRANSPORT_EXPORT void propagateTimeZones(Journey &jny);
    void propagateTimeZones(JourneySection &sec);

    /** Fix common nonsense found in journey section paths reported from backends. */
    void postProcessPath(JourneySection &section);

    /** Set a static operator URL wherever missing/needed. */
    void applyOperatorUrl(Journey &jny, const QUrl &operatorUrl);
    void applyOperatorUrl(JourneySection &section, const QUrl &operatorUrl);
}

}

#endif // KPUBLICTRANSPORT_JOURNEYUTIL_P_H
