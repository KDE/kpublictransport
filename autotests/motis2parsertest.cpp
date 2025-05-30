/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"
#include "backends/motis2parser.cpp"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Path>
#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

#ifdef Q_OS_LINUX
void initLocale()
{
    qputenv("LANG", "en_US.utf-8");
}

Q_CONSTRUCTOR_FUNCTION(initLocale)
#endif

class Motis2ParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testParseLocation_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("name-search")
            << QStringLiteral(SOURCE_DIR "/data/motis2/location-name-search.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/location-name-search.out.json");
        QTest::newRow("geo-lookup")
            << QStringLiteral(SOURCE_DIR "/data/motis2/location-geo-search.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/location-geo-search.out.json");
        QTest::newRow("address")
            << QStringLiteral(SOURCE_DIR "/data/motis2/location-addresses.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/location-addresses.out.json");
    }

    void testParseLocation()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        Motis2Parser p(u"motis"_s);
        const auto result = p.parseLocations(Test::readFile(inFileName));
        QVERIFY(!result.empty());
        const auto resultJson = Location::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).array();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }

    void testParseMapStops_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("map-stops")
            << QStringLiteral(SOURCE_DIR "/data/motis2/location-map-stops.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/location-map-stops.out.json");
    }

    void testParseMapStops()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        Motis2Parser p(u"motis"_s);
        const auto result = p.parseMapStops(Test::readFile(inFileName));
        QVERIFY(!result.empty());
        const auto resultJson = Location::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).array();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }

    void testParseStopovers_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");
        QTest::addColumn<bool>("arrival");

        QTest::newRow("departure")
            << QStringLiteral(SOURCE_DIR "/data/motis2/stopover-departure.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/stopover-departure.out.json")
            << false;
        QTest::newRow("arrival")
            << QStringLiteral(SOURCE_DIR "/data/motis2/stopover-arrival.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/stopover-arrival.out.json")
            << true;
        QTest::newRow("arrival-realtime")
            << QStringLiteral(SOURCE_DIR "/data/motis2/stopover-arrival-realtime.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/stopover-arrival-realtime.out.json")
            << true;
    }

    void testParseStopovers()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);
        QFETCH(bool, arrival);

        Motis2Parser p(u"motis"_s);
        const auto result = p.parseStopTimes(Test::readFile(inFileName), arrival);
        QVERIFY(!result.empty());
        const auto resultJson = Stopover::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).array();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
        QVERIFY(!p.m_nextPageCursor.isEmpty());
        QVERIFY(!p.m_previousPageCursor.isEmpty());
    }

    void testParseJourneys_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");
        QTest::addColumn<bool>("canPage");

        QTest::newRow("transit")
            << QStringLiteral(SOURCE_DIR "/data/motis2/journey-transit.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/journey-transit.out.json")
            << true;
        QTest::newRow("bike-rental")
            << QStringLiteral(SOURCE_DIR "/data/motis2/journey-bike-rental.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/journey-bike-rental.out.json")
            << true;
        QTest::newRow("direct-walk")
            << QStringLiteral(SOURCE_DIR "/data/motis2/journey-direct-walk.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/journey-direct-walk.out.json")
            << false;
    }

    void testParseJourneys()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);
        QFETCH(bool, canPage);

        Motis2Parser p(u"motis"_s);
        const auto result = p.parseItineraries(Test::readFile(inFileName));
        QVERIFY(!result.empty());
        QVERIFY(!canPage ^ !p.m_nextPageCursor.isEmpty());
        QVERIFY(!canPage ^ !p.m_previousPageCursor.isEmpty());
        const auto resultJson = Journey::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).array();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }

    void testParseTrip_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("limited-entry-exit")
            << QStringLiteral(SOURCE_DIR "/data/motis2/trip-limited-entry-exit.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/trip-limited-entry-exit.out.json");
        QTest::newRow("alerts")
            << QStringLiteral(SOURCE_DIR "/data/motis2/trip-alerts.in.json")
            << QStringLiteral(SOURCE_DIR "/data/motis2/trip-alerts.out.json");
    }

    void testParseTrip()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        Motis2Parser p(u"motis"_s);
        const auto result = p.parseItinerary(QJsonDocument::fromJson(Test::readFile(inFileName)).object());
        const auto resultJson = Journey::toJson(result);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).object();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }
};

QTEST_GUILESS_MAIN(Motis2ParserTest)

#include "motis2parsertest.moc"
