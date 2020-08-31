/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LOADUTIL_H
#define KPUBLICTRANSPORT_LOADUTIL_H

#include "load.h"

#include <vector>

namespace KPublicTransport {

/** Internal utility functions for dealing with LoadInfo objects. */
namespace LoadUtil
{
    std::vector<LoadInfo> merge(const std::vector<LoadInfo> &lhs, const std::vector<LoadInfo> &rhs);
}

}

#endif // KPUBLICTRANSPORT_LOADUTIL_H
