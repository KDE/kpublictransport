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

#include "backends/efacompactparser.h"
#include "backends/efaxmlparser.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class EfaParserTest : public QObject
{
    Q_OBJECT
private:
    QByteArray readFile(const QString &fn)
    {
        QFile f(fn);
        f.open(QFile::ReadOnly);
        return f.readAll();
    }

private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
        qRegisterMetaType<Disruption::Effect>();
    }

    void testParseLocation_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("vgn-by-coord")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-vgn-by-coord.xml")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-vgn-by-coord.json");
        QTest::newRow("chicago-by-name")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-chicago-by-name.xml")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-chicago-by-name.json");
        QTest::newRow("tfi-alternate-format")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-alternate-tfi-by-name.xml")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-alternate-tfi-by-name.json");
        QTest::newRow("mvv-alternate-format")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-alternate-mvv-by-name.xml")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-alternate-mvv-by-name.json");
        QTest::newRow("bwegt-by-name")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-bwegt-by-name.xml")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-bwegt-by-name.json");
    }

    void testParseLocation()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        KPublicTransport::EfaXmlParser parser;
        parser.setLocationIdentifierType(s("testid"));

        const auto res = parser.parseStopFinderResponse(readFile(inFileName));
        const auto jsonRes = Location::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QCOMPARE(jsonRes, ref);
    }

    void testParseCompactLocation_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("by-by-name")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-compact-by-by-name.xml")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-compact-by-by-name.json");
    }

    void testParseCompactLocation()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        KPublicTransport::EfaCompactParser parser;
        parser.setLocationIdentifierType(s("testid"));

        const auto res = parser.parseStopFinderResponse(readFile(inFileName));
        const auto jsonRes = Location::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QCOMPARE(jsonRes, ref);
    }

    void testParseDepartures_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("vgn-departures")
            << s(SOURCE_DIR "/data/efa/dm-response-full-vgn-departures.xml")
            << s(SOURCE_DIR "/data/efa/dm-response-full-vgn-departures.json");
    }

    void testParseDepartures()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        KPublicTransport::EfaXmlParser parser;
        parser.setLocationIdentifierType(s("testid"));

        const auto res = parser.parseDmResponse(readFile(inFileName));
        const auto jsonRes = Departure::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }

    void testParseCompactDepartures_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("by-departures")
            << s(SOURCE_DIR "/data/efa/dm-response-compact-by-departures.xml")
            << s(SOURCE_DIR "/data/efa/dm-response-compact-by-departures.json");
    }

    void testParseCompactDepartures()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        KPublicTransport::EfaCompactParser parser;
        parser.setLocationIdentifierType(s("testid"));

        const auto res = parser.parseDmResponse(readFile(inFileName));
        const auto jsonRes = Departure::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }

    void testParseTrips_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("vgn-trip")
            << s(SOURCE_DIR "/data/efa/trip-response-full-vgn.xml")
            << s(SOURCE_DIR "/data/efa/trip-response-full-vgn.json");
    }

    void testParseTrips()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        KPublicTransport::EfaXmlParser parser;
        parser.setLocationIdentifierType(s("testid"));

        const auto res = parser.parseTripResponse(readFile(inFileName));
        const auto jsonRes = Journey::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }

    void testParseCompactTrips_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("by-trip")
            << s(SOURCE_DIR "/data/efa/trip-response-compact-by.xml")
            << s(SOURCE_DIR "/data/efa/trip-response-compact-by.json");
    }

    void testParseCompactTrips()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        KPublicTransport::EfaCompactParser parser;
        parser.setLocationIdentifierType(s("testid"));

        const auto res = parser.parseTripResponse(readFile(inFileName));
        const auto jsonRes = Journey::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }

};

QTEST_GUILESS_MAIN(EfaParserTest)

#include "efaparsertest.moc"
