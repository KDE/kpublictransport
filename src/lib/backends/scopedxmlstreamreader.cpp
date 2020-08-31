/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "scopedxmlstreamreader.h"

#include <QDebug>

using namespace KPublicTransport;

ScopedXmlStreamReader::ScopedXmlStreamReader(QXmlStreamReader &reader)
    : m_reader(reader)
{
}

ScopedXmlStreamReader::ScopedXmlStreamReader(QXmlStreamReader &reader, ScopedXmlStreamReader *parent)
    : m_reader(reader)
    , m_parent(parent)
{
    Q_ASSERT_X(!m_parent->m_subReaderLock, "ScopedXmlStreamReader", "Only one sub-reader can be active at the same time!");
    m_parent->m_subReaderLock = true;
}


ScopedXmlStreamReader::ScopedXmlStreamReader(ScopedXmlStreamReader&&) noexcept = default;

ScopedXmlStreamReader::~ScopedXmlStreamReader()
{
    while (!m_reader.atEnd() && !m_reader.hasError() && m_depth > 1) {
        if (m_reader.isStartElement()) {
            ++m_depth;
        }
        if (m_reader.isEndElement()) {
            m_depth--;
            if (m_depth == 1) {
                break;
            }
        }
        m_reader.readNext();
    }

    if (m_parent) {
        m_parent->m_subReaderLock = false;
    }
}

bool ScopedXmlStreamReader::readNextElement()
{
    Q_ASSERT_X(!m_subReaderLock, "ScopedXmlStreamReader", "Operations while a sub-reader is active are forbidden!");

    // previous element was  consumed, so adapt the depth counter before we continue reading
    if (m_reader.isEndElement()) {
        --m_depth;
    }

    while (!m_reader.atEnd() && !m_reader.hasError() && m_depth > 0) {
        m_reader.readNext();
        if (m_reader.isStartElement()) {
            ++m_depth;
            return true;
        }
        if (m_reader.isEndElement()) {
            m_depth--;
        }
    }

    return false;
}

bool ScopedXmlStreamReader::readNextSibling()
{
    // if we are at the root node still, next sibling makes no sense, jump to the first child element first
    if (m_depth == 1 && m_reader.isStartElement()) {
        return readNextElement();
    }
    // if there is no progress compared to last round, skip that element first
    if (m_depth > 1 && m_reader.isStartElement()) {
        m_reader.skipCurrentElement();
        --m_depth;
    } else if (m_reader.isEndElement()) { // content was consumed
        --m_depth;
    }

    const auto currentDepth = m_depth;
    while (!m_reader.atEnd() && !m_reader.hasError() && m_depth >= currentDepth) {
        m_reader.readNext();
        if (m_reader.isStartElement()) {
            ++m_depth;
            if (m_depth == (currentDepth + 1)) {
                return true;
            }
        } else if (m_reader.isEndElement()) {
            --m_depth;
        }
    }

    return false;
}

ScopedXmlStreamReader ScopedXmlStreamReader::subReader()
{
    return ScopedXmlStreamReader(m_reader, this);
}

QXmlStreamAttributes ScopedXmlStreamReader::attributes() const
{
    Q_ASSERT_X(!m_subReaderLock, "ScopedXmlStreamReader", "Operations while a sub-reader is active are forbidden!");
    return m_reader.attributes();
}

QStringRef ScopedXmlStreamReader::name() const
{
    Q_ASSERT_X(!m_subReaderLock, "ScopedXmlStreamReader", "Operations while a sub-reader is active are forbidden!");
    return m_reader.name();
}

QString ScopedXmlStreamReader::readElementText(QXmlStreamReader::ReadElementTextBehaviour behaviour)
{
    Q_ASSERT_X(!m_subReaderLock, "ScopedXmlStreamReader", "Operations while a sub-reader is active are forbidden!");
    return m_reader.readElementText(behaviour);
}
