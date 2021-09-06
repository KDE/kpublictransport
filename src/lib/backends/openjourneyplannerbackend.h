/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENJOURNEYPLANNERBACKEND_H
#define KPUBLICTRANSPORT_OPENJOURNEYPLANNERBACKEND_H

#include "abstractbackend.h"

#include <QUrl>

class QNetworkRequest;

namespace KPublicTransport {

/** Backend for OpenJourneyPlanner services
 *  Due to its similarities, this might also be viable for TRIAS-based services.
 */
class OpenJourneyPlannerBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QUrl endpoint MEMBER m_endpoint)
    Q_PROPERTY(QString authorization MEMBER m_authorization)

public:
    static inline constexpr const char* type() { return "openJourneyPlanner"; }
    AbstractBackend::Capabilities capabilities() const override;
    bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    bool queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const override;
    bool queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    bool queryJourney(const JourneyRequest &request, JourneyReply * reply, QNetworkAccessManager *nam) const override;

private:
    QNetworkRequest networkRequest() const;

    QUrl m_endpoint;
    QString m_authorization;
};

}

#endif // KPUBLICTRANSPORT_OPENJOURNEYPLANNERBACKEND_H
