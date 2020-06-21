/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
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
