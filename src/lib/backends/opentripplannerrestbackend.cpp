/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#include "opentripplannerrestbackend.h"
#include "opentripplannerparser.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/DepartureReply>
#include <KPublicTransport/DepartureRequest>
#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

using namespace KPublicTransport;

OpenTripPlannerRestBackend::OpenTripPlannerRestBackend() = default;
OpenTripPlannerRestBackend::~OpenTripPlannerRestBackend() = default;

AbstractBackend::Capabilities OpenTripPlannerRestBackend::capabilities() const
{
    return m_endpoint.startsWith(QLatin1String("https://")) ? Secure : NoCapability;
}

bool OpenTripPlannerRestBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    Q_UNUSED(type);
    switch (type) {
        case AbstractBackend::QueryType::Journey:
            return !loc.hasCoordinate() && loc.identifier(backendId()).isEmpty();
        case AbstractBackend::QueryType::Departure:
            return loc.identifier(backendId()).isEmpty();
    }
    return false;
}

bool OpenTripPlannerRestBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if (req.hasCoordinate()) {
        QUrlQuery query;
        query.addQueryItem(QStringLiteral("lat"), QString::number(req.latitude()));
        query.addQueryItem(QStringLiteral("lon"), QString::number(req.longitude()));
        query.addQueryItem(QStringLiteral("radius"), QStringLiteral("500")); //  TODO

        QUrl url(m_endpoint + QLatin1String("index/stops"));
        url.setQuery(query);

        QNetworkRequest netReq(url);
        logRequest(req, netReq);
        auto netReply = nam->get(netReq);
        QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply] {
            const auto data = netReply->readAll();
            logReply(reply, netReply, data);

            if (netReply->error() != QNetworkReply::NoError) {
                addError(reply, this, Reply::NetworkError, netReply->errorString());
                return;
            }
            OpenTripPlannerParser p(backendId());
            addResult(reply, p.parseLocationsArray(QJsonDocument::fromJson(data).array()));
        });

        return true;
    }
    if (!req.name().isEmpty()) {
        QUrlQuery query;
        query.addQueryItem(QStringLiteral("query"), req.name());
        query.addQueryItem(QStringLiteral("stops"), QStringLiteral("true"));
        query.addQueryItem(QStringLiteral("corners"), QStringLiteral("false"));

        QUrl url(m_endpoint + QLatin1String("geocode"));
        url.setQuery(query);

        QNetworkRequest netReq(url);
        logRequest(req, netReq);
        auto netReply = nam->get(netReq);
        QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply] {
            const auto data = netReply->readAll();
            logReply(reply, netReply, data);

            if (netReply->error() != QNetworkReply::NoError) {
                addError(reply, this, Reply::NetworkError, netReply->errorString());
                return;
            }
            OpenTripPlannerParser p(backendId());
            addResult(reply, p.parseGeocodeResult(QJsonDocument::fromJson(data).array()));
        });

        return true;
    }

    return false;
}

bool OpenTripPlannerRestBackend::queryDeparture(const DepartureRequest &req, DepartureReply *reply, QNetworkAccessManager *nam) const
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("date"), QString::number(req.dateTime().toSecsSinceEpoch()));
    query.addQueryItem(QStringLiteral("numberOfDepartures"), QStringLiteral("12"));
    query.addQueryItem(QStringLiteral("omitNonPickups"), req.mode() == DepartureRequest::QueryDeparture ? QStringLiteral("true") : QStringLiteral("false"));

    QUrl url(m_endpoint + QLatin1String("index/stops/") + req.stop().identifier(backendId()) + QLatin1String("/stoptimes"));
    url.setQuery(query);

    QNetworkRequest netReq(url);
    logRequest(req, netReq);
    auto netReply = nam->get(netReq);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, req, reply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, this, Reply::NetworkError, netReply->errorString());
            return;
        }
        OpenTripPlannerParser p(backendId());
        auto res = p.parseDeparturesArray(QJsonDocument::fromJson(data).array());
        for (auto &dep : res) {
            dep.setStopPoint(req.stop());
        }
        addResult(reply, this, std::move(res));
    });

    return true;
}

bool OpenTripPlannerRestBackend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("fromPlace"), locationToQuery(req.from()));
    query.addQueryItem(QStringLiteral("toPlace"), locationToQuery(req.to()));
    auto dt = req.dateTime();
    if (timeZone().isValid()) {
        dt = dt.toTimeZone(timeZone());
        dt.setTimeSpec(Qt::LocalTime); // pretend we have local time, so toString() isn't adding a UTC offset
    }
    query.addQueryItem(QStringLiteral("date"), dt.date().toString(Qt::ISODate));
    query.addQueryItem(QStringLiteral("time"), dt.time().toString(Qt::ISODate));
    query.addQueryItem(QStringLiteral("arriveBy"), req.dateTimeMode() == JourneyRequest::Arrival ? QStringLiteral("true") : QStringLiteral("false"));

    QUrl url(m_endpoint + QLatin1String("plan"));
    url.setQuery(query);

    QNetworkRequest netReq(url);
    logRequest(req, netReq);
    auto netReply = nam->get(netReq);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, this, Reply::NetworkError, netReply->errorString());
            return;
        }
        OpenTripPlannerParser p(backendId());
        addResult(reply, this, p.parseJourneys(QJsonDocument::fromJson(data).object()));
    });

    return true;
}

QString OpenTripPlannerRestBackend::locationToQuery(const Location &loc) const
{
    if (loc.hasCoordinate()) {
        return QString::number(loc.latitude()) + QLatin1Char(',') + QString::number(loc.longitude());
    }
    return loc.identifier(backendId());
}
