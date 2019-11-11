/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#include "efacompactparser.h"
#include "logging.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>

#include <QDateTime>
#include <QDebug>
#include <QXmlStreamReader>

using namespace KPublicTransport;

static void parseCompactCoordinate(QXmlStreamReader &reader, Location &loc)
{
    const auto coords = reader.readElementText().split(QLatin1Char(','));
    if (coords.size() == 2) {
        loc.setLatitude(coords[1].toFloat());
        loc.setLongitude(coords[0].toFloat());
    }
}

Location EfaCompactParser::parseCompactSf(QXmlStreamReader &reader) const
{
    Location loc;
    int depth = 1;
    while (!reader.atEnd() && depth >= 1) {
        reader.readNext();
        if (reader.tokenType() == QXmlStreamReader::EndElement) {
            --depth;
            continue;
        }
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("n")) {
            loc.setName(reader.readElementText());
        } else if (reader.name() == QLatin1String("id")) {
            loc.setIdentifier(m_locationIdentifierType, reader.readElementText());
        } else if (reader.name() == QLatin1String("ty")) {
            if (reader.readElementText() != QLatin1String("stop")) {
                reader.skipCurrentElement();
                return {};
            }
        } else if (reader.name() == QLatin1String("r")) {
            ++depth;
        } else if (reader.name() == QLatin1String("c")) {
            parseCompactCoordinate(reader, loc);
        } else if (reader.name() == QLatin1String("pc")) {
            loc.setLocality(reader.readElementText());
        } else {
            reader.skipCurrentElement();
        }
    }

    return loc;
}

std::vector<Location> EfaCompactParser::parseStopFinderResponse(const QByteArray &data) const
{
    std::vector<Location> res;
    QXmlStreamReader reader(data);
    while (!reader.atEnd()) {
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            reader.readNext();
            continue;
        }

        if (reader.name() == QLatin1String("p")) {
            const auto l = parseCompactSf(reader);
            if (!l.isEmpty()) {
                res.push_back(l);
            }
        } else {
            reader.readNext();
        }
    }
    return res;
}

static std::pair<QDateTime, QDateTime> parseCompactTimePair(QXmlStreamReader &reader)
{
    QDateTime scheduledDt, expectedDt;

    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.tokenType() == QXmlStreamReader::EndElement) {
            break;
        }
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("da")) {
            scheduledDt.setDate(QDate::fromString(reader.readElementText(), QStringLiteral("yyyyMMdd")));
        } else if (reader.name() == QLatin1String("t")) {
            scheduledDt.setTime(QTime::fromString(reader.readElementText(), QStringLiteral("hhmm")));
        } else if (reader.name() == QLatin1String("rda")) {
            expectedDt.setDate(QDate::fromString(reader.readElementText(), QStringLiteral("yyyyMMdd")));
        } else if (reader.name() == QLatin1String("rt")) {
            expectedDt.setTime(QTime::fromString(reader.readElementText(), QStringLiteral("hhmm")));
        } else {
            reader.skipCurrentElement();
        }
    }

    return std::make_pair(scheduledDt, expectedDt);
}

Route EfaCompactParser::parseCompactRoute(QXmlStreamReader &reader) const
{
    Route route;
    Line line;

    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.tokenType() == QXmlStreamReader::EndElement) {
            break;
        }
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("des")) {
            route.setDirection(reader.readElementText());
        } else if (reader.name() == QLatin1String("nu")) {
            line.setName(reader.readElementText());
        } else if (reader.name() == QLatin1String("n")) {
            line.setModeString(reader.readElementText());
        } else if (reader.name() == QLatin1String("ty")) {
            line.setMode(motTypeToLineMode(reader.readElementText().toInt()));
        } else {
            reader.skipCurrentElement();
        }
    }

    route.setLine(line);
    return route;
}

Departure EfaCompactParser::parseCompactDp(QXmlStreamReader &reader) const
{
    Departure dep;
    Location loc;
    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.tokenType() == QXmlStreamReader::EndElement) {
            break;
        }
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("n")) {
            loc.setName(reader.readElementText());
        } else if (reader.name() == QLatin1String("rts")) {
            const auto rts = reader.readElementText();
            if (rts == QLatin1String("TRIP_CANCELLED")) {
                dep.setDisruptionEffect(Disruption::NoService);
            }
        } else if (reader.name() == QLatin1String("st")) {
            const auto st = parseCompactTimePair(reader);
            dep.setScheduledDepartureTime(st.first);
            dep.setExpectedDepartureTime(st.second);
        } else if (reader.name() == QLatin1String("m")) {
            dep.setRoute(parseCompactRoute(reader));
        }
        // TODO <r><id></id><pl></pl></r>
        else if (reader.name() == QLatin1String("c")) {
            parseCompactCoordinate(reader, loc);
        } else if (reader.name() == QLatin1String("ns")) {
            // TODO parse notes list
            reader.skipCurrentElement();
        } else {
            reader.skipCurrentElement();
        }
    }

    dep.setStopPoint(loc);
    return dep;
}

std::vector<Departure> EfaCompactParser::parseDmResponse(const QByteArray &data) const
{
    std::vector<Departure> res;
    QXmlStreamReader reader(data);
    while (!reader.atEnd()) {
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            reader.readNext();
            continue;
        }

        if (reader.name() == QLatin1String("dp")) {
            res.push_back(parseCompactDp(reader));
        } else {
            reader.readNext();
        }
    }

    return res;
}

std::vector<Journey> EfaCompactParser::parseTripResponse(const QByteArray &data) const
{
    //qDebug().noquote() << data;
    std::vector<Journey> res;
    QXmlStreamReader reader(data);
    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            continue;
        }

        // TODO
    }
    return res;
}
