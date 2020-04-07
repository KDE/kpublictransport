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

#ifndef KPUBLICTRANSPORT_LINEUTIL_P_H
#define KPUBLICTRANSPORT_LINEUTIL_P_H

#include <KPublicTransport/Line>

class QString;

namespace KPublicTransport {

class LineMetaData;
class Location;

namespace LineUtil
{
    bool isSameLineName(const QString &lhs, const QString &rhs);
    bool isCompatibleMode(Line::Mode lhs, Line::Mode rhs);
    void applyMetaData(Line &line, const Location &loc, bool download);
    void setMetaData(Line &line, LineMetaData metaData);
}

}

#endif // KPUBLICTRANSPORT_LINEUTIL_H
