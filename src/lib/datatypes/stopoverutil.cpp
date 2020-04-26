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
