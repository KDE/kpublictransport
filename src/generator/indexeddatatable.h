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

#ifndef INDEXEDDATATABLE_H
#define INDEXEDDATATABLE_H

#include <QIODevice>

#include <functional>
#include <vector>

class QByteArray;
class QIODevice;
class QString;

/** Indexed data table, a generalized form of a string table.
 *  Entries are of varying length, so a terminating entry is required to separate them (such as a null byte in strings).
 *  Does suffix compression, ie. an entry "B" will be represented by pointing side another element "AB" if present.
 *  @tparam Entry must be iterable, element-wise comparable, copyable and have a size() method
 */
template <typename Entry>
class IndexedDataTable
{
public:
    inline void addEntry(const Entry &entry)
    {
        for (auto it = m_entries.begin(); it != m_entries.end(); ++it) {
            if (entry.size() <= (*it).size()) {
                if (std::equal((*it).begin() + ((*it).size() - entry.size()), (*it).end(), entry.begin())) {
                    return; // new entry is a suffix of (or equal to) an existing element
                }
            } else {
                if (std::equal(entry.begin() + (entry.size() - (*it).size()), entry.end(), (*it).begin())) {
                    (*it) = entry; // an existing element is a suffix of the new element
                    return;
                }
            }
        }
        m_entries.push_back(entry);
    }

    inline std::size_t entryOffset(const Entry &entry) const
    {
        std::size_t offset = 0;
        for (const auto &it : m_entries) {
            if (entry.size() <= it.size()) {
                const auto subOffset = it.size() - entry.size();
                if (std::equal(it.begin() + subOffset, it.end(), entry.begin())) {
                    return offset + subOffset;
                }
            }
            offset += it.size() + 1;
        }

        return std::numeric_limits<std::size_t>::max();
    }

    /** @param entryWrite must write the terminating element at the end! */
    inline void writeCode(const char* type, const char *name, QIODevice *out, std::function<void(const Entry &entry, QIODevice *out)> entryWriter) const
    {
        out->write("static const ");
        out->write(type);
        out->write(" ");
        out->write(name);
        out->write("[] = {\n");
        for (const auto &it : m_entries) {
            out->write("    ");
            entryWriter(it, out);
            out->write("\n");
        }
        out->write("};\n\n");
    }

private:
    std::vector<Entry> m_entries;
};

/** String table specialization. */
class StringTable : IndexedDataTable<QByteArray>
{
public:
    void addString(const QString &s);
    std::size_t stringOffset(const QString &s) const;
    void writeCode(const char *name, QIODevice *out) const;
};

#endif // INDEXEDDATATABLE_H
