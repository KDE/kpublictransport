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
#include <QTimeZone>
#include <QXmlStreamWriter>

using namespace KPublicTransport;

static QString siriNS() { return QStringLiteral("http://www.siri.org.uk/siri"); }
static QString ojpNS() { return QStringLiteral("http://www.vdv.de/ojp"); }
static QString triasNS() { return QStringLiteral("http://www.vdv.de/trias"); }

OpenJourneyPlannerRequestBuilder::OpenJourneyPlannerRequestBuilder() = default;
OpenJourneyPlannerRequestBuilder::~OpenJourneyPlannerRequestBuilder() = default;

void OpenJourneyPlannerRequestBuilder::setRequestorRef(const QString &ref)
{
    m_requestorRef = ref;
}

void OpenJourneyPlannerRequestBuilder::setUseTrias(bool isTrias)
{
    m_useTrias = isTrias;
}

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
    w.writeStartElement(ns(), m_useTrias ?  QStringLiteral("LocationInformationRequest") : QStringLiteral("OJPLocationInformationRequest"));
    writeRequestTimestamp(w);

    w.writeStartElement(ns(), QStringLiteral("InitialInput"));
    if (req.hasCoordinate()) {
        w.writeStartElement(ns(), QStringLiteral("GeoRestriction"));
        w.writeStartElement(ns(), QStringLiteral("Circle"));
        w.writeStartElement(ns(), QStringLiteral("Center"));
        w.writeTextElement(siriNS(), QStringLiteral("Longitude"), QString::number(req.location().longitude()));
        w.writeTextElement(siriNS(), QStringLiteral("Latitude"), QString::number(req.location().latitude()));
        w.writeEndElement(); // </Center>
        w.writeTextElement(ns(), QStringLiteral("Radius"), QString::number(req.maximumDistance()));
        w.writeEndElement(); // </Circle>
        w.writeEndElement(); // </GeoRestriction>
    } else {
        w.writeTextElement(ns(), QStringLiteral("LocationName"), req.location().name());
    }
    w.writeEndElement(); // </InitialInput>

    w.writeStartElement(ns(), QStringLiteral("Restrictions"));
    w.writeTextElement(ns(), QStringLiteral("Type"), QStringLiteral("stop"));
    w.writeTextElement(ns(), QStringLiteral("NumberOfResults"), QString::number(req.maximumResults()));
    // TODO ojp:Language
    w.writeEndElement(); // </Restrictions>

    w.writeEndElement(); // </LocationInformationRequest>
    writeEndServiceRequest(w);
    return output;
}

QByteArray OpenJourneyPlannerRequestBuilder::buildStopEventRequest(const StopoverRequest &req) const
{
    QByteArray output;
    QXmlStreamWriter w(&output);
    setupWriter(w);
    writeStartServiceRequest(w);
    w.writeStartElement(ns(), m_useTrias ? QStringLiteral("StopEventRequest") : QStringLiteral("OJPStopEventRequest"));
    writeRequestTimestamp(w);

    w.writeStartElement(ns(), QStringLiteral("Location"));
    writePlaceRef(w, req.stop());
    w.writeTextElement(ns(), QStringLiteral("DepArrTime"), req.dateTime().toUTC().toString(Qt::ISODate));
    w.writeEndElement(); // </Location>

    w.writeStartElement(ns(), QStringLiteral("Params"));
    w.writeTextElement(ns(), QStringLiteral("StopEventType"), req.mode() == StopoverRequest::QueryArrival ? QStringLiteral("arrival") : QStringLiteral("departure")); // "both" is also supported
    w.writeTextElement(ns(), QStringLiteral("IncludePreviousCalls"), QStringLiteral("false"));
    w.writeTextElement(ns(), QStringLiteral("IncludeOnwardCalls"), QStringLiteral("false"));
    w.writeTextElement(ns(), QStringLiteral("IncludeOperatingDays"), QStringLiteral("false"));
    w.writeTextElement(ns(), QStringLiteral("IncludeRealtimeData"), QStringLiteral("true"));
    w.writeTextElement(ns(), QStringLiteral("NumberOfResults"), QString::number(req.maximumResults()));
    w.writeEndElement(); // </Params>

    w.writeEndElement(); // </StopEventRequest>
    writeEndServiceRequest(w);
    return output;
}

struct {
    IndividualTransport::Mode mode;
    const char *ojpMode;
} static constexpr const individual_transport_modes[] = {
    { IndividualTransport::Walk, "walk" },
    { IndividualTransport::Bike, "cycle" },
    // TODO taxi, self-drive-car others-drive-car motorcycle truck
};

QByteArray OpenJourneyPlannerRequestBuilder::buildTripRequest(const JourneyRequest &req) const
{
    QByteArray output;
    QXmlStreamWriter w(&output);
    setupWriter(w);
    writeStartServiceRequest(w);
    w.writeStartElement(ns(), m_useTrias ? QStringLiteral("TripRequest") : QStringLiteral("OJPTripRequest"));
    writeRequestTimestamp(w);

    w.writeStartElement(ns(), QStringLiteral("Origin"));
    writePlaceRef(w, req.from());
    if (req.dateTimeMode() == JourneyRequest::Departure) {
        w.writeTextElement(ns(), QStringLiteral("DepArrTime"), req.dateTime().toUTC().toString(Qt::ISODate));
    }
    w.writeEndElement(); // </Origin>

    w.writeStartElement(ns(), QStringLiteral("Destination"));
    writePlaceRef(w, req.to());
    if (req.dateTimeMode() == JourneyRequest::Arrival) {
        w.writeTextElement(ns(), QStringLiteral("DepArrTime"), req.dateTime().toUTC().toString(Qt::ISODate));
    }
    w.writeEndElement(); // </Destination>

    if (!m_useTrias) {
        w.writeStartElement(ns(), QStringLiteral("IndividualTransportOptions"));
        for (const auto &accessMode : req.accessModes()) {
            const auto it = std::find_if(std::begin(individual_transport_modes), std::end(individual_transport_modes), [accessMode](const auto &m) {
                return m.mode == accessMode.mode();
            });
            if (it != std::end(individual_transport_modes)) {
                w.writeTextElement(ns(),  QStringLiteral("Mode"), QLatin1String((*it).ojpMode));
                break;
            }
        }
        w.writeEndElement(); // </IndividualTransportOptions>
    }

    w.writeStartElement(ns(), QStringLiteral("Params"));
    w.writeTextElement(ns(), QStringLiteral("IncludeTrackSections"), req.includePaths() ? QStringLiteral("true") : QStringLiteral("false"));
    w.writeTextElement(ns(), QStringLiteral("IncludeLegProjection"), req.includePaths() ? QStringLiteral("true") : QStringLiteral("false"));
    w.writeTextElement(ns(), QStringLiteral("IncludeTurnDescription"), req.includePaths() ? QStringLiteral("true") : QStringLiteral("false"));
    w.writeTextElement(ns(), QStringLiteral("IncludeAccessibility"), QStringLiteral("true")); // ???
    w.writeTextElement(ns(), QStringLiteral("IncludeIntermediateStops"), req.includeIntermediateStops() ? QStringLiteral("true") : QStringLiteral("false"));
    w.writeTextElement(ns(), QStringLiteral("IncludeFares"), QStringLiteral("false")); // TODO
    w.writeTextElement(ns(), QStringLiteral("NumberOfResults"), QString::number(req.maximumResults()));
    // TODO NumberOfResultsBefore|After for next/prev requests
    // TODO BikeTransport
    w.writeEndElement(); // </Params>

    w.writeEndElement(); // </TripRequest>
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
    if (m_useTrias) {
        w.writeNamespace(triasNS(), QStringLiteral("trias"));
        w.writeStartElement(triasNS(), QStringLiteral("Trias"));
        w.writeAttribute(QStringLiteral("version"), QStringLiteral("1.2"));
        w.writeStartElement(triasNS(), QStringLiteral("ServiceRequest"));
    } else {
        w.writeNamespace(ojpNS(), QStringLiteral("ojp"));
        w.writeStartElement(siriNS(), QStringLiteral("OJP"));
        w.writeAttribute(QStringLiteral("version"), QStringLiteral("1.0"));
        w.writeStartElement(siriNS(), QStringLiteral("OJPRequest"));
        w.writeStartElement(siriNS(), QStringLiteral("ServiceRequest"));
    }
    if (!m_requestorRef.isEmpty()) {
        w.writeTextElement(siriNS(), QStringLiteral("RequestorRef"), m_requestorRef);
    }
    writeRequestTimestamp(w);

    if (m_useTrias) {
        w.writeStartElement(ns(), QStringLiteral("RequestPayload"));
    }
}

void OpenJourneyPlannerRequestBuilder::writeEndServiceRequest(QXmlStreamWriter &w) const
{
    if (m_useTrias) {
        w.writeEndElement(); // </trias:RequestPayload>
    }
    w.writeEndElement(); // </siri:ServiceRequest>
    if (!m_useTrias) {
        w.writeEndElement(); // </siri:OJPRequest>
    }
    w.writeEndElement(); // </siri:OJP> or </siri:TRIAS>
    w.writeEndDocument();
}

void OpenJourneyPlannerRequestBuilder::writePlaceRef(QXmlStreamWriter &w, const Location &loc) const
{
    w.writeStartElement(ns(), m_useTrias ? QStringLiteral("LocationRef") : QStringLiteral("PlaceRef"));
    const auto id = loc.identifier(QStringLiteral("uic")); // ### TODO configure id type
    if (!id.isEmpty()) {
        w.writeTextElement(ns(), m_useTrias ? QStringLiteral("StopPointRef") : QStringLiteral("StopPlaceRef"), id);
    } else if (loc.hasCoordinate()) {
        w.writeStartElement(ns(), QStringLiteral("GeoPosition"));
        w.writeTextElement(siriNS(), QStringLiteral("Longitude"), QString::number(loc.longitude()));
        w.writeTextElement(siriNS(), QStringLiteral("Latitude"), QString::number(loc.latitude()));
        w.writeEndElement(); // </GeoPosition>
    }

    w.writeStartElement(ns(), QStringLiteral("LocationName"));
    w.writeTextElement(ns(), QStringLiteral("Text"), loc.name().isEmpty() ? QStringLiteral(" ") : loc.name());
    w.writeEndElement(); // </LocationName>

    w.writeEndElement(); // </PlaceRef>
}

void OpenJourneyPlannerRequestBuilder::writeRequestTimestamp(QXmlStreamWriter &w) const
{
    if (Q_UNLIKELY(m_testMode)) {
        w.writeTextElement(siriNS(), QStringLiteral("RequestTimestamp"), QDateTime({2023, 3, 24}, {12, 34, 56}, QTimeZone::UTC).toString(Qt::ISODate));
    } else {
        w.writeTextElement(siriNS(), QStringLiteral("RequestTimestamp"), QDateTime::currentDateTimeUtc().toString(Qt::ISODate));
    }
}

QString OpenJourneyPlannerRequestBuilder::ns() const
{
    return m_useTrias ? triasNS() : ojpNS();
}
