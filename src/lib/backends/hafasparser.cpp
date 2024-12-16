/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasparser.h"
#include "hafasbackend.h"
#include "logging.h"
#include "uic/uicstationcode.h"

#include <KPublicTransport/Location>

#include <QStringTokenizer>

using namespace Qt::Literals;
using namespace KPublicTransport;

HafasParser::HafasParser() = default;
HafasParser::~HafasParser() = default;

void HafasParser::setLocationIdentifierTypes(const QString &idType, const QString &standardIdType)
{
    m_locationIdentifierType = idType;
    m_standardLocationIdentifierType = standardIdType;
}

void HafasParser::setLineModeMap(std::span<HafasLineModeMapEntry> modeMap)
{
    m_lineModeMap = modeMap;
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

Line::Mode HafasParser::parseLineMode(const QStringView &modeId) const
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
    const auto lineModeIt = std::lower_bound(m_lineModeMap.begin(), m_lineModeMap.end(), modeId, [](const auto &lhs, int rhs) { return lhs.productClass < rhs; });
    if (lineModeIt != m_lineModeMap.end() && (*lineModeIt).productClass == modeId) {
        return (*lineModeIt).mode;
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

Location HafasParser::fromLocationId(const QString &locId) const
{
    Location loc;

    for (auto entry : QStringTokenizer(locId, '@'_L1)) {
        if (entry.startsWith("O="_L1)) {
            loc.setName(entry.mid(2).toString());
        } else if (entry.startsWith("X="_L1)) {
            loc.setLongitude(entry.mid(2).toInt() / 1000000.0);
        } else if (entry.startsWith("Y="_L1)) {
            loc.setLatitude(entry.mid(2).toInt() / 1000000.0);
        } else if (entry.startsWith("L="_L1)) {
            setLocationIdentifier(loc, entry.mid(2).toString());
        } else if (entry.startsWith(u"i=U×00")) {
            if (const auto uicCode = entry.mid(6); UicStationCode::isValid(uicCode, m_uicCountryCodes)) {
                loc.setIdentifier(u"uic"_s, uicCode.toString());
            }
        } else if (entry.startsWith("A="_L1)) {
            if (entry.mid(2) == "1"_L1) {
                loc.setType(Location::Stop);
            } else if (entry.mid(2) == "2"_L1) {
                loc.setType(Location::Address);
            }
            // A=4 is POI
        }
    }

    loc.setIdentifier(u"hafas"_s, locId);
    return loc;
}

static constexpr const Load::Category load_value_map[] = {
    Load::Unknown,
    Load::Low, // 1
    Load::Medium, // 2
    Load::High, // 3
    Load::Full // 4
};

Load::Category HafasParser::parseLoadLevel(int level)
{
    if (level >= 0 && level < (int)std::size(load_value_map)) {
        return load_value_map[level];
    }
    return Load::Unknown;
}
