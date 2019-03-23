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

#ifndef KPUBLICTRANSPORT_HAFASQUERYPARSER_H
#define KPUBLICTRANSPORT_HAFASQUERYPARSER_H

#include "kpublictransport_export.h"
#include "hafasparser.h"

#include <KPublicTransport/Line>

#include <QString>

#include <unordered_map>
#include <vector>

class QByteArray;

namespace KPublicTransport {

class Departure;
class Journey;
class Location;

/** Parse for Hafas "query.exe" variant XML responses.
 *  @internal only exported for unit tests.
 */
class KPUBLICTRANSPORT_EXPORT HafasQueryParser : public HafasParser
{
public:
    HafasQueryParser(const std::unordered_map<int, Line::Mode> &modeMap);
    void setLocationIdentifierType(const QString &idType);

    std::vector<Departure> parseStationBoardResponse(const QByteArray &data, bool isArrival);
    std::vector<Location> parseGetStopResponse(const QByteArray &data);
    std::vector<Journey> parseQueryResponse(const QByteArray &data);

private:
    QString m_locationIdentifierType;
    const std::unordered_map<int, Line::Mode> &m_lineModeMap;
};

}

#endif // KPUBLICTRANSPORT_HAFASQUERYPARSER_H
