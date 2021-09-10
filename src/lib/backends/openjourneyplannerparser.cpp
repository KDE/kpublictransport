/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "openjourneyplannerparser.h"
#include "scopedxmlstreamreader.h"

#include <gtfs/hvt.h>
#include <ifopt/ifoptutil.h>

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include <QByteArray>
#include <QDebug>
#include <QPointF>
#include <QXmlStreamReader>

using namespace KPublicTransport;

bool OpenJourneyPlannerParser::hasError() const
{
    return !m_errorMsg.isEmpty();
}

QString OpenJourneyPlannerParser::errorMessage() const
{
    return m_errorMsg;
}

std::vector<Location> OpenJourneyPlannerParser::parseLocationInformationResponse(const QByteArray &responseData)
{
    QXmlStreamReader reader(responseData);
    ScopedXmlStreamReader r(reader);
    while (r.readNextElement()) {
        if (r.isElement("OJPLocationInformationDelivery") || r.isElement("LocationInformationResponse")) {
            return parseLocationInformationDelivery(r.subReader());
        }
    }
    return {};
}

std::vector<Stopover> OpenJourneyPlannerParser::parseStopEventResponse(const QByteArray &responseData)
{
    QXmlStreamReader reader(responseData);
    ScopedXmlStreamReader r(reader);
    while (r.readNextElement()) {
        if (r.isElement("OJPStopEventDelivery") || r.isElement("StopEventResponse")) {
            return parseStopEventDelivery(r.subReader());
        }
    }
    return {};
}

std::vector<Journey> OpenJourneyPlannerParser::parseTripResponse(const QByteArray &responseData)
{
    QXmlStreamReader reader(responseData);
    ScopedXmlStreamReader r(reader);
    while (r.readNextElement()) {
        if (r.isElement("OJPTripDelivery") || r.isElement("TripResponse")) {
            return parseTripDelivery(r.subReader());
        }
    }
    return {};
}

std::vector<Location> OpenJourneyPlannerParser::parseLocationInformationDelivery(ScopedXmlStreamReader &&r)
{
    std::vector<Location> l;
    while (r.readNextSibling()) {
        if (r.isElement("Location") || r.isElement("LocationResult")) {
            auto loc = parseLocationInformationLocationResult(r.subReader());
            if (!loc.isEmpty()) {
                l.push_back(std::move(loc));
            }
        } else if (r.isElement("ErrorCondition")) {
            parseError(r.subReader());
        }
    }
    return l;
}

Location OpenJourneyPlannerParser::parseLocationInformationLocationResult(ScopedXmlStreamReader &&r) const
{
    Location loc;
    while (r.readNextSibling()) {
        if (r.isElement("Location")) {
            loc = parseLocationInformationLocation(r.subReader());
        }
    }
    return loc;
}

Location OpenJourneyPlannerParser::parseLocationInformationLocation(ScopedXmlStreamReader &&r) const
{
    Location loc;
    while (r.readNextSibling()) {
        if (r.isElement("StopPlace") || r.isElement("StopPoint")) {
            loc.setType(Location::Stop);
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("StopPlaceRef") || subR.isElement("StopPointRef")) {
                    const auto id = subR.readElementText();
                    loc.setIdentifier(m_identifierType, id);
                    if (IfoptUtil::isValid(id)) {
                        loc.setIdentifier(IfoptUtil::identifierType(), id);
                    }
                } else if (subR.isElement("StopPlaceName") || subR.isElement("StopPointName")) {
                    loc.setName(parseTextElement(subR.subReader()));
                }
            }
        } else if (r.isElement("GeoPosition")) {
            const auto p = parseGeoPosition(r.subReader());
            loc.setLongitude(p.x());
            loc.setLatitude(p.y());
        } else if (r.isElement("LocationName")) {
            loc.setLocality(parseTextElement(r.subReader()));
        }
    }

    // cleanup locality also containing the stop name
    if (loc.locality().startsWith(loc.name()) && loc.locality().endsWith(QLatin1Char(')'))) {
        const auto idx = loc.locality().lastIndexOf(QLatin1Char('('));
        if (idx > 0) {
            loc.setLocality(loc.locality().mid(idx + 1, loc.locality().size() - idx - 2));
        }
    }

    return loc;
}

QString OpenJourneyPlannerParser::parseTextElement(ScopedXmlStreamReader &&r) const
{
    QString t;
    while (r.readNextSibling()) {
        if (r.isElement("Text")) {
            t = r.readElementText();
        }
    }
    return t;
}

QPointF OpenJourneyPlannerParser::parseGeoPosition(ScopedXmlStreamReader &&r) const
{
    QPointF p;
    while (r.readNextSibling()) {
        if (r.isElement("Longitude")) {
            p.setX(r.readElementText().toDouble());
        } else if (r.isElement("Latitude")) {
            p.setY(r.readElementText().toDouble());
        }
    }
    return p;
}

std::vector<Stopover> OpenJourneyPlannerParser::parseStopEventDelivery(ScopedXmlStreamReader &&r)
{
    std::vector<Stopover> l;
    while (r.readNextSibling()) {
        if (r.isElement("StopEventResponseContext")) {
            parseResponseContext(r.subReader());
        } else if (r.isElement("StopEventResult")) {
            l.push_back(parseStopEventResult(r.subReader()));
        } else if (r.isElement("ErrorCondition")) {
            parseError(r.subReader());
        }
    }
    return l;
}

void OpenJourneyPlannerParser::parseResponseContext(ScopedXmlStreamReader &&r)
{
    while (r.readNextSibling()) {
        if (r.isElement("Places")) {
            parseResponseContextPlaces(r.subReader());
        }
    }
}

void OpenJourneyPlannerParser::parseResponseContextPlaces(ScopedXmlStreamReader && r)
{
    while (r.readNextSibling()) {
        if (r.isElement("Location")) {
            auto loc = parseLocationInformationLocation(r.subReader());
            m_contextLocations.insert(loc.identifier(m_identifierType), std::move(loc));
        }
    }
}

Stopover OpenJourneyPlannerParser::parseStopEventResult(ScopedXmlStreamReader &&r) const
{
    Stopover stop;
    while (r.readNextSibling()) {
        if (r.isElement("StopEvent")) {
            stop = parseStopEvent(r.subReader());
        }
    }
    return stop;
}

Stopover OpenJourneyPlannerParser::parseStopEvent(ScopedXmlStreamReader &&r) const
{
    Stopover stop;
    Route route;
    QStringList attrs;
    while (r.readNextSibling()) {
        if (r.isElement("ThisCall")) {
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("CallAtStop")) {
                    parseCallAtStop(subR.subReader(), stop);
                }
            }
        } else if (r.isElement("Service")) {
            parseService(r.subReader(), route, attrs);
        }
        // Extensions?
    }
    stop.setRoute(route);
    stop.addNotes(std::move(attrs));
    return stop;
}

void OpenJourneyPlannerParser::parseCallAtStop(ScopedXmlStreamReader &&r, Stopover &stop) const
{
    Location loc;
    while (r.readNextSibling()) {
        if (r.isElement("StopPointRef")) {
            const auto id = r.readElementText();
            loc = m_contextLocations.value(id);
        } else if (r.isElement("GeoPosition")) {
            const auto p = parseGeoPosition(r.subReader());
            loc.setLatitude(p.y());
            loc.setLongitude(p.x());
            loc.setType(Location::Place);
        } else if (r.isElement("LocationName") || r.isElement("StopPointName")) {
            if (loc.name().isEmpty()) {
                loc.setName(parseTextElement(r.subReader()));
            }
        } else if (r.isElement("ServiceDeparture")) {
            const auto t = parseTime(r.subReader());
            stop.setScheduledDepartureTime(t.scheduledTime);
            stop.setExpectedDepartureTime(t.expectedTime);
        } else if (r.isElement("ServiceArrival")) {
            const auto t = parseTime(r.subReader());
            stop.setScheduledArrivalTime(t.scheduledTime);
            stop.setExpectedArrivalTime(t.expectedTime);
        } else if (r.isElement("PlannedQuay") || r.isElement("PlannedBay")) {
            stop.setScheduledPlatform(parseTextElement(r.subReader()));
        } else if (r.isElement("EstimatedQuay") || r.isElement("EstimatedBay")) {
            stop.setExpectedPlatform(parseTextElement(r.subReader()));
        } else if (r.isElement("NotServicedStop")) {
            if (r.readElementText() == QLatin1String("true")) {
                stop.setDisruptionEffect(Disruption::NoService);
            }
        }
    }
    stop.setStopPoint(std::move(loc));
}

void OpenJourneyPlannerParser::parseService(ScopedXmlStreamReader &&r, Route &route, QStringList &attributes) const
{
    auto line = route.line();
    while (r.readNextSibling()) {
        if (r.isElement("Mode")) {
            line.setMode(parseMode(r.subReader()));
        } else if (r.isElement("PublishedLineName")) {
            line.setName(parseTextElement(r.subReader()));
        } else if (r.isElement("Attribute")) {
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("Text")) {
                    attributes.push_back(parseTextElement(subR.subReader()));
                }
            }
        } else if (r.isElement("DestinationStopPointRef")) {
            // TODO
        } else if (r.isElement("DestinationText")) {
            route.setDirection(parseTextElement(r.subReader()));
        } else if (r.isElement("ServiceSection")) {
            route.setLine(std::move(line));
            parseService(r.subReader(), route, attributes);
            line = route.line();
        }
    }
    route.setLine(std::move(line));
}

OpenJourneyPlannerParser::TimePair OpenJourneyPlannerParser::parseTime(ScopedXmlStreamReader &&r) const
{
    TimePair t;
    while (r.readNextSibling()) {
        if (r.isElement("TimetabledTime")) {
            t.scheduledTime = QDateTime::fromString(r.readElementText(), Qt::ISODate);
        } else if (r.isElement("EstimatedTime")) {
            t.expectedTime = QDateTime::fromString(r.readElementText(), Qt::ISODate);
        }
    }
    return t;
}

Line::Mode OpenJourneyPlannerParser::parseMode(ScopedXmlStreamReader &&r) const
{
    QString mode, subMode;
    while (r.readNextSibling()) {
        if (r.isElement("PtMode")) {
            mode = r.readElementText();
        } else if (r.name().endsWith(QLatin1String("Submode"))) {
            subMode = r.readElementText();
        }
    }

    const auto m = Gtfs::Hvt::typeToMode(subMode);
    if (m == Line::Unknown) {
        return Gtfs::Hvt::typeToMode(mode);
    }
    return m;
}

std::vector<Journey> OpenJourneyPlannerParser::parseTripDelivery(ScopedXmlStreamReader &&r)
{
    std::vector<Journey> l;
    while (r.readNextSibling()) {
        if (r.isElement("TripResponseContext")) {
            parseResponseContext(r.subReader());
        } else if (r.isElement("TripResult")) {
            l.push_back(parseTripResult(r.subReader()));
        } else if (r.isElement("ErrorCondition")) {
            parseError(r.subReader());
        }
    }
    return l;
}

Journey OpenJourneyPlannerParser::parseTripResult(ScopedXmlStreamReader &&r) const
{
    Journey jny;
    while (r.readNextSibling()) {
        if (r.isElement("Trip")) {
            jny = parseTrip(r.subReader());
        }
    }
    return jny;
}

Journey OpenJourneyPlannerParser::parseTrip(ScopedXmlStreamReader &&r) const
{
    Journey jny;
    std::vector<JourneySection> sections;
    while (r.readNextSibling()) {
        if (r.isElement("TripLeg")) {
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("TimedLeg")) {
                    sections.push_back(parseTimedLeg(subR.subReader()));
                } else if (subR.isElement("TransferLeg")) {
                    auto section = parseTransferLeg(subR.subReader());
                    section.setMode(JourneySection::Transfer);
                    sections.push_back(std::move(section));
                } else if (subR.isElement("ContinuousLeg")) {
                    auto section = parseTransferLeg(subR.subReader());
                    section.setMode(JourneySection::Walking);
                    sections.push_back(std::move(section));
                }
            }
        }
    }
    jny.setSections(std::move(sections));
    return jny;
}

JourneySection OpenJourneyPlannerParser::parseTimedLeg(ScopedXmlStreamReader &&r) const
{
    JourneySection section;
    section.setMode(JourneySection::PublicTransport);
    std::vector<Stopover> intermediateStops;
    Route route;
    QStringList attributes;
    while (r.readNextSibling()) {
        if (r.isElement("LegBoard")) {
            Stopover stop;
            parseCallAtStop(r.subReader(), stop);
            section.setFrom(stop.stopPoint());
            section.setScheduledDepartureTime(stop.scheduledDepartureTime());
            section.setExpectedDepartureTime(stop.expectedDepartureTime());
            section.setScheduledDeparturePlatform(stop.scheduledPlatform());
            section.setExpectedDeparturePlatform(stop.expectedPlatform());
        } else if (r.isElement("LegIntermediates")) {
            Stopover stop;
            parseCallAtStop(r.subReader(), stop);
            intermediateStops.push_back(std::move(stop));
        } else if (r.isElement("LegAlight")) {
            Stopover stop;
            parseCallAtStop(r.subReader(), stop);
            section.setTo(stop.stopPoint());
            section.setScheduledArrivalTime(stop.scheduledArrivalTime());
            section.setExpectedArrivalTime(stop.expectedArrivalTime());
            section.setScheduledArrivalPlatform(stop.scheduledPlatform());
            section.setExpectedArrivalPlatform(stop.expectedPlatform());
        } else if (r.isElement("Service")) {
            parseService(r.subReader(), route, attributes);
        } else if (r.isElement("LegTrack")) {
            Path path;
            path.setSections({parsePathGuildanceSection(r.subReader())});
            section.setPath(std::move(path));
        }
    }
    section.setRoute(std::move(route));
    section.addNotes(std::move(attributes));
    section.setIntermediateStops(std::move(intermediateStops));
    return section;
}

JourneySection OpenJourneyPlannerParser::parseTransferLeg(ScopedXmlStreamReader &&r) const
{
    // TODO WalkDuration vs. BufferTime?
    JourneySection section;
    while (r.readNextSibling()) {
        if (r.isElement("LegStart")) {
            Stopover stop;
            parseCallAtStop(r.subReader(), stop);
            section.setFrom(stop.stopPoint());
        } else if (r.isElement("LegEnd")) {
            Stopover stop;
            parseCallAtStop(r.subReader(), stop);
            section.setTo(stop.stopPoint());
        } else if (r.isElement("TimeWindowStart")) {
            section.setScheduledDepartureTime(QDateTime::fromString(r.readElementText(), Qt::ISODate));
        } else if (r.isElement("TimeWindowEnd")) {
            section.setScheduledArrivalTime(QDateTime::fromString(r.readElementText(), Qt::ISODate));
        } else if (r.isElement("PathGuidance")) {
            section.setPath(parsePathGuidance(r.subReader()));
        }
    }
    return section;
}

Path OpenJourneyPlannerParser::parsePathGuidance(ScopedXmlStreamReader &&r) const
{
    Path path;
    std::vector<PathSection> sections;
    while (r.readNextSibling()) {
        if (r.isElement("PathGuidanceSection")) {
            sections.push_back(parsePathGuildanceSection(r.subReader()));
        }
    }
    path.setSections(std::move(sections));
    return path;
}

PathSection OpenJourneyPlannerParser::parsePathGuildanceSection(ScopedXmlStreamReader &&r) const
{
    PathSection section;
    while (r.readNextSibling()) {
        if (r.isElement("TrackSection")) {
            section = parseTrackSection(r.subReader());
        }
    }
    return section;
}

PathSection OpenJourneyPlannerParser::parseTrackSection(ScopedXmlStreamReader &&r) const
{
    PathSection section;
    while (r.readNextSibling()) {
        if (r.isElement("LinkProjection")) {
            auto subR = r.subReader();
            QPolygonF poly;
            while (subR.readNextSibling()) {
                if (subR.isElement("Position")) {
                    poly.push_back(parseGeoPosition(subR.subReader()));
                }
            }
            section.setPath(std::move(poly));
        } else if (r.isElement("RoadName")) {
            section.setDescription(r.readElementText());
        }
    }
    return section;
}

void OpenJourneyPlannerParser::parseError(ScopedXmlStreamReader &&r)
{
    while (r.readNextSibling()) {
        if (r.isElement("Description")) {
            m_errorMsg = r.readElementText();
        }
    }
}
