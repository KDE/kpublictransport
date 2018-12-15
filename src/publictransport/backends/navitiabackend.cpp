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

#include "navitiabackend.h"
#include "logging.h"
#include "navitiaparser.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/DepartureReply>
#include <KPublicTransport/DepartureRequest>
#include <KPublicTransport/Location>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

using namespace KPublicTransport;

NavitiaBackend::NavitiaBackend() = default;

bool NavitiaBackend::queryJourney(JourneyReply *reply, QNetworkAccessManager *nam) const
{
    return true;
}

bool NavitiaBackend::queryDeparture(DepartureReply *reply, QNetworkAccessManager *nam) const
{
    const auto req = reply->request();
    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(m_endpoint);
    url.setPath(
        QStringLiteral("/v1/coverage/") +
        (m_coverage.isEmpty() ? QString::number(req.stop().latitude()) + QLatin1Char(';') + QString::number(req.stop().longitude()) : m_coverage) +
        QStringLiteral("/coord/") + QString::number(req.stop().latitude()) + QLatin1Char(';') + QString::number(req.stop().longitude()) +
        QStringLiteral("/departures")
    );

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("from_datetime"), req.dateTime().toString(QStringLiteral("yyyyMMddThhmmss")));
    query.addQueryItem(QStringLiteral("disable_geojson"), QStringLiteral("true"));
    query.addQueryItem(QStringLiteral("depth"), QStringLiteral("0"));
    url.setQuery(query);

    QNetworkRequest netReq(url);
    netReq.setRawHeader("Authorization", m_auth.toUtf8());

    qCDebug(Log) << "GET:" << url;
    auto netReply = nam->get(netReq);
    QObject::connect(netReply, &QNetworkReply::finished, [netReply, reply] {
        switch (netReply->error()) {
            case QNetworkReply::NoError:
                addResult(reply, NavitiaParser::parseDepartures(netReply->readAll()));
                break;
            case QNetworkReply::ContentNotFoundError:
                addError(reply, Reply::NotFoundError, NavitiaParser::parseErrorMessage(netReply->readAll()));
                break;
            default:
                addError(reply, Reply::NetworkError, netReply->errorString());
                qCDebug(Log) << netReply->error() << netReply->errorString();
                break;
        }
        netReply->deleteLater();
    });

    return true;
}
