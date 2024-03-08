/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "uicstationcode.h"

#include <QString>
#include <QStringView>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

bool UicStationCode::isValid(QStringView id, const std::vector<uint8_t> &allowedCountryCodes)
{
    // too short, or not a number
    if (id.size() < 7 || std::any_of(id.begin(), id.end(), [](QChar c) { return !c.isDigit() || c.row() > 0; })) {
        return false;
    }

    // too long, but just 0 prefixed
    if (id.size() > 7 && std::any_of(id.begin(), id.begin() + id.size() - 7, [](QChar c) { return c != QLatin1Char('0'); })) {
        return false;
    }

    // one of the explicitly allowed UIC country codes
    if (!allowedCountryCodes.empty()) {
        const uint8_t countryCode = id.mid(id.size() - 7, 2).toInt();
        return std::binary_search(allowedCountryCodes.begin(), allowedCountryCodes.end(), countryCode);
    }

    // if no UIC country codes are explicitly allowed, insist on the right length
    return id.size() == 7 && id.at(0) != QLatin1Char('0');
}

QStringView UicStationCode::country(QStringView id)
{
    return id.mid(0, 2);
}

QString UicStationCode::identifierType()
{
    return u"uic"_s;
}
