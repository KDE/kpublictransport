/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_EFAXMLPARSER_H
#define KPUBLICTRANSPORT_EFAXMLPARSER_H

#include "efaparser.h"

class QPolygonF;

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
    void parseLocationCommon(Location &loc, const ScopedXmlStreamReader &reader) const;
    Location parseItdOdvAssignedStop(const ScopedXmlStreamReader &reader) const;
    Location parseOdvNameElem(ScopedXmlStreamReader &reader) const;

    Stopover parseDmDeparture(ScopedXmlStreamReader &&reader) const;
    void parseTripDeparture(ScopedXmlStreamReader &&reader, JourneySection &section) const;
    void parseTripArrival(ScopedXmlStreamReader &&reader, JourneySection &section) const;

    Stopover parsePartialTripIntermediateStop(ScopedXmlStreamReader &&reader) const;
    std::vector<Stopover> parsePartialTripStopSequence(ScopedXmlStreamReader &&reader) const;

    std::vector<JourneySection> parseTripPartialRoute(ScopedXmlStreamReader &&reader) const;
    Journey parseTripRoute(ScopedXmlStreamReader &&reader) const;
    QStringList parseInfoLink(ScopedXmlStreamReader &&reader) const;
    Path parsePathCoordinates(ScopedXmlStreamReader &&reader) const;
    Path parsePathDescriptionList(ScopedXmlStreamReader &&reader, const QPolygonF &poly) const;

    mutable QHash<QString, Location> m_locations;
};

}

#endif // KPUBLICTRANSPORT_EFAXMLPARSER_H
