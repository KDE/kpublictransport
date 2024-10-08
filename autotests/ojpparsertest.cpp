/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backends/openjourneyplannerparser.h"
#include "testhelpers.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QLocale>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class OjpParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testParseLocations_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("ch-location-by-coord")
            << s(SOURCE_DIR "/data/ojp/ch-location-by-coord.xml")
            << s(SOURCE_DIR "/data/ojp/ch-location-by-coord.json");
        QTest::newRow("ch-location-by-name")
            << s(SOURCE_DIR "/data/ojp/ch-location-by-name.xml")
            << s(SOURCE_DIR "/data/ojp/ch-location-by-name.json");
        QTest::newRow("vvo-location-by-name")
            << s(SOURCE_DIR "/data/ojp/vvo-location-by-name.xml")
            << s(SOURCE_DIR "/data/ojp/vvo-location-by-name.json");
    }

    void testParseLocations()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        OpenJourneyPlannerParser p;
        p.setLocationIdentifierType(QStringLiteral("test_id"));
        p.setUicLocationIdentifierType(QStringLiteral("uic"));
        const auto res = p.parseLocationInformationResponse(Test::readFile(inFileName));
        QVERIFY(!p.hasError());
        const auto jsonRes = Location::toJson(res);

        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).array();
        QVERIFY(Test::compareJson(refFileName, jsonRes, ref));
    }

    void testParseStopover_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("ch-stopover-departure")
            << s(SOURCE_DIR "/data/ojp/ch-stopover-departure.xml")
            << s(SOURCE_DIR "/data/ojp/ch-stopover-departure.json");
        QTest::newRow("vvo-stopover-departure")
            << s(SOURCE_DIR "/data/ojp/vvo-stopover-departure.xml")
            << s(SOURCE_DIR "/data/ojp/vvo-stopover-departure.json");
    }

    void testParseStopover()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        OpenJourneyPlannerParser p;
        p.setLocationIdentifierType(QStringLiteral("test_id"));
        p.setUicLocationIdentifierType(QStringLiteral("uic"));
        const auto res = p.parseStopEventResponse(Test::readFile(inFileName));
        QVERIFY(!p.hasError());
        const auto jsonRes = Stopover::toJson(res);

        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).array();
        QVERIFY(Test::compareJson(refFileName, jsonRes, ref));
    }

    void testParseJourney_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("ch-journey-basic")
            << s(SOURCE_DIR "/data/ojp/ch-journey-basic.xml")
            << s(SOURCE_DIR "/data/ojp/ch-journey-basic.json");
        QTest::newRow("vvo-journey-intermediates")
            << s(SOURCE_DIR "/data/ojp/vvo-journey-intermediates.xml")
            << s(SOURCE_DIR "/data/ojp/vvo-journey-intermediates.json");
    }

    void testParseJourney()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        OpenJourneyPlannerParser p;
        p.setLocationIdentifierType(QStringLiteral("test_id"));
        p.setUicLocationIdentifierType(QStringLiteral("uic"));
        const auto res = p.parseTripResponse(Test::readFile(inFileName));
        QVERIFY(!p.hasError());
        const auto jsonRes = Journey::toJson(res);

        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).array();
        QVERIFY(Test::compareJson(refFileName, jsonRes, ref));
    }

    void testParseError()
    {
        {
            OpenJourneyPlannerParser p;
            p.setLocationIdentifierType(QStringLiteral("test_id"));
            p.setUicLocationIdentifierType(QStringLiteral("uic"));
            auto res = p.parseTripResponse(Test::readFile(s(SOURCE_DIR "/data/ojp/ch-error-notripfound.xml")));
            QVERIFY(res.empty());
            QVERIFY(p.hasError());
            QCOMPARE(p.errorMessage(), QLatin1String("TRIP_NOTRIPFOUND"));
        }

        {
            OpenJourneyPlannerParser p;
            p.setLocationIdentifierType(QStringLiteral("test_id"));
            p.setUicLocationIdentifierType(QStringLiteral("uic"));
            auto res = p.parseStopEventResponse(Test::readFile(s(SOURCE_DIR "/data/ojp/xml-error.xml")));
            QVERIFY(res.empty());
            QVERIFY(p.hasError());
            QCOMPARE(p.errorMessage(), QLatin1String("Premature end of document."));
        }
    }
};

QTEST_GUILESS_MAIN(OjpParserTest)

#include "ojpparsertest.moc"
