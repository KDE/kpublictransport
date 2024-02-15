/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"
#include "backends/motisparser.cpp"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

class MotisParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testParseLocation_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("name-search")
            << QStringLiteral(SOURCE_DIR "/data/motis/location-name-search.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis/location-name-search.out.json");
        QTest::newRow("geo-lookup")
            << QStringLiteral(SOURCE_DIR "/data/motis/location-geo-search.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis/location-geo-search.out.json");
    }

    void testParseLocation()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        MotisParser p(u"motis"_s);
        const auto result = p.parseStations(Test::readFile(inFileName));
        QVERIFY(!result.empty());
        QVERIFY(!p.hasError());
        const auto resultJson = Location::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).array();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }

    void testParseStopovers_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("stopover-non-terminal")
            << QStringLiteral(SOURCE_DIR "/data/motis/stopovers-non-terminal.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis/stopovers-non-terminal.out.json");
        QTest::newRow("stopover-terminal")
            << QStringLiteral(SOURCE_DIR "/data/motis/stopovers-terminal.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis/stopovers-terminal.out.json");
    }

    void testParseStopovers()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        MotisParser p(u"motis"_s);
        const auto result = p.parseEvents(Test::readFile(inFileName));
        QVERIFY(!result.empty());
        QVERIFY(!p.hasError());
        const auto resultJson = Stopover::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).array();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }

    void testParseJourneys_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("ch-transport-only")
            << QStringLiteral(SOURCE_DIR "/data/motis/journey-ch-transport-only.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis/journey-ch-transport-only.out.json");
    }

    void testParseJourneys()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        MotisParser p(u"motis"_s);
        const auto result = p.parseConnections(Test::readFile(inFileName));
        QVERIFY(!result.journeys.empty());
        QVERIFY(result.begin);
        QVERIFY(result.end);
        QVERIFY(!p.hasError());
        const auto resultJson = Journey::toJson(result.journeys);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).array();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }

    void testParseError()
    {
        {
            MotisParser p(u"motis"_s);
            const auto result = p.parseStations(Test::readFile(QStringLiteral(SOURCE_DIR "/data/motis/error.in.json")));
            QVERIFY(result.empty());
            QVERIFY(p.hasError());
            QCOMPARE(p.errorMessage(), "access: timestamp not in schedule"_L1);
        }
        {
            MotisParser p(u"motis"_s);
            const auto result = p.parseConnections(Test::readFile(QStringLiteral(SOURCE_DIR "/data/motis/error.in.json")));
            QVERIFY(result.empty());
            QVERIFY(p.hasError());
            QCOMPARE(p.errorMessage(), "access: timestamp not in schedule"_L1);
        }
    }
};

QTEST_GUILESS_MAIN(MotisParserTest)

#include "motisparsertest.moc"
