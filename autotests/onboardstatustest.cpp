/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"

#include "../src/onboard/onboardstatusmanager_p.h"
#include "../src/onboard/backend/restonboardbackend_p.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/OnboardStatus>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class OnboardStatusTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testFrontend()
    {
        OnboardStatus status;
        QVERIFY(status.status() != OnboardStatus::Onboard);
#ifndef Q_OS_ANDROID
        QVERIFY(status.status() != OnboardStatus::LocationServiceNotEnabled);
        QVERIFY(status.status() != OnboardStatus::MissingPermissions);
#endif
        QVERIFY(!status.hasPosition());
    }

    void testScriptedPositionParsers_data()
    {
        QTest::addColumn<QString>("backendId");
        QTest::addColumn<QString>("inputFile");
        QTest::addColumn<float>("lat");
        QTest::addColumn<float>("lon");
        QTest::addColumn<float>("speed");
        QTest::addColumn<float>("heading");
        QTest::addColumn<float>("altitude");

        QTest::newRow("cd-railjet") << s("ceskedrahy") << s("cd-railjet.json") << 52.527308f << 13.367355f << 42.0f << NAN << 14.4f;
        QTest::newRow("db-ice") << s("deutschebahn-ice") << s("db-ice.json") << 52.3937f << 10.0929f << 199.0f << NAN << NAN;
        QTest::newRow("flixbus") << s("flixbus") << s("flixbus.json") << 53.153505f << 8.274373f << 26.777f << NAN << NAN;
        QTest::newRow("sncf-inoui") << s("sncf-tgv") << s("sncf-inoui.json") << 48.064258333f << 7.33914f << 105.379f << 212.5f << 205.47f;
        QTest::newRow("thalys") << s("icomera-omboard") << s("thalys.json") << 50.948208f << 6.885135f << 163.512f << 259.72f << 54.7f;
        QTest::newRow("oebb-railnet") << s("oebb") << s("oebb-railnet.json") << 47.4719f << 19.022648f << NAN << NAN << NAN;
        QTest::newRow("oebb-railnetregio") << s("oebb") << s("oebb-railnetregio.json") << 48.1459f << 16.4267f << 37.325f  << NAN << NAN;

        QTest::newRow("ana") << s("panasonic-inflight-v1") << s("../onboard-journey/ana.in.json") << 39.3520f << 141.077f << 801.916f << 191.0f << 9753.91f;
        QTest::newRow("united-panasonic") << s("panasonic-inflight-v1") << s("../onboard-journey/united-panasonic.in.json") << 41.5150f << 2.069f << 872.292f << 169.0f << 10668.6f;
        QTest::newRow("cathay-pacific") << s("panasonic-inflight-v2") << s("../onboard-journey/cathay-pacific.in.json") << 23.198333f << 118.836667f << 755.616f << 231.0f << 12187.7f;
        QTest::newRow("aegean") << s("aegean") << s("aegean.json") << 47.96723323f << 11.781437752f << 1007.0f << 137.0f << 7328.0f;
        QTest::newRow("eurowings") << s("lufthansa") << s("../onboard-journey/eurowings.in.json") << 51.58527374267578f << 12.357730865478516f << 637.087f << -137.6375f << 9018.42f;
        QTest::newRow("lufthansa") << s("lufthansa") << s("../onboard-journey/lufthansa.in.json") << 51.9423f << 12.4496f << 718.576f << -120.785f << 6491.63f;
    }

    void testScriptedPositionParsers()
    {
        QFETCH(QString, backendId);
        QFETCH(QString, inputFile);
        QFETCH(float, lat);
        QFETCH(float, lon);
        QFETCH(float, speed);
        QFETCH(float, heading);
        QFETCH(float, altitude);

        auto backend = OnboardStatusManager::createBackend(backendId);
        QVERIFY(backend);
        auto restApi = qobject_cast<const RestOnboardBackend*>(backend.get());
        QVERIFY(restApi);
        QVERIFY(restApi->createPositionRequest().url().isValid());

        QFile f(QLatin1String(SOURCE_DIR) + QLatin1String("/data/onboard-position/") + inputFile);
        QVERIFY(f.open(QFile::ReadOnly));
        const auto inputDoc = QJsonDocument::fromJson(f.readAll());

        PositionData pos;
        if (inputDoc.isArray()) {
            pos = restApi->parsePositionData(inputDoc.array());
        } else {
            pos = restApi->parsePositionData(inputDoc.object());
        }
        QCOMPARE(pos.latitude, lat);
        QCOMPARE(pos.longitude, lon);
        QCOMPARE(pos.speed, speed);
        QCOMPARE(pos.heading, heading);
        QCOMPARE(pos.altitude, altitude);
    }

    void testScriptedJourneyParsers_data()
    {
        QTest::addColumn<QString>("backendId");
        QTest::addColumn<QString>("testFile");

        QTest::newRow("cd-railjet") << s("ceskedrahy") << s("cd-railjet");
        QTest::newRow("db-ice") << s("deutschebahn-ice") << s("db-ice");
        QTest::newRow("db-ice-canceled-stops") << s("deutschebahn-ice") << s("db-ice-canceled-stops");
        QTest::newRow("db-zugportal") << s("deutschebahn-zugportal") << s("db-zugportal");
        QTest::newRow("db-zugportal-canceled") << s("deutschebahn-zugportal") << s("db-zugportal-canceled");
        QTest::newRow("db-zugportal-occupancy") << s("deutschebahn-zugportal") << s("db-zugportal-occupancy");
        QTest::newRow("sncf-inoui") << s("sncf-tgv") << s("sncf-inoui");
        QTest::newRow("sbb") << s("sbb") << s("sbb");
        QTest::newRow("oebb-railnet") << s("oebb") << s("oebb-railnet");

        QTest::newRow("ana") << s("panasonic-inflight-v1") << s("ana");
        QTest::newRow("unite-panasonic") << s("panasonic-inflight-v1") << s("united-panasonic");
        QTest::newRow("cathay-pacific") << s("panasonic-inflight-v2") << s("cathay-pacific");
        QTest::newRow("eurowings") << s("lufthansa") << s("eurowings");
        QTest::newRow("lufthansa") << s("lufthansa") << s("lufthansa");
        QTest::newRow("united") << s("united") << s("united");
        QTest::newRow("nstrein") << s("nstrein") << s("nstrein");
    }

    void testScriptedJourneyParsers()
    {
        QFETCH(QString, backendId);
        QFETCH(QString, testFile);

        auto backend = OnboardStatusManager::createBackend(backendId);
        QVERIFY(backend);
        auto restApi = qobject_cast<const RestOnboardBackend*>(backend.get());
        QVERIFY(restApi);
        QVERIFY(restApi->createJourneyRequest().url().isValid());

        QFile inputFile(QLatin1String(SOURCE_DIR) + QLatin1String("/data/onboard-journey/") + testFile + QLatin1String(".in.json"));
        QVERIFY(inputFile.open(QFile::ReadOnly));

        const auto inputDoc = QJsonDocument::fromJson(inputFile.readAll());
        Journey jny;
        if (inputDoc.isArray()) {
            jny = restApi->parseJourneyData(inputDoc.array());
        } else {
            jny = restApi->parseJourneyData(inputDoc.object());
        }

        const auto jsonRes = Journey::toJson(jny);

        const QString refFileName = QLatin1String(SOURCE_DIR) + QLatin1String("/data/onboard-journey/") + testFile + QLatin1String(".out.json");
        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).object();
        QVERIFY(Test::compareJson(refFileName, jsonRes, ref));
    }

    void testScriptedSupport_data()
    {
        QTest::addColumn<QString>("backendId");
        QTest::addColumn<bool>("supportsPosition");
        QTest::addColumn<bool>("supportsJourney");

        QTest::newRow("cd-railjet") << s("ceskedrahy") << true << true;
        QTest::newRow("db-ice") << s("deutschebahn-ice") << true << true;
        QTest::newRow("db-zugportal") << s("deutschebahn-zugportal") << false << true;
        QTest::newRow("sncf-inoui") << s("sncf-tgv") << true << true;
        QTest::newRow("sbb") << s("sbb") << true << true;
        QTest::newRow("thalys") << s("icomera-omboard") << true << false;

        QTest::newRow("ana") << s("panasonic-inflight-v1") << true << true;
        QTest::newRow("united") << s("panasonic-inflight-v1") << true << true;
        QTest::newRow("cathay-pacific") << s("panasonic-inflight-v2") << true << true;
        QTest::newRow("aegean") << s("aegean") << true << false;
        QTest::newRow("eurowings") << s("eurowings") << true << true;
    }

    void testScriptedSupport()
    {
        QFETCH(QString, backendId);
        QFETCH(bool, supportsPosition);
        QFETCH(bool, supportsJourney);

        auto backend = OnboardStatusManager::createBackend(backendId);
        QVERIFY(backend);
        auto restApi = qobject_cast<const RestOnboardBackend*>(backend.get());
        QVERIFY(restApi);

        QCOMPARE(restApi->supportsPosition(), supportsPosition);
        QCOMPARE(restApi->supportsJourney(), supportsJourney);
    }
};

QTEST_GUILESS_MAIN(OnboardStatusTest)

#include "onboardstatustest.moc"
