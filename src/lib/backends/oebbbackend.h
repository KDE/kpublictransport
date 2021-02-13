/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OEBBBACKEND_H
#define KPUBLICTRANSPORT_OEBBBACKEND_H

#include "hafasmgatebackend.h"

namespace KPublicTransport {

/** ÖBB-specific backend, adding ÖBB vehicle layout support on top of their standard Hafas. */
class OebbBackend : public HafasMgateBackend
{
public:
    static inline constexpr const char* type() { return "oebb"; }
    bool queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const override;
};

}

#endif // KPUBLICTRANSPORT_OEBBBACKEND_H
