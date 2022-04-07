/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QStringRef name() const;
#else
    QStringView name() const;
#endif
    /** Same as QXmlStreamReader::readElementText. */
    QString readElementText(QXmlStreamReader::ReadElementTextBehaviour behaviour = QXmlStreamReader::ErrorOnUnexpectedElement);

    /** Checks if the current element has the specified name. */
    bool isElement(const char *name) const;

private:
    explicit ScopedXmlStreamReader(QXmlStreamReader &reader, ScopedXmlStreamReader *parent);

    QXmlStreamReader &m_reader;
    ScopedXmlStreamReader *m_parent = nullptr;
    int m_depth = 1;
    bool m_subReaderLock = false;
};

}

#endif // KPUBLICTRANSPORT_SCOPEDXMLSTREAMREADER_H
