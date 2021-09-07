/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "openjourneyplannerbackend.h"
#include "openjourneyplannerparser.h"
#include "openjourneyplannerrequestbuilder.h"

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
    return m_endpoint.scheme() == QLatin1String("https") ? AbstractBackend::Secure : AbstractBackend::NoCapability;
}

bool OpenJourneyPlannerBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    if (!loc.identifier(QStringLiteral("uic")).isEmpty()) {// ### TODO configure identifier type
        return false;
    }
    // TODO according to the docs this is supposed to work?
    //return !loc.hasCoordinate() || type != AbstractBackend::QueryType::Journey;
    return true;
}

bool OpenJourneyPlannerBackend::queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if ((request.types() & Location::Stop) == 0) {
        return false;
    }

    OpenJourneyPlannerRequestBuilder builder;
    const auto postData = builder.buildLocationInformationRequest(request);
    const auto netReq = networkRequest();
    logRequest(request, netReq, postData);
    const auto netReply = nam->post(netReq, postData);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        OpenJourneyPlannerParser p;
        auto locs = p.parseLocationInformationResponse(data);
        // TODO caching, error handling
        addResult(reply, std::move(locs));
    });

    return true;
}

bool OpenJourneyPlannerBackend::queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    OpenJourneyPlannerRequestBuilder builder;
    const auto postData = builder.buildStopEventRequest(request);
    const auto netReq = networkRequest();
    logRequest(request, netReq, postData);
    const auto netReply = nam->post(netReq, postData);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        OpenJourneyPlannerParser p;
        auto stops = p.parseStopEventResponse(data);
        // TODO caching, error handling
        addResult(reply, this, std::move(stops));
    });

    return true;
}

bool OpenJourneyPlannerBackend::queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    OpenJourneyPlannerRequestBuilder builder;
    const auto postData = builder.buildTripRequest(request);
    const auto netReq = networkRequest();
    logRequest(request, netReq, postData);
    // TODO
    return false;
}

QNetworkRequest OpenJourneyPlannerBackend::networkRequest() const
{
    QNetworkRequest req(m_endpoint);
    req.setHeader(QNetworkRequest::ContentTypeHeader, QByteArray("application/xml"));
    if (!m_authorization.isEmpty()) {
        req.setRawHeader("Authorization", m_authorization.toUtf8());
    }
    return req;
}
