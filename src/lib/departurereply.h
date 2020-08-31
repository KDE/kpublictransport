/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_DEPARTUREREPLY_H
#define KPUBLICTRANSPORT_DEPARTUREREPLY_H

#include "stopoverreply.h"
#warning "Using departurereply.h is deprecated, include stopoverreply.h instead!"

namespace KPublicTransport {

/** Deprecated, use StopoverReply.
 *  @deprecated
 */
[[deprecated("Use StopoverReply instead")]] typedef StopoverReply DepartureReply;

}

#endif
