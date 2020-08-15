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
