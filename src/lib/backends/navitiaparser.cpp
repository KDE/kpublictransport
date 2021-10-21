/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "navitiaparser.h"
#include "../geo/geojson_p.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Line>
#include <KPublicTransport/RentalVehicle>
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

    auto codes = obj.value(QLatin1String("codes")).toArray();
    if (codes.empty()) {
        codes = obj.value(QLatin1String("stop_area")).toObject().value(QLatin1String("codes")).toArray();
    }
    for (const auto &codeV : qAsConst(codes)) {
        const auto code = codeV.toObject();
        if (code.value(QLatin1String("type")).toString() == QLatin1String("UIC8")) {
            loc.setIdentifier(QStringLiteral("uic"), code.value(QLatin1String("value")).toString().left(7));
        }
    }

    const auto poi_type = obj.value(QLatin1String("poi_type")).toObject().value(QLatin1String("id")).toString();
    if (poi_type == QLatin1String("poi_type:amenity:bicycle_rental")) {
        RentalVehicleNetwork network;
        network.setName(obj.value(QLatin1String("properties")).toObject().value(QLatin1String("network")).toString());

        RentalVehicleStation station;
        station.setNetwork(network);
        const auto standsObj = obj.value(QLatin1String("stands")).toObject();
        station.setAvailableVehicles(standsObj.value(QLatin1String("available_bikes")).toInt(-1));
        station.setCapacity(standsObj.value(QLatin1String("total_stands")).toInt(-1));

        loc.setType(Location::RentedVehicleStation);
        loc.setData(station);
    }

    return loc;
}

static Location parseWrappedLocation(const QJsonObject &obj)
{
    const auto type = obj.value(QLatin1String("embedded_type")).toString();
    auto loc = parseLocation(obj.value(type).toObject());
    loc.setName(obj.value(QLatin1String("name")).toString());
    if (type == QLatin1String("stop_area") || type == QLatin1String("stop_point")) {
        loc.setType(Location::Stop);
    }
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

static Path parsePathWithInstructionStartCoordinate(const QPolygonF &pathLineString, const QJsonArray &pathArray)
{
    std::vector<PathSection> pathSections;
    pathSections.reserve(pathArray.size());
    PathSection prevPathSec;
    int prevPolyIdx = 0;
    bool isFirstSection = true;
    for (const auto &pathV : pathArray) {
        const auto pathObj = pathV.toObject();
        PathSection pathSec;
        pathSec.setDescription(pathObj.value(QLatin1String("instruction")).toString());
        if (pathSec.description().isEmpty()) {
            pathSec.setDescription(pathObj.value(QLatin1String("name")).toString());
        }

        if (!isFirstSection) {
            const auto coordObj = pathObj.value(QLatin1String("instruction_start_coordinate")).toObject();
            const QPointF coord(coordObj.value(QLatin1String("lon")).toString().toDouble(), coordObj.value(QLatin1String("lat")).toString().toDouble());
            const auto it = std::min_element(pathLineString.begin() + prevPolyIdx, pathLineString.end(), [coord](QPointF lhs, QPointF rhs) {
                return Location::distance(lhs.y(), lhs.x(), coord.y(), coord.x()) < Location::distance(rhs.y(), rhs.x(), coord.y(), coord.x());
            });
            int polyIdx = std::distance(pathLineString.begin(), it);

            QPolygonF subPoly;
            subPoly.reserve(polyIdx - prevPolyIdx + 1);
            std::copy(pathLineString.begin() + prevPolyIdx, pathLineString.begin() + polyIdx + 1, std::back_inserter(subPoly));
            prevPathSec.setPath(std::move(subPoly));
            prevPolyIdx = polyIdx;
            pathSections.push_back(std::move(prevPathSec));
        } else {
            isFirstSection = false;
        }
        prevPathSec = pathSec;
    }

    QPolygonF subPoly;
    subPoly.reserve(prevPolyIdx - pathLineString.size() + 1);
    std::copy(pathLineString.begin() + prevPolyIdx, pathLineString.end(), std::back_inserter(subPoly));
    prevPathSec.setPath(std::move(subPoly));
    pathSections.push_back(std::move(prevPathSec));

    Path path;
    path.setSections(std::move(pathSections));
    return path;
}

static Path parsePathFromLength(const QPolygonF &pathLineString, const QJsonArray &pathArray)
{
    std::vector<PathSection> pathSections;
    pathSections.reserve(pathArray.size());
    int prevPolyIdx = 0;
    for (const auto &pathV : pathArray) {
        const auto pathObj = pathV.toObject();
        PathSection pathSec;
        pathSec.setDescription(pathObj.value(QLatin1String("instruction")).toString());
        if (pathSec.description().isEmpty()) {
            pathSec.setDescription(pathObj.value(QLatin1String("name")).toString());
        }

        int polyIdx = prevPolyIdx + 1;
        const auto length = pathObj.value(QLatin1String("length")).toInt();
        for (float l = 0.0f, prevDelta = std::numeric_limits<float>::max(); polyIdx < pathLineString.size(); ++polyIdx) {
            l += Location::distance(pathLineString.at(polyIdx - 1).y(), pathLineString.at(polyIdx - 1).x(), pathLineString.at(polyIdx).y(), pathLineString.at(polyIdx).x());
            auto delta = length - l;
            if (delta <= 0) {
                if (prevDelta < -delta) {
                    --polyIdx;
                }
                break;
            }
            prevDelta = delta;
        }

        QPolygonF subPoly;
        subPoly.reserve(polyIdx - prevPolyIdx + 1);
        std::copy(pathLineString.begin() + prevPolyIdx, pathLineString.begin() + std::min(polyIdx + 1, pathLineString.size()), std::back_inserter(subPoly));
        pathSec.setPath(std::move(subPoly));
        prevPolyIdx = polyIdx;
        pathSections.push_back(std::move(pathSec));
    }

    Path path;
    path.setSections(std::move(pathSections));
    return path;
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

    const auto hasRealTime = obj.value(QLatin1String("data_freshness")).toString() != QLatin1String("base_schedule");
    section.setScheduledDepartureTime(parseDateTime(obj.value(QLatin1String("base_departure_date_time")), section.from().timeZone()));
    section.setScheduledArrivalTime(parseDateTime(obj.value(QLatin1String("base_arrival_date_time")), section.to().timeZone()));
    if (hasRealTime) {
        section.setScheduledArrivalTime(parseDateTime(obj.value(QLatin1String("arrival_date_time")), section.to().timeZone()));
        section.setScheduledDepartureTime(parseDateTime(obj.value(QLatin1String("departure_date_time")), section.from().timeZone()));
    }

    const auto typeStr = obj.value(QLatin1String("type")).toString();
    if (typeStr == QLatin1String("public_transport")) {
        section.setMode(JourneySection::PublicTransport);
    // TODO we have no type for parking/rent/return yet
    } else if (typeStr == QLatin1String("transfer") || typeStr == QLatin1String("park") ||
        typeStr == QLatin1String("bss_rent") || typeStr == QLatin1String("bss_put_back")) {
        section.setMode(JourneySection::Transfer);
    } else if (typeStr == QLatin1String("street_network") || typeStr == QLatin1String("walking") || typeStr == QLatin1String("crow_fly")) {
        const auto modeStr = obj.value(QLatin1String("mode")).toString();
        if (modeStr == QLatin1String("bike")) {
            if (section.from().type() == Location::RentedVehicleStation) {
                section.setMode(JourneySection::RentedVehicle);
                RentalVehicle v;
                v.setType(RentalVehicle::Bicycle);
                v.setNetwork(section.from().rentalVehicleStation().network());
                section.setRentalVehicle(v);
            } else {
                section.setMode(JourneySection::IndividualTransport);
                section.setIndividualTransport({IndividualTransport::Bike, IndividualTransport::None});
            }
        } else if (modeStr == QLatin1String("car")) {
            section.setMode(JourneySection::IndividualTransport);
            section.setIndividualTransport({IndividualTransport::Car, IndividualTransport::None});
        } else {
            section.setMode(JourneySection::Walking);
        }
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
            if (!hasRealTime) { // intermediate stops seems to miss the "data_freshness" field, so propagate that
                stop.setExpectedArrivalTime({});
                stop.setExpectedDepartureTime({});
            }
            stops.push_back(std::move(stop));
        }
        section.setIntermediateStops(std::move(stops));
    }

    const auto emissionObj = obj.value(QLatin1String("co2_emission")).toObject();
    section.setCo2Emission(emissionObj.value(QLatin1String("value")).toDouble(-1));

    const auto pathLineString = GeoJson::readLineString(obj.value(QLatin1String("geojson")).toObject());
    const auto pathArray = obj.value(QLatin1String("path")).toArray();
    if (!pathArray.empty()) {
        const auto hasInstrStartCoordinate = pathArray.at(0).toObject().contains(QLatin1String("instruction_start_coordinate"));
        Path path;
        if (hasInstrStartCoordinate) {
            path = parsePathWithInstructionStartCoordinate(pathLineString, pathArray);
        } else {
            path = parsePathFromLength(pathLineString, pathArray);
        }
        section.setPath(std::move(path));
    } else if (!pathLineString.isEmpty()) {
        Path path;
        PathSection pathSection;
        pathSection.setPath(pathLineString);
        path.setSections({pathSection});
        section.setPath(std::move(path));
    }

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
