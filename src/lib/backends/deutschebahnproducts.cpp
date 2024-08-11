/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "deutschebahnproducts.h"

using namespace Qt::Literals;
using namespace KPublicTransport;

// ### alphabetically sorted by name
struct {
    const char *type;
    Line::Mode mode;
} static constexpr const train_type_map[] = {
    { "EC",  Line::LongDistanceTrain },
    { "IC",  Line::LongDistanceTrain },
    { "ICE", Line::LongDistanceTrain },
    { "NJ",  Line::LongDistanceTrain },
    { "RB",  Line::LocalTrain },
    { "RE",  Line::LocalTrain },
    { "RJ",  Line::LongDistanceTrain },
    { "S", Line::RapidTransit },
};

bool DeutscheBahnProducts::isValid(QStringView categoryName)
{
    const auto it = std::lower_bound(std::begin(train_type_map), std::end(train_type_map), categoryName, [](auto lhs, auto rhs) {
        return QLatin1StringView(lhs.type) < rhs;
    });

    return it != std::end(train_type_map) && QLatin1StringView((*it).type) == categoryName;
}

Line::Mode DeutscheBahnProducts::modeType(QStringView categoryName)
{
    const auto it = std::lower_bound(std::begin(train_type_map), std::end(train_type_map), categoryName, [](auto lhs, auto rhs) {
        return QLatin1StringView(lhs.type) < rhs;
    });

    return it != std::end(train_type_map) && QLatin1StringView((*it).type) == categoryName ? (*it).mode : Line::Unknown;
}
