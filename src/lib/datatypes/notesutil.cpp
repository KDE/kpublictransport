/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "notesutil_p.h"

#include <QRegularExpression>
#include <QString>
#include <QStringList>

using namespace KPublicTransport;


QString NotesUtil::normalizeNote(const QString &note)
{
    auto n = note;
    n.replace(QLatin1String("&nbsp;"), QLatin1String(" "));
    n.replace(QLatin1String("  "), QLatin1String(" "));

    if (!note.contains(QLatin1String("href"))) { // only mess with rich text if this isn't marked up already
        static QRegularExpression linkRegExp(QStringLiteral("(?:https?://)?(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,}(:?/[^ \"<>]+)?"));
        const auto match = linkRegExp.match(n);
        if (match.hasMatch()) {
            n.replace(match.capturedStart(), match.capturedLength(), QLatin1String("<a href=\"")
                + (match.capturedView().startsWith(QLatin1String("http")) ? QString() : QStringLiteral("https://"))
                + match.capturedView()
                + QLatin1String("\">") + match.capturedView() + QLatin1String("</a>"));
        }
    }

    // strip <span> tags
    static QRegularExpression spanExp(QStringLiteral("</?span[^>]*>"));
    n.remove(spanExp);
    static QRegularExpression styleAttrExp(QStringLiteral(" style=\"[^>\"]*\""));
    n.remove(styleAttrExp);

    // clean up extra line breaks and empty paragraphs
    static QRegularExpression consecutiveBrExp(QStringLiteral("<br[^>]*> *(?:<br[^>]*>|\n)"));
    while (n.contains(consecutiveBrExp)) {
        n.replace(consecutiveBrExp, QStringLiteral("<br/>"));
    }
    static QRegularExpression leadinBrExp(QStringLiteral("<p> *<br[^>]*>"));
    static QRegularExpression trailingBrExp(QStringLiteral("<br[^>]*> *</p>"));
    static QRegularExpression trailingBrExp2(QStringLiteral("<br[^>]*> *<p>"));
    n.replace(leadinBrExp, QStringLiteral("<p>"));
    n.replace(trailingBrExp, QStringLiteral("</p>"));
    n.replace(trailingBrExp2, QStringLiteral("<p>"));
    static QRegularExpression emptyParaExp(QStringLiteral("<p> *</p>"));
    n.remove(emptyParaExp);

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
        const auto idx = NotesUtil::needsAdding(res, r);
        if (idx >= 0) {
            NotesUtil::performAdd(res, r, idx);
        }
    }
    return res;
}
