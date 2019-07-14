/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_ATTRIBUTIONUTIL_P_H
#define KPUBLICTRANSPORT_ATTRIBUTIONUTIL_P_H

#include <vector>

namespace KPublicTransport {

class Attribution;

/** Functions to merge Attribution information. */
namespace AttributionUtil
{
    /** Sorts @p attrs in the order expected by merge. */
    void sort(std::vector<Attribution> &attrs);

    /** @p left is assumed to be sorted already. */
    void merge(std::vector<Attribution> &left, std::vector<Attribution> &&right);
    void merge(std::vector<Attribution> &left, const std::vector<Attribution> &right);
    void merge(std::vector<Attribution> &left, const Attribution &right);
    void merge(Attribution &left, const Attribution &right);
}

}

#endif // KPUBLICTRANSPORT_ATTRIBUTIONUTIL_P_H
