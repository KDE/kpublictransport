/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"
#include "backends/opentripplannerparser.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/RentalVehicle>
#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

using RentalVehicleNetworkMap = QHash<QString, RentalVehicleNetwork>;

class OtpParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
        QLocale::setDefault(QLocale(QLocale::Swedish, QLocale::Finland));
        qRegisterMetaType<Disruption::Effect>();
        qRegisterMetaType<RentalVehicle>();
    }

    void testParseLocationByCoordinate_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");
        QTest::addColumn<RentalVehicleNetworkMap>("networks");

        QTest::newRow("fi-digitransit-location")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-location-by-coordinate.in.json")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-location-by-coordinate.out.json")
            << RentalVehicleNetworkMap();

        RentalVehicleNetworkMap networks;
        networks.insert(s("car-sharing"), {});
        networks.insert(s("taxi"), {});
        RentalVehicleNetwork n;
        n.setName(s("RegioRad"));
        n.setVehicleTypes(RentalVehicle::Bicycle);
        networks.insert(s("regiorad"), n);
        QTest::newRow("de-stadtnavi-rental-vehicle-locations")
            << s(SOURCE_DIR "/data/otp/de-stadtnavi-rental-vehicle-locations.in.json")
            << s(SOURCE_DIR "/data/otp/de-stadtnavi-rental-vehicle-locations.out.json")
            << networks;
    }

    void testParseLocationByCoordinate()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);
        QFETCH(RentalVehicleNetworkMap, networks);

        OpenTripPlannerParser p(s("gtfs"));
        p.setKnownRentalVehicleNetworks(networks);
        const auto res = p.parseLocationsByCoordinate(QJsonDocument::fromJson(Test::readFile(inFileName)).object());
        const auto jsonRes = Location::toJson(res);

        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }

    void testParseLocationByName_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("fi-digitransit-location")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-location-by-name.in.json")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-location-by-name.out.json");
        QTest::newRow("it-torino-location")
            << s(SOURCE_DIR "/data/otp/it-torino-location-by-name.in.json")
            << s(SOURCE_DIR "/data/otp/it-torino-location-by-name.out.json");
    }

    void testParseLocationByName()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        OpenTripPlannerParser p(s("gtfs"));
        const auto res = p.parseLocationsByName(QJsonDocument::fromJson(Test::readFile(inFileName)).object());
        const auto jsonRes = Location::toJson(res);

        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }

    void testParseDepartures_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("fi-digitransit-departures")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-departure.in.json")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-departure.out.json");
    }

    void testParseDepartures()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        OpenTripPlannerParser p(s("gtfs"));
        const auto res = p.parseDepartures(QJsonDocument::fromJson(Test::readFile(inFileName)).object());
        const auto jsonRes = Stopover::toJson(res);

        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }

    void testParseJourney_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");
        QTest::addColumn<QString>("networkConfig");

        QTest::newRow("fi-digitransit-journey")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-journey.in.json")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-journey.out.json")
            << QString();
        QTest::newRow("no-entur-journey")
            << s(SOURCE_DIR "/data/otp/no-entur-journey.in.json")
            << s(SOURCE_DIR "/data/otp/no-entur-journey.out.json")
            << QString();
        QTest::newRow("de-ulm-rentalbike-journey")
            << s(SOURCE_DIR "/data/otp/de-ulm-rentalbike-journey.in.json")
            << s(SOURCE_DIR "/data/otp/de-ulm-rentalbike-journey.out.json")
            << s(SOURCE_DIR "/../src/lib/networks/de_bw_ulm.json");
        QTest::newRow("de-stadtnavi-carpool-journey")
            << s(SOURCE_DIR "/data/otp/de-stadtnavi-carpool-journey.in.json")
            << s(SOURCE_DIR "/data/otp/de-stadtnavi-carpool-journey.out.json")
            << s(SOURCE_DIR "/../src/lib/networks/de_bw_stadtnavi.json");
        QTest::newRow("de-stadtnavi-bike-parking-journey")
            << s(SOURCE_DIR "/data/otp/de-stadtnavi-bike-parking-journey.in.json")
            << s(SOURCE_DIR "/data/otp/de-stadtnavi-bike-parking-journey.out.json")
            << s(SOURCE_DIR "/../src/lib/networks/de_bw_stadtnavi.json");
        QTest::newRow("no-entur-navigation-guides")
            << s(SOURCE_DIR "/data/otp/no-entur-navigation-guides.in.json")
            << s(SOURCE_DIR "/data/otp/no-entur-navigation-guides.out.json")
            << QString();
    }

    void testParseJourney()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);
        QFETCH(QString, networkConfig);

        const auto configObj = QJsonDocument::fromJson(Test::readFile(networkConfig)).object();
        const auto networkConfigObj = configObj.value(QLatin1String("options")).toObject().value(QLatin1String("rentalVehicleNetworks")).toObject();
        QHash <QString, RentalVehicleNetwork> rentalVehicleNetworks;
        for (auto it = networkConfigObj.begin(); it != networkConfigObj.end(); ++it) {
            auto n = RentalVehicleNetwork::fromJson(it.value().toObject());
            rentalVehicleNetworks.insert(it.key(), std::move(n));
        }

        OpenTripPlannerParser p(s("gtfs"), s("1"));
        p.setKnownRentalVehicleNetworks(rentalVehicleNetworks);
        const auto res = p.parseJourneys(QJsonDocument::fromJson(Test::readFile(inFileName)).object());
        const auto jsonRes = Journey::toJson(res);

        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).array();

        QVERIFY(!jsonRes.empty());
        QVERIFY(Test::compareJson(refFileName, jsonRes, ref));
    }
};

QTEST_GUILESS_MAIN(OtpParserTest)

#include "otpparsertest.moc"
