/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "attributionutil_p.h"

#include <KPublicTransport/Attribution>

#include <QUrl>

using namespace KPublicTransport;

static bool attrLessThan(const Attribution &lhs, const Attribution &rhs)
{
    return QString::compare(lhs.name(), rhs.name(), Qt::CaseInsensitive) < 0;
}

static bool attrEqual(const Attribution &lhs, const Attribution &rhs)
{
    return QString::compare(lhs.name(),rhs.name(), Qt::CaseInsensitive) == 0;
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
