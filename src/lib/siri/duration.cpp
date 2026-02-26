/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "duration.h"

#include <QDebug>

using namespace Qt::Literals;
using namespace KPublicTransport;

std::chrono::seconds Siri::fromDuration(QStringView duration)
{
    if (!duration.startsWith('P'_L1)) {
        return {};
    }
    duration = duration.mid(1);

    bool inTime = false;
    std::chrono::seconds result(0);

    while (duration.size() > 1) {
        if (duration.startsWith('T'_L1)) {
            inTime = true;
            duration = duration.mid(1);
            continue;
        }

        qsizetype idx = 0;
        for (; idx < duration.size() - 1; ++idx) {
            if (!duration[idx].isDigit()) {
                break;
            }
        }
        const auto num = duration.left(idx).toInt();
        if (inTime) {
            if (duration[idx] == 'H'_L1) {
                result += std::chrono::hours(num);
            } else if (duration[idx] == 'M'_L1) {
                result += std::chrono::minutes(num);
            } else if (duration[idx] == 'S'_L1) {
                result += std::chrono::seconds(num);
            }
        }

        duration = duration.mid(idx + 1);
    }

    return result;
}
