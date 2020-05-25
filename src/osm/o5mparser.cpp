/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#include "o5mparser.h"
#include "datatypes.h"

#include <QDebug>

#include <cstring>

using namespace OSM;

enum : uint8_t {
    O5M_RESET = 0xff,
    O5M_NODE = 0x10,
    O5M_WAY = 0x11,
    O5M_RELATION = 0x12,
    O5M_BOUNDING_BOX = 0xdb,
    O5M_TIMESTAMP = 0xdc,
    O5M_HEADER = 0xe0,
    O5M_NUMBER_CONTINUATION = 0b1000'0000,
    O5M_NUMBER_MASK = 0b0111'1111,
    O5M_SIGNED_BIT = 0b1,
};

enum : uint16_t {
    O5M_STRING_TABLE_SIZE = 15000,
    O5M_STRING_TABLE_MAXLEN = 250,
};

O5mParser::O5mParser(DataSet *dataSet)
    : m_dataSet(dataSet)
{
    m_stringLookupTable.resize(O5M_STRING_TABLE_SIZE);
}

void O5mParser::parse(const uint8_t* data, std::size_t len)
{
    qDebug() << "begin parsing";
    const auto endIt = data + len;
    for (auto it = data; it < endIt - 1;) {
        const auto blockType = (*it);
        if (blockType == O5M_RESET) {
            resetDeltaCodingState();
            ++it;
            continue;
        }

        auto blockSize = readUnsigned(++it, endIt);
        if (blockSize >= (uint64_t)(endIt - it)) {
            qWarning() << "premature end of file, or blocksize too large" << (endIt - it) << blockType << blockSize;
            break;
        }
        switch (blockType) {
            case O5M_HEADER:
                if (blockSize != 4 || std::strncmp(reinterpret_cast<const char*>(it), "o5m2", 4) != 0) {
                    qWarning() << "Invalid file header";
                    return;
                }
                break;
            case O5M_BOUNDING_BOX:
            case O5M_TIMESTAMP:
                // not of interest at the moment
                break;
            case O5M_NODE:
                readNode(it, it + blockSize);
                break;
            case O5M_WAY:
                readWay(it, it + blockSize);
                break;
            case O5M_RELATION:
                readRelation(it, it + blockSize);
                break;
            default:
                qDebug() << "unhandled o5m block type:" << (it - data) << blockType << blockSize;
        }

        it += blockSize;
    }

    qDebug() << "parsing done";
}

uint64_t O5mParser::readUnsigned(const uint8_t *&it, const uint8_t *endIt) const
{
    uint64_t result = 0;
    int i = 0;
    for (; it < endIt && ((*it) & O5M_NUMBER_CONTINUATION); ++it, ++i) {
        result |= ((*it) & O5M_NUMBER_MASK) << (i * 7);
    }
    result |= ((uint64_t)(*it++) & O5M_NUMBER_MASK) << (i * 7);
    return result;
}

int64_t O5mParser::readSigned(const uint8_t *&it, const uint8_t *endIt) const
{
    const uint64_t u = readUnsigned(it, endIt);
    return (u & O5M_SIGNED_BIT) ? (-(u >> 1) -1) : (u >> 1);
}

template <typename T>
T O5mParser::readDelta(const uint8_t *&it, const uint8_t *endIt, T &deltaState)
{
    deltaState += (T)readSigned(it, endIt);
    return deltaState;
}

const char* O5mParser::readString(const uint8_t *&it, const uint8_t *endIt)
{
    auto ref = readUnsigned(it, endIt);
    if (ref) {
        return m_stringLookupTable[(m_stringLookupPosition + O5M_STRING_TABLE_SIZE - ref) % O5M_STRING_TABLE_SIZE];
    } else {
        const auto s = reinterpret_cast<const char*>(it);
        const auto len = std::strlen(s);
        if (len <= O5M_STRING_TABLE_MAXLEN) {
            m_stringLookupTable[m_stringLookupPosition] = s;
            m_stringLookupPosition = (m_stringLookupPosition + 1) % O5M_STRING_TABLE_SIZE;
        }
        it += len + 1;
        return s;
    }
}

std::pair<const char*, const char*> O5mParser::readStringPair(const uint8_t *&it, const uint8_t *endIt)
{
    auto ref = readUnsigned(it, endIt);
    if (ref) {
        const auto s = m_stringLookupTable[(m_stringLookupPosition + O5M_STRING_TABLE_SIZE - ref) % O5M_STRING_TABLE_SIZE];
        const auto len1 = std::strlen(s);
        return std::make_pair(s, s + len1 + 1);
    } else {
        const auto s = reinterpret_cast<const char*>(it);
        const auto len1 = std::strlen(s);
        const auto len2 = std::strlen(s + len1 + 1);

        if (len1 + len2 <= O5M_STRING_TABLE_MAXLEN) {
            m_stringLookupTable[m_stringLookupPosition] = s;
            m_stringLookupPosition = (m_stringLookupPosition + 1) % O5M_STRING_TABLE_SIZE;
        }

        it += len1 + len2 + 2;
        return std::make_pair(s, s + len1 + 1);
    }
}

void O5mParser::skipVersionInformation(const uint8_t *&it, const uint8_t *end)
{
    if (it >= end) { return; }
    const auto version = readUnsigned(it, end);
    if (version > 0) {
        qWarning() << "skipping changeset data not implemented yet!";
        //    timestamp (seconds since 1970, signed, delta-coded)
        //    author information – only if timestamp is not 0:
        //        changeset (signed, delta-coded)
        //        uid, user (string pair)
        it = end;
    }
}

void O5mParser::readNode(const uint8_t *begin, const uint8_t *end)
{
    auto it = begin;
    const OSM::Id id = readDelta(it, end, m_nodeIdDelta);
    skipVersionInformation(it, end);
    if (it >= end) { return; }

    const auto lat = readDelta(it, end, m_latDelata);
    const auto lon = readDelta(it, end, m_lonDelta);
    qDebug() << "    node" << id << (lat / 1.0e7) << (lon / 1.0e7);
    if (it >= end) { return; }

    while (it < end) {
        const auto tag = readStringPair(it, end);
        qDebug() << "      tag" << tag.first << tag.second;
    }
}

void O5mParser::readWay(const uint8_t *begin, const uint8_t *end)
{
    auto it = begin;
    const OSM::Id id = readDelta(it, end, m_wayIdDelta);
    skipVersionInformation(it, end);
    if (it >= end) { return; }

    const auto nodesBlockSize = readUnsigned(it, end);
    qDebug() << "    way" << id << nodesBlockSize;
    if (it + nodesBlockSize > end) { return; }

    const auto nodesBlockEnd = it + nodesBlockSize;
    while(it < nodesBlockEnd) {
        const OSM::Id nodeId = readDelta(it, end, m_wayNodeIdDelta);
        qDebug() << "      nd" << nodeId;
    }

    while (it < end) {
        const auto tag = readStringPair(it, end);
        qDebug() << "      tag" << tag.first << tag.second;
    }
}

void O5mParser::readRelation(const uint8_t *begin, const uint8_t *end)
{
    auto it = begin;
    const OSM::Id id = readDelta(it, end, m_relIdDelta);
    skipVersionInformation(it, end);
    if (it >= end) { return; }

    const auto relBlockSize = readUnsigned(it, end);
    qDebug() << "    relation" << id << relBlockSize;
    if (it + relBlockSize > end) { return; }

    const auto relBlockEnd = it + relBlockSize;
    while (it < relBlockEnd) {
        const OSM::Id memId = readDelta(it, end, m_relMemberIdDelta);
        const auto typeAndRole = readString(it, end);
        qDebug() << "     mem" << memId << typeAndRole[0] << (typeAndRole + 1);
    }

    while (it < end) {
        const auto tag = readStringPair(it, end);
        qDebug() << "      tag" << tag.first << tag.second;
    }
}

void O5mParser::resetDeltaCodingState()
{
    m_nodeIdDelta = 0;
    m_latDelata = 0;
    m_lonDelta = 0;

    m_wayIdDelta = 0;
    m_wayNodeIdDelta = 0;

    m_relIdDelta = 0;
    m_relMemberIdDelta = 0;
}
