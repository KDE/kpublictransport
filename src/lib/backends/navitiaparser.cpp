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

#include "navitiaparser.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Line>
#include <KPublicTransport/Stopover>

#include <QColor>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimeZone>

using namespace KPublicTransport;

NavitiaParser::NavitiaParser() = default;
NavitiaParser::~NavitiaParser() = default;

static QDateTime parseDateTime(const QJsonValue &v, const QTimeZone &tz)
{
    auto dt = QDateTime::fromString(v.toString(), QStringLiteral("yyyyMMddTHHmmss"));
    if (tz.isValid()) {
        dt.setTimeZone(tz);
    }
    return dt;
}

struct {
    const char *name;
    Line::Mode mode;
} static const navitia_physical_modes[] = {
    { "Air", Line::Air },
    { "Boat", Line::Boat },
    { "Bus", Line::Bus },
    { "BusRapidTransit", Line::BusRapidTransit },
    { "Coach", Line::Coach },
    { "Ferry", Line::Ferry },
    { "Funicular", Line::Funicular },
    { "LocalTrain", Line::LocalTrain },
    { "LongDistanceTrain", Line::LongDistanceTrain },
    { "Metro", Line::Metro },
    { "RailShuttle", Line::RailShuttle },
    { "RapidTransit", Line::RapidTransit },
    { "Shuttle", Line::Shuttle },
    { "Taxi", Line::Taxi },
    { "Train", Line::Train },
    { "Tramway", Line::Tramway }
};

static Line::Mode parsePhysicalMode(const QString &mode)
{
    const auto modeStr = mode.toLatin1();
    if (!modeStr.startsWith("physical_mode:")) {
        return Line::Unknown;
    }
    for (auto it = std::begin(navitia_physical_modes); it != std::end(navitia_physical_modes); ++it) {
        if (strcmp(modeStr.constData() + 14, it->name) == 0) {
            return it->mode;
        }
    }

    return Line::Unknown;
}

static void parseAdminRegion(Location &loc, const QJsonObject &ar)
{
    const auto level = ar.value(QLatin1String("level")).toInt();
    if (level == 8) {
        loc.setLocality(ar.value(QLatin1String("name")).toString());
    }
    else if (level == 10) {
        loc.setPostalCode(ar.value(QLatin1String("zip_code")).toString());
    }
}

static Location parseLocation(const QJsonObject &obj)
{
    Location loc;
    loc.setName(obj.value(QLatin1String("label")).toString());
    // TODO parse more fields

    const auto coord = obj.value(QLatin1String("coord")).toObject();
    loc.setCoordinate(coord.value(QLatin1String("lat")).toString().toDouble(), coord.value(QLatin1String("lon")).toString().toDouble());

    auto tz = obj.value(QLatin1String("timezone")).toString();
    if (tz.isEmpty()) {
        tz = obj.value(QLatin1String("stop_area")).toObject().value(QLatin1String("timezone")).toString();
    }
    if (!tz.isEmpty()) {
        loc.setTimeZone(QTimeZone(tz.toUtf8()));
    }

    const auto ars = obj.value(QLatin1String("administrative_regions")).toArray();
    for (const auto &ar : ars) {
        parseAdminRegion(loc, ar.toObject());
    }

    return loc;
}

static Location parseWrappedLocation(const QJsonObject &obj)
{
    auto loc = parseLocation(obj.value(obj.value(QLatin1String("embedded_type")).toString()).toObject());
    loc.setName(obj.value(QLatin1String("name")).toString());
    return loc;
}

static void parseStopDateTime(const QJsonObject &dtObj, Stopover &departure)
{
    departure.setScheduledDepartureTime(parseDateTime(dtObj.value(QLatin1String("base_departure_date_time")), departure.stopPoint().timeZone()));
    departure.setScheduledArrivalTime(parseDateTime(dtObj.value(QLatin1String("base_arrival_date_time")), departure.stopPoint().timeZone()));
    if (dtObj.value(QLatin1String("data_freshness")).toString() != QLatin1String("base_schedule")) {
        departure.setExpectedDepartureTime(parseDateTime(dtObj.value(QLatin1String("departure_date_time")), departure.stopPoint().timeZone()));
        departure.setExpectedArrivalTime(parseDateTime(dtObj.value(QLatin1String("arrival_date_time")), departure.stopPoint().timeZone()));
    }

}

JourneySection NavitiaParser::parseJourneySection(const QJsonObject &obj) const
{
    JourneySection section;
    section.setFrom(parseWrappedLocation(obj.value(QLatin1String("from")).toObject()));
    section.setTo(parseWrappedLocation(obj.value(QLatin1String("to")).toObject()));

    const auto displayInfo = obj.value(QLatin1String("display_informations")).toObject();
    Line line;
    line.setName(displayInfo.value(QLatin1String("label")).toString());
    line.setColor(QColor(QLatin1Char('#') + displayInfo.value(QLatin1String("color")).toString()));
    line.setTextColor(QColor(QLatin1Char('#') + displayInfo.value(QLatin1String("text_color")).toString()));
    line.setModeString(displayInfo.value(QLatin1String("commercial_mode")).toString());
    const auto links = obj.value(QLatin1String("links")).toArray();
    for (const auto &v : links) {
        const auto link = v.toObject();
        const auto type = link.value(QLatin1String("type")).toString();
        if (type == QLatin1String("physical_mode")) {
            line.setMode(parsePhysicalMode(link.value(QLatin1String("id")).toString()));
        }
        parseDisruptionLink(section, link);
    }
    const auto displayLinks = displayInfo.value(QLatin1String("links")).toArray();
    for (const auto &v : displayLinks) {
        const auto link = v.toObject();
        parseDisruptionLink(section, link);
    }

    Route route;
    route.setDirection(displayInfo.value(QLatin1String("direction")).toString());
    route.setLine(line);
    section.setRoute(route);

    section.setScheduledDepartureTime(parseDateTime(obj.value(QLatin1String("base_departure_date_time")), section.from().timeZone()));
    section.setScheduledArrivalTime(parseDateTime(obj.value(QLatin1String("base_arrival_date_time")), section.to().timeZone()));
    if (obj.value(QLatin1String("data_freshness")).toString() != QLatin1String("base_schedule")) {
        section.setScheduledArrivalTime(parseDateTime(obj.value(QLatin1String("arrival_date_time")), section.to().timeZone()));
        section.setScheduledDepartureTime(parseDateTime(obj.value(QLatin1String("departure_date_time")), section.from().timeZone()));
    }

    const auto typeStr = obj.value(QLatin1String("type")).toString();
    if (typeStr == QLatin1String("public_transport")) {
        section.setMode(JourneySection::PublicTransport);
    } else if (typeStr == QLatin1String("transfer")) {
        section.setMode(JourneySection::Transfer);
    } else if (typeStr == QLatin1String("street_network") || typeStr == QLatin1String("walking") || typeStr == QLatin1String("crow_fly")) {
        section.setMode(JourneySection::Walking);
        section.setDistance(obj.value(QLatin1String("geojson")).toObject().value(QLatin1String("properties")).toArray().at(0).toObject().value(QLatin1String("length")).toInt());
    } else if (typeStr == QLatin1String("waiting")) {
        section.setMode(JourneySection::Waiting);
    }

    const auto stopsDtA = obj.value(QLatin1String("stop_date_times")).toArray();
    if (stopsDtA.size() > 2) { // departure/arrival are included, we don't want that
        std::vector<Stopover> stops;
        stops.reserve(stopsDtA.size() - 2);
        for (auto it = std::next(stopsDtA.begin()); it != std::prev(stopsDtA.end()); ++it) {
            const auto obj = (*it).toObject();
            Stopover stop;
            stop.setStopPoint(parseLocation(obj.value(QLatin1String("stop_point")).toObject()));
            parseStopDateTime(obj, stop);
            stops.push_back(std::move(stop));
        }
        section.setIntermediateStops(std::move(stops));
    }

    const auto emissionObj = obj.value(QLatin1String("co2_emission")).toObject();
    section.setCo2Emission(emissionObj.value(QLatin1String("value")).toDouble(-1));

    return section;
}

Journey NavitiaParser::parseJourney(const QJsonObject &obj) const
{
    Journey journey;

    const auto secArray = obj.value(QLatin1String("sections")).toArray();
    std::vector<JourneySection> sections;
    sections.reserve(secArray.size());
    for (const auto &v : secArray) {
        sections.push_back(parseJourneySection(v.toObject()));
    }
    journey.setSections(std::move(sections));
    return journey;
}

std::vector<Journey> NavitiaParser::parseJourneys(const QByteArray &data)
{
    const auto topObj = QJsonDocument::fromJson(data).object();
    m_disruptions = topObj.value(QLatin1String("disruptions")).toArray();
    const auto journeys = topObj.value(QLatin1String("journeys")).toArray();

    std::vector<Journey> res;
    res.reserve(journeys.size());

    for (const auto &v : journeys) {
        res.push_back(parseJourney(v.toObject()));
    }

    parseLinks(topObj.value(QLatin1String("links")).toArray());
    parseAttributions(topObj.value(QLatin1String("feed_publishers")).toArray());
    return res;
}

Stopover NavitiaParser::parseDeparture(const QJsonObject &obj) const
{
    // TODO remove code duplication with journey parsing
    Stopover departure;
    const auto displayInfo = obj.value(QLatin1String("display_informations")).toObject();

    Line line;
    line.setName(displayInfo.value(QLatin1String("label")).toString());
    line.setColor(QColor(QLatin1Char('#') + displayInfo.value(QLatin1String("color")).toString()));
    line.setTextColor(QColor(QLatin1Char('#') + displayInfo.value(QLatin1String("text_color")).toString()));
    line.setModeString(displayInfo.value(QLatin1String("commercial_mode")).toString());
    const auto links = obj.value(QLatin1String("links")).toArray();
    for (const auto &v : links) {
        const auto link = v.toObject();
        if (link.value(QLatin1String("type")).toString() == QLatin1String("physical_mode")) {
            line.setMode(parsePhysicalMode(link.value(QLatin1String("id")).toString()));
        }
        parseDisruptionLink(departure, link);
    }
    const auto displayLinks = displayInfo.value(QLatin1String("links")).toArray();
    for (const auto &v : displayLinks) {
        const auto link = v.toObject();
        parseDisruptionLink(departure, link);
    }

    Route route;
    route.setDirection(displayInfo.value(QLatin1String("direction")).toString());
    const auto routeObj = obj.value(QLatin1String("route")).toObject();
    const auto destObj = routeObj.value(QLatin1String("direction")).toObject();
    route.setDestination(parseWrappedLocation(destObj));
    route.setLine(line);

    departure.setRoute(route);
    departure.setStopPoint(parseLocation(obj.value(QLatin1String("stop_point")).toObject()));
    parseStopDateTime(obj.value(QLatin1String("stop_date_time")).toObject(), departure);

    return departure;
}

std::vector<Stopover> NavitiaParser::parseDepartures(const QByteArray &data)
{
    const auto topObj = QJsonDocument::fromJson(data).object();
    m_disruptions = topObj.value(QLatin1String("disruptions")).toArray();
    const auto departures = topObj.value(QLatin1String("departures")).toArray();

    std::vector<Stopover> res;
    res.reserve(departures.size());

    for (const auto &v : departures) {
        res.push_back(parseDeparture(v.toObject()));
    }

    parseLinks(topObj.value(QLatin1String("links")).toArray());
    parseAttributions(topObj.value(QLatin1String("feed_publishers")).toArray());
    return res;
}

std::vector<Location> NavitiaParser::parsePlacesNearby(const QByteArray &data)
{
    const auto topObj = QJsonDocument::fromJson(data).object();
    const auto placesNearby = topObj.value(QLatin1String("places_nearby")).toArray();

    std::vector<Location> res;
    res.reserve(placesNearby.size());

    for (const auto &v : placesNearby) {
        res.push_back(parseWrappedLocation(v.toObject()));
    }

    parseAttributions(topObj.value(QLatin1String("feed_publishers")).toArray());
    return res;
}

std::vector<Location> NavitiaParser::parsePlaces(const QByteArray &data)
{
    const auto topObj = QJsonDocument::fromJson(data).object();
    const auto placesNearby = topObj.value(QLatin1String("places")).toArray();

    std::vector<Location> res;
    res.reserve(placesNearby.size());

    for (const auto &v : placesNearby) {
        res.push_back(parseWrappedLocation(v.toObject()));
    }

    parseAttributions(topObj.value(QLatin1String("feed_publishers")).toArray());
    return res;
}

QString NavitiaParser::parseErrorMessage(const QByteArray &data)
{
    const auto topObj = QJsonDocument::fromJson(data).object();
    const auto errorObj = topObj.value(QLatin1String("error")).toObject();

    // id field contains error enum, might also be useful
    return errorObj.value(QLatin1String("message")).toString();
}

void NavitiaParser::parseLinks(const QJsonArray &links)
{
    for (const auto &v : links) {
        const auto link = v.toObject();
        const auto rel = link.value(QLatin1String("rel")).toString();
        if (rel == QLatin1String("next")) {
            nextLink = QUrl(link.value(QLatin1String("href")).toString());
        } else if (rel == QLatin1String("prev")) {
            prevLink = QUrl(link.value(QLatin1String("href")).toString());
        }
    }
}

void NavitiaParser::parseAttributions(const QJsonArray& feeds)
{
    for (const auto &v : feeds) {
        const auto feed = v.toObject();
        Attribution attr;
        attr.setName(feed.value(QLatin1String("name")).toString());
        QUrl url(feed.value(QLatin1String("url")).toString());
        if (!url.isEmpty()) {
            url.setScheme(QStringLiteral("https")); // missing in a few cases
        }
        attr.setUrl(url);
        attr.setLicense(feed.value(QLatin1String("license")).toString());
        // TODO map known licenses to spdx links
        attributions.push_back(std::move(attr));
    }
}

QJsonObject NavitiaParser::findDisruption(const QString &id) const
{
    for (const auto &v : m_disruptions) {
        const auto disruption = v.toObject();
        if (disruption.value(QLatin1String("uri")).toString() == id) {
            return disruption;
        }
    }
    return {};
}

static QString disruptionMessage(const QJsonObject &distruption)
{
    const auto msgs = distruption.value(QLatin1String("messages")).toArray();
    for (const auto &msgV : msgs) {
        const auto msg = msgV.toObject();
        const auto types = msg.value(QLatin1String("channel")).toObject().value(QLatin1String("types")).toArray();
        for (const auto &typeV : types) {
            if (typeV.toString() == QLatin1String("web")) {
                return msg.value(QLatin1String("text")).toString();
            }
        }
    }
    return {};
}

template <typename T>
void NavitiaParser::parseDisruptionLink(T &element, const QJsonObject &link) const
{
    const auto type = link.value(QLatin1String("type")).toString();
    if (type != QLatin1String("disruption")) {
        return;
    }

    const auto id = link.value(QLatin1String("id")).toString();
    const auto disruption = findDisruption(id);
    if (disruption.value(QLatin1String("severity")).toObject().value(QLatin1String("effect")).toString() == QLatin1String("NO_SERVICE")) {
        element.setDisruptionEffect(Disruption::NoService);
    }
    element.addNote(disruptionMessage(disruption));
}
