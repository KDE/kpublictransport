/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_EFAPARSER_H
#define KPUBLICTRANSPORT_EFAPARSER_H

#include <KPublicTransport/Reply>

#include <QHash>
#include <QString>

#include <vector>

class QByteArray;
class QXmlStreamReader;

namespace KPublicTransport {

class Departure;
class Journey;
class JourneySection;
class Location;

/** Parser for responses from EFA services. */
class EfaParser
{
public:
    void setLocationIdentifierType(const  QString &locationIdentifierType);

    std::vector<Location> parseStopFinderResponse(const QByteArray &data) const;
    std::vector<Departure> parseDmResponse(const QByteArray &data) const;
    std::vector<Journey> parseTripResponse(const QByteArray &data) const;

    Reply::Error error() const;
    QString errorMessage() const;

private:
    Location parseItdOdvAssignedStop(QXmlStreamReader &reader) const;
    Departure parseDmDeparture(QXmlStreamReader &reader) const;
    void parseTripDeparture(QXmlStreamReader &reader, JourneySection &section) const;
    void parseTripArrival(QXmlStreamReader &reader, JourneySection &section) const;
    JourneySection parseTripPartialRoute(QXmlStreamReader &reader) const;
    Journey parseTripRoute(QXmlStreamReader &reader) const;

    QString m_locationIdentifierType;
    mutable QString m_errorMsg;
    mutable Reply::Error m_error = Reply::NoError;
    mutable QHash<QString, Location> m_locations;
};

}

#endif // KPUBLICTRANSPORT_EFAPARSER_H
