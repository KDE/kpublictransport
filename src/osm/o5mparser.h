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

#ifndef OSM_O5MPARSER_H
#define OSM_O5MPARSER_H

#include <cstddef>
#include <cstdint>
#include <vector>

class O5mParserTest;

namespace OSM {

class DataSet;

/** Zero-copy parser of O5M binary files.
 *  @see https://wiki.openstreetmap.org/wiki/O5m
 */
class O5mParser
{
public:
    explicit O5mParser(DataSet *dataSet);

    /** Parse the given binary content.
     *  Feed this with QFile::map() for example.
     */
    void parse(const uint8_t *data, std::size_t len);

private:
    friend class ::O5mParserTest;

    uint64_t readUnsigned(const uint8_t *&it, const uint8_t *endIt) const;
    int64_t readSigned(const uint8_t *&it, const uint8_t *endIt) const;
    template <typename T>
    T readDelta(const uint8_t *&it, const uint8_t *endIt, T &deltaState);

    const char* readString(const uint8_t *&it, const uint8_t *endIt);
    std::pair<const char*, const char*> readStringPair(const uint8_t *&it, const uint8_t *endIt);

    void skipVersionInformation(const uint8_t *&it, const uint8_t *end);
    template <typename Elem>
    void readTagOrBbox(Elem &e, const uint8_t *&it, const uint8_t *endIt);

    void readNode(const uint8_t *begin, const uint8_t *end);
    void readWay(const uint8_t *begin, const uint8_t *end);
    void readRelation(const uint8_t *begin, const uint8_t *end);

    DataSet *m_dataSet = nullptr;

    // delta coding state
    void resetDeltaCodingState();

    int64_t m_nodeIdDelta = 0;
    int32_t m_latDelata = 0; // this can overflow, but that is intentional according to the spec!
    int32_t m_lonDelta = 0;

    int64_t m_wayIdDelta = 0;
    int64_t m_wayNodeIdDelta = 0;

    int64_t m_relIdDelta = 0;
    int64_t m_relMemberIdDelta = 0;

    std::vector<const char*> m_stringLookupTable;
    uint16_t m_stringLookupPosition = 0;
};

}

#endif // OSM_O5MPARSER_H
