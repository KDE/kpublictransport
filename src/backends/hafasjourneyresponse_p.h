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

#ifndef KPUBLICTRANSPORT_HAFASJOURNEYRESPONSE_P_H
#define KPUBLICTRANSPORT_HAFASJOURNEYRESPONSE_P_H

#include <QTextCodec>

#include <cstdint>

namespace KPublicTransport {

#pragma pack(push)
#pragma pack(1)

// occurs once at offset 0
struct HafasJourneyResponseHeader
{
    uint16_t version;
    uint16_t departureNameStr;
    uint16_t padding1;
    uint16_t departureType;
    uint32_t departureLongitude;
    uint32_t departureLatitude;
    uint16_t arrivalNameStr;
    uint16_t padding2;
    uint16_t arrivalType;
    uint32_t arrivalLongitude;
    uint32_t arrivalLatitude;
    // amount of journeys in the response
    uint16_t numJourneys;
    uint32_t serviceDaysTableOffset;
    // offset to HafasJourneyResponseStringTable
    uint32_t stringTableOffset;
    // base date for all times in the response, in days after 1980-01-01
    uint16_t date;
    uint8_t padding3[12];
    // offset to HafasJourneyResponseStation table
    uint32_t stationTableOffset;
    uint32_t commentTableOffset;
    uint8_t padding4[8];
    // offset to HafasJourneyResponseExtendedHeader
    uint32_t extendedHeaderOffset;
};
static_assert(sizeof(HafasJourneyResponseHeader) == 0x4a, "size of response header is wrong");
static_assert(alignof(HafasJourneyResponseHeader) == 1, "broken alignment for binary response struct");

// extended header, occurs once at offset HafasJourneyResponseHeader::extendedHeaderOffset
struct HafasJourneyResponseExtendedHeader
{
    // length of the extended header (should >= sizeof(HafasJourneyResponseExtendedHeader)
    uint32_t length;
    uint32_t padding1;
    uint16_t seqNum;
    uint16_t requestIdStr;
    // offset to HafasJourneyResponseDetailsHeader
    uint32_t detailsOffset;
    // error code for the journey query, 0 means success
    uint16_t errorCode;
    uint16_t padding2;
    uint32_t disruptionTableOffset;
    uint8_t padding3[8];
    // string table index for the name of the encoding used in the string table
    uint16_t encodingStr;
    uint16_t ldStr;
    // base offset for attributes table
    uint32_t attributesOffset;
    uint32_t padding4;
    // if > 0 this is an index into a uint16_t table with the journey attribute offsets
    uint32_t journeyAttributesIndexOffset;
};
static_assert(alignof(HafasJourneyResponseExtendedHeader) == 1, "broken alignment for binary response struct");

// journey details header, occurs once at offset HafasJourneyResponseExtendedHeader::detailsOffset
struct HafasJourneyResponseDetailsHeader
{
    uint16_t version;
    uint16_t padding;
    uint16_t journeyDetailsIndexOffset;
    uint16_t sectionDetailsOffset;
    uint16_t sectionDetailsSize;
    uint16_t stopsSize;
    uint16_t stopsOffset;
};
static_assert(alignof(HafasJourneyResponseDetailsHeader) == 1, "broken alignment for binary response struct");

// occurs HafasJourneyResponseHeader::numJourneys times, right after HafasJourneyResponseHeader at offset 0x4a
struct HafasJourneyResponseJourney
{
    uint16_t serviceDaysTableOffset;
    // offset for the HafasJourneyResponseSection table to start
    uint32_t sectionsOffset;
    // number of sections in this journey
    uint16_t numSections;
    uint16_t numChanges;
    uint16_t duration;
};
static_assert(sizeof(HafasJourneyResponseJourney) == 12, "size of journey structure is wrong");
static_assert(alignof(HafasJourneyResponseJourney) == 1, "broken alignment for binary response struct");

// occurs HafasJourneyResponseJourney::numSections times, after HafasJourneyResponseHeader + HafasJourneyResponseJourney::sectionsOffset
struct HafasJourneyResponseSection
{
    // hours * 100 + minutes
    uint16_t scheduledDepartureTime;
    // index into station table
    uint16_t departureStationIdx;
    uint16_t scheduledArrivalTime;
    uint16_t arrivalStationIdx;
    // section mode, see enum below
    uint16_t type;
    // index into string table
    uint16_t lineNameStr;
    // index into string table
    uint16_t scheduledDeparturePlatformStr;
    uint16_t scheduledArrivalPlatformStr;
    // section attribute table index
    uint16_t sectionAttributeIndex;
    uint16_t commentIdx;
};
static_assert(sizeof(HafasJourneyResponseSection) == 20, "size of section structure is wrong");
static_assert(alignof(HafasJourneyResponseSection) == 1, "broken alignment for binary response struct");

// values for HafasJourneyResponseSection::type
namespace HafasJourneyResponseSectionMode {
enum Mode {
    Walk = 1,
    PublicTransport = 2,
    Transfer1 = 3,
    Transfer2 = 4
};
}

struct HafasJourneyResponseSectionDetail
{
    // see above for format
    uint16_t expectedDepartureTime;
    uint16_t expectedArrivalTime;
    // indexes into string table
    uint16_t expectedDeparturePlatformStr;
    uint16_t expectedArrivalPlatformStr;
    uint16_t flags;
    uint16_t padding1;
    uint16_t stopIndex;
    uint16_t numStops;
};
static_assert(alignof(HafasJourneyResponseSectionDetail) == 1, "broken alignment for binary response struct");

// occurs multiple times at offset HafasJourneyResponseHeader::stationTableOffset
struct HafasJourneyResponseStation
{
    // station name as index into the string table
    uint16_t nameStr;
    uint32_t id;
    // geo coordinates * 1000000
    uint32_t longitude;
    uint32_t latitude;
};
static_assert(sizeof(HafasJourneyResponseStation) == 14, "size of station structure is wrong");
static_assert(alignof(HafasJourneyResponseStation) == 1, "broken alignment for binary response struct");

// attribute table entries: pair if string table indexes
struct HafasJourneyResponseAttribute
{
    uint16_t keyStr;
    uint16_t valueStr;
};
static_assert(sizeof(HafasJourneyResponseAttribute) == 4, "size of attribute structure is wrong");
static_assert(alignof(HafasJourneyResponseAttribute) == 1, "broken alignment for binary response struct");

// disruption table entry
struct HafasJourneyResponseDisruption
{
    uint16_t padding1;
    // index of the affected section
    uint16_t section;
    uint16_t bitmask;
    // indexes into string table
    uint16_t startStr;
    uint16_t endStr;
    uint16_t idStr;
    uint16_t titleStr;
    uint16_t messageStr;
    // offset from start of disruption table to the next element
    uint16_t nextOffset;
    // index into attribute table
    uint16_t disruptionAttributeIndex;

};
static_assert(alignof(HafasJourneyResponseDisruption) == 1, "broken alignment for binary response struct");

#pragma pack(pop)

// occurs once, at offset HafasJourneyResponseHeader::stringTableOffset
class HafasJourneyResponseStringTable
{
public:
    explicit inline HafasJourneyResponseStringTable(const QByteArray &data, uint32_t stringTableOffset, uint16_t codecIdx) :
        m_data(data.constData() + stringTableOffset)
    {
        m_codec = QTextCodec::codecForName(QByteArray(m_data + codecIdx));
    }

    inline QString lookup(uint16_t index)
    {
        // null terminated strings in the given codec
        return m_codec->toUnicode(m_data + index);
    }

private:
    const char *m_data;
    QTextCodec* m_codec;
};

}

#endif // KPUBLICTRANSPORT_HAFASJOURNEYRESPONSE_P_H
