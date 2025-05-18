/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "deutschebahnbackend.h"
#include "deutschebahnparser.h"
#include "deutschebahnproducts.h"
#include "deutschebahnvehiclelayoutparser.h"
#include "cache.h"
#include "logging.h"

#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopoverReply>
#include <KPublicTransport/StopoverRequest>
#include <KPublicTransport/TripReply>
#include <KPublicTransport/TripRequest>
#include <KPublicTransport/VehicleLayoutReply>
#include <KPublicTransport/VehicleLayoutRequest>

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QRegularExpression>
#include <QUrl>
#include <QUrlQuery>

using namespace Qt::Literals;
using namespace KPublicTransport;

AbstractBackend::Capabilities DeutscheBahnBackend::capabilities() const
{
    if (m_bypassDbApi) {
        return HafasMgateBackend::capabilities();
    }

    return  Secure | CanQueryArrivals | CanQueryPreviousDeparture | CanQueryPreviousJourney | CanQueryNextJourney;
}

bool DeutscheBahnBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    if (m_bypassDbApi) {
        return HafasMgateBackend::needsLocationQuery(loc, type);
    }

    switch (type) {
        case AbstractBackend::QueryType::Departure:
            return locationIdentifier(loc).isEmpty() && !loc.hasIdentifier(hafasIdentifier());
        case AbstractBackend::QueryType::Journey:
            return !loc.hasIdentifier(hafasIdentifier());
    }

    return true;
}

bool DeutscheBahnBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if (m_bypassDbApi) {
        return HafasMgateBackend::queryLocation(req, reply, nam);
    }

    QUrl url;
    QUrlQuery query;
    if (req.hasCoordinate()) {
        url = QUrl(u"https://www.bahn.de/web/api/reiseloesung/orte/nearby"_s);
        query.addQueryItem(u"lat"_s, QString::number(req.location().latitude()));
        query.addQueryItem(u"long"_s, QString::number(req.location().longitude()));
        query.addQueryItem(u"radius"_s, QString::number(req.maximumDistance()));
        // products[]=<...> product categories
        query.addQueryItem(u"maxNo"_s, QString::number(req.maximumResults()));
    } else {
        url = QUrl(u"https://www.bahn.de/web/api/reiseloesung/orte"_s);
        query.addQueryItem(u"suchbegriff"_s, req.location().name());
        query.addQueryItem(u"typ"_s, u"ALL"_s); // ???
        query.addQueryItem(u"limit"_s, QString::number(req.maximumResults()));
    }
    url.setQuery(query);
    qCDebug(Log) << url;

    const auto netReq = makeHafasProxyRequest(url);
    logRequest(req, netReq);
    auto netReply = nam->get(netReq);
    netReply->setParent(reply);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply] {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, reply->errorString());
            return;
        }

        std::vector<Location> locs = DeutscheBahnParser::parseLocations(data, m_parser);
        Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), locs, {});
        addResult(reply, std::move(locs));
    });

    return true;
}

struct {
    Line::Mode mode;
    const char *name;
} constexpr static const line_mode_map[] = {
    { Line::Boat, "SCHIFF" },
    { Line::Bus, "BUS" },
    { Line::Coach, "BUS" },
    { Line::Ferry, "SCHIFF" },
    { Line::Funicular, "TRAM" },
    { Line::LocalTrain, "REGIONAL" },
    { Line::LongDistanceTrain, "ICE" },
    { Line::LongDistanceTrain, "EC_IC" },
    { Line::Train, "ICE" },
    { Line::Train, "EC_IC" },
    { Line::Train, "IR" },
    // { Line::Train, "REGIONAL" }, ### semantics?
    { Line::Metro, "UBAHN" },
    { Line::RapidTransit, "SBAHN" },
    { Line::Shuttle, "BUS" },
    { Line::Taxi, "ANRUFPFLICHTIG" },
    { Line::Tramway, "TRAM" },
};

[[nodiscard]] static QStringList lineModesForRequest(const std::vector<Line::Mode> &modes)
{
    QStringList l;
    for (auto mode : modes) {
        for (const auto &m : line_mode_map) {
            if (m.mode == mode) {
                l.push_back(QLatin1StringView(m.name));
            }
        }
    }
    l.removeDuplicates();
    return l;
}

bool DeutscheBahnBackend::queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    if (m_bypassDbApi) {
        return HafasMgateBackend::queryStopover(request, reply, nam);
    }

    auto url = request.mode() == StopoverRequest::QueryDeparture ?
        QUrl(u"https://www.bahn.de/web/api/reiseloesung/abfahrten"_s) :
        QUrl(u"https://www.bahn.de/web/api/reiseloesung/ankuenfte"_s);

    // paging uses a fixed 1h window
    auto dt = request.dateTime().toTimeZone(timeZone());
    const auto ctx = requestContext(request);
    if (ctx.type == RequestContext::Previous) {
        dt = ctx.dateTime.addSecs(-3600);
    }

    QUrlQuery query;
    query.addQueryItem(u"datum"_s, dt.date().toString(Qt::ISODate));
    query.addQueryItem(u"zeit"_s, dt.time().toString(Qt::ISODate));
    auto stopId = locationIdentifier(request.stop());
    if (stopId.isEmpty()) {
        stopId = request.stop().identifier(hafasIdentifier());
    }
    query.addQueryItem(u"ortId"_s, stopId);
    query.addQueryItem(u"mitVias"_s, u"true"_s);
    query.addQueryItem(u"maxVias"_s, request.mode() == StopoverRequest::QueryDeparture ? u"2"_s : u"100"_s); // "1" results in 0 vias, "2" in two...

    const auto modes = lineModesForRequest(request.lineModes());
    for (const auto &m : modes) {
        query.addQueryItem(u"verkehrsmittel[]"_s, m);
    }
    url.setQuery(query);
    qCDebug(Log) << url;

    const auto netReq = makeHafasProxyRequest(url);
    logRequest(request, netReq);
    auto netReply = nam->get(netReq);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, reply->errorString());
            return;
        }

        const auto responseObj = QJsonDocument::fromJson(data).object();
        const auto stopsArray = responseObj.value("entries"_L1).toArray();
        std::vector<Stopover> stops = DeutscheBahnParser::parseStopovers(stopsArray, reply->request().mode() == StopoverRequest::QueryDeparture, m_parser);
        addResult(reply, this, std::move(stops));
    });

    return true;
}

bool DeutscheBahnBackend::queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    if (m_bypassDbApi) {
        return HafasMgateBackend::queryJourney(request, reply, nam);
    }

    if ((request.modes() & JourneySection::PublicTransport) == 0) {
        return false;
    }

    const auto modesStr = lineModesForRequest(request.lineModes());
    QJsonArray modes;
    std::copy(modesStr.begin(), modesStr.end(), std::back_inserter(modes));

    auto dt = request.dateTime().toTimeZone(timeZone());
    dt.setTimeZone(QTimeZone::LocalTime);
    QJsonObject postObj({
        {"abfahrtsHalt"_L1, request.from().identifier(hafasIdentifier())},
        {"anfrageZeitpunkt"_L1, dt.toString(Qt::ISODate)},
        {"ankunftsHalt"_L1, request.to().identifier(hafasIdentifier())},
        {"ankunftSuche"_L1, request.dateTimeMode() == JourneyRequest::Departure ? "ABFAHRT"_L1 : "ANKUNFT"_L1},
        {"klasse"_L1, "KLASSE_2"_L1},
        {"produktgattungen"_L1, modes},
        {"reisende"_L1, QJsonArray({QJsonObject{
            {"typ"_L1, "ERWACHSENER"_L1},
            {"ermaessigungen"_L1, QJsonArray({QJsonObject{
                {"art"_L1, "KEINE_ERMAESSIGUNG"_L1},
                {"klasse"_L1, "KLASSENLOS"_L1}
            }})},
            {"alter"_L1, QJsonArray()},
            {"anzahl"_L1, 1},
        }})},
        {"schnelleVerbindungen"_L1, true},
        {"sitzplatzOnly"_L1, false},
        {"bikeCarriage"_L1, request.requiresBikeTransport()},
        {"reservierungsKontingenteVorhanden"_L1, false},
        {"nurDeutschlandTicketVerbindungen"_L1, false},
        {"deutschlandTicketVorhanden"_L1, false}
    });
    if (const auto pagingRef = requestContextData(request).toString(); !pagingRef.isEmpty()) {
        postObj.insert("pagingReference"_L1, pagingRef);
    }
    QUrl url(u"https://www.bahn.de/web/api/angebote/fahrplan"_s);
    qDebug() << postObj;

    const auto postData = QJsonDocument(postObj).toJson(QJsonDocument::Compact);
    auto netReq = makeHafasProxyRequest(url);
    netReq.setHeader(QNetworkRequest::ContentTypeHeader, QByteArrayLiteral("application/json"));
    logRequest(request, netReq, postData);
    auto netReply = nam->post(netReq, postData);
    netReply->setParent(reply);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply] {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, reply->errorString());
            return;
        }

        const auto responseObj = QJsonDocument::fromJson(data).object();
        const auto pagingRefs = responseObj.value("verbindungReference"_L1).toObject();
        setPreviousRequestContext(reply, pagingRefs.value("earlier"_L1).toString());
        setNextRequestContext(reply, pagingRefs.value("later"_L1).toString());

        const auto journeysArray = responseObj.value("verbindungen"_L1).toArray();
        std::vector<Journey> journeys = DeutscheBahnParser::parseJourneys(journeysArray, m_parser);
        addResult(reply, this, std::move(journeys));
    });

    return true;
}

bool DeutscheBahnBackend::queryTrip(const TripRequest &request, TripReply *reply, QNetworkAccessManager *nam) const
{
    if (m_bypassDbApi) {
        return HafasMgateBackend::queryTrip(request, reply, nam);
    }

    const auto tripId = request.identifier(locationIdentifierType());
    if (tripId.isEmpty()) {
        return false;
    }

    QUrl url(u"https://www.bahn.de/web/api/reiseloesung/fahrt"_s);
    QUrlQuery query;
    query.addQueryItem(u"journeyId"_s, tripId);
    query.addQueryItem(u"poly"_s, u"true"_s);
    url.setQuery(query);
    qCDebug(Log) << url;

    const auto netReq = makeHafasProxyRequest(url);
    logRequest(request, netReq);
    auto netReply = nam->get(netReq);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply, tripId]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, reply->errorString());
            return;
        }

        const auto responseObj = QJsonDocument::fromJson(data).object();
        auto jny = DeutscheBahnParser::parseTrip(responseObj, m_parser);
        jny.setIdentifier(locationIdentifierType(), tripId); // not contained in the response
        addResult(reply, this, std::move(jny));
    });

    return true;
}

QString DeutscheBahnBackend::hafasIdentifier() const
{
    return locationIdentifierType() + "-hafas"_L1;
}

QNetworkRequest DeutscheBahnBackend::makeHafasProxyRequest(const QUrl &url) const
{
    QNetworkRequest netRequest(url);
    netRequest.setRawHeader("Accept-Language", preferredLanguage().toUtf8());
    return netRequest;
}

struct TrainNum {
    QString category;
    QString number;
};

static TrainNum extractTrainNumber(const Route &route)
{
    TrainNum trainNum;
    QRegularExpression rx(u"([A-Z]+)?\\s*(\\d+)"_s);

    if (!route.name().isEmpty()) {
        const auto match = rx.match(route.name());
        if (match.hasMatch()) {
            trainNum = { match.captured(1), match.captured(2) };
        }
    }

    const auto line = route.line();
    const auto match = rx.match(line.modeString() + line.name());
    if (match.hasMatch()) {
        if (trainNum.category.isEmpty()) {
            trainNum.category = match.captured(1);
        }
        if (trainNum.number.isEmpty()) {
            trainNum.number = match.captured(2);
        }
    }

    return trainNum;
}

bool DeutscheBahnBackend::queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const
{
    // unlike the rest of the DB API, this only works in Germany, so do our own geo filtering here.
    const auto germanyBBox = QPolygonF({ {5.56384, 55.0492}, {6.131, 47.2565}, {15.4307, 47.4737}, {14.6794, 54.7568} });
    if (!germanyBBox.containsPoint({request.stopover().stopPoint().longitude(), request.stopover().stopPoint().latitude()}, Qt::WindingFill)) {
        qDebug() << "request outside of bounding box";
        return false;
    }

    const auto ibnr = request.stopover().stopPoint().identifier("ibnr"_L1);
    const auto dt = request.stopover().scheduledDepartureTime().isValid() ? request.stopover().scheduledDepartureTime() : request.stopover().scheduledArrivalTime();
    const auto [trainCategory, trainNum] = extractTrainNumber(request.stopover().route());
    if (!dt.isValid() || trainNum.isEmpty() || !DeutscheBahnProducts::isValid(trainCategory) || ibnr.isEmpty()) {
        return false;
    }

    QUrl url;
    url.setScheme(u"https"_s);
    url.setHost(u"www.bahn.de"_s);
    url.setPath(u"/web/api/reisebegleitung/wagenreihung/vehicle-sequence"_s);
    QUrlQuery query;
    query.addQueryItem(u"category"_s, trainCategory);
    query.addQueryItem(u"number"_s, trainNum);
    query.addQueryItem(u"date"_s, dt.date().toString(u"yyyy-MM-dd"));
    query.addQueryItem(u"time"_s, dt.toUTC().toString(Qt::ISODate));
    query.addQueryItem(u"evaNumber"_s, ibnr);
    url.setQuery(query);
    qDebug() << url;

    QNetworkRequest netReq(url);
    logRequest(request, netReq);
    auto netReply = nam->get(netReq);
    netReply->setParent(reply);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() == QNetworkReply::NoError) {
            auto res = DeutscheBahnVehicleLayoutParser::parse(data);
            Cache::addVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey(), res, {}, std::chrono::minutes(2));
            addResult(reply, res);
        } else {
            addError(reply, Reply::NotFoundError, reply->errorString());
            Cache::addNegativeVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey(), std::chrono::hours(24));
        }
        netReply->deleteLater();
    });

    return true;
}
