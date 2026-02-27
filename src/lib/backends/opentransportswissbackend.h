/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENTRANSPORTSWISSBACKEND_H
#define KPUBLICTRANSPORT_OPENTRANSPORTSWISSBACKEND_H

#include "openjourneyplannerbackend.h"

namespace KPublicTransport {

/** OpenTransportData Swiss train formation support, on top of OJP 2.0. */
class OpenTransportSwissBackend : public OpenJourneyPlannerBackend
{
    Q_GADGET
    Q_PROPERTY(QString formationAuthorization MEMBER m_formationAuthorization)
    Q_PROPERTY(QJsonObject formationOperatorMap MEMBER m_formationOperatorMap)

public:
    static constexpr const char* type() { return "opentransportswiss"; }
    bool queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const override;

private:
    QString m_formationAuthorization;
    QJsonObject m_formationOperatorMap;
};

}

#endif
