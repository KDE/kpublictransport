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

QStringView IfoptUtil::stopPlace(QStringView ifopt)
{
    qsizetype pos = 0;
    for (int i = 0; i < 3; i++) {
        pos = ifopt.indexOf(QLatin1Char(':'), pos) + 1;
    }
    return ifopt.left(pos - 1);
}

bool IfoptUtil::isSameStopPlace(QStringView lhs, QStringView rhs)
{
    return stopPlace(lhs) == stopPlace(rhs);
}
