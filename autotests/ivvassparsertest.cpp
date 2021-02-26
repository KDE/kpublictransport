/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backends/ivvassparser.cpp"

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
private:
    QByteArray readFile(const QString &fn)
    {
        QFile f(fn);
        f.open(QFile::ReadOnly);
        return f.readAll();
    }

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

        const auto result = IvvAssParser::parseLocations(readFile(inFileName));
        const auto resultJson = Location::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(readFile(outFileName)).array();
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

        const auto result = IvvAssParser::parseStopovers(readFile(inFileName));
        const auto resultJson = Stopover::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(readFile(outFileName)).array();
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
    }

    void testParseJourneys()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        const auto result = IvvAssParser::parseJourneys(readFile(inFileName));
        const auto resultJson = Journey::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(readFile(outFileName)).array();
        if (resultJson != resultRef) {
            qDebug().noquote() << QJsonDocument(resultJson).toJson();
        }
        QVERIFY(!resultJson.isEmpty());
        QCOMPARE(resultJson, resultRef);
    }
};

QTEST_GUILESS_MAIN(IvvAssParserTest)

#include "ivvassparsertest.moc"
