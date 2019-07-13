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

#include "efaparser.h"
#include "logging.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>

#include <QDateTime>
#include <QDebug>
#include <QXmlStreamReader>

using namespace KPublicTransport;

void EfaParser::setLocationIdentifierType(const QString& locationIdentifierType)
{
    m_locationIdentifierType = locationIdentifierType;
}

Reply::Error EfaParser::error() const
{
    return m_error;
}

QString EfaParser::errorMessage() const
{
    return m_errorMsg;
}

Location EfaParser::parseItdOdvAssignedStop(QXmlStreamReader &reader) const
{
    Location loc;
    if (reader.attributes().hasAttribute(QLatin1String("x")) && reader.attributes().hasAttribute(QLatin1String("y"))) {
        loc.setLatitude(reader.attributes().value(QLatin1String("y")).toDouble());
        loc.setLongitude(reader.attributes().value(QLatin1String("x")).toDouble());
    }
    loc.setIdentifier(m_locationIdentifierType, reader.attributes().value(QLatin1String("stopID")).toString());
    loc.setName(reader.attributes().value(QLatin1String("nameWithPlace")).toString());
    loc.setLocality(reader.attributes().value(QLatin1String("place")).toString());
    reader.skipCurrentElement();
    return loc;
}

std::vector<Location> EfaParser::parseStopFinderResponse(const QByteArray &data) const
{
    //qDebug().noquote() << data;
    std::vector<Location> res;
    QXmlStreamReader reader(data);
    while (!reader.atEnd()) {
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            reader.readNext();
            continue;
        }

        if (reader.name() == QLatin1String("itdOdvAssignedStop") && reader.attributes().hasAttribute(QLatin1String("stopID"))) {
            res.push_back(parseItdOdvAssignedStop(reader));
        } else {
            reader.readNext();
        }
    }
    return res;
}

static QDateTime parseDateTime(QXmlStreamReader &reader)
{
    QDateTime dt;
    while (!reader.atEnd()) {
        reader.readNext();
        const auto token = reader.tokenType();
        if (token == QXmlStreamReader::EndElement) {
            break;
        }
        if (token != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("itdDate")) {
            QDate d(
                reader.attributes().value(QLatin1String("year")).toInt(),
                reader.attributes().value(QLatin1String("month")).toInt(),
                reader.attributes().value(QLatin1String("day")).toInt());
            dt.setDate(d);
        } else if (reader.name() == QLatin1String("itdTime")) {
            QTime t(
                reader.attributes().value(QLatin1String("hour")).toInt(),
                reader.attributes().value(QLatin1String("minute")).toInt(), 0);
            dt.setTime(t);
        }
        reader.skipCurrentElement();
    }

    return dt;
}

// convert "means of transport" type id to Line::Mode
// so far this seems to be identical in all installations, if that eventually changes
// this needs a similar configuration as Hafas uses
static Line::Mode motTypeToLineMode(int mot)
{
    // comments below are EFA names found in XML responses (usually translated)
    // the mapping isn't necessary 100% obvious everywhere
    switch (mot) {
        case 0: return Line::Train;
        case 1: return Line::RapidTransit; // "Commuter railway"
        case 2: return Line::Metro; // "Subway"
        case 3: return Line::RapidTransit; // "City rail" / "Stadtbahn"
        case 4: return Line::Tramway;
        case 5: return Line::Bus;
        case 6: return Line::Bus; // "Regional bus"
        case 7: return Line::BusRapidTransit; // "Express bus"
        case 8: return Line::Funicular; // "Cable car/Rack railway"
        case 9: return Line::Ferry;
        case 10: return Line::Taxi; // "Taxi on demand"
        case 11: return Line::Unknown; // "Other"
        case 12: return Line::Air; // "Airplane"
        case 13: return Line::LocalTrain;
        case 14:
        case 15:
        case 16:
            return Line::LongDistanceTrain; // "Train (intercity)"
        case 17: return Line::Bus; // "Rail replacement service"
        case 18: return Line::Train; // "Rail shuttle"
        case 19: return Line::Bus; // "Peoples bus" / "Bürgerbus"
    }
    qCDebug(Log) << "Unknown means ot transport: " << mot;
    return Line::Unknown;
}

Departure EfaParser::parseDmDeparture(QXmlStreamReader &reader) const
{
    Departure dep;
    dep.setScheduledPlatform(reader.attributes().value(QLatin1String("platformName")).toString());

    Location stop;
    const auto stopId = reader.attributes().value(QLatin1String("stopID")).toString();
    const auto stopIt = m_locations.find(stopId);
    if (stopIt != m_locations.end()) {
        stop = stopIt.value();
    }

    stop.setName(reader.attributes().value(QLatin1String("stopName")).toString());
    if (reader.attributes().hasAttribute(QLatin1String("x")) && reader.attributes().hasAttribute(QLatin1String("y"))) {
        stop.setLatitude(reader.attributes().value(QLatin1String("y")).toFloat());
        stop.setLongitude(reader.attributes().value(QLatin1String("x")).toFloat());
    }
    stop.setIdentifier(m_locationIdentifierType, stopId);
    dep.setStopPoint(stop);

    while (!reader.atEnd()) {
        reader.readNext();
        const auto token = reader.tokenType();
        if (token == QXmlStreamReader::EndElement) {
            break;
        }
        if (token != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("itdServingLine")) {
            Line line;
            line.setName(reader.attributes().value(QLatin1String("number")).toString());
            line.setMode(motTypeToLineMode(reader.attributes().value(QLatin1String("motType")).toInt()));
            Route route;
            route.setDirection(reader.attributes().value(QLatin1String("direction")).toString());
            route.setLine(line);
            dep.setRoute(route);
            reader.skipCurrentElement();
        } else if (reader.name() == QLatin1String("itdDateTime")) {
            dep.setScheduledDepartureTime(parseDateTime(reader));
        } else {
            reader.skipCurrentElement();
        }
    }

    return dep;
}

std::vector<Departure> EfaParser::parseDmResponse(const QByteArray &data) const
{
    //qDebug().noquote() << data;
    std::vector<Departure> res;
    QXmlStreamReader reader(data);
    while (!reader.atEnd()) {
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            reader.readNext();
            continue;
        }

        if (reader.name() == QLatin1String("itdOdvAssignedStop") && reader.attributes().hasAttribute(QLatin1String("stopID"))) {
            const auto loc = parseItdOdvAssignedStop(reader);
            m_locations[loc.identifier(m_locationIdentifierType)] = loc;
        } else if (reader.name() == QLatin1String("itdDeparture")) {
            res.push_back(parseDmDeparture(reader));
        } else {
            reader.readNext();
        }
    }

    return res;
}

void EfaParser::parseTripDeparture(QXmlStreamReader &reader, JourneySection &section) const
{
    Location loc;
    loc.setName(reader.attributes().value(QLatin1String("name")).toString());
    loc.setLatitude(reader.attributes().value(QLatin1String("y")).toFloat());
    loc.setLongitude(reader.attributes().value(QLatin1String("x")).toFloat());
    loc.setIdentifier(m_locationIdentifierType, reader.attributes().value(QLatin1String("stopID")).toString());

    section.setFrom(loc);
    // ### are those the correct ones? there's also just "platform"
    section.setScheduledDeparturePlatform(reader.attributes().value(QLatin1String("plannedPlatformName")).toString());
    section.setExpectedDeparturePlatform(reader.attributes().value(QLatin1String("platformName")).toString());

    while (!reader.atEnd()) {
        reader.readNext();
        const auto token = reader.tokenType();
        if (token == QXmlStreamReader::EndElement) {
            break;
        }
        if (token != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("itdDateTime")) {
            section.setExpectedDepartureTime(parseDateTime(reader));
        } else if (reader.name() == QLatin1String("itdDateTimeTarget")) {
            section.setScheduledDepartureTime(parseDateTime(reader));
        } else {
            reader.skipCurrentElement();
        }
    }
}

void EfaParser::parseTripArrival(QXmlStreamReader &reader, JourneySection &section) const
{
    Location loc;
    loc.setName(reader.attributes().value(QLatin1String("name")).toString());
    loc.setLatitude(reader.attributes().value(QLatin1String("y")).toFloat());
    loc.setLongitude(reader.attributes().value(QLatin1String("x")).toFloat());
    loc.setIdentifier(m_locationIdentifierType, reader.attributes().value(QLatin1String("stopID")).toString());
    loc.setLocality(reader.attributes().value(QLatin1String("place")).toString());

    section.setTo(loc);
    // ### are those the correct ones? there's also just "platform"
    section.setScheduledArrivalPlatform(reader.attributes().value(QLatin1String("plannedPlatformName")).toString());
    section.setExpectedArrivalPlatform(reader.attributes().value(QLatin1String("platformName")).toString());

    while (!reader.atEnd()) {
        reader.readNext();
        const auto token = reader.tokenType();
        if (token == QXmlStreamReader::EndElement) {
            break;
        }
        if (token != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("itdDateTime")) {
            section.setExpectedArrivalTime(parseDateTime(reader));
        } else if (reader.name() == QLatin1String("itdDateTimeTarget")) {
            section.setScheduledArrivalTime(parseDateTime(reader));
        } else {
            reader.skipCurrentElement();
        }
    }
}

JourneySection EfaParser::parseTripPartialRoute(QXmlStreamReader &reader) const
{
    JourneySection section;

    while (!reader.atEnd()) {
        reader.readNext();
        const auto token = reader.tokenType();
        if (token == QXmlStreamReader::EndElement) {
            break;
        }
        if (token != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("itdPoint")) {
            const auto type = reader.attributes().value(QLatin1String("usage"));
            if (type == QLatin1String("departure")) {
                parseTripDeparture(reader, section);
            } else if (type == QLatin1String("arrival")) {
                parseTripArrival(reader, section);
            }
        } else if (reader.name() == QLatin1String("itdMeansOfTransport")) {
            Line line;
            line.setName(reader.attributes().value(QLatin1String("shortname")).toString());
            line.setModeString(reader.attributes().value(QLatin1String("productName")).toString());
            line.setMode(motTypeToLineMode(reader.attributes().value(QLatin1String("motType")).toInt()));
            Route route;
            route.setDirection(reader.attributes().value(QLatin1String("destination")).toString());
            route.setLine(line);
            section.setRoute(route);
            section.setMode(JourneySection::PublicTransport);
            reader.skipCurrentElement();
        } else {
            reader.skipCurrentElement();
        }
    }

    return section;
}

Journey EfaParser::parseTripRoute(QXmlStreamReader &reader) const
{
    Journey journey;
    std::vector<JourneySection> sections;

    while (!reader.atEnd()) {
        reader.readNext();
        const auto token = reader.tokenType();
        if (token == QXmlStreamReader::EndElement && reader.name() == QLatin1String("itdRoute")) {
            break;
        }
        if (token != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("itdPartialRoute")) {
            sections.push_back(parseTripPartialRoute(reader));
        }
    }

    journey.setSections(std::move(sections));
    return journey;
}

std::vector<Journey> EfaParser::parseTripResponse(const QByteArray &data) const
{
    //qDebug().noquote() << data;
    std::vector<Journey> res;
    QXmlStreamReader reader(data);
    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("itdRoute")) {
            res.push_back(parseTripRoute(reader));
        }
    }
    return res;
}
