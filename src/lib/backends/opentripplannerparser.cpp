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

#include <KPublicTransport/Journey>
#include <KPublicTransport/RentalVehicle>
#include <KPublicTransport/Stopover>

#include <QColor>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QTimeZone>

using namespace KPublicTransport;

OpenTripPlannerParser::OpenTripPlannerParser(const QString &identifierType)
    : m_identifierType(identifierType)
{
}

OpenTripPlannerParser::~OpenTripPlannerParser() = default;

Location OpenTripPlannerParser::parseLocation(const QJsonObject &obj, Location loc) const
{
    const auto parentObj = obj.value(QLatin1String("parentStation")).toObject();
    if (!parentObj.isEmpty()) {
        return parseLocation(parentObj, loc);
    }

    loc.setName(obj.value(QLatin1String("name")).toString());
    loc.setLatitude(obj.value(QLatin1String("lat")).toDouble());
    loc.setLongitude(obj.value(QLatin1String("lon")).toDouble());

    const auto tzId = obj.value(QLatin1String("timezone")).toString();
    if (!tzId.isEmpty()) {
        loc.setTimeZone(QTimeZone(tzId.toUtf8()));
    }

    const auto id = obj.value(QLatin1String("id")).toString();
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

std::vector<Location> OpenTripPlannerParser::parseLocationsArray(const QJsonArray &array) const
{
    std::vector<Location> locs;
    locs.reserve(array.size());
    for (const auto &l : array) {
        locs.push_back(parseLocation(l.toObject()));
    }
    return locs;
}

std::vector<Location> OpenTripPlannerParser::parseGeocodeResult(const QJsonArray &array) const
{
    std::vector<Location> locs;
    locs.reserve(array.size());
    for (const auto &v : array) {
        const auto obj = v.toObject();
        Location loc;
        loc.setLatitude(obj.value(QLatin1String("lat")).toDouble());
        loc.setLongitude(obj.value(QLatin1String("lng")).toDouble()); // sic!
        auto desc = obj.value(QLatin1String("description")).toString();
        if (desc.startsWith(QLatin1String("stop "))) {
            desc = desc.mid(5);
        }
        loc.setName(desc);
        loc.setIdentifier(m_identifierType, obj.value(QLatin1String("id")).toString());
        locs.push_back(loc);
    }
    return locs;
}

void OpenTripPlannerParser::parseAlerts(const QJsonArray& alertsArray) const
{
    m_alerts.reserve(alertsArray.size());
    for (const auto &alertValue : alertsArray) {
        const auto alertObj = alertValue.toObject();
        const auto descsArray = alertObj.value(QLatin1String("alertDescriptionTextTranslations")).toArray();
        if (descsArray.empty()) {
            continue;
        }

        // find the best language
        const auto uiLangs = QLocale().uiLanguages();
        int minIdx = 0, minWeight = std::numeric_limits<int>::max();
        for (int i = 0; i < descsArray.size(); ++i) {
            const auto lang = descsArray.at(i).toObject().value(QLatin1String("language")).toString();
            for (int j = 0; j < uiLangs.size() && j < minWeight; ++j) {
                if (uiLangs.at(j).startsWith(lang)) {
                    minIdx = i;
                    minWeight = j;
                    break;
                }
            }
        }

        m_alerts.push_back(descsArray.at(minIdx).toObject().value(QLatin1String("text")).toString());
    }
}

static QColor parseColor(const QJsonValue &value)
{
    if (value.isNull()) {
        return {};
    }
    return QColor(QLatin1Char('#') + value.toString());
}

Line OpenTripPlannerParser::parseLine(const QJsonObject &obj) const
{
    parseAlerts(obj.value(QLatin1String("alerts")).toArray());

    Line line;
    line.setName(obj.value(QLatin1String("shortName")).toString());
    if (line.name().isEmpty()) {
        line.setName(obj.value(QLatin1String("longName")).toString());
    }

    const auto type = obj.value(QLatin1String("type"));
    if (type.isString()) {
        line.setMode(Gtfs::Hvt::typeToMode(type.toString()));
    } else {
        line.setMode(Gtfs::Hvt::typeToMode(type.toInt(-1)));
    }

    auto presentation = obj.value(QLatin1String("presentation")).toObject();
    if (presentation.isEmpty()) {
        presentation = obj;
    }
    line.setColor(parseColor(presentation.value(QLatin1String("color"))));
    line.setTextColor(parseColor(presentation.value(QLatin1String("textColor"))));
    return line;
}

Route OpenTripPlannerParser::parseRoute(const QJsonObject &obj) const
{
    auto line = parseLine(obj.value(QLatin1String("route")).toObject());
    if (line.name().isEmpty()) {
        line.setName(obj.value(QLatin1String("tripShortName")).toString());
    }

    Route route;
    route.setLine(line);
    route.setDirection(obj.value(QLatin1String("tripHeadsign")).toString());

    return route;
}

Route OpenTripPlannerParser::parseInlineRoute(const QJsonObject &obj) const
{
    Line line;
    line.setMode(Gtfs::Hvt::typeToMode(obj.value(QLatin1String("routeType")).toInt(-1)));
    line.setName(obj.value(QLatin1String("tripShortName")).toString());
    line.setColor(parseColor(obj.value(QLatin1String("routeColor"))));
    line.setTextColor(parseColor(obj.value(QLatin1String("routeTextColor"))));

    Route route;
    route.setDirection(obj.value(QLatin1String("headsign")).toString());
    route.setLine(line);

    return route;
}

Route OpenTripPlannerParser::detectAndParseRoute(const QJsonObject &obj) const
{
    const auto trip = obj.value(QLatin1String("trip")).toObject();
    if (!trip.isEmpty()) {
        return parseRoute(trip);
    }

    const auto line = obj.value(QLatin1String("line")).toObject();
    if (!line.isEmpty()) {
        Route route;
        route.setLine(parseLine(obj.value(QLatin1String("line")).toObject()));
        return route;
    }

    return parseInlineRoute(obj);
}

static QDateTime parseDepartureDateTime(uint64_t baseTime, const QJsonValue &value)
{
    if (value.isDouble()) { // encoded as seconds offset to baseTime
        // UNIX timestamp of midnight in local timezone + UNIX timestamp of local time
        auto dt = QDateTime::fromSecsSinceEpoch(baseTime + value.toDouble());
        dt = dt.toTimeSpec(Qt::UTC);
        return dt;
    }
    return QDateTime::fromString(value.toString(), Qt::ISODate);
}

Stopover OpenTripPlannerParser::parseDeparture(const QJsonObject &obj) const
{
    Stopover dep;
    const auto baseTime = obj.value(QLatin1String("serviceDay")).toDouble(); // ### 64bit
    dep.setScheduledArrivalTime(parseDepartureDateTime(baseTime, obj.value(QLatin1String("scheduledArrival"))));
    dep.setScheduledDepartureTime(parseDepartureDateTime(baseTime, obj.value(QLatin1String("scheduledDeparture"))));
    if (obj.value(QLatin1String("realtime")).toBool()) {
        dep.setExpectedArrivalTime(parseDepartureDateTime(baseTime, obj.value(QLatin1String("realtimeArrival"))));
        dep.setExpectedDepartureTime(parseDepartureDateTime(baseTime, obj.value(QLatin1String("realtimeDeparture"))));
    }
    dep.setScheduledPlatform(obj.value(QLatin1String("stop")).toObject().value(QLatin1String("platformCode")).toString());
    dep.setRoute(detectAndParseRoute(obj));
    dep.addNotes(m_alerts);
    m_alerts.clear();

    return dep;
}

void OpenTripPlannerParser::parseDeparturesForStop(const QJsonObject &obj, std::vector<Stopover> &deps) const
{
    const auto loc = parseLocation(obj.value(QLatin1String("stop")).toObject());
    const auto stopTimes = obj.value(QLatin1String("stoptimes")).toArray();
    for (const auto &stopTime : stopTimes) {
        auto dep = parseDeparture(stopTime.toObject());
        dep.setStopPoint(loc);
        deps.push_back(dep);
    }
}

std::vector<Stopover> OpenTripPlannerParser::parseDepartures(const QJsonObject &obj) const
{
    std::vector<Stopover> deps;

    const auto depsArray = obj.value(QLatin1String("nearest")).toObject().value(QLatin1String("edges")).toArray();
    for (const auto &depsV : depsArray) {
        parseDeparturesForStop(depsV.toObject().value(QLatin1String("node")).toObject().value(QLatin1String("place")).toObject(), deps);
    }

    return deps;
}

std::vector<Stopover> OpenTripPlannerParser::parseDeparturesArray(const QJsonArray &array) const
{
    std::vector<Stopover> deps;
    for (const auto &pattern : array) {
        const auto obj = pattern.toObject();
        const auto times = obj.value(QLatin1String("times")).toArray();
        for (const auto &time : times) {
            deps.push_back(parseDeparture(time.toObject()));
        }
    }
    return deps;
}


static QDateTime parseJourneyDateTime(const QJsonValue &val)
{
    if (val.isDouble()) {
        // timestamp, as UTC value
        auto dt = QDateTime::fromMSecsSinceEpoch(val.toDouble()); // ### sic! double to get 64 bit precision...
        dt = dt.toTimeSpec(Qt::UTC);
        return dt;
    }
    if (val.isString()) {
        return QDateTime::fromString(val.toString(), Qt::ISODate);
    }
    return {};
}

JourneySection OpenTripPlannerParser::parseJourneySection(const QJsonObject &obj) const
{
    JourneySection section;
    section.setScheduledDepartureTime(parseJourneyDateTime(obj.value(QLatin1String("startTime"))));
    section.setScheduledArrivalTime(parseJourneyDateTime(obj.value(QLatin1String("endTime"))));
    if (obj.value(QLatin1String("realTime")).toBool()) {
        section.setExpectedDepartureTime(parseJourneyDateTime(obj.value(QLatin1String("expectedStartTime"))));
        if (!section.expectedDepartureTime().isValid()) {
            section.setExpectedDepartureTime(section.scheduledDepartureTime().addSecs(obj.value(QLatin1String("departureDelay")).toInt()));
        }
        section.setExpectedArrivalTime(parseJourneyDateTime(obj.value(QLatin1String("expectedEndTime"))));
        if (!section.expectedArrivalTime().isValid()) {
            section.setExpectedArrivalTime(section.scheduledArrivalTime().addSecs(obj.value(QLatin1String("arrivalDelay")).toInt()));
        }
    }

    const auto fromObj = obj.value(QLatin1String("from")).toObject();
    const auto fromStop = fromObj.value(QLatin1String("stop")).toObject();
    const auto fromBikeRental = fromObj.value(QLatin1String("bikeRentalStation")).toObject();
    auto from = parseLocation(fromBikeRental);
    from = parseLocation(fromStop);
    from = parseLocation(fromObj, from);
    section.setFrom(from);
    section.setScheduledDeparturePlatform(fromStop.value(QLatin1String("platformCode")).toString());

    const auto toObj = obj.value(QLatin1String("to")).toObject();
    const auto toStop = toObj.value(QLatin1String("stop")).toObject();
    const auto toBikeRental = toObj.value(QLatin1String("bikeRentalStation")).toObject();
    auto to = parseLocation(toBikeRental);
    to = parseLocation(toStop);
    to = parseLocation(toObj, to);
    section.setTo(to);
    section.setScheduledDeparturePlatform(toStop.value(QLatin1String("platformCode")).toString());

    section.setDistance(obj.value(QLatin1String("distance")).toDouble());

    if (obj.value(QLatin1String("transitLeg")).toBool()) {
        section.setMode(JourneySection::PublicTransport);
        section.setRoute(detectAndParseRoute(obj));
    } else {
        if (obj.value(QLatin1String("mode")).toString() == QLatin1String("BICYCLE")) {
            section.setMode(JourneySection::RentedVehicle);
            RentalVehicle v;
            v.setType(RentalVehicle::Bicycle);
            auto networks = fromBikeRental.value(QLatin1String("networks")).toArray();
            if (!networks.isEmpty()) {
                v.setNetwork(networks.at(0).toString());
            } else {
                networks = toBikeRental.value(QLatin1String("networks")).toArray();
                if (!networks.isEmpty()) {
                    v.setNetwork(networks.at(0).toString());
                }
            }
            section.setRentalVehicle(v);
        } else {
            section.setMode(JourneySection::Walking);
        }
    }

    section.addNotes(m_alerts);
    m_alerts.clear();

    const auto stopsA = obj.value(QLatin1String("intermediateStops")).toArray();
    std::vector<Stopover> stops;
    stops.reserve(stopsA.size());
    for (const auto &stopV : stopsA) {
        const auto stopObj = stopV.toObject();
        const auto locObj = stopObj.value(QLatin1String("stop")).toObject();
        const auto loc = parseLocation(locObj);

        Stopover stop;
        stop.setStopPoint(loc);
        stop.setScheduledPlatform(stopObj.value(QLatin1String("platformCode")).toString());
        stop.setScheduledArrivalTime(parseJourneyDateTime(stopObj.value(QLatin1String("scheduledArrivalTime"))));
        stop.setScheduledDepartureTime(parseJourneyDateTime(stopObj.value(QLatin1String("scheduledDepartureTime"))));
        stop.setExpectedArrivalTime(parseJourneyDateTime(stopObj.value(QLatin1String("expectedArrivalTime"))));
        stop.setExpectedDepartureTime(parseJourneyDateTime(stopObj.value(QLatin1String("expectedDepartureTime"))));

        stops.push_back(stop);
    }
    section.setIntermediateStops(std::move(stops));

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
