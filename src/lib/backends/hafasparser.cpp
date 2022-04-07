/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasparser.h"
#include "logging.h"
#include "uic/uicstationcode.h"

#include <KPublicTransport/Location>

using namespace KPublicTransport;

HafasParser::HafasParser() = default;
HafasParser::~HafasParser() = default;

void HafasParser::setLocationIdentifierTypes(const QString &idType, const QString &standardIdType)
{
    m_locationIdentifierType = idType;
    m_standardLocationIdentifierType = standardIdType;
}

void HafasParser::setLineModeMap(std::unordered_map<int, Line::Mode> &&modeMap)
{
    m_lineModeMap = std::move(modeMap);
}

Reply::Error HafasParser::error() const
{
    return m_error;
}

QString HafasParser::errorMessage() const
{
    return m_errorMsg;
}

void HafasParser::clearErrorState()
{
    m_error = Reply::NoError;
    m_errorMsg.clear();
}

Line::Mode HafasParser::parseLineMode(const QString &modeId) const
{
    bool ok = false;
    const auto modeNum = modeId.toInt(&ok);
    if (!ok) {
        return Line::Unknown;
    }
    return parseLineMode(modeNum);
}

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
Line::Mode HafasParser::parseLineMode(const QStringRef &modeId) const
#else
Line::Mode HafasParser::parseLineMode(const QStringView &modeId) const
#endif
{
    bool ok = false;
    const auto modeNum = modeId.toInt(&ok);
    if (!ok) {
        return Line::Unknown;
    }
    return parseLineMode(modeNum);
}

Line::Mode HafasParser::parseLineMode(int modeId) const
{
    const auto lineModeIt = m_lineModeMap.find(modeId);
    if (lineModeIt != m_lineModeMap.end()) {
        return (*lineModeIt).second;
    }
    qCDebug(Log) << "Encountered unknown line type:" << modeId;
    return Line::Unknown;
}

void HafasParser::setLocationIdentifier(Location &loc, const QString &id) const
{
    if (id.isEmpty()) {
        return;
    }
    if (!m_standardLocationIdentifierType.isEmpty() && UicStationCode::isValid(id, m_uicCountryCodes)) {
        loc.setIdentifier(m_standardLocationIdentifierType, id.right(7));
    }
    loc.setIdentifier(m_locationIdentifierType, id);
}

void HafasParser::setStandardLocationIdentfierCountries(std::vector<uint8_t> &&uicCountryCodes)
{
    m_uicCountryCodes = std::move(uicCountryCodes);
}
