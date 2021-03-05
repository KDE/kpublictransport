/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "loadutil_p.h"

#include <QDebug>

using namespace KPublicTransport;

std::vector<LoadInfo> LoadUtil::merge(const std::vector<LoadInfo> &lhs, const std::vector<LoadInfo> &rhs)
{
    // any result is better than none
    if (lhs.empty()) {
        return rhs;
    }
    if (rhs.empty()) {
        return lhs;
    }

    std::vector<LoadInfo> result;
    result.reserve(std::max(lhs.size(), rhs.size()));
    std::copy(lhs.begin(), lhs.end(), std::back_inserter(result));

    const auto classOrder = [](const auto &loadL, const auto &loadR) {
        return loadL.seatingClass() < loadR.seatingClass();
    };
    std::sort(result.begin(), result.end(), classOrder);

    for (const auto &l : rhs) {
        const auto it = std::lower_bound(result.begin(), result.end(), l, classOrder);
        if (it == result.end() || (*it).seatingClass() != l.seatingClass()) {
            result.insert(it, l);
        } else {
            (*it).setLoad(std::max((*it).load(), l.load()));
        }
    }

    // class-less vs. class-specific information
    if (result.size() > 1 && result.front().seatingClass().isEmpty()) {
        // TODO check that this doesn't reduce the highest load we have?
        result.erase(result.begin());
    }

    return result;
}
