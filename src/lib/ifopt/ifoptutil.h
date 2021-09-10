/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_IFOPTUTIL_H
#define KPUBLICTRANSPORT_IFOPTUTIL_H

class QString;
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

/** Returns the country identifier for the given (valid!) IFOPT identifier @p ifopt. */
QStringView country(QStringView ifopt);

/** Returns the stop place identifier for the given (valid!) IFOPT identifier @p ifopt. */
QStringView stopPlace(QStringView ifopt);

/** Returns the stop level identifier for the given (valid!) IFOPT identifier @p ifopt. */
QStringView level(QStringView ifopt);

/** Checks whether two valid IFOPT ids refer to the same stop place. */
bool isSameStopPlace(QStringView lhs, QStringView rhs);

/** Merge two IFOPT ids that refer to the same stop place while retaining the maximum level of detail.
 *  Precondition: isValid(lhs) && isValid(rhs) && isSameStopPlace(lhs, rhs)
 */
QStringView merge(QStringView lhs, QStringView rhs);

/** The identifier type for use in @c Location::identifer for IFOPT ids. */
QString identifierType();

}

}

#endif // KPUBLICTRANSPORT_IFOPTUTIL_H
