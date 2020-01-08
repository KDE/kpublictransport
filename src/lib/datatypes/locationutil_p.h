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

#ifndef KPUBLICTRANSPORT_LOCATIONUTIL_P_H
#define KPUBLICTRANSPORT_LOCATIONUTIL_P_H

class QString;

namespace KPublicTransport {

class Location;
class LocationRequest;

/** Internal methods around Location. */
namespace LocationUtil
{
    /** Request specific sorting/comparison for replies/models. */
    bool sortLessThan(const LocationRequest &request, const Location &lhs, const Location &rhs);

    /** Returns the key used for caching a location with the given name and coordinates. */
    QString cacheKey(const QString &name, float lat, float lon);
}

}

#endif // KPUBLICTRANSPORT_LOCATIONUTIL_P_H
