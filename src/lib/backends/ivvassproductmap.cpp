/*
    SPDX-FileCopyrightText: 2021-2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "ivvassproductmap.h"

#include <QDebug>
#include <QUrlQuery>

using namespace KPublicTransport;

struct {
    const char *product;
    Line::Mode mode;
} static constexpr const product_mode_map[] = {
    { "Boat", Line::Ferry },
    { "Bus", Line::Bus },
    { "CommunityBus", Line::Bus },
    { "LightRail", Line::Tramway },
    { "LongDistanceTrains", Line::LongDistanceTrain },
    { "OnDemandServices", Line::Taxi },
    { "RailReplacementServices", Line::Bus },
    { "RegionalTrains", Line::LocalTrain },
    { "SuburbanTrains", Line::RapidTransit },
    { "Underground", Line::Metro }
};

Line::Mode IvvAssProductMap::parseProduct(QStringView product)
{
    for (const auto &m : product_mode_map) {
        if (product == QLatin1String(m.product)) {
            return m.mode;
            break;
        }
    }

    qWarning() << "Unknown IVV ASS product type:" << product;
    return Line::Unknown;
}

void IvvAssProductMap::lineModesToQuery(const std::vector<Line::Mode> &lineModes, QUrlQuery &query)
{
    if (lineModes.empty()) {
        return;
    }

    QStringList products;
    for (auto &m : product_mode_map) {
        // lineModes is guaranteed to be sorted
        if (std::binary_search(lineModes.begin(), lineModes.end(), m.mode)) {
            products.push_back(QLatin1String(m.product));
        }
    }
    if (!products.isEmpty()) {
        query.addQueryItem(QStringLiteral("p"), products.join(QLatin1Char(',')));
    }
}
