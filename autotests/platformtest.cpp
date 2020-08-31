/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/Journey>
#include <KPublicTransport/Stopover>

#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class PlatformTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testNormalize_data()
    {
        QTest::addColumn<QString>("in");
        QTest::addColumn<QString>("out");

        QTest::newRow("empty") << QString() << QString();
        QTest::newRow("no change") << s("1") << s("1");

        QTest::newRow("prefix1") << s("Platform 2") << s("2");
        QTest::newRow("prefix2") << s("pl. 3") << s("3");
        QTest::newRow("prefix3") << s("PLATFORM 4") << s("4");

        QTest::newRow("prefix4") << s("Bahnsteig 5 A-B") << s("5 A-B");
        QTest::newRow("prefix5") << s("Bstg. 6") << s("6");
        QTest::newRow("prefix6") << s("Gleis 7") << s("7");

        QTest::newRow("no info") << s("---") << QString();
    }

    void testNormalize()
    {
        QFETCH(QString, in);
        QFETCH(QString, out);

        Stopover dep;
        dep.setScheduledPlatform(in);
        QCOMPARE(dep.scheduledPlatform(), out);
        dep.setExpectedPlatform(in);
        QCOMPARE(dep.expectedPlatform(), out);

        JourneySection sec;
        sec.setScheduledDeparturePlatform(in);
        QCOMPARE(sec.scheduledDeparturePlatform(), out);
        sec.setScheduledArrivalPlatform(in);
        QCOMPARE(sec.scheduledArrivalPlatform(), out);
        sec.setExpectedDeparturePlatform(in);
        QCOMPARE(sec.expectedDeparturePlatform(), out);
        sec.setExpectedArrivalPlatform(in);
        QCOMPARE(sec.expectedArrivalPlatform(), out);
    }

    void testPlatformChanged_data()
    {
        QTest::addColumn<QString>("scheduled");
        QTest::addColumn<QString>("expected");
        QTest::addColumn<bool>("changed");

        QTest::newRow("empty") << QString() << QString() << false;
        QTest::newRow("same") << s("1") << s("1") << false;
        QTest::newRow("different") << s("2") << s("3") << true;
        QTest::newRow("no expected") << s("4") << QString() << false;
        QTest::newRow("no scheduled") << QString() << s("5") << false;
    }

    void testPlatformChanged()
    {
        QFETCH(QString, scheduled);
        QFETCH(QString, expected);
        QFETCH(bool, changed);

        Stopover dep;
        dep.setScheduledPlatform(scheduled);
        dep.setExpectedPlatform(expected);
        QCOMPARE(dep.platformChanged(), changed);

        JourneySection sec;
        sec.setScheduledDeparturePlatform(scheduled);
        sec.setExpectedDeparturePlatform(expected);
        QCOMPARE(sec.departurePlatformChanged(), changed);
        sec.setScheduledArrivalPlatform(scheduled);
        sec.setExpectedArrivalPlatform(expected);
        QCOMPARE(sec.arrivalPlatformChanged(), changed);
    }
};

QTEST_GUILESS_MAIN(PlatformTest)

#include "platformtest.moc"
