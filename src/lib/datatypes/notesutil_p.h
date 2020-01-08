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

#ifndef KPUBLICTRANSPORT_NOTESUTIL_P_H
#define KPUBLICTRANSPORT_NOTESUTIL_P_H

class QString;
class QStringList;

namespace KPublicTransport {

/** Utilities around free-form notes attached to transport objects.
 *  Used for code sharing between those objects.
 */
namespace NotesUtil
{
    /** Normalize a note string. */
    QString normalizeNote(const QString &note);

    /** Check if a note should be added, or replace an existing entry. */
    int needsAdding(const QStringList &notes, const QString &note);
    /** Add or replace a note. */
    void performAdd(QStringList &notes, const QString &note, int index);

    /** Merge two notes. */
    QStringList mergeNotes(const QStringList &lhs, const QStringList &rhs);}

}

#endif // KPUBLICTRANSPORT_NOTESUTIL_P_H
