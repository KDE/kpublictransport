/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_HAFASVEHICLELAYOUTPARSER_H
#define KPUBLICTRANSPORT_HAFASVEHICLELAYOUTPARSER_H

#include <vector>

class QByteArray;
class QJsonObject;

namespace KPublicTransport {

class Platform;
class Vehicle;

/** Parser for vehicle and platform layout responses embedded in Hafas remark messages. */
namespace HafasVehicleLayoutParser
{
    /** Parses vehicle layout data from common.stcXXXL responses. */
    std::vector<Vehicle> parseVehicleLayouts(const QJsonObject &commonObj);

    /** Parses a I - JF remark containing JSON train formation data. */
    Vehicle parseTrainFormation(const QByteArray &data);

    /** Parses platform data from common.tcpdL in Hafas journey responses. */
    std::vector<Platform> parsePlatforms(const QJsonObject &commonObj);

    /** Parses a I - XP remark containing XML platform sector data. */
    Platform parsePlatformSectors(const QByteArray &data);
}

}

#endif // KPUBLICTRANSPORT_HAFASVEHICLELAYOUTPARSER_H
