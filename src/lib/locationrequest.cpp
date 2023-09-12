/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "locationrequest.h"
#include "datatypes/datatypes_p.h"
#include "datatypes/json_p.h"
#include "datatypes/locationutil_p.h"

#include <QCryptographicHash>
#include <QDebug>
#include <QMetaEnum>
#include <QSharedData>
#include <QStringList>

#include <cmath>

using namespace KPublicTransport;

namespace KPublicTransport {
class LocationRequestPrivate : public QSharedData {
public:
    Location location;
    QStringList backendIds;
    int maximumDistance = 1000;
    int maximumResults = 10;
    Location::Types types = Location::Stop | Location::RentedVehicleStation;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(LocationRequest)
KPUBLICTRANSPORT_MAKE_PROPERTY(LocationRequest, int, maximumDistance, setMaximumDistance)
KPUBLICTRANSPORT_MAKE_PROPERTY(LocationRequest, int, maximumResults, setMaximumResults)
KPUBLICTRANSPORT_MAKE_PROPERTY(LocationRequest, Location::Types, types, setTypes)

LocationRequest::LocationRequest(const Location &locaction)
    : d(new LocationRequestPrivate)
{
    d->location = locaction;
}

bool LocationRequest::isValid() const
{
    return hasCoordinate() || !d->location.name().isEmpty();
}

Location LocationRequest::location() const
{
    return d->location;
}

void LocationRequest::setLocation(const Location &location)
{
    d.detach();
    d->location = location;
}

float LocationRequest::latitude() const
{
    return d->location.latitude();
}

void LocationRequest::setLatitude(float lat)
{
    d.detach();
    d->location.setLatitude(lat);
}

float LocationRequest::longitude() const
{
    return d->location.longitude();
}

void LocationRequest::setLongitude(float lon)
{
    d.detach();
    d->location.setLongitude(lon);
}

void LocationRequest::setCoordinate(float lat, float lon)
{
    d.detach();
    d->location.setCoordinate(lat, lon);
}

bool LocationRequest::hasCoordinate() const
{
    return d->location.hasCoordinate();
}

QString LocationRequest::name() const
{
    if (d->location.name().isEmpty()) {
        return QString(d->location.locality() + QLatin1Char(' ') + d->location.streetAddress()).trimmed();
    }
    return d->location.name();
}

void LocationRequest::setName(const QString &name)
{
    d.detach();
    d->location.setName(name);
}

QString LocationRequest::cacheKey() const
{
    QCryptographicHash hash(QCryptographicHash::Sha1);
    hash.addData(LocationUtil::cacheKey(d->location).toUtf8());
    const auto me = QMetaEnum::fromType<Location::Types>();
    hash.addData(me.valueToKeys(types()));
    hash.addData(QByteArray::number(maximumDistance()));
    hash.addData(QByteArray::number(maximumResults()));
    return QString::fromUtf8(hash.result().toHex());
}

QJsonObject LocationRequest::toJson(const LocationRequest &req)
{
    auto obj = Json::toJson(req);
    obj.insert(QLatin1String("location"), Location::toJson(req.location()));
    return obj;
}

QStringList LocationRequest::backendIds() const
{
    return d->backendIds;
}

void LocationRequest::setBackendIds(const QStringList &backendIds)
{
    d.detach();
    d->backendIds = backendIds;
}

#include "moc_locationrequest.cpp"
