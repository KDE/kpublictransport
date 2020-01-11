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

#include <KPublicTransport/Departure>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

using namespace KPublicTransport;

OpenTripPlannerParser::OpenTripPlannerParser(const QString &identifierType)
    : m_identifierType(identifierType)
{
}

OpenTripPlannerParser::~OpenTripPlannerParser() = default;

Location OpenTripPlannerParser::parseLocation(const QJsonObject &obj) const
{
    const auto parentObj = obj.value(QLatin1String("parentStation")).toObject();
    if (!parentObj.isEmpty()) {
        return parseLocation(parentObj);
    }

    Location loc;
    loc.setName(obj.value(QLatin1String("name")).toString());
    loc.setLatitude(obj.value(QLatin1String("lat")).toDouble());
    loc.setLongitude(obj.value(QLatin1String("lon")).toDouble());
    // TODO time zone

    const auto id = obj.value(QLatin1String("gtfsId")).toString();
    if (!id.isEmpty()) {
        loc.setIdentifier(m_identifierType, id);
    }
    return loc;
}

std::vector<Location> OpenTripPlannerParser::parseLocationsByCoordinate(const QJsonObject &obj) const
{
    std::vector<Location> locs;
    const auto stopArray = obj.value(QLatin1String("stopsByRadius")).toObject().value(QLatin1String("edges")).toArray();
    locs.reserve(stopArray.size());
    for (const auto &stop : stopArray) {
        locs.push_back(parseLocation(stop.toObject().value(QLatin1String("node")).toObject().value(QLatin1String("stop")).toObject()));
    }

    // deduplicate elements, which we get due to searching for stops rather than stations
    std::stable_sort(locs.begin(), locs.end(), [this](const auto &lhs, const auto &rhs) {
        return lhs.identifier(m_identifierType) < rhs.identifier(m_identifierType);
    });
    locs.erase(std::unique(locs.begin(), locs.end(), [this](const auto &lhs, const auto &rhs) {
        return lhs.identifier(m_identifierType) == rhs.identifier(m_identifierType);
    }), locs.end());

    return locs;
}

std::vector<Location> OpenTripPlannerParser::parseLocationsByName(const QJsonObject &obj) const
{
    std::vector<Location> locs;
    const auto stationArray = obj.value(QLatin1String("stations")).toArray();
    locs.reserve(stationArray.size());
    for (const auto &station : stationArray) {
        locs.push_back(parseLocation(station.toObject()));
    }
    return locs;
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

void OpenTripPlannerParser::parseDeparturesForStop(const QJsonObject &obj, std::vector<Departure> &deps) const
{
    const auto loc = parseLocation(obj.value(QLatin1String("stop")).toObject());
    const auto stopTimes = obj.value(QLatin1String("stoptimes")).toArray();
    for (const auto &stopTime : stopTimes) {
        auto dep = parseDeparture(stopTime.toObject());
        dep.setStopPoint(loc);
        deps.push_back(dep);
    }
}

std::vector<Departure> OpenTripPlannerParser::parseDepartures(const QJsonObject &obj) const
{
    std::vector<Departure> deps;

    const auto depsArray = obj.value(QLatin1String("nearest")).toObject().value(QLatin1String("edges")).toArray();
    for (const auto &depsV : depsArray) {
        parseDeparturesForStop(depsV.toObject().value(QLatin1String("node")).toObject().value(QLatin1String("place")).toObject(), deps);
    }

    return deps;
}

JourneySection OpenTripPlannerParser::parseJourneySection(const QJsonObject &obj) const
{
    JourneySection section;
    section.setScheduledDepartureTime(QDateTime::fromMSecsSinceEpoch(obj.value(QLatin1String("startTime")).toDouble())); // ### sic! double to get 64 bit precision...
    section.setScheduledArrivalTime(QDateTime::fromMSecsSinceEpoch(obj.value(QLatin1String("endTime")).toDouble()));
    if (obj.value(QLatin1String("realTime")).toBool()) {
        section.setExpectedDepartureTime(section.scheduledDepartureTime().addSecs(obj.value(QLatin1String("departureDelay")).toInt()));
        section.setExpectedArrivalTime(section.scheduledArrivalTime().addSecs(obj.value(QLatin1String("arrivalDelay")).toInt()));
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

Journey OpenTripPlannerParser::parseJourney(const QJsonObject &obj) const
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

std::vector<Journey> OpenTripPlannerParser::parseJourneys(const QJsonObject& obj) const
{
    std::vector<Journey> journeys;

    const auto journeysArray = obj.value(QLatin1String("plan")).toObject().value(QLatin1String("itineraries")).toArray();
    journeys.reserve(journeysArray.size());
    for (const auto &journeyObj : journeysArray) {
        journeys.push_back(parseJourney(journeyObj.toObject()));
    }

    return journeys;
}
