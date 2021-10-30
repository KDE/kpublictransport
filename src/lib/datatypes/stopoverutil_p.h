/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_STOPOVERUTIL_P_H
#define KPUBLICTRANSPORT_STOPOVERUTIL_P_H

class QTimeZone;

namespace KPublicTransport {

class Stopover;
class StopoverRequest;

/** Internal methods around Stopover objects. */
namespace StopoverUtil
{
    /** Request specific time-based sorting/comparison. */
    bool timeLessThan(const StopoverRequest &req, const Stopover &lhs, const Stopover &rhs);
    bool timeEqual(const StopoverRequest &req, const Stopover &lhs, const Stopover &rhs);

    /** Reinterpret all floating times as times with the given timezone. */
    void applyTimeZone(Stopover &dep, const QTimeZone &tz);
}

}

#endif // KPUBLICTRANSPORT_STOPOVERUTIL_H
