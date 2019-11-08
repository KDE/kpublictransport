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

#include <KPublicTransport/Location>

#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class LocationTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testLocationNameCompare_data()
    {
        QTest::addColumn<QString>("lhs");
        QTest::addColumn<QString>("rhs");

        QTest::newRow("identical") << s("Berlin Hbf") << s("Berlin Hbf");

        QTest::newRow("case folding") << s("Berlin Hbf") << s("Berlin HBF");

        QTest::newRow("separators1") << s("Berlin Hauptbahnhof") << s("Berlin, Hauptbahnhof");
        QTest::newRow("separators2") << s("Berlin Hauptbahnhof") << s("Berlin (Hauptbahnhof)");
        QTest::newRow("separators3") << s("Berlin, Hauptbahnhof") << s("Berlin (Hauptbahnhof)");
        QTest::newRow("separators4") << s("Paris-Gare-de-Lyon") << s("Paris Gare de Lyon");

        QTest::newRow("abbreviations1") << s("Berlin Hbf") << s("Berlin Hauptbahnhof");
        QTest::newRow("abbreviations2") << s("Amsterdam Cs") << s("Amsterdam Centraal");
        QTest::newRow("abbreviations3") << s("Berlin Friedrich Straße") << s("Berlin Friedrich Str.");

        QTest::newRow("inline abbreviation1") << s("Berlin Friedrichstr.") << s("Berlin Friedrichstrasse");

        QTest::newRow("extras1") << s("S+U Berlin Hbf") << s("Berlin Hauptbahnhof");
        QTest::newRow("extras2") << s("Berlin Schönefeld Flughafen (S)") << s("S Berlin Schönefeld Flughafen");
        QTest::newRow("extras3") << s("Paris Gare de Lyon RER") << s("Paris Gare de Lyon");
        QTest::newRow("extras4") << s("Paris-Gare-de-Lyon RER (Paris)") << s("Gare de Lyon RER A (Paris)");

        QTest::newRow("station1") << s("Boissy-St-Léger") << s("Gare de Boissy-St-Léger");
        QTest::newRow("station2") << s("Flughafen Wien") << s("Flughafen Wien Bahnhof");
        QTest::newRow("station3") << s("Berlin Schönefeld Flughafen Bhf") << s("Berlin Schönefeld Flughafen");

        QTest::newRow("duplicates1") << s("Paris Gare de Lyon (Paris)") << s("Paris Gare de Lyon");
        QTest::newRow("duplicates2") << s("Gare de Saint-Rémy les Chevreuse (Saint-Rémy-lès-Chevreuse)") << s("St-Rémy-lès-Chevreuse (Saint-Rémy-lès-Chevreuse)");

        QTest::newRow("normalization1") << s("Boissy-St-Léger (Boissy-Saint-Léger)") << s("Boissy St Léger");

        QTest::newRow("order1") << s("Paris Gare de Lyon") << s("Gare de Lyon (Paris)");

        QTest::newRow("localization1") << s("Berlin Flughafen Schönefeld (Airport)") << s("Berlin Flughafen Schönefeld Bhf");

        QTest::newRow("diacritic1") << s("Berlin Flughafen Schonefeld") << s("Berlin Flughafen Schönefeld");
        QTest::newRow("diacritic2") << s("Berlin Flughafen Schoenefeld") << s("Berlin Flughafen Schönefeld");
        QTest::newRow("diacritic3") << s("København H") << s("Koebenhavn H");

        QTest::newRow("prefix1") << s("Zürich Flughafen") << s("Zürich Flughafen (Kloten)");

        QTest::newRow("unicode1") << s("Berlin Friedrichstraße") << s("Berlin Friedrichstrasse");
    }

    void testLocationNameCompare()
    {
        QFETCH(QString, lhs);
        QFETCH(QString, rhs);
        Location l, r;
        l.setName(lhs);
        r.setName(rhs);

        QEXPECT_FAIL("inline abbreviation1", "not implemented yet", Abort);
        QVERIFY(Location::isSame(l, r));
        QVERIFY(Location::isSame(r, l));
    }

    void testLocationNameMerge_data()
    {
        QTest::addColumn<QString>("lhs");
        QTest::addColumn<QString>("rhs");
        QTest::addColumn<QString>("result");

        QTest::newRow("identical") << s("Berlin Hbf") << s("Berlin Hbf") << s("Berlin Hbf");
        QTest::newRow("abbreviation") << s("Berlin Hbf") << s("Berlin Hauptbahnhof") << s("Berlin Hauptbahnhof");
        QTest::newRow("separators") << s("Châtelet les Halles (Paris)") << s("Châtelet-les-Halles (Paris)") << s("Châtelet les Halles (Paris)");

        // TODO stuff that doesn't work as good as it could be yet
        //QTest::newRow("all caps") << s("BERLIN") << s("Berlin") << s("Berlin");
        //QTest::newRow("unicode") << s("København H") << s("Koebenhavn H") << s("København H");
        //QTest::newRow("redundancy") << s("Bern (Bern)") << s("Bern") << s("Bern");
    }

    void testLocationNameMerge()
    {
        QFETCH(QString, lhs);
        QFETCH(QString, rhs);
        QFETCH(QString, result);

        Location l, r;
        l.setName(lhs);
        r.setName(rhs);

        QCOMPARE(Location::merge(l, r).name(), result);
        QCOMPARE(Location::merge(r, l).name(), result);
    }

    void testCoordinates()
    {
        Location l, r;
        l.setName(QStringLiteral("Berlin"));
        r.setName(QStringLiteral("Berlin"));

        l.setCoordinate(52.555, 13.555);
        QVERIFY(Location::isSame(l, r));
        QVERIFY(Location::isSame(r, l));

        r.setCoordinate(52.557, 13.557);
        QVERIFY(Location::isSame(l, r));
        QVERIFY(Location::isSame(r, l));

        QVERIFY(std::abs(Location::merge(l, r).latitude() - 52.556) < 0.001);
        QVERIFY(std::abs(Location::merge(r, l).latitude() - 52.556) < 0.001);
        QVERIFY(std::abs(Location::merge(l, r).longitude() - 13.556) < 0.001);
        QVERIFY(std::abs(Location::merge(r, l).longitude() - 13.556) < 0.001);

        r.setCoordinate(-52.5, 135.5);
        QVERIFY(!Location::isSame(l, r));
        QVERIFY(!Location::isSame(r, l));
    }

    void testLocationIdentifierCompare()
    {
        Location l, r;
        l.setIdentifier(QStringLiteral("ibnr"), QStringLiteral("8012345"));
        r.setIdentifier(QStringLiteral("ibnr"), QStringLiteral("8054321"));
        QVERIFY(!Location::isSame(l, r));
        QVERIFY(!Location::isSame(r, l));
        QVERIFY(Location::isSame(l, l));

        l.setIdentifier(QStringLiteral("db"), QStringLiteral("12345"));
        r.setIdentifier(QStringLiteral("db"), QStringLiteral("12345"));
        QVERIFY(!Location::isSame(l, r));
        QVERIFY(!Location::isSame(r, l));
        QVERIFY(Location::isSame(l, l));

        l.setIdentifier(QStringLiteral("sncf"), QStringLiteral("FRABC"));
        QVERIFY(!Location::isSame(l, r));
        QVERIFY(!Location::isSame(r, l));
        QVERIFY(Location::isSame(l, l));

        Location l2, r2;
        l2.setName(QStringLiteral("Brussels Gare de Midi"));
        l2.setName(QStringLiteral("Brussels Gare de Midi"));
        l2.setIdentifier(QStringLiteral("vendor1"), QStringLiteral("12345"));
        r2.setIdentifier(QStringLiteral("vendor2"), QStringLiteral("54321"));
        QVERIFY(Location::isSame(l2, r2));
        QVERIFY(Location::isSame(r2, l2));
    }
};

QTEST_GUILESS_MAIN(LocationTest)

#include "locationtest.moc"
