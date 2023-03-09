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

inline bool hasMatchingPrefixAndSuffix(QStringView lhs, QStringView rhs)
{
    // find matching prefix
    int prefixLen = 0;
    for (auto lIt = lhs.begin(), rIt = rhs.begin(); lIt != lhs.end() && rIt != rhs.end(); ++lIt, ++rIt) {
        if ((*lIt).toCaseFolded() == (*rIt).toCaseFolded()) {
            continue;
        }
        prefixLen = std::distance(lhs.begin(), lIt);
        if (!prefixLen || !(*std::prev(lIt)).isSpace()) { // no prefix or no separator
            return false;
        }
        break;
    }

    // find matching suffix
    int suffixLen = 0;
    for (auto lIt = lhs.rbegin(), rIt = rhs.rbegin(); lIt != lhs.rend() && rIt != rhs.rend(); ++lIt, ++rIt) {
        if ((*lIt).toCaseFolded() == (*rIt).toCaseFolded()) {
            continue;
        }
        suffixLen = std::distance(lhs.rbegin(), lIt);
        if (!suffixLen || !(*std::prev(lIt)).isSpace()) { // no suffix or no separator
            return false;
        }
        break;
    }

    const auto fullLen = prefixLen + suffixLen - 1; // -1 for the separator used twice
    if (lhs.size() > fullLen && rhs.size() > fullLen) {
        return false; // both have a varying middle part
    }

    // verify the single sided middle part is not containing numbers
    if (lhs.size() > rhs.size()) {
        std::swap(lhs, rhs);
    }
    for (auto i = prefixLen; i < rhs.size() - suffixLen; ++i) {
        if (rhs[i].isDigit()) {
            return false;
        }
    }

    return true;
}

inline bool isSameLineName(const QString &lhs, const QString &rhs, LineNameCompareMode mode)
{
    return lhs.compare(rhs, Qt::CaseInsensitive) == 0
        || isSameLineName(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), mode)
        || isSameLineName(lhs.rbegin(), lhs.rend(), rhs.rbegin(), rhs.rend(), mode)
        || (mode == FuzzyCompare && hasMatchingPrefixAndSuffix(lhs, rhs));
}

}
}
