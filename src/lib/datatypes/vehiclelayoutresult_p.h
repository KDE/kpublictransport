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

#ifndef KPUBLICTRANSPORT_VEHICLELAYOUTRESULT_H
#define KPUBLICTRANSPORT_VEHICLELAYOUTRESULT_H

#include "departure.h"
#include "platform.h"
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
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Departure, departure, setDeparture)

public:
    VehicleLayoutResult(const Vehicle &vehicle, const Platform &platform, const Departure &dep);

    static VehicleLayoutResult fromJson(const QJsonObject &obj);
    static std::vector<VehicleLayoutResult> fromJson(const QJsonArray &array);
    static QJsonObject toJson(const VehicleLayoutResult &res);
    static QJsonArray toJson(const std::vector<VehicleLayoutResult> &res);
};

}

#endif // KPUBLICTRANSPORT_VEHICLELAYOUTRESULT_H
