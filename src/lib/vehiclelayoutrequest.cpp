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
#include "datatypes/locationutil_p.h"
#include "datatypes/datatypes_p.h"
#include "datatypes/departure.h"
#include "datatypes/journey.h"
#include "datatypes/json_p.h"

#include <QStringList>

using namespace KPublicTransport;

enum { DepartureCacheTimeResolution = 60 }; // in seconds

namespace KPublicTransport {

class VehicleLayoutRequestPrivate : public QSharedData
{
public:
    Departure departure;
    QStringList backendIds;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(VehicleLayoutRequest)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleLayoutRequest, KPublicTransport::Departure, departure, setDeparture)

VehicleLayoutRequest::VehicleLayoutRequest(const Departure &dep)
    : d(new VehicleLayoutRequestPrivate)
{
    d->departure = dep;
}

VehicleLayoutRequest::VehicleLayoutRequest(const JourneySection &section)
    : d(new VehicleLayoutRequestPrivate)
{
    d->departure.setStopPoint(section.from());
    d->departure.setRoute(section.route());
    d->departure.setScheduledDepartureTime(section.scheduledDepartureTime());
    d->departure.setExpectedDepartureTime(section.expectedDepartureTime());
    d->departure.setScheduledPlatform(section.scheduledDeparturePlatform());
    d->departure.setExpectedPlatform(section.expectedDeparturePlatform());
}

VehicleLayoutRequest VehicleLayoutRequest::fromJourneySection(const JourneySection &section) const
{
    return VehicleLayoutRequest(section);
}

bool VehicleLayoutRequest::isValid() const
{
    return d->departure.scheduledDepartureTime().isValid() && !d->departure.route().line().name().isEmpty();
}

QString VehicleLayoutRequest::cacheKey() const
{
    return QString::number(d->departure.scheduledDepartureTime().toSecsSinceEpoch() / DepartureCacheTimeResolution) + QLatin1Char('_')
        + LocationUtil::cacheKey(d->departure.stopPoint());
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
