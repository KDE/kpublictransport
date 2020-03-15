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

#include "notesutil_p.h"

#include <QRegularExpression>
#include <QString>
#include <QStringList>

using namespace KPublicTransport;


QString NotesUtil::normalizeNote(const QString &note)
{
    auto n = note;
    n.replace(QLatin1String("  "), QLatin1String(" "));

    if (!note.contains(QLatin1String("href"))) { // only mess with rich text if this isn't marked up already
        static QRegularExpression linkRegExp(QStringLiteral("(?:https?://)?(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,}(:?/[^ \"<>]+)?"));
        const auto match = linkRegExp.match(n);
        if (match.hasMatch()) {
            n.replace(match.capturedStart(), match.capturedLength(), QLatin1String("<a href=\"")
                + (match.capturedRef().startsWith(QLatin1String("http")) ? QString() : QLatin1String("https://"))
                + match.capturedRef().toString()
                + QLatin1String("\">") + match.capturedRef() + QLatin1String("</a>"));
        }
    }

    // strip <span> tags
    static QRegularExpression spanExp(QStringLiteral("</?span[^>]*>"));
    n.remove(spanExp);

    return n.trimmed();
}

int NotesUtil::needsAdding(const QStringList &notes, const QString &note)
{
    if (note.isEmpty()) {
        return -1;
    }

    for (auto it = notes.begin(); it != notes.end(); ++it) {
        if ((*it).contains(note)) {
            return -1;
        }
        if (note.contains(*it)) {
            return std::distance(notes.begin(), it);
        }
    }

    return notes.size();
}

void NotesUtil::performAdd(QStringList &notes, const QString &note, int index)
{
    if (index < 0) {
        return;
    }
    if (index >= notes.size()) {
        notes.push_back(note);
    } else {
        notes[index] = note;
    }
}

QStringList NotesUtil::mergeNotes(const QStringList &lhs, const QStringList &rhs)
{
    if (lhs.isEmpty()) {
        return rhs;
    }
    if (rhs.isEmpty()) {
        return lhs;
    }

    auto res = lhs;
    for (const auto &r : rhs) {
        if (!res.contains(r)) {
            res.push_back(r);
        }
    }
    return res;
}
