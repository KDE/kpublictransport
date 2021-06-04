/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_IFOPTUTIL_H
#define KPUBLICTRANSPORT_IFOPTUTIL_H

class QStringView;

namespace KPublicTransport {

/** Utility functions for dealing with IFOPT (Identification of Fixed Objects in Public Transport).
 *  @see https://wiki.openstreetmap.org/wiki/Key:ref:IFOPT
 *  @see https://en.wikipedia.org/wiki/Identification_of_Fixed_Objects_in_Public_Transport
 */
namespace IfoptUtil
{

/** Check if @p ifopt is a valid IFOPT identifier. */
bool isValid(QStringView ifopt);

/** Returns the stop place identifier for the given (valid!) IFOPT identifier @p ifopt. */
QStringView stopPlace(QStringView ifopt);

/** Checks whether two valid IFOPT ids refer to the same stop place. */
bool isSameStopPlace(QStringView lhs, QStringView rhs);

}

}

#endif // KPUBLICTRANSPORT_IFOPTUTIL_H
