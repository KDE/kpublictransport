/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "stopoverutil_p.h"
#include "lineutil_p.h"

#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopoverRequest>

#include <QDateTime>
#include <QTimeZone>

using namespace KPublicTransport;

static QDateTime clipSeconds(QDateTime dt)
{
    dt.setTime({dt.time().hour(), dt.time().minute()});
    return dt;
}

bool StopoverUtil::timeLessThan(const StopoverRequest &req, const Stopover &lhs, const Stopover &rhs)
{
    if (req.mode() == StopoverRequest::QueryDeparture) {
        return clipSeconds(lhs.scheduledDepartureTime()) < clipSeconds(rhs.scheduledDepartureTime());
    } else {
        return clipSeconds(lhs.scheduledArrivalTime()) < clipSeconds(rhs.scheduledArrivalTime());
    }
}

bool StopoverUtil::timeEqual(const StopoverRequest &req, const Stopover &lhs, const Stopover &rhs)
{
    if (req.mode() == StopoverRequest::QueryDeparture) {
        return clipSeconds(lhs.scheduledDepartureTime()) == clipSeconds(rhs.scheduledDepartureTime());
    } else {
        return clipSeconds(lhs.scheduledArrivalTime()) == clipSeconds(rhs.scheduledArrivalTime());
    }
}

static QDateTime applyTimeZone(QDateTime dt, const QTimeZone &tz)
{
    if (!dt.isValid() || dt.timeSpec() != Qt::LocalTime) {
        return dt;
    }
    dt.setTimeZone(tz);
    return dt;
}

void StopoverUtil::applyTimeZone(Stopover &dep, const QTimeZone &tz)
{
    dep.setScheduledDepartureTime(applyTimeZone(dep.scheduledDepartureTime(), tz));
    dep.setExpectedDepartureTime(applyTimeZone(dep.expectedDepartureTime(), tz));
    dep.setScheduledArrivalTime(applyTimeZone(dep.scheduledArrivalTime(), tz));
    dep.setExpectedArrivalTime(applyTimeZone(dep.expectedArrivalTime(), tz));
}

void StopoverUtil::applyMetaData(Stopover &dep, bool download)
{
    auto route = dep.route();
    auto line = route.line();
    LineUtil::applyMetaData(line, dep.stopPoint(), download);
    route.setLine(line);
    dep.setRoute(route);
}
