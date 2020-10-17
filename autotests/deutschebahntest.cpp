/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backends/deutschebahnvehiclelayoutparser.cpp"

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class DbParserTest : public QObject
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
        qRegisterMetaType<Disruption::Effect>();
    }

    void testVehicleLayoutParse_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("vehicleFileName");
        QTest::addColumn<QString>("platformFileName");
        QTest::addColumn<QString>("departureFileName");

        QTest::newRow("valid-double-segment-ice")
            << s(SOURCE_DIR "/data/deutschebahn/double-segment-ice-input.json")
            << s(SOURCE_DIR "/data/deutschebahn/double-segment-ice-vehicle.json")
            << s(SOURCE_DIR "/data/deutschebahn/double-segment-ice-platform.json")
            << s(SOURCE_DIR "/data/deutschebahn/double-segment-ice-departure.json");

        QTest::newRow("valid-double-deck-ic")
            << s(SOURCE_DIR "/data/deutschebahn/double-deck-ic-input.json")
            << s(SOURCE_DIR "/data/deutschebahn/double-deck-ic-vehicle.json")
            << s(SOURCE_DIR "/data/deutschebahn/double-deck-ic-platform.json")
            << s(SOURCE_DIR "/data/deutschebahn/double-deck-ic-departure.json");

        QTest::newRow("no-position")
            << s(SOURCE_DIR "/data/deutschebahn/no-position-input.json")
            << s(SOURCE_DIR "/data/deutschebahn/no-position-vehicle.json")
            << s(SOURCE_DIR "/data/deutschebahn/no-position-platform.json")
            << s(SOURCE_DIR "/data/deutschebahn/no-position-departure.json");
    }

    void testVehicleLayoutParse()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, vehicleFileName);
        QFETCH(QString, platformFileName);
        QFETCH(QString, departureFileName);

        KPublicTransport::DeutscheBahnVehicleLayoutParser parser;

        QVERIFY(parser.parse(readFile(inFileName)));
        QCOMPARE(parser.error, Reply::NoError);
        QVERIFY(parser.errorMessage.isEmpty());
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

        const auto departureJson = Stopover::toJson(parser.departure);
        const auto departureRef = QJsonDocument::fromJson(readFile(departureFileName)).object();
        if (departureJson != departureRef) {
            qDebug().noquote() << QJsonDocument(departureJson).toJson();
        }
        QVERIFY(!departureJson.isEmpty());
        QCOMPARE(departureJson, departureRef);
    }

    void testVehicleLayoutParseFailure()
    {
        KPublicTransport::DeutscheBahnVehicleLayoutParser parser;

        QVERIFY(!parser.parse(readFile(QStringLiteral(SOURCE_DIR "/data/deutschebahn/not-found-error.json"))));
        QCOMPARE(parser.error, Reply::NotFoundError);
        QVERIFY(!parser.errorMessage.isEmpty());
    }
};

QTEST_GUILESS_MAIN(DbParserTest)

#include "deutschebahntest.moc"
