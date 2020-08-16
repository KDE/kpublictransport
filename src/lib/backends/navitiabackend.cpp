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

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

using namespace KPublicTransport;

NavitiaBackend::NavitiaBackend() = default;

AbstractBackend::Capabilities NavitiaBackend::capabilities() const
{
    return Secure | CanQueryNextJourney | CanQueryPreviousJourney | CanQueryArrivals; // https is hardcoded below
}

bool NavitiaBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    Q_UNUSED(type);
    return !loc.hasCoordinate();
}

bool NavitiaBackend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    if (!req.from().hasCoordinate() || !req.to().hasCoordinate()) {
        return false;
    }

    QUrl url = requestContext(req).value<QUrl>();
    if (!url.isValid()) {
        url.setHost(m_endpoint);
        url.setPath(QStringLiteral("/v1") +
            (m_coverage.isEmpty() ? QString() : (QStringLiteral("/coverage/") + m_coverage)) +
            QStringLiteral("/journeys"));

        QUrlQuery query;
        query.addQueryItem(QStringLiteral("from"), QString::number(req.from().longitude()) + QLatin1Char(';') + QString::number(req.from().latitude()));
        query.addQueryItem(QStringLiteral("to"), QString::number(req.to().longitude()) + QLatin1Char(';') + QString::number(req.to().latitude()));
        if (req.dateTime().isValid()) {
            query.addQueryItem(QStringLiteral("datetime"), req.dateTime().toString(QStringLiteral("yyyyMMddThhmmss")));
            query.addQueryItem(QStringLiteral("datetime_represents"), req.dateTimeMode() == JourneyRequest::Arrival ? QStringLiteral("arrival") : QStringLiteral("departure"));
        }

        // TODO: disable reply parts we don't care about
        query.addQueryItem(QStringLiteral("disable_geojson"), QStringLiteral("true")); // ### seems to have no effect?
        query.addQueryItem(QStringLiteral("depth"), QStringLiteral("0")); // ### also has no effect?
        url.setQuery(query);
    }
    url.setScheme(QStringLiteral("https")); // force https in any case

    QNetworkRequest netReq(url);
    netReq.setRawHeader("Authorization", m_auth.toUtf8());
    logRequest(req, netReq);
    auto netReply = nam->get(netReq);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                NavitiaParser parser;
                addResult(reply, this, parser.parseJourneys(data));
                if (parser.nextLink.isValid()) {
                    setNextRequestContext(reply, parser.nextLink);
                }
                if (parser.prevLink.isValid()) {
                    setPreviousRequestContext(reply, parser.prevLink);
                }
                addAttributions(reply, std::move(parser.attributions));
                break;
            }
            case QNetworkReply::ContentNotFoundError:
                addError(reply, Reply::NotFoundError, NavitiaParser::parseErrorMessage(data));
                break;
            default:
                addError(reply, Reply::NetworkError, netReply->errorString());
                break;
        }
        netReply->deleteLater();
    });

    return true;
}

bool NavitiaBackend::queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    if (!req.stop().hasCoordinate()) {
        return false;
    }
    const auto loc = req.stop();

    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(m_endpoint);
    url.setPath(
        QStringLiteral("/v1/coverage/") +
        (m_coverage.isEmpty() ? QString::number(loc.longitude()) + QLatin1Char(';') + QString::number(loc.latitude()) : m_coverage) +
        QStringLiteral("/coord/") + QString::number(loc.longitude()) + QLatin1Char(';') + QString::number(loc.latitude()) +
        (req.mode() == StopoverRequest::QueryDeparture ? QStringLiteral("/departures") : QStringLiteral("/arrivals"))
    );

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("from_datetime"), req.dateTime().toString(QStringLiteral("yyyyMMddThhmmss")));
    query.addQueryItem(QStringLiteral("disable_geojson"), QStringLiteral("true"));
    query.addQueryItem(QStringLiteral("depth"), QStringLiteral("0"));
    url.setQuery(query);

    QNetworkRequest netReq(url);
    netReq.setRawHeader("Authorization", m_auth.toUtf8());
    logRequest(req, netReq);
    auto netReply = nam->get(netReq);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                NavitiaParser p;
                addResult(reply, this, p.parseDepartures(data));
                if (p.nextLink.isValid()) {
                    setNextRequestContext(reply, p.nextLink);
                }
                if (p.prevLink.isValid()) {
                    setPreviousRequestContext(reply, p.prevLink);
                }
                addAttributions(reply, std::move(p.attributions));
                break;
            }
            case QNetworkReply::ContentNotFoundError:
                addError(reply, Reply::NotFoundError, NavitiaParser::parseErrorMessage(data));
                break;
            default:
                addError(reply, Reply::NetworkError, netReply->errorString());
                break;
        }
        netReply->deleteLater();
    });

    return true;
}

bool NavitiaBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(m_endpoint);

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("disable_geojson"), QStringLiteral("true"));
    query.addQueryItem(QStringLiteral("depth"), QStringLiteral("1")); // 1 so administrative region elements are included
    query.addQueryItem(QStringLiteral("type[]"), QStringLiteral("stop_area"));
    query.addQueryItem(QStringLiteral("count"), QString::number(std::max(1, req.maximumResults())));

    if (req.hasCoordinate()) {
        url.setPath(
            QStringLiteral("/v1/coord/") + QString::number(req.longitude()) + QLatin1Char(';') + QString::number(req.latitude()) +
            QStringLiteral("/places_nearby")
        );
        query.addQueryItem(QStringLiteral("distance"), QString::number(std::max(1, req.maximumDistance())));
    } else if (!req.name().isEmpty()) {
        url.setPath(QStringLiteral("/v1/places"));
        query.addQueryItem(QStringLiteral("q"), req.name());
    } else {
        return false;
    }

    url.setQuery(query);
    QNetworkRequest netReq(url);
    netReq.setRawHeader("Authorization", m_auth.toUtf8());
    logRequest(req, netReq);
    auto netReply = nam->get(netReq);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        switch (netReply->error()) {
            case QNetworkReply::NoError:
            {
                std::vector<Location> res;
                NavitiaParser p;
                if (reply->request().hasCoordinate()) {
                    res = p.parsePlacesNearby(data);
                } else {
                    res = p.parsePlaces(data);
                }
                Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), res, p.attributions);
                addResult(reply, std::move(res));
                addAttributions(reply, std::move(p.attributions));
                break;
            }
            case QNetworkReply::ContentNotFoundError:
                addError(reply, Reply::NotFoundError, NavitiaParser::parseErrorMessage(data));
                break;
            default:
                addError(reply, Reply::NetworkError, netReply->errorString());
                break;
        }
        netReply->deleteLater();
    });

    return true;
}
