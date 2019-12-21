/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#include "vehiclelayoutrequest.h"
#include "datatypes/datatypes_p.h"
#include "datatypes/departure.h"
#include "datatypes/json_p.h"

#include <QStringList>

using namespace KPublicTransport;

namespace KPublicTransport {

class VehicleLayoutRequestPrivate : public QSharedData
{
public:
    Departure departure;
    QStringList backendIds;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(VehicleLayoutRequest)

VehicleLayoutRequest::VehicleLayoutRequest(const Departure &dep)
    : d(new VehicleLayoutRequestPrivate)
{
    d->departure = dep;
}

bool VehicleLayoutRequest::isValid() const
{
    return d->departure.scheduledDepartureTime().isValid() && !d->departure.route().line().name().isEmpty();
}

Departure VehicleLayoutRequest::departure() const
{
    return d->departure;
}

QString VehicleLayoutRequest::cacheKey() const
{
    return {}; // TODO
}

QJsonObject VehicleLayoutRequest::toJson(const VehicleLayoutRequest &req)
{
    return Json::toJson(req);
}

QStringList VehicleLayoutRequest::backendIds() const
{
    return d->backendIds;
}

void VehicleLayoutRequest::setBackendIds(const QStringList &backendIds)
{
    d.detach();
    d->backendIds = backendIds;
}

#include "moc_vehiclelayoutrequest.cpp"
