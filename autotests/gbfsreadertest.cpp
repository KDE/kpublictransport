/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"

#include "../src/lib/gbfs/gbfsreader.cpp"
#include "../src/lib/gbfs/gbfsvehicletype.cpp"
#include "../src/lib/gbfs/gbfsvehicletypes.cpp"

#include <KPublicTransport/RentalVehicle>

#include <QJsonDocument>
#include <QJsonObject>
#include <QTest>

#include <cmath>

using namespace Qt::Literals;
using namespace KPublicTransport;

class GBFSReaderTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testReadCoords()
    {
        auto obj = QJsonDocument::fromJson("{\"lat\":48.396619,\"lon\":9.990212}").object();
        QCOMPARE(obj.size(), 2);
        QCOMPARE(GBFSReader::readLatitude(obj), 48.396619);
        QCOMPARE(GBFSReader::readLongitude(obj), 9.990212);
        obj = QJsonDocument::fromJson("{\"lat\":\"41.4852\",\"lon\":\"-81.8039\",\"vehicle_type\":\"scooter\"}").object();
        QCOMPARE(obj.size(), 3);
        QCOMPARE(GBFSReader::readLatitude(obj), 41.4852);
        QCOMPARE(GBFSReader::readLongitude(obj), -81.8039);
        obj = {};
        QCOMPARE(GBFSReader::readLatitude(obj), NAN);
        QCOMPARE(GBFSReader::readLongitude(obj), NAN);
    }

    void testReadVehicleNetwork_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("bolt-oslo-3.0")
            << u"" SOURCE_DIR "/data/gbfs/bolt-oslo-gbfs2.3.in.json"_s
            << u"" SOURCE_DIR "/data/gbfs/bolt-oslo-gbfs2.3.out.json"_s;
        QTest::newRow("voi-oslo-3.0")
            << u"" SOURCE_DIR "/data/gbfs/voi-oslo-gbfs3.0.in.json"_s
            << u"" SOURCE_DIR "/data/gbfs/voi-oslo-gbfs3.0.out.json"_s;
    }

    void testReadVehicleNetwork()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        const auto net = GBFSReader::readSystemInformation(QJsonDocument::fromJson(Test::readFile(inFileName)).object());
        const auto resultJson = RentalVehicleNetwork::toJson(net);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).object();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }

    void testReadVehicleTypes_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("bolt-electric-scooter-2.3")
            << u"" SOURCE_DIR "/data/gbfs/bolt-electric-scooter-gbfs2.3.in.json"_s
            << u"" SOURCE_DIR "/data/gbfs/bolt-electric-scooter-gbfs2.3.out.json"_s;
        QTest::newRow("getaround-electric-car-3.0")
            << u"" SOURCE_DIR "/data/gbfs/getaround-electric-car-gbfs3.0.in.json"_s
            << u"" SOURCE_DIR "/data/gbfs/getaround-electric-car-gbfs3.0.out.json"_s;
        QTest::newRow("urbansharing-bike-2.3")
            << u"" SOURCE_DIR "/data/gbfs/urbansharing-bike-gbfs2.3.in.json"_s
            << u"" SOURCE_DIR "/data/gbfs/urbansharing-bike-gbfs2.3.out.json"_s;
        QTest::newRow("voi-electric-scooter-3.0")
            << u"" SOURCE_DIR "/data/gbfs/voi-electric-scooter-gbfs3.0.in.json"_s
            << u"" SOURCE_DIR "/data/gbfs/voi-electric-scooter-gbfs3.0.out.json"_s;
    }

    void testReadVehicleTypes()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        const auto vt = GBFSVehicleType::fromGbfs(QJsonDocument::fromJson(Test::readFile(inFileName)).object());
        const auto resultJson = RentalVehicleType::toJson(vt);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).object();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }

    void testReadStation_data()
    {
        QTest::addColumn<QString>("vehicleTypesFileName");
        QTest::addColumn<QString>("stationInfoFileName");
        QTest::addColumn<QString>("stationStatusFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("dott-trondheim-3.0")
            << u"" SOURCE_DIR "/data/gbfs/dott-trondheim-gbfs3.0-vehicletypes.json"_s
            << u"" SOURCE_DIR "/data/gbfs/dott-trondheim-station-gbfs3.0-station.json"_s
            << u"" SOURCE_DIR "/data/gbfs/dott-trondheim-station-gbfs3.0-status.json"_s
            << u"" SOURCE_DIR "/data/gbfs/dott-trondheim-station-gbfs3.0-out.json"_s;
        QTest::newRow("bysykkel-oslo-3.0")
            << u"" SOURCE_DIR "/data/gbfs/bysykkel-oslo-gbfs3.0-vehicletypes.json"_s
            << u"" SOURCE_DIR "/data/gbfs/bysykkel-oslo-station-gbfs3.0-station.json"_s
            << u"" SOURCE_DIR "/data/gbfs/bysykkel-oslo-station-gbfs3.0-status.json"_s
            << u"" SOURCE_DIR "/data/gbfs/bysykkel-oslo-station-gbfs3.0-out.json"_s;
        QTest::newRow("bysykkel-oslo-2.3")
            << u"" SOURCE_DIR "/data/gbfs/bysykkel-oslo-gbfs2.3-vehicletypes.json"_s
            << u"" SOURCE_DIR "/data/gbfs/bysykkel-oslo-station-gbfs2.3-station.json"_s
            << u"" SOURCE_DIR "/data/gbfs/bysykkel-oslo-station-gbfs2.3-status.json"_s
            << u"" SOURCE_DIR "/data/gbfs/bysykkel-oslo-station-gbfs2.3-out.json"_s;
        QTest::newRow("ch-2.1")
            << QString()
            << u"" SOURCE_DIR "/data/gbfs/ch-station-gbfs2.1-station.json"_s
            << u"" SOURCE_DIR "/data/gbfs/ch-station-gbfs2.1-status.json"_s
            << u"" SOURCE_DIR "/data/gbfs/ch-station-gbfs2.1-out.json"_s;
        QTest::newRow("bird-schaffhausen-3.0")
            << u"" SOURCE_DIR "/data/gbfs/bird-schaffhausen-gbfs3.0-vehicletypes.json"_s
            << u"" SOURCE_DIR "/data/gbfs/bird-schaffhausen-station-gbfs3.0-station.json"_s
            << u"" SOURCE_DIR "/data/gbfs/bird-schaffhausen-station-gbfs3.0-status.json"_s
            << u"" SOURCE_DIR "/data/gbfs/bird-schaffhausen-station-gbfs3.0-out.json"_s;
    }

    void testReadStation()
    {
        QFETCH(QString, vehicleTypesFileName);
        QFETCH(QString, stationInfoFileName);
        QFETCH(QString, stationStatusFileName);
        QFETCH(QString, outFileName);

        const GBFSVehicleTypes vehicleTypes(QJsonDocument::fromJson(Test::readFile(vehicleTypesFileName)));
        auto s = GBFSReader::readStationInformation(QJsonDocument::fromJson(Test::readFile(stationInfoFileName)).object(), vehicleTypes);
        GBFSReader::readStationStatus(QJsonDocument::fromJson(Test::readFile(stationStatusFileName)).object(), s, vehicleTypes);
        const auto resultJson = RentalVehicleStation::toJson(s);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).object();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }

    void testReadVehicle_data()
    {
        QTest::addColumn<QString>("vehicleTypesFileName");
        QTest::addColumn<QString>("vehicleFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("dott-trondheim-3.0")
            << u"" SOURCE_DIR "/data/gbfs/dott-trondheim-gbfs3.0-vehicletypes.json"_s
            << u"" SOURCE_DIR "/data/gbfs/dott-trondheim-vehicle-gbfs3.0-status.json"_s
            << u"" SOURCE_DIR "/data/gbfs/dott-trondheim-vehicle-gbfs3.0-out.json"_s;
    }

    void testReadVehicle()
    {
        QFETCH(QString, vehicleTypesFileName);
        QFETCH(QString, vehicleFileName);
        QFETCH(QString, outFileName);

        const GBFSVehicleTypes vehicleTypes(QJsonDocument::fromJson(Test::readFile(vehicleTypesFileName)));
        const auto v = GBFSReader::readVehicleStatus(QJsonDocument::fromJson(Test::readFile(vehicleFileName)).object(), vehicleTypes);
        const auto resultJson = RentalVehicle::toJson(v);
        const auto resultRef = QJsonDocument::fromJson(Test::readFile(outFileName)).object();
        QVERIFY(!resultJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, resultJson, resultRef));
    }
};

QTEST_APPLESS_MAIN(GBFSReaderTest)

#include "gbfsreadertest.moc"
