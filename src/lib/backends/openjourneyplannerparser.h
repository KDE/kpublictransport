/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENJOURNEYPLANNERPARSER_H
#define KPUBLICTRANSPORT_OPENJOURNEYPLANNERPARSER_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Line>

#include <QDateTime>
#include <QHash>
#include <QString>

#include <vector>

namespace KPublicTransport {

class Journey;
class JourneySection;
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
    std::vector<Stopover> parseStopEventResponse(const QByteArray &responseData);
    std::vector<Journey> parseTripResponse(const QByteArray &responseData);

private:
    std::vector<Location> parseLocationInformationDelivery(ScopedXmlStreamReader &&r) const;
    Location parseLocationInformationLocationOuter(ScopedXmlStreamReader &&r) const;
    Location parseLocationInformationLocationInner(ScopedXmlStreamReader &&r) const;
    QString parseTextElement(ScopedXmlStreamReader &&r) const;

    std::vector<Stopover> parseStopEventDelivery(ScopedXmlStreamReader &&r);
    void parseResponseContext(ScopedXmlStreamReader &&r);
    void parseResponseContextPlaces(ScopedXmlStreamReader &&r);
    Stopover parseStopEventResult(ScopedXmlStreamReader &&r) const;
    Stopover parseStopEvent(ScopedXmlStreamReader &&r) const;
    void parseCallAtStop(ScopedXmlStreamReader &&r, Stopover &stop) const;
    void parseService(ScopedXmlStreamReader &&r, Route &route, QStringList &attributes) const;
    struct TimePair {
        QDateTime scheduledTime;
        QDateTime expectedTime;
    };
    TimePair parseTime(ScopedXmlStreamReader &&r) const;
    Line::Mode parseMode(ScopedXmlStreamReader &&r) const;

    std::vector<Journey> parseTripDelivery(ScopedXmlStreamReader &&r);
    Journey parseTripResult(ScopedXmlStreamReader &&r) const;
    Journey parseTrip(ScopedXmlStreamReader &&r) const;
    JourneySection parseTimedLeg(ScopedXmlStreamReader &&r) const;
    JourneySection parseTransferLeg(ScopedXmlStreamReader &&r) const;

    QString m_identifierType = QStringLiteral("uic"); // TODO
    QHash<QString, Location> m_contextLocations;
};

}

#endif // KPUBLICTRANSPORT_OPENJOURNEYPLANNERPARSER_H
