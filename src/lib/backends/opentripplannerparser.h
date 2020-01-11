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

#include "kpublictransport_export.h"

#include <vector>

class QJsonObject;

namespace KPublicTransport {

class Departure;
class Journey;
class Location;

/** Parser for OTP responses as defined by the GraphQL files in the otp/ subdir.
 *  @internal only exported for unit tests
 */
namespace OpenTripPlannerParser
{
    KPUBLICTRANSPORT_EXPORT std::vector<Location> parseLocationsByCoordinate(const QJsonObject &obj);
    KPUBLICTRANSPORT_EXPORT std::vector<Location> parseLocationsByName(const QJsonObject &obj);
    KPUBLICTRANSPORT_EXPORT std::vector<Departure> parseDepartures(const QJsonObject &obj);
    KPUBLICTRANSPORT_EXPORT std::vector<Journey> parseJourneys(const QJsonObject &obj);
}

}

#endif // KPUBLICTRANSPORT_OPENTRIPPLANNERPARSER_H
