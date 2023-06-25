/*
    SPDX-FileCopyrightText: 2018-2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_NAVITIAPHYSICALMODE_H
#define KPUBLICTRANSPORT_NAVITIAPHYSICALMODE_H

#include <KPublicTransport/Line>

class QStringView;
class QUrlQuery;

namespace KPublicTransport {

/** Navitia physical modes (line modes in our speak) translation functions. */
namespace NavitiaPhysicalMode
{
    /** Convert "physical mode" to Line::Mode */
    Line::Mode parsePhysicalMode(QStringView mode);

    /** Convert a set of line modes to a corresponding URL query. */
    void lineModesToQuery(const std::vector<Line::Mode> &lineModes, QUrlQuery &query);
}

}

#endif // KPUBLICTRANSPORT_NAVITIAPHYSICALMODE_H
