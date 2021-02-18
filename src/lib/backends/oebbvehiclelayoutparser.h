/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OEBBVEHICLELAYOUTPARSER_H
#define KPUBLICTRANSPORT_OEBBVEHICLELAYOUTPARSER_H

#include <KPublicTransport/Platform>
#include <KPublicTransport/Vehicle>
#include <KPublicTransport/Stopover>

class QByteArray;

namespace KPublicTransport {

/** Parser for vehicle layout responses from ÖBB. */
class OebbVehicleLayoutParser
{
public:
    bool parse(const QByteArray &data);

    Stopover stopover;
};

}

#endif // KPUBLICTRANSPORT_OEBBVEHICLELAYOUTPARSER_H
