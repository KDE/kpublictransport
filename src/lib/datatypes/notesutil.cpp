/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "notesutil_p.h"

#include <QRegularExpression>
#include <QString>
#include <QStringList>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

QString NotesUtil::normalizeNote(const QString &note)
{
    auto n = note;
    n.replace(QLatin1String("&nbsp;"), QLatin1String(" "));
    n.replace(QLatin1String("  "), QLatin1String(" "));

    if (!note.contains(QLatin1String("href"))) { // only mess with rich text if this isn't marked up already
        static const QRegularExpression linkRegExp(u"(?:https?://)?(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,}(:?/[^ \"<>]+)?"_s);
        const auto match = linkRegExp.match(n);
        if (match.hasMatch()) {
            n.replace(match.capturedStart(), match.capturedLength(), QLatin1String("<a href=\"")
                + (match.capturedView().startsWith(QLatin1String("http")) ? QString() : QStringLiteral("https://"))
                + match.capturedView()
                + QLatin1String("\">") + match.capturedView() + QLatin1String("</a>"));
        }
    }

    // fix http: links
    n.replace("href=\"http:"_L1, "href=\"https:"_L1);

    // strip <span> tags
    static const QRegularExpression spanExp(u"</?span[^>]*>"_s);
    n.remove(spanExp);
    static const QRegularExpression styleAttrExp(u" style=\"[^>\"]*\""_s);
    n.remove(styleAttrExp);

    // clean up extra line breaks and empty paragraphs
    static const QRegularExpression consecutiveBrExp(u"<br[^>]*> *(?:<br[^>]*>|\n)"_s);
    while (n.contains(consecutiveBrExp)) {
        n.replace(consecutiveBrExp, QStringLiteral("<br/>"));
    }
    static const QRegularExpression leadinBrExp(u"<p> *<br[^>]*>"_s);
    static const QRegularExpression trailingBrExp(u"<br[^>]*> *</p>"_s);
    static const QRegularExpression trailingBrExp2(u"<br[^>]*> *<p>"_s);
    n.replace(leadinBrExp, QStringLiteral("<p>"));
    n.replace(trailingBrExp, QStringLiteral("</p>"));
    n.replace(trailingBrExp2, QStringLiteral("<p>"));
    static const QRegularExpression emptyParaExp(u"<p> *</p>"_s);
    n.remove(emptyParaExp);

    return n.trimmed();
}

qsizetype NotesUtil::needsAdding(const QStringList &notes, const QString &note)
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

void NotesUtil::performAdd(QStringList &notes, const QString &note, qsizetype index)
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
