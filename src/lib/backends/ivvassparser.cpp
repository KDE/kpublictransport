/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "ivvassparser.h"
#include "ivvassproductmap.h"
#include "ifopt/ifoptutil.h"

#include <KPublicTransport/Equipment>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Stopover>

#include <QByteArray>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRegularExpression>

#include <cmath>

using namespace KPublicTransport;

IvvAssParser::IvvAssParser(const QTimeZone &tz, const QString &locationIdentifier)
    : m_timezone(tz)
    , m_locationIdentifier(locationIdentifier)
{
}

IvvAssParser::LocationData IvvAssParser::parseLocation(const QJsonObject &stopObj) const
{
    LocationData r;
    r.loc.setLatitude(stopObj.value(QLatin1String("lat")).toDouble(NAN));
    r.loc.setLongitude(stopObj.value(QLatin1String("lon")).toDouble(NAN));
    if (!r.loc.hasCoordinate()) {
        // sic, x/y are swapped here!
        r.loc.setLatitude(stopObj.value(QLatin1String("x")).toDouble(NAN));
        r.loc.setLongitude(stopObj.value(QLatin1String("y")).toDouble(NAN));
    }

    r.loc.setName(stopObj.value(QLatin1String("name")).toString());
    if (r.loc.name().isEmpty()) {
        r.loc.setName(stopObj.value(QLatin1String("description")).toString());
    }
    r.loc.setLocality(stopObj.value(QLatin1String("city")).toString());
    if (r.loc.locality().isEmpty()) {
        r.loc.setLocality(stopObj.value(QLatin1String("municipality")).toString());
    }

    if (stopObj.value(QLatin1String("type")).toString() == QLatin1String("coordinate")) {
        return r;
    }

    const auto id = stopObj.value(IfoptUtil::identifierType()).toString();
    if (IfoptUtil::isValid(id)) {
        r.loc.setIdentifier(IfoptUtil::identifierType(), id);
    } else {
        r.loc.setIdentifier(m_locationIdentifier, id);
    }

    // location is a platform: split out platform name
    if (stopObj.value(QLatin1String("subtype")).toString() == QLatin1String("Post")) {
        static QRegularExpression rx(QStringLiteral(R"((.*) \(((:?Gleis|Bahnsteig) .*)\)$)"));
        const auto match = rx.match(r.loc.name());
        if (match.hasMatch()) {
            r.loc.setName(match.captured(1));
            r.platform = match.captured(2);
        }
    }

    r.loc.setType(Location::Stop);
    return r;
}

std::vector<Location> IvvAssParser::parseLocations(const QByteArray &data)
{
    const auto top = QJsonDocument::fromJson(data).object();
    if (!parseError(top)) {
        return {};
    }
    std::vector<Location> locs;

    const auto stops = top.value(QLatin1String("stops")).toArray();
    locs.reserve(stops.size());
    for (const auto &stopV : stops) {
        const auto stopObj = stopV.toObject();
        locs.push_back(parseLocation(stopObj).loc);
    }
    const auto objects = top.value(QLatin1String("objects")).toArray();
    locs.reserve(locs.size() + objects.size());
    for (const auto &objectV : objects) {
        const auto obj = objectV.toObject();
        const auto type = obj.value(QLatin1String("type")).toString();
        if (type != QLatin1String("stop")) { // poi, parking, etc
            continue;
        }
        locs.push_back(parseLocation(obj).loc);

        const auto elevators = obj.value(QLatin1String("elevators")).toArray();
        const auto escalators = obj.value(QLatin1String("escalators")).toArray();
        locs.reserve(locs.size() + elevators.size() + escalators.size());
        for (const auto &eleV : elevators) {
            const auto eleObj = eleV.toObject();
            auto ele = parseLocation(eleObj).loc;
            Equipment eq;
            eq.setType(Equipment::Elevator);
            eq.setDisruptionEffect(eleObj.value(QLatin1String("status")).toString() == QLatin1String("active") ? Disruption::NormalService : Disruption::NoService);
            ele.setData(std::move(eq));
            ele.setType(Location::Equipment);
            locs.push_back(std::move(ele));
        }
        for (const auto &escV : escalators) {
            const auto escObj = escV.toObject();
            auto esc = parseLocation(escObj).loc;
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
        auto v = parseLocation(vehicleV.toObject()).loc;
        v.setType(Location::RentedVehicle); // TODO can we get vehicle types and networks from somewhere?
        locs.push_back(std::move(v));
    }

    return locs;
}

static Route parseRoute(const QJsonObject &lineObj)
{
    Line line;
    line.setName(lineObj.value(QLatin1String("number")).toString());
    line.setMode(IvvAssProductMap::parseProduct(lineObj.value(QLatin1String("product")).toString()));

    Route route;
    route.setLine(std::move(line));
    route.setDirection(lineObj.value(QLatin1String("direction")).toString());
    return route;
}

static void applyTimeZone(QDateTime &dt, const QTimeZone &tz)
{
    if (dt.timeSpec() == Qt::OffsetFromUTC && tz.offsetFromUtc(dt) == dt.offsetFromUtc()) {
        dt.setTimeZone(tz);
    }
}

IvvAssParser::EventTime IvvAssParser::parseTime(const QJsonObject &obj, const char *baseKey, const char *scheduledKey) const
{
    EventTime t;
    t.scheduled = QDateTime::fromString(obj.value(QLatin1String(scheduledKey)).toString(), Qt::ISODate);
    t.expected = QDateTime::fromString(obj.value(QLatin1String(baseKey)).toString(), Qt::ISODate);
    if (!t.scheduled.isValid() && t.expected.isValid()) {
        std::swap(t.scheduled, t.expected);
    }
    applyTimeZone(t.scheduled, m_timezone);
    applyTimeZone(t.expected, m_timezone);
    return t;
}

std::vector<Stopover> IvvAssParser::parseStopovers(const QByteArray &data)
{
    const auto top = QJsonDocument::fromJson(data).object();
    if (!parseError(top)) {
        return {};
    }
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
            s.setStopPoint(stop.loc);
            s.setScheduledPlatform(stop.platform);
            const auto t = parseTime(eventObj, "departure", "departureScheduled");
            s.setScheduledDepartureTime(t.scheduled);
            s.setExpectedDepartureTime(t.expected);

            const auto lineObj = eventObj.value(QLatin1String("line")).toObject();
            s.setRoute(parseRoute(lineObj));

            const auto postObj = eventObj.value(QLatin1String("post")).toObject();
            const auto postName = postObj.value(QLatin1String("name")).toString();
            if (postName.startsWith(QLatin1Char('(')) && postName.endsWith(QLatin1Char(')'))) {
                s.setScheduledPlatform(postName.mid(1, postName.size() - 2));
            } else {
                s.setScheduledPlatform(postName);
            }

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

static Path parseDirections(Path &&fullPath, const QJsonArray &directions)
{
    if (directions.isEmpty() || fullPath.isEmpty()) {
        return std::move(fullPath);
    }

    const auto poly = fullPath.sections()[0].path();

    Path p;
    std::vector<PathSection> secs;

    int prevSecStart = 0;
    PathSection prevSec;

    for (const auto &dirV : directions) {
        const auto dirObj = dirV.toObject();
        const auto lat = dirObj.value(QLatin1String("x")).toDouble();
        const auto lon = dirObj.value(QLatin1String("y")).toDouble();

        int nextSecStart = prevSecStart;
        for (; nextSecStart < poly.size(); ++nextSecStart) {
            if (Location::distance(lat, lon, poly[nextSecStart].y(), poly[nextSecStart].x()) < 1.0) {
                break;
            }
        }

        if (nextSecStart > prevSecStart) {
            QPolygonF subPoly;
            subPoly.reserve(nextSecStart - prevSecStart + 1);
            std::copy(poly.begin() + prevSecStart, poly.begin() + nextSecStart, std::back_inserter(subPoly));
            subPoly.push_back({lon, lat});
            prevSec.setPath(std::move(subPoly));
            secs.push_back(prevSec);
        }
        prevSecStart = nextSecStart;
        prevSec.setDescription(dirObj.value(QLatin1String("street")).toString());
    }
    if (poly.size() > prevSecStart) {
        QPolygonF subPoly;
        subPoly.reserve(poly.size() - prevSecStart);
        std::copy(poly.begin() + prevSecStart, poly.end(), std::back_inserter(subPoly));
        prevSec.setPath(std::move(subPoly));
        secs.push_back(prevSec);
    }

    p.setSections(std::move(secs));
    return p;
}

std::vector<Journey> IvvAssParser::parseJourneys(const QByteArray &data)
{
    const auto top = QJsonDocument::fromJson(data).object();
    if (!parseError(top)) {
        return {};
    }
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

            const auto origin = parseLocation(segmentObj.value(QLatin1String("origin")).toObject());
            s.setFrom(origin.loc);
            s.setScheduledDeparturePlatform(origin.platform);
            const auto dest = parseLocation(segmentObj.value(QLatin1String("destination")).toObject());
            s.setTo(dest.loc);
            s.setScheduledArrivalPlatform(dest.platform);

            const auto dt = parseTime(segmentObj, "departure", "departureScheduled");
            s.setScheduledDepartureTime(dt.scheduled);
            s.setExpectedDepartureTime(dt.expected);
            const auto at = parseTime(segmentObj, "arrival", "arrivalScheduled");
            s.setScheduledArrivalTime(at.scheduled);
            s.setExpectedArrivalTime(at.expected);

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
                const auto viaLoc = parseLocation(viaObj);
                stop.setStopPoint(viaLoc.loc);
                stop.setScheduledPlatform(viaLoc.platform);

                const auto dt = parseTime(viaObj, "departure", "departureScheduled");
                stop.setScheduledDepartureTime(dt.scheduled);
                stop.setExpectedDepartureTime(dt.expected);
                const auto at = parseTime(viaObj, "arrival", "arrivalScheduled");
                stop.setScheduledArrivalTime(at.scheduled);
                stop.setExpectedArrivalTime(at.expected);

                const auto demand = viaObj.value(QLatin1String("demandEstimated"));
                stop.setLoadInformation(parseDemand(demand));

                intermediateStops.push_back(std::move(stop));
            }
            s.setIntermediateStops(std::move(intermediateStops));

            s.setDistance(segmentObj.value(QLatin1String("distance")).toInt());
            const auto polygon = segmentObj.value(QLatin1String("polygon")).toString();
            QPolygonF poly;
            const auto coords = QStringView(polygon).split(QLatin1Char(' '), Qt::SkipEmptyParts);
            poly.reserve(coords.size());
            for (const auto &coord : coords) {
                const auto p = coord.split(QLatin1Char(','));
                if (p.size() == 2) {
                    poly.push_back({p[1].toDouble(), p[0].toDouble()});
                }
            }
            PathSection section;
            section.setPath(poly);
            Path path;
            path.setSections({section});
            s.setPath(parseDirections(std::move(path), segmentObj.value(QLatin1String("directions")).toArray()));

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

bool IvvAssParser::parseError(const QJsonObject &top)
{
    errorMessage = top.value(QLatin1String("error")).toString();
    return errorMessage.isEmpty();
}
