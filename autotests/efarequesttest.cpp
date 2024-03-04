/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mocknetworkaccessmanager.h"

#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Manager>
#include <KPublicTransport/Location>
#include <KPublicTransport/StopoverReply>
#include <KPublicTransport/StopoverRequest>

#include <QFile>
#include <QSignalSpy>
#include <QTest>
#include <QUrlQuery>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class EfaRequestTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
        QLocale::setDefault(QLocale(u"en_US.utf-8"));

        m_mgr.setNetworkAccessManager(&m_nam);
    }

    void testStopoverRequest_data()
    {
        QTest::addColumn<StopoverRequest>("request");
        QTest::addColumn<QUrl>("requestUrl");

        StopoverRequest req;
        req.setBackendIds({s("de_bw_vvs")});
        Location stop;
        stop.setIdentifier(QLatin1String("de_bw_vvs"), QLatin1String("12345"));
        req.setStop(stop);
        req.setDateTime(QDateTime({2023, 6, 25}, {9, 39}, QTimeZone::UTC));
        QTest::newRow("id-based-default") << req << QUrl(s("https://www2.vvs.de/vvs/XML_DM_REQUEST?outputFormat=XML&coordOutputFormat=WGS84[DD.ddddd]&language=en&type_dm=stop&name_dm=12345&itdDate=20230625&itdTime=0939&useRealtime=1&limit=12&mode=direct&ptOptionsActive=1&merge_dep=1&stateless=1&sessionID=0&requestID=0"));

        stop = {};
        stop.setCoordinate(48.78, 9.18);
        req.setStop(stop);
        req.setMaximumResults(3);
        QTest::newRow("coordinate-based") << req << QUrl(s("https://www2.vvs.de/vvs/XML_DM_REQUEST?outputFormat=XML&coordOutputFormat=WGS84[DD.ddddd]&language=en&type_dm=coord&name_dm=9.18:48.78:WGS84[DD.ddddd]&itdDate=20230625&itdTime=0939&useRealtime=1&limit=3&mode=direct&ptOptionsActive=1&merge_dep=1&stateless=1&sessionID=0&requestID=0"));

        // not supported, so no impact
        req.setLineModes({Line::LocalTrain, Line::RapidTransit, Line::Metro});
        QTest::newRow("line-mode-constraints") << req << QUrl(s("https://www2.vvs.de/vvs/XML_DM_REQUEST?outputFormat=XML&coordOutputFormat=WGS84[DD.ddddd]&language=en&type_dm=coord&name_dm=9.18:48.78:WGS84[DD.ddddd]&itdDate=20230625&itdTime=0939&useRealtime=1&limit=3&mode=direct&ptOptionsActive=1&merge_dep=1&stateless=1&sessionID=0&requestID=0"));
    }

    void testStopoverRequest()
    {
        QFETCH(StopoverRequest, request);
        QFETCH(QUrl, requestUrl);

        m_nam.requests.clear();
        QVERIFY(request.isValid());

        auto reply = m_mgr.queryStopover(request);
        QSignalSpy finishedSpy(reply, &Reply::finished);
        QVERIFY(finishedSpy.wait());
        reply->deleteLater();
        QCOMPARE(reply->error(), Reply::NetworkError);
        QCOMPARE(m_nam.requests.size(), 1);
        QCOMPARE(m_nam.requests[0].op, QNetworkAccessManager::GetOperation);

        const auto url = m_nam.requests[0].request.url();
        QCOMPARE(url, requestUrl);
    }

    void testJourneyRequest_data()
    {
        QTest::addColumn<JourneyRequest>("request");
        QTest::addColumn<QUrl>("requestUrl");

        JourneyRequest req;
        req.setBackendIds({s("de_bw_vvs")});
        Location from;
        from.setIdentifier(QLatin1String("de_bw_vvs"), QLatin1String("12345"));
        Location to;
        to.setIdentifier(QLatin1String("de_bw_vvs"), QLatin1String("23456"));
        req.setFrom(from);
        req.setTo(to);
        req.setDateTime(QDateTime({2023, 6, 24}, {20, 58}, QTimeZone::UTC));
        QTest::newRow("id-based-default") << req << QUrl(s("https://www2.vvs.de/vvs/XML_TRIP_REQUEST2?outputFormat=XML&coordOutputFormat=WGS84[DD.ddddd]&language=en&locationServerActive=1&useRealtime=1&type_origin=stop&name_origin=12345&type_destination=stop&name_destination=23456&itdDate=20230624&itdTime=2058&itdTripDateTimeDepArr=dep&itOptionsActive=1&trITDepMOT=100&trITArrMOT=100&calcNumberOfTrips=12&calcCO2=1&coordListOutputFormat=STRING&stateless=1&sessionID=0&requestID=0"));

        from = {};
        from.setCoordinate(48.78, 9.18);
        to = {};
        to.setCoordinate(48.59, 8.86);
        req.setFrom(from);
        req.setTo(to);
        QTest::newRow("coordinate-based-default") << req << QUrl(s("https://www2.vvs.de/vvs/XML_TRIP_REQUEST2?outputFormat=XML&coordOutputFormat=WGS84[DD.ddddd]&language=en&locationServerActive=1&useRealtime=1&type_origin=coord&name_origin=9.18:48.78:WGS84[DD.ddddd]&type_destination=coord&name_destination=8.86:48.59:WGS84[DD.ddddd]&itdDate=20230624&itdTime=2058&itdTripDateTimeDepArr=dep&itOptionsActive=1&trITDepMOT=100&trITArrMOT=100&calcNumberOfTrips=12&calcCO2=1&coordListOutputFormat=STRING&stateless=1&sessionID=0&requestID=0"));

        req.setMaximumResults(4);
        req.setIncludeIntermediateStops(false);
        req.setIncludePaths(true);
        req.setDateTimeMode(JourneyRequest::Arrival);
        req.setAccessModes({ IndividualTransport::Walk, IndividualTransport::Bike });
        req.setEgressModes({ IndividualTransport::Walk, IndividualTransport::Bike });
        QTest::newRow("arrival-with-access-mode") << req << QUrl(s("https://www2.vvs.de/vvs/XML_TRIP_REQUEST2?outputFormat=XML&coordOutputFormat=WGS84[DD.ddddd]&language=en&locationServerActive=1&useRealtime=1&type_origin=coord&name_origin=9.18:48.78:WGS84[DD.ddddd]&type_destination=coord&name_destination=8.86:48.59:WGS84[DD.ddddd]&itdDate=20230624&itdTime=2058&itdTripDateTimeDepArr=arr&itOptionsActive=1&trITDepMOT=100&trITArrMOT=100&calcNumberOfTrips=4&calcCO2=1&coordListOutputFormat=STRING&stateless=1&sessionID=0&requestID=0"));

        req.setLineModes({Line::Bus, Line::Ferry});
        QTest::newRow("line-mode-constraints") << req << QUrl(s("https://www2.vvs.de/vvs/XML_TRIP_REQUEST2?outputFormat=XML&coordOutputFormat=WGS84[DD.ddddd]&language=en&locationServerActive=1&useRealtime=1&type_origin=coord&name_origin=9.18:48.78:WGS84[DD.ddddd]&type_destination=coord&name_destination=8.86:48.59:WGS84[DD.ddddd]&itdDate=20230624&itdTime=2058&itdTripDateTimeDepArr=arr&inclMOT_5=on&inclMOT_6=on&inclMOT_17=on&inclMOT_19=on&inclMOT_9=on&itOptionsActive=1&trITDepMOT=100&trITArrMOT=100&calcNumberOfTrips=4&calcCO2=1&coordListOutputFormat=STRING&stateless=1&sessionID=0&requestID=0"));
    }

    void testJourneyRequest()
    {
        QFETCH(JourneyRequest, request);
        QFETCH(QUrl, requestUrl);

        m_nam.requests.clear();
        QVERIFY(request.isValid());

        auto reply = m_mgr.queryJourney(request);
        QSignalSpy finishedSpy(reply, &Reply::finished);
        QVERIFY(finishedSpy.wait());
        reply->deleteLater();
        QCOMPARE(reply->error(), Reply::NetworkError);
        QCOMPARE(m_nam.requests.size(), 1);
        QCOMPARE(m_nam.requests[0].op, QNetworkAccessManager::GetOperation);

        const auto url = m_nam.requests[0].request.url();
        QCOMPARE(url, requestUrl);
    }

private:
    MockNetworkAccessManager m_nam;
    Manager m_mgr;
};

QTEST_GUILESS_MAIN(EfaRequestTest)

#include "efarequesttest.moc"
