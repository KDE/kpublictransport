/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "localizer_p.h"

#include <KPublicTransport/Journey>

#include <KLocalizedString>

#include <QDateTime>
#include <QLocale>
#include <QTimeZone>

using namespace Qt::StringLiterals;

static bool needsTimeZone(const QDateTime &dt)
{
    if (dt.timeSpec() == Qt::TimeZone && dt.timeZone().abbreviation(dt) != QTimeZone::systemTimeZone().abbreviation(dt)) {
        return true;
    } else if (dt.timeSpec() == Qt::OffsetFromUTC && dt.timeZone().offsetFromUtc(dt) != dt.offsetFromUtc()) {
        return true;
    } else if (dt.timeSpec() == Qt::UTC && QTimeZone::systemTimeZone() != QTimeZone::utc()) {
        return true;
    }
    return false;
}

QString Localizer::formatTime(const KPublicTransport::Journey &journey, const QString &propertyName) const
{
    QDateTime dt;
    if (propertyName == "scheduledDepartureTime"_L1) {
        dt = journey.scheduledDepartureTime();
    } else if (propertyName == "scheduledArrivalTime"_L1) {
        dt = journey.scheduledArrivalTime();
    } else if (propertyName == "expectedArrivalTime"_L1) {
        dt = journey.expectedArrivalTime();
    } else if (propertyName == "expectedDepartureTime"_L1) {
        dt = journey.expectedDepartureTime();
    }

    if (!dt.isValid()) {
        return {};
    }

    QString output;
    if (QLocale().timeFormat(QLocale::ShortFormat).contains(QStringLiteral("ss"))) {
        output = QLocale().toString(dt.time(), QStringLiteral("hh:mm"));
    } else {
        output = QLocale().toString(dt.time(), QLocale::ShortFormat);
    }
    if (needsTimeZone(dt)) {
        output += QLatin1Char(' ') + dt.timeZoneAbbreviation();
    }
    return output;
}

QString Localizer::formatDurationCustom(int seconds) const
{
    enum TimeConstants {
        SecsInDay = 86400,
        SecsInHour = 3600,
        SecsInMinute = 60,
    };

    bool isNegative = seconds < 0;
    if (isNegative) {
        seconds = -seconds;
    }

    int hours = seconds / SecsInHour;
    seconds = seconds % SecsInHour;
    int minutes = seconds / SecsInMinute;

    QString duration;
    if (hours == 0) {
        duration = i18nc("Duration in minutes", "%1 min", minutes);
    } else if (minutes == 0) {
        duration = i18nc("Duration in hours and minutes", "%1 hr", hours);
    } else {
        duration = i18nc("Duration in hours and minutes", "%1 hr %2 min", hours, minutes);
    }
    if (isNegative) {
        duration = QLocale().negativeSign() + duration;
    }
    return duration;
}

#include "moc_localizer_p.cpp"
