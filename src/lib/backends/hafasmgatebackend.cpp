/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasmgatebackend.h"
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
#include <KPublicTransport/TripReply>
#include <KPublicTransport/TripRequest>

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

using namespace Qt::Literals::StringLiterals;

namespace KPublicTransport {

class HafasMgateRequestContext
{
public:
    QDateTime dateTime;
    int duration = 0;

    inline operator QVariant() const {
        return QVariant::fromValue(*this);
    }
};

}

Q_DECLARE_METATYPE(KPublicTransport::HafasMgateRequestContext)

using namespace KPublicTransport;

HafasMgateBackend::HafasMgateBackend() = default;
HafasMgateBackend::~HafasMgateBackend() = default;

void HafasMgateBackend::init()
{
    m_parser.setLocationIdentifierTypes(locationIdentifierType(), standardLocationIdentifierType());
    m_parser.setLineModeMap(m_lineModeMap);
    m_parser.setStandardLocationIdentfierCountries(std::move(m_uicCountryCodes));
    m_parser.setProductNameMappings(std::move(m_productNameMappings));
}

AbstractBackend::Capabilities HafasMgateBackend::capabilities() const
{
    return (m_endpoint.startsWith(QLatin1String("https")) ? Secure : NoCapability)
        | CanQueryArrivals | CanQueryPreviousDeparture | CanQueryPreviousJourney | CanQueryNextJourney;
}

Location::Types HafasMgateBackend::supportedLocationTypes() const
{
    return Location::Stop;
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
        obj.insert(QLatin1String("extId"), id);
        obj.insert(QLatin1String("type"), QLatin1String("S")); // 'S' == station
    }

    else if (loc.hasCoordinate()) {
        QJsonObject crd {
            {"y"_L1, HafasParser::coordGeo2Hafas(loc.latitude())},
            {"x"_L1, HafasParser::coordGeo2Hafas(loc.longitude())},
        };
        obj.insert(QLatin1String("crd"), crd);
        obj.insert(QLatin1String("type"), QLatin1String("C")); // 'C' == coordinate
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
        cfg.insert(QLatin1String("polyEnc"), QLatin1String("GPA"));
        if (!m_rtMode.isEmpty()) {
            cfg.insert("rtMode"_L1, m_rtMode);
        }

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
        req.insert(QLatin1String("arrLocL"), arrLocL);
        req.insert(QLatin1String("depLocL"), depLocL);
        req.insert(QLatin1String("extChgTime"), -1);
        req.insert(QLatin1String("getEco"), false);
        req.insert(QLatin1String("getIST"), false);
        req.insert(QLatin1String("getPasslist"), request.includeIntermediateStops());
        req.insert(QLatin1String("getPolyline"), request.includePaths());
        req.insert(QLatin1String("getSimpleTrainComposition"), true);
        req.insert(QLatin1String("getTrainComposition"), true);
        req.insert(QLatin1String("numF"), request.maximumResults());

        QDateTime dt = request.dateTime();
        if (timeZone().isValid()) {
            dt = dt.toTimeZone(timeZone());
        }
        req.insert(QLatin1String("outDate"), dt.date().toString(QStringLiteral("yyyyMMdd")));
        req.insert(QLatin1String("outTime"), dt.time().toString(QStringLiteral("hhmmss")));
        req.insert(QLatin1String("outFrwd"), request.dateTimeMode() == JourneyRequest::Departure);
        const auto ctxSrc = requestContextData(request).toString();
        if (!ctxSrc.isEmpty()) {
            req.insert(QLatin1String("ctxScr"), ctxSrc);
        }

        QJsonArray jnyFltrL;
        for (const auto &conGroup : m_conGroups) {
            const auto accessMatch = std::find(request.accessModes().begin(), request.accessModes().end(), conGroup.access) != request.accessModes().end();
            const auto egressMatch = std::find(request.egressModes().begin(), request.egressModes().end(), conGroup.egress) != request.egressModes().end();
            if (accessMatch && egressMatch) {
                QJsonObject jnyFltr;
                jnyFltr.insert(QLatin1String("mode"), QLatin1String("INC"));
                jnyFltr.insert(QLatin1String("type"), QLatin1String("GROUP"));
                jnyFltr.insert(QLatin1String("value"), conGroup.group);
                jnyFltrL.push_back(jnyFltr);
            }
        }
        addLineModeJourneyFilter(request.lineModes(), jnyFltrL);
        if (request.requiresBikeTransport()) {
            jnyFltrL.push_back(QJsonObject{{"type"_L1, "BC"_L1}, {"mode"_L1, "INC"_L1}});
        }
        if (!jnyFltrL.isEmpty()) {
            req.insert(QLatin1String("jnyFltrL"),  jnyFltrL);
        }

        tripSearch.insert(QLatin1String("cfg"), cfg);
        tripSearch.insert(QLatin1String("meth"), QLatin1String("TripSearch"));
        tripSearch.insert(QLatin1String("req"), req);
    }

    QByteArray postData;
    const auto netRequest = makePostRequest(tripSearch, postData);
    logRequest(request, netRequest, postData);
    auto netReply = nam->post(netRequest, postData);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [netReply, reply, this]() {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                auto res = m_parser.parseJourneys(data);
                if (m_parser.error() == Reply::NoError) {
                    setNextRequestContext(reply, m_parser.m_nextJourneyContext);
                    setPreviousRequestContext(reply, m_parser.m_previousJourneyContext);
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

    const auto ctx = requestContextData(request).value<HafasMgateRequestContext>();
    auto dt = ctx.dateTime.isValid() ? ctx.dateTime : request.dateTime();
    if (timeZone().isValid()) {
        dt = dt.toTimeZone(timeZone());
    }

    QJsonObject stationBoard;
    {
        QJsonObject req;
        req.insert(QLatin1String("date"), dt.toString(QStringLiteral("yyyyMMdd")));
        if (ctx.duration > 0) {
            req.insert(QLatin1String("dur"), QString::number(ctx.duration));
        } else {
            req.insert(QLatin1String("maxJny"), request.maximumResults());
        }
        // stbFltrEquiv is no longer allowed above API version 1.20
        if (QVersionNumber::fromString(m_version) < QVersionNumber(1, 20)) {
            req.insert(QLatin1String("stbFltrEquiv"), true);
        }

        req.insert(QLatin1String("stbLoc"), stbLoc);
        req.insert(QLatin1String("time"), dt.toString(QStringLiteral("hhmmss")));
        req.insert(QLatin1String("type"), request.mode() == StopoverRequest::QueryDeparture ? QLatin1String("DEP") : QLatin1String("ARR"));

        QJsonArray jnyFltrL;
        addLineModeJourneyFilter(request.lineModes(), jnyFltrL);
        if (!jnyFltrL.isEmpty()) {
            req.insert(QLatin1String("jnyFltrL"),  jnyFltrL);
        }

        stationBoard.insert(QLatin1String("meth"), QLatin1String("StationBoard"));
        stationBoard.insert(QLatin1String("req"), req);
    }

    QByteArray postData;
    const auto netRequest = makePostRequest(stationBoard, postData);
    logRequest(request, netRequest, postData);
    auto netReply = nam->post(netRequest, postData);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [netReply, reply, dt, this]() {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                auto result = m_parser.parseDepartures(data);
                if (m_parser.error() != Reply::NoError) {
                    addError(reply, m_parser.error(), m_parser.errorMessage());
                } else {
                    HafasMgateRequestContext prevCtx;
                    prevCtx.dateTime = dt.addSecs(-3600); // TODO: follow duration parameter in request once we have that
                    prevCtx.duration = 60;
                    setPreviousRequestContext(reply, prevCtx);

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
    QJsonObject methodObj;
    if (req.hasCoordinate()) {
        QJsonObject coord {
            {"x"_L1, HafasParser::coordGeo2Hafas(req.longitude())},
            {"y"_L1, HafasParser::coordGeo2Hafas(req.latitude())},
        };
        QJsonObject ring;
        ring.insert(QLatin1String("cCrd"), coord);
        ring.insert(QLatin1String("maxDist"), std::max(1, req.maximumDistance()));

        QJsonObject reqObj;
        reqObj.insert(QLatin1String("ring"), ring);
        // ### make this configurable in LocationRequest
        reqObj.insert(QLatin1String("getStops"), true);
        reqObj.insert(QLatin1String("getPOIs"), false);
        reqObj.insert(QLatin1String("maxLoc"), std::max(1, req.maximumResults()));

        methodObj.insert(QLatin1String("meth"), QLatin1String("LocGeoPos"));
        methodObj.insert(QLatin1String("req"), reqObj);

    } else if (!req.name().isEmpty()) {
        QJsonObject loc;
        loc.insert(QLatin1String("name"), req.name()); // + '?' for auto completion search?
        loc.insert(QLatin1String("type"), QLatin1String("S")); // station: S, address: A, POI: P

        QJsonObject input;
        input.insert(QLatin1String("field"), QLatin1String("S"));
        input.insert(QLatin1String("loc"), loc);
        input.insert(QLatin1String("maxLoc"), std::max(1, req.maximumResults()));

        QJsonObject reqObj;
        reqObj.insert(QLatin1String("input"), input);

        methodObj.insert(QLatin1String("meth"), QLatin1String("LocMatch"));
        methodObj.insert(QLatin1String("req"), reqObj);

    } else {
        return false;
    }

    QByteArray postData;
    const auto netRequest = makePostRequest(methodObj, postData);
    logRequest(req, netRequest, postData);
    const auto netReply = nam->post(netRequest, postData);
    netReply->setParent(reply);

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

bool HafasMgateBackend::queryTrip(const TripRequest &req, TripReply *reply, QNetworkAccessManager *nam) const
{
    const auto tripId = req.identifier(locationIdentifierType());
    if (tripId.isEmpty()) {
        return false;
    }

    QJsonObject methodObj({
        {"meth"_L1, "JourneyDetails"_L1},
        {"cfg"_L1, QJsonObject({
            {"polyEnc"_L1, "GPA"_L1}
        })},
        {"req"_L1, QJsonObject({
            {"jid"_L1, tripId},
            {"getPolyline"_L1, true},
        })},
    });

    QByteArray postData;
    const auto netRequest = makePostRequest(methodObj, postData);
    logRequest(req, netRequest, postData);
    const auto netReply = nam->post(netRequest, postData);
    netReply->setParent(reply);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [netReply, reply, this]() {
        netReply->deleteLater();
        qDebug() << netReply->request().url();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                auto res = m_parser.parseTrip(data);
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
    });


    return true;
}

QNetworkRequest HafasMgateBackend::makePostRequest(const QJsonObject &svcReq, QByteArray &postData) const
{
    QJsonObject top;
    top.insert(QLatin1String("auth"), m_auth);
    top.insert(QLatin1String("client"), m_client);
    if (!m_extParam.isEmpty()) {
        top.insert(QLatin1String("ext"), m_extParam);
    }
    top.insert(QLatin1String("formatted"), false);
    top.insert(QLatin1String("lang"), preferredLanguage());
    top.insert(QLatin1String("ver"), m_version);

    QJsonArray svcReqs;
    svcReqs.push_back(svcReq);
    top.insert(QLatin1String("svcReqL"), svcReqs);

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

void HafasMgateBackend::setMicMacSalt(const QString &salt)
{
    m_micMacSalt = QByteArray::fromHex(salt.toUtf8());
}

void HafasMgateBackend::setChecksumSalt(const QString &salt)
{
    m_checksumSalt = QByteArray::fromHex(salt.toUtf8());
}

void HafasMgateBackend::setConGroups(const QJsonArray &conGroups)
{
    m_conGroups.reserve(conGroups.size());
    for (const auto &conGroupVal : conGroups) {
        const auto conGroupObj = conGroupVal.toObject();
        ConGroup cg;
        cg.access = IndividualTransport::fromJson(conGroupObj.value(QLatin1String("access")).toObject());
        cg.egress = IndividualTransport::fromJson(conGroupObj.value(QLatin1String("egress")).toObject());
        cg.group = conGroupObj.value(QLatin1String("conGroup")).toString();
        m_conGroups.push_back(std::move(cg));
    }
}

static QStringList parseProductNameMappingFieldNames(const QJsonValue &val)
{
    if (val.isString()) {
        return QStringList({val.toString()});
    }
    if (val.isArray()) {
        const auto a = val.toArray();
        QStringList l;
        l.reserve(a.size());
        std::transform(a.begin(), a.end(), std::back_inserter(l), [](const auto &v) { return v.toString(); });
        return l;
    }
    return {};
}

void HafasMgateBackend::setProductNameMappings(const QJsonArray &productNameMappings)
{
    m_productNameMappings.reserve(productNameMappings.size());
    for (const auto &mV : productNameMappings) {
        const auto mObj = mV.toObject();
        HafasMgateProductNameMapping m;
        m.cls = mObj.value(QLatin1String("cls")).toInt(-1);
        m.lineName = parseProductNameMappingFieldNames(mObj.value(QLatin1String("lineName")));
        m.routeName = parseProductNameMappingFieldNames(mObj.value(QLatin1String("routeName")));
        m_productNameMappings.push_back(std::move(m));
    }
}

void HafasMgateBackend::addLineModeJourneyFilter(const std::vector<Line::Mode> &lineModes, QJsonArray &jnyFltrL) const
{
    if (lineModes.empty()) {
        return;
    }

    int productBitmask = 0;
    for (const auto mode : lineModes) {
        for (const auto& [key, value] : m_lineModeMap) {
            if (value == mode)  {
                productBitmask |= key;
            }
        }
    }

    if (productBitmask != 0) {
        jnyFltrL.push_back(QJsonObject({
            {QLatin1String("type"), QLatin1String("PROD")},
            {QLatin1String("mode"), QLatin1String("INC")},
            {QLatin1String("value"), QString::number(productBitmask)}
        }));
    }
}
