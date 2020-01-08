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
#include <QUrl>

using namespace KPublicTransport;

static QDateTime applyTimeZone(QDateTime dt, const QDateTime &refDt)
{
    if (dt.timeSpec() != Qt::LocalTime) {
        return dt;
    }

    if (refDt.timeSpec() == Qt::TimeZone) {
        dt.setTimeZone(refDt.timeZone());
    } else if (refDt.timeSpec() == Qt::OffsetFromUTC) {
        dt.setOffsetFromUtc(refDt.offsetFromUtc());
    }

    return dt;
}

int MergeUtil::distance(const QDateTime& lhs, const QDateTime& rhs)
{
    const auto ldt = applyTimeZone(lhs, rhs);
    const auto rdt = applyTimeZone(rhs, lhs);
    return std::abs(ldt.secsTo(rdt));
}

bool MergeUtil::isBefore(const QDateTime& lhs, const QDateTime& rhs)
{
    const auto ldt = applyTimeZone(lhs, rhs);
    const auto rdt = applyTimeZone(rhs, lhs);
    return ldt < rdt;
}

QDateTime MergeUtil::mergeDateTimeEqual(const QDateTime &lhs, const QDateTime &rhs)
{
    // anything is better than invalid, timezone is best
    if (!rhs.isValid() || lhs.timeSpec() == Qt::TimeZone) {
        return lhs;
    }
    if (!lhs.isValid() || rhs.timeSpec() == Qt::TimeZone) {
        return rhs;
    }

    // UTC offset it better than local time
    if (lhs.timeSpec() == Qt::OffsetFromUTC || rhs.timeSpec() == Qt::LocalTime) {
        return lhs;
    }
    return rhs;
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

    // recover timezone of we can
    if (lhs.timeSpec() == Qt::TimeZone) {
        dt.setTimeZone(lhs.timeZone());
        return dt;
    } else if (rhs.timeSpec() == Qt::TimeZone) {
        dt.setTimeZone(rhs.timeZone());
        return dt;
    }

    // recover UTC offset if we can
    if (dt.timeSpec() == Qt::OffsetFromUTC) {
        return dt;
    } else if (lhs.timeSpec() == Qt::OffsetFromUTC) {
        dt.setOffsetFromUtc(lhs.offsetFromUtc());
    } else if (rhs.timeSpec() == Qt::OffsetFromUTC) {
        dt.setOffsetFromUtc(rhs.offsetFromUtc());
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
