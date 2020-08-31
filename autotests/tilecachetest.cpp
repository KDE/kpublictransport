/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <map/loader/tilecache.h>
#include <osm/datatypes.h>

#include <QTest>

using namespace KOSMIndoorMap;

class TileCacheTest: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testTileFromCoordinate_data()
    {
        QTest::addColumn<int>("z");
        QTest::addColumn<double>("lat");
        QTest::addColumn<double>("lon");
        QTest::addColumn<int>("x");
        QTest::addColumn<int>("y");

        QTest::newRow("z17") << 17 << 52.5258 << 13.3684 << 70403 << 42982;
    }

    void testTileFromCoordinate()
    {
        QFETCH(int, z);
        QFETCH(double, lat);
        QFETCH(double, lon);
        QFETCH(int, x);
        QFETCH(int, y);

        const auto tile = Tile::fromCoordinate(lat, lon, z);
        QCOMPARE(tile.x, x);
        QCOMPARE(tile.y, y);
        QCOMPARE(tile.z, z);
    }

    void testCoordinateForTile()
    {
        Tile t(0, 0, 1);
        QCOMPARE(t.topLeft().latF(), 85.0511287);
        QCOMPARE(t.topLeft().lonF(), -180.0);
        QCOMPARE(t.boundingBox().min.latF(), 0.0);
        QCOMPARE(t.boundingBox().min.lonF(), -180.0);
        QCOMPARE(t.boundingBox().max.latF(), 85.0511287);
        QCOMPARE(t.boundingBox().max.lonF(), 0.0);
    }
};

QTEST_GUILESS_MAIN(TileCacheTest)

#include "tilecachetest.moc"
