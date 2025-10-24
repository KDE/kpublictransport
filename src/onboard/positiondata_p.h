/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_POSITIONDATA_H
#define KPUBLICTRANSPORT_POSITIONDATA_H

#include <QDateTime>

#include <cmath>

namespace KPublicTransport {

/** Current position reading. */
class PositionData
{
public:
    [[nodiscard]] bool hasCoordinate() const
    {
        return !std::isnan(latitude) && !std::isnan(longitude) && latitude >= -90.0f && latitude <= 90.0f && longitude >= -180.0f && longitude <= 180.0f;
    }

    float latitude = NAN;
    float longitude = NAN;
    float speed = NAN; // km/h
    float heading = NAN; // degree
    float altitude = NAN; // meter
    QDateTime timestamp;

    // further commonly / sometimes available values: altitude, temperature
};

}

#endif // KPUBLICTRANSPORT_POSITIONDATA_H
