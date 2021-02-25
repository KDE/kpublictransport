/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "ivvassbackend.h"

#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>
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
    return false; // TODO
}

bool IvvAssBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    QUrlQuery query;
    if (req.hasCoordinate()) {
        query.addQueryItem(QStringLiteral("eID"), QStringLiteral("tx_ekap_here"));
        query.addQueryItem(QStringLiteral("lat"), QString::number(req.latitude()));
        query.addQueryItem(QStringLiteral("lon"), QString::number(req.longitude()));
    } else {
        query.addQueryItem(QStringLiteral("eID"), QStringLiteral("tx_vrsinfo_ass2_objects"));
        query.addQueryItem(QStringLiteral("t"), QStringLiteral("sap")); // ???
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
        qDebug() << data;

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        addError(reply, Reply::UnknownError, {});
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
        query.addQueryItem(QStringLiteral("i"), QStringLiteral("802"));  // TODO vrs station id, ifopt
    }
//     query.addQueryItem(QStringLiteral("c"), QString::number(req.maximumResults()));
    // TODO timezone conversion
    query.addQueryItem(QStringLiteral("t"), req.dateTime().toString(Qt::ISODate));

    QUrl url(m_endpoint);
    url.setQuery(query);

    QNetworkRequest netRequest(url);
    logRequest(req, netRequest);
    auto netReply = nam->get(netRequest);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);
        qDebug() << data;

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        addError(reply, Reply::UnknownError, {});
    });

    return true;
}

bool IvvAssBackend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("eID"), QStringLiteral("tx_vrsinfo_ass2_router"));
    query.addQueryItem(QStringLiteral("f"), QStringLiteral("802"));  // TODO vrs station id, ifopt, coordinates possible as well?
    query.addQueryItem(QStringLiteral("t"), QStringLiteral("2071"));  // TODO
    // TODO timezone conversion
    query.addQueryItem(req.dateTimeMode() == JourneyRequest::Departure ? QStringLiteral("d") : QStringLiteral("a"), req.dateTime().toString(Qt::ISODate));
    query.addQueryItem(QStringLiteral("c"), QString::number(req.maximumResults()));
    query.addQueryItem(QStringLiteral("s"), QStringLiteral("t"));
    query.addQueryItem(QStringLiteral("o"), QStringLiteral("vdpa")); // v: intermediate stops, d: walking directions, p: paths, a: load

    QUrl url(m_endpoint);
    url.setQuery(query);

    QNetworkRequest netRequest(url);
    logRequest(req, netRequest);
    auto netReply = nam->get(netRequest);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);
        qDebug() << data;

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        addError(reply, Reply::UnknownError, {});
    });

    return true;
}
