/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "ivvassparser.h"

#include <KPublicTransport/Equipment>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include <QByteArray>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <cmath>

using namespace KPublicTransport;

static Location parseLocation(const QJsonObject &stopObj)
{
    Location loc;
    loc.setLatitude(stopObj.value(QLatin1String("lat")).toDouble(NAN));
    loc.setLongitude(stopObj.value(QLatin1String("lon")).toDouble(NAN));
    if (!loc.hasCoordinate()) {
        // sic, x/y are swapped here!
        loc.setLatitude(stopObj.value(QLatin1String("x")).toDouble(NAN));
        loc.setLongitude(stopObj.value(QLatin1String("y")).toDouble(NAN));
    }

    loc.setName(stopObj.value(QLatin1String("name")).toString());
    if (loc.name().isEmpty()) {
        loc.setName(stopObj.value(QLatin1String("description")).toString());
    }
    loc.setLocality(stopObj.value(QLatin1String("city")).toString());
    if (loc.locality().isEmpty()) {
        loc.setLocality(stopObj.value(QLatin1String("municipality")).toString());
    }

    if (stopObj.value(QLatin1String("type")).toString() == QLatin1String("coordinate")) {
        return loc;
    }

    loc.setIdentifier(QStringLiteral("ifopt"), stopObj.value(QLatin1String("ifopt")).toString());
    loc.setType(Location::Stop);
    return loc;
}

std::vector<Location> IvvAssParser::parseLocations(const QByteArray &data)
{
    const auto top = QJsonDocument::fromJson(data).object();
    std::vector<Location> locs;

    const auto stops = top.value(QLatin1String("stops")).toArray();
    locs.reserve(stops.size());
    for (const auto &stopV : stops) {
        const auto stopObj = stopV.toObject();
        locs.push_back(parseLocation(stopObj));
    }
    const auto objects = top.value(QLatin1String("objects")).toArray();
    locs.reserve(locs.size() + objects.size());
    for (const auto &objectV : objects) {
        const auto obj = objectV.toObject();
        const auto type = obj.value(QLatin1String("type")).toString();
        if (type != QLatin1String("stop")) { // poi, parking, etc
            continue;
        }
        locs.push_back(parseLocation(obj));

        const auto elevators = obj.value(QLatin1String("elevators")).toArray();
        const auto escalators = obj.value(QLatin1String("escalators")).toArray();
        locs.reserve(locs.size() + elevators.size() + escalators.size());
        for (const auto &eleV : elevators) {
            const auto eleObj = eleV.toObject();
            auto ele = parseLocation(eleObj);
            Equipment eq;
            eq.setType(Equipment::Elevator);
            eq.setDisruptionEffect(eleObj.value(QLatin1String("status")).toString() == QLatin1String("active") ? Disruption::NormalService : Disruption::NoService);
            ele.setData(std::move(eq));
            ele.setType(Location::Equipment);
            locs.push_back(std::move(ele));
        }
        for (const auto &escV : escalators) {
            const auto escObj = escV.toObject();
            auto esc = parseLocation(escObj);
            Equipment eq;
            eq.setType(Equipment::Escalator);
            eq.setDisruptionEffect(escObj.value(QLatin1String("status")).toString() == QLatin1String("active") ? Disruption::NormalService : Disruption::NoService);
            esc.setData(std::move(eq));
            esc.setType(Location::Equipment);
            locs.push_back(std::move(esc));
        }
    }

    const auto vehicles = top.value(QLatin1String("vehicles")).toArray();
    locs.reserve(locs.size() + vehicles.size());
    for (const auto &vehicleV : vehicles) {
        auto v = parseLocation(vehicleV.toObject());
        v.setType(Location::RentedVehicle); // TODO can we get vehicle types and networks from somewhere?
        locs.push_back(std::move(v));
    }

    return locs;
}

struct {
    const char *product;
    Line::Mode mode;
} static constexpr const product_mode_map[] = {
    { "Boat", Line::Ferry },
    { "Bus", Line::Bus },
    { "CommunityBus", Line::Bus },
    { "LightRail", Line::Tramway },
    { "LongDistanceTrains", Line::LongDistanceTrain },
    { "OnDemandServices", Line::Taxi },
    { "RailReplacementServices", Line::Bus },
    { "RegionalTrains", Line::LocalTrain },
    { "SuburbanTrains", Line::RapidTransit },
    { "Underground", Line::Metro }
};

static Route parseRoute(const QJsonObject &lineObj)
{
    Line line;
    line.setName(lineObj.value(QLatin1String("number")).toString());
    const auto product = lineObj.value(QLatin1String("product")).toString();
    for (const auto &m : product_mode_map) {
        if (product == QLatin1String(m.product)) {
            line.setMode(m.mode);
            break;
        }
    }
    if (line.mode() == Line::Unknown) {
        qWarning() << "Unknown product type:" << product;
    }

    Route route;
    route.setLine(std::move(line));
    route.setDirection(lineObj.value(QLatin1String("direction")).toString());
    return route;
}

std::vector<Stopover> IvvAssParser::parseStopovers(const QByteArray &data)
{
    const auto top = QJsonDocument::fromJson(data).object();
    const auto timetable = top.value(QLatin1String("timetable")).toArray();

    std::vector<Stopover> stopovers;
    for (const auto &timetableV : timetable) {
        const auto timetableObj = timetableV.toObject();
        const auto stopObj = timetableObj.value(QLatin1String("stop")).toObject();
        const auto stop = parseLocation(stopObj);

        const auto events = timetableObj.value(QLatin1String("events")).toArray();
        stopovers.reserve(stopovers.size() + events.size());
        for (const auto &eventV : events) {
            const auto eventObj = eventV.toObject();

            Stopover s;
            s.setStopPoint(stop);
            s.setScheduledDepartureTime(QDateTime::fromString(eventObj.value(QLatin1String("departureScheduled")).toString(), Qt::ISODate));
            s.setExpectedDepartureTime(QDateTime::fromString(eventObj.value(QLatin1String("departure")).toString(), Qt::ISODate));

            const auto lineObj = eventObj.value(QLatin1String("line")).toObject();
            s.setRoute(parseRoute(lineObj));

            const auto postObj = eventObj.value(QLatin1String("post")).toObject();
            s.setScheduledPlatform(postObj.value(QLatin1String("name")).toString());
            stopovers.push_back(std::move(s));
        }
    }

    return stopovers;
}

static std::vector<LoadInfo> parseDemand(const QJsonValue &demand)
{
    if (!demand.isDouble()) {
        return {};
    }

    const auto d = demand.toInt();
    if (d < 0 || d > 2) {
        return {};
    }

    static constexpr const Load::Category load_category_map[] = { Load::Low, Load::Medium, Load::High };

    LoadInfo l;
    l.setLoad(load_category_map[d]);
    return {l};
}

std::vector<Journey> IvvAssParser::parseJourneys(const QByteArray &data)
{
    const auto top = QJsonDocument::fromJson(data).object();
    const auto routes = top.value(QLatin1String("routes")).toArray();

    std::vector<Journey> journeys;
    journeys.reserve(routes.size());
    for (const auto &routeV : routes) {
        const auto routeObj = routeV.toObject();
        Journey journey;

        const auto segments = routeObj.value(QLatin1String("segments")).toArray();
        std::vector<JourneySection> sections;
        sections.reserve(segments.size());
        for (const auto &segmentV : segments) {
            const auto segmentObj = segmentV.toObject();
            JourneySection s;
            // TODO platform data is merged into location names
            s.setFrom(parseLocation(segmentObj.value(QLatin1String("origin")).toObject()));
            s.setTo(parseLocation(segmentObj.value(QLatin1String("destination")).toObject()));

            s.setScheduledDepartureTime(QDateTime::fromString(segmentObj.value(QLatin1String("departureScheduled")).toString(), Qt::ISODate));
            s.setExpectedDepartureTime(QDateTime::fromString(segmentObj.value(QLatin1String("departure")).toString(), Qt::ISODate));
            s.setScheduledArrivalTime(QDateTime::fromString(segmentObj.value(QLatin1String("arrivalScheduled")).toString(), Qt::ISODate));
            s.setExpectedArrivalTime(QDateTime::fromString(segmentObj.value(QLatin1String("arrival")).toString(), Qt::ISODate));

            const auto type = segmentObj.value(QLatin1String("type")).toString();
            // TODO "publicTransport"
            s.setMode(type == QLatin1String("walk") ? JourneySection::Walking : JourneySection::PublicTransport);

            if (s.mode() == JourneySection::PublicTransport) {
                const auto lineObj = segmentObj.value(QLatin1String("line")).toObject();
                s.setRoute(parseRoute(lineObj));
            }

            const auto vias = segmentObj.value(QLatin1String("vias")).toArray();
            std::vector<Stopover> intermediateStops;
            intermediateStops.reserve(vias.size());
            for (const auto &viaV : vias) {
                const auto viaObj = viaV.toObject();
                Stopover stop;
                stop.setStopPoint(parseLocation(viaObj));
                stop.setScheduledDepartureTime(QDateTime::fromString(viaObj.value(QLatin1String("departureScheduled")).toString(), Qt::ISODate));
                stop.setExpectedDepartureTime(QDateTime::fromString(viaObj.value(QLatin1String("departure")).toString(), Qt::ISODate));
                stop.setScheduledArrivalTime(QDateTime::fromString(viaObj.value(QLatin1String("arrivalScheduled")).toString(), Qt::ISODate));
                stop.setExpectedArrivalTime(QDateTime::fromString(viaObj.value(QLatin1String("arrival")).toString(), Qt::ISODate));

                const auto demand = viaObj.value(QLatin1String("demandEstimated"));
                stop.setLoadInformation(parseDemand(demand));

                intermediateStops.push_back(std::move(stop));
            }
            s.setIntermediateStops(std::move(intermediateStops));

            s.setDistance(segmentObj.value(QLatin1String("distance")).toInt());
            const auto polygon = segmentObj.value(QLatin1String("polygon")).toString();
            QPolygonF poly;
            const auto coords = polygon.splitRef(QLatin1Char(' '), Qt::SkipEmptyParts);
            poly.reserve(coords.size());
            for (const auto &coord : coords) {
                const auto p = coord.split(QLatin1Char(','));
                if (p.size() == 2) {
                    poly.push_back({p[0].toDouble(), p[1].toDouble()});
                }
            }
            PathSection section;
            section.setPath(poly);
            Path path;
            path.setSections({section});
            s.setPath(std::move(path));

            const auto highestDemand = segmentObj.value(QLatin1String("highestDemandEstimated"));
            s.setLoadInformation(parseDemand(highestDemand));

            const auto infos = segmentObj.value(QLatin1String("infos")).toArray();
            for (const auto &infoV : infos) {
                const auto infoObj = infoV.toObject();
                s.addNote(infoObj.value(QLatin1String("text")).toString());
            }

            sections.push_back(std::move(s));
        }

        journey.setSections(std::move(sections));
        journeys.push_back(std::move(journey));
    }

    return journeys;
}
