/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#include "opentripplannerparser.h"
#include "gtfs/hvt.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

using namespace KPublicTransport;

static Location parseLocation(const QJsonObject &obj)
{
    Location loc;
    loc.setName(obj.value(QLatin1String("name")).toString());
    loc.setLatitude(obj.value(QLatin1String("lat")).toDouble());
    loc.setLongitude(obj.value(QLatin1String("lon")).toDouble());
    // TODO time zone
    // TODO recursion into parent station
    // TODO gtfs id
    return loc;
}

static Line parseLine(const QJsonObject &obj)
{
    Line line;
    // TODO alerts need to be propagated to journey section / departure
    line.setName(obj.value(QLatin1String("shortName")).toString());
    line.setMode(Gtfs::Hvt::typeToMode(obj.value(QLatin1String("type")).toInt()));
    // TODO parse color
    return line;
}

static Route parseRoute(const QJsonObject &obj)
{
    Route route;
    route.setLine(parseLine(obj.value(QLatin1String("route")).toObject()));
    route.setDirection(obj.value(QLatin1String("tripHeadsign")).toString());
    return route;
}

static Departure parseDeparture(const QJsonObject &obj)
{
    Departure dep;
    const auto baseTime = obj.value(QLatin1String("serviceDay")).toDouble(); // ### 64bit
    dep.setScheduledArrivalTime(QDateTime::fromSecsSinceEpoch(baseTime + obj.value(QLatin1String("scheduledArrival")).toDouble()));
    dep.setScheduledDepartureTime(QDateTime::fromSecsSinceEpoch(baseTime + obj.value(QLatin1String("scheduledDeparture")).toDouble()));
    if (obj.value(QLatin1String("realtime")).toBool()) {
        dep.setExpectedArrivalTime(QDateTime::fromSecsSinceEpoch(baseTime + obj.value(QLatin1String("realtimeArrival")).toDouble()));
        dep.setExpectedDepartureTime(QDateTime::fromSecsSinceEpoch(baseTime + obj.value(QLatin1String("realtimeDeparture")).toDouble()));
    }
    dep.setScheduledPlatform(obj.value(QLatin1String("stop")).toObject().value(QLatin1String("platformCode")).toString());
    dep.setRoute(parseRoute(obj.value(QLatin1String("trip")).toObject()));
    return dep;
}

static void parseDeparturesForStop(const QJsonObject &obj, std::vector<Departure> &deps)
{
    const auto loc = parseLocation(obj.value(QLatin1String("stop")).toObject());
    const auto stopTimes = obj.value(QLatin1String("stoptimes")).toArray();
    for (const auto &stopTime : stopTimes) {
        auto dep = parseDeparture(stopTime.toObject());
        dep.setStopPoint(loc);
        deps.push_back(dep);
    }
}

std::vector<Departure> OpenTripPlannerParser::parseDepartures(const QJsonObject &obj)
{
    std::vector<Departure> deps;

    const auto depsArray = obj.value(QLatin1String("nearest")).toObject().value(QLatin1String("edges")).toArray();
    for (const auto &depsV : depsArray) {
        parseDeparturesForStop(depsV.toObject().value(QLatin1String("node")).toObject().value(QLatin1String("place")).toObject(), deps);
    }

    return deps;
}

static JourneySection parseJourneySection(const QJsonObject &obj)
{
    JourneySection section;
    section.setScheduledDepartureTime(QDateTime::fromMSecsSinceEpoch(obj.value(QLatin1String("startTime")).toDouble())); // ### sic! double to get 64 bit precision...
    section.setScheduledArrivalTime(QDateTime::fromMSecsSinceEpoch(obj.value(QLatin1String("endTime")).toDouble()));
    if (obj.value(QLatin1String("realTime")).toBool()) {
        // TODO
    }
    section.setFrom(parseLocation(obj.value(QLatin1String("from")).toObject())); // TODO handle the nested structure correctly, TODO parse platforms
    section.setTo(parseLocation(obj.value(QLatin1String("to")).toObject()));
    section.setDistance(obj.value(QLatin1String("distance")).toDouble());

    if (obj.value(QLatin1String("transitLeg")).toBool()) {
        section.setMode(JourneySection::PublicTransport);
        section.setRoute(parseRoute(obj.value(QLatin1String("trip")).toObject()));
    } else {
        section.setMode(JourneySection::Walking);
    }

    return section;
}

static Journey parseJourney(const QJsonObject &obj)
{
    std::vector<JourneySection> sections;
    const auto sectionsArray = obj.value(QLatin1String("legs")).toArray();
    for (const auto &sectionObj : sectionsArray) {
        sections.push_back(parseJourneySection(sectionObj.toObject()));
    }

    Journey journey;
    journey.setSections(std::move(sections));
    return journey;
}

std::vector<Journey> OpenTripPlannerParser::parseJourneys(const QJsonObject& obj)
{
    std::vector<Journey> journeys;

    const auto journeysArray = obj.value(QLatin1String("plan")).toObject().value(QLatin1String("itineraries")).toArray();
    journeys.reserve(journeysArray.size());
    for (const auto &journeyObj : journeysArray) {
        journeys.push_back(parseJourney(journeyObj.toObject()));
    }

    return journeys;
}
