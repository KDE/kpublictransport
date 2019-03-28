/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#include "efabackend.h"
#include "efaparser.h"
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

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

using namespace KPublicTransport;

EfaBackend::EfaBackend() = default;
EfaBackend::~EfaBackend() = default;

bool EfaBackend::isSecure() const
{
    return m_endpoint.startsWith(QLatin1String("https"));
}

bool EfaBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    Q_UNUSED(type);
    return loc.identifier(locationIdentifierType()).isEmpty();
}

bool EfaBackend::queryLocation(const LocationRequest& request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    // TODO support query by coordinate
    if (request.name().isEmpty()) {
        return false;
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("XML_STOPFINDER_REQUEST"));

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("locationServerActive"), QStringLiteral("1"));
    query.addQueryItem(QStringLiteral("outputFormat"), QStringLiteral("XML"));
    query.addQueryItem(QStringLiteral("type_sf"), QStringLiteral("stop"));
    query.addQueryItem(QStringLiteral("name_sf"), request.name());
    query.addQueryItem(QStringLiteral("anyObjFilter_sf"), QStringLiteral("2")); // bitfield, "2" is the flag for stops
    query.addQueryItem(QStringLiteral("coordOutputFormat"), QStringLiteral("WGS84[DD.ddddd]"));
    url.setQuery(query);

    auto netReply = nam->get(QNetworkRequest(url));
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        if (netReply->error() != QNetworkReply::NoError) {
            qCDebug(Log) << netReply->url() << netReply->errorString();
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        qDebug() << netReply->url();
        EfaParser p;
        p.setLocationIdentifierType(locationIdentifierType());
        // TODO handle parser and response errors
        addResult(reply, p.parseStopFinderResponse(netReply->readAll()));
    });

    return true;
}

bool EfaBackend::queryDeparture(const DepartureRequest &request, DepartureReply *reply, QNetworkAccessManager *nam) const
{
    const auto stopId = request.stop().identifier(locationIdentifierType());
    if (stopId.isEmpty()) {
        return false;
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("XML_DM_REQUEST"));

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("outputFormat"), QStringLiteral("XML"));
    query.addQueryItem(QStringLiteral("coordOutputFormat"), QStringLiteral("WGS84[DD.ddddd]"));
    query.addQueryItem(QStringLiteral("type_dm"), QStringLiteral("stop"));
    query.addQueryItem(QStringLiteral("name_dm"), stopId);
    query.addQueryItem(QStringLiteral("itdDate"), request.dateTime().date().toString(QStringLiteral("yyyyMMdd")));
    query.addQueryItem(QStringLiteral("itdTime"), request.dateTime().time().toString(QStringLiteral("hhmm")));
    query.addQueryItem(QStringLiteral("useRealtime"), QStringLiteral("1"));
    query.addQueryItem(QStringLiteral("limit"), QStringLiteral("12")); // TODO

    // not exactly sure what these do, but without this the result is missing departure times
    query.addQueryItem(QStringLiteral("mode"), QStringLiteral("direct"));
    query.addQueryItem(QStringLiteral("ptOptionsActive"), QStringLiteral("1"));
    query.addQueryItem(QStringLiteral("merge_dep"), QStringLiteral("1"));

    url.setQuery(query);

    auto netReply = nam->get(QNetworkRequest(url));
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        if (netReply->error() != QNetworkReply::NoError) {
            qCDebug(Log) << netReply->url() << netReply->errorString();
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        qDebug() << netReply->url();
        EfaParser p;
        p.setLocationIdentifierType(locationIdentifierType());
        // TODO handle parser and response errors
        addResult(reply, p.parseDmResponse(netReply->readAll()));
    });

    return true;
}

bool EfaBackend::queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    // TODO direct coordinate queries seem to be possible too
    const auto fromId = request.from().identifier(locationIdentifierType());
    const auto toId = request.to().identifier(locationIdentifierType());
    if (fromId.isEmpty() || toId.isEmpty()) {
        return false;
    }

    QUrl url(m_endpoint);
    url.setPath(url.path() + QLatin1String("XML_TRIP_REQUEST2"));

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("outputFormat"), QStringLiteral("XML"));
    query.addQueryItem(QStringLiteral("coordOutputFormat"), QStringLiteral("WGS84[DD.ddddd]"));
    query.addQueryItem(QStringLiteral("locationServerActive"), QStringLiteral("1"));
    query.addQueryItem(QStringLiteral("useRealtime"), QStringLiteral("1"));

    // TODO also observerd:
    //    type_origin:             coord
    //    name_origin:             52.500000:13.500000:WGS84[...]
    query.addQueryItem(QStringLiteral("type_origin"), QStringLiteral("stop"));
    query.addQueryItem(QStringLiteral("name_origin"), fromId);
    query.addQueryItem(QStringLiteral("type_destination"), QStringLiteral("stop"));
    query.addQueryItem(QStringLiteral("name_destination"), toId);

    query.addQueryItem(QStringLiteral("itdDate"), request.dateTime().date().toString(QStringLiteral("yyyyMMdd")));
    query.addQueryItem(QStringLiteral("itdTime"), request.dateTime().time().toString(QStringLiteral("hhmm")));
    query.addQueryItem(QStringLiteral("itdTripDateTimeDepArr"), request.dateTimeMode() == JourneyRequest::Departure ? QStringLiteral("dep") : QStringLiteral("arr"));

    query.addQueryItem(QStringLiteral("calcNumberOfTrips"), QStringLiteral("12")); // TODO

    // saves several 100kb due to not encoding that path coordinates (which we don't even need) as XML
    query.addQueryItem(QStringLiteral("coordListOutputFormat"), QStringLiteral("STRING"));

    url.setQuery(query);

    auto netReply = nam->get(QNetworkRequest(url));
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        if (netReply->error() != QNetworkReply::NoError) {
            qCDebug(Log) << netReply->url() << netReply->errorString();
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        qDebug() << netReply->url();
        EfaParser p;
        p.setLocationIdentifierType(locationIdentifierType());
        // TODO handle parser and response errors
        addResult(reply, p.parseTripResponse(netReply->readAll()));
    });

    return true;
}

QString EfaBackend::locationIdentifierType() const
{
    return m_locationIdentifierType.isEmpty() ? backendId() : m_locationIdentifierType;
}
