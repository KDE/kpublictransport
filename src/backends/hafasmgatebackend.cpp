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

#include "hafasmgatebackend.h"
#include "hafasmgateparser.h"
#include "logging.h"
#include "cache.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/DepartureReply>
#include <KPublicTransport/DepartureRequest>
#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>

#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMetaEnum>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrlQuery>

using namespace KPublicTransport;

HafasMgateBackend::HafasMgateBackend() = default;

bool HafasMgateBackend::isSecure() const
{
    return m_endpoint.startsWith(QLatin1String("https"));
}

bool HafasMgateBackend::queryJourney(JourneyReply *reply, QNetworkAccessManager *nam) const
{
    m_parser.setLocationIdentifierType(locationIdentifierType());
    const auto request = reply->request();

    const auto fromId = request.from().identifier(locationIdentifierType());
    if (!fromId.isEmpty()) {
        return queryJourney(reply, fromId, nam);
    }

    LocationRequest locReq;
    locReq.setCoordinate(request.from().latitude(), request.from().longitude());
    locReq.setName(request.from().name());
    // TODO set max result = 1

    // check if this location query is cached already
    const auto cacheEntry = Cache::lookupLocation(backendId(), locReq.cacheKey());
    switch (cacheEntry.type) {
        case CacheHitType::Negative:
            addError(reply, Reply::NotFoundError, {});
            return false;
        case CacheHitType::Positive:
            if (cacheEntry.data.size() >= 1) {
                return queryJourney(reply, cacheEntry.data[0].identifier(locationIdentifierType()), nam);
            }
            break;
        case CacheHitType::Miss:
            break;
    }

    // query from location
    const auto locReply = postLocationQuery(locReq, nam);
    if (!locReply) {
        return false;
    }
    QObject::connect(locReply, &QNetworkReply::finished, reply, [this, reply, locReply, locReq, nam]() {
        switch (locReply->error()) {
            case QNetworkReply::NoError:
            {
                auto res = m_parser.parseLocations(locReply->readAll());
                if (m_parser.error() == Reply::NoError && !res.empty()) {
                    Cache::addLocationCacheEntry(backendId(), locReq.cacheKey(), res);
                    const auto id = res[0].identifier(locationIdentifierType());
                    if (!id.isEmpty()) {
                        queryJourney(reply, id, nam);
                    } else {
                        addError(reply, Reply::NotFoundError, QStringLiteral("Location query found no result for departure."));
                    }
                } else {
                    Cache::addNegativeLocationCacheEntry(backendId(), locReq.cacheKey());
                    addError(reply, m_parser.error(), m_parser.errorMessage());
                }
                break;
            }
            default:
                addError(reply, Reply::NetworkError, locReply->errorString());
                qCDebug(Log) << locReply->error() << locReply->errorString();
                break;
        }
        locReply->deleteLater();
    });

    return true;
}

bool HafasMgateBackend::queryJourney(JourneyReply *reply, const QString &fromId, QNetworkAccessManager *nam) const
{
    const auto request = reply->request();

    const auto toId = request.to().identifier(locationIdentifierType());
    if (!toId.isEmpty()) {
        return queryJourney(reply, fromId, toId, nam);
    }

    LocationRequest locReq;
    locReq.setCoordinate(request.to().latitude(), request.to().longitude());
    locReq.setName(request.to().name());
    // TODO set max result = 1

    // check if this location query is cached already
    const auto cacheEntry = Cache::lookupLocation(backendId(), locReq.cacheKey());
    switch (cacheEntry.type) {
        case CacheHitType::Negative:
            addError(reply, Reply::NotFoundError, {});
            return false;
        case CacheHitType::Positive:
            if (cacheEntry.data.size() >= 1) {
                return queryJourney(reply, fromId, cacheEntry.data[0].identifier(locationIdentifierType()), nam);
            }
            break;
        case CacheHitType::Miss:
            break;
    }

    // query to location
    const auto locReply = postLocationQuery(locReq, nam);
    if (!locReply) {
        addError(reply, Reply::NotFoundError, {});
        return false;
    }
    QObject::connect(locReply, &QNetworkReply::finished, reply, [this, fromId, reply, locReply, locReq, nam]() {
        switch (locReply->error()) {
            case QNetworkReply::NoError:
            {
                auto res = m_parser.parseLocations(locReply->readAll());
                if (m_parser.error() == Reply::NoError && !res.empty()) {
                    Cache::addLocationCacheEntry(backendId(), locReq.cacheKey(), res);
                    const auto id = res[0].identifier(locationIdentifierType());
                    if (!id.isEmpty()) {
                        queryJourney(reply, fromId, id, nam);
                    } else {
                        addError(reply, Reply::NotFoundError, QStringLiteral("Location query found no result for arrival."));
                    }
                } else {
                    Cache::addNegativeLocationCacheEntry(backendId(), locReq.cacheKey());
                    addError(reply, m_parser.error(), m_parser.errorMessage());
                }
                break;
            }
            default:
                addError(reply, Reply::NetworkError, locReply->errorString());
                qCDebug(Log) << locReply->error() << locReply->errorString();
                break;
        }
        locReply->deleteLater();
    });

    return true;
}

bool HafasMgateBackend::queryJourney(JourneyReply *reply, const QString &fromId, const QString &toId, QNetworkAccessManager *nam) const
{
    qCDebug(Log) << backendId() << fromId << toId;
    const auto request = reply->request();

    QJsonObject tripSearch;
    {
        QJsonObject cfg;
        cfg.insert(QStringLiteral("polyEnc"), QLatin1String("GPA"));

        QJsonArray arrLocL;
        QJsonObject arrLoc;
        arrLoc.insert(QStringLiteral("extId"), toId);
        arrLoc.insert(QStringLiteral("type"), QLatin1String("S")); // 'S' == station
        arrLocL.push_back(arrLoc);

        QJsonArray depLocL;
        QJsonObject depLoc;
        depLoc.insert(QStringLiteral("extId"), fromId);
        depLoc.insert(QStringLiteral("type"), QLatin1String("S"));
        depLocL.push_back(depLoc);

        QJsonArray jnyFltrL;
        QJsonObject jnyFltr;
        jnyFltr.insert(QStringLiteral("mode"), QLatin1String("BIT"));
        jnyFltr.insert(QStringLiteral("type"), QLatin1String("PROD"));
        jnyFltr.insert(QStringLiteral("value"), QLatin1String("1111111001"));
        jnyFltrL.push_back(jnyFltr);

        QJsonObject req;
        req.insert(QStringLiteral("arrLocL"), arrLocL);
        req.insert(QStringLiteral("depLocL"), depLocL);
        req.insert(QStringLiteral("extChgTime"), -1);
        req.insert(QStringLiteral("getEco"), false);
        req.insert(QStringLiteral("getIST"), false);
        req.insert(QStringLiteral("getPasslist"), true); // ???
        req.insert(QStringLiteral("getPolyline"), false);
        req.insert(QStringLiteral("jnyFltrL"), jnyFltrL);

        req.insert(QStringLiteral("outDate"), request.dateTime().date().toString(QStringLiteral("yyyyMMdd")));
        req.insert(QStringLiteral("outTime"), request.dateTime().time().toString(QStringLiteral("hhmmss")));
        req.insert(QStringLiteral("outFrwd"), true);

        tripSearch.insert(QStringLiteral("cfg"), cfg);
        tripSearch.insert(QStringLiteral("meth"), QLatin1String("TripSearch"));
        tripSearch.insert(QStringLiteral("req"), req);
    }

    auto netReply = postRequest(tripSearch, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [netReply, reply, this]() {
        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                auto res = m_parser.parseJourneys(netReply->readAll());
                if (m_parser.error() == Reply::NoError) {
                    addResult(reply, std::move(res));
                } else {
                    addError(reply, m_parser.error(), m_parser.errorMessage());
                }
                break;
            }
            default:
                addError(reply, Reply::NetworkError, netReply->errorString());
                qCDebug(Log) << netReply->error() << netReply->errorString();
                break;
        }
        netReply->deleteLater();
    });

    return true;
}

bool HafasMgateBackend::queryDeparture(DepartureReply *reply, QNetworkAccessManager *nam) const
{
    m_parser.setLocationIdentifierType(locationIdentifierType());
    const auto request = reply->request();

    const auto id = request.stop().identifier(locationIdentifierType());
    if (!id.isEmpty()) {
        queryDeparture(reply, id, nam);
        return true;
    }

    // missing the station id
    LocationRequest locReq;
    locReq.setCoordinate(request.stop().latitude(), request.stop().longitude());
    locReq.setName(request.stop().name());
    // TODO set max result = 1

    // check if this location query is cached already
    const auto cacheEntry = Cache::lookupLocation(backendId(), locReq.cacheKey());
    switch (cacheEntry.type) {
        case CacheHitType::Negative:
            addError(reply, Reply::NotFoundError, {});
            return false;
        case CacheHitType::Positive:
            if (cacheEntry.data.size() >= 1) {
                queryDeparture(reply, cacheEntry.data[0].identifier(locationIdentifierType()), nam);
                return true;
            }
            break;
        case CacheHitType::Miss:
            break;
    }

    const auto locReply = postLocationQuery(locReq, nam);
    if (!locReply) {
        return false;
    }
    QObject::connect(locReply, &QNetworkReply::finished, reply, [this, reply, locReply, locReq, nam]() {
        qDebug() << locReply->request().url();
        switch (locReply->error()) {
            case QNetworkReply::NoError:
            {
                auto res = m_parser.parseLocations(locReply->readAll());
                if (m_parser.error() == Reply::NoError && !res.empty()) {
                    Cache::addLocationCacheEntry(backendId(), locReq.cacheKey(), res);
                    const auto id = res[0].identifier(locationIdentifierType());
                    if (!id.isEmpty()) {
                        queryDeparture(reply, id, nam);
                    } else {
                        addError(reply, Reply::NotFoundError, QStringLiteral("Location query found no results."));
                    }
                } else {
                    Cache::addNegativeLocationCacheEntry(backendId(), locReq.cacheKey());
                    addError(reply, m_parser.error(), m_parser.errorMessage());
                }
                break;
            }
            default:
                addError(reply, Reply::NetworkError, locReply->errorString());
                qCDebug(Log) << locReply->error() << locReply->errorString();
                break;
        }
        locReply->deleteLater();
    });

    return true;
}

void HafasMgateBackend::queryDeparture(DepartureReply *reply, const QString &locationId, QNetworkAccessManager *nam) const
{
    const auto request = reply->request();

    QJsonObject stationBoard;
    {
        QJsonObject cfg;
        cfg.insert(QStringLiteral("polyEnc"), QLatin1String("GPA"));

        QJsonObject req;
        req.insert(QStringLiteral("date"), request.dateTime().toString(QStringLiteral("yyyyMMdd")));
        req.insert(QStringLiteral("maxJny"), 12);
        req.insert(QStringLiteral("stbFltrEquiv"), true);

        QJsonObject stbLoc;
        stbLoc.insert(QStringLiteral("extId"), locationId);
        stbLoc.insert(QStringLiteral("state"), QLatin1String("F"));
        stbLoc.insert(QStringLiteral("type"), QLatin1String("S"));

        req.insert(QStringLiteral("stbLoc"), stbLoc);
        req.insert(QStringLiteral("time"), request.dateTime().toString(QStringLiteral("hhmmss")));
        req.insert(QStringLiteral("type"), request.mode() == DepartureRequest::QueryDeparture ? QLatin1String("DEP") : QLatin1String("ARR"));

        stationBoard.insert(QStringLiteral("cfg"), cfg);
        stationBoard.insert(QStringLiteral("meth"), QLatin1String("StationBoard"));
        stationBoard.insert(QStringLiteral("req"), req);
    }

    auto netReply = postRequest(stationBoard, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [netReply, reply, this]() {
        qDebug() << netReply->request().url();
        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                auto result = m_parser.parseDepartures(netReply->readAll());
                if (m_parser.error() != Reply::NoError) {
                    addError(reply, m_parser.error(), m_parser.errorMessage());
                    qCDebug(Log) << m_parser.error() << m_parser.errorMessage();
                } else {
                    addResult(reply, std::move(result));
                }
                break;
            }
            default:
                addError(reply, Reply::NetworkError, netReply->errorString());
                qCDebug(Log) << netReply->error() << netReply->errorString();
                break;
        }
        netReply->deleteLater();
    });
}

bool HafasMgateBackend::queryLocation(LocationReply *reply, QNetworkAccessManager *nam) const
{
    m_parser.setLocationIdentifierType(locationIdentifierType());

    const auto req = reply->request();
    const auto netReply = postLocationQuery(req, nam);
    if (!netReply) {
        return false;
    }

    QObject::connect(netReply, &QNetworkReply::finished, reply, [netReply, reply, this]() {
        qDebug() << netReply->request().url();
        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                auto res = m_parser.parseLocations(netReply->readAll());
                if (m_parser.error() == Reply::NoError) {
                    Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), res);
                    addResult(reply, std::move(res));
                } else {
                    Cache::addNegativeLocationCacheEntry(backendId(), reply->request().cacheKey());
                    addError(reply, m_parser.error(), m_parser.errorMessage());
                }
                break;
            }
            default:
                addError(reply, Reply::NetworkError, netReply->errorString());
                qCDebug(Log) << netReply->error() << netReply->errorString();
                break;
        }
        netReply->deleteLater();
    });

    return true;
}

QNetworkReply* HafasMgateBackend::postRequest(const QJsonObject &svcReq, QNetworkAccessManager *nam) const
{
    QJsonObject top;
    {
        QJsonObject auth;
        auth.insert(QStringLiteral("aid"), m_aid);
        auth.insert(QStringLiteral("type"), QLatin1String("AID"));
        top.insert(QStringLiteral("auth"), auth);
    }
    {
        QJsonObject client;
        client.insert(QStringLiteral("id"), m_clientId);
        client.insert(QStringLiteral("type"), m_clientType);
        if (!m_clientVersion.isEmpty()) {
            client.insert(QStringLiteral("v"), m_clientVersion);
        }
        if (!m_clientName.isEmpty()) {
            client.insert(QStringLiteral("name"), m_clientName);
        }
        top.insert(QStringLiteral("client"), client);
    }
    top.insert(QStringLiteral("formatted"), false);
    top.insert(QStringLiteral("lang"), QLatin1String("eng"));
    {
        QJsonArray svcReqs;
        {
            QJsonObject req;
            req.insert(QStringLiteral("getServerDateTime"), true);
            req.insert(QStringLiteral("getTimeTablePeriod"), false);

            QJsonObject serverInfo;
            serverInfo.insert(QStringLiteral("meth"), QLatin1String("ServerInfo"));
            serverInfo.insert(QStringLiteral("req"), req);

            svcReqs.push_back(serverInfo);
        }
        svcReqs.push_back(svcReq);
        top.insert(QStringLiteral("svcReqL"), svcReqs);
    }
    top.insert(QStringLiteral("ver"), m_version);

    const auto content = QJsonDocument(top).toJson(QJsonDocument::Compact);
    QUrl url(m_endpoint);
    QUrlQuery query;
    if (!m_micMacSalt.isEmpty()) {
        QCryptographicHash md5(QCryptographicHash::Md5);
        md5.addData(content);
        const auto mic = md5.result().toHex();
        query.addQueryItem(QStringLiteral("mic"), QString::fromLatin1(mic));

        md5.reset();
        // yes, mic is added as hex-encoded string, and the salt is added as raw bytes
        md5.addData(mic);
        md5.addData(m_micMacSalt);
        query.addQueryItem(QStringLiteral("mac"), QString::fromLatin1(md5.result().toHex()));
    }
    if (!m_checksumSalt.isEmpty()) {
        QCryptographicHash md5(QCryptographicHash::Md5);
        md5.addData(content);
        md5.addData(m_checksumSalt);
        query.addQueryItem(QStringLiteral("checksum"), QString::fromLatin1(md5.result().toHex()));
    }
    url.setQuery(query);

    auto netReq = QNetworkRequest(url);
    netReq.setHeader(QNetworkRequest::ContentTypeHeader, QLatin1String("application/json"));
    qCDebug(Log) << netReq.url();
    //qCDebug(Log).noquote() << QJsonDocument(top).toJson();
    return nam->post(netReq, content);
}

QNetworkReply* HafasMgateBackend::postLocationQuery(const LocationRequest &req, QNetworkAccessManager *nam) const
{
    QJsonObject methodObj;
    if (req.hasCoordinate()) {
        QJsonObject cfg;
        cfg.insert(QStringLiteral("polyEnc"), QLatin1String("GPA"));

        QJsonObject coord;
        coord.insert(QStringLiteral("x"), (int)(req.longitude() * 1000000));
        coord.insert(QStringLiteral("y"), (int)(req.latitude() * 1000000));
        QJsonObject ring;
        ring.insert(QStringLiteral("cCrd"), coord);
        ring.insert(QStringLiteral("maxDist"), 20000); // not sure which unit...

        QJsonObject reqObj;
        reqObj.insert(QStringLiteral("ring"), ring);
        // ### make this configurable in LocationRequest
        reqObj.insert(QStringLiteral("getStops"), true);
        reqObj.insert(QStringLiteral("getPOIs"), false);
        reqObj.insert(QStringLiteral("maxLoc"), 12);

        methodObj.insert(QStringLiteral("cfg"), cfg);
        methodObj.insert(QStringLiteral("meth"), QLatin1String("LocGeoPos"));
        methodObj.insert(QStringLiteral("req"), reqObj);

    } else if (!req.name().isEmpty()) {
        QJsonObject cfg;
        cfg.insert(QStringLiteral("polyEnc"), QLatin1String("GPA"));

        QJsonObject loc;
        loc.insert(QStringLiteral("name"), req.name()); // + '?' for auto completion search?
        loc.insert(QStringLiteral("type"), QLatin1String("S")); // station: S, address: A, POI: P

        QJsonObject input;
        input.insert(QStringLiteral("field"), QLatin1String("S"));
        input.insert(QStringLiteral("loc"), loc);
        // ### make this configurable in LocationRequest
        input.insert(QStringLiteral("maxLoc"), 12);

        QJsonObject reqObj;
        reqObj.insert(QStringLiteral("input"), input);

        methodObj.insert(QStringLiteral("cfg"), cfg);
        methodObj.insert(QStringLiteral("meth"), QLatin1String("LocMatch"));
        methodObj.insert(QStringLiteral("req"), reqObj);

    } else {
        return nullptr;
    }

    return postRequest(methodObj, nam);
}

void HafasMgateBackend::setMicMacSalt(const QString &salt)
{
    m_micMacSalt = QByteArray::fromHex(salt.toUtf8());
}

void HafasMgateBackend::setChecksumSalt(const QString &salt)
{
    m_checksumSalt = QByteArray::fromHex(salt.toUtf8());
}

void HafasMgateBackend::setLineModeMap(const QJsonObject& obj)
{
    const auto idx = Line::staticMetaObject.indexOfEnumerator("Mode");
    Q_ASSERT(idx >= 0);
    const auto me = Line::staticMetaObject.enumerator(idx);

    std::unordered_map<int, Line::Mode> modeMap;
    for (auto it = obj.begin(); it != obj.end(); ++it) {
        modeMap[it.key().toInt()] = static_cast<Line::Mode>(me.keyToValue(it.value().toString().toUtf8().constData()));
    }
    m_parser.setLineModeMap(std::move(modeMap));
}

QString HafasMgateBackend::locationIdentifierType() const
{
    return m_locationIdentifierType.isEmpty() ? backendId() : m_locationIdentifierType;
}
