/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef POLYGONSIMPLIFIER_H
#define POLYGONSIMPLIFIER_H

class QPolygonF;

/** Methods to simplify polygon geometry. */
namespace PolygonSimplifier
{
    /** Douglas Peucker algorithm.
     *  @param distance Threshold in meters.
     *  @see https://en.wikipedia.org/wiki/Ramer%E2%80%93Douglas%E2%80%93Peucker_algorithm
     */
    QPolygonF douglasPeucker(const QPolygonF &poly, double distance);

    /** Offset ("grow") a polygon by @p distance in meters. */
    QPolygonF offset(const QPolygonF &poly, double distance);
}

#endif // POLYGONSIMPLIFIER_H
