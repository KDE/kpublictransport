/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"

#include "backends/deutschebahnparser.cpp"
#include "backends/hafasmgateparser.h"
#include "datatypes/featureutil.cpp"

#include <QJsonObject>
#include <QJsonDocument>
#include <QStandardPaths>
#include <QTest>

using namespace Qt::Literals;
using namespace KPublicTransport;

class DeutscheBahnParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
        qRegisterMetaType<Disruption::Effect>();
        QStandardPaths::setTestModeEnabled(true);
    }

    void testLocationParser_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("stations") << u"" SOURCE_DIR "/data/db-hafas/location-stations.in.json"_s << u"" SOURCE_DIR "/data/db-hafas/location-stations.out.json"_s;
        QTest::newRow("poi") << u"" SOURCE_DIR "/data/db-hafas/location-poi.in.json"_s << u"" SOURCE_DIR "/data/db-hafas/location-poi.out.json"_s;
    }

    void testLocationParser()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        HafasMgateParser p;
        p.setLocationIdentifierTypes(u"db"_s, u"ibnr"_s);

        const auto data = Test::readFile(inFileName);
        const auto result = DeutscheBahnParser::parseLocations(data, p);
        const auto resJson = KPublicTransport::Location::toJson(result);

        const auto refJson = QJsonDocument::fromJson(Test::readFile(refFileName)).array();
        QVERIFY(Test::compareJson(refFileName, resJson, refJson));
    }

    void testStopoverParser_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<bool>("isDeparture");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("departure") << u"" SOURCE_DIR "/data/db-hafas/stopover-departure.in.json"_s << true << u"" SOURCE_DIR "/data/db-hafas/stopover-departure.out.json"_s;
    }

    void testStopoverParser()
    {
        QFETCH(QString, inFileName);
        QFETCH(bool, isDeparture);
        QFETCH(QString, refFileName);

        HafasMgateParser p;
        p.setLocationIdentifierTypes(u"db"_s, u"ibnr"_s);

        const auto data = Test::readFile(inFileName);
        const auto inJson = QJsonDocument::fromJson(data).object();
        const auto result = DeutscheBahnParser::parseStopovers(inJson["entries"_L1].toArray(), isDeparture, p);
        const auto resJson = KPublicTransport::Stopover::toJson(result);

        const auto refJson = QJsonDocument::fromJson(Test::readFile(refFileName)).array();
        QVERIFY(Test::compareJson(refFileName, resJson, refJson));
    }

    void testJourneyParser_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("nowalk") << u"" SOURCE_DIR "/data/db-hafas/journey-nowalk.in.json"_s << u"" SOURCE_DIR "/data/db-hafas/journey-nowalk.out.json"_s;
        QTest::newRow("walk") << u"" SOURCE_DIR "/data/db-hafas/journey-walk.in.json"_s << u"" SOURCE_DIR "/data/db-hafas/journey-walk.out.json"_s;
        QTest::newRow("international") << u"" SOURCE_DIR "/data/db-hafas/journey-international.in.json"_s << u"" SOURCE_DIR "/data/db-hafas/journey-international.out.json"_s;
        QTest::newRow("cancelled") << u"" SOURCE_DIR "/data/db-hafas/journey-cancelled.in.json"_s << u"" SOURCE_DIR "/data/db-hafas/journey-cancelled.out.json"_s;
        QTest::newRow("extra-stop") << u"" SOURCE_DIR "/data/db-hafas/journey-transfer-extra-stop.in.json"_s << u"" SOURCE_DIR "/data/db-hafas/journey-transfer-extra-stop.out.json"_s;
    }

    void testJourneyParser()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        HafasMgateParser p;
        p.setLocationIdentifierTypes(u"db"_s, u"ibnr"_s);

        const auto data = Test::readFile(inFileName);
        const auto inJson = QJsonDocument::fromJson(data).object();
        const auto result = DeutscheBahnParser::parseJourneys(inJson["verbindungen"_L1].toArray(), p);
        const auto resJson = KPublicTransport::Journey::toJson(result);

        const auto refJson = QJsonDocument::fromJson(Test::readFile(refFileName)).array();
        QVERIFY(Test::compareJson(refFileName, resJson, refJson));
    }

    void testTripParser_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("international") << u"" SOURCE_DIR "/data/db-hafas/trip-international.in.json"_s << u"" SOURCE_DIR "/data/db-hafas/trip-international.out.json"_s;
    }

    void testTripParser()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        HafasMgateParser p;
        p.setLocationIdentifierTypes(u"db"_s, u"ibnr"_s);

        const auto data = Test::readFile(inFileName);
        const auto inJson = QJsonDocument::fromJson(data).object();
        const auto result = DeutscheBahnParser::parseTrip(inJson, p);
        const auto resJson = KPublicTransport::JourneySection::toJson(result);

        const auto refJson = QJsonDocument::fromJson(Test::readFile(refFileName)).object();
        QVERIFY(Test::compareJson(refFileName, resJson, refJson));
    }
};

QTEST_GUILESS_MAIN(DeutscheBahnParserTest)

#include "deutschebahnparsertest.moc"
