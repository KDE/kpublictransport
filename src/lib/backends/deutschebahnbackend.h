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
public:
    static inline constexpr const char* type() { return "deutschebahn"; }
    bool queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const override;
};

}

#endif
