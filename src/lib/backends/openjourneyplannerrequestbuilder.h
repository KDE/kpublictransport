/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENJOURNEYPLANNERREQUESTBUILDER_H
#define KPUBLICTRANSPORT_OPENJOURNEYPLANNERREQUESTBUILDER_H

class QByteArray;
class QXmlStreamWriter;

namespace KPublicTransport {

class JourneyRequest;
class Location;
class LocationRequest;
class StopoverRequest;

/** Generate XML requests for Open Journey Planner and TRIAS. */
class OpenJourneyPlannerRequestBuilder
{
public:
    QByteArray buildLocationInformationRequest(const LocationRequest &req) const;
    QByteArray buildStopEventRequest(const StopoverRequest &req) const;
    QByteArray buildTripRequest(const JourneyRequest &req) const;

    /** @internal produce indented output for unit tests. */
    void setTestMode(bool testMode);

private:
    void setupWriter(QXmlStreamWriter &w) const;
    void writeStartServiceRequest(QXmlStreamWriter &w) const;
    void writeEndServiceRequest(QXmlStreamWriter &w) const;
    void writePlaceRef(QXmlStreamWriter &w, const Location &loc) const;

    bool m_testMode = false;
};

}

#endif // KPUBLICTRANSPORT_OPENJOURNEYPLANNERREQUESTBUILDER_H