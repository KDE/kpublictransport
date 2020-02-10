/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_HAFASMGATEPARSER_H
#define KPUBLICTRANSPORT_HAFASMGATEPARSER_H

#include "kpublictransport_export.h"
#include "hafasparser.h"

#include <KPublicTransport/Disruption>
#include <KPublicTransport/Line>
#include <KPublicTransport/Reply>

#include <unordered_map>
#include <vector>

#include <QColor>

class QByteArray;
class QJsonValue;

namespace KPublicTransport {

class Departure;
class Journey;
class Location;

struct Ico {
    QColor bg;
    QColor fg;
};

/** Hafas response parser.
 *  @internal exported for unit tests only
 */
class KPUBLICTRANSPORT_EXPORT HafasMgateParser : public HafasParser
{
public:
    HafasMgateParser();
    ~HafasMgateParser();

    std::vector<Departure> parseDepartures(const QByteArray &data) const;
    std::vector<Location> parseLocations(const QByteArray &data) const;
    std::vector<Journey> parseJourneys(const QByteArray &data) const;

    static QDateTime parseDateTime(const QString &date, const QJsonValue &time, const QJsonValue &tzOffset);

private:
    Q_DISABLE_COPY(HafasMgateParser)
    std::vector<Departure> parseStationBoardResponse(const QJsonObject &obj) const;
    std::vector<Line> parseLines(const QJsonArray &prodL, const std::vector<Ico> &icos) const;
    std::vector<Location> parseLocations(const QJsonArray &locL) const;
    std::vector<Journey> parseTripSearch(const QJsonObject &obj) const;
    bool parseError(const QJsonObject &obj) const;
};

}

#endif // KPUBLICTRANSPORT_HAFASMGATEPARSER_H
