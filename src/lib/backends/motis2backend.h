/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_MOTIS2BACKEND_H
#define KPUBLICTRANSPORT_MOTIS2BACKEND_H

#include "abstractbackend.h"

#include <QUrl>

class QNetworkRequest;

namespace KPublicTransport {

class IndividualTransport;
class MotisPathQueryTask;

/** Backend for Motis v2 providers.
 *  @see https://github.com/motis-project/motis/blob/master/openapi.yaml
 */
class Motis2Backend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QUrl endpoint MEMBER m_endpoint)
    Q_PROPERTY(QString locationIdentifierType MEMBER m_locationIdentifierType)
    Q_PROPERTY(int cacheDays MEMBER m_cacheDays)
    Q_PROPERTY(bool supportsStreetRouting MEMBER m_supportsStreetRouting)

public:
    explicit Motis2Backend();
    ~Motis2Backend() override;

    static constexpr const char* type() { return "motis2"; }
    [[nodiscard]] Capabilities capabilities() const override;
    [[nodiscard]] Location::Types supportedLocationTypes() const override;
    [[nodiscard]] bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    [[nodiscard]] bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryTrip(const TripRequest &req, TripReply *reply, QNetworkAccessManager *nam) const override;

private:
    template <typename Request>
    QNetworkReply* makeRequest(const Request &req, QObject *parent, QLatin1StringView command, const QUrlQuery &query, QNetworkAccessManager *nam) const;

    [[nodiscard]] QString encodeLocation(const Location &loc) const;

    QUrl m_endpoint;
    QString m_locationIdentifierType;
    int m_cacheDays = 7;
    bool m_supportsStreetRouting = true;
};

}

#endif
