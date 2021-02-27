/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasmgatebackend.h"
#include "hafasmgateparser.h"
#include "logging.h"
#include "cache.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopoverReply>
#include <KPublicTransport/StopoverRequest>

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
#include <QVersionNumber>

using namespace KPublicTransport;

HafasMgateBackend::HafasMgateBackend() = default;
HafasMgateBackend::~HafasMgateBackend() = default;

void HafasMgateBackend::init()
{
    m_parser.setLocationIdentifierTypes(locationIdentifierType(), standardLocationIdentifierType());
    m_parser.setLineModeMap(std::move(m_lineModeMap));
    m_parser.setStandardLocationIdentfierCountries(std::move(m_uicCountryCodes));
}

AbstractBackend::Capabilities HafasMgateBackend::capabilities() const
{
    return (m_endpoint.startsWith(QLatin1String("https")) ? Secure : NoCapability) | CanQueryArrivals;
}

bool HafasMgateBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    Q_UNUSED(type);
    return !loc.hasCoordinate() && locationIdentifier(loc).isEmpty();
}

QJsonObject HafasMgateBackend::locationToJson(const Location &loc) const
{
    QJsonObject obj;

    const auto id = locationIdentifier(loc);
    if (!id.isEmpty()) {
        obj.insert(QStringLiteral("extId"), id);
        obj.insert(QStringLiteral("type"), QStringLiteral("S")); // 'S' == station
    }

    else if (loc.hasCoordinate()) {
        QJsonObject crd;
        crd.insert(QStringLiteral("y"), (int)(loc.latitude() * 1000000));
        crd.insert(QStringLiteral("x"), (int)(loc.longitude() * 1000000));
        obj.insert(QStringLiteral("crd"), crd);
        obj.insert(QStringLiteral("type"), QStringLiteral("C")); // 'C' == coordinate
    }

    return obj;
}

bool HafasMgateBackend::queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    if ((request.modes() & JourneySection::PublicTransport) == 0) {
        return false;
    }

    QJsonObject tripSearch;
    {
        QJsonObject cfg;
        cfg.insert(QStringLiteral("polyEnc"), QLatin1String("GPA"));

        const auto depLoc = locationToJson(request.from());
        const auto arrLoc = locationToJson(request.to());
        if (depLoc.isEmpty() || arrLoc.isEmpty()) {
            return false;
        }
        QJsonArray depLocL;
        depLocL.push_back(depLoc);
        QJsonArray arrLocL;
        arrLocL.push_back(arrLoc);

        QJsonObject req;
        req.insert(QStringLiteral("arrLocL"), arrLocL);
        req.insert(QStringLiteral("depLocL"), depLocL);
        req.insert(QStringLiteral("extChgTime"), -1);
        req.insert(QStringLiteral("getEco"), false);
        req.insert(QStringLiteral("getIST"), false);
        req.insert(QStringLiteral("getPasslist"), request.includeIntermediateStops());
        req.insert(QStringLiteral("getPolyline"), request.includePaths());
        req.insert(QStringLiteral("numF"), request.maximumResults());

        QDateTime dt = request.dateTime();
        if (timeZone().isValid()) {
            dt = dt.toTimeZone(timeZone());
        }
        req.insert(QStringLiteral("outDate"), dt.date().toString(QStringLiteral("yyyyMMdd")));
        req.insert(QStringLiteral("outTime"), dt.time().toString(QStringLiteral("hhmmss")));
        req.insert(QStringLiteral("outFrwd"), request.dateTimeMode() == JourneyRequest::Departure);

        tripSearch.insert(QStringLiteral("cfg"), cfg);
        tripSearch.insert(QStringLiteral("meth"), QLatin1String("TripSearch"));
        tripSearch.insert(QStringLiteral("req"), req);
    }

    QByteArray postData;
    const auto netRequest = makePostRequest(tripSearch, postData);
    logRequest(request, netRequest, postData);
    auto netReply = nam->post(netRequest, postData);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [netReply, reply, this]() {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                auto res = m_parser.parseJourneys(data);
                if (m_parser.error() == Reply::NoError) {
                    addResult(reply, this, std::move(res));
                } else {
                    addError(reply, m_parser.error(), m_parser.errorMessage());
                }
                break;
            }
            default:
                addError(reply, Reply::NetworkError, netReply->errorString());
                break;
        }
        netReply->deleteLater();
    });

    return true;
}

bool HafasMgateBackend::queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    const auto stbLoc = locationToJson(request.stop());
    if (stbLoc.isEmpty()) {
        return false;
    }

    QJsonObject stationBoard;
    {
        QJsonObject cfg;
        cfg.insert(QStringLiteral("polyEnc"), QLatin1String("GPA"));

        QDateTime dt = request.dateTime();
        if (timeZone().isValid()) {
            dt = dt.toTimeZone(timeZone());
        }

        QJsonObject req;
        req.insert(QStringLiteral("date"), dt.toString(QStringLiteral("yyyyMMdd")));
        req.insert(QStringLiteral("maxJny"), request.maximumResults());
        // stbFltrEquiv is no longer allowed above API version 1.20
        if (QVersionNumber::fromString(m_version) < QVersionNumber(1, 20)) {
            req.insert(QStringLiteral("stbFltrEquiv"), true);
        }

        req.insert(QStringLiteral("stbLoc"), stbLoc);
        req.insert(QStringLiteral("time"), dt.toString(QStringLiteral("hhmmss")));
        req.insert(QStringLiteral("type"), request.mode() == StopoverRequest::QueryDeparture ? QLatin1String("DEP") : QLatin1String("ARR"));

        stationBoard.insert(QStringLiteral("cfg"), cfg);
        stationBoard.insert(QStringLiteral("meth"), QLatin1String("StationBoard"));
        stationBoard.insert(QStringLiteral("req"), req);
    }

    QByteArray postData;
    const auto netRequest = makePostRequest(stationBoard, postData);
    logRequest(request, netRequest, postData);
    auto netReply = nam->post(netRequest, postData);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [netReply, reply, this]() {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);
        qDebug() << netReply->request().url();

        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                auto result = m_parser.parseDepartures(data);
                if (m_parser.error() != Reply::NoError) {
                    addError(reply, m_parser.error(), m_parser.errorMessage());
                } else {
                    addResult(reply, this, std::move(result));
                }
                break;
            }
            default:
                addError(reply, Reply::NetworkError, netReply->errorString());
                break;
        }
        netReply->deleteLater();
    });

    return true;
}

bool HafasMgateBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if ((req.types() & Location::Stop) == 0) {
        return false;
    }

    QJsonObject methodObj;
    if (req.hasCoordinate()) {
        QJsonObject cfg;
        cfg.insert(QStringLiteral("polyEnc"), QLatin1String("GPA"));

        QJsonObject coord;
        coord.insert(QStringLiteral("x"), (int)(req.longitude() * 1000000));
        coord.insert(QStringLiteral("y"), (int)(req.latitude() * 1000000));
        QJsonObject ring;
        ring.insert(QStringLiteral("cCrd"), coord);
        ring.insert(QStringLiteral("maxDist"), std::max(1, req.maximumDistance()));

        QJsonObject reqObj;
        reqObj.insert(QStringLiteral("ring"), ring);
        // ### make this configurable in LocationRequest
        reqObj.insert(QStringLiteral("getStops"), true);
        reqObj.insert(QStringLiteral("getPOIs"), false);
        reqObj.insert(QStringLiteral("maxLoc"), std::max(1, req.maximumResults()));

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
        input.insert(QStringLiteral("maxLoc"), std::max(1, req.maximumResults()));

        QJsonObject reqObj;
        reqObj.insert(QStringLiteral("input"), input);

        methodObj.insert(QStringLiteral("cfg"), cfg);
        methodObj.insert(QStringLiteral("meth"), QLatin1String("LocMatch"));
        methodObj.insert(QStringLiteral("req"), reqObj);

    } else {
        return false;
    }

    QByteArray postData;
    const auto netRequest = makePostRequest(methodObj, postData);
    logRequest(req, netRequest, postData);
    const auto netReply = nam->post(netRequest, postData);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [netReply, reply, this]() {
        qDebug() << netReply->request().url();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                auto res = m_parser.parseLocations(data);
                if (m_parser.error() == Reply::NoError) {
                    Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), res, {});
                    addResult(reply, std::move(res));
                } else {
                    addError(reply, m_parser.error(), m_parser.errorMessage());
                }
                break;
            }
            default:
                addError(reply, Reply::NetworkError, netReply->errorString());
                break;
        }
        netReply->deleteLater();
    });

    return true;
}

QNetworkRequest HafasMgateBackend::makePostRequest(const QJsonObject &svcReq, QByteArray &postData) const
{
    QJsonObject top;
    top.insert(QStringLiteral("auth"), m_auth);
    top.insert(QStringLiteral("client"), m_client);
    if (!m_extParam.isEmpty()) {
        top.insert(QStringLiteral("ext"), m_extParam);
    }
    top.insert(QStringLiteral("formatted"), false);
    top.insert(QStringLiteral("lang"), preferredLanguage());
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

    postData = QJsonDocument(top).toJson(QJsonDocument::Compact);
    QUrl url(m_endpoint);
    QUrlQuery query;
    if (!m_micMacSalt.isEmpty()) {
        QCryptographicHash md5(QCryptographicHash::Md5);
        md5.addData(postData);
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
        md5.addData(postData);
        md5.addData(m_checksumSalt);
        query.addQueryItem(QStringLiteral("checksum"), QString::fromLatin1(md5.result().toHex()));
    }
    url.setQuery(query);

    auto netReq = QNetworkRequest(url);
    netReq.setHeader(QNetworkRequest::ContentTypeHeader, QLatin1String("application/json"));
    applySslConfiguration(netReq);
    return netReq;
}

void HafasMgateBackend::setAuthObject(const QJsonObject& obj)
{
    m_auth = obj;
}

void HafasMgateBackend::setMicMacSalt(const QString &salt)
{
    m_micMacSalt = QByteArray::fromHex(salt.toUtf8());
}

void HafasMgateBackend::setChecksumSalt(const QString &salt)
{
    m_checksumSalt = QByteArray::fromHex(salt.toUtf8());
}
