/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "journeyutil_p.h"
#include "lineutil_p.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Stopover>

#include <QDateTime>
#include <QTimeZone>

using namespace KPublicTransport;

QDateTime JourneyUtil::firstTransportDeparture(const Journey &jny)
{
    for (const auto &section : jny.sections()) {
        if (section.mode() == JourneySection::PublicTransport) {
            return section.scheduledDepartureTime();
        }
    }

    return jny.scheduledDepartureTime();
}

bool JourneyUtil::firstTransportDepartureLessThan(const Journey &lhs, const Journey &rhs)
{
    return firstTransportDeparture(lhs) < firstTransportDeparture(rhs);
}

bool JourneyUtil::firstTransportDepartureEqual(const Journey &lhs, const Journey &rhs)
{
    return firstTransportDeparture(lhs) == firstTransportDeparture(rhs);
}

static QDateTime applyTimeZone(QDateTime dt, const QTimeZone &tz)
{
    if (!dt.isValid()) {
        return dt;
    }
    switch (dt.timeSpec()) {
        case Qt::LocalTime:
            dt.setTimeZone(tz);
            break;
        case Qt::UTC:
            dt = dt.toTimeZone(tz);
            break;
        default:
            break;
    }
    return dt;
}

void JourneyUtil::applyTimeZone(Journey &jny, const QTimeZone &tz)
{
    auto sections = std::move(jny.takeSections());
    for (auto &sec : sections) {
        sec.setScheduledDepartureTime(applyTimeZone(sec.scheduledDepartureTime(), tz));
        sec.setExpectedDepartureTime(applyTimeZone(sec.expectedDepartureTime(), tz));
        sec.setScheduledArrivalTime(applyTimeZone(sec.scheduledArrivalTime(), tz));
        sec.setExpectedArrivalTime(applyTimeZone(sec.expectedArrivalTime(), tz));
    }
    jny.setSections(std::move(sections));
}

void JourneyUtil::applyMetaData(Journey &jny, bool download)
{
    auto sections = std::move(jny.takeSections());
    for (auto &sec : sections) {
        if (!sec.from().hasCoordinate() || sec.mode() != JourneySection::PublicTransport) {
            continue;
        }
        auto route = sec.route();
        auto line = route.line();
        LineUtil::applyMetaData(line, sec.from(), download);
        route.setLine(line);
        sec.setRoute(route);

        // propagate to intermediate stops
        auto stops = sec.takeIntermediateStops();
        for (auto &stop : stops) {
            stop.setRoute(route);
        }
        sec.setIntermediateStops(std::move(stops));
    }
    jny.setSections(std::move(sections));
}
