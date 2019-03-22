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

void HafasQueryBackend::init() const
{
    m_parser.setLocationIdentifierType(m_locationIdentifierType);
}

bool HafasQueryBackend::isSecure() const
{
    return m_endpoint.startsWith(QLatin1String("https://"));
}

bool HafasQueryBackend::queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    init();
    if (request.name().isEmpty()) {
        return false; // TODO queries by coordinate
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("/ajax-getstop.exe/en"));

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("getstop"), QStringLiteral("1"));
    query.addQueryItem(QStringLiteral("REQ0JourneyStopsS0A"), QStringLiteral("255"));
    query.addQueryItem(QStringLiteral("REQ0JourneyStopsS0G"), request.name()); // TODO apps are seen to append '?' here
    query.addQueryItem(QStringLiteral("REQ0JourneyStopsB"), QStringLiteral("12")); // TODO max results
    url.setQuery(query);

    auto netReply = nam->get(QNetworkRequest(url));
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        qDebug() << netReply->request().url();
        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            qCDebug(Log) << reply->error() << reply->errorString();
            return;
        }

        auto res = m_parser.parseGetStopResponse(netReply->readAll());
        // TODO error handling
        addResult(reply, std::move(res));
    });

    return true;
}

bool HafasQueryBackend::queryDeparture(const DepartureRequest &request, DepartureReply *reply, QNetworkAccessManager *nam) const
{
    init();

    const auto stationId = request.stop().identifier(m_locationIdentifierType);
    if (stationId.isEmpty()) {
        // TODO support location queries like in the mgate variant
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
    qDebug() << url;

    auto netReply = nam->get(QNetworkRequest(url));
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        qDebug() << netReply->request().url();
        netReply->deleteLater();
        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            qCDebug(Log) << reply->error() << reply->errorString();
            return;
        }
        auto res = m_parser.parseStationBoardResponse(netReply->readAll(), reply->request().mode() == DepartureRequest::QueryArrival);
        // TODO error handling
        addResult(reply, std::move(res));
    });

    return true;
}

QString HafasQueryBackend::locationId(const Location &loc) const
{
    const auto id = loc.identifier(m_locationIdentifierType);
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
    init();

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
    qDebug() << url;

    auto netReply = nam->get(QNetworkRequest(url));
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        qDebug() << netReply->request().url();
        netReply->deleteLater();
        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            qCDebug(Log) << reply->error() << reply->errorString();
            return;
        }

        auto res = m_parser.parseQueryResponse(netReply->readAll());
        // TODO error handling
        addResult(reply, std::move(res));
    });

    return true;
}
