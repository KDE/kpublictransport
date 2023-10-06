/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasquerybackend.h"
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

#include <QDateTime>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include <QTextCodec>
#else
#include <QStringDecoder>
#endif
#include <QUrl>
#include <QUrlQuery>

using namespace KPublicTransport;

HafasQueryBackend::HafasQueryBackend() = default;
HafasQueryBackend::~HafasQueryBackend() = default;

void HafasQueryBackend::init()
{
    m_parser.setLocationIdentifierTypes(locationIdentifierType(), standardLocationIdentifierType());
    m_parser.setLineModeMap(m_lineModeMap);
    m_parser.setStandardLocationIdentfierCountries(std::move(m_uicCountryCodes));
}

AbstractBackend::Capabilities HafasQueryBackend::capabilities() const
{
    return (m_endpoint.startsWith(QLatin1String("https://")) ? Secure : NoCapability) | CanQueryArrivals;
}

bool HafasQueryBackend::needsLocationQuery(const Location &loc, QueryType type) const
{
    switch (type) {
        case QueryType::Departure:
            return locationIdentifier(loc).isEmpty();
        case QueryType::Journey:
            return locationIdentifier(loc).isEmpty(); // TODO coordinate-based search doesn't actually seem to work? && !loc.hasCoordinate();
    }
    return false;
}

bool HafasQueryBackend::queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if ((request.types() & Location::Stop) == 0) {
        return false;
    }

    if (request.hasCoordinate()) {
        return queryLocationByCoordinate(request, reply, nam);
    }
    if (!request.name().isEmpty()) {
        return queryLocationByName(request, reply, nam);
    }
    return false;
}

static QByteArray readReplyAsUtf8(QNetworkReply *reply)
{
    const auto data = reply->readAll();
    const auto contentType = reply->header(QNetworkRequest::ContentTypeHeader).toString();
    const auto charsetStart = contentType.indexOf(QLatin1String("charset="));
    if (charsetStart < 0) {
        return data;
    }
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    const auto codec = QTextCodec::codecForName(QStringView(contentType).mid(charsetStart + 8).toUtf8());
    if (!codec) {
        return data;
    }
    return codec->toUnicode(data).toUtf8();
#else
    auto codec = QStringDecoder(QStringView(contentType).mid(charsetStart + 8).toUtf8().constData());
    if (!codec.isValid()) {
        return data;
    }
    return QString(codec.decode(data)).toUtf8();
#endif
}

bool HafasQueryBackend::queryLocationByName(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("/ajax-getstop.exe/") + preferredLanguage());

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("getstop"), QStringLiteral("1"));
    query.addQueryItem(QStringLiteral("REQ0JourneyStopsS0A"), QStringLiteral("255"));
    query.addQueryItem(QStringLiteral("REQ0JourneyStopsS0G"), request.name()); // TODO apps are seen to append '?' here
    query.addQueryItem(QStringLiteral("REQ0JourneyStopsB"), QString::number(std::max(1, request.maximumResults())));
    query.addQueryItem(QStringLiteral("js"), QStringLiteral("true"));
    url.setQuery(query);

    const QNetworkRequest netRequest(url);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        const auto data = readReplyAsUtf8(netReply);
        logReply(reply, netReply, data);
        netReply->deleteLater();

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        auto res = m_parser.parseGetStopResponse(data);
        if (m_parser.error() != Reply::NoError) {
            addError(reply, m_parser.error(), m_parser.errorMessage());
        } else {
            Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), res, {});
            addResult(reply, std::move(res));
        }
    });

    return true;
}

bool HafasQueryBackend::queryLocationByCoordinate(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("/query.exe/") + preferredLanguage() + QLatin1Char('y'));

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("performLocating"), QStringLiteral("2"));
    query.addQueryItem(QStringLiteral("tpl"), QStringLiteral("stop2json"));
    query.addQueryItem(QStringLiteral("look_x"), QString::number((int)(request.longitude() * 1000000)));
    query.addQueryItem(QStringLiteral("look_y"), QString::number((int)(request.latitude() * 1000000)));
    query.addQueryItem(QStringLiteral("look_maxdist"), QString::number(std::max(1, request.maximumDistance())));
    query.addQueryItem(QStringLiteral("look_maxno"), QString::number(std::max(1, request.maximumResults())));
    url.setQuery(query);

    const QNetworkRequest netRequest(url);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        auto res = m_parser.parseQueryLocationResponse(data);
        if (m_parser.error() != Reply::NoError) {
            addError(reply, m_parser.error(), m_parser.errorMessage());
        } else {
            Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), res, {});
            addResult(reply, std::move(res));
        }
    });
    return true;
}

bool HafasQueryBackend::queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    const auto stationId = locationIdentifier(request.stop());
    if (stationId.isEmpty()) {
        qCDebug(Log) << "no station identifier found for departure stop" << backendId();
        return false;
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("/stboard.exe/") + preferredLanguage());

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("boardType"), request.mode() == StopoverRequest::QueryDeparture ? QStringLiteral("dep") : QStringLiteral("arr"));
    query.addQueryItem(QStringLiteral("disableEquivs"), QStringLiteral("0"));
    query.addQueryItem(QStringLiteral("maxJourneys"), QString::number(request.maximumResults()));
    query.addQueryItem(QStringLiteral("input"), stationId);
    query.addQueryItem(QStringLiteral("date"), request.dateTime().date().toString(QStringLiteral("dd.MM.yy")));
    query.addQueryItem(QStringLiteral("time"), request.dateTime().time().toString(QStringLiteral("hh:mm")));
    query.addQueryItem(QStringLiteral("L"), QStringLiteral("vs_java3"));
    query.addQueryItem(QStringLiteral("start"), QStringLiteral("yes"));
    url.setQuery(query);

    const QNetworkRequest netRequest(url);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        auto res = m_parser.parseStationBoardResponse(data, reply->request().mode() == StopoverRequest::QueryArrival);
        if (m_parser.error() != Reply::NoError) {
            addError(reply, m_parser.error(), m_parser.errorMessage());
        } else {
            addResult(reply, this, std::move(res));
        }
    });

    return true;
}

QString HafasQueryBackend::locationId(const Location &loc) const
{
    const auto id = locationIdentifier(loc);
    if (!id.isEmpty()) {
        return QLatin1String("A=1@L=") + id;
    }

    if (loc.hasCoordinate()) {
        return QLatin1String("A=1@X=") + QString::number((int)(loc.longitude() * 1000000)) + QLatin1String("@Y=") + QString::number((int)(loc.latitude() * 1000000));
    }

    if (!loc.name().isEmpty()) {
        return QLatin1String("A=1@G=") + loc.name();
    }

    return {};
}

bool HafasQueryBackend::queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const
{
#if Q_BYTE_ORDER == Q_BIG_ENDIAN
#warning Hafas binary journey reponse parsing not implemented for big endian yet!
    return false;
#endif
    if ((request.modes() & JourneySection::PublicTransport) == 0) {
        return false;
    }

    const auto fromId = locationId(request.from());
    const auto toId = locationId(request.to());
    if (fromId.isEmpty() || toId.isEmpty()) {
        return false;
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("/query.exe/") + preferredLanguage());
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("REQ0JourneyStopsS0ID"), fromId);
    query.addQueryItem(QStringLiteral("REQ0JourneyStopsZ0ID"), toId);
    query.addQueryItem(QStringLiteral("REQ0JourneyDate"), request.dateTime().date().toString(QStringLiteral("dd.MM.yy")));
    query.addQueryItem(QStringLiteral("REQ0JourneyTime"), request.dateTime().time().toString(QStringLiteral("hh:mm")));
    query.addQueryItem(QStringLiteral("REQ0HafasSearchForw"), request.dateTimeMode() == JourneyRequest::Departure ? QStringLiteral("1") : QStringLiteral("0"));
    query.addQueryItem(QStringLiteral("REQ0JourneyProduct_prod_list_1"), QStringLiteral("1111111111"));
    // no idea what this stuff does, but it seems necessary...
    query.addQueryItem(QStringLiteral("start"), QStringLiteral("Suchen"));
    query.addQueryItem(QStringLiteral("h2g-direct"), QStringLiteral("11"));
    query.addQueryItem(QStringLiteral("clientType"), QStringLiteral("ANDROID"));

    url.setQuery(query);

    const QNetworkRequest netRequest(url);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        auto res = m_parser.parseQueryJourneyResponse(data);
        if (m_parser.error() != Reply::NoError) {
            addError(reply, m_parser.error(), m_parser.errorMessage());
        } else {
            addResult(reply, this, std::move(res));
        }
    });

    return true;
}
