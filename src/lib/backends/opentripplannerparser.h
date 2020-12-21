/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H
#define KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Location>

#include <QHash>
#include <QString>
#include <QStringList>

#include <vector>

class QJsonArray;
class QJsonObject;

namespace KPublicTransport {

class Journey;
class JourneySection;
class Line;
class RentalVehicleNetwork;
class Route;
class Stopover;

/** Parser for OTP responses as defined by the GraphQL files in the otp/ subdir.
 *  @internal only exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT OpenTripPlannerParser
{
public:
    explicit OpenTripPlannerParser(const QString &identifierType);
    ~OpenTripPlannerParser();
    void setKnownRentalVehicleNetworks(const QHash<QString, RentalVehicleNetwork> &networks);

    std::vector<Location> parseLocationsByCoordinate(const QJsonObject &obj) const;
    std::vector<Location> parseLocationsByName(const QJsonObject &obj) const;
    std::vector<Location> parseLocationsArray(const QJsonArray &array) const;
    std::vector<Location> parseGeocodeResult(const QJsonArray &array) const;
    std::vector<Stopover> parseDepartures(const QJsonObject &obj) const;
    std::vector<Stopover> parseDeparturesArray(const QJsonArray &array) const;
    std::vector<Journey> parseJourneys(const QJsonObject &obj) const;

private:
    QVariant parseRentalVehicleData(const QJsonObject &obj) const;
    /// @return @c false for Location objects that should be discarded entirely
    bool parseLocationFragment(const QJsonObject &obj, Location &loc) const;
    Location parseLocation(const QJsonObject &obj) const;
    void parseAlerts(const QJsonArray &alertsArray) const;
    Line parseLine(const QJsonObject &obj) const;
    Route parseRoute(const QJsonObject &obj) const;
    Route parseInlineRoute(const QJsonObject &obj) const;
    Route detectAndParseRoute(const QJsonObject &obj) const;
    Stopover parseDeparture(const QJsonObject &obj) const;
    void parseDeparturesForStop(const QJsonObject &obj, std::vector<Stopover> &deps) const;
    JourneySection parseJourneySection(const QJsonObject &obj) const;
    Journey parseJourney(const QJsonObject &obj) const;

    QString m_identifierType;
    QHash<QString, RentalVehicleNetwork> m_rentalVehicleNetworks;
    mutable QStringList m_alerts;
};

}

#endif // KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H
