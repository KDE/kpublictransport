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
    w.writeStartElement(ojpNS(), QStringLiteral("PlaceRef"));
    w.writeTextElement(ojpNS(), QStringLiteral("StopPlaceRef"), req.stop().identifier(QStringLiteral("uic"))); // ### TODO configure id type
    w.writeEndElement(); // </ojp:PlaceRef>
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

    // TODO

    writeEndServiceRequest(w);
    return {};
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
