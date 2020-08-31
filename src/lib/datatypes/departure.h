/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_DEPARTURE_H
#define KPUBLICTRANSPORT_DEPARTURE_H

#include "stopover.h"
#warning "Using departure.h is deprecated, include stopover.h instead!"

namespace KPublicTransport {

/** Deprecated, use Stopover.
 *  @deprecated
 */
[[deprecated("Use Stopover instead")]] typedef Stopover Departure;

}

#endif
