/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
