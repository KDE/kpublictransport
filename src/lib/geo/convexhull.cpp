/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "convexhull_p.h"

#include <QDebug>
#include <QLineF>
#include <QPolygonF>

using namespace KPublicTransport;

static double orientation(QPointF p, QPointF q, QPointF r)
{
    return (q.y() - p.y()) * (r.x() - q.x()) - (r.y() - q.y()) * (q.x() - p.x());
}

// see https://en.wikipedia.org/wiki/Gift_wrapping_algorithm
QPolygonF ConvexHull::compute(const std::vector<QPointF> &points)
{
    QPolygonF hull;
    if (points.size() < 3) {
        return hull;
    }

    // find left-most point
    const auto it = std::min_element(points.begin(), points.end(), [](auto lhs, auto rhs) {
        return lhs.x() < rhs.x();
    });
    hull.push_back(*it);
    auto p = std::distance(points.begin(), it);

    while (true) {
        auto q = (p + 1) % points.size();
        for (std::size_t r = 0; r < points.size(); ++r) {
            if (q == r) {
                continue;
            }

            auto o = orientation(points[p], points[q], points[r]);
            if (o < 0.0) {
                q = r;
            } else if (o == 0.0) {
                if (QLineF(points[p], points[r]).length() > QLineF(points[p], points[q]).length()) {
                    q = r;
                }
            }
        }
        p = q;
        hull.push_back(points[p]);

        if (hull.isClosed()) {
            break;
        }
    }

    return hull;
}
