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

#ifndef KPUBLICTRANSPORT_EFAXMLPARSER_H
#define KPUBLICTRANSPORT_EFAXMLPARSER_H

#include "efaparser.h"

namespace KPublicTransport {

/** Parser for full XML responses from EFA services.
 *  @internal only exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT EfaXmlParser : public EfaParser
{
public:
    std::vector<Location> parseStopFinderResponse(const QByteArray &data) const;
    std::vector<Departure> parseDmResponse(const QByteArray &data) const;
    std::vector<Journey> parseTripResponse(const QByteArray &data) const;

private:
    Location parseItdOdvAssignedStop(QXmlStreamReader &reader) const;
    Location parseOdvNameElem(QXmlStreamReader &reader) const;

    Departure parseDmDeparture(QXmlStreamReader &reader) const;
    void parseTripDeparture(QXmlStreamReader &reader, JourneySection &section) const;
    void parseTripArrival(QXmlStreamReader &reader, JourneySection &section) const;
    Departure parseCompactDp(QXmlStreamReader &reader) const;

    JourneySection parseTripPartialRoute(QXmlStreamReader &reader) const;
    Journey parseTripRoute(QXmlStreamReader &reader) const;
    QStringList parseInfoLink(QXmlStreamReader &reader) const;

    mutable QHash<QString, Location> m_locations;
};

}

#endif // KPUBLICTRANSPORT_EFAXMLPARSER_H
