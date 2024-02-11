/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "motisparser.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>

using namespace KPublicTransport;
using namespace Qt::Literals::StringLiterals;

MotisParser::MotisParser(QString locIdentifierType)
    : m_locIdentifierType(std::move(locIdentifierType))
{
}

bool MotisParser::hasError() const
{
    return !m_errorMsg.isEmpty();
}

QString MotisParser::errorMessage() const
{
    return m_errorMsg;
}

std::vector<Journey> MotisParser::parseConnections(const QByteArray &data)
{
    const auto content = parseContent(data);
    if (hasError()) {
        return {};
    }
    const auto connections = content.value("connections"_L1).toArray();

    std::vector<Journey> journeys;
    journeys.reserve(connections.size());

    for (const auto &conV :connections) {
        journeys.push_back(parseConnection(conV.toObject()));
    }

    return journeys;
}

[[nodiscard]] static QDateTime scheduledTime(const QJsonObject &eventInfo)
{
    const auto ts = eventInfo.value("schedule_time"_L1).toInteger();
    return ts ? QDateTime::fromSecsSinceEpoch(ts) : QDateTime();
}

[[nodiscard]] static QDateTime expectedTime(const QJsonObject &eventInfo)
{
    const auto reason = eventInfo.value("reason"_L1).toString();
    if (reason == "SCHEDULE"_L1 || reason == "REPAIR"_L1) {
        return {};
    }
    const auto ts = eventInfo.value("time"_L1).toInteger();
    return ts ? QDateTime::fromSecsSinceEpoch(ts) : QDateTime();
}

[[nodiscard]] static QString expectedPlatform(const QJsonObject &eventInfo)
{
    if (eventInfo.value("reason"_L1).toString() == "SCHEDULE"_L1) {
        return {};
    }
    return eventInfo.value("track"_L1).toString();
}

// see https://motis-project.de/docs/api/connection.html#transport
constexpr inline Line::Mode clasz_map[] = {
    Line::Air,               // 0 flights
    Line::LongDistanceTrain, // 1 long distance high speed trains (e.g. TGV)
    Line::LongDistanceTrain, // 2 long distance inter city trains
    Line::Coach,             // 3 long distance buses
    Line::LongDistanceTrain, // 4 long distance night trains
    Line::LocalTrain,        // 5 regional express trains
    Line::LocalTrain,        // 6 regional trains
    Line::RapidTransit,      // 7 metro trains
    Line::Metro,             // 8 subway trains
    Line::Tramway,           // 9 trams
    Line::Bus,               // 10 buses
    Line::Ferry,             // 11 ships/ferries
    Line::Taxi,              // 12 other (taxis, etc.)
};

// TODO do we generally need this, or can this eventually be fixed/normalized server-side?
static void postprocessRoute(Route &route)
{
    auto l = route.line();
    if (l.mode() == Line::Metro && l.name().endsWith(" 0"_L1)) {
        l.setName(l.name().left(l.name().size() - 2));
    }
    if (l.mode() == Line::Tramway && l.name().startsWith("Tram "_L1)) {
        l.setName(l.name().mid(5));
    }
    while (l.mode() == Line::LongDistanceTrain && l.name().startsWith("ICE 0"_L1)) {
        l.setName(l.name().remove(4, 1));
    }
    while (l.mode() == Line::LongDistanceTrain && l.name().startsWith("IC 0"_L1)) {
        l.setName(l.name().remove(3, 1));
    }
    route.setLine(l);
}

[[nodiscard]] static Route parseRoute(const QJsonObject &obj)
{
    Line line;
    line.setName(obj.value("name"_L1).toString()); // TODO use category_name and line_id instead?
    if (const auto provider = obj.value("provider"_L1).toString(); !provider.isEmpty() && provider != "UNKNOWN_AGENCY"_L1) {
        line.setOperatorName(provider);
    }
    const auto clasz = obj.value("clasz"_L1).toInt();
    if (clasz >= 0 && clasz < (int)std::size(clasz_map)) {
        line.setMode(clasz_map[clasz]);
    }
    Route route;
    route.setDirection(obj.value("direction"_L1).toString());
    const auto trainNr = obj.value("train_nr"_L1).toInt();
    if (trainNr) { // TODO skip is already in line name?
        route.setName(QString::number(trainNr));
    }
    route.setLine(line);
    postprocessRoute(route);
    return route;
}

Journey MotisParser::parseConnection(const QJsonObject &con) const
{
    const auto stopsA = con.value("stops"_L1).toArray();
    std::vector<Stopover> stops;
    stops.reserve(stopsA.size());
    for (const auto &stopV : stopsA) {
        const auto stopObj = stopV.toObject();
        Stopover stop;
        stop.setStopPoint(parseStation(stopObj.value("station"_L1).toObject()));
        if (const auto dep = stopObj.value("departure"_L1).toObject(); dep.value("valid"_L1).toBool()) {
            stop.setScheduledDepartureTime(scheduledTime(dep));
            stop.setExpectedDepartureTime(expectedTime(dep));
            if (const auto p = dep.value("schedule_track"_L1).toString(); !p.isEmpty()) {
                stop.setScheduledPlatform(p);
            }
            if (const auto p = expectedPlatform(dep); !p.isEmpty()) {
                stop.setExpectedPlatform(p);
            }
        }
        if (const auto arr = stopObj.value("arrival"_L1).toObject(); arr.value("valid"_L1).toBool()) {
            stop.setScheduledArrivalTime(scheduledTime(arr));
            stop.setExpectedArrivalTime(expectedTime(arr));
            if (const auto p = arr.value("schedule_track"_L1).toString(); !p.isEmpty() && stop.scheduledPlatform().isEmpty()) {
                stop.setScheduledPlatform(p);
            }
            if (const auto p = expectedPlatform(arr); !p.isEmpty() && stop.expectedPlatform().isEmpty()) {
                stop.setExpectedPlatform(p);
            }
        }
        stops.push_back(std::move(stop));
    }

    // TODO parse notes and attributes

    const auto transports = con.value("transports"_L1).toArray();
    std::vector<JourneySection> sections;
    sections.reserve(transports.size());
    for (const auto &transportV :transports) {
        const auto transport = transportV.toObject();
        const auto move = transport.value("move"_L1).toObject();
        const auto range = move.value("range"_L1).toObject();
        const auto from = range.value("from"_L1).toInteger();
        const auto to = range.value("to"_L1).toInteger();
        if (from < 0 || from >= (qint64)stops.size() || to < 0 || to >= (qint64)stops.size() || to <= from) {
            qWarning() << "invalid range indices!";
            return {};
        }

        JourneySection sec;
        sec.setDeparture(stops[from]);
        sec.setArrival(stops[to]);
        if (to - from > 1) {
            std::vector<Stopover> intermediateStops;
            intermediateStops.reserve(to - from);
            std::copy(stops.begin() + from + 1, stops.begin() + to, std::back_inserter(intermediateStops));
            sec.setIntermediateStops(std::move(intermediateStops));
        }

        const auto moveType = transport.value("move_type"_L1).toString();
        if (moveType == "Transport"_L1) {
            sec.setMode(JourneySection::PublicTransport);
        } else if (moveType == "Walk"_L1) {
            const auto mumoType = move.value("mumo_type"_L1).toString();
            if (mumoType == "bike"_L1) {
                sec.setMode(JourneySection::IndividualTransport);
                sec.setIndividualTransport(IndividualTransport(IndividualTransport::Bike));
            } else if (mumoType == "car"_L1) {
                sec.setMode(JourneySection::IndividualTransport);
                sec.setIndividualTransport(IndividualTransport(IndividualTransport::Car));
            } else {
                sec.setMode(JourneySection::Walking);
            }
        } else {
            qWarning() << "unknown move_type" << moveType;
        }

        if (sec.mode() == JourneySection::PublicTransport) {
            sec.setRoute(parseRoute(move));
        }

        sections.push_back(std::move(sec));
    }

    Journey jny;
    jny.setSections(std::move(sections));
    return jny;
}

std::vector<Stopover> MotisParser::parseEvents(const QByteArray &data)
{
    const auto content = parseContent(data);
    if (hasError()) {
        return {};
    }

    const auto stopPoint = parseStation(content.value("station"_L1).toObject());

    const auto events = content.value("events"_L1).toArray();
    std::vector<Stopover> result;
    std::vector<QString> ids;
    for (const auto &eventV : events) {
        const auto event = eventV.toObject();

        Stopover stop;
        stop.setStopPoint(stopPoint);
        const auto ev = event.value("event"_L1).toObject();
        if (!ev.value("valid"_L1).toBool()) {
            continue;
        }
        const auto type = event.value("type"_L1).toString();
        if (type == "DEP"_L1) {
            stop.setScheduledDepartureTime(scheduledTime(ev));
            stop.setExpectedDepartureTime(expectedTime(ev));
        } else if (type == "ARR"_L1) {
            stop.setScheduledArrivalTime(scheduledTime(ev));
            stop.setExpectedArrivalTime(expectedTime(ev));
        } else {
            continue;
        }
        if (const auto p = ev.value("schedule_track"_L1).toString(); !p.isEmpty()) {
            stop.setScheduledPlatform(p);
        }
        if (const auto p = expectedPlatform(ev); !p.isEmpty()) {
            stop.setExpectedPlatform(p);
        }

        const auto trips = event.value("trips"_L1).toArray();
        if (trips.empty()) {
            continue;
        }
        const auto trip = trips.at(0).toObject();
        stop.setRoute(parseRoute(trip.value("transport"_L1).toObject()));
        // TODO what's in the id block next to transport? train_nr and destination stop ids seem relevant?

        // merge disjoint arrival/departure events
        const auto id = trip.value("id"_L1).toObject().value("id"_L1).toString();
        if (auto it = std::find(ids.begin(), ids.end(), id); it != ids.end())  {
            result[std::distance(ids.begin(), it)] = Stopover::merge(result[std::distance(ids.begin(), it)], stop);
        } else {
            result.push_back(std::move(stop));
            ids.push_back(id);
        }
    }

    return result;
}

std::vector<Location> MotisParser::parseStations(const QByteArray &data)
{
    const auto content = parseContent(data);
    if (hasError()) {
        return {};
    }

    QJsonArray stations;
    if (content.contains("guesses"_L1)) {
        stations = content.value("guesses"_L1).toArray();
    } else {
        stations = content.value("stations"_L1).toArray();
    }

    std::vector<Location> result;
    result.reserve(stations.size());
    for (const auto &stationV : stations) {
        result.push_back(parseStation(stationV.toObject()));
    }

    return result;
}

Location MotisParser::parseStation(const QJsonObject &station) const
{
    Location loc;
    loc.setType(Location::Stop);
    loc.setIdentifier(m_locIdentifierType, station.value("id"_L1).toString());
    loc.setName(station.value("name"_L1).toString());
    const auto pos = station.value("pos"_L1).toObject();
    loc.setLatitude((float)pos.value("lat"_L1).toDouble());
    loc.setLongitude((float)pos.value("lng"_L1).toDouble());
    return loc;
}

QJsonObject MotisParser::parseContent(const QByteArray &data)
{
    const auto top = QJsonDocument::fromJson(data).object();
    auto content = top.value("content"_L1).toObject();

    if (top.value("content_type"_L1).toString() == "MotisError"_L1) {
        m_errorMsg = content.value("reason"_L1).toString();
    }

    return content;
}
