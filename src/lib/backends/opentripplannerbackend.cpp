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

#include "opentripplannerbackend.h"

#include <KPublicTransport/DepartureReply>
#include <KPublicTransport/DepartureRequest>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>

#include <kgraphql.h>

#include <QDebug>
#include <QUrl>

using namespace KPublicTransport;

OpenTripPlannerBackend::OpenTripPlannerBackend() = default;
OpenTripPlannerBackend::~OpenTripPlannerBackend() = default;

AbstractBackend::Capabilities OpenTripPlannerBackend::capabilities() const
{
    return m_endpoint.startsWith(QLatin1String("https://")) ? Secure : NoCapability;
}

bool OpenTripPlannerBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    Q_UNUSED(type);
    return !loc.hasCoordinate();
}

bool OpenTripPlannerBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    KGraphQLRequest gqlReq(QUrl(m_endpoint + QLatin1String("index/graphql")));

    if (req.hasCoordinate()) {
        gqlReq.setQueryFromFile(QStringLiteral(":/org.kde.kpublictransport/otp/stationByCoordinate.graphql"));
        gqlReq.setVariable(QStringLiteral("lat"), req.latitude());
        gqlReq.setVariable(QStringLiteral("lon"), req.longitude());
    } else {
        gqlReq.setQueryFromFile(QStringLiteral(":/org.kde.kpublictransport/otp/stationByName.graphql"));
        gqlReq.setVariable(QStringLiteral("name"), req.name());
    }

    KGraphQL::query(gqlReq, nam, [this, reply](const KGraphQLReply &gqlReply) {
        if (gqlReply.error() != KGraphQLReply::NoError) {
            addError(reply, this, Reply::NetworkError, gqlReply.errorString());
            return;
        }
        // TODO
        qDebug() << backendId() << gqlReply.data();
        addError(reply, this, Reply::NetworkError, {});
    });

    qDebug() << backendId() << "starting";
    return true;
}

bool OpenTripPlannerBackend::queryDeparture(const DepartureRequest &req, DepartureReply *reply, QNetworkAccessManager *nam) const
{
    KGraphQLRequest gqlReq(QUrl(m_endpoint + QLatin1String("index/graphql")));
    gqlReq.setQueryFromFile(QStringLiteral(":/org.kde.kpublictransport/otp/departure.graphql"));

    // TODO
    return false;
}

bool OpenTripPlannerBackend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    KGraphQLRequest gqlReq(QUrl(m_endpoint + QLatin1String("index/graphql")));
    gqlReq.setQueryFromFile(QStringLiteral(":/org.kde.kpublictransport/otp/journey.graphql"));
    gqlReq.setVariable(QStringLiteral("fromLat"), req.from().latitude());
    gqlReq.setVariable(QStringLiteral("fromLon"), req.from().longitude());
    gqlReq.setVariable(QStringLiteral("toLat"), req.to().latitude());
    gqlReq.setVariable(QStringLiteral("toLon"), req.to().longitude());
    // TODO time, arrival/departure

    KGraphQL::query(gqlReq, nam, [this, reply](const KGraphQLReply &gqlReply) {
        if (gqlReply.error() != KGraphQLReply::NoError) {
            addError(reply, this, Reply::NetworkError, gqlReply.errorString());
            return;
        }
        // TODO
        qDebug() << backendId() << gqlReply.data();
        addError(reply, this, Reply::NetworkError, {});
    });

    return true;
}
