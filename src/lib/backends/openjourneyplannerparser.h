/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENJOURNEYPLANNERPARSER_H
#define KPUBLICTRANSPORT_OPENJOURNEYPLANNERPARSER_H

#include "kpublictransport_export.h"

#include <vector>

class QByteArray;
class QString;

namespace KPublicTransport {

class Journey;
class Location;
class Route;
class ScopedXmlStreamReader;
class Stopover;

/** Parser for Open Journey Planner / TRIAS responses.
 *  @internal exported for testing only
 */
class KPUBLICTRANSPORT_EXPORT OpenJourneyPlannerParser
{
public:
    std::vector<Location> parseLocationInformationResponse(const QByteArray &responseData) const;
    std::vector<Stopover> parseStopEventResponse(const QByteArray &responseData) const;
    std::vector<Journey> parseTripResponse(const QByteArray &responseData) const;

private:
    std::vector<Location> parseLocationInformationDelivery(ScopedXmlStreamReader &&r) const;
    Location parseLocationInformationLocationOuter(ScopedXmlStreamReader &&r) const;
    Location parseLocationInformationLocationInner(ScopedXmlStreamReader &&r) const;
    QString parseTextElement(ScopedXmlStreamReader &&r) const;

    std::vector<Stopover> parseStopEventDelivery(ScopedXmlStreamReader &&r) const;
    void parseResponseContext(ScopedXmlStreamReader &&r) const;
    Stopover parseStopEventResult(ScopedXmlStreamReader &&r) const;
    Stopover parseStopEvent(ScopedXmlStreamReader &&r) const;
    void parseCallAtStop(ScopedXmlStreamReader &&r, Stopover &stop) const;
    void parseService(ScopedXmlStreamReader &&r, Route &route) const;
};

}

#endif // KPUBLICTRANSPORT_OPENJOURNEYPLANNERPARSER_H
