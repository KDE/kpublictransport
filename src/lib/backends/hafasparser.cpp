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

    loc.setIdentifier(m_locationIdentifierType + "-hafas"_L1, locId);
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

static constexpr const HafasRemarkData remarks_map[] = {
    // different name formats for the line, used by SBB
    { "A", "1", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "A", "2", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "A", "3", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    // same as above, containing product, line number and journey number
    { "A", "4", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "A", "A4", FeatureRemark, Feature::Toilet, Feature::Available },
    { "A", "BO", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "BR", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "BT", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "BW", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "BZ", FeatureRemark, Feature::BusinessArea, Feature::Available },
    { "A", "CK", IgnoreRemark, Feature::NoFeature, Feature::Unknown }, // Komfort Check-in advertisment
    { "A", "CR", FeatureRemark, Feature::BikeStorage, Feature::Conditional },
    { "A", "EA", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "EF", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "EH", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "ER", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "EXTERNAL_ID", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "A", "FA", FeatureRemark, Feature::FamilyArea, Feature::Available },
    { "A", "FB", FeatureRemark, Feature::BikeStorage, Feature::Limited },
    { "A", "FH", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "FK", FeatureRemark, Feature::BikeStorage, Feature::Limited },
    { "A", "FR", FeatureRemark, Feature::BikeStorage, Feature::Conditional },
    // observied with different meanings - Conditional bike storage (DE) vs free wifi (CH)
    // { "A", "FS", FeatureRemark, Feature::BikeStorage, Feature::Conditional },
    { "A", "FZ", FeatureRemark, Feature::FamilyArea, Feature::Available },
    { "A", "G ", FeatureRemark, Feature::BikeStorage, Feature::Limited },
    // NASA: GTFS route type
    { "A", "GT", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "A", "HD", FeatureRemark, Feature::SilentArea, Feature::Available },
    { "A", "HK", FeatureRemark, Feature::ToddlerArea, Feature::Available },
    { "A", "JOURNEYNUMBER", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "A", "KG", FeatureRemark, Feature::Restaurant, Feature::Unavailable },
    { "A", "KK", FeatureRemark, Feature::ToddlerArea, Feature::Available },
    { "A", "KL", FeatureRemark, Feature::AirConditioning, Feature::Available },
    { "A", "KN", FeatureRemark, Feature::FamilyArea, Feature::Available },
    { "A", "LS", FeatureRemark, Feature::PowerSockets, Feature::Available },
    { "A", "MN", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "MP", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "NAME", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    // observed with different meanings? no bike storage (DE?) vs. low floor vehicle (CH)
    // { "A", "NF", FeatureRemark, Feature::BikeStorage, Feature::Unavailable },
    { "A", "OA", FeatureRemark, Feature::WheelchairAccessible, Feature::Conditional },
    { "A", "OC", FeatureRemark, Feature::WheelchairAccessibleToilet, Feature::Available },
    { "A", "OG", FeatureRemark, Feature::WheelchairAccessibleToilet, Feature::Limited },
    { "A", "OPERATOR", OperatorRemark, Feature::NoFeature, Feature::Unknown },
    { "A", "QP", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "RG", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "RO", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    // observed with different meanings: wheelchair access in DE, quiet zone in CH
    //{ "A", "RZ", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "SA", FeatureRemark, Feature::ToddlerArea, Feature::Limited },
    { "A", "SI", FeatureRemark, Feature::WheelchairAccessible, Feature::Limited },
    { "A", "SN", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "TD", FeatureRemark, Feature::WiFi, Feature::Available },
    { "A", "TM", FeatureRemark, Feature::Restaurant, Feature::Limited },
    { "A", "TO", FeatureRemark, Feature::Toilet, Feature::Available },
    { "A", "UA", FeatureRemark, Feature::BusinessArea, Feature::Available },
    { "A", "VB", FeatureRemark, Feature::BikeStorage, Feature::Limited },
    { "A", "VN", FeatureRemark, Feature::BikeStorage, Feature::Unavailable },
    { "A", "VR", FeatureRemark, Feature::BikeStorage, Feature::Conditional },
    { "A", "WI", FeatureRemark, Feature::WiFi, Feature::Available },
    { "A", "WR", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "WV", FeatureRemark, Feature::WiFi, Feature::Available },
    { "A", "ZB", FeatureRemark, Feature::WheelchairAccessible, Feature::Limited },
    { "A", "ZM", FeatureRemark, Feature::WheelchairAccessible, Feature::Limited },
    { "A", "aD", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "aR", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "aS", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "bV", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "bW", FeatureRemark, Feature::BikeStorage, Feature::Conditional },
    { "A", "bf", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "bg", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "bq", FeatureRemark, Feature::BikeStorage, Feature::Limited },
    { "A", "br", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "bs", FeatureRemark, Feature::WheelchairAccessibleToilet, Feature::Available },
    { "A", "bv", FeatureRemark, Feature::WiFi, Feature::Available },
    { "A", "cc", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "cd", FeatureRemark, Feature::BikeStorage, Feature::Limited },
    { "A", "cg", FeatureRemark, Feature::BikeStorage, Feature::Conditional },
    { "A", "cj", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "de", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "df", FeatureRemark, Feature::WheelchairAccessible, Feature::Unavailable },
    { "A", "dg", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    // NASA: literally just a '.'
    { "A", "dj", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "A", "dk", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "dl", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "ei", FeatureRemark, Feature::BikeStorage, Feature::Available },
    { "A", "ek", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "ga", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "gd", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "hz", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "ia", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "ic", FeatureRemark, Feature::Restaurant, Feature::Available },
    { "A", "ie", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "in", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "kx", FeatureRemark, Feature::PowerSockets, Feature::Available },
    { "A", "lb", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    { "A", "mG", FeatureRemark, Feature::BikeStorage, Feature::Conditional },
    { "A", "mg", FeatureRemark, Feature::WheelchairAccessible, Feature::Conditional },
   // ZVV: pointless note about checking intermediate stops for more details
    { "A", "moreAttr", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "A", "yh", FeatureRemark, Feature::WiFi, Feature::Available },
    { "A", "zd", OperatorRemark, Feature::NoFeature, Feature::Unknown },
    { "A", "zn", OperatorRemark, Feature::NoFeature, Feature::Unknown },
    // pointless CO2 emission reduction ad
    { "H", "text.connection.eco.co2.decreased.consumption.message", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "H", "vmt.accessible", FeatureRemark, Feature::WheelchairAccessible, Feature::Available },
    // contains a pointless note about checking trip details
    { "H", "wagenstand_v2", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    // SBB line number?
    { "I", "FD", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "I", "JF", TrainFormationRemark, Feature::NoFeature, Feature::Unknown },
    // Swiss journey id
    { "I", "JY", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
     // SBB: some unknown number for buses
    { "I", "RN", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "I", "TC", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    // SBB: some XML structure of unknown content, related to train/platform layouts
    { "I", "XC", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "I", "XG", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    { "I", "XP", PlatformSectorsRemark, Feature::NoFeature, Feature::Unknown },
    // SBB: some XML structure of unknown content, related to train/platform layouts
    { "I", "XT", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
    // Swiss journey id
    { "I", "sj", IgnoreRemark, Feature::NoFeature, Feature::Unknown },
};

HafasRemarkData HafasParser::lookupRemarkData(QStringView type, QStringView code)
{
    for (const auto &r : remarks_map) {
        if (type == QLatin1StringView(r.type) && code == QLatin1StringView(r.code)) {
            return r;
        }
    }
    return {};
}
