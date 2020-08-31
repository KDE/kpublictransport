/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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

    /** Returns the key used for caching a location @p loc. */
    QString cacheKey(const Location &loc);
}

}

#endif // KPUBLICTRANSPORT_LOCATIONUTIL_P_H
