/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "pathfilter_p.h"

#include <QDebug>
#include <QLineF>
#include <QPolygonF>

using namespace KPublicTransport;

[[nodiscard]] static double turnAngle(const QPolygonF &path, qsizetype i)
{
    QLineF l1(path[i], path[i+1]);
    QLineF l2(path[i+1], path[i+2]);
    const auto turnAngle = l1.angleTo(l2);
    return std::min(turnAngle, 360.0 - turnAngle);
}

void PathFilter::removeSpikes(QPolygonF &path, double maxAngle)
{
    if (path.size() < 3 || path.isClosed()) {
        return;
    }

    for (qsizetype i = 0; i < path.size() - 2; ++i) {
        const auto a1 = turnAngle(path, i);
        if (a1 <= maxAngle) {
            continue;
        }
        // look ahead by one, if the next turn is even steeper the current one is likely a side-effect that one, not the cause
        const auto a2 = (i < path.size() - 3) ? turnAngle(path, i + 1) : 0.0;
        if (a2 > a1) {
            path.remove(i + 2, 1);
        } else {
            path.remove(i + 1, 1);
        }
        --i;
    }
}
