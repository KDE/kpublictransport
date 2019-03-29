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

        if (reader.name() == QLatin1String("odvNameElem") && reader.attributes().hasAttribute(QLatin1String("stateless"))) {
            Location loc;
            loc.setLatitude(reader.attributes().value(QLatin1String("y")).toDouble());
            loc.setLongitude(reader.attributes().value(QLatin1String("x")).toDouble());
            loc.setIdentifier(m_locationIdentifierType, reader.attributes().value(QLatin1String("stateless")).toString());
            loc.setName(reader.readElementText(QXmlStreamReader::SkipChildElements));
            res.push_back(loc);
            // TODO anything to be done with itdOdvAssignedStops?
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

static Departure parseDmDeparture(QXmlStreamReader &reader)
{
    Departure dep;
    dep.setScheduledPlatform(reader.attributes().value(QLatin1String("platformName")).toString());

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

        if (reader.name() == QLatin1String("itdDeparture")) {
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
            section.setScheduledDepartureTime(parseDateTime(reader));
        } else if (reader.name() == QLatin1String("itdDateTimeTarget")) {
            section.setExpectedDepartureTime(parseDateTime(reader));
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
            section.setScheduledArrivalTime(parseDateTime(reader));
        } else if (reader.name() == QLatin1String("itdDateTimeTarget")) {
            section.setExpectedArrivalTime(parseDateTime(reader));
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
