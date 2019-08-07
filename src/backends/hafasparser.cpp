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

#include "hafasparser.h"
#include "logging.h"

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

Line::Mode HafasParser::parseLineMode(const QStringRef &modeId) const
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
    if (!m_standardLocationIdentifierType.isEmpty() && isUicStationId(id)) {
        loc.setIdentifier(m_standardLocationIdentifierType, id);
    }
    loc.setIdentifier(m_locationIdentifierType, id);
}

bool HafasParser::isUicStationId(const QString &id)
{
    if (id.size() != 7 || std::any_of(id.begin(), id.end(), [](QChar c) { return !c.isDigit(); })) {
        return false;
    }

    return id.at(0) != QLatin1Char('0');
}
