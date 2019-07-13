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

#include "abstractbackend.h"
#include "../journeyrequestcontext_p.h"

#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>

#include <QDebug>
#include <QPolygonF>

using namespace KPublicTransport;

AbstractBackend::AbstractBackend() = default;
AbstractBackend::~AbstractBackend() = default;

QString AbstractBackend::backendId() const
{
    return m_backendId;
}

void AbstractBackend::setBackendId(const QString& id)
{
    m_backendId = id;
}

bool AbstractBackend::isLocationExcluded(const Location &loc) const
{
    if (loc.hasCoordinate() && !m_geoFilter.isEmpty()) {
        return !m_geoFilter.containsPoint({loc.longitude(), loc.latitude()}, Qt::WindingFill);
    }
    return false;
}

bool AbstractBackend::isCoordinateExcluded(float lat, float lon) const
{
    return !m_geoFilter.isEmpty() && !m_geoFilter.containsPoint({lon, lat}, Qt::WindingFill);
}

void AbstractBackend::setGeoFilter(const QPolygonF &poly)
{
    m_geoFilter = poly;
}

void AbstractBackend::init()
{
}

AbstractBackend::Capabilities AbstractBackend::capabilities() const
{
    return NoCapability;
}

bool AbstractBackend::needsLocationQuery(const Location &loc, QueryType type) const
{
    Q_UNUSED(loc);
    Q_UNUSED(type);
    return false;
}

bool AbstractBackend::queryDeparture(const DepartureRequest &request, DepartureReply *reply, QNetworkAccessManager *nam) const
{
    Q_UNUSED(request);
    Q_UNUSED(reply);
    Q_UNUSED(nam);
    return false;
}

bool AbstractBackend::queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    Q_UNUSED(request);
    Q_UNUSED(reply);
    Q_UNUSED(nam);
    return false;
}

bool AbstractBackend::queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    Q_UNUSED(request);
    Q_UNUSED(reply);
    Q_UNUSED(nam);
    return false;
}

QVariant AbstractBackend::journeyContext(const JourneyRequest &request) const
{
    return request.context(this).backendData;
}

void AbstractBackend::setNextJourneyContext(JourneyReply *reply, const QVariant &data) const
{
    reply->setNextContext(this, data);
}

void AbstractBackend::setPreviousJourneyContext(JourneyReply *reply, const QVariant &data) const
{
    reply->setPreviousContext(this, data);
}

void AbstractBackend::addAttributions(Reply *reply, std::vector<Attribution> &&attributions)
{
    reply->addAttributions(std::move(attributions));
}

Attribution AbstractBackend::attribution() const
{
    return m_attribution;
}

void AbstractBackend::setAttribution(const Attribution &attr)
{
    m_attribution = attr;
}
