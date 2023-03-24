/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "openjourneyplannerbackend.h"
#include "openjourneyplannerparser.h"
#include "openjourneyplannerrequestbuilder.h"
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

using namespace KPublicTransport;

AbstractBackend::Capabilities OpenJourneyPlannerBackend::capabilities() const
{
    return AbstractBackend::CanQueryArrivals |
        (m_endpoint.scheme() == QLatin1String("https") ? AbstractBackend::Secure : AbstractBackend::NoCapability);
}

bool OpenJourneyPlannerBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    return !loc.hasCoordinate() && loc.identifier(QStringLiteral("uic")).isEmpty(); // ### TODO configure identifier type
}

bool OpenJourneyPlannerBackend::queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if ((request.types() & Location::Stop) == 0) {
        return false;
    }

    const auto postData = requestBuilder().buildLocationInformationRequest(request);
    const auto netReq = networkRequest();
    logRequest(request, netReq, postData);
    const auto netReply = nam->post(netReq, postData);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        auto p = parser();
        auto locs = p.parseLocationInformationResponse(data);
        if (p.hasError()) {
            addError(reply, Reply::NotFoundError, p.errorMessage());
        } else {
            Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), locs, {});
            addResult(reply, std::move(locs));
        }
    });

    return true;
}

bool OpenJourneyPlannerBackend::queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    const auto postData = requestBuilder().buildStopEventRequest(request);
    const auto netReq = networkRequest();
    logRequest(request, netReq, postData);
    const auto netReply = nam->post(netReq, postData);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        auto p = parser();
        auto stops = p.parseStopEventResponse(data);
        if (p.hasError()) {
            addError(reply, Reply::NotFoundError, p.errorMessage());
        } else {
            // TODO caching
            addResult(reply, this, std::move(stops));
        }
    });

    return true;
}

bool OpenJourneyPlannerBackend::queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    const auto postData = requestBuilder().buildTripRequest(request);
    const auto netReq = networkRequest();
    logRequest(request, netReq, postData);
    const auto netReply = nam->post(netReq, postData);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        auto p = parser();
        auto jnys = p.parseTripResponse(data);
        if (p.hasError()) {
            addError(reply, Reply::NotFoundError, p.errorMessage());
        } else {
            // TODO caching
            addResult(reply, this, std::move(jnys));
        }
    });

    return true;
}

QNetworkRequest OpenJourneyPlannerBackend::networkRequest() const
{
    QNetworkRequest req(m_endpoint);
    req.setHeader(QNetworkRequest::ContentTypeHeader, m_contentType);
    if (!m_authorization.isEmpty()) {
        req.setRawHeader("Authorization", m_authorization.toUtf8());
    }
    return req;
}

OpenJourneyPlannerRequestBuilder OpenJourneyPlannerBackend::requestBuilder() const
{
    OpenJourneyPlannerRequestBuilder builder;
    builder.setRequestorRef(m_requestorRef);
    builder.setUseTrias(m_useTrias);
    return builder;
}

OpenJourneyPlannerParser OpenJourneyPlannerBackend::parser() const
{
    OpenJourneyPlannerParser p;
    p.setLocationIdentifierType(backendId());
    p.setUicLocationIdentifierType(m_uicLocationIdentifierType);
    return p;
}
