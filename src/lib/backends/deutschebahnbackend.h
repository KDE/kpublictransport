/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_DEUTSCHEBAHNBACKEND_H
#define KPUBLICTRANSPORT_DEUTSCHEBAHNBACKEND_H

#include "hafasmgatebackend.h"

namespace KPublicTransport {

/** Backend for DB-specific APIs. */
class DeutscheBahnBackend : public HafasMgateBackend
{
    Q_GADGET
    Q_PROPERTY(bool useHafasMgate MEMBER m_bypassDbApi)
public:
    [[nodiscard]] static inline constexpr const char* type() { return "deutschebahn"; }

    [[nodiscard]] Capabilities capabilities() const override;
    [[nodiscard]] bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    [[nodiscard]] bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryTrip(const TripRequest &request, TripReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const override;

private:
    [[nodiscard]] QNetworkRequest makeHafasProxyRequest(const QUrl &url) const;
    [[nodiscard]] QString hafasIdentifier() const;

    bool m_bypassDbApi = true;
};

}

#endif
