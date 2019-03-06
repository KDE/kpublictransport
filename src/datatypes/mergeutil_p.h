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

namespace KPublicTransport {

/** Utilities for merging objects. */
namespace MergeUtil
{
    /** Compare the two given times.
     *  Additionally to equal comparison as done by QDateTime, this also considers
     *  The case of comparing a time with timezone and one specified in local time *at the destination*
     *  without timezone. Ie. this assumes that the two times you are comparing are for the same location.
     */
    bool isSameTime(const QDateTime &lhs, const QDateTime &rhs);
    /** Same as the above, just for lessThan comparison. */
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
