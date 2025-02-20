/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "journey.h"

#include "identifier_p.h"
#include "journeyutil_p.h"
#include "json_p.h"
#include "datatypes_p.h"
#include "loadutil_p.h"
#include "logging.h"
#include "mergeutil_p.h"
#include "notesutil_p.h"
#include "platformutils_p.h"
#include "rentalvehicle.h"
#include "rentalvehicleutil_p.h"
#include "stopover.h"

#include <KLocalizedString>

#include <QDebug>
#include <QVariant>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

namespace KPublicTransport {

class JourneySectionPrivate : public QSharedData
{
public:
    [[nodiscard]] bool isValidIndex(qsizetype idx) const;

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
    RentalVehicle rentalVehicle;
    Path path;
    Vehicle departureVehicleLayout;
    Platform departurePlatformLayout;
    Vehicle arrivalVehicleLayout;
    Platform arrivalPlatformLayout;
    IndividualTransport individualTransport;
    IdentifierSet ids;
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
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, RentalVehicle, rentalVehicle, setRentalVehicle)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, Path, path, setPath)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, Vehicle, departureVehicleLayout, setDepartureVehicleLayout)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, Platform, departurePlatformLayout, setDeparturePlatformLayout)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, Vehicle, arrivalVehicleLayout, setArrivalVehicleLayout)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, Platform, arrivalPlatformLayout, setArrivalPlatformLayout)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneySection, KPublicTransport::IndividualTransport, individualTransport, setIndividualTransport)

bool JourneySectionPrivate::isValidIndex(qsizetype idx) const
{
    return idx >= 0 && idx <= (qsizetype)(intermediateStops.size()) + 1;
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

    double dist = 0;
    if (d->from.hasCoordinate() && d->to.hasCoordinate()) {
        auto startLat = d->from.latitude();
        auto  startLon = d->from.longitude();

        for (const auto &stop : d->intermediateStops) {
            if (!stop.stopPoint().hasCoordinate()) {
                continue;
            }
            dist += Location::distance(startLat, startLon, stop.stopPoint().latitude(), stop.stopPoint().longitude());
            startLat = stop.stopPoint().latitude();
            startLon = stop.stopPoint().longitude();
        }

        dist += Location::distance(startLat, startLon, d->to.latitude(), d->to.longitude());
    }
    dist = std::max<double>(dist, d->path.distance());
    return std::max((int)std::round(dist), d->distance);
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
    d.detach();
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
    dep.setDisruptionEffect(disruptionEffect());
    dep.setVehicleLayout(departureVehicleLayout());
    dep.setPlatformLayout(departurePlatformLayout());
    return dep;
}

void JourneySection::setDeparture(const Stopover &departure)
{
    setFrom(departure.stopPoint());
    setScheduledDepartureTime(departure.scheduledDepartureTime());
    setExpectedDepartureTime(departure.expectedDepartureTime());
    setScheduledDeparturePlatform(departure.scheduledPlatform());
    setExpectedDeparturePlatform(departure.expectedPlatform());
    setDeparturePlatformLayout(departure.platformLayout());
    setDepartureVehicleLayout(departure.vehicleLayout());
    if (departure.disruptionEffect() == Disruption::NoService) {
        setDisruptionEffect(departure.disruptionEffect());
    }
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
    arr.setDisruptionEffect(disruptionEffect());
    arr.setVehicleLayout(arrivalVehicleLayout());
    arr.setPlatformLayout(arrivalPlatformLayout());
    return arr;
}

void JourneySection::setArrival(const Stopover &arrival)
{
    setTo(arrival.stopPoint());
    setScheduledArrivalTime(arrival.scheduledArrivalTime());
    setExpectedArrivalTime(arrival.expectedArrivalTime());
    setScheduledArrivalPlatform(arrival.scheduledPlatform());
    setExpectedArrivalPlatform(arrival.expectedPlatform());
    setArrivalPlatformLayout(arrival.platformLayout());
    setArrivalVehicleLayout(arrival.vehicleLayout());
    if (arrival.disruptionEffect() == Disruption::NoService) {
        setDisruptionEffect(arrival.disruptionEffect());
    }
}

struct {
    Line::Mode mode;
    int gramPerKm;
} static constexpr const emissionForModeMap[] = {
    { Line::Air, 285 },
    { Line::Boat, 245 },
    { Line::Bus, 68 },
    { Line::Coach, 68 },
    { Line::Ferry, 245 },
    // { Line::Funicular, -1 }, TODO
    { Line::LocalTrain, 14 },
    { Line::LongDistanceTrain, 14 },
    { Line::Metro, 11 },
    { Line::RailShuttle, 11 }, // assuming tram/rapid transit-like
    { Line::RapidTransit, 11 },
    { Line::Shuttle, 68 },
    { Line::Taxi, 158 },
    { Line::Train, 14 },
    { Line::Tramway, 11 },
    { Line::RideShare, 158 },
    // { Line::AerialLift, -1 }, TODO
};

struct {
    IndividualTransport::Mode mode;
    int gramPerKm;
} static constexpr const emissionForIvModeMap[] = {
    { IndividualTransport::Walk, 0 },
    { IndividualTransport::Bike, 0 },
    { IndividualTransport::Car, 158 }
};

struct {
    RentalVehicle::VehicleType mode;
    int gramPerKm;
} static constexpr const emissionForRvModeMap[] = {
    { RentalVehicle::Bicycle, 0 },
    // { RentalVehicle::Pedelec, -1 }, TODO
    // { RentalVehicle::ElectricKickScooter, -1 }, TODO
    // { RentalVehicle::ElectricMoped, -1 }, TODO
    { RentalVehicle::Car, 158 },
};

int JourneySection::co2Emission() const
{
    if (d->co2Emission >= 0) {
        return d->co2Emission;
    }

    switch (d->mode) {
        case JourneySection::Invalid:
            return -1;
        case JourneySection::Walking:
        case JourneySection::Transfer:
        case JourneySection::Waiting:
            return 0;
        case JourneySection::PublicTransport:
        {
            const auto mode = route().line().mode();
            for (const auto &map : emissionForModeMap) {
                if (map.mode == mode) {
                    return (map.gramPerKm * distance()) / 1000;
                }
            }
            qCDebug(Log) << "No CO2 emission estimate for mode" << mode;
            return -1;
        }
        case JourneySection::IndividualTransport:
        {
            const auto mode = individualTransport().mode();
            for (const auto &map :emissionForIvModeMap) {
                if (map.mode == mode) {
                    return (map.gramPerKm *distance()) / 1000;
                }
            }
            qCDebug(Log) << "No CO2 emission estimate for mode" << mode;
            return -1;
        }
        case JourneySection::RentedVehicle:
        {
            const auto mode = rentalVehicle().type();
            for (const auto &map :emissionForRvModeMap) {
                if (map.mode == mode) {
                    return (map.gramPerKm *distance()) / 1000;
                }
            }
            qCDebug(Log) << "No CO2 emission estimate for vehicle type" << mode;
            return -1;
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

QList<LoadInfo> JourneySection::loadInformationList() const
{
    QList<LoadInfo> l;
    l.reserve((qsizetype)d->loadInformation.size());
    std::copy(d->loadInformation.begin(), d->loadInformation.end(), std::back_inserter(l));
    return l;
}

void JourneySection::setLoadInformationList(const QList<LoadInfo> &loadInfo)
{
    d->loadInformation.clear();
    d->loadInformation.reserve(loadInfo.size());
    std::copy(loadInfo.begin(), loadInfo.end(), std::back_inserter(d->loadInformation));
}

const std::vector<KPublicTransport::Feature>& JourneySection::features() const
{
    return d->departureVehicleLayout.features();
}

[[nodiscard]] std::vector<KPublicTransport::Feature>&& JourneySection::takeFeatures()
{
    return d->departureVehicleLayout.takeFeatures();
}

void JourneySection::setFeatures(std::vector<KPublicTransport::Feature> &&features)
{
    d.detach();
    d->departureVehicleLayout.setFeatures(std::move(features));
}

QString JourneySection::iconName() const
{
    switch (d->mode) {
        case JourneySection::Invalid:
            return {};
        case JourneySection::PublicTransport:
            return d->route.line().iconName();
        case JourneySection::RentedVehicle:
            return d->rentalVehicle.vehicleTypeIconName();
        case JourneySection::IndividualTransport:
            return d->individualTransport.modeIconName();
        case JourneySection::Transfer:
        case JourneySection::Walking:
        case JourneySection::Waiting:
            break;
    }

    return modeIconName(d->mode);
}

QString JourneySection::modeIconName(JourneySection::Mode mode)
{
    switch (mode) {
        case JourneySection::Invalid:
            return {};
        case JourneySection::PublicTransport:
            return Line::modeIconName(Line::Train);
        case JourneySection::Transfer:
            return u"qrc:///org.kde.kpublictransport/assets/images/journey-mode-transfer.svg"_s;
        case JourneySection::Walking:
            return IndividualTransport::modeIconName(IndividualTransport::Walk);
        case JourneySection::Waiting:
            return u"qrc:///org.kde.kpublictransport/assets/images/journey-mode-wait.svg"_s;
        case JourneySection::RentedVehicle:
            return RentalVehicle::vehicleTypeIconName(RentalVehicle::ElectricKickScooter);
        case JourneySection::IndividualTransport:
            return IndividualTransport::modeIconName(IndividualTransport::Bike);
    }

    return u"question"_s;
}

QString JourneySection::label() const
{
    switch (mode()) {
    case JourneySection::Invalid:
        break;
    case JourneySection::PublicTransport:
        return route().line().name();
    case JourneySection::Walking:
        return i18nc("mode of individual transport", "Walk");
    case JourneySection::Waiting:
        return i18n("Wait");
    case JourneySection::Transfer:
        break; // ?
    case JourneySection::RentedVehicle:
        return rentalVehicle().label();
    case JourneySection::IndividualTransport:
        return individualTransport().label();
    }

    return {};
}

Load::Category JourneySection::maximumOccupancy() const
{
    return std::accumulate(d->loadInformation.begin(), d->loadInformation.end(), Load::Unknown, [](auto l, const auto &info) {
        return std::max(l, info.load());
    });
}

QString JourneySection::identifier(QAnyStringView identifierType) const
{
    return d->ids.identifier(identifierType);
}

bool JourneySection::hasIdentifier(QAnyStringView identifierType) const
{
    return d->ids.hasIdentifier(identifierType);
}

void JourneySection::setIdentifier(const QString &identifierType, const QString &id)
{
    d.detach();
    d->ids.setIdentifier(identifierType, id);
}

bool JourneySection::hasIdentifiers() const
{
    return !d->ids.isEmpty();
}

Stopover JourneySection::stopover(qsizetype idx) const
{
    if (!d->isValidIndex(idx)) {
        return {};
    }

    if (idx == 0) {
        return departure();
    }
    if (idx <= (qsizetype)d->intermediateStops.size()) {
        return d->intermediateStops[idx - 1];
    }
    return arrival();
}

void JourneySection::setStopovver(qsizetype idx, const Stopover &stop)
{
    if (!d->isValidIndex(idx)) {
        return;
    }

    if (idx == 0) {
        setDeparture(stop);
    } else if (idx <= (qsizetype)d->intermediateStops.size()) {
        d.detach();
        d->intermediateStops[idx - 1] = stop;
    } else {
        setArrival(stop);
    }
}

qsizetype JourneySection::indexOfStopover(const Stopover &stop) const
{
    if (Stopover::isSame(departure(), stop)) {
        return 0;
    }
    if (const auto it = std::ranges::find_if(d->intermediateStops, [&stop](const auto &s) { return Stopover::isSame(s, stop); }); it != d->intermediateStops.end()) {
        return std::distance(d->intermediateStops.begin(), it) + 1;
    }
    if (Stopover::isSame(arrival(), stop)) {
        return (qsizetype)d->intermediateStops.size() + 1;
    }
    return -1;
}

JourneySection JourneySection::subsection(qsizetype begin, qsizetype end) const
{
    if (!d->isValidIndex(begin) || !d->isValidIndex(end) || end <= begin) {
        return {};
    }

    auto partialTrip = *this;
    if (begin > 0) {
        partialTrip.setDeparture(stopover(begin));
    }
    if (end <= (qsizetype)d->intermediateStops.size()) {
        partialTrip.setArrival(stopover(end));
    }

    const auto beginIt = d->intermediateStops.begin() + std::max<qsizetype>(0, begin);
    const auto endIt = beginIt + std::max<qsizetype>(0, end - begin - 1);
    partialTrip.setIntermediateStops({beginIt, endIt});

    auto path = d->path;
    auto pathSections = path.takeSections();

    // find the closest points on the path to the departure/arrival locations
    // we have to expect aribitrarly broken/imprecise data here...
    qsizetype beginSection = -1, beginPoint = -1, endSection = -1, endPoint = -1;
    double beginMinDist = std::numeric_limits<double>::max(), endMinDist = std::numeric_limits<double>::max();
    for (std::size_t i = 0; i < pathSections.size(); ++i) {
        const auto poly = pathSections[i].path();
        for (qsizetype j = 0; j < poly.size(); ++j) {
            const auto p = poly[j];
            if (const auto d = Location::distance(p.y(), p.x(), partialTrip.from().latitude(), partialTrip.from().longitude()); d <beginMinDist) {
                beginSection = (qsizetype)i;
                beginPoint = j;
                beginMinDist = d;
            }
            if (const auto d = Location::distance(p.y(), p.x(), partialTrip.to().latitude(), partialTrip.to().longitude()); d <endMinDist) {
                endSection = (qsizetype)i;
                endPoint = j;
                endMinDist = d;
            }
        }
    }

    // if we found something, truncate path accordingly
    if (std::tie(beginSection, beginPoint) < std::tie(endSection, endPoint)) {
        // start cutting from the end, as otherwise the end indices become invalid!
        pathSections.erase(pathSections.begin() + endSection + 1, pathSections.end());
        pathSections.erase(pathSections.begin(), pathSections.begin() + beginSection);

        auto poly = pathSections.back().path();
        poly.erase(poly.begin() + endPoint + 1, poly.end());
        pathSections.back().setPath(poly);

        poly = pathSections.front().path();
        poly.erase(poly.begin(), poly.begin() + beginPoint);
        pathSections.front().setPath(poly);

        path.setSections(std::move(pathSections));
        partialTrip.setPath(path);
    }

    return partialTrip;
}

void JourneySection::applyMetaData(bool download)
{
    if (!from().hasCoordinate() || mode() != JourneySection::PublicTransport) {
        return;
    }
    auto line = d->route.line();
    line.applyMetaData(from(), download);
    d->route.setLine(line);

    // propagate to intermediate stops
    for (auto &stop : d->intermediateStops) {
        stop.setRoute(d->route);
    }
}

bool JourneySection::isSame(const JourneySection &lhs, const JourneySection &rhs)
{
    if (lhs.d->mode != rhs.d->mode) {
        return false;
    }

    if (lhs.d->mode == JourneySection::IndividualTransport && lhs.d->individualTransport != rhs.d->individualTransport) {
        return false;
    }

    switch (lhs.d->ids.compare(rhs.d->ids)) {
        case IdentifierSet::NotEqual: return false;
        case IdentifierSet::Equal: // same trip id can still mean diffierent departure/arrival stops
        case IdentifierSet::NoIntersection: break;
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
    res.d->ids.merge(rhs.d->ids);
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
    res.setDistance(std::max(lhs.d->distance, rhs.d->distance));

    if (lhs.intermediateStops().size() == rhs.intermediateStops().size()) {
        auto stops = res.takeIntermediateStops();
        for (uint i = 0; i < stops.size(); ++i) {
            stops[i] = Stopover::merge(stops[i], rhs.intermediateStops()[i]);
            stops[i].setRoute(res.route());
        }
        res.setIntermediateStops(std::move(stops));
    } else if (lhs.intermediateStops().empty() && !rhs.intermediateStops().empty()) {
        res.setIntermediateStops(std::vector<Stopover>(rhs.intermediateStops()));
    } else if (!lhs.intermediateStops().empty() && rhs.intermediateStops().empty()) {
        res.setIntermediateStops(std::vector<Stopover>(lhs.intermediateStops()));
    }

    res.d->co2Emission = std::max(lhs.d->co2Emission, rhs.d->co2Emission);
    res.d->loadInformation = LoadUtil::merge(lhs.d->loadInformation, rhs.d->loadInformation);
    res.d->rentalVehicle = RentalVehicleUtil::merge(lhs.d->rentalVehicle, rhs.d->rentalVehicle);

    res.d->path = lhs.d->path.sections().size() < rhs.d->path.sections().size() ? rhs.d->path : lhs.d->path;

    res.d->departureVehicleLayout = Vehicle::merge(lhs.d->departureVehicleLayout, rhs.d->departureVehicleLayout);
    res.d->departurePlatformLayout = Platform::merge(lhs.d->departurePlatformLayout, rhs.d->departurePlatformLayout);
    res.d->arrivalVehicleLayout = Vehicle::merge(lhs.d->arrivalVehicleLayout, rhs.d->arrivalVehicleLayout);
    res.d->arrivalPlatformLayout = Platform::merge(lhs.d->arrivalPlatformLayout, rhs.d->arrivalPlatformLayout);

    return res;
}

QJsonObject JourneySection::toJson(const JourneySection &section)
{
    auto obj = Json::toJson(section);
    if (!section.d->ids.isEmpty()) {
        obj.insert("identifiers"_L1, section.d->ids.toJson());
    }
    if (section.mode() != Waiting) {
        const auto fromObj = Location::toJson(section.from());
        if (!fromObj.empty()) {
            obj.insert(QLatin1String("from"), fromObj);
        }
        const auto toObj = Location::toJson(section.to());
        if (!toObj.empty()) {
            obj.insert(QLatin1String("to"), toObj);
        }
    }
    if (section.mode() == PublicTransport) {
        const auto routeObj = Route::toJson(section.route());
        if (!routeObj.empty()) {
            obj.insert(QLatin1String("route"), routeObj);
        }
        if (!section.intermediateStops().empty()) {
            obj.insert(QLatin1String("intermediateStops"), Stopover::toJson(section.intermediateStops()));
        }
        if (!section.loadInformation().empty()) {
            obj.insert(QLatin1String("load"), LoadInfo::toJson(section.loadInformation()));
        }
    }
    if (section.d->distance <= 0) {
        obj.remove("distance"_L1);
    }
    if (section.d->co2Emission < 0) {
        obj.remove(QLatin1String("co2Emission"));
    }
    if (section.rentalVehicle().type() != RentalVehicle::Unknown) {
        obj.insert(QLatin1String("rentalVehicle"), RentalVehicle::toJson(section.rentalVehicle()));
    }

    if (!section.path().isEmpty()) {
        obj.insert(QLatin1String("path"), Path::toJson(section.path()));
    }

    if (!section.departureVehicleLayout().isEmpty()) {
        obj.insert(QLatin1String("departureVehicleLayout"), Vehicle::toJson(section.departureVehicleLayout()));
    }
    if (!section.departurePlatformLayout().isEmpty()) {
        obj.insert(QLatin1String("departurePlatformLayout"), Platform::toJson(section.departurePlatformLayout()));
    }
    if (!section.arrivalVehicleLayout().isEmpty()) {
        obj.insert(QLatin1String("arrivalVehicleLayout"), Vehicle::toJson(section.arrivalVehicleLayout()));
    }
    if (!section.arrivalPlatformLayout().isEmpty()) {
        obj.insert(QLatin1String("arrivalPlatformLayout"), Platform::toJson(section.arrivalPlatformLayout()));
    }

    if (section.mode() == JourneySection::IndividualTransport) {
        obj.insert(QLatin1String("individualTransport"), IndividualTransport::toJson(section.individualTransport()));
    }

    if (obj.size() <= 2) { // only the disruption and mode enums, ie. this is an empty object
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
    section.d->ids.fromJson(obj.value("identifiers"_L1).toObject());
    section.setFrom(Location::fromJson(obj.value(QLatin1String("from")).toObject()));
    section.setTo(Location::fromJson(obj.value(QLatin1String("to")).toObject()));
    section.setRoute(Route::fromJson(obj.value(QLatin1String("route")).toObject()));
    section.setIntermediateStops(Stopover::fromJson(obj.value(QLatin1String("intermediateStops")).toArray()));
    section.setLoadInformation(LoadInfo::fromJson(obj.value(QLatin1String("load")).toArray()));
    section.setRentalVehicle(RentalVehicle::fromJson(obj.value(QLatin1String("rentalVehicle")).toObject()));
    section.setPath(Path::fromJson(obj.value(QLatin1String("path")).toObject()));
    section.setDepartureVehicleLayout(Vehicle::fromJson(obj.value(QLatin1String("departureVehicleLayout")).toObject()));
    section.setDeparturePlatformLayout(Platform::fromJson(obj.value(QLatin1String("departurePlatformLayout")).toObject()));
    section.setArrivalVehicleLayout(Vehicle::fromJson(obj.value(QLatin1String("arrivalVehicleLayout")).toObject()));
    section.setArrivalPlatformLayout(Platform::fromJson(obj.value(QLatin1String("arrivalPlatformLayout")).toObject()));
    section.setIndividualTransport(IndividualTransport::fromJson(obj.value(QLatin1String("individualTransport")).toObject()));
    section.applyMetaData(false);
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
    d.detach();
    return std::move(d->sections);
}

void Journey::setSections(std::vector<JourneySection> &&sections)
{
    d.detach();
    d->sections = std::move(sections);
}

QList<JourneySection> Journey::sectionsList() const
{
    QList<JourneySection> l;
    l.reserve((qsizetype)d->sections.size());
    std::copy(d->sections.begin(), d->sections.end(), std::back_inserter(l));
    return l;
}

void Journey::setSectionsList(const QList<JourneySection> &sections)
{
    d->sections.clear();
    d->sections.reserve(sections.size());
    std::copy(sections.begin(), sections.end(), std::back_inserter(d->sections));
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

QDateTime Journey::expectedDepartureTime() const
{
    return d->sections.empty() ? QDateTime() : d->sections.front().expectedDepartureTime();
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

QDateTime Journey::expectedArrivalTime() const
{
    return d->sections.empty() ? QDateTime() : d->sections.back().expectedArrivalTime();
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

int Journey::distance() const
{
    return std::accumulate(d->sections.begin(), d->sections.end(), 0, [](auto dist, const auto &jny) { return dist + jny.distance(); });
}

int Journey::co2Emission() const
{
    return std::accumulate(d->sections.begin(), d->sections.end(), 0, [](auto co2, const auto &jny) { return co2 + std::max(0, jny.co2Emission()); });
}

Load::Category Journey::maximumOccupancy() const
{
    return std::accumulate(d->sections.begin(), d->sections.end(), Load::Unknown, [](auto l, const auto &jny) {
        return std::max(l, jny.maximumOccupancy());
    });
}

void Journey::applyMetaData(bool download)
{
    for (auto &sec : d->sections) {
        sec.applyMetaData(download);
    }
}

static bool isTransportSection(JourneySection::Mode mode)
{
    return mode == JourneySection::PublicTransport
        || mode == JourneySection::RentedVehicle
        || mode == JourneySection::IndividualTransport;
}

bool Journey::isSame(const Journey &lhs, const Journey &rhs)
{
    auto lIt = lhs.sections().begin();
    auto rIt = rhs.sections().begin();

    while (lIt != lhs.sections().end() || rIt != rhs.sections().end()) {
        // ignore non-transport sections
        if (lIt != lhs.sections().end() && !isTransportSection((*lIt).mode())) {
            ++lIt;
            continue;
        }
        if (rIt != rhs.sections().end() && !isTransportSection((*rIt).mode())) {
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
    obj.insert(QLatin1String("sections"), JourneySection::toJson(journey.sections()));
    return obj;
}

QJsonArray Journey::toJson(const std::vector<Journey> &journeys)
{
    return Json::toJson(journeys);
}

Journey Journey::fromJson(const QJsonObject &obj)
{
    Journey j;
    j.setSections(JourneySection::fromJson(obj.value(QLatin1String("sections")).toArray()));
    return j;
}

std::vector<Journey> Journey::fromJson(const QJsonArray &array)
{
    return Json::fromJson<Journey>(array);
}

#include "moc_journey.cpp"
