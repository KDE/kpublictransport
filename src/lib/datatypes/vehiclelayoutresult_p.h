/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_VEHICLELAYOUTRESULT_H
#define KPUBLICTRANSPORT_VEHICLELAYOUTRESULT_H

#include "platform.h"
#include "stopover.h"
#include "vehicle.h"

namespace KPublicTransport {

class VehicleLayoutResultPrivate;

/** Internal structure used to store vehicle layout query results in the cache.
 *  Since those results consist of multiple parts, we need a simple container type for this
 */
class VehicleLayoutResult
{
    KPUBLICTRANSPORT_GADGET(VehicleLayoutResult)
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Vehicle, vehicle, setVehicle)
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Platform, platform, setPlatform)
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Stopover, departure, setDeparture)

public:
    VehicleLayoutResult(const Vehicle &vehicle, const Platform &platform, const Stopover &dep);

    static VehicleLayoutResult fromJson(const QJsonObject &obj);
    static std::vector<VehicleLayoutResult> fromJson(const QJsonArray &array);
    static QJsonObject toJson(const VehicleLayoutResult &res);
    static QJsonArray toJson(const std::vector<VehicleLayoutResult> &res);
};

}

#endif // KPUBLICTRANSPORT_VEHICLELAYOUTRESULT_H
