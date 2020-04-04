/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#include <QString>

namespace KPublicTransport {

// implementation details shared with the line metadata code generator
namespace Internal {

template <typename Iter>
inline bool isSameLineName(const Iter &lBegin, const Iter &lEnd, const Iter &rBegin, const Iter &rEnd)
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

    // one input is prefix of the other, that is ok if there's a separator
    return (lIt != lEnd && (*lIt).isSpace()) || (rIt != rEnd && (*rIt).isSpace());
}

inline bool isSameLineName(const QString &lhs, const QString &rhs)
{
    return lhs.compare(rhs, Qt::CaseInsensitive) == 0
        || isSameLineName(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
        || isSameLineName(lhs.rbegin(), lhs.rend(), rhs.rbegin(), rhs.rend());
}

}
}
