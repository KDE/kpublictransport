/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/HafasMgateParser>
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

class HafasMgateParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
        qRegisterMetaType<Disruption::Effect>();
    }

    void testParseGeneralError_data()
    {
        QTest::addColumn<QString>("input");
        QTest::newRow("version") << s(SOURCE_DIR "/data/hafas/error-invalid-version.json");
        QTest::newRow("parse-clientId") << s(SOURCE_DIR "/data/hafas/error-parse-clientId.json");
        QTest::newRow("parse-stbFilterEquiv") << s(SOURCE_DIR "/data/hafas/error-parse-stbFilterEquiv.json");
        QTest::newRow("parse-empty") << s(SOURCE_DIR "/data/hafas/error-parse-empty.json");
    }

    void testParseGeneralError()
    {
        QFETCH(QString, input);

        {
            HafasMgateParser p;
            p.parseLocations(Test::readFile(input));
            QCOMPARE(p.error(), Reply::UnknownError);
            QVERIFY(!p.errorMessage().isEmpty());
        }

        {
            HafasMgateParser p;
            p.parseDepartures(Test::readFile(input));
            QCOMPARE(p.error(), Reply::UnknownError);
            QVERIFY(!p.errorMessage().isEmpty());
        }

        {
            HafasMgateParser p;
            p.parseJourneys(Test::readFile(input));
            QCOMPARE(p.error(), Reply::UnknownError);
            QVERIFY(!p.errorMessage().isEmpty());
        }
    }

    void testParseDepartureError()
    {
        HafasMgateParser p;
        const auto res = p.parseDepartures(Test::readFile(s(SOURCE_DIR "/data/hafas/stationboard-error-response.json")));
        QVERIFY(res.empty());
        QCOMPARE(p.error(), Reply::NotFoundError);
        QVERIFY(!p.errorMessage().isEmpty());
    }

    void parseDateTime_data()
    {
        QTest::addColumn<QString>("date");
        QTest::addColumn<QString>("time");
        QTest::addColumn<QJsonValue>("tzOffset");
        QTest::addColumn<QDateTime>("dt");

        QTest::newRow("empty") << QString() << QString() << QJsonValue() << QDateTime();
        QTest::newRow("same day") << s("20190105") << s("142100") << QJsonValue() << QDateTime({2019, 1, 5}, {14, 21});
        QTest::newRow("next day") << s("20190105") << s("01142100") << QJsonValue() << QDateTime({2019, 1, 6}, {14, 21});
        QTest::newRow("same day offset") << s("20190105") << s("142100") << QJsonValue(120) << QDateTime({2019, 1, 5}, {14, 21}, QTimeZone::fromSecondsAheadOfUtc(7200));
        QTest::newRow("next day offset") << s("20190105") << s("01142100") << QJsonValue(-120) << QDateTime({2019, 1, 6}, {14, 21}, QTimeZone::fromSecondsAheadOfUtc(-7200));
    }

    void parseDateTime()
    {
        QFETCH(QString, date);
        QFETCH(QString, time);
        QFETCH(QJsonValue, tzOffset);
        QFETCH(QDateTime, dt);
        QCOMPARE(HafasMgateParser::parseDateTime(date, QJsonValue(time), tzOffset), dt);
    }

    void testParseDepartures_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("de-nw-avv-canceled-departures")
            << s(SOURCE_DIR "/data/hafas/canceled-departures.in.json")
            << s(SOURCE_DIR "/data/hafas/canceled-departures.out.json");
    }

    void testParseDepartures()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        HafasMgateParser p;
        p.setLocationIdentifierTypes(QStringLiteral("unit-test"));
        const auto res = p.parseDepartures(Test::readFile(inFileName));
        const auto jsonRes = Stopover::toJson(res);

        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }

    void testParseJourneys_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("de-db-canceled-with-path")
            << s(SOURCE_DIR "/data/hafas/canceled-journey-with-path.in.json")
            << s(SOURCE_DIR "/data/hafas/canceled-journey-with-path.out.json");
        QTest::newRow("de-bvg-alternative-load-messages")
            << s(SOURCE_DIR "/data/hafas/journey-bvg-load-messages.in.json")
            << s(SOURCE_DIR "/data/hafas/journey-bvg-load-messages.out.json");
        QTest::newRow("de-vsn-alternative-platform-data")
            << s(SOURCE_DIR "/data/hafas/journey-vsn-alternative-platform-data.in.json")
            << s(SOURCE_DIR "/data/hafas/journey-vsn-alternative-platform-data.out.json");
    }

    void testParseJourneys()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        HafasMgateParser p;
        p.setLocationIdentifierTypes(QStringLiteral("unit-test"));
        const auto res = p.parseJourneys(Test::readFile(inFileName));
        const auto jsonRes = Journey::toJson(res);

        const auto ref = QJsonDocument::fromJson(Test::readFile(refFileName)).array();

        QVERIFY(!jsonRes.empty());
        QVERIFY(Test::compareJson(refFileName, jsonRes, ref));
    }
};

QTEST_GUILESS_MAIN(HafasMgateParserTest)

#include "hafasmgateparsertest.moc"
