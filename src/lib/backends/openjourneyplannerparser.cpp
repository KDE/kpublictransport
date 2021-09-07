/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "openjourneyplannerparser.h"
#include "scopedxmlstreamreader.h"

#include <gtfs/hvt.h>

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include <QByteArray>
#include <QDebug>
#include <QXmlStreamReader>

using namespace KPublicTransport;

std::vector<Location> OpenJourneyPlannerParser::parseLocationInformationResponse(const QByteArray &responseData) const
{
    QXmlStreamReader reader(responseData);
    ScopedXmlStreamReader r(reader);
    while (r.readNextElement()) {
        if (r.isElement("OJPLocationInformationDelivery")) {
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
        if (r.isElement("OJPStopEventDelivery")) {
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
        if (r.isElement("OJPTripDelivery")) {
            return parseTripDelivery(r.subReader());
        }
    }
    return {};
}

std::vector<Location> OpenJourneyPlannerParser::parseLocationInformationDelivery(ScopedXmlStreamReader &&r) const
{
    std::vector<Location> l;
    while (r.readNextSibling()) {
        if (r.isElement("Location")) {
            auto loc = parseLocationInformationLocationOuter(r.subReader());
            if (!loc.isEmpty()) {
                l.push_back(std::move(loc));
            }
        }
    }
    return l;
}

Location OpenJourneyPlannerParser::parseLocationInformationLocationOuter(ScopedXmlStreamReader &&r) const
{
    Location loc;
    while (r.readNextSibling()) {
        if (r.isElement("Location")) {
            loc = parseLocationInformationLocationInner(r.subReader());
        }
    }
    return loc;
}

Location OpenJourneyPlannerParser::parseLocationInformationLocationInner(ScopedXmlStreamReader &&r) const
{
    Location loc;
    while (r.readNextSibling()) {
        if (r.isElement("StopPlace")) {
            loc.setType(Location::Stop);
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("StopPlaceRef")) {
                    loc.setIdentifier(m_identifierType, subR.readElementText());
                } else if (subR.isElement("StopPlaceName")) {
                    loc.setName(parseTextElement(subR.subReader()));
                }
            }
        } else if (r.isElement("GeoPosition")) {
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("Longitude")) {
                    loc.setLongitude(subR.readElementText().toDouble());
                } else if (subR.isElement("Latitude")) {
                    loc.setLatitude(subR.readElementText().toDouble());
                }
            }
        } else if (r.isElement("LocationName")) {
            // TODO this needs some post-processing it seems
            loc.setLocality(parseTextElement(r.subReader()));
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

std::vector<Stopover> OpenJourneyPlannerParser::parseStopEventDelivery(ScopedXmlStreamReader &&r)
{
    std::vector<Stopover> l;
    while (r.readNextSibling()) {
        if (r.isElement("StopEventResponseContext")) {
            parseResponseContext(r.subReader());
        } else if (r.isElement("StopEventResult")) {
            l.push_back(parseStopEventResult(r.subReader()));
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
            auto loc = parseLocationInformationLocationInner(r.subReader());
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
    while (r.readNextSibling()) {
        if (r.isElement("StopPointRef")) {
            const auto id = r.readElementText();
            stop.setStopPoint(m_contextLocations.value(id));
        } else if (r.isElement("ServiceDeparture")) {
            const auto t = parseTime(r.subReader());
            stop.setScheduledDepartureTime(t.scheduledTime);
            stop.setExpectedDepartureTime(t.expectedTime);
        } else if (r.isElement("ServiceArrival")) {
            const auto t = parseTime(r.subReader());
            stop.setScheduledArrivalTime(t.scheduledTime);
            stop.setExpectedArrivalTime(t.expectedTime);
        } else if (r.isElement("PlannedQuay")) {
            stop.setScheduledPlatform(parseTextElement(r.subReader()));
        } else if (r.isElement("EstimatedQuay")) {
            stop.setExpectedPlatform(parseTextElement(r.subReader()));
        } else if (r.isElement("NotServicedStop")) {
            if (r.readElementText() == QLatin1String("true")) {
                stop.setDisruptionEffect(Disruption::NoService);
            }
        }
    }
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
                    sections.push_back(parseTransferLeg(subR.subReader()));
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
            // TODO
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
    section.setMode(JourneySection::Transfer);
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
        }
    }
    return section;
}
