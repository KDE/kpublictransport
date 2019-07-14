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

#include "attributionutil_p.h"

#include <KPublicTransport/Attribution>

#include <QUrl>

using namespace KPublicTransport;

static bool attrLessThan(const Attribution &lhs, const Attribution &rhs)
{
    return lhs.name() < rhs.name();
}

static bool attrEqual(const Attribution &lhs, const Attribution &rhs)
{
    return lhs.name() == rhs.name();
}

void AttributionUtil::sort(std::vector<Attribution> &attrs)
{
    std::sort(attrs.begin(), attrs.end(), attrLessThan);
}

void AttributionUtil::merge(std::vector<Attribution> &left, std::vector<Attribution> &&right)
{
    if (left.empty()) {
        left = std::move(right);
        sort(left);
    } else {
        for (const auto &a : right) {
            merge(left, a);
        }
    }
}

void AttributionUtil::merge(std::vector<Attribution> &left, const std::vector<Attribution> &right)
{
    for (const auto &a : right) {
        merge(left, a);
    }
}

void AttributionUtil::merge(std::vector<Attribution> &left, const Attribution &right)
{
    if (right.isEmpty()) {
        return;
    }

    const auto it = std::lower_bound(left.begin(), left.end(), right, attrLessThan);
    if (it != left.end() && attrEqual(*it, right)) {
        merge(*it, right);
    } else {
        left.insert(it, right);
    }
}

void AttributionUtil::merge(Attribution &left, const Attribution &right)
{
    if (!left.url().isValid() && right.url().isValid()) {
        left.setUrl(right.url());
    }
    if (!left.hasLicense() && right.hasLicense()) {
        left.setLicense(right.license());
        left.setLicenseUrl(right.licenseUrl());
    }
}
