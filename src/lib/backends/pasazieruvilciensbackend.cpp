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
#include "localbackendutils.h"

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
    if (m_stations.empty() && !m_fetchingStations) {
        QObject::disconnect(this, &PasazieruVilciensBackend::newStationData, nullptr, nullptr);
        QObject::connect(this, &PasazieruVilciensBackend::newStationData, this, [=, this]() {
                queryJourney(req, reply, nam);
            }, Qt::SingleShotConnection);
        const_cast<PasazieruVilciensBackend *>(this)->downloadStationData(reply, nam);

        return true;
    }

    auto tripResult = fetchTrip(req, nam);
    auto joinedTripResult = fetchJoinedTrip(req, nam);

    auto processResults = [=, this]() {
        std::vector<Journey> results = *tripResult->results;
        results.insert(results.end(), joinedTripResult->results->begin(), joinedTripResult->results->end());
        std::sort(results.begin(), results.end(), [](const Journey &a, const Journey &b) {
            return a.scheduledDepartureTime() < b.scheduledDepartureTime();
        });

        addResult(reply, this, std::move(results));

        Attribution attribution;
        attribution.setName(QStringLiteral("Pasazieru vilciens"));
        attribution.setUrl(QUrl(QStringLiteral("https://pv.lv")));
        addAttributions(reply, {attribution});
    };

    connect(tripResult.get(), &PendingQuery::finished, this, [=, this]() {
        if (joinedTripResult->results) {
            processResults();
        } else {
            connect(joinedTripResult.get(), &PendingQuery::finished, this, processResults);
        }
    });

    return true;
}

bool PasazieruVilciensBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if (m_stations.empty() && !m_fetchingStations) {
        QObject::disconnect(this, &PasazieruVilciensBackend::newStationData, nullptr, nullptr);
        QObject::connect(this, &PasazieruVilciensBackend::newStationData, this, [=, this]() {
            queryLocation(req, reply, nam);
        }, Qt::SingleShotConnection);
        const_cast<PasazieruVilciensBackend *>(this)->downloadStationData(reply, nam);

        return true;
    }

    std::vector<Location> locations;
    QString name = LocalBackendUtils::makeSearchableName(req.name());

    for (auto [id, station] : std::as_const(m_stations)) {
        if (station.searchableName.contains(name)) {
            auto loc = stationToLocation(station);
            locations.push_back(std::move(loc));
        }
    }

    addResult(reply, std::move(locations));

    return false;
}

void PasazieruVilciensBackend::downloadStationData(Reply *reply, QNetworkAccessManager *nam)
{
    m_fetchingStations = true;

    auto *netReply = nam->get(QNetworkRequest(QUrl(QStringLiteral("https://pvapi.pv.lv/api/getallStations/"))));
    QObject::connect(netReply, &QNetworkReply::finished, this, [=, this]() {
        const auto bytes = netReply->readAll();

        logReply(reply, netReply, bytes);

        if (!m_stations.empty()) {
            return;
        }

        const auto jsonValue = QJsonDocument::fromJson(bytes);
        const auto data = jsonValue[QStringLiteral("data")].toArray();

        for (const auto &stationJson : data) {
            const QString name = stationJson[u"name"].toString();
            m_stations.insert({int(stationJson[u"id"].toDouble()),
                PV::Station {
                    .id = int(stationJson[QStringLiteral("id")].toDouble()),
                    .name = name,
                    .searchableName = LocalBackendUtils::makeSearchableName(name),
                    .latitude = static_cast<float>(stationJson[u"latitude"].toDouble()),
                    .longitude = static_cast<float>(stationJson[u"longitude"].toDouble())
                }});
        }

        Q_EMIT newStationData();

        m_fetchingStations = false;
        netReply->deleteLater();
    });
}

std::shared_ptr<PendingQuery> PasazieruVilciensBackend::fetchTrip(const JourneyRequest &req, QNetworkAccessManager *nam) const
{
    auto pendingQuery = std::make_shared<PendingQuery>();

    auto reqUrl = QUrl(QStringLiteral("https://pvapi.pv.lv/api/gettrip"));
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("stationAId"), req.from().identifier(QStringLiteral("pvint")));
    query.addQueryItem(QStringLiteral("stationBId"), req.to().identifier(QStringLiteral("pvint")));
    query.addQueryItem(QStringLiteral("date"), req.dateTime().date().toString(Qt::ISODate));
    reqUrl.setQuery(query);

    auto netReply = nam->get(QNetworkRequest(reqUrl));
    QObject::connect(netReply, &QNetworkReply::finished, netReply, [=, this]() {
        auto jsonValue = QJsonDocument::fromJson(netReply->readAll());
        const auto data = jsonValue[u"data"].toArray();

        if (data.empty()) {
            pendingQuery->reportFinished({});
        }

        auto journeys = std::make_shared<std::vector<Journey>>();
        auto runningRequests = std::make_shared<int>();

        bool foundAny = false;
        for (const auto tripJson : data) {
            QTimeZone tz("Europe/Riga");

            auto arrival = QDateTime::fromSecsSinceEpoch(qint64(tripJson[QStringLiteral("arrival")].toDouble())).toTimeZone(tz);
            auto departure = QDateTime::fromSecsSinceEpoch(qint64(tripJson[QStringLiteral("departure")].toDouble())).toTimeZone(tz);

            // Filter for requested arrival / departure time frame
            if (!LocalBackendUtils::isInSelectedTimeframe(departure, arrival, req)) {
                continue;
            }

            foundAny = true;

            QUrl detailsUrl(QStringLiteral("https://pvapi.pv.lv/api/getroute"));
            QUrlQuery query;
            query.addQueryItem(QStringLiteral("stationAId"), req.from().identifier(QStringLiteral("pvint")));
            query.addQueryItem(QStringLiteral("stationBId"), req.to().identifier(QStringLiteral("pvint")));
            query.addQueryItem(QStringLiteral("getRouteId"), QString::number(tripJson[QStringLiteral("getRouteId")].toInt()));
            query.addQueryItem(QStringLiteral("lang"), QStringLiteral("en"));
            detailsUrl.setQuery(query);

            auto trainNr = tripJson[u"trainNr"].toString();
            bool isBus = tripJson[u"bus"].toBool();
            auto routeName = tripJson[u"name"].toString();
            QString platform = tripJson[u"roadNumber"].toString();

            auto detailsReply = nam->get(QNetworkRequest(detailsUrl));
            (*runningRequests)++;
            QObject::connect(detailsReply, &QNetworkReply::finished, this, [=, this]() {
                const auto jsonValue = QJsonDocument::fromJson(detailsReply->readAll());
                auto stopsJson = prepareStops(jsonValue[u"data"][u"route"].toArray());
                auto stops = parseStopovers({stopsJson.begin() + 1, stopsJson.end() - 1}, departure);

                JourneySection section;
                section.setFrom(req.from());
                section.setTo(req.to());
                section.setScheduledDeparturePlatform(platform);

                section.setScheduledDepartureTime(departure);
                section.setScheduledArrivalTime(arrival);

                section.setMode(JourneySection::Mode::PublicTransport);
                section.setIntermediateStops(std::move(stops));

                Line line;
                line.setName(trainNr);
                line.setMode(isBus ? Line::Mode::Bus : Line::Mode::Train);

                Route route;
                route.setName(routeName);
                route.setLine(line);

                section.setRoute(route);

                Journey journey;
                journey.setSections({section});
                journeys->push_back(std::move(journey));

                (*runningRequests)--;

                if (*runningRequests == 0) {
                    pendingQuery->reportFinished(std::move(*journeys));
                }
            });
        }

        if (!foundAny) {
            pendingQuery->reportFinished({});
        }

        netReply->deleteLater();
    });

    return pendingQuery;
}

std::shared_ptr<PendingQuery> PasazieruVilciensBackend::fetchJoinedTrip(const JourneyRequest &req, QNetworkAccessManager *nam) const
{
    auto pendingQuery = std::make_shared<PendingQuery>();

    QUrl reqUrl(QStringLiteral("https://pvapi.pv.lv/api/getjoinedtrip"));
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("stationAId"), req.from().identifier(QStringLiteral("pvint")));
    query.addQueryItem(QStringLiteral("stationBId"), req.to().identifier(QStringLiteral("pvint")));
    query.addQueryItem(QStringLiteral("date"), req.dateTime().date().toString(Qt::ISODate));
    reqUrl.setQuery(query);

    auto netReply = nam->get(QNetworkRequest(reqUrl));
    QObject::connect(netReply, &QNetworkReply::finished, this, [=, this]() {
        auto joinedTrip = QJsonDocument::fromJson(netReply->readAll());
        auto data = joinedTrip[QStringLiteral("data")].toArray();

        auto journeys = std::make_shared<std::vector<Journey>>();
        auto runningRequests = std::make_shared<int>();

        bool foundAny = false;
        for (const auto &tripJson : data) {
            QTimeZone tz("Europe/Riga");

            auto arrival = QDateTime::fromSecsSinceEpoch(qint64(tripJson[QStringLiteral("arrival")].toDouble())).toTimeZone(tz);
            auto departure = QDateTime::fromSecsSinceEpoch(qint64(tripJson[QStringLiteral("departure")].toDouble())).toTimeZone(tz);

            auto route1Id = tripJson[u"leg1routeId"].toString();
            auto route2Id = tripJson[u"leg2routeId"].toString();

            auto startStationId = tripJson[u"startStationId"].toString();
            auto startTime = parseDateTime(tripJson[u"startTime"].toString(), departure.date());
            auto startTrainNr = tripJson[u"startTrainNumber"].toString();

            auto transferStationId = tripJson[u"transferPlaceId"].toString();
            auto transferArriveTime = parseDateTime(tripJson[u"transferArriveTime"].toString(), departure.date(), startTime);
            auto transferLeaveTime = parseDateTime(tripJson[u"transferLeaveTime"].toString(), departure.date(), transferArriveTime);

            auto endStationId = tripJson[u"endStationId"].toString();
            auto endTime = parseDateTime(tripJson[u"endTime"].toString(), departure.date(), transferLeaveTime);
            auto endTrainNr = tripJson[u"endTrainNumber"].toString();

            // Filter for requested arrival / departure time frame
            if (!LocalBackendUtils::isInSelectedTimeframe(departure, arrival, req)) {
                continue;
            }

            foundAny = true;

            auto startTrainNumber = tripJson[QStringLiteral("startTrainNr")].toString();
            auto endTrainNumber = tripJson[QStringLiteral("endTrainNr")].toString();

            QUrl detailsUrl(QStringLiteral("https://pvapi.pv.lv/api/getjoinedroute"));
            QUrlQuery query;
            query.addQueryItem(QStringLiteral("stationAId"), startStationId);
            query.addQueryItem(QStringLiteral("stationBId"), endStationId);
            query.addQueryItem(QStringLiteral("stationXId"), transferStationId);
            query.addQueryItem(QStringLiteral("leg1RouteId"), route1Id);
            query.addQueryItem(QStringLiteral("leg2RouteId"), route2Id);
            query.addQueryItem(QStringLiteral("lang"), QStringLiteral("en"));
            detailsUrl.setQuery(query);

            auto detailsReply = nam->get(QNetworkRequest(detailsUrl));
            (*runningRequests)++;

            connect(detailsReply, &QNetworkReply::finished, this, [=, this]() {
                auto jsonValue = QJsonDocument::fromJson(detailsReply->readAll());
                auto stopovers = jsonValue[u"data"][u"route"].toArray();

                auto [stopOversAJson, stopOversBJson] = splitJoinedSections(std::move(stopovers));

                auto stopoversA = parseStopovers(std::move(stopOversAJson), departure);
                auto stopoversB = parseStopovers(std::move(stopOversBJson), departure);

                JourneySection sectionA;
                sectionA.setFrom(lookupStation(startStationId.toInt()));
                sectionA.setTo(lookupStation(transferStationId.toInt()));
                sectionA.setScheduledDepartureTime(startTime);
                sectionA.setScheduledArrivalTime(transferArriveTime);
                sectionA.setIntermediateStops(std::move(stopoversA));
                sectionA.setMode(JourneySection::Mode::PublicTransport);

                Line lineA;
                lineA.setName(startTrainNr);
                lineA.setMode(Line::Mode::Train);

                Route routeA;
                routeA.setLine(lineA);

                sectionA.setRoute(routeA);

                JourneySection sectionB;
                sectionB.setFrom(lookupStation(transferStationId.toInt()));
                sectionB.setTo(lookupStation(endStationId.toInt()));
                sectionB.setScheduledDepartureTime(transferLeaveTime);
                sectionB.setScheduledArrivalTime(endTime);
                sectionB.setIntermediateStops(std::move(stopoversB));
                sectionB.setMode(JourneySection::Mode::PublicTransport);

                Line lineB;
                lineB.setName(endTrainNr);
                lineB.setMode(Line::Mode::Train);

                Route routeB;
                routeB.setLine(lineB);

                sectionB.setRoute(routeB);

                Journey journey;
                journey.setSections({sectionA, sectionB});
                journeys->push_back(std::move(journey));

                (*runningRequests)--;

                if (*runningRequests == 0) {
                    pendingQuery->reportFinished(std::move(*journeys));
                }
            });
        }

        if (!foundAny) {
            pendingQuery->reportFinished({});
        }

        netReply->deleteLater();
    });

    return pendingQuery;
}

Location PasazieruVilciensBackend::stationToLocation(const PV::Station &station)
{
    Location loc;
    loc.setCoordinate(station.latitude, station.longitude);
    loc.setIdentifier(QStringLiteral("pvint"), QString::number(station.id));
    loc.setName(station.name);
    loc.setType(Location::Stop);
    return loc;
}

Location PasazieruVilciensBackend::lookupStation(int pvint) const
{
    const auto &station = m_stations.at(pvint);
    return stationToLocation(station);
}

std::vector<Stopover> PasazieruVilciensBackend::parseStopovers(std::vector<QJsonObject> &&stops, const QDateTime &startTime) const {
    std::vector<Stopover> stopovers;

    // Just to ensure timestamps can't go backwards
    QDateTime previousArrivalTime;

    for (auto &&stopoverJson : stops) {
        Stopover stopover;

        QDateTime arrivalDateTime = parseDateTime(stopoverJson[QStringLiteral("time")].toString(), startTime.date(), arrivalDateTime);
        previousArrivalTime = arrivalDateTime;

        stopover.setScheduledArrivalTime(arrivalDateTime);
        stopover.setScheduledDepartureTime(arrivalDateTime);
        stopover.setStopPoint(stationToLocation(m_stations.at(stopoverJson[QStringLiteral("stationId")].toInt())));
        stopovers.push_back(std::move(stopover));
    }

    return stopovers;
}

std::vector<QJsonObject> PasazieruVilciensBackend::prepareStops(QJsonArray &&data) const
{
    // Drop items not part of the route and items that are unsupported
    std::vector<QJsonValueRef> filteredItems;
    std::copy_if(data.begin(), data.end(), std::back_inserter(filteredItems), [](const auto &item) {
        const auto obj = item.toObject();
        const auto type = obj[QStringLiteral("type")].toString();
        bool inRoute = obj[QStringLiteral("inRoute")].toBool();
        return (type == QStringLiteral("stop") || type == QStringLiteral("transfer")) && inRoute;
    });

    // Convert all elements in the array to objects
    std::vector<QJsonObject> items;
    std::transform(filteredItems.begin(), filteredItems.end(), std::back_inserter(items), [](auto &&item) {
        return item.toObject();
    });

    return items;
}

std::tuple<std::vector<QJsonObject>, std::vector<QJsonObject>> PasazieruVilciensBackend::splitJoinedSections(QJsonArray &&data) const
{
    auto route = prepareStops(std::move(data));

    // find the transfer
    auto endTransferIt = std::find_if(route.begin(), route.end(), [](const auto &item) {
        return item[u"type"].toString() == u"transfer";
    });
    Q_ASSERT(endTransferIt != route.end());

    auto startTransferIt = std::find_if(endTransferIt + 1, route.end(), [](const auto &item) {
        return item[u"type"].toString() == u"transfer";
    });
    Q_ASSERT(startTransferIt != route.end());

    // Copy stopovers between start and transfer, transfer and end
    std::vector firstPart(route.begin() + 1, endTransferIt);
    std::vector secondPart(startTransferIt + 1, route.end() - 1);

    return {firstPart, secondPart};
}

QDateTime PasazieruVilciensBackend::parseDateTime(const QString &timeString, const QDate &date, const QDateTime &knownPreviousTime) const
{
    auto time = QTime::fromString(timeString);

    auto dateTime = date.startOfDay();
    dateTime.setTime(time);
    dateTime.setTimeZone(QTimeZone("Europe/Riga"));

    if (!knownPreviousTime.isNull() && dateTime < knownPreviousTime) {
        dateTime.setDate(dateTime.date().addDays(1));
    }

    return dateTime;
}
