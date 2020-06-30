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

#include <datatypes.h>

#include <QTest>

class OsmTypeTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testZIndex_data()
    {
        QTest::addColumn<double>("lon");
        QTest::addColumn<double>("lat");
        QTest::addColumn<qulonglong>("z");

        QTest::newRow("-180,-90") << -180.0 << -90.0 << 0ull;
        QTest::newRow("-179,-90") << -179.0 << -90.0 << 143488451117056ull;
        QTest::newRow("-180,-89") << -180.0 << -89.0 << 71744225558528ull;
        QTest::newRow("0,0") << 0.0 << 0.0 << 3286330935456890880ull;
        QTest::newRow("180,90") << 180.0 << 90.0 << 13145323741827563520ull;
    }

    void testZIndex()
    {
        QFETCH(double, lat);
        QFETCH(double, lon);
        QFETCH(qulonglong, z);

        OSM::Coordinate coord(lat, lon);
        QCOMPARE(coord.z(), z);

        OSM::Coordinate coord2(z);
        QCOMPARE(coord2.latitude, coord.latitude);
        QCOMPARE(coord2.longitude, coord.longitude);
    }

    void testTagKeys()
    {
        OSM::DataSet ds;

        OSM::TagKey nullKey;
        QCOMPARE(nullKey, ds.tagKey("akey"));
        QCOMPARE(nullKey.isNull(), true);

        const auto key1 = ds.makeTagKey("akey", OSM::DataSet::StringIsPersistent);
        QCOMPARE(key1, ds.makeTagKey("akey", OSM::DataSet::StringIsPersistent));
        QCOMPARE(key1, ds.tagKey("akey"));
        QCOMPARE(key1.isNull(), false);
        QCOMPARE(key1.name(), "akey");
        QVERIFY(key1 != nullKey);

        const auto key2 = ds.makeTagKey("bkey", OSM::DataSet::StringIsTransient);
        QVERIFY(key1 != key2);
        QCOMPARE(key2, ds.makeTagKey("bkey", OSM::DataSet::StringIsTransient));

        OSM::Node node;
        OSM::setTagValue(node, key1, "avalue");
        OSM::setTagValue(node, key2, "bvalue-1");
        OSM::setTagValue(node, key2, "bvalue");

        QCOMPARE(OSM::tagValue(node, key1), "avalue");
        QCOMPARE(OSM::tagValue(node, key2), "bvalue");

        QCOMPARE(OSM::tagValue(node, "bkey"), "bvalue");
        QCOMPARE(OSM::tagValue(node, "akey"), "avalue");
    }
};

QTEST_GUILESS_MAIN(OsmTypeTest)

#include "osmtypetest.moc"
