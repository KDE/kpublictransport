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

#include "../src/datatypes/mergeutil.cpp"

#include <KPublicTransport/Departure>
#include <KPublicTransport/Journey>

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
        Departure dep;
        dep.addNote(s("line1"));
        dep.addNote(s("line2"));
        QCOMPARE(dep.notes().size(), 2);
        const auto json = Departure::toJson(dep);
        //qDebug().noquote() << QJsonDocument(json).toJson();
        const auto dep2 = Departure::fromJson(json);
        QCOMPARE(dep.notes(), dep2.notes());
    }

    void testAddNotes()
    {
        JourneySection sec;
        sec.addNote(s("line1"));
        sec.addNotes({s("line2"), s("line1")});
        QCOMPARE(sec.notes(), QStringList({s("line1"), s("line2")}));
    }

    void testNotesMerge()
    {
        Departure dep1;
        Departure dep2;
        dep1.addNote(s("line1"));
        dep2.addNotes({s("line2"), s("line1")});

        const auto dep3 = Departure::merge(dep1, dep2);
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
        QCOMPARE(MergeUtil::normalizeNote(in), out);
    }

    void testRichText_data()
    {
        QTest::addColumn<QString>("in");
        QTest::addColumn<QString>("out");

        QTest::newRow("full url") << s("Check-in here: http://www.kde.org") << s("Check-in here: <a href=\"http://www.kde.org\">http://www.kde.org</a>");
        QTest::newRow("existing link") << s("Check-in here: <a href=\"http://www.kde.org\">http://www.kde.org</a>") << s("Check-in here: <a href=\"http://www.kde.org\">http://www.kde.org</a>");
        QTest::newRow("missing scheme") << s("Check-in here: www.kde.org/donate") << s("Check-in here: <a href=\"https://www.kde.org/donate\">www.kde.org/donate</a>");
    }

    void testRichText()
    {
        QFETCH(QString, in);
        QFETCH(QString, out);
        QCOMPARE(MergeUtil::normalizeNote(in), out);
    }
};

QTEST_GUILESS_MAIN(NotesTest)

#include "notestest.moc"
