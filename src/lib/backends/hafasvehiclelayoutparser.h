/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_HAFASVEHICLELAYOUTPARSER_H
#define KPUBLICTRANSPORT_HAFASVEHICLELAYOUTPARSER_H

class QByteArray;

namespace KPublicTransport {

class Platform;
class Vehicle;

/** Parser for vehicle and platform layout responses embedded in Hafas remark messages. */
namespace HafasVehicleLayoutParser
{
    /** Parses a I - JF remark containing JSON train formation data. */
    Vehicle parseTrainFormation(const QByteArray &data);
    /** Parses a I - XP remark containing XML platform sector data. */
    Platform parsePlatformSectors(const QByteArray &data);
}

}

#endif // KPUBLICTRANSPORT_HAFASVEHICLELAYOUTPARSER_H
