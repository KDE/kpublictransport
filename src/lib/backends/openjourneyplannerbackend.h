/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENJOURNEYPLANNERBACKEND_H
#define KPUBLICTRANSPORT_OPENJOURNEYPLANNERBACKEND_H

#include "abstractbackend.h"

#include <QByteArray>
#include <QUrl>

class QNetworkRequest;

namespace KPublicTransport {

class OpenJourneyPlannerParser;
class OpenJourneyPlannerRequestBuilder;

/** Backend for OpenJourneyPlanner services
 *  Due to its similarities, this might also be viable for TRIAS-based services.
 */
class OpenJourneyPlannerBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QUrl endpoint MEMBER m_endpoint)
    Q_PROPERTY(QString authorization MEMBER m_authorization)
    Q_PROPERTY(QString requestorRef MEMBER m_requestorRef)
    Q_PROPERTY(bool useTrias MEMBER m_useTrias)
    /** Override the default HTTP ContentType header in the request. */
    Q_PROPERTY(QByteArray contentType MEMBER m_contentType)
    /** Location identifier type for UIC station codes.
     *  Typically "uic" or "ibnr".
     */
    Q_PROPERTY(QString uicLocationIdentifierType MEMBER m_uicLocationIdentifierType)

public:
    static  constexpr const char* type() { return "openJourneyPlanner"; }
    [[nodiscard]] AbstractBackend::Capabilities capabilities() const override;
    [[nodiscard]] Location::Types supportedLocationTypes() const override;
    [[nodiscard]] bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    [[nodiscard]] bool queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryJourney(const JourneyRequest &request, JourneyReply * reply, QNetworkAccessManager *nam) const override;

private:
    [[nodiscard]] QNetworkRequest networkRequest() const;
    [[nodiscard]] OpenJourneyPlannerRequestBuilder requestBuilder() const;
    [[nodiscard]] OpenJourneyPlannerParser parser() const;

    QUrl m_endpoint;
    QString m_authorization;
    QString m_requestorRef = QStringLiteral("KPublicTransport");
    bool m_useTrias = false;
    QByteArray m_contentType = "application/xml";
    QString m_uicLocationIdentifierType;
};

}

#endif // KPUBLICTRANSPORT_OPENJOURNEYPLANNERBACKEND_H
