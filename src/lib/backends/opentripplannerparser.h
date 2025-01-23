/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H
#define KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H

#include "kpublictransport_export.h"
#include "opentripplannerrequestcontext.h"

#include <KPublicTransport/Feature>
#include <KPublicTransport/Line>
#include <KPublicTransport/Location>
#include <KPublicTransport/RentalVehicle>

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
class Route;
class Stopover;

/** Parser for OTP responses as defined by the GraphQL files in the otp/ subdir.
 *  @internal only exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT OpenTripPlannerParser
{
public:
    explicit OpenTripPlannerParser(const QString &identifierType, const QString &ifoptPrefix = {});
    ~OpenTripPlannerParser();
    void setKnownRentalVehicleNetworks(const QHash<QString, RentalVehicleNetwork> &networks);

    std::vector<Location> parseLocationsByCoordinate(const QJsonObject &obj) const;
    std::vector<Location> parseLocationsByName(const QJsonObject &obj) const;
    std::vector<Location> parseLocationsArray(const QJsonArray &array) const;
    std::vector<Location> parseGeocodeResult(const QJsonArray &array) const;
    std::vector<Stopover> parseDepartures(const QJsonObject &obj) const;
    std::vector<Stopover> parseDeparturesArray(const QJsonArray &array) const;
    std::vector<Journey> parseJourneys(const QJsonObject &obj);
    [[nodiscard]] JourneySection parseTrip(const QJsonObject &obj) const;

    OpenTripPlannerRequestContext m_nextJourneyContext;
    OpenTripPlannerRequestContext m_prevJourneyContext;
private:
    QVariant parseRentalVehicleData(const QJsonObject &obj) const;
    /// @return @c false for Location objects that should be discarded entirely
    bool parseLocationFragment(const QJsonObject &obj, Location &loc) const;
    Location parseLocation(const QJsonObject &obj) const;
    void parseAlerts(const QJsonArray &alertsArray) const;

    struct RouteData {
        Route route;
        std::vector<Feature> features;
    };
    RouteData parseLine(const QJsonObject &obj) const;
    RouteData parseRoute(const QJsonObject &obj) const;
    RouteData parseInlineRoute(const QJsonObject &obj) const;
    RouteData detectAndParseRoute(const QJsonObject &obj) const;
    Stopover parseDeparture(const QJsonObject &obj) const;
    void parseDeparturesForStop(const QJsonObject &obj, std::vector<Stopover> &deps) const;
    JourneySection parseJourneySection(const QJsonObject &obj) const;
    Journey parseJourney(const QJsonObject &obj) const;

    QString m_identifierType;
    QString m_ifoptPrefix;
    QHash<QString, RentalVehicleNetwork> m_rentalVehicleNetworks;
    mutable QStringList m_alerts;
};

}

#endif // KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H
