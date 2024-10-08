/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_DEUTSCHEBAHNVEHICLELAYOUTPARSER_H
#define KPUBLICTRANSPORT_DEUTSCHEBAHNVEHICLELAYOUTPARSER_H

#include <KPublicTransport/Platform>
#include <KPublicTransport/Vehicle>
#include <KPublicTransport/Reply>
#include <KPublicTransport/Stopover>

class QByteArray;

namespace KPublicTransport {

/** Parser for vehicle layout responses from Deutsche Bahn. */
class DeutscheBahnVehicleLayoutParser
{
public:
    [[nodiscard]] static Stopover parse(const QByteArray &data);

private:
    static void parseVehicleSection(Vehicle &vehicle, const QJsonObject &obj, const Platform &platform);
    static void parsePlatformSection(Platform &platform, const QJsonObject &obj);
    static void fillMissingPositions(Vehicle &vehicle, Platform &platform);
};

}

#endif // KPUBLICTRANSPORT_DEUTSCHEBAHNVEHICLELAYOUTPARSER_H
