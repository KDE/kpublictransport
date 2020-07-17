/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSM_OSMPBFPARSER_H
#define KOSM_OSMPBFPARSER_H

#include "datatypes.h"

namespace OSMPBF {
class PrimitiveBlock;
class PrimitiveGroup;
}

namespace OSM {

/** Parser of .osm.pbf files.
 *  @see https://wiki.openstreetmap.org/wiki/PBF_Format
 */
class OsmPbfParser
{
public:
    explicit OsmPbfParser(DataSet *dataSet);

    /** Parse the given binary content.
     *  Feed this with QFile::map() for example.
     */
    void parse(const uint8_t *data, std::size_t len);

private:
    bool parseBlob(const uint8_t *&it, const uint8_t *end);
    void parsePrimitiveBlock(const uint8_t *data, std::size_t len);
    void parseDenseNodes(const OSMPBF::PrimitiveBlock &block,  const OSMPBF::PrimitiveGroup &group);
    void parseWays(const OSMPBF::PrimitiveBlock &block, const OSMPBF::PrimitiveGroup &group);
    void parseRelations(const OSMPBF::PrimitiveBlock &block, const OSMPBF::PrimitiveGroup &group);

    DataSet *m_dataSet = nullptr;
    QByteArray m_zlibBuffer;
};

}

#endif // KOSM_OSMPBFPARSER_H
