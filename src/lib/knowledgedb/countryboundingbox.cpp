/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "countryboundingbox_p.h"
#include "countryboundingbox_data.cpp"

#include <QRectF>
#include <QString>

using namespace KPublicTransport;

static bool operator<(const CountryBoundingBoxData &lhs, QStringView rhs) {
    return QLatin1StringView(lhs.code, 2) < rhs;
}

QRectF KPublicTransport::boundingBoxForCountry(QStringView countryCode)
{
    const auto it = std::lower_bound(std::begin(country_bounding_boxes), std::end(country_bounding_boxes), countryCode);
    if (it == std::end(country_bounding_boxes) || QLatin1StringView((*it).code, 2) != countryCode) {
        return {};
    }
    return QRectF(QPointF((*it).minLon / 100.0, (*it).minLat / 100.0), QPointF((*it).maxLon / 100.0, (*it).maxLat / 100.0));
}
