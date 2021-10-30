/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "stopoverutil_p.h"
#include "timeutil_p.h"

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

void StopoverUtil::applyTimeZone(Stopover &dep, const QTimeZone &tz)
{
    dep.setScheduledDepartureTime(TimeUtil::applyTimeZone(dep.scheduledDepartureTime(), tz));
    dep.setExpectedDepartureTime(TimeUtil::applyTimeZone(dep.expectedDepartureTime(), tz));
    dep.setScheduledArrivalTime(TimeUtil::applyTimeZone(dep.scheduledArrivalTime(), tz));
    dep.setExpectedArrivalTime(TimeUtil::applyTimeZone(dep.expectedArrivalTime(), tz));
}
