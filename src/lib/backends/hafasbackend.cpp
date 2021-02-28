/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasbackend.h"
#include "logging.h"

#include <KPublicTransport/Location>

#include <QJsonArray>
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
        const auto mode = static_cast<Line::Mode>(me.keyToValue(prodObj.value(QLatin1String("mode")).toString().toUtf8().constData()));
        if (mode == Line::Unknown) {
            qCWarning(Log) << "Invalid product mode:" << prodObj;
        }
        for (const auto &bit : bitmasks) {
            m_lineModeMap[bit.toInt()] = mode;
        }
    }
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
