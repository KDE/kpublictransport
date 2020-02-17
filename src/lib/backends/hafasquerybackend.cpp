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

#include "hafasquerybackend.h"
#include "cache.h"
#include "logging.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/DepartureReply>
#include <KPublicTransport/DepartureRequest>
#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>

#include <QDateTime>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

using namespace KPublicTransport;

HafasQueryBackend::HafasQueryBackend() = default;
HafasQueryBackend::~HafasQueryBackend() = default;

void HafasQueryBackend::init()
{
    m_parser.setLocationIdentifierTypes(locationIdentifierType(), standardLocationIdentifierType());
    m_parser.setLineModeMap(std::move(m_lineModeMap));
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
            return locationIdentifier(loc).isEmpty() && !loc.hasCoordinate();
    }
    return false;
}

bool HafasQueryBackend::queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if (request.hasCoordinate()) {
        return queryLocationByCoordinate(request, reply, nam);
    }
    if (!request.name().isEmpty()) {
        return queryLocationByName(request, reply, nam);
    }
    return false;
}

bool HafasQueryBackend::queryLocationByName(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("/ajax-getstop.exe/en"));

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("getstop"), QStringLiteral("1"));
    query.addQueryItem(QStringLiteral("REQ0JourneyStopsS0A"), QStringLiteral("255"));
    query.addQueryItem(QStringLiteral("REQ0JourneyStopsS0G"), request.name()); // TODO apps are seen to append '?' here
    query.addQueryItem(QStringLiteral("REQ0JourneyStopsB"), QStringLiteral("12")); // TODO max results
    url.setQuery(query);

    const QNetworkRequest netRequest(url);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);
        netReply->deleteLater();
        qDebug() << netReply->request().url();

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, this, Reply::NetworkError, netReply->errorString());
            return;
        }

        auto res = m_parser.parseGetStopResponse(data);
        if (m_parser.error() != Reply::NoError) {
            addError(reply, this, m_parser.error(), m_parser.errorMessage());
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
    url.setPath(url.path() + QLatin1String("/query.exe/eny"));

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("performLocating"), QStringLiteral("2"));
    query.addQueryItem(QStringLiteral("tpl"), QStringLiteral("stop2json"));
    query.addQueryItem(QStringLiteral("look_x"), QString::number((int)(request.longitude() * 1000000)));
    query.addQueryItem(QStringLiteral("look_y"), QString::number((int)(request.latitude() * 1000000)));
    query.addQueryItem(QStringLiteral("look_maxdist"), QStringLiteral("5000")); // TODO max dist
    query.addQueryItem(QStringLiteral("look_maxno"), QStringLiteral("12")); // TODO max results
    url.setQuery(query);

    const QNetworkRequest netRequest(url);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, this, Reply::NetworkError, netReply->errorString());
            return;
        }
        qDebug() << netReply->request().url();
        auto res = m_parser.parseQueryLocationResponse(data);
        if (m_parser.error() != Reply::NoError) {
            addError(reply, this, m_parser.error(), m_parser.errorMessage());
        } else {
            Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), res, {});
            addResult(reply, std::move(res));
        }
    });
    return true;
}

bool HafasQueryBackend::queryDeparture(const DepartureRequest &request, DepartureReply *reply, QNetworkAccessManager *nam) const
{
    const auto stationId = locationIdentifier(request.stop());
    if (stationId.isEmpty()) {
        qCDebug(Log) << "no station identifier found for departure stop" << backendId();
        return false;
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("/stboard.exe/en")); // dn/nn?

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("boardType"), request.mode() == DepartureRequest::QueryDeparture ? QStringLiteral("dep") : QStringLiteral("arr"));
    query.addQueryItem(QStringLiteral("disableEquivs"), QStringLiteral("0"));
    query.addQueryItem(QStringLiteral("maxJourneys"), QStringLiteral("12"));
    query.addQueryItem(QStringLiteral("input"), stationId);
    query.addQueryItem(QStringLiteral("date"), request.dateTime().date().toString(QStringLiteral("dd.MM.yy")));
    query.addQueryItem(QStringLiteral("time"), request.dateTime().time().toString(QStringLiteral("hh:mm")));
    query.addQueryItem(QStringLiteral("L"), QStringLiteral("vs_java3"));
    query.addQueryItem(QStringLiteral("start"), QStringLiteral("yes"));
    url.setQuery(query);

    const QNetworkRequest netRequest(url);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        qDebug() << netReply->request().url();
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, this, Reply::NetworkError, netReply->errorString());
            return;
        }
        auto res = m_parser.parseStationBoardResponse(data, reply->request().mode() == DepartureRequest::QueryArrival);
        if (m_parser.error() != Reply::NoError) {
            addError(reply, this, m_parser.error(), m_parser.errorMessage());
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
    const auto fromId = locationId(request.from());
    const auto toId = locationId(request.to());
    if (fromId.isEmpty() || toId.isEmpty()) {
        return false;
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("/query.exe/en"));
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
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        qDebug() << netReply->request().url();
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, this, Reply::NetworkError, netReply->errorString());
            return;
        }

        auto res = m_parser.parseQueryJourneyResponse(data);
        if (m_parser.error() != Reply::NoError) {
            addError(reply, this, m_parser.error(), m_parser.errorMessage());
        } else {
            addResult(reply, this, std::move(res));
        }
    });

    return true;
}
