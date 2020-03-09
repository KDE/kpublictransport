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

#ifndef STRINGTABLE_H
#define STRINGTABLE_H

#include <vector>

class QByteArray;
class QIODevice;
class QString;

/** String table generation. */
class StringTable
{
public:
    void addString(const QString &s);
    std::size_t stringOffset(const QString &s) const;
    void writeCode(const QString &name, QIODevice *out) const;

private:
    std::vector<QByteArray> m_strings;
};

#endif // STRINGTABLE_H
