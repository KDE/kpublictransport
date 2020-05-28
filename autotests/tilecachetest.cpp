/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#include <map/loader/tilecache.h>

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
};

QTEST_GUILESS_MAIN(TileCacheTest)

#include "tilecachetest.moc"
