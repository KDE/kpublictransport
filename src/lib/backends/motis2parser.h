/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_MOTIS2PARSER_H
#define KPUBLICTRANSPORT_MOTIS2PARSER_H

#include "kpublictransport_export.h"

#include <QUrl>

#include <vector>

class QJsonObject;

namespace KPublicTransport {

class Location;
class Journey;
class Path;
class Route;
class Stopover;

/** Response parsing for Motis v2.
 *  @see https://github.com/motis-project/motis/blob/master/openapi.yaml
 *  @internal exported only for unit tests
 */
class KPUBLICTRANSPORT_EXPORT Motis2Parser
{
public:
    explicit Motis2Parser(QString locIdentifierType);

    [[nodiscard]] std::vector<Journey> parseItineraries(const QByteArray &data);
    [[nodiscard]] Journey parseItinerary(const QJsonObject &itinerary) const;
    [[nodiscard]] std::vector<Stopover> parseStopTimes(const QByteArray &data, bool isArrivals);
    [[nodiscard]] std::vector<Location> parseLocations(const QByteArray &data) const;
    [[nodiscard]] std::vector<Location> parseMapStops(const QByteArray &data) const;
    [[nodiscard]] std::vector<Location> parseRentals(const QByteArray &data) const;

    QString m_previousPageCursor;
    QString m_nextPageCursor;

private:
    [[nodiscard]] Stopover parsePlace(const QJsonObject &obj, bool hasRealTime) const;
    [[nodiscard]] Route parseRoute(const QJsonObject &obj) const;
    void parseCursors(const QJsonObject &obj);

    QString m_locIdentifierType;
};

}

#endif
