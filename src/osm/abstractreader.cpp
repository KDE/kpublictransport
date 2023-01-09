/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "abstractreader.h"
#include "datatypes.h"
#include "datasetmergebuffer.h"

#include <QDebug>
#include <QIODevice>

#include <cassert>
#include <cstring>

using namespace OSM;

namespace OSM {
/** Readonly QIODevice adapter for memory-mapped data. */
class MemoryMapIoDevice : public QIODevice
{
    Q_OBJECT
public:
    explicit MemoryMapIoDevice(const uint8_t *data, std::size_t size, QObject *parent = nullptr)
        : QIODevice(parent)
        , m_data(data)
        , m_size(size)
    {}
    ~MemoryMapIoDevice() = default;

    bool open(QIODevice::OpenMode mode) override
    {
        if (mode != QIODevice::ReadOnly) {
            return false;
        }
        return QIODevice::open(mode);
    }

    bool isSequential() const override
    {
        return false;
    }

    qint64 size() const override
    {
        return m_size;
    }

protected:
    qint64 readData(char *data, qint64 maxlen) override
    {
        const auto readSize = std::min<qint64>(m_size - pos(), maxlen);
        if (readSize < 0) {
            return 0;
        }
        std::memcpy(data, reinterpret_cast<const char*>(m_data + pos()), readSize);
        return readSize;
    }

    qint64 writeData([[maybe_unused]] const char *data, [[maybe_unused]] qint64 len) override
    {
        return 0;
    }

private:
    const uint8_t *m_data = nullptr;
    const std::size_t m_size = {};
};
}


AbstractReader::AbstractReader(OSM::DataSet *dataSet)
    : m_dataSet(dataSet)
{
    assert(dataSet);
}

AbstractReader::~AbstractReader() = default;

void AbstractReader::setMergeBuffer(OSM::DataSetMergeBuffer *buffer)
{
    m_mergeBuffer = buffer;
}

void AbstractReader::read(const uint8_t *data, std::size_t len)
{
    readFromData(data, len);
    if (!m_error.isEmpty()) {
        qWarning() << m_error;
    }
}

void AbstractReader::read(QIODevice *io)
{
    readFromIODevice(io);
    if (!m_error.isEmpty()) {
        qWarning() << m_error;
    }
}

void AbstractReader::readFromData(const uint8_t *data, std::size_t len)
{
    assert(data);
    MemoryMapIoDevice io(data, len);
    io.open(QIODevice::ReadOnly);
    readFromIODevice(&io);
}

void AbstractReader::readFromIODevice(QIODevice *io)
{
    assert(io);
    QByteArray data = io->readAll();
    readFromData(reinterpret_cast<const uint8_t*>(data.constData()), data.size());
}

QString AbstractReader::errorString() const
{
    return m_error;
}

void AbstractReader::addNode(OSM::Node &&node)
{
    m_mergeBuffer ? m_mergeBuffer->nodes.push_back(std::move(node)) : m_dataSet->addNode(std::move(node));
}

void AbstractReader::addWay(OSM::Way &&way)
{
    m_mergeBuffer ? m_mergeBuffer->ways.push_back(std::move(way)) : m_dataSet->addWay(std::move(way));
}

void AbstractReader::addRelation(OSM::Relation &&relation)
{
    m_mergeBuffer ? m_mergeBuffer->relations.push_back(std::move(relation)) : m_dataSet->addRelation(std::move(relation));
}

#include "abstractreader.moc"
