/*
    SPDX-FileCopyrightText: 2019-2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "timeutil_p.h"

#include <QDateTime>
#include <QTimeZone>

using namespace KPublicTransport;

QDateTime TimeUtil::applyTimeZone(QDateTime dt, const QTimeZone &tz)
{
    if (!dt.isValid()) {
        return dt;
    }
    switch (dt.timeSpec()) {
        case Qt::LocalTime:
            dt.setTimeZone(tz);
            break;
        case Qt::UTC:
            dt = dt.toTimeZone(tz);
            break;
        default:
            break;
    }
    return dt;
}
