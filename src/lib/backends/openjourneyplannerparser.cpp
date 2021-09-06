/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "openjourneyplannerparser.h"
#include "scopedxmlstreamreader.h"

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

std::vector<Stopover> OpenJourneyPlannerParser::parseStopEventResponse(const QByteArray &responseData) const
{
    qDebug().noquote() << responseData; // ### for development only
    QXmlStreamReader reader(responseData);
    ScopedXmlStreamReader r(reader);
    while (r.readNextElement()) {
        if (r.isElement("OJPStopEventDelivery")) {
            return parseStopEventDelivery(r.subReader());
        }
    }
    return {};
}

std::vector<Journey> OpenJourneyPlannerParser::parseTripResponse(const QByteArray &responseData) const
{
    qDebug().noquote() << responseData;
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
                    loc.setIdentifier(QStringLiteral("uic"), subR.readElementText()); // ### TODO configure identifier type!
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

std::vector<Stopover> OpenJourneyPlannerParser::parseStopEventDelivery(ScopedXmlStreamReader &&r) const
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

void OpenJourneyPlannerParser::parseResponseContext(ScopedXmlStreamReader &&r) const
{
    while (r.readNextSibling()) {
        // TODO
    }
}

Stopover OpenJourneyPlannerParser::parseStopEventResult(ScopedXmlStreamReader &&r) const
{
    qDebug();
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
    qDebug();
    Stopover stop;
    Route route;
    while (r.readNextSibling()) {
        if (r.isElement("ThisCall")) {
            auto subR = r.subReader();
            while (subR.readNextSibling()) {
                if (subR.isElement("CallAtStop")) {
                    parseCallAtStop(subR.subReader(), stop);
                }
            }
        } else if (r.isElement("Service")) {
            parseService(r.subReader(), route);
        } else if (r.isElement("Extension")) {
            // TODO
        }
    }
    stop.setRoute(route);
    return stop;
}

void OpenJourneyPlannerParser::parseCallAtStop(ScopedXmlStreamReader &&r, Stopover &stop) const
{
    qDebug();
    while (r.readNextSibling()) {
        if (r.isElement("StopPointRef")) {
            // TODO
        } else if (r.isElement("ServiceDeparture")) {
            // TODO
        } else if (r.isElement("ServiceArrival")) {
            // TODO
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

void OpenJourneyPlannerParser::parseService(ScopedXmlStreamReader &&r, Route &route) const
{
    qDebug();
    auto line = route.line();
    while (r.readNextSibling()) {
        if (r.isElement("Mode")) {
            // TODO
        } else if (r.isElement("PublishedLineName")) {
            line.setName(parseTextElement(r.subReader()));
        } else if (r.isElement("Attribute")) {
            // TODO
        } else if (r.isElement("DestinationStopPointRef")) {
            // TODO
        } else if (r.isElement("DestinationText")) {
            route.setDirection(parseTextElement(r.subReader()));
        }
    }
    route.setLine(std::move(line));
}
