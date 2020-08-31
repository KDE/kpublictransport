/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <QString>

namespace KPublicTransport {

// implementation details shared with the line metadata code generator
namespace Internal {

enum LineNameCompareMode {
    StrictCompare,
    FuzzyCompare,
};

template <typename Iter>
inline bool isSameLineName(const Iter &lBegin, const Iter &lEnd, const Iter &rBegin, const Iter &rEnd, LineNameCompareMode mode)
{
    auto lIt = lBegin;
    auto rIt = rBegin;
    while (lIt != lEnd && rIt != rEnd) {
        // ignore spaces etc.
        if (!(*lIt).isLetterOrNumber()) {
            ++lIt;
            continue;
        }
        if (!(*rIt).isLetterOrNumber()) {
            ++rIt;
            continue;
        }

        if ((*lIt).toCaseFolded() != (*rIt).toCaseFolded()) {
            return false;
        }

        ++lIt;
        ++rIt;
    }

    if (lIt == lEnd && rIt == rEnd) { // both inputs fully consumed, and no mismatch found
        return true;
    }

    if (mode == StrictCompare) {
        return false;
    }
    // one input is prefix of the other, that is ok if there's a separator
    return (lIt != lEnd && (*lIt).isSpace()) || (rIt != rEnd && (*rIt).isSpace());
}

inline bool isSameLineName(const QString &lhs, const QString &rhs, LineNameCompareMode mode)
{
    return lhs.compare(rhs, Qt::CaseInsensitive) == 0
        || isSameLineName(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), mode)
        || isSameLineName(lhs.rbegin(), lhs.rend(), rhs.rbegin(), rhs.rend(), mode);
}

}
}
