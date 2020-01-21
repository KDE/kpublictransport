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

#include "journeyutil_p.h"

#include <KPublicTransport/Journey>

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
