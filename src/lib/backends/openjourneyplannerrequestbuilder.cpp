/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "openjourneyplannerrequestbuilder.h"

#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/StopoverRequest>
#include <KPublicTransport/TripRequest>

#include <QByteArray>
#include <QDateTime>
#include <QDebug>
#include <QTimeZone>
#include <QXmlStreamWriter>

using namespace Qt::Literals;
using namespace KPublicTransport;

static constexpr auto siriNS() { return "http://www.siri.org.uk/siri"_L1; }
static constexpr auto ojpNS() { return "http://www.vdv.de/ojp"_L1; }
static constexpr auto triasNS() { return "http://www.vdv.de/trias"_L1; }

OpenJourneyPlannerRequestBuilder::OpenJourneyPlannerRequestBuilder() = default;
OpenJourneyPlannerRequestBuilder::~OpenJourneyPlannerRequestBuilder() = default;

void OpenJourneyPlannerRequestBuilder::setRequestorRef(const QString &ref)
{
    m_requestorRef = ref;
}

void OpenJourneyPlannerRequestBuilder::setIdentifierType(const QString &identifierType)
{
    m_identifierType = identifierType;
}

void OpenJourneyPlannerRequestBuilder::setProtocol(Protocol protocol)
{
    m_protocol = protocol;
}

void OpenJourneyPlannerRequestBuilder::setSupportedModes(const std::vector<Siri::Mode> *modes)
{
    m_supportedModes = modes;
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
    w.writeStartElement(ns(), isTrias() ?  "LocationInformationRequest" : "OJPLocationInformationRequest");
    writeRequestTimestamp(w);

    w.writeStartElement(ns(), "InitialInput");
    if (req.hasCoordinate()) {
        w.writeStartElement(ns(), "GeoRestriction");
        w.writeStartElement(ns(), "Circle");
        w.writeStartElement(ns(), "Center");
        w.writeTextElement(siriNS(), "Longitude", QString::number(req.location().longitude()));
        w.writeTextElement(siriNS(), "Latitude", QString::number(req.location().latitude()));
        w.writeEndElement(); // </Center>
        w.writeTextElement(ns(), "Radius", QString::number(req.maximumDistance()));
        w.writeEndElement(); // </Circle>
        w.writeEndElement(); // </GeoRestriction>
    } else {
        w.writeTextElement(ns(), m_protocol == OJP2 ? "Name" : "LocationName", req.location().name());
    }
    w.writeEndElement(); // </InitialInput>

    w.writeStartElement(ns(), "Restrictions");
    w.writeTextElement(ns(), "Type", "stop");
    w.writeTextElement(ns(), "NumberOfResults", QString::number(req.maximumResults()));
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
    w.writeStartElement(ns(), isTrias() ? "StopEventRequest" : "OJPStopEventRequest");
    writeRequestTimestamp(w);

    w.writeStartElement(ns(), "Location");
    writePlaceRef(w, req.stop());
    w.writeTextElement(ns(), "DepArrTime", req.dateTime().toUTC().toString(Qt::ISODate));
    w.writeEndElement(); // </Location>

    w.writeStartElement(ns(), "Params");
    w.writeTextElement(ns(), "StopEventType", req.mode() == StopoverRequest::QueryArrival ? "arrival" : "departure"); // "both" is also supported
    w.writeTextElement(ns(), "IncludePreviousCalls", "false");
    w.writeTextElement(ns(), "IncludeOnwardCalls", "false");
    w.writeTextElement(ns(), "IncludeOperatingDays", "false");
    w.writeTextElement(ns(), "IncludeRealtimeData", "true");
    w.writeTextElement(ns(), "NumberOfResults", QString::number(req.maximumResults()));
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

QByteArray OpenJourneyPlannerRequestBuilder::buildTripRequest(const JourneyRequest &req, const QDateTime &contextDt, PagingMode pageMode) const
{
    QByteArray output;
    QXmlStreamWriter w(&output);
    setupWriter(w);
    writeStartServiceRequest(w);
    w.writeStartElement(ns(), isTrias() ? "TripRequest" : "OJPTripRequest");
    writeRequestTimestamp(w);

    const auto dt = ((contextDt.isValid() && pageMode != None) ? contextDt : req.dateTime()).toUTC();

    w.writeStartElement(ns(), "Origin");
    writePlaceRef(w, req.from());
    if (req.dateTimeMode() == JourneyRequest::Departure) {
        w.writeTextElement(ns(), "DepArrTime", dt.toString(Qt::ISODate));
    }
    w.writeEndElement(); // </Origin>

    w.writeStartElement(ns(), "Destination");
    writePlaceRef(w, req.to());
    if (req.dateTimeMode() == JourneyRequest::Arrival) {
        w.writeTextElement(ns(), "DepArrTime", dt.toString(Qt::ISODate));
    }
    w.writeEndElement(); // </Destination>

    if (m_protocol == OJP1) {
        w.writeStartElement(ns(), "IndividualTransportOptions");
        for (const auto &accessMode : req.accessModes()) {
            const auto it = std::find_if(std::begin(individual_transport_modes), std::end(individual_transport_modes), [accessMode](const auto &m) {
                return m.mode == accessMode.mode();
            });
            if (it != std::end(individual_transport_modes)) {
                w.writeTextElement(ns(),  "Mode", QLatin1String((*it).ojpMode));
                break;
            }
        }
        w.writeEndElement(); // </IndividualTransportOptions>
    }

    w.writeStartElement(ns(), "Params");
    w.writeTextElement(ns(), "IncludeTrackSections", req.includePaths() ? "true" : "false");
    w.writeTextElement(ns(), "IncludeLegProjection", req.includePaths() ? "true" : "false");
    w.writeTextElement(ns(), "IncludeTurnDescription", req.includePaths() ? "true" : "false");
    w.writeTextElement(ns(), "IncludeAccessibility", "true"); // ???
    w.writeTextElement(ns(), "IncludeIntermediateStops", req.includeIntermediateStops() ? "true" : "false");
    w.writeTextElement(ns(), "IncludeFares", "false"); // TODO
    switch (pageMode) {
        case None:
            w.writeTextElement(ns(), "NumberOfResults", QString::number(req.maximumResults()));
            break;
        case After:
            w.writeTextElement(ns(), "NumberOfResultsAfter", QString::number(req.maximumResults()));
            break;
        case Before:
            w.writeTextElement(ns(), "NumberOfResultsBefore", QString::number(req.maximumResults()));
            break;
    }
    // TODO BikeTransport

    if (m_protocol == OJP2 && !req.lineModes().empty() && m_supportedModes) {
        const auto excludedModes = Siri::Mode::intersection(Siri::Mode::fromModes(req.invertedLineModes()), *m_supportedModes);
        for (const auto &m : excludedModes) {
            w.writeStartElement(ns(), "ModeAndModeOfOperationFilter");
            w.writeTextElement(ns(), "Exclude", "true");
            if (m.hasSubmode()) {
                w.writeTextElement(siriNS(), m.submodeTypeName(), m.submodeString());
            } else {
                w.writeTextElement(ns(), "PtMode", m.modeString());
            }
            w.writeEndElement();
        }
    }

    w.writeEndElement(); // </Params>

    w.writeEndElement(); // </TripRequest>
    writeEndServiceRequest(w);
    return output;
}

QByteArray OpenJourneyPlannerRequestBuilder::buildTripInfoRequest(const TripRequest &req) const
{
    QByteArray output;
    QXmlStreamWriter w(&output);
    setupWriter(w);
    writeStartServiceRequest(w);
    w.writeStartElement(ns(), "OJPTripInfoRequest");
    writeRequestTimestamp(w);

    const auto id = req.identifier(m_identifierType);
    const auto idx = id.lastIndexOf('|'_L1);
    if (idx > 0) {
        w.writeTextElement(ns(), "JourneyRef", QStringView(id).left(idx));
        w.writeTextElement(ns(), "OperatingDayRef", QStringView(id).mid(idx + 1));
    }

    w.writeStartElement(ns(), "Params");
    w.writeTextElement(ns(), "IncludeTrackSections", "true");
    w.writeTextElement(ns(), "IncludeTrackProjection", "true");
    w.writeEndElement(); // </Params>

    w.writeEndElement(); // </OJPTripInfoRequest>
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
    w.writeNamespace(siriNS(), "siri");
    switch (m_protocol) {
    case OJP1:
        w.writeNamespace(ojpNS(), "ojp");
        w.writeStartElement(siriNS(), "OJP");
        w.writeAttribute("version", "1.0");
        w.writeStartElement(siriNS(), "OJPRequest");
        w.writeStartElement(siriNS(), "ServiceRequest");
        break;
    case OJP2:
        w.writeNamespace(ojpNS(), "ojp");
        w.writeStartElement(ojpNS(), "OJP");
        w.writeAttribute("version", "2.0");
        w.writeStartElement(ojpNS(), "OJPRequest");
        w.writeStartElement(siriNS(), "ServiceRequest");
        break;
    case TRIAS:
        w.writeNamespace(triasNS(), "trias");
        w.writeStartElement(triasNS(), "Trias");
        w.writeAttribute("version", "1.2");
        w.writeStartElement(triasNS(), "ServiceRequest");
        break;
    }
    if (!m_requestorRef.isEmpty()) {
        w.writeTextElement(siriNS(), "RequestorRef", m_requestorRef);
    }
    writeRequestTimestamp(w);

    if (isTrias()) {
        w.writeStartElement(ns(), "RequestPayload");
    }
}

void OpenJourneyPlannerRequestBuilder::writeEndServiceRequest(QXmlStreamWriter &w) const
{
    if (isTrias()) {
        w.writeEndElement(); // </trias:RequestPayload>
    }
    w.writeEndElement(); // </siri:ServiceRequest>
    if (!isTrias()) {
        w.writeEndElement(); // </siri:OJPRequest>
    }
    w.writeEndElement(); // </siri:OJP> or </siri:TRIAS>
    w.writeEndDocument();
}

void OpenJourneyPlannerRequestBuilder::writePlaceRef(QXmlStreamWriter &w, const Location &loc) const
{
    w.writeStartElement(ns(), isTrias() ? "LocationRef" : "PlaceRef");
    const auto id = loc.identifier(QStringLiteral("uic")); // ### TODO configure id type
    if (!id.isEmpty()) {
        switch (m_protocol) {
        case OJP1:
            w.writeTextElement(ns(), "StopPlaceRef", id);
            break;
        case OJP2:
            w.writeTextElement(siriNS(), "StopPointRef", id);
            break;
        case TRIAS:
            w.writeTextElement(ns(), "StopPointRef", id);
            break;
        }
    } else if (loc.hasCoordinate()) {
        w.writeStartElement(ns(), "GeoPosition");
        w.writeTextElement(siriNS(), "Longitude", QString::number(loc.longitude()));
        w.writeTextElement(siriNS(), "Latitude", QString::number(loc.latitude()));
        w.writeEndElement(); // </GeoPosition>
    }

    w.writeStartElement(ns(), m_protocol == OJP2 ? "Name" : "LocationName");
    w.writeTextElement(ns(), "Text", loc.name().isEmpty() ? QStringLiteral(" ") : loc.name());
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
    return isTrias() ? triasNS() : ojpNS();
}

bool OpenJourneyPlannerRequestBuilder::isTrias() const
{
    return m_protocol == TRIAS;
}
