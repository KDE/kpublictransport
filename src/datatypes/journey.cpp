/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#include "journey.h"
#include "json_p.h"
#include "datatypes_p.h"
#include "mergeutil_p.h"

#include <QDebug>
#include <QVariant>

using namespace KPublicTransport;

namespace KPublicTransport {

class JourneySectionPrivate : public QSharedData
{
public:
    JourneySection::Mode mode = JourneySection::Invalid;
    QDateTime scheduledDepartureTime;
    QDateTime expectedDepartureTime;
    QDateTime scheduledArrivalTime;
    QDateTime expectedArrivalTime;
    Location from;
    Location to;
    Route route;
    QString scheduledDeparturePlatform;
    QString expectedDeparturePlatform;
    QString scheduledArrivalPlatform;
    QString expectedArrivalPlatform;
};

class JourneyPrivate : public QSharedData
{
public:
    std::vector<JourneySection> sections;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(JourneySection)

JourneySection::Mode JourneySection::mode() const
{
    return d->mode;
}

void JourneySection::setMode(JourneySection::Mode mode)
{
    d.detach();
    d->mode = mode;
}

QDateTime JourneySection::scheduledDepartureTime() const
{
    return d->scheduledDepartureTime;
}

void JourneySection::setScheduledDepartureTime(const QDateTime &dt)
{
    d.detach();
    d->scheduledDepartureTime = dt;
}

QDateTime JourneySection::expectedDepartureTime() const
{
    return d->expectedDepartureTime;
}

void JourneySection::setExpectedDepartureTime(const QDateTime &dt)
{
    d.detach();
    d->expectedDepartureTime = dt;
}

bool JourneySection::hasExpectedDepartureTime() const
{
    return d->expectedDepartureTime.isValid();
}

int JourneySection::departureDelay() const
{
    if (hasExpectedDepartureTime()) {
        return d->scheduledDepartureTime.secsTo(d->expectedDepartureTime) / 60;
    }
    return 0;
}

QDateTime JourneySection::scheduledArrivalTime() const
{
    return d->scheduledArrivalTime;
}

void JourneySection::setScheduledArrivalTime(const QDateTime &dt)
{
    d.detach();
    d->scheduledArrivalTime = dt;
}

QDateTime JourneySection::expectedArrivalTime() const
{
    return d->expectedArrivalTime;
}

void JourneySection::setExpectedArrivalTime(const QDateTime &dt)
{
    d.detach();
    d->expectedArrivalTime = dt;
}

bool JourneySection::hasExpectedArrivalTime() const
{
    return d->expectedArrivalTime.isValid();
}

int JourneySection::arrivalDelay() const
{
    if (hasExpectedArrivalTime()) {
        return d->scheduledArrivalTime.secsTo(d->expectedArrivalTime) / 60;
    }
    return 0;
}

int JourneySection::duration() const
{
    return d->scheduledDepartureTime.secsTo(d->scheduledArrivalTime);
}

Location JourneySection::from() const
{
    return d->from;
}

void JourneySection::setFrom(const Location &from)
{
    d.detach();
    d->from = from;
}

Location JourneySection::to() const
{
    return d->to;
}

void JourneySection::setTo(const Location &to)
{
    d.detach();
    d->to = to;
}

Route JourneySection::route() const
{
    return d->route;
}

void JourneySection::setRoute(const Route &route)
{
    d.detach();
    d->route = route;
}

QString JourneySection::scheduledDeparturePlatform() const
{
    return d->scheduledDeparturePlatform;
}

void JourneySection::setScheduledDeparturePlatform(const QString &platform)
{
    d.detach();
    d->scheduledDeparturePlatform = platform;
}

QString JourneySection::expectedDeparturePlatform() const
{
    return d->expectedDeparturePlatform;
}

void JourneySection::setExpectedDeparturePlatform(const QString &platform)
{
    d.detach();
    d->expectedDeparturePlatform = platform;
}

bool JourneySection::hasExpectedDeparturePlatform() const
{
    return !d->expectedDeparturePlatform.isEmpty();
}

bool JourneySection::departurePlatformChanged() const
{
    return hasExpectedDeparturePlatform() && d->expectedDeparturePlatform != d->scheduledDeparturePlatform;
}

QString JourneySection::scheduledArrivalPlatform() const
{
    return d->scheduledArrivalPlatform;
}

void JourneySection::setScheduledArrivalPlatform(const QString &platform)
{
    d.detach();
    d->scheduledArrivalPlatform = platform;
}

QString JourneySection::expectedArrivalPlatform() const
{
    return d->expectedArrivalPlatform;
}

void JourneySection::setExpectedArrivalPlatform(const QString &platform)
{
    d.detach();
    d->expectedArrivalPlatform = platform;
}

bool JourneySection::hasExpectedArrivalPlatform() const
{
    return !d->expectedArrivalPlatform.isEmpty();
}

bool JourneySection::arrivalPlatformChanged() const
{
    return hasExpectedArrivalPlatform() && d->scheduledArrivalPlatform != d->expectedArrivalPlatform;
}

bool JourneySection::isSame(const JourneySection &lhs, const JourneySection &rhs)
{
    if (lhs.d->mode != rhs.d->mode) {
        return false;
    }

    // we have N criteria to compare here, with 3 possible results:
    // - equal
    // - similar-ish, unknwon, or at least not conflicting
    // - conflicting
    // A single conflict results in a negative result, at least N - 1 equal comparisons lead to
    // in a positive result.
    enum { Equal = 1, Compatible = 0, Conflict = -1000 };
    int result = 0;

    const auto depTimeDist = MergeUtil::distance(lhs.d->scheduledDepartureTime, rhs.d->scheduledDepartureTime);
    result += depTimeDist < 60 ? Equal : depTimeDist <= 60 ? Compatible : Conflict;
    const auto arrTimeDist = MergeUtil::distance(lhs.d->scheduledArrivalTime, rhs.d->scheduledArrivalTime);
    result += arrTimeDist < 60 ? Equal : depTimeDist <= 60 ? Compatible : Conflict;

    const auto sameFrom = Location::isSame(lhs.d->from, rhs.d->from);
    const auto fromDist = Location::distance(lhs.from(), rhs.from());
    result += sameFrom ? Equal : fromDist < 200 ? Compatible : Conflict;

    const auto sameTo = Location::isSame(lhs.d->to, rhs.d->to);
    const auto toDist = Location::distance(lhs.to(), rhs.to());
    result += sameTo ? Equal : toDist < 200 ? Compatible : Conflict;

    const auto sameRoute = Route::isSame(lhs.d->route, rhs.d->route);
    const auto sameDir = Location::isSameName(lhs.d->route.direction(), rhs.d->route.direction());
    result += sameRoute ? Equal : sameDir ? Compatible : Conflict;

    if (!lhs.scheduledDeparturePlatform().isEmpty() && !rhs.scheduledDeparturePlatform().isEmpty()) {
        result += lhs.scheduledDeparturePlatform() == rhs.scheduledDeparturePlatform() ? Equal : Conflict;
    }

    return result >= 4;
}

JourneySection JourneySection::merge(const JourneySection &lhs, const JourneySection &rhs)
{
    using namespace MergeUtil;
    auto res = lhs;
    res.setScheduledDepartureTime(mergeDateTimeEqual(lhs.scheduledDepartureTime(), rhs.scheduledDepartureTime()));
    res.setExpectedDepartureTime(mergeDateTimeMax(lhs.expectedDepartureTime(), rhs.expectedDepartureTime()));
    res.setScheduledArrivalTime(mergeDateTimeMax(lhs.scheduledArrivalTime(), rhs.scheduledArrivalTime()));
    res.setExpectedArrivalTime(mergeDateTimeMax(lhs.expectedArrivalTime(), rhs.expectedArrivalTime()));

    if (res.expectedDeparturePlatform().isEmpty()) {
        res.setExpectedDeparturePlatform(rhs.expectedDeparturePlatform());
    }
    if (res.expectedArrivalPlatform().isEmpty()) {
        res.setExpectedArrivalPlatform(rhs.expectedArrivalPlatform());
    }
    res.setFrom(Location::merge(lhs.from(), rhs.from()));
    res.setTo(Location::merge(lhs.to(), rhs.to()));
    res.setRoute(Route::merge(lhs.route(), rhs.route()));

    res.setScheduledDeparturePlatform(mergeString(lhs.scheduledDeparturePlatform(), rhs.scheduledDeparturePlatform()));
    res.setScheduledArrivalPlatform(mergeString(lhs.scheduledArrivalPlatform(), rhs.scheduledArrivalPlatform()));

    return res;
}

QJsonObject JourneySection::toJson(const JourneySection &section)
{
    auto obj = Json::toJson(section);
    if (section.mode() != Waiting) {
        obj.insert(QStringLiteral("from"), Location::toJson(section.from()));
        obj.insert(QStringLiteral("to"), Location::toJson(section.to()));
    }
    if (section.mode() == PublicTransport) {
        obj.insert(QStringLiteral("route"), Route::toJson(section.route()));
    }
    return obj;
}

QJsonArray JourneySection::toJson(const std::vector<JourneySection> &sections)
{
    return Json::toJson(sections);
}

JourneySection JourneySection::fromJson(const QJsonObject &obj)
{
    auto section = Json::fromJson<JourneySection>(obj);
    section.setFrom(Location::fromJson(obj.value(QLatin1String("from")).toObject()));
    section.setTo(Location::fromJson(obj.value(QLatin1String("to")).toObject()));
    section.setRoute(Route::fromJson(obj.value(QLatin1String("route")).toObject()));
    return section;
}

std::vector<JourneySection> JourneySection::fromJson(const QJsonArray &array)
{
    return Json::fromJson<JourneySection>(array);
}


KPUBLICTRANSPORT_MAKE_GADGET(Journey)

const std::vector<JourneySection>& Journey::sections() const
{
    return d->sections;
}

std::vector<JourneySection>&& Journey::takeSections()
{
    return std::move(d->sections);
}

void Journey::setSections(std::vector<JourneySection> &&sections)
{
    d.detach();
    d->sections = std::move(sections);
}

QVariantList Journey::sectionsVariant() const
{
    QVariantList l;
    l.reserve(d->sections.size());
    std::transform(d->sections.begin(), d->sections.end(), std::back_inserter(l), [](const auto &sec) { return QVariant::fromValue(sec); });
    return l;
}

QDateTime Journey::scheduledDepartureTime() const
{
    if (!d->sections.empty()) {
        return d->sections.front().scheduledDepartureTime();
    }
    return {};
}

QDateTime Journey::scheduledArrivalTime() const
{
    if (!d->sections.empty()) {
        return d->sections.back().scheduledArrivalTime();
    }
    return {};
}

int Journey::duration() const
{
    return scheduledDepartureTime().secsTo(scheduledArrivalTime());
}

int Journey::numberOfChanges() const
{
    return std::count_if(d->sections.begin(), d->sections.end(), [](const auto &section) { return section.mode() == JourneySection::PublicTransport; });
}

bool Journey::isSame(const Journey &lhs, const Journey &rhs)
{
    auto lIt = lhs.sections().begin();
    auto rIt = rhs.sections().begin();

    while (lIt != lhs.sections().end() || rIt != rhs.sections().end()) {
        // ignore non-transport sections
        if (lIt != lhs.sections().end() && (*lIt).mode() != JourneySection::PublicTransport) {
            ++lIt;
            continue;
        }
        if (rIt != rhs.sections().end() && (*rIt).mode() != JourneySection::PublicTransport) {
            ++rIt;
            continue;
        }

        if (lIt == lhs.sections().end() || rIt == rhs.sections().end()) {
            return false;
        }

        if (!JourneySection::isSame(*lIt, *rIt)) {
            return false;
        }

        ++lIt;
        ++rIt;
    }

    Q_ASSERT(lIt == lhs.sections().end() && rIt == rhs.sections().end());
    return true;
}

Journey Journey::merge(const Journey &lhs, const Journey &rhs)
{
    std::vector<JourneySection> sections;
    sections.reserve(lhs.sections().size() + rhs.sections().size());
    std::copy(lhs.sections().begin(), lhs.sections().end(), std::back_inserter(sections));
    std::copy(rhs.sections().begin(), rhs.sections().end(), std::back_inserter(sections));
    std::sort(sections.begin(), sections.end(), [](const auto &lSec, const auto &rSec) {
        if (MergeUtil::distance(lSec.scheduledDepartureTime(), rSec.scheduledDepartureTime()) == 0) {
            return lSec.mode() < rSec.mode();
        }
        return MergeUtil::isBefore(lSec.scheduledDepartureTime(), rSec.scheduledDepartureTime());
    });

    for (auto it = sections.begin(); it != sections.end(); ++it) {
        const auto nextIt = it + 1;
        if (nextIt == sections.end()) {
            break;
        }

        if (JourneySection::isSame(*it, *nextIt) || ((*it).mode() == (*nextIt).mode() && (*it).mode() != JourneySection::PublicTransport)) {
            *it = JourneySection::merge(*it, *nextIt);
            sections.erase(nextIt);
        }
    }

    Journey res;
    res.setSections(std::move(sections));
    return res;
}

QJsonObject Journey::toJson(const Journey &journey)
{
    QJsonObject obj;
    obj.insert(QStringLiteral("sections"), JourneySection::toJson(journey.sections()));
    return obj;
}

QJsonArray Journey::toJson(const std::vector<Journey> &journeys)
{
    return Json::toJson(journeys);
}

Journey KPublicTransport::Journey::fromJson(const QJsonObject &obj)
{
    Journey j;
    j.setSections(JourneySection::fromJson(obj.value(QLatin1String("sections")).toArray()));
    return j;
}

#include "moc_journey.cpp"
