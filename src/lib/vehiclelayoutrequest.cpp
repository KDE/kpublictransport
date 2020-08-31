/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "vehiclelayoutrequest.h"
#include "datatypes/locationutil_p.h"
#include "datatypes/datatypes_p.h"
#include "datatypes/stopover.h"
#include "datatypes/journey.h"
#include "datatypes/json_p.h"

#include <QStringList>

using namespace KPublicTransport;

enum { DepartureCacheTimeResolution = 60 }; // in seconds

namespace KPublicTransport {

class VehicleLayoutRequestPrivate : public QSharedData
{
public:
    Stopover departure;
    QStringList backendIds;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(VehicleLayoutRequest)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleLayoutRequest, Stopover, departure, setDeparture)

VehicleLayoutRequest::VehicleLayoutRequest(const Stopover &dep)
    : d(new VehicleLayoutRequestPrivate)
{
    d->departure = dep;
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
