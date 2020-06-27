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
    auto dep = lhs;

    using namespace MergeUtil;
    dep.setScheduledDepartureTime(mergeDateTimeEqual(lhs.scheduledDepartureTime(), rhs.scheduledDepartureTime()));
    dep.setExpectedDepartureTime(mergeDateTimeMax(lhs.expectedDepartureTime(), rhs.expectedDepartureTime()));
    dep.setScheduledArrivalTime(mergeDateTimeEqual(lhs.scheduledArrivalTime(), rhs.scheduledArrivalTime()));
    dep.setExpectedArrivalTime(mergeDateTimeMax(lhs.expectedArrivalTime(), rhs.expectedArrivalTime()));

    if (dep.scheduledPlatform().isEmpty() && !rhs.scheduledPlatform().isEmpty()) {
        dep.setScheduledPlatform(rhs.scheduledPlatform());
    }
    if (!dep.hasExpectedPlatform() && rhs.hasExpectedPlatform()) {
        dep.setExpectedPlatform(rhs.expectedPlatform());
    }

    dep.setRoute(Route::merge(lhs.route(), rhs.route()));
    dep.setStopPoint(Location::merge(lhs.stopPoint(), rhs.stopPoint()));
    dep.setDisruptionEffect(std::max(lhs.disruptionEffect(), rhs.disruptionEffect()));
    dep.setNotes(NotesUtil::mergeNotes(lhs.notes(), rhs.notes()));
    dep.d->loadInformation = LoadUtil::merge(lhs.d->loadInformation, rhs.d->loadInformation);
    return dep;
}

QJsonObject Stopover::toJson(const Stopover &dep)
{
    auto obj = Json::toJson(dep);
    const auto routeObj = Route::toJson(dep.route());
    if (!routeObj.empty()) {
        obj.insert(QStringLiteral("route"), routeObj);
    }
    const auto locObj = Location::toJson(dep.stopPoint());
    if (!locObj.empty()) {
        obj.insert(QStringLiteral("stopPoint"), locObj);
    }
    if (!dep.loadInformation().empty()) {
        obj.insert(QStringLiteral("load"), LoadInfo::toJson(dep.loadInformation()));
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
    auto dep = Json::fromJson<Stopover>(obj);
    dep.setRoute(Route::fromJson(obj.value(QLatin1String("route")).toObject()));
    dep.setStopPoint(Location::fromJson(obj.value(QLatin1String("stopPoint")).toObject()));
    dep.setLoadInformation(LoadInfo::fromJson(obj.value(QLatin1String("load")).toArray()));
    StopoverUtil::applyMetaData(dep, false);
    return dep;
}

std::vector<Stopover> Stopover::fromJson(const QJsonArray &array)
{
    return Json::fromJson<Stopover>(array);
}

#include "moc_stopover.cpp"
