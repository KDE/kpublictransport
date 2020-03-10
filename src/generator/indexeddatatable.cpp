/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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
