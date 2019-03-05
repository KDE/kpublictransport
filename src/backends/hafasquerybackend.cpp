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
#include <KPublicTransport/Location>

#include <QDateTime>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

using namespace KPublicTransport;

HafasQueryBackend::HafasQueryBackend() = default;

bool HafasQueryBackend::isSecure() const
{
    return m_endpoint.startsWith(QLatin1String("https://"));
}

bool HafasQueryBackend::queryDeparture(DepartureReply *reply, QNetworkAccessManager *nam) const
{
    const auto request = reply->request();
    const auto stationId = request.stop().identifier(QLatin1String("ibnr")); // only seems to exist with IBNR so far? if that turns out to be wrong, do the same as in the mgate backend
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
        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            qCDebug(Log) << reply->error() << reply->errorString();
            return;
        }
        auto res = m_parser.parseStationBoardResponse(netReply->readAll(), reply->request().mode() == DepartureRequest::QueryArrival);
        // TODO error handling
        addResult(reply, std::move(res));
        netReply->deleteLater();
    });

    return true;
}
