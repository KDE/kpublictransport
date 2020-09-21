/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <map/loader/mapdata.h>

#include <QTest>

using namespace KOSMIndoorMap;

class MapLevelTest: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testAboveBelow_data()
    {
        QTest::addColumn<int>("level");
        QTest::addColumn<int>("above");
        QTest::addColumn<int>("below");

        QTest::newRow("0.3") << 3 << 10 << 0;
        QTest::newRow("1.7") << 17 << 20 << 10;
        QTest::newRow("-0.7") << -7 << 0 << -10;
        QTest::newRow("-1.5") << -15 << -10 << -20;
    }

    void testAboveBelow()
    {
        QFETCH(int, level);
        QFETCH(int, above);
        QFETCH(int, below);

        MapLevel ml(level);
        QVERIFY(!ml.isFullLevel());
        QCOMPARE(ml.fullLevelAbove(), above);
        QCOMPARE(ml.fullLevelBelow(), below);
    }
};

QTEST_GUILESS_MAIN(MapLevelTest)

#include "mapleveltest.moc"
