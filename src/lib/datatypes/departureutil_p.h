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

#ifndef KPUBLICTRANSPORT_DEPARTUREUTIL_P_H
#define KPUBLICTRANSPORT_DEPARTUREUTIL_P_H

class QTimeZone;

namespace KPublicTransport {

class Departure;
class DepartureRequest;

/** Internal methods around Departure. */
namespace DepartureUtil
{
    /** Request specific time-based sorting/comparison. */
    bool timeLessThan(const DepartureRequest &req, const Departure &lhs, const Departure &rhs);
    bool timeEqual(const DepartureRequest &req, const Departure &lhs, const Departure &rhs);

    /** Reinterpret all floating times as times with the given timezone. */
    void applyTimeZone(Departure &dep, const QTimeZone &tz);
    /** Augment line meta data. */
    void applyMetaData(Departure &dep, bool download);
}

}

#endif // KPUBLICTRANSPORT_DEPARTUREUTIL_H
