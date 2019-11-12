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

#ifndef KPUBLICTRANSPORT_SCOPEDXMLSTREAMREADER_H
#define KPUBLICTRANSPORT_SCOPEDXMLSTREAMREADER_H

#include <QXmlStreamReader>

namespace KPublicTransport {

/** Safety wrapper around QXmlStreamReader to consume a element sub-tree. */
class ScopedXmlStreamReader
{
public:
    /** Construct a new ScopedXmlStreamReader from a QXmlStreamReader.
     *  Do not use @p reader API directly while this instance is alive.
     */
    explicit ScopedXmlStreamReader(QXmlStreamReader &reader);

    ScopedXmlStreamReader(const ScopedXmlStreamReader&) = delete;
    ScopedXmlStreamReader& operator=(const ScopedXmlStreamReader) = delete;
    ScopedXmlStreamReader(ScopedXmlStreamReader&&) noexcept;

    /** Destroying a ScopedXmlStreamReader will make it consume whatever remains of the
     *  current element sub-tree. The underlying QXmlStreamReader will be left pointing
     *  to the EndElement of the current sub-tree.
     */
    ~ScopedXmlStreamReader();

    /** Forward the reader to the start of the next element.
     *  @returns @c true if this succeeded, @c false if the input end has been reached or
     *  the element sub-tree this instance was created on has been entirely consumed.
     */
    bool readNextElement();

    /** Forward the reader to the start of the next sibling element, skipping over the sub trees.
     *  @returns @c true if this succeeded, @c false if the input end has been reached or
     *  the element sub-tree this instance was created on has been entirely consumed.
     */
    bool readNextSibling();

    /** Creates a ScopedXmlStreamReader for consuming the current sub-tree.
     *  Use this to recursively process element trees.
     *  Only one sub-reader can be active at a time, using this (or a parent) while
     *  a sub-reader is active is not allowed.
     */
    ScopedXmlStreamReader subReader();

    /** Same as QXmlStreamReader::attributes. */
    QXmlStreamAttributes attributes() const;
    /** Same as QXmlStreamReader::name. */
    QStringRef name() const;
    /** Same as QXmlStreamReader::readElementText. */
    QString readElementText(QXmlStreamReader::ReadElementTextBehaviour behaviour = QXmlStreamReader::ErrorOnUnexpectedElement);

private:
    explicit ScopedXmlStreamReader(QXmlStreamReader &reader, ScopedXmlStreamReader *parent);

    QXmlStreamReader &m_reader;
    ScopedXmlStreamReader *m_parent = nullptr;
    int m_depth = 1;
    bool m_subReaderLock = false;
};

}

#endif // KPUBLICTRANSPORT_SCOPEDXMLSTREAMREADER_H
