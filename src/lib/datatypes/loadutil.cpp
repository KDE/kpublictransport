/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "loadutil_p.h"

#include <QDebug>

using namespace KPublicTransport;

std::vector<LoadInfo> LoadUtil::merge(const std::vector<LoadInfo> &lhs, const std::vector<LoadInfo> &rhs)
{
    if (lhs.empty()) {
        return rhs;
    }
    if (rhs.empty()) {
        return lhs;
    }

    // TODO
    return lhs;
}
