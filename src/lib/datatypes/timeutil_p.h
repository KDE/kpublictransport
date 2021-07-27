/*
    SPDX-FileCopyrightText: 2019-2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_TIMEUTIL_P_H
#define KPUBLICTRANSPORT_TIMEUTIL_P_H

class QDateTime;
class QTimeZone;

namespace KPublicTransport {

/** Utilities for dealing with date/time values. */
namespace TimeUtil
{
    QDateTime applyTimeZone(QDateTime dt, const QTimeZone &tz);
}

}

#endif // KPUBLICTRANSPORT_TIMEUTIL_P_H
