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

#include "efaparser.h"
#include "logging.h"

using namespace KPublicTransport;

EfaParser::~EfaParser() = default;

void EfaParser::setLocationIdentifierType(const QString& locationIdentifierType)
{
    m_locationIdentifierType = locationIdentifierType;
}

Reply::Error EfaParser::error() const
{
    return m_error;
}

QString EfaParser::errorMessage() const
{
    return m_errorMsg;
}

Line::Mode EfaParser::motTypeToLineMode(int mot)
{
    // comments below are EFA names found in XML responses (usually translated)
    // the mapping isn't necessary 100% obvious everywhere
    switch (mot) {
        case 0: return Line::Train;
        case 1: return Line::RapidTransit; // "Commuter railway"
        case 2: return Line::Metro; // "Subway"
        case 3: return Line::RapidTransit; // "City rail" / "Stadtbahn"
        case 4: return Line::Tramway;
        case 5: return Line::Bus;
        case 6: return Line::Bus; // "Regional bus"
        case 7: return Line::BusRapidTransit; // "Express bus"
        case 8: return Line::Funicular; // "Cable car/Rack railway"
        case 9: return Line::Ferry;
        case 10: return Line::Taxi; // "Taxi on demand"
        case 11: return Line::Unknown; // "Other"
        case 12: return Line::Air; // "Airplane"
        case 13: return Line::LocalTrain;
        case 14:
        case 15:
        case 16:
            return Line::LongDistanceTrain; // "Train (intercity)"
        case 17: return Line::Bus; // "Rail replacement service"
        case 18: return Line::Train; // "Rail shuttle"
        case 19: return Line::Bus; // "Peoples bus" / "Bürgerbus"
    }
    qCDebug(Log) << "Unknown means ot transport: " << mot;
    return Line::Unknown;
}
