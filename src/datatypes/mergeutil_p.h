/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef KPUBLICTRANSPORT_MERGEUTIL_P_H
#define KPUBLICTRANSPORT_MERGEUTIL_P_H

class QDateTime;
class QString;
class QStringList;

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

    /** Normalize a note string. */
    QString normalizeNote(const QString &note);
    /** Merge two notes. */
    QStringList mergeNotes(const QStringList &lhs, const QStringList &rhs);
}

}

#endif // KPUBLICTRANSPORT_MERGEUTIL_H
