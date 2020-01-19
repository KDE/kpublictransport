/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H
#define KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H

#include "kpublictransport_export.h"

#include <QString>
#include <QStringList>

#include <vector>

class QJsonArray;
class QJsonObject;

namespace KPublicTransport {

class Departure;
class Journey;
class JourneySection;
class Line;
class Location;
class Route;

/** Parser for OTP responses as defined by the GraphQL files in the otp/ subdir.
 *  @internal only exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT OpenTripPlannerParser
{
public:
    explicit OpenTripPlannerParser(const QString &identifierType);
    ~OpenTripPlannerParser();

    std::vector<Location> parseLocationsByCoordinate(const QJsonObject &obj) const;
    std::vector<Location> parseLocationsByName(const QJsonObject &obj) const;
    std::vector<Location> parseLocationsArray(const QJsonArray &array) const;
    std::vector<Departure> parseDepartures(const QJsonObject &obj) const;
    std::vector<Departure> parseDeparturesArray(const QJsonArray &array) const;
    std::vector<Journey> parseJourneys(const QJsonObject &obj) const;

private:
    Location parseLocation(const QJsonObject &obj) const;
    void parseAlerts(const QJsonArray &alertsArray) const;
    Line parseLine(const QJsonObject &obj) const;
    Route parseRoute(const QJsonObject &obj) const;
    Route parseInlineRoute(const QJsonObject &obj) const;
    Departure parseDeparture(const QJsonObject &obj) const;
    void parseDeparturesForStop(const QJsonObject &obj, std::vector<Departure> &deps) const;
    JourneySection parseJourneySection(const QJsonObject &obj) const;
    Journey parseJourney(const QJsonObject &obj) const;

    QString m_identifierType;
    mutable QStringList m_alerts;
};

}

#endif // KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H
