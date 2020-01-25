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
};
}

LocationRequest::LocationRequest()
    : d(new LocationRequestPrivate)
{
}

LocationRequest::LocationRequest(const Location &locaction)
    : d(new LocationRequestPrivate)
{
    d->location = locaction;
}

LocationRequest::LocationRequest(LocationRequest&&) noexcept = default;
LocationRequest::LocationRequest(const LocationRequest&) = default;
LocationRequest::~LocationRequest() = default;
LocationRequest& LocationRequest::operator=(const LocationRequest&) = default;

bool LocationRequest::isValid() const
{
    return hasCoordinate() || !d->location.name().isEmpty();
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
    return Json::toJson(req);
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
