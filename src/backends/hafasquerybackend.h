/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
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
    Q_PROPERTY(bool departureQuerySupported MEMBER m_departureQuerySupported)
public:
    HafasQueryBackend();
    ~HafasQueryBackend();

    void init() override;
    Capabilities capabilities() const override;
    bool needsLocationQuery(const Location &loc, QueryType type) const override;
    bool queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const override;
    bool queryDeparture(const DepartureRequest &request, DepartureReply *reply, QNetworkAccessManager *nam) const override;
    bool queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const override;

private:
    bool queryLocationByName(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const;
    bool queryLocationByCoordinate(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const;

    QString locationId(const Location &loc) const;

    mutable HafasQueryParser m_parser;
    bool m_departureQuerySupported = true;
};

}

#endif // KPUBLICTRANSPORT_HAFASQUERYBACKEND_H
