/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "indexeddatatable.h"

#include <QByteArray>
#include <QIODevice>
#include <QString>

void StringTable::addString(const QString &s)
{
    addEntry(s.toUtf8());
}

std::size_t StringTable::stringOffset(const QString &s) const
{
    return entryOffset(s.toUtf8());
}

void StringTable::writeCode(const char* name, QIODevice *out) const
{
    IndexedDataTable<QByteArray>::writeCode("char", name, out, [](const QByteArray &b, QIODevice *out) {
        out->write("\"");
        out->write(b);
        out->write("\\0\"");
    });
}
