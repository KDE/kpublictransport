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

#ifndef KPUBLICTRANSPORT_OPENTRIPPLANNERBACKEND_H
#define KPUBLICTRANSPORT_OPENTRIPPLANNERBACKEND_H

#include "abstractbackend.h"

#include <vector>

class KGraphQLRequest;

namespace KPublicTransport {

/** Access to OpenTripPlanner GraphQL based backends. */
class OpenTripPlannerGraphQLBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QString endpoint MEMBER m_endpoint)
    Q_PROPERTY(QString apiVersion MEMBER m_apiVersion)
    Q_PROPERTY(QString supportedModes MEMBER m_supportedModes)
    Q_PROPERTY(QJsonValue extraHttpHeaders WRITE setExtraHttpHeaders)

public:
    OpenTripPlannerGraphQLBackend();
    ~OpenTripPlannerGraphQLBackend();

    static inline constexpr const char* type() { return "otp_graphql"; }
    Capabilities capabilities() const override;
    bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    bool queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const override;
    bool queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;

private:
    KGraphQLRequest graphQLRequest() const;
    QUrl graphQLEndpoint() const;
    QString graphQLPath(const QString &fileName) const;

    void setExtraHttpHeaders(const QJsonValue &v);

    QString m_endpoint;
    QString m_apiVersion;
    QString m_supportedModes = QStringLiteral("BUS,RAIL,SUBWAY,TRAM,WALK");
    std::vector<std::pair<QByteArray, QByteArray>> m_extraHeaders;
};

}

#endif // KPUBLICTRANSPORT_OPENTRIPPLANNERBACKEND_H
