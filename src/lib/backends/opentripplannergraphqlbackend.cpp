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

#include "opentripplannergraphqlbackend.h"
#include "opentripplannerparser.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopoverReply>
#include <KPublicTransport/StopoverRequest>

#include <kgraphql.h>

#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QNetworkRequest>
#include <QUrl>

using namespace KPublicTransport;

OpenTripPlannerGraphQLBackend::OpenTripPlannerGraphQLBackend() = default;
OpenTripPlannerGraphQLBackend::~OpenTripPlannerGraphQLBackend() = default;

AbstractBackend::Capabilities OpenTripPlannerGraphQLBackend::capabilities() const
{
    return m_endpoint.startsWith(QLatin1String("https://")) ? Secure : NoCapability;
}

bool OpenTripPlannerGraphQLBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    Q_UNUSED(type);
    return !loc.hasCoordinate();
}

bool OpenTripPlannerGraphQLBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    auto gqlReq = graphQLRequest();
    if (req.hasCoordinate()) {
        gqlReq.setQueryFromFile(graphQLPath(QStringLiteral("stationByCoordinate.graphql")));
        gqlReq.setVariable(QStringLiteral("lat"), req.latitude());
        gqlReq.setVariable(QStringLiteral("lon"), req.longitude());
        gqlReq.setVariable(QStringLiteral("radius"), req.maximumDistance());
    } else {
        gqlReq.setQueryFromFile(graphQLPath(QStringLiteral("stationByName.graphql")));
        gqlReq.setVariable(QStringLiteral("name"), req.name());
    }

    if (isLoggingEnabled()) {
        logRequest(req, gqlReq.networkRequest(), gqlReq.rawData());
    }
    KGraphQL::query(gqlReq, nam, [this, req, reply](const KGraphQLReply &gqlReply) {
        logReply(reply, gqlReply.networkReply(), gqlReply.rawData());
        if (gqlReply.error() != KGraphQLReply::NoError) {
            addError(reply, Reply::NetworkError, gqlReply.errorString());
            return;
        }

        OpenTripPlannerParser p(backendId());
        if (req.hasCoordinate()) {
            addResult(reply, p.parseLocationsByCoordinate(gqlReply.data()));
        } else {
            addResult(reply, p.parseLocationsByName(gqlReply.data()));
        }
    });

    return true;
}

bool OpenTripPlannerGraphQLBackend::queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    auto gqlReq = graphQLRequest();
    gqlReq.setQueryFromFile(graphQLPath(QStringLiteral("departure.graphql")));
    gqlReq.setVariable(QStringLiteral("lat"), req.stop().latitude());
    gqlReq.setVariable(QStringLiteral("lon"), req.stop().longitude());
    auto dt = req.dateTime();
    if (timeZone().isValid()) {
        dt = dt.toTimeZone(timeZone());
    }
    gqlReq.setVariable(QStringLiteral("startTime"), dt.toSecsSinceEpoch());
    gqlReq.setVariable(QStringLiteral("startDateTime"), dt.toString(Qt::ISODate));
    // TODO arrival/departure selection?

    if (isLoggingEnabled()) {
        logRequest(req, gqlReq.networkRequest(), gqlReq.rawData());
    }
    KGraphQL::query(gqlReq, nam, [this, reply](const KGraphQLReply &gqlReply) {
        logReply(reply, gqlReply.networkReply(), gqlReply.rawData());
        if (gqlReply.error() != KGraphQLReply::NoError) {
            addError(reply, Reply::NetworkError, gqlReply.errorString());
        } else {
            OpenTripPlannerParser p(backendId());
            addResult(reply, this, p.parseDepartures(gqlReply.data()));
        }
    });

    return true;
}

bool OpenTripPlannerGraphQLBackend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    auto gqlReq = graphQLRequest();
    gqlReq.setQueryFromFile(graphQLPath(QStringLiteral("journey.graphql")));
    gqlReq.setVariable(QStringLiteral("fromLat"), req.from().latitude());
    gqlReq.setVariable(QStringLiteral("fromLon"), req.from().longitude());
    gqlReq.setVariable(QStringLiteral("toLat"), req.to().latitude());
    gqlReq.setVariable(QStringLiteral("toLon"), req.to().longitude());
    auto dt = req.dateTime();
    if (timeZone().isValid()) {
        dt = dt.toTimeZone(timeZone());
    }
    gqlReq.setVariable(QStringLiteral("date"), dt.toString(QStringLiteral("yyyy-MM-dd")));
    gqlReq.setVariable(QStringLiteral("time"), dt.toString(QStringLiteral("hh:mm:ss")));
    gqlReq.setVariable(QStringLiteral("dateTime"), dt.toString(Qt::ISODate));
    gqlReq.setVariable(QStringLiteral("arriveBy"), req.dateTimeMode() == JourneyRequest::Arrival);
    gqlReq.setVariable(QStringLiteral("modes"), m_supportedModes);

    if (isLoggingEnabled()) {
        logRequest(req, gqlReq.networkRequest(), gqlReq.rawData());
    }
    KGraphQL::query(gqlReq, nam, [this, reply](const KGraphQLReply &gqlReply) {
        logReply(reply, gqlReply.networkReply(), gqlReply.rawData());
        if (gqlReply.error() != KGraphQLReply::NoError) {
            addError(reply, Reply::NetworkError, gqlReply.errorString());
        } else {
            OpenTripPlannerParser p(backendId());
            addResult(reply, this, p.parseJourneys(gqlReply.data()));
        }
    });

    return true;
}

KGraphQLRequest OpenTripPlannerGraphQLBackend::graphQLRequest() const
{
    KGraphQLRequest req(graphQLEndpoint());
    for (const auto &header : m_extraHeaders) {
        req.networkRequest().setRawHeader(header.first, header.second);
    }
    return req;
}

QUrl OpenTripPlannerGraphQLBackend::graphQLEndpoint() const
{
    if (m_apiVersion == QLatin1String("entur")) {
        return QUrl(m_endpoint);
    }
    return QUrl(m_endpoint + QLatin1String("index/graphql"));
}

static QString graphQLBasePath()
{
    return QStringLiteral(":/org.kde.kpublictransport/otp/");
}

QString OpenTripPlannerGraphQLBackend::graphQLPath(const QString &fileName) const
{
    if (!m_apiVersion.isEmpty()) {
        const QString versionedPath = graphQLBasePath() + m_apiVersion + QLatin1Char('/') + fileName;
        if (QFile::exists(versionedPath)) {
            return versionedPath;
        }
    }
    return graphQLBasePath() + fileName;
}

void OpenTripPlannerGraphQLBackend::setExtraHttpHeaders(const QJsonValue &v)
{
    const auto headers = v.toArray();
    m_extraHeaders.reserve(headers.size());
    for (const auto &header : headers) {
        const auto headerObj = header.toObject();
        const auto name = headerObj.value(QLatin1String("name")).toString().toUtf8();
        const auto val = headerObj.value(QLatin1String("value")).toString().toUtf8();
        if (name.isEmpty() || val.isEmpty()) {
            continue;
        }
        m_extraHeaders.push_back(std::make_pair(name, val));
    }
}
