/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_HAFASQUERYBACKEND_H
#define KPUBLICTRANSPORT_HAFASQUERYBACKEND_H

#include "hafasbackend.h"
#include "hafasqueryparser.h"

namespace KPublicTransport {

/** Backends for the Hafas "query.exe" based providers. */
class HafasQueryBackend : public HafasBackend
{
    Q_GADGET
public:
    HafasQueryBackend();
    ~HafasQueryBackend();

    void init() override;
    static inline constexpr const char* type() { return "hafasQuery"; }
    Capabilities capabilities() const override;
    bool needsLocationQuery(const Location &loc, QueryType type) const override;
    bool queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const override;
    bool queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    bool queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const override;

private:
    bool queryLocationByName(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const;
    bool queryLocationByCoordinate(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const;

    QString locationId(const Location &loc) const;

    mutable HafasQueryParser m_parser;
};

}

#endif // KPUBLICTRANSPORT_HAFASQUERYBACKEND_H
