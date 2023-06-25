/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"
#include "ifopt/ifoptutil.cpp"
#include "backends/ivvassparser.cpp"
#include "backends/ivvassproductmap.cpp"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class IvvAssParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testParseLocations_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("location-by-name-vrs")
            << s(SOURCE_DIR "/data/ivvass/location-by-name-vrs-input.json")
            << s(SOURCE_DIR "/data/ivvass/location-by-name-vrs-output.json");
        QTest::newRow("location-by-coord-vrs")
            << s(SOURCE_DIR "/data/ivvass/location-by-coord-vrs-input.json")
            << s(SOURCE_DIR "/data/ivvass/location-by-coord-vrs-output.json");
    }

    void testParseLocations()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        IvvAssParser p(QTimeZone("Europe/Berlin"), s("vrs"));
        const auto result = p.parseLocations(Test::readFile(inFileName));
        QVERIFY(!result.empty());
        QVERIFY(p.errorMessage.isEmpty());
        const auto resultJson = Location::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).array();
        if (resultJson != resultRef) {
            qDebug().noquote() << QJsonDocument(resultJson).toJson();
        }
        QVERIFY(!resultJson.isEmpty());
        QCOMPARE(resultJson, resultRef);
    }

    void testParseStopovers_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("departure-vrs")
            << s(SOURCE_DIR "/data/ivvass/departure-vrs-input.json")
            << s(SOURCE_DIR "/data/ivvass/departure-vrs-output.json");
    }

    void testParseStopovers()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        IvvAssParser p(QTimeZone("Europe/Berlin"), s("vrs"));
        const auto result = p.parseStopovers(Test::readFile(inFileName));
        QVERIFY(!result.empty());
        QVERIFY(p.errorMessage.isEmpty());
        const auto resultJson = Stopover::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).array();
        if (resultJson != resultRef) {
            qDebug().noquote() << QJsonDocument(resultJson).toJson();
        }
        QVERIFY(!resultJson.isEmpty());
        QCOMPARE(resultJson, resultRef);
    }

    void testParseJourneys_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("journey-vrs")
            << s(SOURCE_DIR "/data/ivvass/journey-vrs-input.json")
            << s(SOURCE_DIR "/data/ivvass/journey-vrs-output.json");
        QTest::newRow("journey-long-distance-vrs")
            << s(SOURCE_DIR "/data/ivvass/journey-long-distance-vrs-input.json")
            << s(SOURCE_DIR "/data/ivvass/journey-long-distance-vrs-output.json");
        QTest::newRow("journey-walking-directions-vrs")
            << s(SOURCE_DIR "/data/ivvass/journey-walking-directions-vrs-input.json")
            << s(SOURCE_DIR "/data/ivvass/journey-walking-directions-vrs-output.json");
    }

    void testParseJourneys()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        IvvAssParser p(QTimeZone("Europe/Berlin"), s("vrs"));
        const auto result = p.parseJourneys(Test::readFile(inFileName));
        QVERIFY(!result.empty());
        QVERIFY(p.errorMessage.isEmpty());
        const auto resultJson = Journey::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).array();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }

    void testParseError()
    {
        {
            IvvAssParser p(QTimeZone("Europe/Berlin"), s("vrs"));
            const auto res = p.parseLocations(R"({"error":"Ung\u00fcltige Zeit"})");
            QVERIFY(!p.errorMessage.isEmpty());
        }
        {
            IvvAssParser p(QTimeZone("Europe/Berlin"), s("vrs"));
            const auto res = p.parseStopovers(R"({"error":"Fehlerhaftes Ziel"})");
            QVERIFY(!p.errorMessage.isEmpty());
        }
        {
            IvvAssParser p(QTimeZone("Europe/Berlin"), s("vrs"));
            const auto res = p.parseJourneys(R"({"error":"Fehlerhafter Start"})");
            QVERIFY(!p.errorMessage.isEmpty());
        }
    }
};

QTEST_GUILESS_MAIN(IvvAssParserTest)

#include "ivvassparsertest.moc"
