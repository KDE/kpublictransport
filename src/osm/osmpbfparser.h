/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSM_OSMPBFPARSER_H
#define KOSM_OSMPBFPARSER_H

#include "abstractreader.h"
#include "datatypes.h"

namespace OSMPBF {
class PrimitiveBlock;
class PrimitiveGroup;
}

namespace OSM {

/** Parser of .osm.pbf files.
 *  @see https://wiki.openstreetmap.org/wiki/PBF_Format
 */
class OsmPbfParser : public AbstractReader
{
public:
    explicit OsmPbfParser(DataSet *dataSet);

private:
    void readFromData(const uint8_t *data, std::size_t len) override;

    bool parseBlob(const uint8_t *&it, const uint8_t *end);
    void parsePrimitiveBlock(const uint8_t *data, std::size_t len);
    void parseDenseNodes(const OSMPBF::PrimitiveBlock &block,  const OSMPBF::PrimitiveGroup &group);
    void parseWays(const OSMPBF::PrimitiveBlock &block, const OSMPBF::PrimitiveGroup &group);
    void parseRelations(const OSMPBF::PrimitiveBlock &block, const OSMPBF::PrimitiveGroup &group);

    QByteArray m_zlibBuffer;
};

}

#endif // KOSM_OSMPBFPARSER_H
