/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Line>
#include <KPublicTransport/NavitiaParser>
#include <KPublicTransport/RentalVehicle>
#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJsonDocument>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

class NavitiaParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
        qRegisterMetaType<KPublicTransport::RentalVehicle>();
    }

    void testParseJourney_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");
        QTest::addColumn<QString>("attrRefFileName");

        QTest::newRow("journey")
            << s(SOURCE_DIR "/data/navitia/journey-response.json")
            << s(SOURCE_DIR "/data/navitia/journey-response.out.json")
            << s(SOURCE_DIR "/data/navitia/journey-response.attr.json");
        QTest::newRow("journey-bss-path-no-instr-start-coord")
            << s(SOURCE_DIR "/data/navitia/journey-bss-path-no-instr-start-coord.json")
            << s(SOURCE_DIR "/data/navitia/journey-bss-path-no-instr-start-coord.out.json")
            << s(SOURCE_DIR "/data/navitia/journey-bss-path-no-instr-start-coord.attr.json");
    }

    void testParseJourney()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);
        QFETCH(QString, attrRefFileName);

        NavitiaParser parser;
        const auto res = parser.parseJourneys(Test::readFile(inFileName));
        const auto jsonRes = Journey::toJson(res);

        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).array();
        QVERIFY(Test::compareJson(refFileName, jsonRes, ref));

        QVERIFY(parser.nextLink.isValid());
        QVERIFY(parser.prevLink.isValid());

        const auto attrRes = Attribution::toJson(parser.attributions);
        const auto attrRef = QJsonDocument::fromJson(Test::readFile(attrRefFileName)).array();
        QVERIFY(Test::compareJson(attrRefFileName, attrRes, attrRef));
    }

    void testParseDepartures()
    {
        KPublicTransport::NavitiaParser parser;
        const auto res = parser.parseDepartures(Test::readFile(s(SOURCE_DIR "/data/navitia/departure-response.json")));
        QCOMPARE(res.size(), 10);

        {
            const auto departure = res[0];
            QCOMPARE(departure.scheduledDepartureTime(), QDateTime({2018, 12, 10}, {17, 17}, QTimeZone("Europe/Paris")));
            QCOMPARE(departure.hasExpectedDepartureTime(), false);
            QCOMPARE(departure.scheduledArrivalTime(), QDateTime({2018, 12, 10}, {17, 17}, QTimeZone("Europe/Paris")));
            QCOMPARE(departure.hasExpectedArrivalTime(), false);
            QCOMPARE(departure.stopPoint().name(), QStringLiteral("Gare de Lyon - Diderot (Paris)"));
            QCOMPARE(departure.route().direction(), QStringLiteral("Porte de la Chapelle (Paris)"));
            QCOMPARE(departure.route().line().mode(), KPublicTransport::Line::Bus);
            QCOMPARE(departure.route().line().name(), QStringLiteral("65"));
            QCOMPARE(departure.route().line().color(), QColor(0x00, 0x8b, 0x5a));
            QCOMPARE(departure.route().line().operatorName(), "RATP"_L1);
            QVERIFY(!departure.route().destination().isEmpty());
            QVERIFY(departure.route().destination().hasCoordinate());
            QCOMPARE(departure.route().direction(), departure.route().destination().name());
        }

        {
            const auto departure = res[3];
            QCOMPARE(departure.scheduledDepartureTime(), QDateTime({2018, 12, 10}, {17, 19}, QTimeZone("Europe/Paris")));
            QCOMPARE(departure.hasExpectedDepartureTime(), true);
            QCOMPARE(departure.expectedDepartureTime(), QDateTime({2018, 12, 10}, {17, 21}, QTimeZone("Europe/Paris")));
            QCOMPARE(departure.stopPoint().name(), QStringLiteral("Gare de Lyon RER D (Paris)"));
            QCOMPARE(departure.route().direction(), QStringLiteral("Gare de Villiers le Bel Gonesse Arnouville (Arnouville)"));
            QCOMPARE(departure.route().line().mode(), KPublicTransport::Line::RapidTransit);
            QCOMPARE(departure.route().line().modeString(), QStringLiteral("RER"));
            QCOMPARE(departure.route().line().name(), QStringLiteral("D"));
            QCOMPARE(departure.route().line().color(), QColor(0x5E, 0x96, 0x20));
            QVERIFY(!departure.route().destination().isEmpty());
            QVERIFY(departure.route().destination().hasCoordinate());
            QCOMPARE(departure.route().destination().name(), QStringLiteral("Gare de Goussainville (Goussainville)"));
        }

        QCOMPARE(parser.attributions.size(), 2);
        const auto &attr = parser.attributions.at(0);
        QCOMPARE(attr.name(), QStringLiteral("openstreetmap"));
        QCOMPARE(attr.license(), QStringLiteral("ODbL"));
        QEXPECT_FAIL("", "not implemented yet", Continue);
        QCOMPARE(attr.licenseUrl().host(), QStringLiteral("spdx.org"));
        QCOMPARE(attr.url().host(), QStringLiteral("www.openstreetmap.org"));
    }
};

QTEST_GUILESS_MAIN(NavitiaParserTest)

#include "navitiaparsertest.moc"
