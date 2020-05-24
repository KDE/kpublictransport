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

#include <osm/o5mparser.h>

#include <QTest>

class O5mParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testParseUnsignedInt_data()
    {
        QTest::addColumn<QByteArray>("data");
        QTest::addColumn<uint32_t>("num");

        QTest::newRow("0") << QByteArray::fromHex("00") << 0u;
        QTest::newRow("1") << QByteArray::fromHex("01") << 1u;
        QTest::newRow("127") << QByteArray::fromHex("7f") << 127u;
        QTest::newRow("128") << QByteArray::fromHex("8001") << 128u;
        QTest::newRow("255") << QByteArray::fromHex("FF01") << 255u;
        QTest::newRow("256") << QByteArray::fromHex("8002") << 256u;
        QTest::newRow("323") << QByteArray::fromHex("c302") << 323u;
        QTest::newRow("16384") << QByteArray::fromHex("808001") << 16384u;
    }

    void testParseUnsignedInt()
    {
        QFETCH(QByteArray, data);
        QFETCH(uint32_t, num);

        OSM::O5mParser p(nullptr);
        const auto beginIt = reinterpret_cast<const uint8_t*>(data.constBegin());
        auto it = beginIt;
        const auto endIt = reinterpret_cast<const uint8_t*>(data.constEnd());
        QCOMPARE(p.readUnsigned(it, endIt), num);
        QVERIFY(it > beginIt);
        QVERIFY(it <= endIt);
    }

    void testParseSignedInt_data()
    {
        QTest::addColumn<QByteArray>("data");
        QTest::addColumn<int32_t>("num");

        QTest::newRow("0") << QByteArray::fromHex("00") << 0;
        QTest::newRow("64") << QByteArray::fromHex("8001") << 64;
        QTest::newRow("-2") << QByteArray::fromHex("03") << -2;
        QTest::newRow("-65") << QByteArray::fromHex("8101") << -65;
    }

    void testParseSignedInt()
    {
        QFETCH(QByteArray, data);
        QFETCH(int32_t, num);

        OSM::O5mParser p(nullptr);
        const auto beginIt = reinterpret_cast<const uint8_t*>(data.constBegin());
        auto it = beginIt;
        const auto endIt = reinterpret_cast<const uint8_t*>(data.constEnd());
        QCOMPARE(p.readSigned(it, endIt), num);
        QVERIFY(it > beginIt);
        QVERIFY(it <= endIt);
    }
};

QTEST_GUILESS_MAIN(O5mParserTest)

#include "o5mparsertest.moc"
