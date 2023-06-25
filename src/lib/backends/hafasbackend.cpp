/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasbackend.h"
#include "logging.h"

#include <KPublicTransport/Location>

#include <QJsonObject>
#include <QMetaEnum>

using namespace KPublicTransport;

void HafasBackend::setProductsMap(const QJsonArray& array)
{
    m_lineModeMap.reserve(array.size());
    const auto me = QMetaEnum::fromType<Line::Mode>();
    for (const auto &prodV : array) {
        const auto prodObj = prodV.toObject();
        const auto bitmasks = prodObj.value(QLatin1String("bitmasks")).toArray();
        auto mode = static_cast<Line::Mode>(me.keyToValue(prodObj.value(QLatin1String("mode")).toString().toUtf8().constData()));
        if (mode == Line::Unknown || mode < 0) {
            qCWarning(Log) << "Invalid product mode:" << prodObj;
            mode = Line::Unknown;
        }
        for (const auto &bit : bitmasks) {
            m_lineModeMap.push_back({bit.toInt(), mode});
        }
    }

    std::sort(m_lineModeMap.begin(), m_lineModeMap.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.productClass < rhs.productClass;
    });
}

QString HafasBackend::locationIdentifierType() const
{
    return m_locationIdentifierType.isEmpty() ? backendId() : m_locationIdentifierType;
}

QString HafasBackend::standardLocationIdentifierType() const
{
    return m_standardLocationIdentifierType;
}

QString HafasBackend::locationIdentifier(const Location &loc) const
{
    const auto id = loc.identifier(locationIdentifierType());
    if (!id.isEmpty()) {
        return id;
    }
    return loc.identifier(standardLocationIdentifierType());
}

void HafasBackend::setStandardLocationIdentifierCountries(const QJsonArray &a)
{
    m_uicCountryCodes.reserve(a.size());
    std::transform(a.begin(), a.end(), std::back_inserter(m_uicCountryCodes), [](const auto &v) { return v.toInt(); });
    std::sort(m_uicCountryCodes.begin(), m_uicCountryCodes.end());
}
