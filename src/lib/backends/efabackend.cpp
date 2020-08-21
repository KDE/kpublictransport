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
#include "efacompactparser.h"
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
    return m_endpoint.startsWith(QLatin1String("https")) ? Secure : NoCapability;
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
    url.setPath(url.path() + (m_stopfinderRequestCommand.isEmpty() ? QLatin1String("XML_STOPFINDER_REQUEST") : m_stopfinderRequestCommand));

    auto query = commonQuery();
    query.addQueryItem(QStringLiteral("locationServerActive"), QStringLiteral("1"));

    if (request.hasCoordinate()) {
        query.addQueryItem(QStringLiteral("type_sf"), QStringLiteral("coord"));
        query.addQueryItem(QStringLiteral("name_sf"), QString::number(request.longitude()) + QLatin1Char(':') + QString::number(request.latitude()) + QLatin1String(":WGS84[DD.ddddd]"));
    } else {
        query.addQueryItem(QStringLiteral("type_sf"), QStringLiteral("stop"));
        query.addQueryItem(QStringLiteral("name_sf"), request.name());
    }

    query.addQueryItem(QStringLiteral("anyObjFilter_sf"), QStringLiteral("2")); // bitfield, "2" is the flag for stops
    query.addQueryItem(QStringLiteral("anyMaxSizeHitList"), QString::number(std::max(1, request.maximumResults())));
    url.setQuery(query);

    QNetworkRequest netRequest(url);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        qDebug() << netReply->url();
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
    url.setPath(url.path() + (m_dmRequestCommand.isEmpty() ? QLatin1String("XML_DM_REQUEST") : m_dmRequestCommand));

    QDateTime dt = request.dateTime();
    if (timeZone().isValid()) {
        dt = dt.toTimeZone(timeZone());
    }

    auto query = commonQuery();
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
    query.addQueryItem(QStringLiteral("limit"), QStringLiteral("12")); // TODO

    // not exactly sure what these do, but without this the result is missing departure times
    query.addQueryItem(QStringLiteral("mode"), QStringLiteral("direct"));
    query.addQueryItem(QStringLiteral("ptOptionsActive"), QStringLiteral("1"));
    query.addQueryItem(QStringLiteral("merge_dep"), QStringLiteral("1"));

    url.setQuery(query);

    QNetworkRequest netRequest(url);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        qDebug() << netReply->url();
        auto p = make_parser();
        auto res = p->parseDmResponse(data);
        if (p->error() != Reply::NoError) {
            addError(reply, p->error(), p->errorMessage());
        } else {
            addResult(reply, this, std::move(res));
        }
    });

    return true;
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
    url.setPath(url.path() + (m_tripRequestCommand.isEmpty() ? QLatin1String("XML_TRIP_REQUEST2") : m_tripRequestCommand));

    auto query = commonQuery();
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

    query.addQueryItem(QStringLiteral("calcNumberOfTrips"), QStringLiteral("12")); // TODO

    // saves several 100kb due to not encoding that path coordinates (which we don't even need) as XML
    query.addQueryItem(QStringLiteral("coordListOutputFormat"), QStringLiteral("STRING"));

    url.setQuery(query);

    QNetworkRequest netRequest(url);
    logRequest(request, netRequest);
    auto netReply = nam->get(netRequest);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }
        qDebug() << netReply->url();
        auto p = make_parser();
        auto res = p->parseTripResponse(data);
        if (p->error() != Reply::NoError) {
            addError(reply, p->error(), p->errorMessage());
        } else {
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
