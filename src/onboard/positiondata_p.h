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
    float latitude = NAN;
    float longitude = NAN;
    float speed = NAN;
    float heading = NAN;
    QDateTime timestamp;

    // further commonly / sometimes available values: altitude, temperature
};

}

#endif // KPUBLICTRANSPORT_POSITIONDATA_H
