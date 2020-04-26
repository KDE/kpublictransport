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

#include "efaxmlparser.h"
#include "logging.h"
#include "scopedxmlstreamreader.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>

#include <QDateTime>
#include <QDebug>
#include <QXmlStreamReader>

using namespace KPublicTransport;

Location EfaXmlParser::parseItdOdvAssignedStop(const ScopedXmlStreamReader &reader) const
{
    Location loc;
    if (reader.attributes().hasAttribute(QLatin1String("x")) && reader.attributes().hasAttribute(QLatin1String("y"))) {
        loc.setLatitude(reader.attributes().value(QLatin1String("y")).toDouble());
        loc.setLongitude(reader.attributes().value(QLatin1String("x")).toDouble());
    }
    loc.setIdentifier(m_locationIdentifierType, reader.attributes().value(QLatin1String("stopID")).toString());
    loc.setName(reader.attributes().value(QLatin1String("nameWithPlace")).toString());
    loc.setLocality(reader.attributes().value(QLatin1String("place")).toString());
    return loc;
}

Location EfaXmlParser::parseOdvNameElem(ScopedXmlStreamReader &reader) const
{
    Location loc;
    if (reader.attributes().hasAttribute(QLatin1String("x")) && reader.attributes().hasAttribute(QLatin1String("y"))) {
        loc.setLatitude(reader.attributes().value(QLatin1String("y")).toDouble());
        loc.setLongitude(reader.attributes().value(QLatin1String("x")).toDouble());
    }
    const auto id = reader.attributes().value(QLatin1String("stopID")).toString();
    if (!id.isEmpty()) {
        loc.setIdentifier(m_locationIdentifierType, id);
    } else {
        loc.setIdentifier(m_locationIdentifierType, reader.attributes().value(QLatin1String("stateless")).toString());
    }
    loc.setName(reader.readElementText(QXmlStreamReader::SkipChildElements));
    return loc;
}

std::vector<Location> EfaXmlParser::parseStopFinderResponse(const QByteArray &data) const
{
    std::vector<Location> res;
    QXmlStreamReader xsr(data);
    ScopedXmlStreamReader reader(xsr);
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("itdOdvAssignedStop") && reader.attributes().hasAttribute(QLatin1String("stopID"))) {
            res.push_back(parseItdOdvAssignedStop(reader));
        } else if (reader.name() == QLatin1String("odvNameElem")) {
            if (reader.attributes().hasAttribute(QLatin1String("stopID"))) {
                res.push_back(parseOdvNameElem(reader));
            } else if (reader.attributes().value(QLatin1String("anyType")) == QLatin1String("stop")
                && reader.attributes().hasAttribute(QLatin1String("stateless")))
            {
                res.push_back(parseOdvNameElem(reader));
            }
        }
    }
    return res;
}

static QDateTime parseDateTime(ScopedXmlStreamReader &&reader)
{
    QDateTime dt;
    while (reader.readNextSibling()) {
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
    }

    return dt;
}

Departure EfaXmlParser::parseDmDeparture(ScopedXmlStreamReader &&reader) const
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

    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdServingLine")) {
            Line line;
            line.setName(reader.attributes().value(QLatin1String("number")).toString());
            line.setMode(motTypeToLineMode(reader.attributes().value(QLatin1String("motType")).toInt()));
            Route route;
            route.setDirection(reader.attributes().value(QLatin1String("direction")).toString());
            route.setLine(line);
            dep.setRoute(route);
        } else if (reader.name() == QLatin1String("itdDateTime")) {
            dep.setScheduledDepartureTime(parseDateTime(reader.subReader()));
        } else if (reader.name() == QLatin1String("itdInfoLinkList")) {
            dep.addNotes(parseInfoLink(reader.subReader()));
        }
    }

    return dep;
}

std::vector<Departure> EfaXmlParser::parseDmResponse(const QByteArray &data) const
{
    std::vector<Departure> res;
    QXmlStreamReader xsr(data);
    ScopedXmlStreamReader reader(xsr);
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("itdOdvAssignedStop") && reader.attributes().hasAttribute(QLatin1String("stopID"))) {
            const auto loc = parseItdOdvAssignedStop(reader);
            m_locations[loc.identifier(m_locationIdentifierType)] = loc;
        } else if (reader.name() == QLatin1String("itdDeparture")) {
            res.push_back(parseDmDeparture(reader.subReader()));
        }
    }

    return res;
}

void EfaXmlParser::parseTripDeparture(ScopedXmlStreamReader &&reader, JourneySection &section) const
{
    Location loc;
    loc.setName(reader.attributes().value(QLatin1String("name")).toString());
    loc.setLatitude(reader.attributes().value(QLatin1String("y")).toFloat());
    loc.setLongitude(reader.attributes().value(QLatin1String("x")).toFloat());
    loc.setIdentifier(m_locationIdentifierType, reader.attributes().value(QLatin1String("stopID")).toString());
    loc.setLocality(reader.attributes().value(QLatin1String("place")).toString());

    section.setFrom(loc);
    // ### are those the correct ones? there's also just "platform"
    section.setScheduledDeparturePlatform(reader.attributes().value(QLatin1String("plannedPlatformName")).toString());
    section.setExpectedDeparturePlatform(reader.attributes().value(QLatin1String("platformName")).toString());

    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdDateTime")) {
            section.setExpectedDepartureTime(parseDateTime(reader.subReader()));
        } else if (reader.name() == QLatin1String("itdDateTimeTarget")) {
            section.setScheduledDepartureTime(parseDateTime(reader.subReader()));
        }
    }
}

void EfaXmlParser::parseTripArrival(ScopedXmlStreamReader &&reader, JourneySection &section) const
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

    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdDateTime")) {
            section.setExpectedArrivalTime(parseDateTime(reader.subReader()));
        } else if (reader.name() == QLatin1String("itdDateTimeTarget")) {
            section.setScheduledArrivalTime(parseDateTime(reader.subReader()));
        }
    }
}

Departure EfaXmlParser::parsePartialTripIntermediateStop(ScopedXmlStreamReader &&reader) const
{
    Location loc;
    loc.setName(reader.attributes().value(QLatin1String("name")).toString());
    loc.setLatitude(reader.attributes().value(QLatin1String("y")).toFloat());
    loc.setLongitude(reader.attributes().value(QLatin1String("x")).toFloat());
    loc.setIdentifier(m_locationIdentifierType, reader.attributes().value(QLatin1String("stopID")).toString());
    loc.setLocality(reader.attributes().value(QLatin1String("place")).toString());

    Departure stop;
    stop.setStopPoint(loc);
    stop.setScheduledPlatform(reader.attributes().value(QLatin1String("platform")).toString());

    // TODO arrDelay/depDelay properties - which unit do they have?

    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdDateTime")) {
            // TODO sometimes there are two itdDateTime elements here?
            // TODO sometimes there are invalid itdDateTime elements here?
            const auto dt = parseDateTime(reader.subReader());
            if (dt.isValid()) {
                stop.setScheduledDepartureTime(dt);
            }
        }
    }

    return stop;
}

std::vector<Departure> EfaXmlParser::parsePartialTripStopSequence(ScopedXmlStreamReader &&reader) const
{
    std::vector<Departure> stops;
    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdPoint")) {
            stops.push_back(parsePartialTripIntermediateStop(reader.subReader()));
        }
    }

    if (stops.size() > 2) { // includes departure/arrival stops too
        stops.erase(std::prev(stops.end()));
        stops.erase(stops.begin());
    }

    return stops;
}

JourneySection EfaXmlParser::parseTripPartialRoute(ScopedXmlStreamReader &&reader) const
{
    JourneySection section;
    if (reader.attributes().value(QLatin1String("type")) == QLatin1String("IT")) {
        section.setMode(JourneySection::Walking);
    }

    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdPoint")) {
            const auto type = reader.attributes().value(QLatin1String("usage"));
            if (type == QLatin1String("departure")) {
                parseTripDeparture(reader.subReader(), section);
            } else if (type == QLatin1String("arrival")) {
                parseTripArrival(reader.subReader(), section);
            }
        } else if (reader.name() == QLatin1String("itdMeansOfTransport")) {
            Line line;
            line.setName(reader.attributes().value(QLatin1String("shortname")).toString());
            const auto type = reader.attributes().value(QLatin1String("type")).toInt();
            const auto prodName = reader.attributes().value(QLatin1String("productName"));
            if (type == 99 || prodName == QLatin1String("Fussweg")) {
                section.setMode(JourneySection::Walking);
            } else if (type == 98) {
                section.setMode(JourneySection::Transfer);
            } else {
                line.setModeString(prodName.toString());
            }
            line.setMode(motTypeToLineMode(reader.attributes().value(QLatin1String("motType")).toInt()));
            Route route;
            route.setDirection(reader.attributes().value(QLatin1String("destination")).toString());
            route.setLine(line);
            section.setRoute(route);
            if (section.mode() == JourneySection::Invalid) {
                section.setMode(JourneySection::PublicTransport);
            }
        } else if (reader.name() == QLatin1String("infoLink")) {
            section.addNotes(parseInfoLink(reader.subReader()));
        } else if (reader.name() == QLatin1String("itdStopSeq")) {
            section.setIntermediateStops(parsePartialTripStopSequence(reader.subReader()));
        }
    }

    return section;
}

Journey EfaXmlParser::parseTripRoute(ScopedXmlStreamReader &&reader) const
{
    Journey journey;
    std::vector<JourneySection> sections;

    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("itdPartialRoute")) {
            sections.push_back(parseTripPartialRoute(reader.subReader()));
        }
    }

    journey.setSections(std::move(sections));
    return journey;
}

std::vector<Journey> EfaXmlParser::parseTripResponse(const QByteArray &data) const
{
    //qDebug().noquote() << data;
    std::vector<Journey> res;
    QXmlStreamReader xsr(data);
    ScopedXmlStreamReader reader(xsr);
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("itdRoute")) {
            res.push_back(parseTripRoute(reader.subReader()));
        }
    }
    return res;
}

QStringList EfaXmlParser::parseInfoLink(ScopedXmlStreamReader &&reader) const
{
    QStringList l;
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("infoLinkText") || reader.name() == QLatin1String("subtitle")
            || reader.name() == QLatin1String("wmlText") || reader.name() == QLatin1String("htmlText"))
        {
            l.push_back(reader.readElementText());
        }
    }
    return l;
}
