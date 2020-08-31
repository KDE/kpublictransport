/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_DEPARTUREMODEL_H
#define KPUBLICTRANSPORT_DEPARTUREMODEL_H

#include "stopoverquerymodel.h"
#warning "Using departurequerymodel.h is deprecated, include stopoverquerymodel.h instead!"

namespace KPublicTransport {

/** Deprecated, use StopoverQueryModel.
 *  @deprecated
 */
[[deprecated("Use StopoverQueryModel instead")]] typedef StopoverQueryModel StopoverQueryModel;

}

#endif
