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

#include "departure.h"
#include "datatypes_p.h"
#include "json_p.h"
#include "mergeutil_p.h"
#include "notesutil_p.h"
#include "platformutils_p.h"

#include <QDateTime>
#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class DeparturePrivate : public QSharedData {
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
};
}

KPUBLICTRANSPORT_MAKE_GADGET(Departure)
KPUBLICTRANSPORT_MAKE_PROPERTY(Departure, QDateTime, scheduledArrivalTime, setScheduledArrivalTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(Departure, QDateTime, expectedArrivalTime, setExpectedArrivalTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(Departure, QDateTime, scheduledDepartureTime, setScheduledDepartureTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(Departure, QDateTime, expectedDepartureTime, setExpectedDepartureTime)
KPUBLICTRANSPORT_MAKE_PROPERTY(Departure, Route, route, setRoute)
KPUBLICTRANSPORT_MAKE_PROPERTY(Departure, Location, stopPoint, setStopPoint)
KPUBLICTRANSPORT_MAKE_PROPERTY(Departure, Disruption::Effect, disruptionEffect, setDisruptionEffect)
KPUBLICTRANSPORT_MAKE_PROPERTY(Departure, QStringList, notes, setNotes)

bool Departure::hasExpectedArrivalTime() const
{
    return d->expectedArrivalTime.isValid();
}

int Departure::arrivalDelay() const
{
    if (hasExpectedArrivalTime()) {
        return d->scheduledArrivalTime.secsTo(d->expectedArrivalTime) / 60;
    }
    return 0;
}

bool Departure::hasExpectedDepartureTime() const
{
    return d->expectedDepartureTime.isValid();
}

int Departure::departureDelay() const
{
    if (hasExpectedDepartureTime()) {
        return d->scheduledDepartureTime.secsTo(d->expectedDepartureTime) / 60;
    }
    return 0;
}

QString Departure::scheduledPlatform() const
{
    return d->scheduledPlatform;
}

void Departure::setScheduledPlatform(const QString &platform)
{
    d.detach();
    d->scheduledPlatform = PlatformUtils::normalizePlatform(platform);
}

QString Departure::expectedPlatform() const
{
    return d->expectedPlatform;
}

void Departure::setExpectedPlatform(const QString &platform)
{
    d.detach();
    d->expectedPlatform = PlatformUtils::normalizePlatform(platform);
}

bool Departure::hasExpectedPlatform() const
{
    return !d->expectedPlatform.isEmpty();
}

bool Departure::platformChanged() const
{
    return PlatformUtils::platformChanged(d->scheduledPlatform, d->expectedPlatform);
}

void Departure::addNote(const QString &note)
{
    const auto n = NotesUtil::normalizeNote(note);
    const auto idx = NotesUtil::needsAdding(d->notes, n);
    if (idx >= 0) {
        d.detach();
        NotesUtil::performAdd(d->notes, n, idx);
    }
}

void Departure::addNotes(const QStringList &notes)
{
    for (const auto &n : notes) {
        addNote(n);
    }
}

bool Departure::isSame(const Departure &lhs, const Departure &rhs)
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
    return Location::isSameName(lhs.route().direction(), rhs.route().direction());
}

Departure Departure::merge(const Departure &lhs, const Departure &rhs)
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
    return dep;
}

QJsonObject Departure::toJson(const Departure &dep)
{
    auto obj = Json::toJson(dep);
    obj.insert(QStringLiteral("route"), Route::toJson(dep.route()));
    obj.insert(QStringLiteral("stopPoint"), Location::toJson(dep.stopPoint()));
    return obj;
}

QJsonArray Departure::toJson(const std::vector<Departure> &deps)
{
    return Json::toJson(deps);
}

Departure Departure::fromJson(const QJsonObject &obj)
{
    auto dep = Json::fromJson<Departure>(obj);
    dep.setRoute(Route::fromJson(obj.value(QLatin1String("route")).toObject()));
    dep.setStopPoint(Location::fromJson(obj.value(QLatin1String("stopPoint")).toObject()));
    return dep;
}

#include "moc_departure.cpp"
