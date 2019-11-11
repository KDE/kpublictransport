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

#ifndef KPUBLICTRANSPORT_EFACOMPACTPARSER_H
#define KPUBLICTRANSPORT_EFACOMPACTPARSER_H

#include "efaparser.h"

namespace KPublicTransport {

/** Parser for compact XML responses from EFA services.
 * @internal just exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT EfaCompactParser : public EfaParser
{
public:
    std::vector<Location> parseStopFinderResponse(const QByteArray &data) const;
    std::vector<Departure> parseDmResponse(const QByteArray &data) const;
    std::vector<Journey> parseTripResponse(const QByteArray &data) const;

private:
    Location parseCompactSf(QXmlStreamReader &reader) const;
    Departure parseCompactDp(QXmlStreamReader &reader) const;
};

}

#endif // KPUBLICTRANSPORT_EFACOMPACTPARSER_H
