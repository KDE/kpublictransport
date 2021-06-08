/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../src/lib/datatypes/notesutil.cpp"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Stopover>

#include <QJsonDocument>
#include <QJsonObject>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class NotesTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testSerialization()
    {
        Stopover dep;
        dep.addNote(s("line1"));
        dep.addNote(s("line2"));
        QCOMPARE(dep.notes().size(), 2);
        const auto json = Stopover::toJson(dep);
        //qDebug().noquote() << QJsonDocument(json).toJson();
        const auto dep2 = Stopover::fromJson(json);
        QCOMPARE(dep.notes(), dep2.notes());
    }

    void testAddNotes_data()
    {
        QTest::addColumn<QStringList>("in");
        QTest::addColumn<QStringList>("res");

        QTest::newRow("empty") << QStringList() << QStringList();
        QTest::newRow("one") << QStringList({s("line1")}) << QStringList({s("line1")});
        QTest::newRow("two") << QStringList({s("line1"), s("line2")}) << QStringList({s("line1"), s("line2")});
        QTest::newRow("double") << QStringList({s("line1"), s("line2"), s("line1")}) << QStringList({s("line1"), s("line2")});
        QTest::newRow("substring first") << QStringList({s("note"), s("line2"), s("note - detail")}) << QStringList({s("note - detail"), s("line2")});
        QTest::newRow("substring second") << QStringList({s("note - detail"), s("line2"), s("note")}) << QStringList({s("note - detail"), s("line2")});
    }

    void testAddNotes()
    {
        QFETCH(QStringList, in);
        QFETCH(QStringList, res);

        JourneySection sec;
        sec.addNotes(in);
        QCOMPARE(sec.notes(), res);
        sec.addNotes(in);
        QCOMPARE(sec.notes(), res);

        Stopover dep;
        for (const auto &note : in)
            dep.addNote(note);
        QCOMPARE(dep.notes(), res);
    }

    void testNotesMerge()
    {
        Stopover dep1;
        Stopover dep2;
        dep1.addNote(s("line1"));
        dep2.addNotes({s("line2"), s("line1")});

        const auto dep3 = Stopover::merge(dep1, dep2);
        QCOMPARE(dep3.notes(), QStringList({s("line1"), s("line2")}));
    }

    void testNormalize_data()
    {
        QTest::addColumn<QString>("in");
        QTest::addColumn<QString>("out");

        QTest::newRow("empty") << QString() << QString();
        QTest::newRow("leading space") << s(" note") << s("note");
        QTest::newRow("trailing space") << s("note ") << s("note");
        QTest::newRow("double space") << s("note  1") << s("note 1");
    }

    void testNormalize()
    {
        QFETCH(QString, in);
        QFETCH(QString, out);
        QCOMPARE(NotesUtil::normalizeNote(in), out);
    }

    void testRichText_data()
    {
        QTest::addColumn<QString>("in");
        QTest::addColumn<QString>("out");

        QTest::newRow("full url") << s("Check-in here: http://www.kde.org") << s("Check-in here: <a href=\"http://www.kde.org\">http://www.kde.org</a>");
        QTest::newRow("existing link") << s("Check-in here: <a href=\"http://www.kde.org\">http://www.kde.org</a>") << s("Check-in here: <a href=\"http://www.kde.org\">http://www.kde.org</a>");
        QTest::newRow("missing scheme") << s("Check-in here: www.kde.org/donate") << s("Check-in here: <a href=\"https://www.kde.org/donate\">www.kde.org/donate</a>");
        QTest::newRow("too much html") << s("<p><span style=\"color: rgb(37, 48, 59); font-family: &quot;Open Sans&quot;, Arial, sans-serif; font-size: 14px;\"><b>Attention</b></span></p><p><span style=\"color: rgb(37, 48, 59); font-family: &quot;Open Sans&quot;, Arial, sans-serif; font-size: 14px;\">Les lignes de&nbsp;BUS DIRECT ne sont pas accessibles avec un pass Navigo. Un ticket peut être acheté dans toutes les stations Métro-RER, y compris à l'aéroport.</span></p>") << s("<p><b>Attention</b></p><p>Les lignes de BUS DIRECT ne sont pas accessibles avec un pass Navigo. Un ticket peut être acheté dans toutes les stations Métro-RER, y compris à l'aéroport.</p>");
        QTest::newRow("empty p 1") << s("foo <p> </p>bar") << s("foo bar");
        QTest::newRow("empty p 2") << s("foo <p></p>bar") << s("foo bar");
        QTest::newRow("linebreak 1") << s("foo<br/></p>") << s("foo</p>");
        QTest::newRow("linebreak 2") << s("foo <p><br></p>bar") << s("foo bar");

        QTest::newRow("style stripping") << s(" &nbsp;\n<p style=\"font-family: MetaWeb-Normal, sans-serif; font-size: 12px; font-variant-numeric: normal; font-variant-east-asian: normal; background-color: #ffffff; color: #666666; line-height: 1.5; margin: 0px 0px 0.5em; padding: 0px;\">Die Hauptstra&szlig;e wird von der Einm&uuml;ndung Otto-Hahn-Stra&szlig;e bis einschlie&szlig;lich Rathausplatz komplett saniert.") << s("<p>Die Hauptstra&szlig;e wird von der Einm&uuml;ndung Otto-Hahn-Stra&szlig;e bis einschlie&szlig;lich Rathausplatz komplett saniert.");
        QTest::newRow("leading spaces") << s(" &nbsp; Wegen Bauarbeiten") << s("Wegen Bauarbeiten");
    }

    void testRichText()
    {
        QFETCH(QString, in);
        QFETCH(QString, out);
        QCOMPARE(NotesUtil::normalizeNote(in), out);
    }
};

QTEST_GUILESS_MAIN(NotesTest)

#include "notestest.moc"
