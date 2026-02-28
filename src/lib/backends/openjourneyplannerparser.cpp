/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "openjourneyplannerparser.h"
#include "scopedxmlstreamreader.h"

#include <gtfs/hvt.h>
#include <ifopt/ifoptutil.h>
#include <siri/duration.h>
#include <siri/occupancy.h>
#include <uic/uicstationcode.h>

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopInformation>

#include <QByteArray>
#include <QDebug>
#include <QPointF>
#include <QXmlStreamReader>

using namespace Qt::Literals;
using namespace KPublicTransport;

bool OpenJourneyPlannerParser::hasError() const
{
    return !m_errorMsg.isEmpty();
}

QString OpenJourneyPlannerParser::errorMessage() const
{
    return m_errorMsg;
}

void OpenJourneyPlannerParser::setLocationIdentifierType(const QString &idType)
{
    m_identifierType = idType;
}

void OpenJourneyPlannerParser::setUicLocationIdentifierType(const QString &uicIdType)
{
    m_uicIdentifierType = uicIdType;
}

std::vector<Location> OpenJourneyPlannerParser::parseLocationInformationResponse(const QByteArray &responseData)
{
    QXmlStreamReader reader(responseData);
    ScopedXmlStreamReader r(reader);
    std::vector<Location> res;
    while (r.readNextElement()) {
        if (r.isElement("OJPLocationInformationDelivery") || r.isElement("LocationInformationResponse")) {
            res = parseLocationInformationDelivery(r.subReader());
        }
    }
    if (reader.hasError() && m_errorMsg.isEmpty()) {
        m_errorMsg = reader.errorString();
    }
    return res;
}

std::vector<Stopover> OpenJourneyPlannerParser::parseStopEventResponse(const QByteArray &responseData)
{
    QXmlStreamReader reader(responseData);
    ScopedXmlStreamReader r(reader);
    std::vector<Stopover> res;
    while (r.readNextElement()) {
        if (r.isElement("OJPStopEventDelivery") || r.isElement("StopEventResponse")) {
            res = parseStopEventDelivery(r.subReader());
        }
    }
    if (reader.hasError() && m_errorMsg.isEmpty()) {
        m_errorMsg = reader.errorString();
    }
    return res;
}

std::vector<Journey> OpenJourneyPlannerParser::parseTripResponse(const QByteArray &responseData)
{
    QXmlStreamReader reader(responseData);
    ScopedXmlStreamReader r(reader);
    std::vector<Journey> res;
    while (r.readNextElement()) {
        if (r.isElement("OJPTripDelivery") || r.isElement("TripResponse")) {
            res = parseTripDelivery(r.subReader());
        }
    }
    if (reader.hasError() && m_errorMsg.isEmpty()) {
        m_errorMsg = reader.errorString();
    }
    return res;
}

JourneySection OpenJourneyPlannerParser::parseTripInfoResponse(const QByteArray &responseData)
{
    QXmlStreamReader reader(responseData);
    ScopedXmlStreamReader r(reader);
    JourneySection section;
    while (r.readNextElement()) {
        if (r.isElement("OJPTripInfoDelivery")) {
            section = parseTripInfoDelivery(r.subReader());
        }
    }
    if (reader.hasError() && m_errorMsg.isEmpty()) {
        m_errorMsg = reader.errorString();
    }
    return section;
}

std::vector<Location> OpenJourneyPlannerParser::parseLocationInformationDelivery(ScopedXmlStreamReader &&r)
{
    std::vector<Location> l;
    while (r.readNextSibling()) {
        if (r.isElement("Location") || r.isElement("LocationResult") || r.isElement("PlaceResult")) {
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
        if (r.isElement("Location") || r.isElement("Place")) {
            loc = parseLocationInformationLocation(r.subReader());
        }
    }
    return loc;
}

Location OpenJourneyPlannerParser::parseLocationInformationLocation(ScopedXmlStreamReader &&r) const
{
    StopInformation info;
    Location loc;
    while (r.readNextSibling()) {
        if (r.isElement("StopPlace") || r.isElement("StopPoint")) {
            loc.setType(Location::Stop);
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("StopPlaceRef") || subR.isElement("StopPointRef")) {
                    const auto id = subR.readElementText();
                    setLocationIdentifier(loc, id);
                } else if (subR.isElement("StopPlaceName") || subR.isElement("StopPointName")) {
                    loc.setName(parseTextElement(subR.subReader()));
                } else if (subR.isElement("ParentRef") && !m_uicIdentifierType.isEmpty() && !loc.hasIdentifier(m_uicIdentifierType)) {
                    const auto id = subR.readElementText();
                    const auto parentLoc = m_contextLocations.value(id);
                    const auto uicId = parentLoc.identifier(m_uicIdentifierType);
                    if (!uicId.isEmpty()) {
                        loc.setIdentifier(m_uicIdentifierType, uicId);
                    }
                }
            }
        } else if (r.isElement("GeoPosition")) {
            const auto p = parseGeoPosition(r.subReader());
            loc.setLongitude(p.x());
            loc.setLatitude(p.y());
        } else if (r.isElement("LocationName")) {
            loc.setLocality(parseTextElement(r.subReader()));
        } else if (r.isElement("Mode")) {
            Line l;
            l.setMode(parseMode(r.subReader()));
            info.addLine(l);
        }
    }
    if (!info.lines().empty()) {
        loc.setData(info);
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

QString OpenJourneyPlannerParser::parseTextElement(ScopedXmlStreamReader &&r, const char *elementName) const
{
    QString t;
    while (r.readNextSibling()) {
        if (r.isElement(elementName)) {
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
        } else if (r.isElement("Situations")) {
            parseResponseContextSituations(r.subReader());
        }
    }
}

void OpenJourneyPlannerParser::parseResponseContextPlaces(ScopedXmlStreamReader && r)
{
    while (r.readNextSibling()) {
        if (r.isElement("Location") || r.isElement("Place")) {
            auto loc = parseLocationInformationLocation(r.subReader());
            m_contextLocations.insert(loc.identifier(m_identifierType), std::move(loc));
        }
    }
}

void OpenJourneyPlannerParser::parseResponseContextSituations(ScopedXmlStreamReader &&r)
{
    while (r.readNextSibling()) {
        if (r.isElement("PtSituation")) {
            parseSituation(r.subReader());
        }
    }
}

void OpenJourneyPlannerParser::parseSituation(ScopedXmlStreamReader &&r)
{
    QString source, id, summary, desc;
    while (r.readNextSibling()) {
        if (r.isElement("ParticipantRef")) {
            source = r.readElementText();
        } else if (r.isElement("SituationNumber")) {
            id = r.readElementText();
        } else if (r.isElement("Summary")) {
            summary = r.readElementText();
        } else if (r.isElement("Description")) { // TODO there's also <Detail>, but that seems a bit excessive?
            desc = r.readElementText();
        } else if  (r.isElement("PublishingActions")) {
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("PublishingAction")) {
                    auto [s, d] = parsePublishingAction(subR.subReader());
                    summary = std::move(s);
                    desc = std::move(d);
                }
            }
        }
    }
    m_contextSituations.insert(source + '-'_L1 + id, "<b>"_L1 + summary + "</b><br/>"_L1 + desc);
}

std::pair<QString, QString>OpenJourneyPlannerParser::parsePublishingAction(ScopedXmlStreamReader &&r) const
{
    std::pair<QString, QString> situation;
    while (r.readNextSibling()) {
        if (r.isElement("PassengerInformationAction")) {
            situation = parsePassengerInformationAction(r.subReader());
        }
    }
    return situation;
}

std::pair<QString, QString>OpenJourneyPlannerParser::parsePassengerInformationAction(ScopedXmlStreamReader &&r) const
{
    QString summary;
    QStringList desc;
    while (r.readNextSibling()) {
        if (r.isElement("TextualContent")) {
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("SummaryContent")) {
                    summary = parseTextElement(subR.subReader(), "SummaryText");
                } else if (subR.isElement("ReasonContent")) {
                    desc.push_back(parseTextElement(subR.subReader(), "ReasonText"));
                } else if (subR.isElement("DescriptionContent")) {
                    desc.push_back(parseTextElement(subR.subReader(), "DescriptionText"));
                } else if (subR.isElement("ConsequenceContent")) {
                    desc.push_back(parseTextElement(subR.subReader(), "ConsequenceText"));
                } else if (subR.isElement("DurationContent")) {
                    desc.push_back(parseTextElement(subR.subReader(), "DurationText"));
                }
            }
        }
    }
    return std::make_pair(summary, desc.join("<br/>"_L1));
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
    while (r.readNextSibling()) {
        if (r.isElement("ThisCall")) {
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("CallAtStop")) {
                    parseCallAtStop(subR.subReader(), stop);
                }
            }
        } else if (r.isElement("Service")) {
            Service service;
            parseService(r.subReader(), service);
            stop.setRoute(service.route);
            stop.setTripIdentifier(m_identifierType, service.identifier);
            stop.addNotes(std::move(service.attributes));
        }
        // Extensions?
    }
    return stop;
}

void OpenJourneyPlannerParser::parseCallAtStop(ScopedXmlStreamReader &&r, Stopover &stop) const
{
    Location loc;
    std::vector<LoadInfo> occupancy;
    while (r.readNextSibling()) {
        if (r.isElement("StopPointRef")) {
            const auto id = r.readElementText();
            auto l = m_contextLocations.value(id);
            if (l.isEmpty()) {
                setLocationIdentifier(loc, id);
            } else {
                loc = l;
            }
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
            if (r.readElementText() == "true"_L1) {
                stop.setDisruptionEffect(Disruption::NoService);
            }
        } else if (r.isElement("ExpectedDepartureOccupancy")) {
            occupancy.push_back(parseExpectedDepartureOccupancy(r.subReader()));
        }
    }
    stop.setStopPoint(std::move(loc));
    stop.setLoadInformation(std::move(occupancy));
}

void OpenJourneyPlannerParser::parseService(ScopedXmlStreamReader &&r, Service &service) const
{
    auto line = service.route.line();
    QString jnyRef, opDate;
    while (r.readNextSibling()) {
        if (r.isElement("Mode")) {
            line.setMode(parseMode(r.subReader()));
        } else if (r.isElement("PublishedLineName") || r.isElement("PublishedServiceName")) {
            line.setName(parseTextElement(r.subReader()));
        } else if (r.isElement("Attribute")) {
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("Text") || subR.isElement("UserText")) {
                    service.attributes.push_back(parseTextElement(subR.subReader()));
                }
            }
        } else if (r.isElement("DestinationStopPointRef")) {
            // TODO
        } else if (r.isElement("DestinationText")) {
            service.route.setDirection(parseTextElement(r.subReader()));
        } else if (r.isElement("ServiceSection")) {
            service.route.setLine(std::move(line));
            parseService(r.subReader(), service);
            line = service.route.line();
        } else if (r.isElement("SituationFullRef")) {
            const auto situationId = parseSituationRef(r.subReader());
            service.attributes.push_back(m_contextSituations.value(situationId));
        } else if (r.isElement("SituationFullRefs")) {
            auto subR = r.subReader();
            while (subR.readNextElement()) {
                if (subR.isElement("SituationFullRef")) {
                    const auto situationId = parseSituationRef(subR.subReader());
                    service.attributes.push_back(m_contextSituations.value(situationId));
                }
            }
        } else if (r.isElement("TrainNumber")) {
            service.route.setName(r.readElementText());
        } else if (r.isElement("OperatorRef")) {
            line.setOperatorIdentifier(m_identifierType, r.readElementText());
        } else if (r.isElement("JourneyRef")) {
            jnyRef = r.readElementText();
        } else if (r.isElement("OperatingDayRef")) {
            opDate = r.readElementText();
        }
    }
    service.route.setLine(std::move(line));
    service.identifier = jnyRef + '|'_L1 + opDate;
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

QString OpenJourneyPlannerParser::parseSituationRef(ScopedXmlStreamReader &&r) const
{
    QString source, id;
    while (r.readNextSibling()) {
        if (r.isElement("ParticipantRef")) {
            source = r.readElementText();
        } else if (r.isElement("SituationNumber")) {
            id = r.readElementText();
        }
    }
    return source + QLatin1Char('-') + id;
}

LoadInfo OpenJourneyPlannerParser::parseExpectedDepartureOccupancy(ScopedXmlStreamReader &&r) const
{
    LoadInfo info;
    while (r.readNextSibling()) {
        if (r.isElement("OccupancyLevel")) {
            info.setLoad(Siri::fromOccupancyEnum(r.readElementText()));
        } else if (r.isElement("FareClass")) {
            // TODO translate SIRI class enums
            info.setSeatingClass(r.readElementText());
        }
    }
    return info;
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
        if (r.isElement("TripLeg") || r.isElement("Leg")) {
            JourneySection section;
            double emission = NAN;

            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("TimedLeg")) {
                    section = parseTimedLeg(subR.subReader());
                } else if (subR.isElement("TransferLeg") || subR.isElement("InterchangeLeg")) {
                    section = parseTransferLeg(subR.subReader());
                    section.setMode(JourneySection::Transfer);
                } else if (subR.isElement("ContinuousLeg")) {
                    section = parseTransferLeg(subR.subReader());
                    section.setMode(JourneySection::Walking);
                } else if (subR.isElement("EmissionCO2")) {
                    auto sub2R = subR.subReader();
                    while (sub2R.readNextSibling()) {
                        if (sub2R.isElement("KilogramPerPersonKm")) {
                            bool ok = false;
                            emission = sub2R.readElementText().toDouble(&ok);
                            if (!ok) {
                                emission = NAN;
                            }
                        }
                    }
                }
            }

            if (!std::isnan(emission) && section.distance() > 0) {
                section.setCo2Emission((int)std::round(emission * section.distance()));
            }

            sections.push_back(std::move(section));
        }
    }

    // resolve times on duration-only legs in relation to adjacent legs
    for (auto it = sections.begin(); it != sections.end(); ++it) {
        if ((*it).scheduledDepartureTime().isValid()) {
            continue;
        }
        const auto dur = std::chrono::seconds(QDateTime::fromSecsSinceEpoch(0).secsTo((*it).scheduledArrivalTime()));
        if (it == sections.begin() && sections.size() > 1) { // first one is connected to the following one
            (*it).setScheduledArrivalTime((*std::next(it)).scheduledDepartureTime());
            (*it).setScheduledDepartureTime((*it).scheduledArrivalTime().addDuration(-dur));
        } else { // all subsequent ones follow the previous one
            (*it).setScheduledDepartureTime((*std::prev(it)).scheduledArrivalTime());
            (*it).setScheduledArrivalTime((*it).scheduledDepartureTime().addDuration(dur));
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
    while (r.readNextSibling()) {
        if (r.isElement("LegBoard")) {
            Stopover stop;
            parseCallAtStop(r.subReader(), stop);
            section.setDeparture(stop);
        } else if (r.isElement("LegIntermediates") || r.isElement("LegIntermediate")) {
            Stopover stop;
            parseCallAtStop(r.subReader(), stop);
            intermediateStops.push_back(std::move(stop));
        } else if (r.isElement("LegAlight")) {
            Stopover stop;
            parseCallAtStop(r.subReader(), stop);
            section.setArrival(stop);
        } else if (r.isElement("Service")) {
            Service service;
            parseService(r.subReader(), service);
            section.setRoute(std::move(service.route));
            section.setIdentifier(m_identifierType, service.identifier);
            section.addNotes(std::move(service.attributes));
        } else if (r.isElement("LegTrack")) {
            Path path;
            path.setSections({parsePathGuidanceSection(r.subReader())});
            section.setPath(std::move(path));
        }
    }
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
        } else if (r.isElement("PathGuidance") || r.isElement("NavigationPath")) {
            section.setPath(parsePathGuidance(r.subReader()));
        } else if (r.isElement("Length")) {
            bool ok = false;
            const auto d = r.readElementText().toDouble(&ok);
            if (ok && d > 0.0) {
                section.setDistance((int)std::round(d));
            }
        } else if (r.isElement("Duration") && !section.scheduledDepartureTime().isValid()) {
            const auto dur = Siri::fromDuration(r.readElementText());
            if (dur > std::chrono::seconds(0)) {
                section.setScheduledArrivalTime(QDateTime::fromMSecsSinceEpoch(0).addDuration(dur));
            }
        }
    }
    return section;
}

Path OpenJourneyPlannerParser::parsePathGuidance(ScopedXmlStreamReader &&r) const
{
    Path path;
    std::vector<PathSection> sections;
    while (r.readNextSibling()) {
        if (r.isElement("PathGuidanceSection") || r.isElement("NavigationSection")) {
            sections.push_back(parsePathGuidanceSection(r.subReader()));
        }
    }
    path.setSections(std::move(sections));
    return path;
}

PathSection OpenJourneyPlannerParser::parsePathGuidanceSection(ScopedXmlStreamReader &&r) const
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
        if (r.isElement("LinkProjection") || r.isElement("Projection")) {
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

JourneySection OpenJourneyPlannerParser::parseTripInfoDelivery(ScopedXmlStreamReader &&r)
{
    JourneySection section;
    while (r.readNextSibling()) {
        if (r.isElement("TripInfoResponseContext")) {
            parseResponseContext(r.subReader());
        } else if (r.isElement("TripInfoResult")) {
            section = parseTripInfoResult(r.subReader());
        } else if (r.isElement("ErrorCondition")) {
            parseError(r.subReader());
        }
    }
    return section;
}

JourneySection OpenJourneyPlannerParser::parseTripInfoResult(ScopedXmlStreamReader &&r) const
{
    JourneySection section;
    std::vector<Stopover> stops;
    while (r.readNextSibling()) {
        if (r.isElement("PreviousCall") || r.isElement("OnwardCall")) {
            Stopover stop;
            parseCallAtStop(r.subReader(), stop);
            stops.push_back(std::move(stop));
        } else if (r.isElement("Service")) {
            Service service;
            parseService(r.subReader(), service);
            section.setRoute(service.route);
            section.setIdentifier(m_identifierType, service.identifier);
            section.addNotes(service.attributes);
        } else if (r.isElement("JourneyTrack")) {
            Path path;
            path.setSections({parsePathGuidanceSection(r.subReader())});
            section.setPath(path);
        }
    }

    if (stops.size() < 2) {
        return section;
    }
    section.setDeparture(stops.front());
    section.setArrival(stops.back());
    stops.pop_back();
    stops.erase(stops.begin());
    section.setIntermediateStops(std::move(stops));
    section.setMode(JourneySection::PublicTransport);
    return section;
}

void OpenJourneyPlannerParser::parseError(ScopedXmlStreamReader &&r)
{
    while (r.readNextSibling()) {
        if (r.isElement("Description") || r.isElement("TripProblemType")) {
            m_errorMsg = r.readElementText();
        }
    }
}

void OpenJourneyPlannerParser::setLocationIdentifier(Location &loc, const QString &id) const
{
    loc.setIdentifier(m_identifierType, id);
    if (IfoptUtil::isValid(id)) {
        loc.setIdentifier(IfoptUtil::identifierType(), id);
    }
    if (!m_uicIdentifierType.isEmpty() && UicStationCode::isValid(id)) {
        loc.setIdentifier(m_uicIdentifierType, id);
    }
}
