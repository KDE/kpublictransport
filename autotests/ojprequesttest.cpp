/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"
#include "backends/openjourneyplannerrequestbuilder.cpp"

#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/StopoverRequest>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class OjpRequestTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testLocationRequest_data()
    {
        QTest::addColumn<LocationRequest>("request");
        QTest::addColumn<QString>("refFileName");

        Location loc;
        loc.setCoordinate(46.1, 7.78);
        LocationRequest req;
        req.setLocation(loc);
        req.setMaximumDistance(500);
        req.setMaximumResults(23);
        QTest::newRow("location-by-coord") << req << s(SOURCE_DIR "/data/ojp-request/location-by-coord.xml");

        loc = {};
        loc.setName(s("Randa"));
        req.setLocation(loc);
        QTest::newRow("location-by-name") << req << s(SOURCE_DIR "/data/ojp-request/location-by-name.xml");
    }

    void testLocationRequest()
    {
        QFETCH(LocationRequest, request);
        QFETCH(QString, refFileName);

        OpenJourneyPlannerRequestBuilder builder;
        builder.setRequestorRef(QStringLiteral("KPublicTransport"));
        builder.setTestMode(true);

        auto res = builder.buildLocationInformationRequest(request);
        auto ref = Test::readFile(refFileName);
        QVERIFY(Test::compareXml(refFileName, res, ref));

        const auto ojp2FileName = QString(refFileName).insert(refFileName.size() -4, u"-ojp2");
        builder.setProtocol(OpenJourneyPlannerRequestBuilder::OJP2);
        res = builder.buildLocationInformationRequest(request);
        ref = Test::readFile(ojp2FileName);
        QVERIFY(Test::compareXml(ojp2FileName, res, ref));

        const auto triasFileName = QString(refFileName).insert(refFileName.size() -4, u"-trias");
        builder.setProtocol(OpenJourneyPlannerRequestBuilder::TRIAS);
        res = builder.buildLocationInformationRequest(request);
        ref = Test::readFile(triasFileName);
        QVERIFY(Test::compareXml(triasFileName, res, ref));
    }

    void testStopoverRequest_data()
    {
        QTest::addColumn<StopoverRequest>("request");
        QTest::addColumn<QString>("refFileName");

        Location loc;
        loc.setIdentifier(QStringLiteral("uic"), QStringLiteral("8501687"));
        StopoverRequest req;
        req.setStop(loc);
        req.setMode(StopoverRequest::QueryDeparture);
        req.setDateTime(QDateTime({2020, 9, 6}, {20, 54}, QTimeZone::UTC));
        req.setMaximumResults(4);
        QTest::newRow("stopover-departure") << req << s(SOURCE_DIR "/data/ojp-request/stopover-departure.xml");
        req.setMode(StopoverRequest::QueryArrival);
        QTest::newRow("stopover-arrival") << req << s(SOURCE_DIR "/data/ojp-request/stopover-arrival.xml");
    }

    void testStopoverRequest()
    {
        QFETCH(StopoverRequest, request);
        QFETCH(QString, refFileName);

        OpenJourneyPlannerRequestBuilder builder;
        builder.setRequestorRef(QStringLiteral("KPublicTransport"));
        builder.setTestMode(true);
        auto res = builder.buildStopEventRequest(request);
        auto ref = Test::readFile(refFileName);
        QVERIFY(Test::compareXml(refFileName, res, ref));

        builder.setProtocol(OpenJourneyPlannerRequestBuilder::TRIAS);

        const auto ojp2FileName = QString(refFileName).insert(refFileName.size() -4, u"-ojp2");
        builder.setProtocol(OpenJourneyPlannerRequestBuilder::OJP2);
        res = builder.buildStopEventRequest(request);
        ref = Test::readFile(ojp2FileName);
        QVERIFY(Test::compareXml(ojp2FileName, res, ref));

        const auto triasFileName = QString(refFileName).insert(refFileName.size() -4, u"-trias");
        builder.setProtocol(OpenJourneyPlannerRequestBuilder::TRIAS);
        res = builder.buildStopEventRequest(request);
        refFileName = refFileName.insert(refFileName.size() -4, u"-trias");
        ref = Test::readFile(refFileName);
        QVERIFY(Test::compareXml(refFileName, res, ref));
    }

    void testJourneyRequest_data()
    {
        QTest::addColumn<JourneyRequest>("request");
        QTest::addColumn<QString>("refFileName");

        Location from;
        from.setCoordinate(46.1, 7.78);
        Location to;
        to.setIdentifier(QStringLiteral("uic"), QStringLiteral("8500010"));
        JourneyRequest req;
        req.setFrom(from);
        req.setTo(to);
        req.setDateTime(QDateTime({2020, 9, 6}, {20, 54}, QTimeZone::UTC));
        req.setDateTimeMode(JourneyRequest::Departure);
        req.setMaximumResults(3);
        req.setIncludeIntermediateStops(true);
        req.setIncludePaths(false);
        QTest::newRow("journey-departure") << req << s(SOURCE_DIR "/data/ojp-request/journey-departure.xml");
        from.setName(QStringLiteral("Randa"));
        req.setFrom(from);
        req.setIncludeIntermediateStops(false);
        req.setIncludePaths(true);
        req.setDateTimeMode(JourneyRequest::Arrival);
        QTest::newRow("journey-arrival") << req << s(SOURCE_DIR "/data/ojp-request/journey-arrival.xml");
    }

    void testJourneyRequest()
    {
        QFETCH(JourneyRequest, request);
        QFETCH(QString, refFileName);

        OpenJourneyPlannerRequestBuilder builder;
        builder.setRequestorRef(QStringLiteral("KPublicTransport"));
        builder.setTestMode(true);
        auto res = builder.buildTripRequest(request);
        auto ref = Test::readFile(refFileName);
        QVERIFY(Test::compareXml(refFileName, res, ref));

        const auto ojp2FileName = QString(refFileName).insert(refFileName.size() -4, u"-ojp2");
        builder.setProtocol(OpenJourneyPlannerRequestBuilder::OJP2);
        res = builder.buildTripRequest(request);
        ref = Test::readFile(ojp2FileName);
        QVERIFY(Test::compareXml(ojp2FileName, res, ref));

        const auto triasFileName = QString(refFileName).insert(refFileName.size() -4, u"-trias");
        builder.setProtocol(OpenJourneyPlannerRequestBuilder::TRIAS);
        res = builder.buildTripRequest(request);
        refFileName = refFileName.insert(refFileName.size() -4, u"-trias");
        ref = Test::readFile(refFileName);
        QVERIFY(Test::compareXml(refFileName, res, ref));
    }
};

QTEST_GUILESS_MAIN(OjpRequestTest)

#include "ojprequesttest.moc"
