/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Line>
#include <KPublicTransport/NavitiaParser>
#include <KPublicTransport/Stopover>

#include <QFile>
#include <QTest>
#include <QTimeZone>

class NavitiaParserTest : public QObject
{
    Q_OBJECT
private:
    QByteArray readFile(const char *fn)
    {
        QFile f(QString::fromUtf8(fn));
        f.open(QFile::ReadOnly);
        return f.readAll();
    }

private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testParseJourneys()
    {
        KPublicTransport::NavitiaParser parser;
        const auto res = parser.parseJourneys(readFile(SOURCE_DIR "/data/navitia/journey-response.json"));
        QCOMPARE(res.size(), 4);

        {
            const auto journey = res[0];
            QCOMPARE(journey.sections().size(), 6);
            QCOMPARE(journey.scheduledDepartureTime(), QDateTime({2018, 12, 2}, {22, 4, 51}));
            QEXPECT_FAIL("", "tz propagation not implemented yet", Continue);
            QCOMPARE(journey.scheduledDepartureTime().timeZone().id(), "Europe/Paris");
            QCOMPARE(journey.scheduledArrivalTime(), QDateTime({2018, 12, 2}, {23, 0, 15}));
            QEXPECT_FAIL("", "tz propagation not implemented yet", Continue);
            QCOMPARE(journey.scheduledArrivalTime().timeZone().id(), "Europe/Paris");
            QCOMPARE(journey.duration(), 3324);

            auto sec = journey.sections()[0];
            QCOMPARE(sec.mode(), KPublicTransport::JourneySection::Walking);
            QCOMPARE(sec.distance(), 77);
            QEXPECT_FAIL("", "tz propagation not implemented yet", Continue);
            QCOMPARE(sec.from().timeZone().id(), "Europe/Paris");

            sec = journey.sections()[1];
            QCOMPARE(sec.mode(), KPublicTransport::JourneySection::PublicTransport);
            QCOMPARE(sec.scheduledDepartureTime(), QDateTime({2018, 12, 2}, {22, 6}, QTimeZone("Europe/Paris")));
            QCOMPARE(sec.scheduledDepartureTime().timeZone().id(), "Europe/Paris");
            QCOMPARE(sec.hasExpectedDepartureTime(), false);
            QCOMPARE(sec.scheduledArrivalTime(), QDateTime({2018, 12, 2}, {22, 41}, QTimeZone("Europe/Paris")));
            QCOMPARE(sec.scheduledArrivalTime().timeZone().id(), "Europe/Paris");
            QCOMPARE(sec.hasExpectedArrivalTime(), false);
            QCOMPARE(sec.duration(), 2100);
            QCOMPARE(sec.from().name(), QStringLiteral("Aéroport CDG 2 TGV (Le Mesnil-Amelot)"));
            QCOMPARE(sec.from().latitude(), 49.0047f);
            QCOMPARE(sec.from().timeZone().id(), "Europe/Paris");
            QCOMPARE(sec.from().locality(), QStringLiteral("Le Mesnil-Amelot"));
            QCOMPARE(sec.to().name(), QStringLiteral("Châtelet les Halles (Paris)"));
            QCOMPARE(sec.to().longitude(), 2.34701f);
            QCOMPARE(sec.to().timeZone().id(), "Europe/Paris");
            QCOMPARE(sec.to().locality(), QStringLiteral("Paris"));
            QCOMPARE(sec.to().postalCode(), QStringLiteral("75001"));
            QCOMPARE(sec.route().line().name(), QStringLiteral("B"));
            QCOMPARE(sec.route().line().mode(), KPublicTransport::Line::RapidTransit);
            QCOMPARE(sec.route().line().modeString(), QStringLiteral("RER"));
            QCOMPARE(sec.route().line().color(), QColor(123, 163, 220));
            QCOMPARE(sec.route().line().textColor(), QColor(255, 255, 255));
            QCOMPARE(sec.intermediateStops().size(), 3);
            for (const auto &stop : sec.intermediateStops()) {
                QVERIFY(!stop.stopPoint().name().isEmpty());
                QVERIFY(stop.stopPoint().hasCoordinate());
                QVERIFY(stop.scheduledArrivalTime().isValid());
                QVERIFY(stop.scheduledDepartureTime().isValid());
                QVERIFY(!stop.expectedArrivalTime().isValid());
                QVERIFY(!stop.expectedDepartureTime().isValid());
            }
            QCOMPARE(sec.co2Emission(), 147);
            QCOMPARE(sec.path().isEmpty(), false);
            QCOMPARE(sec.path().sections()[0].path().size(), 5);

            sec = journey.sections()[2];
            QCOMPARE(sec.mode(), KPublicTransport::JourneySection::Transfer);

            sec = journey.sections()[3];
            QCOMPARE(sec.mode(), KPublicTransport::JourneySection::Waiting);

            sec = journey.sections()[4];
            QCOMPARE(sec.scheduledDepartureTime(), QDateTime({2018, 12, 2}, {22, 49}, QTimeZone("Europe/Paris")));
            QCOMPARE(sec.scheduledArrivalTime(), QDateTime({2018, 12, 2}, {22, 51}, QTimeZone("Europe/Paris")));
            QCOMPARE(sec.duration(), 120);
            QCOMPARE(sec.route().line().name(), QStringLiteral("A"));
            QCOMPARE(sec.route().line().color(), QColor(QStringLiteral("#D1302F")));
            QCOMPARE(sec.route().line().textColor(), QColor(255, 255, 255));
            QCOMPARE(sec.from().name(), QStringLiteral("Châtelet les Halles (Paris)"));
            QCOMPARE(sec.to().name(), QStringLiteral("Gare de Lyon RER A (Paris)"));
            QCOMPARE(sec.intermediateStops().size(), 0);
        }

        {
            const auto journey = res[1];
            QCOMPARE(journey.sections().size(), 6);

            auto sec = journey.sections()[1];
            QCOMPARE(sec.route().line().name(), QStringLiteral("B"));
            QCOMPARE(sec.route().line().mode(), KPublicTransport::Line::RapidTransit);
            sec = journey.sections()[4];
            QCOMPARE(sec.route().line().name(), QStringLiteral("65"));
        }

        {
            const auto journey = res[2];
            QCOMPARE(journey.sections().size(), 6);

            auto sec = journey.sections()[1];
            QCOMPARE(sec.route().line().name(), QStringLiteral("B"));
            sec = journey.sections()[4];
            QCOMPARE(sec.route().line().name(), QStringLiteral("91"));
            QCOMPARE(sec.route().line().modeString(), QStringLiteral("Bus"));
            QCOMPARE(sec.route().line().mode(), KPublicTransport::Line::Bus);
        }

        {
            const auto journey = res[3];
            QCOMPARE(journey.sections().size(), 3);

            auto sec = journey.sections()[1];
            QCOMPARE(sec.route().line().name(), QStringLiteral("DIRECT 4"));
            QCOMPARE(sec.route().line().mode(), KPublicTransport::Line::Bus);
            QCOMPARE(sec.route().line().modeString(), QStringLiteral("Bus"));
        }

        QVERIFY(parser.nextLink.isValid());
        QVERIFY(parser.prevLink.isValid());

        QCOMPARE(parser.attributions.size(), 2);
        const auto &attr = parser.attributions.at(0);
        QCOMPARE(attr.name(), QStringLiteral("openstreetmap"));
        QCOMPARE(attr.license(), QStringLiteral("ODbL"));
        QEXPECT_FAIL("", "not implemented yet", Continue);
        QCOMPARE(attr.licenseUrl().host(), QStringLiteral("spdx.org"));
        QCOMPARE(attr.url().host(), QStringLiteral("www.openstreetmap.org"));
    }

    void testParseDepartures()
    {
        KPublicTransport::NavitiaParser parser;
        const auto res = parser.parseDepartures(readFile(SOURCE_DIR "/data/navitia/departure-response.json"));
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
