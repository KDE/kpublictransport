/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"

#include "backends/hafasvehiclelayoutparser.cpp"

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class HafasVehicleLayoutParserTest : public QObject
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
    void testPlatformParse_stcL_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("vehicleFileName");

        QTest::newRow("sbb")
            << s(SOURCE_DIR "/data/hafas/stcL-sbb-input.json")
            << s(SOURCE_DIR "/data/hafas/stcL-sbb-vehicles.json");
    }

    void testPlatformParse_stcL()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, vehicleFileName);

        const auto vehicles = HafasVehicleLayoutParser::parseVehicleLayouts(QJsonDocument::fromJson(readFile(inFileName)).object());
        const auto vehicleJson = Vehicle::toJson(vehicles);
        const auto vehicleRef = QJsonDocument::fromJson(readFile(vehicleFileName)).array();
        QVERIFY(!vehicleJson.isEmpty());
        QVERIFY(Test::compareJson(vehicleFileName, vehicleJson, vehicleRef));
    }

    void testVehicleLayoutParse_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("vehicleFileName");

        QTest::newRow("sbb-ic-bern")
            << s(SOURCE_DIR "/data/hafas/rem-I-JF-sbb-ic-train-formation-bern-input.json")
            << s(SOURCE_DIR "/data/hafas/rem-I-JF-sbb-ic-train-formation-bern-vehicle.json");

        QTest::newRow("sbb-ic-visp")
            << s(SOURCE_DIR "/data/hafas/rem-I-JF-sbb-ic-train-formation-visp-input.json")
            << s(SOURCE_DIR "/data/hafas/rem-I-JF-sbb-ic-train-formation-visp-vehicle.json");

        QTest::newRow("sbb-split-layout")
            << s(SOURCE_DIR "/data/hafas/rem-I-JF-sbb-split-layout-train-formation-input.json")
            << s(SOURCE_DIR "/data/hafas/rem-I-JF-sbb-split-layout-train-formation-vehicle.json");
    }

    void testVehicleLayoutParse()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, vehicleFileName);

        const auto vehicle = HafasVehicleLayoutParser::parseTrainFormation(readFile(inFileName));
        const auto vehicleJson = Vehicle::toJson(vehicle);
        const auto vehicleRef = QJsonDocument::fromJson(readFile(vehicleFileName)).object();
        QVERIFY(!vehicleJson.isEmpty());
        QVERIFY(Test::compareJson(vehicleFileName, vehicleJson, vehicleRef));
    }

    void testPlatformParseXml_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("platformFileName");

        QTest::newRow("sbb-bern")
            << s(SOURCE_DIR "/data/hafas/rem-I-XP-sbb-platform-sectors-bern.xml")
            << s(SOURCE_DIR "/data/hafas/rem-I-XP-sbb-platform-bern.json");
        QTest::newRow("sbb-visp")
            << s(SOURCE_DIR "/data/hafas/rem-I-XP-sbb-platform-sectors-visp.xml")
            << s(SOURCE_DIR "/data/hafas/rem-I-XP-sbb-platform-visp.json");
    }

    void testPlatformParseXml()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, platformFileName);

        const auto platform = HafasVehicleLayoutParser::parsePlatformSectors(readFile(inFileName));
        const auto platformJson = Platform::toJson(platform);
        const auto platformRef = QJsonDocument::fromJson(readFile(platformFileName)).object();
        QVERIFY(!platformJson.isEmpty());
        QVERIFY(Test::compareJson(platformFileName, platformJson, platformRef));
    }

    void testPlatformParse_tcpdL_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("platformFileName");

        QTest::newRow("sbb")
            << s(SOURCE_DIR "/data/hafas/tcpdL-sbb-input.json")
            << s(SOURCE_DIR "/data/hafas/tcpdL-sbb-platforms.json");
    }

    void testPlatformParse_tcpdL()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, platformFileName);

        const auto platforms = HafasVehicleLayoutParser::parsePlatforms(QJsonDocument::fromJson(readFile(inFileName)).object());
        const auto platformJson = Platform::toJson(platforms);
        const auto platformRef = QJsonDocument::fromJson(readFile(platformFileName)).array();
        QVERIFY(!platformJson.isEmpty());
        QVERIFY(Test::compareJson(platformFileName, platformJson, platformRef));
    }
};

QTEST_GUILESS_MAIN(HafasVehicleLayoutParserTest)

#include "hafasvehiclelayoutparsertest.moc"
