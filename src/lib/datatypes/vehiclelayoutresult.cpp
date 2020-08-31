/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "vehiclelayoutresult_p.h"
#include "datatypes_p.h"
#include "json_p.h"

using namespace KPublicTransport;

namespace KPublicTransport {
class VehicleLayoutResultPrivate : public QSharedData
{
public:
    Vehicle vehicle;
    Platform platform;
    Stopover departure;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(VehicleLayoutResult)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleLayoutResult, Vehicle, vehicle, setVehicle)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleLayoutResult, Platform, platform, setPlatform)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleLayoutResult, Stopover, departure, setDeparture)

VehicleLayoutResult::VehicleLayoutResult(const Vehicle &vehicle, const Platform &platform, const Stopover &dep)
    : d(new VehicleLayoutResultPrivate)
{
    d->vehicle = vehicle;
    d->platform = platform;
    d->departure = dep;
}

VehicleLayoutResult VehicleLayoutResult::fromJson(const QJsonObject &obj)
{
    VehicleLayoutResult res;
    res.setVehicle(Vehicle::fromJson(obj.value(QLatin1String("vehicle")).toObject()));
    res.setPlatform(Platform::fromJson(obj.value(QLatin1String("platform")).toObject()));
    res.setDeparture(Stopover::fromJson(obj.value(QLatin1String("departure")).toObject()));
    return res;
}

std::vector<VehicleLayoutResult> VehicleLayoutResult::fromJson(const QJsonArray &array)
{
    return Json::fromJson<VehicleLayoutResult>(array);
}

QJsonObject KPublicTransport::VehicleLayoutResult::toJson(const VehicleLayoutResult &res)
{
    QJsonObject obj;
    obj.insert(QStringLiteral("vehicle"), Vehicle::toJson(res.vehicle()));
    obj.insert(QStringLiteral("platform"), Platform::toJson(res.platform()));
    obj.insert(QStringLiteral("departure"), Stopover::toJson(res.departure()));
    return obj;
}

QJsonArray VehicleLayoutResult::toJson(const std::vector<VehicleLayoutResult> &res)
{
    return Json::toJson(res);
}
