/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
