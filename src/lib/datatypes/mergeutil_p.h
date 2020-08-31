/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_MERGEUTIL_P_H
#define KPUBLICTRANSPORT_MERGEUTIL_P_H

class QDateTime;
class QString;

namespace KPublicTransport {

/** Utilities for merging objects. */
namespace MergeUtil
{
    /** Compute the absolute difference in seconds between the two given times.
     *  Times without timezone are assumed to be in local time *at the destination*,
     *  not in current local timezone. This matters when comparing against a time
     *  with a specified timezone.
     */
    int distance(const QDateTime &lhs, const QDateTime &rhs);
    /** lessThan comparison of the given times, with the above timezone semantics. */
    bool isBefore(const QDateTime &lhs, const QDateTime &rhs);

    /** Assumes lhs == rhs if both sides are valid, and prefers values with timezone information. */
    QDateTime mergeDateTimeEqual(const QDateTime &lhs, const QDateTime &rhs);

    /** Takes the later time if both sides are valid, and tries to preserve timezone information. */
    QDateTime mergeDateTimeMax(const QDateTime &lhs, const QDateTime &rhs);

    /** Takes the longer input string. */
    QString mergeString(const QString &lhs, const QString &rhs);
}

}

#endif // KPUBLICTRANSPORT_MERGEUTIL_H
