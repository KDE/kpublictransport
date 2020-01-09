/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H
#define KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H

#include <KPublicTransport/Departure>
#include <KPublicTransport/Journey>

class QJsonObject;

namespace KPublicTransport {

/** Parser for OTP responses as defined by the GraphQL files in the otp/ subdir. */
namespace OpenTripPlannerParser
{
    std::vector<Departure> parseDepartures(const QJsonObject &obj);
    std::vector<Journey> parseJourneys(const QJsonObject &obj);
}

}

#endif // KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H
