/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LINEUTIL_P_H
#define KPUBLICTRANSPORT_LINEUTIL_P_H

#include <KPublicTransport/Line>

class QString;

namespace KPublicTransport {


namespace LineUtil
{
    [[nodiscard]] bool isSameLineNameStrict(const QString &lhs, const QString &rhs);
    [[nodiscard]] bool isSameLineNameFuzzy(const QString &lhs, const QString &rhs);

    /** Name has a high identification quality, ie. we can rely more on a name
     *  match even if e.g. the mode doesn't match that well.
     */
    [[nodiscard]] bool isHighlyIdentifyingName(QStringView s);

    [[nodiscard]] bool isCompatibleMode(Line::Mode lhs, Line::Mode rhs);
    /** Much less strict than the above, just verifies the basic mode of transport is
     *  the same (rail, road, etc)
     */
    [[nodiscard]] bool isCompatibleBaseMode(Line::Mode lhs, Line::Mode rhs);
}

}

#endif // KPUBLICTRANSPORT_LINEUTIL_H
