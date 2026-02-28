/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENJOURNEYPLANNERREQUESTBUILDER_H
#define KPUBLICTRANSPORT_OPENJOURNEYPLANNERREQUESTBUILDER_H

#include <QString>

class QXmlStreamWriter;

namespace KPublicTransport {

class JourneyRequest;
class Location;
class LocationRequest;
class StopoverRequest;
class TripRequest;

/** Generate XML requests for Open Journey Planner and TRIAS. */
class OpenJourneyPlannerRequestBuilder
{
public:
    explicit OpenJourneyPlannerRequestBuilder();
    ~OpenJourneyPlannerRequestBuilder();

    void setRequestorRef(const QString &ref);
    void setIdentifierType(const QString &identifierType);

    /** Specify which protocol flavor the output is for. */
    enum Protocol {
        OJP1,
        OJP2,
        TRIAS,
    };
    void setProtocol(Protocol protocol);

    [[nodiscard]] QByteArray buildLocationInformationRequest(const LocationRequest &req) const;
    [[nodiscard]] QByteArray buildStopEventRequest(const StopoverRequest &req) const;
    [[nodiscard]] QByteArray buildTripRequest(const JourneyRequest &req) const;
    [[nodiscard]] QByteArray buildTripInfoRequest(const TripRequest &req) const;

    /** @internal produce indented output for unit tests. */
    void setTestMode(bool testMode);

private:
    void setupWriter(QXmlStreamWriter &w) const;
    void writeStartServiceRequest(QXmlStreamWriter &w) const;
    void writeEndServiceRequest(QXmlStreamWriter &w) const;
    void writePlaceRef(QXmlStreamWriter &w, const Location &loc) const;
    void writeRequestTimestamp(QXmlStreamWriter &w) const;

    [[nodiscard]] QString ns() const;
    [[nodiscard]] bool isTrias() const;

    QString m_requestorRef;
    QString m_identifierType;
    Protocol m_protocol = OJP1;
    bool m_testMode = false;
};

}

#endif // KPUBLICTRANSPORT_OPENJOURNEYPLANNERREQUESTBUILDER_H
