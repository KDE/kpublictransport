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

enum { StopoverCacheTimeResolution = 60 }; // in seconds

namespace KPublicTransport {

class VehicleLayoutRequestPrivate : public QSharedData
{
public:
    Stopover stopover;
    QStringList backendIds;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(VehicleLayoutRequest)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleLayoutRequest, Stopover, stopover, setStopover)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleLayoutRequest, QStringList, backendIds, setBackendIds)

VehicleLayoutRequest::VehicleLayoutRequest(const Stopover &stopover)
    : d(new VehicleLayoutRequestPrivate)
{
    d->stopover = stopover;
}

bool VehicleLayoutRequest::isValid() const
{
    return (d->stopover.scheduledDepartureTime().isValid() || d->stopover.scheduledArrivalTime().isValid()) && !d->stopover.route().line().name().isEmpty();
}

QString VehicleLayoutRequest::cacheKey() const
{
    return QString::number(d->stopover.scheduledDepartureTime().toSecsSinceEpoch() / StopoverCacheTimeResolution) + QLatin1Char('_')
        + LocationUtil::cacheKey(d->stopover.stopPoint());
}

QJsonObject VehicleLayoutRequest::toJson(const VehicleLayoutRequest &req)
{
    auto obj = Json::toJson(req);
    obj.insert(QLatin1String("stopover"), Stopover::toJson(req.stopover()));
    return obj;
}

#include "moc_vehiclelayoutrequest.cpp"
