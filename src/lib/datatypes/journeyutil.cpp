/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "journeyutil_p.h"

#include "logging.h"
#include "stopoverutil_p.h"
#include "timeutil_p.h"

#include "geo/pathfilter_p.h"

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
        propagateTimeZones(sec);
    }
    jny.setSections(std::move(sections));
}

void JourneyUtil::propagateTimeZones(JourneySection &sec)
{
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

void JourneyUtil::postProcessPath(JourneySection &section)
{
    if (!section.from().hasCoordinate() || !section.to().hasCoordinate() || section.path().isEmpty()) {
        return;
    }

    // remove implausible paths
    // NOTE: circular lines have pointDist 0, so the heuristic doesn't work for those
    const auto pointDist = Location::distance(section.from(), section.to());
    const auto pathDist = section.path().distance();
    if (pathDist > pointDist * 10 && pointDist != 0) {
        qCDebug(Log) << "Dropping implausibly long path:" << pointDist << pathDist;
        section.setPath({});
    }

    // filter spikes found in rail paths in nearly all backends and GTFS shapes
    if (section.mode() == JourneySection::PublicTransport && Line::modeIsRailBound(section.route().line().mode())) {
        auto path = section.path();
        auto pathSecs = path.takeSections();
        for (auto &pathSec : pathSecs) {
            QPolygonF p = pathSec.path();
            PathFilter::removeSpikes(p, 55.0);
            pathSec.setPath(p);
        }
        path.setSections(std::move(pathSecs));
        section.setPath(path);
    }
}
