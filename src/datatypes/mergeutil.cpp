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

#include "mergeutil_p.h"

#include <QDateTime>
#include <QDebug>
#include <QString>
#include <QTimeZone>

using namespace KPublicTransport;

int MergeUtil::distance(const QDateTime& lhs, const QDateTime& rhs)
{
    if (lhs.timeSpec() == Qt::LocalTime && rhs.timeSpec() == Qt::TimeZone) {
        auto dt = lhs;
        dt.setTimeZone(rhs.timeZone());
        return std::abs(dt.secsTo(rhs));
    }
    if (lhs.timeSpec() == Qt::TimeZone && rhs.timeSpec() == Qt::LocalTime) {
        auto dt = rhs;
        dt.setTimeZone(lhs.timeZone());
        return std::abs(dt.secsTo(lhs));
    }

    return std::abs(lhs.secsTo(rhs));
}

bool MergeUtil::isBefore(const QDateTime& lhs, const QDateTime& rhs)
{
    if (lhs.timeSpec() == Qt::LocalTime && rhs.timeSpec() == Qt::TimeZone) {
        auto dt = lhs;
        dt.setTimeZone(rhs.timeZone());
        return dt < rhs;
    }
    if (lhs.timeSpec() == Qt::TimeZone && rhs.timeSpec() == Qt::LocalTime) {
        auto dt = rhs;
        dt.setTimeZone(lhs.timeZone());
        return lhs < dt;
    }

    return lhs < rhs;
}

QDateTime MergeUtil::mergeDateTimeEqual(const QDateTime &lhs, const QDateTime &rhs)
{
    // if only one side is valid, prefer that one
    if (!lhs.isValid()) {
        return rhs;
    }
    if (!rhs.isValid()) {
        return lhs;
    }

    // if one side has tz, prefer that
    if (lhs.timeSpec() != Qt::TimeZone && rhs.timeSpec() == Qt::TimeZone) {
        return rhs;
    }
    return lhs;
}

QDateTime MergeUtil::mergeDateTimeMax(const QDateTime &lhs, const QDateTime &rhs)
{
    // if only one side is valid, prefer that one
    if (!lhs.isValid()) {
        return rhs;
    }
    if (!rhs.isValid()) {
        return lhs;
    }

    auto dt = isBefore(lhs, rhs) ? rhs : lhs;
    if (dt.timeSpec() == Qt::TimeZone) {
        return dt;
    }

    if (lhs.timeSpec() == Qt::TimeZone) {
        dt.setTimeZone(lhs.timeZone());
    } else if (rhs.timeSpec() == Qt::TimeZone) {
        dt.setTimeZone(rhs.timeZone());
    }
    return dt;
}

QString MergeUtil::mergeString(const QString &lhs, const QString &rhs)
{
    // ### this is deterministic, but not necessarily ideal
    // we could prefer mixed case over all caps, unicode over transliterated, etc
    if (lhs.size() == rhs.size()) {
        return lhs < rhs ? lhs : rhs;
    }
    return lhs.size() < rhs.size() ? rhs : lhs;
}
