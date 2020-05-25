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

// see https://wiki.openstreetmap.org/wiki/O5m for the examples used below
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

    void testParseString()
    {
        const auto data = QByteArray::fromHex("0031696e6e65720001");
        const auto beginIt = reinterpret_cast<const uint8_t*>(data.constBegin());
        auto it = beginIt;
        const auto endIt = reinterpret_cast<const uint8_t*>(data.constEnd());

        OSM::O5mParser p(nullptr);
        auto s = p.readString(it, endIt);
        QCOMPARE(s, "1inner");
        QCOMPARE(it, beginIt + 8);

        s = p.readString(it, endIt);
        QCOMPARE(s, "1inner");
        QCOMPARE(it, beginIt + 9);
    }

    void testParseStringPair()
    {
        const auto data = QByteArray::fromHex("006f6e6577617900796573000061746d006e6f000200fc07004a6f686e00020301");
        const auto beginIt = reinterpret_cast<const uint8_t*>(data.constBegin());
        auto it = beginIt;
        const auto endIt = reinterpret_cast<const uint8_t*>(data.constEnd());

        OSM::O5mParser p(nullptr);
        auto s = p.readStringPair(it, endIt);
        QCOMPARE(s.first, "oneway");
        QCOMPARE(s.second, "yes");
        QCOMPARE(it, beginIt + 12);

        s = p.readStringPair(it, endIt);
        QCOMPARE(s.first, "atm");
        QCOMPARE(s.second, "no");
        QCOMPARE(it, beginIt + 20);

        s = p.readStringPair(it, endIt);
        QCOMPARE(s.first, "oneway");
        QCOMPARE(s.second, "yes");
        QCOMPARE(it, beginIt + 21);

        s = p.readStringPair(it, endIt);
        QCOMPARE(s.first, "\xfc\x07");
        QCOMPARE(s.second, "John");
        QCOMPARE(it, beginIt + 30);

        s = p.readStringPair(it, endIt);
        QCOMPARE(s.first, "atm");
        QCOMPARE(s.second, "no");
        QCOMPARE(it, beginIt + 31);

        s = p.readStringPair(it, endIt);
        QCOMPARE(s.first, "oneway");
        QCOMPARE(s.second, "yes");
        QCOMPARE(it, beginIt + 32);

        s = p.readStringPair(it, endIt);
        QCOMPARE(s.first, "\xfc\x07");
        QCOMPARE(s.second, "John");
        QCOMPARE(it, beginIt + 33);
    }

    void testParseWay()
    {
        const auto data = QByteArray::fromHex("CCE48E04002DCAAFA01A02BCA0AFF6018FFAD5F70180DFBB9E0FA5E5E5A60DE4E5E5A60DE385959D0F9E86959D0FF7E6E5A60D0062426F780031332E333634313031392C35322E353233323734312C31332E333635373039392C35322E353234323033310000726566003630323400");
        const auto beginIt = reinterpret_cast<const uint8_t*>(data.constBegin());
        auto it = beginIt;
        const auto endIt = reinterpret_cast<const uint8_t*>(data.constEnd());

        OSM::O5mParser p(nullptr);
        p.readWay(it, endIt);
    }
};

QTEST_GUILESS_MAIN(O5mParserTest)

#include "o5mparsertest.moc"
