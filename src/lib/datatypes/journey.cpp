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
#include "journeyutil_p.h"
#include "json_p.h"
#include "datatypes_p.h"
#include "mergeutil_p.h"
#include "notesutil_p.h"
#include "platformutils_p.h"
#include "stopover.h"

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
    int distance = 0;
    Disruption::Effect disruptionEffect = Disruption::NormalService;
    QStringList notes;
    std::vector<Stopover> intermediateStops;
    int co2Emission = -1;
    std::vector<LoadInfo> loadInformation;

    int estimatedDistance() const;
};

class JourneyPrivate : public QSharedData
{
public:
    std::vector<JourneySection> sections;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(JourneySection)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, JourneySection::Mode, mode, setMode)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, QDateTime, scheduledDepartureTime, setScheduledDepartureTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, QDateTime, expectedDepartureTime, setExpectedDepartureTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, QDateTime, scheduledArrivalTime, setScheduledArrivalTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, QDateTime, expectedArrivalTime, setExpectedArrivalTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, Location, from, setFrom)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, Location, to, setTo)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, Route, route, setRoute)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, Disruption::Effect, disruptionEffect, setDisruptionEffect)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, QStringList, notes, setNotes)

int JourneySectionPrivate::estimatedDistance() const
{
    assert(from.hasCoordinate() && to.hasCoordinate());
    int d = 0;

    float startLat = from.latitude();
    float startLon = from.longitude();

    for (const auto &stop : intermediateStops) {
        if (!stop.stopPoint().hasCoordinate()) {
            continue;
        }
        d += Location::distance(startLat, startLon, stop.stopPoint().latitude(), stop.stopPoint().longitude());
        startLat = stop.stopPoint().latitude();
        startLon = stop.stopPoint().longitude();
    }

    d += Location::distance(startLat, startLon, to.latitude(), to.longitude());
    return d;
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

int JourneySection::distance() const
{
    if (d->mode == JourneySection::Waiting) {
        return 0;
    }
    if (!d->from.hasCoordinate() || !d->to.hasCoordinate()) {
        return d->distance;
    }
    return std::max(d->estimatedDistance(), d->distance);
}

void JourneySection::setDistance(int value)
{
    d.detach();
    d->distance = value;
}

QString JourneySection::scheduledDeparturePlatform() const
{
    return d->scheduledDeparturePlatform;
}

void JourneySection::setScheduledDeparturePlatform(const QString &platform)
{
    d.detach();
    d->scheduledDeparturePlatform = PlatformUtils::normalizePlatform(platform);
}

QString JourneySection::expectedDeparturePlatform() const
{
    return d->expectedDeparturePlatform;
}

void JourneySection::setExpectedDeparturePlatform(const QString &platform)
{
    d.detach();
    d->expectedDeparturePlatform = PlatformUtils::normalizePlatform(platform);
}

bool JourneySection::hasExpectedDeparturePlatform() const
{
    return !d->expectedDeparturePlatform.isEmpty();
}

bool JourneySection::departurePlatformChanged() const
{
    return PlatformUtils::platformChanged(d->scheduledDeparturePlatform, d->expectedDeparturePlatform);
}

QString JourneySection::scheduledArrivalPlatform() const
{
    return d->scheduledArrivalPlatform;
}

void JourneySection::setScheduledArrivalPlatform(const QString &platform)
{
    d.detach();
    d->scheduledArrivalPlatform = PlatformUtils::normalizePlatform(platform);
}

QString JourneySection::expectedArrivalPlatform() const
{
    return d->expectedArrivalPlatform;
}

void JourneySection::setExpectedArrivalPlatform(const QString &platform)
{
    d.detach();
    d->expectedArrivalPlatform = PlatformUtils::normalizePlatform(platform);
}

bool JourneySection::hasExpectedArrivalPlatform() const
{
    return !d->expectedArrivalPlatform.isEmpty();
}

bool JourneySection::arrivalPlatformChanged() const
{
    return PlatformUtils::platformChanged(d->scheduledArrivalPlatform, d->expectedArrivalPlatform);
}

void JourneySection::addNote(const QString &note)
{
    const auto n = NotesUtil::normalizeNote(note);
    const auto idx = NotesUtil::needsAdding(d->notes, n);
    if (idx >= 0) {
        d.detach();
        NotesUtil::performAdd(d->notes, n, idx);
    }
}

void JourneySection::addNotes(const QStringList &notes)
{
    for (const auto &n : notes) {
        addNote(n);
    }
}

const std::vector<Stopover>& JourneySection::intermediateStops() const
{
    return d->intermediateStops;
}

std::vector<Stopover>&& JourneySection::takeIntermediateStops()
{
    return std::move(d->intermediateStops);
}

void JourneySection::setIntermediateStops(std::vector<Stopover> &&stops)
{
    d.detach();
    d->intermediateStops = std::move(stops);
}

QVariantList JourneySection::intermediateStopsVariant() const
{
    QVariantList l;
    l.reserve(d->intermediateStops.size());
    std::transform(d->intermediateStops.begin(), d->intermediateStops.end(), std::back_inserter(l), [](const auto &stop) { return QVariant::fromValue(stop); });
    return l;
}

Stopover JourneySection::departure() const
{
    Stopover dep;
    dep.setStopPoint(from());
    dep.setRoute(route());
    dep.setScheduledDepartureTime(scheduledDepartureTime());
    dep.setExpectedDepartureTime(expectedDepartureTime());
    dep.setScheduledPlatform(scheduledDeparturePlatform());
    dep.setExpectedPlatform(expectedDeparturePlatform());
    dep.addNotes(notes());
    return dep;
}

Stopover JourneySection::arrival() const
{
    Stopover arr;
    arr.setStopPoint(to());
    arr.setRoute(route());
    arr.setScheduledArrivalTime(scheduledArrivalTime());
    arr.setExpectedArrivalTime(expectedArrivalTime());
    arr.setScheduledPlatform(scheduledArrivalPlatform());
    arr.setExpectedPlatform(expectedArrivalPlatform());
    return arr;
}

int JourneySection::co2Emission() const
{
    if (d->co2Emission >= 0) {
        return d->co2Emission;
    }

    struct {
        Line::Mode mode;
        int gramPerKm;
    } static const emissionForModeMap[] = {
        { Line::Air, 285 },
        { Line::Boat, 245 },
        { Line::Bus, 68 },
        { Line::BusRapidTransit, 68 },
        { Line::Coach, 68 },
        { Line::Ferry, 245 },
        { Line::LocalTrain, 14 },
        { Line::LongDistanceTrain, 14 },
        { Line::Metro, 11 },
        { Line::RapidTransit, 11 },
        { Line::Taxi, 158 },
        { Line::Train, 14 },
        { Line::Tramway, 11 },
    };

    const auto mode = route().line().mode();
    for (const auto &map : emissionForModeMap) {
        if (map.mode == mode) {
            return (map.gramPerKm * distance()) / 1000;
        }
    }
    return -1;
}

void JourneySection::setCo2Emission(int value)
{
    d.detach();
    d->co2Emission = value;
}

const std::vector<LoadInfo>& JourneySection::loadInformation() const
{
    return d->loadInformation;
}

std::vector<LoadInfo>&& JourneySection::takeLoadInformation()
{
    d.detach();
    return std::move(d->loadInformation);
}

void JourneySection::setLoadInformation(std::vector<LoadInfo> &&loadInfo)
{
    d.detach();
    d->loadInformation = std::move(loadInfo);
}

QVariantList JourneySection::loadInformationVariant() const
{
    QVariantList l;
    l.reserve(d->loadInformation.size());
    std::transform(d->loadInformation.begin(), d->loadInformation.end(), std::back_inserter(l), [](const auto &load) { return QVariant::fromValue(load); });
    return l;
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
    const auto sameLine = Line::isSame(lhs.d->route.line(), rhs.d->route.line());
    result += sameRoute ? Equal : (sameDir || sameLine) ? Compatible : Conflict;

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

    res.setDisruptionEffect(std::max(lhs.disruptionEffect(), rhs.disruptionEffect()));
    res.setNotes(NotesUtil::mergeNotes(lhs.notes(), rhs.notes()));
    res.setDistance(std::max(lhs.distance(), rhs.distance()));

    if (lhs.intermediateStops().size() == rhs.intermediateStops().size()) {
        auto stops = res.takeIntermediateStops();
        for (uint i = 0; i < stops.size(); ++i) {
            stops[i] = Stopover::merge(stops[i], rhs.intermediateStops()[i]);
        }
        res.setIntermediateStops(std::move(stops));
    }

    res.d->co2Emission = std::max(lhs.d->co2Emission, rhs.d->co2Emission);

    return res;
}

QJsonObject JourneySection::toJson(const JourneySection &section)
{
    auto obj = Json::toJson(section);
    if (section.mode() != Waiting) {
        const auto fromObj = Location::toJson(section.from());
        if (!fromObj.empty()) {
            obj.insert(QStringLiteral("from"), fromObj);
        }
        const auto toObj = Location::toJson(section.to());
        if (!toObj.empty()) {
            obj.insert(QStringLiteral("to"), toObj);
        }
    }
    if (section.mode() == PublicTransport) {
        const auto routeObj = Route::toJson(section.route());
        if (!routeObj.empty()) {
            obj.insert(QStringLiteral("route"), routeObj);
        }
        if (!section.intermediateStops().empty()) {
            obj.insert(QStringLiteral("intermediateStops"), Stopover::toJson(section.intermediateStops()));
        }
    }
    if (section.d->co2Emission < 0) {
        obj.remove(QLatin1String("co2Emission"));
    }

    if (obj.size() <= 3) { // only the disruption and mode enums and distance, ie. this is an empty object
        return {};
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
    section.setIntermediateStops(Stopover::fromJson(obj.value(QLatin1String("intermediateStops")).toArray()));
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

bool Journey::hasExpectedDepartureTime() const
{
    return d->sections.empty() ? false : d->sections.front().hasExpectedDepartureTime();
}

int Journey::departureDelay() const
{
    return d->sections.empty() ? 0 : d->sections.front().departureDelay();
}

QDateTime Journey::scheduledArrivalTime() const
{
    if (!d->sections.empty()) {
        return d->sections.back().scheduledArrivalTime();
    }
    return {};
}

bool Journey::hasExpectedArrivalTime() const
{
    return d->sections.empty() ? false : d->sections.back().hasExpectedArrivalTime();
}

int Journey::arrivalDelay() const
{
    return d->sections.empty() ? 0 : d->sections.back().arrivalDelay();
}

int Journey::duration() const
{
    return scheduledDepartureTime().secsTo(scheduledArrivalTime());
}

int Journey::numberOfChanges() const
{
    return std::max(0, static_cast<int>(std::count_if(d->sections.begin(), d->sections.end(), [](const auto &section) { return section.mode() == JourneySection::PublicTransport; }) - 1));
}

Disruption::Effect Journey::disruptionEffect() const
{
    Disruption::Effect effect = Disruption::NormalService;
    for (const auto &sec : d->sections) {
        effect = std::max(effect, sec.disruptionEffect());
    }
    return effect;
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
    JourneyUtil::applyMetaData(j, false);
    return j;
}

std::vector<Journey> Journey::fromJson(const QJsonArray &array)
{
    return Json::fromJson<Journey>(array);
}

#include "moc_journey.cpp"
