/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "opentripplannergraphqlbackend.h"
#include "opentripplannerparser.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/RentalVehicle>
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
    if ((req.types() & (Location::Stop | Location::RentedVehicle | Location::RentedVehicleStation)) == 0) {
        return false;
    }

    auto gqlReq = graphQLRequest();
    if (req.hasCoordinate()) {
        gqlReq.setQueryFromFile(graphQLPath(QStringLiteral("stationByCoordinate.graphql")));
        gqlReq.setVariable(QStringLiteral("lat"), req.latitude());
        gqlReq.setVariable(QStringLiteral("lon"), req.longitude());
        gqlReq.setVariable(QStringLiteral("radius"), req.maximumDistance());
        gqlReq.setVariable(QStringLiteral("maxResults"), req.maximumResults());
        QJsonArray placeTypeFilter;
        if (req.types() & Location::Stop) {
            placeTypeFilter.push_back(QStringLiteral("STOP"));
        }
        if (req.types() & (Location::RentedVehicleStation | Location::RentedVehicle)) {
            placeTypeFilter.push_back(QStringLiteral("BICYCLE_RENT"));
        }
        // TODO: also supports BIKE_PARK, CAR_PARK
        gqlReq.setVariable(QStringLiteral("placeType"), placeTypeFilter);
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
        p.setKnownRentalVehicleNetworks(m_rentalNetworks);
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

    QJsonArray modes;
    QJsonObject walkMode;
    walkMode.insert(QStringLiteral("mode"), QStringLiteral("WALK"));
    modes.push_back(walkMode);
    if (req.modes() & JourneySection::PublicTransport) {
        for (const auto &mode : m_supportedTransitModes) {
            QJsonObject transitMode;
            transitMode.insert(QStringLiteral("mode"), mode);
            modes.push_back(transitMode);
        }
    }
    if (req.modes() & JourneySection::RentedVehicle) {
        for (const auto &mode : m_supportedRentalModes) {
            QJsonObject rentMode;
            rentMode.insert(QStringLiteral("mode"), mode);
            rentMode.insert(QStringLiteral("qualifier"), QStringLiteral("RENT"));
            modes.push_back(rentMode);
        }
    }
    gqlReq.setVariable(QStringLiteral("modes"), modes);

    if (isLoggingEnabled()) {
        logRequest(req, gqlReq.networkRequest(), gqlReq.rawData());
    }
    KGraphQL::query(gqlReq, nam, [this, reply](const KGraphQLReply &gqlReply) {
        logReply(reply, gqlReply.networkReply(), gqlReply.rawData());
        if (gqlReply.error() != KGraphQLReply::NoError) {
            addError(reply, Reply::NetworkError, gqlReply.errorString());
        } else {
            OpenTripPlannerParser p(backendId());
            p.setKnownRentalVehicleNetworks(m_rentalNetworks);
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
    applySslConfiguration(req.networkRequest());
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

void OpenTripPlannerGraphQLBackend::setRentalVehicleNetworks(const QJsonObject &obj)
{
    m_rentalNetworks.reserve(obj.size());
    for (auto it = obj.begin(); it != obj.end(); ++it) {
        auto n = RentalVehicleNetwork::fromJson(it.value().toObject());
        m_rentalNetworks.insert(it.key(), std::move(n));
    }
}
