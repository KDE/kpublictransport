/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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

class Journey;
class Location;
class Stopover;

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

    std::vector<Stopover> parseDepartures(const QByteArray &data) const;
    std::vector<Location> parseLocations(const QByteArray &data) const;
    std::vector<Journey> parseJourneys(const QByteArray &data) const;

    static QDateTime parseDateTime(const QString &date, const QJsonValue &time, const QJsonValue &tzOffset);

private:
    Q_DISABLE_COPY(HafasMgateParser)
    std::vector<Stopover> parseStationBoardResponse(const QJsonObject &obj) const;
    std::vector<Line> parseLines(const QJsonArray &prodL, const std::vector<Ico> &icos) const;
    std::vector<Location> parseLocations(const QJsonArray &locL) const;
    std::vector<Journey> parseTripSearch(const QJsonObject &obj) const;
    bool parseError(const QJsonObject &obj) const;
};

}

#endif // KPUBLICTRANSPORT_HAFASMGATEPARSER_H
