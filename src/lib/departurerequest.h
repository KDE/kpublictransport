/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_DEPARTUREREQUEST_H
#define KPUBLICTRANSPORT_DEPARTUREREQUEST_H

#include "stopoverrequest.h"
#warning "Using departurerequest.h is deprecated, include stopoverrequest.h instead!"

namespace KPublicTransport {

/** Deprecated, use StopoverRequest.
 *  @deprecated
 */
[[deprecated("Use StopoverRequest instead")]] typedef StopoverRequest DepartureRequest;

}

#endif

