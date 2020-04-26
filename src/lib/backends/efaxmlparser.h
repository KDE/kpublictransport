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

class ScopedXmlStreamReader;

/** Parser for full XML responses from EFA services.
 *  @internal only exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT EfaXmlParser : public EfaParser
{
public:
    std::vector<Location> parseStopFinderResponse(const QByteArray &data) const override;
    std::vector<Stopover> parseDmResponse(const QByteArray &data) const override;
    std::vector<Journey> parseTripResponse(const QByteArray &data) const override;

private:
    Location parseItdOdvAssignedStop(const ScopedXmlStreamReader &reader) const;
    Location parseOdvNameElem(ScopedXmlStreamReader &reader) const;

    Stopover parseDmDeparture(ScopedXmlStreamReader &&reader) const;
    void parseTripDeparture(ScopedXmlStreamReader &&reader, JourneySection &section) const;
    void parseTripArrival(ScopedXmlStreamReader &&reader, JourneySection &section) const;

    Stopover parsePartialTripIntermediateStop(ScopedXmlStreamReader &&reader) const;
    std::vector<Stopover> parsePartialTripStopSequence(ScopedXmlStreamReader &&reader) const;

    JourneySection parseTripPartialRoute(ScopedXmlStreamReader &&reader) const;
    Journey parseTripRoute(ScopedXmlStreamReader &&reader) const;
    QStringList parseInfoLink(ScopedXmlStreamReader &&reader) const;

    mutable QHash<QString, Location> m_locations;
};

}

#endif // KPUBLICTRANSPORT_EFAXMLPARSER_H
