/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#include "locationrequest.h"
#include "datatypes/datatypes_p.h"
#include "datatypes/json_p.h"
#include "datatypes/location.h"
#include "datatypes/locationutil_p.h"

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
};
}

KPUBLICTRANSPORT_MAKE_GADGET(LocationRequest)
KPUBLICTRANSPORT_MAKE_PROPERTY(LocationRequest, int, maximumDistance, setMaximumDistance)
KPUBLICTRANSPORT_MAKE_PROPERTY(LocationRequest, int, maximumResults, setMaximumResults)

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
    return LocationUtil::cacheKey(d->location);
}

QJsonObject LocationRequest::toJson(const LocationRequest &req)
{
    auto obj = Json::toJson(req);
    obj.insert(QStringLiteral("location"), Location::toJson(req.location()));
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
