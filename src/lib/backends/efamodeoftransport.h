/*
    SPDX-FileCopyrightText: 2019-2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_EFAMODEOFTRANSPORT_H
#define KPUBLICTRANSPORT_EFAMODEOFTRANSPORT_H

#include "efabackend.h"
#include <KPublicTransport/Line>

class QUrlQuery;

namespace KPublicTransport {

/** EFA mode of transport (MOT) mapping functions.
 *  Needed by both the parser and the request generation.
 */
namespace EfaModeOfTransport
{
    /** Convert "mode of transport" type id to Line::Mode */
    Line::Mode motTypeToLineMode(int mot);

    /** Convert a set of line modes to a corresponding URL query. */
    void lineModesToQuery(const std::vector<Line::Mode> &lineModes, QUrlQuery &query);
}

}

#endif // KPUBLICTRANSPORT_EFAMODEOFTRANSPORT_H
