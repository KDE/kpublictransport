/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "efabackend.h"
#include "efacompactparser.h"
#include "efamodeoftransport.h"
#include "efaxmlparser.h"
#include "cache.h"
#include "logging.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopoverReply>
#include <KPublicTransport/StopoverRequest>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

using namespace KPublicTransport;

EfaBackend::EfaBackend() = default;
EfaBackend::~EfaBackend() = default;

AbstractBackend::Capabilities EfaBackend::capabilities() const
{
    return (m_endpoint.startsWith(QLatin1String("https")) ? Secure : NoCapability)
        | CanQueryNextJourney | CanQueryPreviousJourney | CanQueryNextDeparture | CanQueryPreviousDeparture;
}

bool EfaBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    Q_UNUSED(type);
    return !loc.hasCoordinate() && loc.identifier(locationIdentifierType()).isEmpty();
}

bool EfaBackend::queryLocation(const LocationRequest& request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if ((request.name().isEmpty() && !request.hasCoordinate()) || (request.types() & Location::Stop) == 0) {
        return false;
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + (m_stopfinderRequestCommand.isEmpty() ? QStringLiteral("XML_STOPFINDER_REQUEST") : m_stopfinderRequestCommand));

    auto query = commonQuery();
    query.addQueryItem(QStringLiteral("locationServerActive"), QStringLiteral("1"));

    if (request.hasCoordinate()) {
        query.addQueryItem(QStringLiteral("type_sf"), QStringLiteral("coord"));
        query.addQueryItem(QStringLiteral("name_sf"), QString::number(request.longitude()) + QLatin1Char(':') + QString::number(request.latitude()) + QLatin1String(":WGS84[DD.ddddd]"));
    } else {
        query.addQueryItem(QStringLiteral("type_sf"), QStringLiteral("any"));
        query.addQueryItem(QStringLiteral("name_sf"), request.name());
    }

    query.addQueryItem(QStringLiteral("anyObjFilter_sf"), QStringLiteral("2")); // bitfield, "2" is the flag for stops
    query.addQueryItem(QStringLiteral("anyMaxSizeHitList"), QString::number(std::max(1, request.maximumResults())));
    url.setQuery(query);

    QNetworkRequest netRequest(url);
    applySslConfiguration(netRequest);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        auto p = make_parser();
        auto res = p->parseStopFinderResponse(data);
        if (p->error() != Reply::NoError) {
            addError(reply, p->error(), p->errorMessage());
        } else {
            Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), res, {});
            addResult(reply, std::move(res));
        }
    });

    return true;
}

bool EfaBackend::queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    const auto stopId = request.stop().identifier(locationIdentifierType());
    if (stopId.isEmpty() && !request.stop().hasCoordinate()) {
        return false;
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + (m_dmRequestCommand.isEmpty() ? QStringLiteral("XML_DM_REQUEST") : m_dmRequestCommand));

    QDateTime dt = request.dateTime();
    if (timeZone().isValid()) {
        dt = dt.toTimeZone(timeZone());
    }

    const auto ctx = requestContextData(request).value<EfaRequestContext>();
    auto query = commonQuery();
    if (ctx.isEmpty()) {
        if (stopId.isEmpty()) {
            query.addQueryItem(QStringLiteral("type_dm"), QStringLiteral("coord"));
            query.addQueryItem(QStringLiteral("name_dm"), QString::number(request.stop().longitude()) + QLatin1Char(':') + QString::number(request.stop().latitude()) + QLatin1String(":WGS84[DD.ddddd]"));
        } else {
            query.addQueryItem(QStringLiteral("type_dm"), QStringLiteral("stop"));
            query.addQueryItem(QStringLiteral("name_dm"), stopId);
        }
        query.addQueryItem(QStringLiteral("itdDate"), dt.date().toString(QStringLiteral("yyyyMMdd")));
        query.addQueryItem(QStringLiteral("itdTime"), dt.time().toString(QStringLiteral("hhmm")));
        query.addQueryItem(QStringLiteral("useRealtime"), QStringLiteral("1"));
        query.addQueryItem(QStringLiteral("limit"), QString::number(request.maximumResults()));

        // not exactly sure what these do, but without this the result is missing departure times
        query.addQueryItem(QStringLiteral("mode"), QStringLiteral("direct"));
        query.addQueryItem(QStringLiteral("ptOptionsActive"), QStringLiteral("1"));
        query.addQueryItem(QStringLiteral("merge_dep"), QStringLiteral("1"));

        // enable support for previous/next queries
        query.addQueryItem(QStringLiteral("stateless"), QStringLiteral("1"));
        query.addQueryItem(QStringLiteral("sessionID"), QStringLiteral("0"));
        query.addQueryItem(QStringLiteral("requestID"), QStringLiteral("0"));
    } else {
        query.addQueryItem(QStringLiteral("stateless"), QStringLiteral("1"));
        query.addQueryItem(QStringLiteral("sessionID"), ctx.sessionId);
        query.addQueryItem(QStringLiteral("requestID"), ctx.requestId);
        if (requestContext(request).type == RequestContext::Next) {
            query.addQueryItem(QStringLiteral("command"), QStringLiteral("dmNext"));
        } else {
            query.addQueryItem(QStringLiteral("command"), QStringLiteral("dmPrev"));
        }
    }

    url.setQuery(query);

    QNetworkRequest netRequest(url);
    applySslConfiguration(netRequest);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        auto p = make_parser();
        auto res = p->parseDmResponse(data);
        if (p->error() != Reply::NoError) {
            addError(reply, p->error(), p->errorMessage());
        } else {
            setNextRequestContext(reply, QVariant::fromValue(p->requestContext()));
            setPreviousRequestContext(reply, QVariant::fromValue(p->requestContext()));
            addResult(reply, this, std::move(res));
        }
    });

    return true;
}

struct {
    IndividualTransport::Mode mode;
    IndividualTransport::Qualifier qualifier;
    int itMot;
} static constexpr const itMotMap[] = {
    { IndividualTransport::Walk, IndividualTransport::None, 100 },
    { IndividualTransport::Bike, IndividualTransport::Park, 101 },
    { IndividualTransport::Bike, IndividualTransport::None, 102 },
    { IndividualTransport::Car, IndividualTransport::Rent, 103 }, // ### 103 is "Kiss & Ride", unclear which of this two this practically maps to...
    { IndividualTransport::Car, IndividualTransport::Dropoff, 103 },
    { IndividualTransport::Car, IndividualTransport::Park, 104 },
    // TODO 105 Taxi
    // TODO 106 and 107 exist as well but no idea yet what they mean...
};

static void addItModeOptions(QUrlQuery &query, const QString &paramName, const std::vector<IndividualTransport> &modes)
{
    for (const auto &mode : modes) {
        const auto it = std::find_if(std::begin(itMotMap), std::end(itMotMap), [mode](const auto &m) {
            return m.mode == mode.mode() && m.qualifier == mode.qualifier();
        });
        if (it != std::end(itMotMap)) {
            query.addQueryItem(paramName, QString::number((*it).itMot));;
            break;
        }
    }
}

bool EfaBackend::queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    if ((request.modes() & JourneySection::PublicTransport) == 0) {
        return false;
    }

    const auto fromId = request.from().identifier(locationIdentifierType());
    const auto toId = request.to().identifier(locationIdentifierType());
    if ((fromId.isEmpty() && !request.from().hasCoordinate()) || (toId.isEmpty() && !request.to().hasCoordinate())) {
        return false;
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + (m_tripRequestCommand.isEmpty() ? QStringLiteral("XML_TRIP_REQUEST2") : m_tripRequestCommand));

    const auto ctx = requestContextData(request).value<EfaRequestContext>();
    auto query = commonQuery();
    if (ctx.isEmpty()) {
        query.addQueryItem(QStringLiteral("locationServerActive"), QStringLiteral("1"));
        query.addQueryItem(QStringLiteral("useRealtime"), QStringLiteral("1"));

        if (fromId.isEmpty()) {
            query.addQueryItem(QStringLiteral("type_origin"), QStringLiteral("coord"));
            query.addQueryItem(QStringLiteral("name_origin"), QString::number(request.from().longitude()) + QLatin1Char(':') + QString::number(request.from().latitude()) + QLatin1String(":WGS84[DD.ddddd]"));
        } else {
            query.addQueryItem(QStringLiteral("type_origin"), QStringLiteral("stop"));
            query.addQueryItem(QStringLiteral("name_origin"), fromId);
        }
        if (toId.isEmpty()) {
            query.addQueryItem(QStringLiteral("type_destination"), QStringLiteral("coord"));
            query.addQueryItem(QStringLiteral("name_destination"), QString::number(request.to().longitude()) + QLatin1Char(':') + QString::number(request.to().latitude()) + QLatin1String(":WGS84[DD.ddddd]"));
        } else {
            query.addQueryItem(QStringLiteral("type_destination"), QStringLiteral("stop"));
            query.addQueryItem(QStringLiteral("name_destination"), toId);
        }

        QDateTime dt = request.dateTime();
        if (timeZone().isValid()) {
            dt = dt.toTimeZone(timeZone());
        }
        query.addQueryItem(QStringLiteral("itdDate"), dt.date().toString(QStringLiteral("yyyyMMdd")));
        query.addQueryItem(QStringLiteral("itdTime"), dt.time().toString(QStringLiteral("hhmm")));
        query.addQueryItem(QStringLiteral("itdTripDateTimeDepArr"), request.dateTimeMode() == JourneyRequest::Departure ? QStringLiteral("dep") : QStringLiteral("arr"));

        EfaModeOfTransport::lineModesToQuery(request.lineModes(), query);
        query.addQueryItem(QStringLiteral("itOptionsActive"), QStringLiteral("1"));
        addItModeOptions(query, QStringLiteral("trITDepMOT"), request.accessModes());
        addItModeOptions(query, QStringLiteral("trITArrMOT"), request.egressModes());

        query.addQueryItem(QStringLiteral("calcNumberOfTrips"), QString::number(std::max(1, request.maximumResults())));
        query.addQueryItem(QStringLiteral("calcCO2"), QStringLiteral("1"));

        // saves several 100kb due to not encoding that path coordinates (which we don't even need) as XML
        query.addQueryItem(QStringLiteral("coordListOutputFormat"), QStringLiteral("STRING"));

        // enable support for previous/next queries
        query.addQueryItem(QStringLiteral("stateless"), QStringLiteral("1"));
        query.addQueryItem(QStringLiteral("sessionID"), QStringLiteral("0"));
        query.addQueryItem(QStringLiteral("requestID"), QStringLiteral("0"));
    } else {
        query.addQueryItem(QStringLiteral("stateless"), QStringLiteral("1"));
        query.addQueryItem(QStringLiteral("sessionID"), ctx.sessionId);
        query.addQueryItem(QStringLiteral("requestID"), ctx.requestId);
        if (requestContext(request).type == RequestContext::Next) {
            query.addQueryItem(QStringLiteral("command"), QStringLiteral("tripNext"));
        } else {
            query.addQueryItem(QStringLiteral("command"), QStringLiteral("tripPrev"));
        }
    }

    url.setQuery(query);
    qCDebug(Log) << url;

    QNetworkRequest netRequest(url);
    applySslConfiguration(netRequest);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        auto p = make_parser();
        auto res = p->parseTripResponse(data);
        if (p->error() != Reply::NoError) {
            addError(reply, p->error(), p->errorMessage());
        } else {
            setNextRequestContext(reply, QVariant::fromValue(p->requestContext()));
            setPreviousRequestContext(reply, QVariant::fromValue(p->requestContext()));
            addResult(reply, this, std::move(res));
        }
    });

    return true;
}

QString EfaBackend::locationIdentifierType() const
{
    return m_locationIdentifierType.isEmpty() ? backendId() : m_locationIdentifierType;
}

std::unique_ptr<EfaParser> EfaBackend::make_parser() const
{
    std::unique_ptr<EfaParser> p;
    if (m_compactXmlResponse) {
        p = std::make_unique<EfaCompactParser>();
    } else {
        p = std::make_unique<EfaXmlParser>();
    }
    p->setLocationIdentifierType(locationIdentifierType());
    return p;
}

QUrlQuery EfaBackend::commonQuery() const
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("outputFormat"), QStringLiteral("XML"));
    query.addQueryItem(QStringLiteral("coordOutputFormat"), QStringLiteral("WGS84[DD.ddddd]"));
    query.addQueryItem(QStringLiteral("language"), preferredLanguage());
    if (!m_mId.isEmpty()) {
        query.addQueryItem(QStringLiteral("mId"), m_mId);
    }
    return query;
}

void EfaBackend::setXmlOutputFormat(const QString &format)
{
    m_compactXmlResponse = format == QLatin1String("compact");
}
