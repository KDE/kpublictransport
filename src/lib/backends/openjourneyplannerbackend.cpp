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
#include <KPublicTransport/TripReply>
#include <KPublicTransport/TripRequest>

#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

using namespace KPublicTransport;

AbstractBackend::Capabilities OpenJourneyPlannerBackend::capabilities() const
{
    return AbstractBackend::CanQueryArrivals |
        (m_protocol == OJP2 ? AbstractBackend::CanQueryNextJourney | AbstractBackend::CanQueryPreviousJourney :AbstractBackend::NoCapability) |
        (m_endpoint.scheme() == QLatin1String("https") ? AbstractBackend::Secure : AbstractBackend::NoCapability);
}

Location::Types OpenJourneyPlannerBackend::supportedLocationTypes() const
{
    return Location::Stop;
}

bool OpenJourneyPlannerBackend::needsLocationQuery(const Location &loc, [[maybe_unused]] AbstractBackend::QueryType type) const
{
    return !loc.hasCoordinate() && loc.identifier(QStringLiteral("uic")).isEmpty(); // ### TODO configure identifier type
}

bool OpenJourneyPlannerBackend::queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    const auto postData = requestBuilder().buildLocationInformationRequest(request);
    const auto netReq = networkRequest();
    logRequest(request, netReq, postData);
    const auto netReply = nam->post(netReq, postData);
    netReply->setParent(reply);
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
    netReply->setParent(reply);
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
    QByteArray postData;
    switch (requestContext(request).type) {
        case RequestContext::Normal:
            postData = requestBuilder().buildTripRequest(request);
            break;
        case RequestContext::Previous:
            postData = requestBuilder().buildTripRequest(request, requestContextData(request).toDateTime(), OpenJourneyPlannerRequestBuilder::Before);
            break;
        case RequestContext::Next:
            postData = requestBuilder().buildTripRequest(request, requestContextData(request).toDateTime(), OpenJourneyPlannerRequestBuilder::After);
            break;
    }
    const auto netReq = networkRequest();
    logRequest(request, netReq, postData);
    const auto netReply = nam->post(netReq, postData);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, request, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        auto p = parser();
        auto jnys = p.parseTripResponse(data);
        if (p.hasError() || jnys.empty()) {
            addError(reply, Reply::NotFoundError, p.errorMessage());
        } else {
            QDateTime nextCtx, prevCtx;
            for (const auto &jny : jnys) {
                if (request.dateTimeMode() == JourneyRequest::Departure) {
                    prevCtx = prevCtx.isValid() ? std::min(jny.scheduledDepartureTime(), prevCtx) : jny.scheduledDepartureTime();
                    nextCtx = nextCtx.isValid() ? std::max(jny.scheduledDepartureTime(), nextCtx) : jny.scheduledDepartureTime();
                } else {
                    prevCtx = prevCtx.isValid() ? std::min(jny.scheduledArrivalTime(), prevCtx) : jny.scheduledArrivalTime();
                    nextCtx = nextCtx.isValid() ? std::max(jny.scheduledArrivalTime(), nextCtx) : jny.scheduledArrivalTime();
                }
            }
            setPreviousRequestContext(reply, prevCtx);
            setNextRequestContext(reply, nextCtx);
            addResult(reply, this, std::move(jnys));
        }
    });

    return true;
}

bool OpenJourneyPlannerBackend::queryTrip(const TripRequest &request, TripReply *reply, QNetworkAccessManager *nam) const
{
    if (m_protocol != OJP2 || !m_supportsTripQueries || request.identifier(backendId()).isEmpty()) {
        return false;
    }

    const auto postData = requestBuilder().buildTripInfoRequest(request);
    const auto netReq = networkRequest();
    logRequest(request, netReq, postData);

    const auto netReply = nam->post(netReq, postData);
    netReply->setParent(reply);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        auto p = parser();
        auto trip = p.parseTripInfoResponse(data);
        if (p.hasError()) {
            addError(reply, Reply::NotFoundError, p.errorMessage());
        } else {
            addResult(reply, this, std::move(trip));
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
    builder.setIdentifierType(backendId());
    builder.setProtocol(static_cast<OpenJourneyPlannerRequestBuilder::Protocol>(m_protocol));
    builder.setSupportedModes(&m_supportedModes);
    return builder;
}

OpenJourneyPlannerParser OpenJourneyPlannerBackend::parser() const
{
    OpenJourneyPlannerParser p;
    p.setLocationIdentifierType(backendId());
    p.setUicLocationIdentifierType(m_uicLocationIdentifierType);
    p.setHafasAttributeMapName(m_hafasAttrMapName);
    return p;
}

void OpenJourneyPlannerBackend::setSupportedModes(const QJsonArray &json)
{
    m_supportedModes = Siri::Mode::fromJson(json);
    std::sort(m_supportedModes.begin(), m_supportedModes.end());
}
