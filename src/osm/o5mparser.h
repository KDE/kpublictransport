/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_O5MPARSER_H
#define OSM_O5MPARSER_H

#include <cstddef>
#include <cstdint>
#include <vector>

class O5mParserTest;

namespace OSM {

class DataSet;
class DataSetMergeBuffer;

/** Zero-copy parser of O5M binary files.
 *  @see https://wiki.openstreetmap.org/wiki/O5m
 */
class O5mParser
{
public:
    explicit O5mParser(DataSet *dataSet);

    /** Sets a merge buffer.
     *  When set, the parser will insert all elements into that buffer
     *  rather than in the OSM::DataSet specified in the constructor.
     *  It is then your responsibility to properly integrate those.
     *  @note The OSM::DataSet is used for generating tag keys and for memory
     *  managing strings in this case as well. So the generated elements are
     *  tied to the OSM::DataSet in any case.
     */
    void setMergeBuffer(OSM::DataSetMergeBuffer *buffer);

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
    DataSetMergeBuffer *m_mergeBuffer = nullptr;

    // delta coding state
    void resetDeltaCodingState();

    int64_t m_nodeIdDelta = 0;
    int32_t m_latDelata = 0; // this can overflow, but that is intentional according to the spec!
    int32_t m_lonDelta = 0;

    int64_t m_wayIdDelta = 0;
    int64_t m_wayNodeIdDelta = 0;

    int64_t m_relIdDelta = 0;
    int64_t m_relNodeMemberIdDelta = 0;
    int64_t m_relWayMemberIdDelta = 0;
    int64_t m_relRelMemberIdDelta = 0;

    std::vector<const char*> m_stringLookupTable;
    uint16_t m_stringLookupPosition = 0;
};

}

#endif // OSM_O5MPARSER_H
