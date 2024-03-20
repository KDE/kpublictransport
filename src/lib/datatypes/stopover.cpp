/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "stopover.h"
#include "datatypes_p.h"
#include "json_p.h"
#include "loadutil_p.h"
#include "mergeutil_p.h"
#include "notesutil_p.h"
#include "platformutils_p.h"
#include "stopoverutil_p.h"

#include <QDateTime>
#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class StopoverPrivate : public QSharedData {
public:
    Disruption::Effect disruptionEffect = Disruption::NormalService;
    QDateTime scheduledArrivalTime;
    QDateTime expectedArrivalTime;
    QDateTime scheduledDepartureTime;
    QDateTime expectedDepartureTime;
    QString scheduledPlatform;
    QString expectedPlatform;
    Route route;
    Location stopPoint;
    QStringList notes;
    std::vector<LoadInfo> loadInformation;
    Vehicle vehicleLayout;
    Platform platformLayout;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(Stopover)
KPUBLICTRANSPORT_MAKE_PROPERTY(Stopover, QDateTime, scheduledArrivalTime, setScheduledArrivalTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(Stopover, QDateTime, expectedArrivalTime, setExpectedArrivalTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(Stopover, QDateTime, scheduledDepartureTime, setScheduledDepartureTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(Stopover, QDateTime, expectedDepartureTime, setExpectedDepartureTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(Stopover, Route, route, setRoute)
KPUBLICTRANSPORT_MAKE_PROPERTY(Stopover, Location, stopPoint, setStopPoint)
KPUBLICTRANSPORT_MAKE_PROPERTY(Stopover, Disruption::Effect, disruptionEffect, setDisruptionEffect)
KPUBLICTRANSPORT_MAKE_PROPERTY(Stopover, QStringList, notes, setNotes)
KPUBLICTRANSPORT_MAKE_PROPERTY(Stopover, Vehicle, vehicleLayout, setVehicleLayout)
KPUBLICTRANSPORT_MAKE_PROPERTY(Stopover, Platform, platformLayout, setPlatformLayout)

bool Stopover::hasExpectedArrivalTime() const
{
    return d->expectedArrivalTime.isValid();
}

int Stopover::arrivalDelay() const
{
    if (hasExpectedArrivalTime()) {
        return d->scheduledArrivalTime.secsTo(d->expectedArrivalTime) / 60;
    }
    return 0;
}

bool Stopover::hasExpectedDepartureTime() const
{
    return d->expectedDepartureTime.isValid();
}

int Stopover::departureDelay() const
{
    if (hasExpectedDepartureTime()) {
        return d->scheduledDepartureTime.secsTo(d->expectedDepartureTime) / 60;
    }
    return 0;
}

QString Stopover::scheduledPlatform() const
{
    return d->scheduledPlatform;
}

void Stopover::setScheduledPlatform(const QString &platform)
{
    d.detach();
    d->scheduledPlatform = PlatformUtils::normalizePlatform(platform);
}

QString Stopover::expectedPlatform() const
{
    return d->expectedPlatform;
}

void Stopover::setExpectedPlatform(const QString &platform)
{
    d.detach();
    d->expectedPlatform = PlatformUtils::normalizePlatform(platform);
}

bool Stopover::hasExpectedPlatform() const
{
    return !d->expectedPlatform.isEmpty();
}

bool Stopover::platformChanged() const
{
    return PlatformUtils::platformChanged(d->scheduledPlatform, d->expectedPlatform);
}

void Stopover::addNote(const QString &note)
{
    const auto n = NotesUtil::normalizeNote(note);
    const auto idx = NotesUtil::needsAdding(d->notes, n);
    if (idx >= 0) {
        d.detach();
        NotesUtil::performAdd(d->notes, n, idx);
    }
}

void Stopover::addNotes(const QStringList &notes)
{
    for (const auto &n : notes) {
        addNote(n);
    }
}

const std::vector<LoadInfo>& Stopover::loadInformation() const
{
    return d->loadInformation;
}

std::vector<LoadInfo>&& Stopover::takeLoadInformation()
{
    d.detach();
    return std::move(d->loadInformation);
}

void Stopover::setLoadInformation(std::vector<LoadInfo> &&loadInfo)
{
    d.detach();
    d->loadInformation = std::move(loadInfo);
}

QVariantList Stopover::loadInformationVariant() const
{
    QVariantList l;
    l.reserve(d->loadInformation.size());
    std::transform(d->loadInformation.begin(), d->loadInformation.end(), std::back_inserter(l), [](const auto &load) { return QVariant::fromValue(load); });
    return l;
}

const std::vector<KPublicTransport::Feature>& Stopover::features() const
{
    return d->vehicleLayout.features();
}

[[nodiscard]] std::vector<KPublicTransport::Feature>&& Stopover::takeFeatures()
{
    return d->vehicleLayout.takeFeatures();
}

void Stopover::setFeatures(std::vector<KPublicTransport::Feature> &&features)
{
    d.detach();
    d->vehicleLayout.setFeatures(std::move(features));
}

void Stopover::applyMetaData(bool download)
{
    auto line = d->route.line();
    line.applyMetaData(stopPoint(), download);
    d->route.setLine(line);
}

bool Stopover::isSame(const Stopover &lhs, const Stopover &rhs)
{
    // same time is mandatory
    const auto departureTimeMatch = lhs.scheduledDepartureTime().isValid()
        && rhs.scheduledDepartureTime().isValid()
        && MergeUtil::distance(lhs.scheduledDepartureTime(), rhs.scheduledDepartureTime()) < 60;
    const auto arrivalTimeMatch = lhs.scheduledArrivalTime().isValid()
        && rhs.scheduledArrivalTime().isValid()
        && MergeUtil::distance(lhs.scheduledArrivalTime(), rhs.scheduledArrivalTime()) < 60;
    if (!departureTimeMatch && !arrivalTimeMatch) {
        return false;
    }

    // same route would be sufficient, if that's not the case, look for other hints
    // this might be the same below
    if (Route::isSame(lhs.route(), rhs.route())) {
        return true;
    }

    // different platform can't be the same train
    if (!lhs.scheduledPlatform().isEmpty() && !rhs.scheduledPlatform().isEmpty() && lhs.scheduledPlatform() != rhs.scheduledPlatform()) {
        return false;
    }

    // same destination and departure time is likely the same route after all
    // TODO we should check for conflicting line names or train types here maybe?
    return (!lhs.route().destination().isEmpty() && !rhs.route().destination().isEmpty() && Location::isSame(lhs.route().destination(), rhs.route().destination()))
        || Location::isSameName(lhs.route().direction(), rhs.route().direction());
}

Stopover Stopover::merge(const Stopover &lhs, const Stopover &rhs)
{
    auto stopover = lhs;

    using namespace MergeUtil;
    stopover.setScheduledDepartureTime(mergeDateTimeEqual(lhs.scheduledDepartureTime(), rhs.scheduledDepartureTime()));
    stopover.setExpectedDepartureTime(mergeDateTimeMax(lhs.expectedDepartureTime(), rhs.expectedDepartureTime()));
    stopover.setScheduledArrivalTime(mergeDateTimeEqual(lhs.scheduledArrivalTime(), rhs.scheduledArrivalTime()));
    stopover.setExpectedArrivalTime(mergeDateTimeMax(lhs.expectedArrivalTime(), rhs.expectedArrivalTime()));

    if (stopover.scheduledPlatform().isEmpty() && !rhs.scheduledPlatform().isEmpty()) {
        stopover.setScheduledPlatform(rhs.scheduledPlatform());
    }
    if (!stopover.hasExpectedPlatform() && rhs.hasExpectedPlatform()) {
        stopover.setExpectedPlatform(rhs.expectedPlatform());
    }

    stopover.setRoute(Route::merge(lhs.route(), rhs.route()));
    stopover.setStopPoint(Location::merge(lhs.stopPoint(), rhs.stopPoint()));
    stopover.setDisruptionEffect(std::max(lhs.disruptionEffect(), rhs.disruptionEffect()));
    stopover.setNotes(NotesUtil::mergeNotes(lhs.notes(), rhs.notes()));
    stopover.d->loadInformation = LoadUtil::merge(lhs.d->loadInformation, rhs.d->loadInformation);
    stopover.d->vehicleLayout = Vehicle::merge(lhs.d->vehicleLayout, rhs.d->vehicleLayout);
    stopover.d->platformLayout = Platform::merge(lhs.d->platformLayout, rhs.d->platformLayout);
    return stopover;
}

QJsonObject Stopover::toJson(const Stopover &stopover)
{
    auto obj = Json::toJson(stopover);
    const auto routeObj = Route::toJson(stopover.route());
    if (!routeObj.empty()) {
        obj.insert(QLatin1String("route"), routeObj);
    }
    const auto locObj = Location::toJson(stopover.stopPoint());
    if (!locObj.empty()) {
        obj.insert(QLatin1String("stopPoint"), locObj);
    }
    if (!stopover.loadInformation().empty()) {
        obj.insert(QLatin1String("load"), LoadInfo::toJson(stopover.loadInformation()));
    }
    if (!stopover.vehicleLayout().isEmpty()) {
        obj.insert(QLatin1String("vehicleLayout"), Vehicle::toJson(stopover.vehicleLayout()));
    }
    if (!stopover.platformLayout().isEmpty()) {
        obj.insert(QLatin1String("platformLayout"), Platform::toJson(stopover.platformLayout()));
    }

    if (obj.size() == 1) { // only the disruption enum, ie. this is an empty object
        return {};
    }
    return obj;
}

QJsonArray Stopover::toJson(const std::vector<Stopover> &deps)
{
    return Json::toJson(deps);
}

Stopover Stopover::fromJson(const QJsonObject &obj)
{
    auto stopover = Json::fromJson<Stopover>(obj);
    stopover.setRoute(Route::fromJson(obj.value(QLatin1String("route")).toObject()));
    stopover.setStopPoint(Location::fromJson(obj.value(QLatin1String("stopPoint")).toObject()));
    stopover.setLoadInformation(LoadInfo::fromJson(obj.value(QLatin1String("load")).toArray()));
    stopover.setVehicleLayout(Vehicle::fromJson(obj.value(QLatin1String("vehicleLayout")).toObject()));
    stopover.setPlatformLayout(Platform::fromJson(obj.value(QLatin1String("platformLayout")).toObject()));
    stopover.applyMetaData(false);
    return stopover;
}

std::vector<Stopover> Stopover::fromJson(const QJsonArray &array)
{
    return Json::fromJson<Stopover>(array);
}

#include "moc_stopover.cpp"
