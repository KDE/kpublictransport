/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "navitiabackend.h"
#include "logging.h"
#include "navitiaparser.h"
#include "navitiaphysicalmode.h"
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

struct {
    IndividualTransport::Mode mode;
    IndividualTransport::Qualifier qualifier;
    const char *name;
} static constexpr const mode_table[] = {
    { IndividualTransport::Walk, IndividualTransport::None, "walking" },
    { IndividualTransport::Bike, IndividualTransport::None, "bike" },
    { IndividualTransport::Bike, IndividualTransport::Park, "bike" }, // ### ?
    { IndividualTransport::Bike, IndividualTransport::Rent, "bss" },
    { IndividualTransport::Car, IndividualTransport::None, "car" },
    { IndividualTransport::Car, IndividualTransport::Park, "car" },
    { IndividualTransport::Car, IndividualTransport::Dropoff, "car_no_park" },
    // TODO: ridesharing, taxi
};

static void addModeArgument(const QString &arg, const std::vector<IndividualTransport> &modes, QUrlQuery &query)
{
    for (const auto &mode : modes) {
        const auto it = std::find_if(std::begin(mode_table), std::end(mode_table), [mode](const auto &entry) {
            return entry.mode == mode.mode() && entry.qualifier == mode.qualifier();
        });
        if (it != std::end(mode_table)) {
            query.addQueryItem(arg, QLatin1String((*it).name));
        }
    }
}

bool NavitiaBackend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    if ((req.modes() & JourneySection::PublicTransport) == 0) {
        return false;
    }
    if (!req.from().hasCoordinate() || !req.to().hasCoordinate()) {
        return false;
    }

    QUrl url = requestContextData(req).value<QUrl>();
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
        query.addQueryItem(QStringLiteral("count"), QString::number(std::max(1, req.maximumResults())));
        NavitiaPhysicalMode::lineModesToQuery(req.lineModes(), query);
        addModeArgument(QStringLiteral("first_section_mode[]"), req.accessModes(), query);
        addModeArgument(QStringLiteral("last_section_mode[]"), req.egressModes(), query);

        // TODO: disable reply parts we don't care about
        query.addQueryItem(QStringLiteral("disable_geojson"), req.includePaths() ? QStringLiteral("false") : QStringLiteral("true"));
        query.addQueryItem(QStringLiteral("depth"), QStringLiteral("0")); // ### also has no effect?
        query.addQueryItem(QStringLiteral("add_poi_infos[]"), QStringLiteral("bss_stands"));
        url.setQuery(query);
    }
    url.setScheme(QStringLiteral("https")); // force https in any case

    QNetworkRequest netReq(url);
    netReq.setRawHeader("Authorization", m_auth.toUtf8());
    logRequest(req, netReq);
    auto netReply = nam->get(netReq);
    netReply->setParent(reply);
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
    query.addQueryItem(QStringLiteral("count"), QString::number(std::max(1, req.maximumResults())));
    NavitiaPhysicalMode::lineModesToQuery(req.lineModes(), query);
    url.setQuery(query);

    QNetworkRequest netReq(url);
    netReq.setRawHeader("Authorization", m_auth.toUtf8());
    logRequest(req, netReq);
    auto netReply = nam->get(netReq);
    netReply->setParent(reply);
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
    if ((req.types() & (Location::Stop | Location::RentedVehicleStation)) == 0) {
        return false;
    }

    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(m_endpoint);

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("disable_geojson"), QStringLiteral("true"));
    query.addQueryItem(QStringLiteral("depth"), QStringLiteral("1")); // 1 so administrative region elements are included
    query.addQueryItem(QStringLiteral("count"), QString::number(std::max(1, req.maximumResults())));
    if (req.types() & Location::Stop) {
        query.addQueryItem(QStringLiteral("type[]"), QStringLiteral("stop_point"));
    }
    if (req.types() & Location::RentedVehicleStation) {
        query.addQueryItem(QStringLiteral("type[]"), QStringLiteral("poi"));
        query.addQueryItem(QStringLiteral("add_poi_infos[]"), QStringLiteral("bss_stands"));
        // filter is exclusive, so we cannot use this when also looking for other objects
        if ((req.types() & ~(Location::RentedVehicleStation | Location::RentedVehicle)) == 0) {
            query.addQueryItem(QStringLiteral("filter"), QStringLiteral("poi_type.id=poi_type:amenity:bicycle_rental"));
        }
    }

    if (req.hasCoordinate()) {
        url.setPath(QStringLiteral("/v1") +
            (m_coverage.isEmpty() ? QString() : (QStringLiteral("/coverage/") + m_coverage)) +
            QStringLiteral("/coord/") + QString::number(req.longitude()) + QLatin1Char(';') + QString::number(req.latitude()) +
            QStringLiteral("/places_nearby"));
        query.addQueryItem(QStringLiteral("distance"), QString::number(std::max(1, req.maximumDistance())));
    } else if (!req.name().isEmpty()) {
        url.setPath(QStringLiteral("/v1") +
            (m_coverage.isEmpty() ? QString() : (QStringLiteral("/coverage/") + m_coverage)) +
            QStringLiteral("/places"));
        query.addQueryItem(QStringLiteral("q"), req.name());
    } else {
        return false;
    }

    url.setQuery(query);
    QNetworkRequest netReq(url);
    netReq.setRawHeader("Authorization", m_auth.toUtf8());
    logRequest(req, netReq);
    auto netReply = nam->get(netReq);
    netReply->setParent(reply);
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
