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
        QCOMPARE(status.status(), OnboardStatus::NotConnected);
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

        QTest::newRow("cd-railjet") << s("ceskedrahy") << s("cd-railjet.json") << 52.527308f << 13.367355f << 42.0f << NAN;
        QTest::newRow("db-ice") << s("deutschebahn-ice") << s("db-ice.json") << 52.3937f << 10.0929f << 199.0f << NAN;
        QTest::newRow("flixbus") << s("flixbus") << s("flixbus.json") << 53.153505f << 8.274373f << 26.777f << NAN;
        QTest::newRow("sncf-inoui") << s("sncf") << s("sncf-inoui.json") << 48.064258333f << 7.33914f << 29.272f << 212.5f;
        QTest::newRow("thalys") << s("thalys") << s("thalys.json") << 50.948208f << 6.885135f << 45.42f << 259.72f;
    }

    void testScriptedPositionParsers()
    {
        QFETCH(QString, backendId);
        QFETCH(QString, inputFile);
        QFETCH(float, lat);
        QFETCH(float, lon);
        QFETCH(float, speed);
        QFETCH(float, heading);

        auto backend = OnboardStatusManager::createBackend(backendId);
        QVERIFY(backend);
        auto restApi = qobject_cast<const RestOnboardBackend*>(backend.get());
        QVERIFY(restApi);
        QVERIFY(restApi->createPositionRequest().url().isValid());

        QFile f(QLatin1String(SOURCE_DIR) + QLatin1String("/data/onboard-position/") + inputFile);
        QVERIFY(f.open(QFile::ReadOnly));
        const auto inputObj = QJsonDocument::fromJson(f.readAll()).object();

        const auto pos = restApi->parsePositionData(inputObj);
        QCOMPARE(pos.latitude, lat);
        QCOMPARE(pos.longitude, lon);
        QCOMPARE(pos.speed, speed);
        QCOMPARE(pos.heading, heading);
    }

    void testScriptedJourneyParsers_data()
    {
        QTest::addColumn<QString>("backendId");
        QTest::addColumn<QString>("testFile");

        QTest::newRow("cd-railjet") << s("ceskedrahy") << s("cd-railjet");
        QTest::newRow("db-ice") << s("deutschebahn-ice") << s("db-ice");
        QTest::newRow("sncf-inoui") << s("sncf") << s("sncf-inoui");
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
        const auto inputObj = QJsonDocument::fromJson(inputFile.readAll()).object();

        const auto jny = restApi->parseJourneyData(inputObj);
        const auto jsonRes = Journey::toJson(jny);

        const QString refFileName = QLatin1String(SOURCE_DIR) + QLatin1String("/data/onboard-journey/") + testFile + QLatin1String(".out.json");
        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).object();
        QVERIFY(Test::compareJson(refFileName, jsonRes, ref));
    }
};

QTEST_GUILESS_MAIN(OnboardStatusTest)

#include "onboardstatustest.moc"
