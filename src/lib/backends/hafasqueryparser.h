/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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

class Journey;
class Location;
class Stopover;

/** Parse for Hafas "query.exe" variant XML responses.
 *  @internal only exported for unit tests.
 */
class KPUBLICTRANSPORT_EXPORT HafasQueryParser : public HafasParser
{
public:
    HafasQueryParser();
    ~HafasQueryParser();

    std::vector<Stopover> parseStationBoardResponse(const QByteArray &data, bool isArrival);
    std::vector<Location> parseGetStopResponse(const QByteArray &data);
    std::vector<Location> parseQueryLocationResponse(const QByteArray &data);
    std::vector<Journey> parseQueryJourneyResponse(const QByteArray &data);
};

}

#endif // KPUBLICTRANSPORT_HAFASQUERYPARSER_H
