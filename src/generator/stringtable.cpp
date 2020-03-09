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

#include "stringtable.h"

#include <QByteArray>
#include <QIODevice>
#include <QString>

void StringTable::addString(const QString &s)
{
    const auto b = s.toUtf8();
    if (std::find(m_strings.begin(), m_strings.end(), b) != m_strings.end()) {
        return;
    }
    m_strings.push_back(b);
}

std::size_t StringTable::stringOffset(const QString &s) const
{
    const auto b = s.toUtf8();
    std::size_t offset = 0;
    for (const auto &it : m_strings) {
        if (it == b) {
            return offset;
        }
        offset += it.size() + 1;
    }

    return 0;
}

void StringTable::writeCode(const QString &name, QIODevice *out) const
{
    out->write("static const char ");
    out->write(name.toUtf8());
    out->write("[] =\n");
    for (const auto &it : m_strings) {
        out->write("    \"");
        out->write(it);
        out->write("\\0\"\n");
    }
    out->write(";\n");
}
