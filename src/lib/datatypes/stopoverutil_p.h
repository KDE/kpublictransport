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

#ifndef KPUBLICTRANSPORT_STOPOVERUTIL_P_H
#define KPUBLICTRANSPORT_STOPOVERUTIL_P_H

class QTimeZone;

namespace KPublicTransport {

class DepartureRequest;
class Stopover;

/** Internal methods around Stopover objects. */
namespace StopoverUtil
{
    /** Request specific time-based sorting/comparison. */
    bool timeLessThan(const DepartureRequest &req, const Stopover &lhs, const Stopover &rhs);
    bool timeEqual(const DepartureRequest &req, const Stopover &lhs, const Stopover &rhs);

    /** Reinterpret all floating times as times with the given timezone. */
    void applyTimeZone(Stopover &dep, const QTimeZone &tz);
    /** Augment line meta data. */
    void applyMetaData(Stopover &dep, bool download);
}

}

#endif // KPUBLICTRANSPORT_STOPOVERUTIL_H
