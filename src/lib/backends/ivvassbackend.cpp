/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "ivvassbackend.h"
#include "ivvassparser.h"
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

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrlQuery>

using namespace KPublicTransport;

AbstractBackend::Capabilities IvvAssBackend::capabilities() const
{
    return m_endpoint.scheme() == QLatin1String("https") ? Capability::Secure : Capability::NoCapability;
}

bool IvvAssBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    Q_UNUSED(type);
    return !loc.hasCoordinate() && loc.identifier(QStringLiteral("ifopt")).isEmpty();
}

bool IvvAssBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if ((req.types() & Location::Stop) == 0 && !req.hasCoordinate()) {
        return false; // name based search is only available for stops
    }

    QUrlQuery query;
    if (req.hasCoordinate()) {
        query.addQueryItem(QStringLiteral("eID"), QStringLiteral("tx_ekap_here"));
        query.addQueryItem(QStringLiteral("lat"), QString::number(req.latitude()));
        query.addQueryItem(QStringLiteral("lon"), QString::number(req.longitude()));
    } else {
        query.addQueryItem(QStringLiteral("eID"), QStringLiteral("tx_vrsinfo_ass2_objects"));
        query.addQueryItem(QStringLiteral("t"), QStringLiteral("s")); // s: stops, a: addresses, p: pois
        query.addQueryItem(QStringLiteral("q"), req.name());
    }
    query.addQueryItem(QStringLiteral("sc"), QString::number(req.maximumResults())); // station count
    query.addQueryItem(QStringLiteral("ac"), QStringLiteral("0")); // address count
    query.addQueryItem(QStringLiteral("pc"), QStringLiteral("0")); // poi count

    QUrl url(m_endpoint);
    url.setQuery(query);

    QNetworkRequest netRequest(url);
    logRequest(req, netRequest);
    auto netReply = nam->get(netRequest);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        IvvAssParser p;
        auto result = p.parseLocations(data);
        if (p.errorMessage.isEmpty()) {
            Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), result, {});
            addResult(reply, std::move(result));
        } else {
            addError(reply, Reply::UnknownError, std::move(p.errorMessage));
        }
    });

    return true;
}

bool IvvAssBackend::queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("eID"), QStringLiteral("tx_vrsinfo_ass2_timetable"));

    if (req.stop().hasCoordinate()) {
        query.addQueryItem(QStringLiteral("r"), QString::number(req.stop().latitude()) + QLatin1Char(',') + QString::number(req.stop().longitude()));
    } else {
        query.addQueryItem(QStringLiteral("i"), req.stop().identifier(QStringLiteral("ifopt")));
    }
    query.addQueryItem(QStringLiteral("c"), QString::number(req.maximumResults()));

    auto dt = req.dateTime();
    if (timeZone().isValid()) {
        dt = dt.toTimeZone(timeZone());
    }
    dt.setTimeSpec(Qt::LocalTime);
    query.addQueryItem(QStringLiteral("t"), dt.toString(Qt::ISODate));

    QUrl url(m_endpoint);
    url.setQuery(query);

    QNetworkRequest netRequest(url);
    logRequest(req, netRequest);
    auto netReply = nam->get(netRequest);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        IvvAssParser p;
        auto result = p.parseStopovers(data);
        if (p.errorMessage.isEmpty()) {
            addResult(reply, this, std::move(result));
        } else {
            addError(reply, Reply::UnknownError, std::move(p.errorMessage));
        }
    });

    return true;
}

static QString locationParameter(const Location &loc)
{
    if (loc.hasCoordinate()) {
        return QString::number(loc.latitude()) + QLatin1Char(',') + QString::number(loc.longitude());
    }
    return loc.identifier(QStringLiteral("ifopt"));
}

bool IvvAssBackend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("eID"), QStringLiteral("tx_vrsinfo_ass2_router"));
    query.addQueryItem(QStringLiteral("f"), locationParameter(req.from()));
    query.addQueryItem(QStringLiteral("t"), locationParameter(req.to()));

    auto dt = req.dateTime();
    if (timeZone().isValid()) {
        dt = dt.toTimeZone(timeZone());
    }
    dt.setTimeSpec(Qt::LocalTime);
    query.addQueryItem(req.dateTimeMode() == JourneyRequest::Departure ? QStringLiteral("d") : QStringLiteral("a"), dt.toString(Qt::ISODate));
    query.addQueryItem(QStringLiteral("c"), QString::number(req.maximumResults()));
    query.addQueryItem(QStringLiteral("s"), QStringLiteral("t"));

    QString options;
    options.reserve(4);
    if (req.includeIntermediateStops()) {
        options += QLatin1Char('v'); // "vias"
    }
    if (req.includePaths()) {
        options += QLatin1Char('d'); // walking directions
        options += QLatin1Char('p'); // paths
    }
    options += QLatin1Char('a'); // load/demand
    query.addQueryItem(QStringLiteral("o"), options);

    QUrl url(m_endpoint);
    url.setQuery(query);

    QNetworkRequest netRequest(url);
    logRequest(req, netRequest);
    auto netReply = nam->get(netRequest);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        IvvAssParser p;
        auto result = p.parseJourneys(data);
        if (p.errorMessage.isEmpty()) {
            addResult(reply, this, std::move(result));
        } else {
            addError(reply, Reply::UnknownError, std::move(p.errorMessage));
        }
    });

    return true;
}
