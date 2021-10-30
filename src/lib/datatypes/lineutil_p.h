/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
    bool isSameLineNameStrict(const QString &lhs, const QString &rhs);
    bool isSameLineNameFuzzy(const QString &lhs, const QString &rhs);
    bool isCompatibleMode(Line::Mode lhs, Line::Mode rhs);
}

}

#endif // KPUBLICTRANSPORT_LINEUTIL_H
