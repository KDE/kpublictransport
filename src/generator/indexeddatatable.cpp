/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "indexeddatatable.h"

#include <QByteArray>
#include <QString>

void StringTable::addString(const QString &s)
{
    addEntry(s.toUtf8());
}

std::size_t StringTable::stringOffset(const QString &s) const
{
    return entryOffset(s.toUtf8());
}

static void writeQuoted(const QByteArray &b, QIODevice *out)
{
    for (char c : b) {
        switch (c) {
            case '"':
            case '\\':
                out->write("\\");
        }
        out->write(&c, 1);
    }
}

void StringTable::writeCode(const char* name, QIODevice *out) const
{
    IndexedDataTable<QByteArray>::writeCode("char", name, out, [](const QByteArray &b, QIODevice *out) {
        out->write("\"");
        writeQuoted(b, out);
        out->write("\\0\"");
    });
}
