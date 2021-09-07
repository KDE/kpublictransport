/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "openjourneyplannerrequestbuilder.h"

#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/StopoverRequest>

#include <QByteArray>
#include <QDateTime>
#include <QDebug>
#include <QXmlStreamWriter>

using namespace KPublicTransport;

static QString siriNS() { return QStringLiteral("http://www.siri.org.uk/siri"); }
static QString ojpNS() { return QStringLiteral("http://www.vdv.de/ojp"); }

void OpenJourneyPlannerRequestBuilder::setTestMode(bool testMode)
{
    m_testMode = testMode;
}

QByteArray OpenJourneyPlannerRequestBuilder::buildLocationInformationRequest(const LocationRequest &req) const
{
    QByteArray output;
    QXmlStreamWriter w(&output);
    setupWriter(w);
    writeStartServiceRequest(w);
    w.writeTextElement(siriNS(), QStringLiteral("RequestRef"), QStringLiteral("KPublicTransport"));
    w.writeStartElement(ojpNS(), QStringLiteral("OJPLocationInformationRequest"));

    w.writeStartElement(ojpNS(), QStringLiteral("InitialInput"));
    if (req.hasCoordinate()) {
        w.writeStartElement(ojpNS(), QStringLiteral("GeoRestriction"));
        w.writeStartElement(ojpNS(), QStringLiteral("Circle"));
        w.writeStartElement(ojpNS(), QStringLiteral("Center"));
        w.writeTextElement(siriNS(), QStringLiteral("Longitude"), QString::number(req.location().longitude()));
        w.writeTextElement(siriNS(), QStringLiteral("Latitude"), QString::number(req.location().latitude()));
        w.writeEndElement(); // </ojp:Center>
        w.writeTextElement(ojpNS(), QStringLiteral("Radius"), QString::number(req.maximumDistance()));
        w.writeEndElement(); // </ojp:Circle>
        w.writeEndElement(); // </ojp:GeoRestriction>
    } else {
        w.writeTextElement(ojpNS(), QStringLiteral("LocationName"), req.location().name());
    }
    w.writeEndElement(); // </ojp:InitialInput>

    w.writeStartElement(ojpNS(), QStringLiteral("Restrictions"));
    w.writeTextElement(ojpNS(), QStringLiteral("Type"), QStringLiteral("stop"));
    w.writeTextElement(ojpNS(), QStringLiteral("NumberOfResults"), QString::number(req.maximumResults()));
    // TODO ojp:Language
    w.writeEndElement(); // </ojp:Restrictions>

    w.writeEndElement(); // </ojp:OJPLocationInformationRequest>
    writeEndServiceRequest(w);
    return output;
}

QByteArray OpenJourneyPlannerRequestBuilder::buildStopEventRequest(const StopoverRequest &req) const
{
    QByteArray output;
    QXmlStreamWriter w(&output);
    setupWriter(w);
    writeStartServiceRequest(w);
    w.writeTextElement(siriNS(), QStringLiteral("RequestRef"), QStringLiteral("KPublicTransport"));
    w.writeStartElement(ojpNS(), QStringLiteral("OJPStopEventRequest"));

    w.writeStartElement(ojpNS(), QStringLiteral("Location"));
    writePlaceRef(w, req.stop());
    w.writeTextElement(ojpNS(), QStringLiteral("DepArrTime"), req.dateTime().toUTC().toString(Qt::ISODate));
    w.writeEndElement(); // </ojp:Location>

    w.writeStartElement(ojpNS(), QStringLiteral("Params"));
    w.writeTextElement(ojpNS(), QStringLiteral("StopEventType"), req.mode() == StopoverRequest::QueryArrival ? QStringLiteral("arrival") : QStringLiteral("departure")); // "both" is also supported
    w.writeTextElement(ojpNS(), QStringLiteral("IncludePreviousCalls"), QStringLiteral("false"));
    w.writeTextElement(ojpNS(), QStringLiteral("IncludeOnwardCalls"), QStringLiteral("false"));
    w.writeTextElement(ojpNS(), QStringLiteral("IncludeOperatingDays"), QStringLiteral("false"));
    w.writeTextElement(ojpNS(), QStringLiteral("IncludeRealtimeData"), QStringLiteral("true"));
    w.writeTextElement(ojpNS(), QStringLiteral("NumberOfResults"), QString::number(req.maximumResults()));
    w.writeEndElement(); // </ojp:Params>

    w.writeEndElement(); // </ojp:OJPStopEventRequest>
    writeEndServiceRequest(w);
    return output;
}

QByteArray OpenJourneyPlannerRequestBuilder::buildTripRequest(const JourneyRequest &req) const
{
    QByteArray output;
    QXmlStreamWriter w(&output);
    setupWriter(w);
    writeStartServiceRequest(w);
    w.writeTextElement(siriNS(), QStringLiteral("RequestRef"), QStringLiteral("KPublicTransport"));
    w.writeStartElement(ojpNS(), QStringLiteral("OJPTripRequest"));

    w.writeStartElement(ojpNS(), QStringLiteral("Origin"));
    writePlaceRef(w, req.from());
    if (req.dateTimeMode() == JourneyRequest::Departure) {
        w.writeTextElement(ojpNS(), QStringLiteral("DepArrTime"), req.dateTime().toUTC().toString(Qt::ISODate));
    }
    w.writeEndElement(); // </ojp:Origin>

    w.writeStartElement(ojpNS(), QStringLiteral("Destination"));
    writePlaceRef(w, req.to());
    if (req.dateTimeMode() == JourneyRequest::Arrival) {
        w.writeTextElement(ojpNS(), QStringLiteral("DepArrTime"), req.dateTime().toUTC().toString(Qt::ISODate));
    }
    w.writeEndElement(); // </ojp:Destination>

    // TODO IndividualTransportOptions

    w.writeStartElement(ojpNS(), QStringLiteral("Params"));
    w.writeTextElement(ojpNS(), QStringLiteral("IncludeTrackSections"), req.includePaths() ? QStringLiteral("true") : QStringLiteral("false"));
    w.writeTextElement(ojpNS(), QStringLiteral("IncludeLegProjection"), QStringLiteral("true")); // ???
    w.writeTextElement(ojpNS(), QStringLiteral("IncludeTurnDescription"), req.includePaths() ? QStringLiteral("true") : QStringLiteral("false"));
    w.writeTextElement(ojpNS(), QStringLiteral("IncludeAccessibility"), QStringLiteral("true")); // ???
    w.writeTextElement(ojpNS(), QStringLiteral("IncludeIntermediateStops"), req.includeIntermediateStops() ? QStringLiteral("true") : QStringLiteral("false"));
    w.writeTextElement(ojpNS(), QStringLiteral("IncludeFares"), QStringLiteral("false")); // TODO
    w.writeTextElement(ojpNS(), QStringLiteral("NumberOfResults"), QString::number(req.maximumResults()));
    // TODO NumberOfResultsBefore|After for next/prev requests
    w.writeEndElement(); // </ojp:Params>

    w.writeEndElement(); // </ojp:OJPTripRequest>
    writeEndServiceRequest(w);
    return output;
}

void OpenJourneyPlannerRequestBuilder::setupWriter(QXmlStreamWriter &w) const
{
    if (Q_UNLIKELY(m_testMode)) {
        w.setAutoFormatting(true);
        w.setAutoFormattingIndent(1);
    }
}

void OpenJourneyPlannerRequestBuilder::writeStartServiceRequest(QXmlStreamWriter &w) const
{
    w.writeStartDocument();
    w.writeNamespace(siriNS(), QStringLiteral("siri"));
    w.writeNamespace(ojpNS(), QStringLiteral("ojp"));
    w.writeStartElement(siriNS(), QStringLiteral("OJP"));
    w.writeAttribute(QStringLiteral("version"), QStringLiteral("1.0"));
    w.writeStartElement(siriNS(), QStringLiteral("OJPRequest"));
    w.writeStartElement(siriNS(), QStringLiteral("ServiceRequest"));
}

void OpenJourneyPlannerRequestBuilder::writeEndServiceRequest(QXmlStreamWriter &w) const
{
    w.writeEndElement(); // </siri:ServiceRequest>
    w.writeEndElement(); // </siri:OJPRequest>
    w.writeEndElement(); // </siri:OJP>
    w.writeEndDocument();
}

void OpenJourneyPlannerRequestBuilder::writePlaceRef(QXmlStreamWriter &w, const Location &loc) const
{
    w.writeStartElement(ojpNS(), QStringLiteral("PlaceRef"));
    const auto id = loc.identifier(QStringLiteral("uic")); // ### TODO configure id type
    if (!id.isEmpty()) {
        w.writeTextElement(ojpNS(), QStringLiteral("StopPlaceRef"), id);
    } else if (loc.hasCoordinate()) {
        w.writeStartElement(ojpNS(), QStringLiteral("GeoPosition"));
        w.writeTextElement(siriNS(), QStringLiteral("Longitude"), QString::number(loc.longitude()));
        w.writeTextElement(siriNS(), QStringLiteral("Latitude"), QString::number(loc.latitude()));
        w.writeEndElement(); // </ojp:GeoPosition>
    }
    w.writeEndElement(); // </ojp:PlaceRef>
}
