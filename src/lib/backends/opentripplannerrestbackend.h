/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENTRIPPLANNERRESTBACKEND_H
#define KPUBLICTRANSPORT_OPENTRIPPLANNERRESTBACKEND_H

#include "abstractbackend.h"

namespace KPublicTransport {

/** Backend for OpenTripPlanner backends using the REST API. */
class OpenTripPlannerRestBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QString endpoint MEMBER m_endpoint)

public:
    OpenTripPlannerRestBackend();
    ~OpenTripPlannerRestBackend();

    static inline constexpr const char* type() { return "otp_rest"; }
    Capabilities capabilities() const override;
    bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    bool queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const override;
    bool queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;

private:
    QString locationToQuery(const Location &loc) const;

    QString m_endpoint;
};

}

#endif // KPUBLICTRANSPORT_OPENTRIPPLANNERRESTBACKEND_H
