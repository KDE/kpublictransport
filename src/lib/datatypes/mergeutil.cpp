/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
        dt.setTimeZone(QTimeZone::fromSecondsAheadOfUtc(refDt.offsetFromUtc()));
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
        dt.setTimeZone(QTimeZone::fromSecondsAheadOfUtc(lhs.offsetFromUtc()));
    } else if (rhs.timeSpec() == Qt::OffsetFromUTC) {
        dt.setTimeZone(QTimeZone::fromSecondsAheadOfUtc(rhs.offsetFromUtc()));
    }

    return dt;
}

static bool containsNonAscii(QStringView s)
{
    for (const auto c : s) {
        if (c.row() != 0 || c.cell() > 127) {
            return true;
        }
    }

    return false;
}

static bool isMixedCase(QStringView s)
{
    const auto letterCount = std::count_if(s.begin(), s.end(), [](auto c) { return c.isLetter(); });
    const auto upperCount = std::count_if(s.begin(), s.end(), [](auto c) { return c.isUpper(); });
    return upperCount != letterCount && upperCount != 0;
}

static bool containsParantheses(QStringView s)
{
    return s.contains(u'(') && s.contains(u')');
}


QString MergeUtil::mergeString(const QString &lhs, const QString &rhs)
{
    // prefer Unicode over ASCII normalization
    const auto lhsNonAscii = containsNonAscii(lhs);
    const auto rhsNonAscii = containsNonAscii(rhs);
    if (lhsNonAscii && !rhsNonAscii) {
        return lhs;
    }
    if (!lhsNonAscii && rhsNonAscii) {
        return rhs;
    }

    // prefer better casing
    const auto lhsMixedCase = isMixedCase(lhs);
    const auto rhsMixedCase = isMixedCase(rhs);
    if (lhsMixedCase && !rhsMixedCase) {
        return lhs;
    }
    if (!lhsMixedCase && rhsMixedCase) {
        return rhs;
    }

    if (lhs.size() == rhs.size()) {
        return lhs < rhs ? lhs : rhs;
    }

    // Prefer strings without parantheses
    bool lhsParan = containsParantheses(lhs);
    bool rhsParan = containsParantheses(rhs);
    if (lhsParan && !rhsParan) {
        return rhs;
    }
    if (rhsParan && !lhsParan) {
        return lhs;
    }

    // Prefer longer string
    return lhs.size() < rhs.size() ? rhs : lhs;
}

QUrl MergeUtil::mergeUrl(const QUrl &lhs, const QUrl &rhs)
{
    return lhs.isEmpty() ? rhs : lhs;
}
