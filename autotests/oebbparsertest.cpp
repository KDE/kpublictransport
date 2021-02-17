/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backends/oebbvehiclelayoutparser.cpp"

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class OebbParserTest : public QObject
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
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testVehicleLayoutParse_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("vehicleFileName");
        QTest::addColumn<QString>("platformFileName");
        QTest::addColumn<QString>("departureFileName");

        QTest::newRow("rj-forward")
            << s(SOURCE_DIR "/data/oebb/rj-forward-input.json")
            << s(SOURCE_DIR "/data/oebb/rj-forward-vehicle.json")
            << s(SOURCE_DIR "/data/oebb/rj-forward-platform.json")
            << s(SOURCE_DIR "/data/oebb/rj-forward-departure.json");

        QTest::newRow("ec-no-platform-sectors")
            << s(SOURCE_DIR "/data/oebb/ec-no-platform-sectors-input.json")
            << s(SOURCE_DIR "/data/oebb/ec-no-platform-sectors-vehicle.json")
            << s(SOURCE_DIR "/data/oebb/ec-no-platform-sectors-platform.json")
            << s(SOURCE_DIR "/data/oebb/ec-no-platform-sectors-departure.json");

        QTest::newRow("ice-empty")
            << s(SOURCE_DIR "/data/oebb/ice-empty-input.json")
            << s(SOURCE_DIR "/data/oebb/ice-empty-vehicle.json")
            << s(SOURCE_DIR "/data/oebb/ice-empty-platform.json")
            << s(SOURCE_DIR "/data/oebb/ice-empty-departure.json");
    }

    void testVehicleLayoutParse()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, vehicleFileName);
        QFETCH(QString, platformFileName);
        QFETCH(QString, departureFileName);

        KPublicTransport::OebbVehicleLayoutParser parser;

        QVERIFY(parser.parse(readFile(inFileName)));
        const auto vehicleJson = Vehicle::toJson(parser.vehicle);
        const auto vehicleRef = QJsonDocument::fromJson(readFile(vehicleFileName)).object();
        if (vehicleJson != vehicleRef) {
            qDebug().noquote() << QJsonDocument(vehicleJson).toJson();
        }
        QVERIFY(!vehicleJson.isEmpty());
        QCOMPARE(vehicleJson, vehicleRef);

        const auto platformJson = Platform::toJson(parser.platform);
        const auto platformRef = QJsonDocument::fromJson(readFile(platformFileName)).object();
        if (platformJson != platformRef) {
            qDebug().noquote() << QJsonDocument(platformJson).toJson();
        }
        QVERIFY(!platformJson.isEmpty());
        QCOMPARE(platformJson, platformRef);

        const auto departureJson = Stopover::toJson(parser.stopover);
        const auto departureRef = QJsonDocument::fromJson(readFile(departureFileName)).object();
        if (departureJson != departureRef) {
            qDebug().noquote() << QJsonDocument(departureJson).toJson();
        }
        QVERIFY(!departureJson.isEmpty());
        QCOMPARE(departureJson, departureRef);
    }

    void testInvalid()
    {
        KPublicTransport::OebbVehicleLayoutParser parser;
        QVERIFY(!parser.parse(readFile(QLatin1String(SOURCE_DIR "/data/oebb/invalid-input.json"))));
    }
};

QTEST_GUILESS_MAIN(OebbParserTest)

#include "oebbparsertest.moc"
