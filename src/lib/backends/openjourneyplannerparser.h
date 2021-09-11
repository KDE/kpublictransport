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

class QPointF;

namespace KPublicTransport {

class Journey;
class JourneySection;
class Location;
class Path;
class PathSection;
class Route;
class ScopedXmlStreamReader;
class Stopover;

/** Parser for Open Journey Planner / TRIAS responses.
 *  @internal exported for testing only
 */
class KPUBLICTRANSPORT_EXPORT OpenJourneyPlannerParser
{
public:
    std::vector<Location> parseLocationInformationResponse(const QByteArray &responseData);
    std::vector<Stopover> parseStopEventResponse(const QByteArray &responseData);
    std::vector<Journey> parseTripResponse(const QByteArray &responseData);

    bool hasError() const;
    QString errorMessage() const;

    void setLocationIdentifierType(const QString &idType);
    void setUicLocationIdentifierType(const QString &uicIdType);

private:
    std::vector<Location> parseLocationInformationDelivery(ScopedXmlStreamReader &&r);
    Location parseLocationInformationLocationResult(ScopedXmlStreamReader &&r) const;
    Location parseLocationInformationLocation(ScopedXmlStreamReader &&r) const;
    QString parseTextElement(ScopedXmlStreamReader &&r) const;
    QPointF parseGeoPosition(ScopedXmlStreamReader &&r) const;

    std::vector<Stopover> parseStopEventDelivery(ScopedXmlStreamReader &&r);
    void parseResponseContext(ScopedXmlStreamReader &&r);
    void parseResponseContextPlaces(ScopedXmlStreamReader &&r);
    void parseResponseContextSituations(ScopedXmlStreamReader &&r);
    void parseSituation(ScopedXmlStreamReader &&r);

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
    QString parseSituationRef(ScopedXmlStreamReader &&r) const;

    std::vector<Journey> parseTripDelivery(ScopedXmlStreamReader &&r);
    Journey parseTripResult(ScopedXmlStreamReader &&r) const;
    Journey parseTrip(ScopedXmlStreamReader &&r) const;
    JourneySection parseTimedLeg(ScopedXmlStreamReader &&r) const;
    JourneySection parseTransferLeg(ScopedXmlStreamReader &&r) const;
    Path parsePathGuidance(ScopedXmlStreamReader &&r) const;
    PathSection parsePathGuildanceSection(ScopedXmlStreamReader &&r) const;
    PathSection parseTrackSection(ScopedXmlStreamReader &&r) const;

    void parseError(ScopedXmlStreamReader &&r);

    void setLocationIdentifier(Location &loc, const QString &id) const;

    QString m_identifierType;
    QString m_uicIdentifierType;
    QHash<QString, Location> m_contextLocations;
    QHash<QString, QString> m_contextSituations;
    QString m_errorMsg;
};

}

#endif // KPUBLICTRANSPORT_OPENJOURNEYPLANNERPARSER_H
