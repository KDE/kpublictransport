/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_ABSTRACTREADER_H
#define OSM_ABSTRACTREADER_H

#include "kosm_export.h"

#include <QString>

#include <cstdint>
#include <cstddef>

class QIODevice;

namespace OSM {

class DataSet;
class DataSetMergeBuffer;
class Node;
class Relation;
class Way;

/** Abstract base class for OSM file format readers. */
class KOSM_EXPORT AbstractReader
{
public:
    virtual ~AbstractReader();

    /** Sets a merge buffer.
     *  When set, the parser will insert all elements into that buffer
     *  rather than in the OSM::DataSet specified in the constructor.
     *  It is then your responsibility to properly integrate those.
     *  @note The OSM::DataSet is used for generating tag keys and for memory
     *  managing strings in this case as well. So the generated elements are
     *  tied to the OSM::DataSet in any case.
     */
    void setMergeBuffer(OSM::DataSetMergeBuffer *buffer);

    /** Read the given data.
     *  Useful e.g. for working on memory-mapped data.
     */
    void read(const uint8_t *data, std::size_t len);

    /** Read data from the given QIODevice. */
    void read(QIODevice *io);

    /** Error message in case parsing failed for some reason. */
    QString errorString() const;

protected:
    explicit AbstractReader(DataSet *dataSet);

    /** Implement for actual parsing.
     *  The default implementation convert into the respective other form,
     *  so implementing one is enough.
     */
    virtual void readFromData(const uint8_t *data, std::size_t len);
    virtual void readFromIODevice(QIODevice *io);

    /** Add read elements to the merge buffer if set, or the dataset otherwise. */
    void addNode(OSM::Node &&node);
    void addWay(OSM::Way &&way);
    void addRelation(OSM::Relation &&relation);

    DataSet *m_dataSet = nullptr;
    QString m_error;

private:
    DataSetMergeBuffer *m_mergeBuffer = nullptr;
};

}

#endif // OSM_ABSTRACTREADER_H
