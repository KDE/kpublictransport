/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "journeyutil_p.h"
#include "stopoverutil_p.h"
#include "timeutil_p.h"

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

void JourneyUtil::applyTimeZone(Journey &jny, const QTimeZone &tz)
{
    auto sections = std::move(jny.takeSections());
    for (auto &sec : sections) {
        sec.setScheduledDepartureTime(TimeUtil::applyTimeZone(sec.scheduledDepartureTime(), tz));
        sec.setExpectedDepartureTime(TimeUtil::applyTimeZone(sec.expectedDepartureTime(), tz));
        sec.setScheduledArrivalTime(TimeUtil::applyTimeZone(sec.scheduledArrivalTime(), tz));
        sec.setExpectedArrivalTime(TimeUtil::applyTimeZone(sec.expectedArrivalTime(), tz));

        auto stops = sec.takeIntermediateStops();
        for (auto &stop : stops) {
            StopoverUtil::applyTimeZone(stop, tz);
        }
        sec.setIntermediateStops(std::move(stops));
    }
    jny.setSections(std::move(sections));
}

void JourneyUtil::propagateTimeZones(Journey &jny)
{
    auto sections = std::move(jny.takeSections());
    for (auto &sec : sections) {
        if (const auto tz = sec.from().timeZone(); tz.isValid()) {
            sec.setScheduledDepartureTime(TimeUtil::applyTimeZone(sec.scheduledDepartureTime(), tz));
            sec.setExpectedDepartureTime(TimeUtil::applyTimeZone(sec.expectedDepartureTime(), tz));
        }
        if (const auto tz = sec.to().timeZone(); tz.isValid()) {
            sec.setScheduledArrivalTime(TimeUtil::applyTimeZone(sec.scheduledArrivalTime(), tz));
            sec.setExpectedArrivalTime(TimeUtil::applyTimeZone(sec.expectedArrivalTime(), tz));
        }

        auto stops = sec.takeIntermediateStops();
        for (auto &stop : stops) {
            StopoverUtil::propagateTimeZone(stop);
        }
        sec.setIntermediateStops(std::move(stops));
    }
    jny.setSections(std::move(sections));
}
