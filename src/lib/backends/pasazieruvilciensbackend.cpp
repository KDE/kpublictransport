/*
    SPDX-FileCopyrightText: 2023 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "pasazieruvilciensbackend.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

#include <QJsonDocument>
#include <QJsonArray>

#include "datatypes/stopover.h"
#include "journeyreply.h"
#include "journeyrequest.h"
#include "locationrequest.h"
#include "locationreply.h"

using namespace KPublicTransport;


PasazieruVilciensBackend::PasazieruVilciensBackend()
    : AbstractBackend()
{
}

AbstractBackend::Capabilities PasazieruVilciensBackend::capabilities() const
{
    return Secure;
}

bool PasazieruVilciensBackend::needsLocationQuery(const Location &loc, QueryType type) const
{
    Q_UNUSED(type);
    return loc.identifier(QStringLiteral("pvint")).isEmpty();
}

bool PasazieruVilciensBackend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    if (m_stations.empty()) {
        QObject::connect(this, &PasazieruVilciensBackend::newStationData, this, [=, this]() {
                queryJourney(req, reply, nam);
            }, Qt::SingleShotConnection);
        const_cast<PasazieruVilciensBackend *>(this)->downloadStationData(reply, nam);

        return true;
    }

    auto reqUrl = QUrl(QStringLiteral("https://pvapi.pv.lv/api/gettrip"));
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("stationAId"), req.from().identifier(QStringLiteral("pvint")));
    query.addQueryItem(QStringLiteral("stationBId"), req.to().identifier(QStringLiteral("pvint")));
    query.addQueryItem(QStringLiteral("date"), QDate::currentDate().toString(Qt::ISODate));
    reqUrl.setQuery(query);

    auto netReply = nam->get(QNetworkRequest(reqUrl));
    QObject::connect(netReply, &QNetworkReply::finished, netReply, [=, this]() {
        auto jsonValue = QJsonDocument::fromJson(netReply->readAll());
        const auto data = jsonValue[QStringLiteral("data")].toArray();

        if (data.empty()) {
            addResult(reply, this, std::vector<Journey>{});
        }

        auto journeys = std::make_shared<std::vector<Journey>>();
        auto runningRequests = std::make_shared<int>();

        for (const auto tripJson : data) {
            QTimeZone tz("Europe/Riga");

            auto arrival = QDateTime::fromSecsSinceEpoch(qint64(tripJson[QStringLiteral("arrival")].toDouble())).toTimeZone(tz);
            auto departure = QDateTime::fromSecsSinceEpoch(qint64(tripJson[QStringLiteral("departure")].toDouble())).toTimeZone(tz);

            // Filter for requested arrival / departure time frame
            if (req.dateTimeMode() == JourneyRequest::Departure) {
                if (departure < req.dateTime()) {
                    continue;
                }
            } else {
                if (arrival > req.dateTime()) {
                    continue;
                }
            }

            QUrl detailsUrl(QStringLiteral("https://pvapi.pv.lv/api/getroute"));
            QUrlQuery query;
            query.addQueryItem(QStringLiteral("stationAId"), req.from().identifier(QStringLiteral("pvint")));
            query.addQueryItem(QStringLiteral("stationBId"), req.to().identifier(QStringLiteral("pvint")));
            query.addQueryItem(QStringLiteral("getRouteId"), QString::number(tripJson[QStringLiteral("getRouteId")].toInt()));
            query.addQueryItem(QStringLiteral("lang"), QStringLiteral("en"));
            detailsUrl.setQuery(query);

            auto trainNr = tripJson[QStringLiteral("trainNr")].toString();
            bool isBus = tripJson[QStringLiteral("bus")].toBool();
            auto routeName = tripJson[QStringLiteral("name")].toString();

            auto detailsReply = nam->get(QNetworkRequest(detailsUrl));
            (*runningRequests)++;
            QObject::connect(detailsReply, &QNetworkReply::finished, this, [=, this]() {
                const auto jsonValue = QJsonDocument::fromJson(detailsReply->readAll());
                const auto data = jsonValue[QStringLiteral("data")][QStringLiteral("route")].toArray();

                auto isStop = [](const auto &stop) -> bool {
                    return stop.value(QStringLiteral("type")).toString() == QStringLiteral("stop");
                };

                std::vector<QJsonObject> stops;
                for (const auto &item : data) {
                    auto stop = item.toObject();
                    if (isStop(stop)) {
                        stops.push_back(std::move(stop));
                    }
                }

                Line line;
                line.setName(trainNr);
                line.setMode(isBus ? Line::Mode::Bus : Line::Mode::Train);

                Route route;
                route.setName(routeName);
                route.setLine(line);

                Journey journey;
                JourneySection section;
                section.setRoute(route);
                section.setFrom(req.from());
                section.setTo(req.to());
                section.setScheduledDepartureTime(departure);
                section.setScheduledArrivalTime(arrival);
                section.setMode(JourneySection::Mode::PublicTransport);

                std::vector<Stopover> stopovers;
                bool atDestionation = false;
                bool afterStart = false;
                for (const auto &stop : parseStopovers(std::move(stops), arrival)) {
                    if (stop.stopPoint().identifier(QStringLiteral("pvint")) == req.to().identifier(QStringLiteral("pvint"))) {
                        atDestionation = true;
                    }

                    if (!atDestionation && afterStart) {
                        stopovers.push_back(stop);
                    }

                    if (stop.stopPoint().identifier(QStringLiteral("pvint")) == req.from().identifier(QStringLiteral("pvint"))) {
                        afterStart = true;
                    }
                }
                section.setIntermediateStops(std::move(stopovers));

                journey.setSections({section});
                journeys->push_back(std::move(journey));

                (*runningRequests)--;

                if (*runningRequests == 0) {
                    Attribution attribution;
                    attribution.setName(QStringLiteral("Pasazieru vilciens"));
                    attribution.setUrl(QUrl(QStringLiteral("https://pv.lv")));

                    addResult(reply, this, std::move(*journeys));
                    addAttributions(reply, {attribution});
                }
            });
        }
    });

    return true;
}

bool PasazieruVilciensBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if (m_stations.empty()) {
        QObject::connect(this, &PasazieruVilciensBackend::newStationData, this, [=, this]() {
            queryLocation(req, reply, nam);
            }, Qt::SingleShotConnection);
        const_cast<PasazieruVilciensBackend *>(this)->downloadStationData(reply, nam);

        return true;
    }

    std::vector<Location> locations;
    for (auto [id, station] : std::as_const(m_stations)) {
        if (station.name.contains(req.name())) {
            auto loc = stationToLocation(std::move(station));
            locations.push_back(std::move(loc));
        }
    }

    addResult(reply, std::move(locations));

    return false;
}

void PasazieruVilciensBackend::downloadStationData(Reply *reply, QNetworkAccessManager *nam)
{
    auto *netReply = nam->get(QNetworkRequest(QUrl(QStringLiteral("https://pvapi.pv.lv/api/getallStations/"))));
    QObject::connect(netReply, &QNetworkReply::finished, this, [=, this]() {
        const auto bytes = netReply->readAll();

        logReply(reply, netReply, bytes);

        const auto jsonValue = QJsonDocument::fromJson(bytes);
        const auto data = jsonValue[QStringLiteral("data")].toArray();


        for (const auto &stationJson : data) {
            m_stations.insert({qint64(stationJson[QStringLiteral("id")].toDouble()),
                Station {
                    .id = qint64(stationJson[QStringLiteral("id")].toDouble()),
                    .name = stationJson[QStringLiteral("name")].toString(),
                    .latitude = static_cast<float>(stationJson[QStringLiteral("latitude")].toDouble()),
                    .longitude = static_cast<float>(stationJson[QStringLiteral("longitude")].toDouble())
                }});
        }

        Q_EMIT newStationData();
    });
}

Location PasazieruVilciensBackend::stationToLocation(Station &&station)
{
    Location loc;
    loc.setCoordinate(station.latitude, station.longitude);
    loc.setIdentifier(QStringLiteral("pvint"), QString::number(station.id));
    loc.setName(station.name);
    loc.setType(Location::Stop);
    return loc;
}

std::vector<Stopover> PasazieruVilciensBackend::parseStopovers(std::vector<QJsonObject> &&stops, const QDateTime &startTime) const {
    std::vector<Stopover> stopovers;

    for (auto &&stopoverJson : stops) {
        Stopover stopover;
        auto arrivalTime = QTime::fromString(stopoverJson[QStringLiteral("time")].toString());
        auto arrivalDateTime = startTime.date().startOfDay(); // TODO what about multi-day travel?
        arrivalDateTime.setTime(arrivalTime);
        arrivalDateTime.setTimeZone(QTimeZone("Europe/Riga"));

        stopover.setScheduledArrivalTime(arrivalDateTime);
        stopover.setScheduledDepartureTime(arrivalDateTime);
        stopover.setStopPoint(stationToLocation(Station(m_stations.at(stopoverJson[QStringLiteral("stationId")].toInt()))));
        stopovers.push_back(std::move(stopover));
    }

    return stopovers;
}
