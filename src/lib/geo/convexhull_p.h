/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_CONVEXHULL_H
#define KPUBLICTRANSPORT_CONVEXHULL_H

#include <vector>

class QPointF;
class QPolygonF;

namespace KPublicTransport {

/** Convex hull algorithm.
 *  @internal
 */
namespace ConvexHull
{
    /** Compute the convex hull of @p points. */
    QPolygonF compute(const std::vector<QPointF> &points);
}

}

#endif // KPUBLICTRANSPORT_CONVEXHULL_H
