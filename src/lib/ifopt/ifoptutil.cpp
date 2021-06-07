/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "ifoptutil.h"

#include <QDebug>
#include <QStringView>

using namespace KPublicTransport;

bool IfoptUtil::isValid(QStringView ifopt)
{
    if (ifopt.size() < 6) {
        return false;
    }

    qsizetype pos = 0;
    int elementCount = 1;
    do {
        const auto idx = ifopt.indexOf(QLatin1Char(':'), pos);
        elementCount += (idx > pos) ? 1 : 0;
        if (idx == pos || idx == ifopt.size() - 1 || (elementCount < 3 && idx < 0)) {
            return false;
        }
        pos = idx + 1;
    } while (pos != 0 && pos < ifopt.size());

    return elementCount >= 3 && elementCount <= 5 && ifopt[0].isLetter() && ifopt[1].isLetter() && ifopt[2] == QLatin1Char(':');
}

static QStringView ifoptPrefix(QStringView ifopt, int elementCount)
{
    qsizetype pos = 0;
    for (int i = 0; i < elementCount; i++) {
        pos = ifopt.indexOf(QLatin1Char(':'), pos) + 1;
    }
    return ifopt.left(pos - 1);
}

QStringView IfoptUtil::country(QStringView ifopt)
{
    return ifoptPrefix(ifopt, 1);
}

QStringView IfoptUtil::stopPlace(QStringView ifopt)
{
    return ifoptPrefix(ifopt, 3);
}

QStringView IfoptUtil::level(QStringView ifopt)
{
    return ifoptPrefix(ifopt, 4);
}

bool IfoptUtil::isSameStopPlace(QStringView lhs, QStringView rhs)
{
    return stopPlace(lhs) == stopPlace(rhs);
}

QStringView IfoptUtil::merge(QStringView lhs, QStringView rhs)
{
    if (lhs.isEmpty()) {
        return rhs;
    }
    if (rhs.isEmpty()) {
        return lhs;
    }

    if (lhs == rhs) {
        return lhs;
    }

    if (level(lhs) == level(rhs)) {
        return level(lhs);
    }

    return stopPlace(lhs);
}
