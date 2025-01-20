/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_DEUTSCHEBAHNPARSER_H
#define KPUBLICTRANSPORT_DEUTSCHEBAHNPARSER_H

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

class QJsonArray;

namespace KPublicTransport {

class HafasMgateParser;

/** Deutsche Bahn Hafas proxy response parser.
 *  @internal exported for unit tests only
 */
class DeutscheBahnParser
{
public:
    [[nodiscard]] static std::vector<Location> parseLocations(const QByteArray &data, const HafasMgateParser &parser);
    [[nodiscard]] static std::vector<Stopover> parseStopovers(const QJsonArray &stopsArray, bool isDeparture, const HafasMgateParser &parser);
    [[nodiscard]] static std::vector<Journey> parseJourneys(const QJsonArray &journeysArray, const HafasMgateParser &parser);
    [[nodiscard]] static JourneySection parseTrip(const QJsonObject &sectionObj, const HafasMgateParser &parser);
};

}

#endif
