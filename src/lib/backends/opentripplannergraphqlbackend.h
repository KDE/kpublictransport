/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENTRIPPLANNERBACKEND_H
#define KPUBLICTRANSPORT_OPENTRIPPLANNERBACKEND_H

#include "abstractbackend.h"

#include <QHash>

#include <vector>

class KGraphQLRequest;

namespace KPublicTransport {

class RentalVehicleNetwork;

/** Access to OpenTripPlanner GraphQL based backends. */
class OpenTripPlannerGraphQLBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QString endpoint MEMBER m_endpoint)
    Q_PROPERTY(QString apiVersion MEMBER m_apiVersion)
    Q_PROPERTY(QStringList supportedTransitModes MEMBER m_supportedTransitModes)
    Q_PROPERTY(QStringList supportedRentalModes MEMBER m_supportedRentalModes)
    Q_PROPERTY(QJsonValue extraHttpHeaders WRITE setExtraHttpHeaders)
    Q_PROPERTY(QJsonObject rentalVehicleNetworks WRITE setRentalVehicleNetworks)
    Q_PROPERTY(QString ifoptPrefix MEMBER m_ifoptPrefix)

public:
    OpenTripPlannerGraphQLBackend();
    ~OpenTripPlannerGraphQLBackend() override;

    [[nodiscard]] static inline constexpr const char* type() { return "otpGraphQl"; }
    [[nodiscard]] Capabilities capabilities() const override;
    [[nodiscard]] bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    [[nodiscard]] bool queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryTrip(const TripRequest &req, TripReply *reply, QNetworkAccessManager *nam) const override;

private:
    [[nodiscard]] KGraphQLRequest graphQLRequest() const;
    [[nodiscard]] QUrl graphQLEndpoint() const;
    [[nodiscard]] QString graphQLPath(const QString &fileName) const;

    void setExtraHttpHeaders(const QJsonValue &v);
    void setRentalVehicleNetworks(const QJsonObject &obj);

    QString m_endpoint;
    QString m_apiVersion;
    QStringList m_supportedTransitModes = { QStringLiteral("TRANSIT") };
    QStringList m_supportedRentalModes = { QStringLiteral("BICYCLE") };
    std::vector<std::pair<QByteArray, QByteArray>> m_extraHeaders;
    QHash<QString, RentalVehicleNetwork> m_rentalNetworks;
    QString m_ifoptPrefix;
};

}

#endif // KPUBLICTRANSPORT_OPENTRIPPLANNERBACKEND_H
