/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mocknetworkaccessmanager.h"

#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Manager>
#include <KPublicTransport/Location>

#include <QFile>
#include <QSignalSpy>
#include <QTest>
#include <QUrlQuery>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class HafasMgateRequestTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
        qputenv("LANG", "en_US");

        m_mgr.setNetworkAccessManager(&m_nam);
    }

    void testJourneyRequest_data()
    {
        QTest::addColumn<JourneyRequest>("request");
        QTest::addColumn<QUrl>("requestUrl");
        QTest::addColumn<QByteArray>("postData");

        JourneyRequest req;
        req.setBackendIds({s("de_db")});
        Location from;
        from.setIdentifier(QLatin1String("ibnr"), QLatin1String("8012345"));
        Location to;
        to.setIdentifier(QLatin1String("ibnr"), QLatin1String("8023456"));
        req.setFrom(from);
        req.setTo(to);
        req.setDateTime(QDateTime({2023, 6, 24}, {20, 58}, Qt::UTC));
        QTest::newRow("id-based-default") << req << QUrl(s("https://reiseauskunft.bahn.de/bin/mgate.exe"))
            << QByteArray(R"({"auth":{"aid":"n91dB8Z77MLdoR0K","type":"AID"},"client":{"id":"DB","name":"DB Navigator","type":"AND","v":19040000},"ext":"DB.R20.12.b","formatted":false,"lang":"en","svcReqL":[{"cfg":{"polyEnc":"GPA"},"meth":"TripSearch","req":{"arrLocL":[{"extId":"8023456","type":"S"}],"depLocL":[{"extId":"8012345","type":"S"}],"extChgTime":-1,"getEco":false,"getIST":false,"getPasslist":true,"getPolyline":false,"getSimpleTrainComposition":true,"getTrainComposition":true,"numF":12,"outDate":"20230624","outFrwd":true,"outTime":"225800"}}],"ver":"1.18"})");

        from = {};
        from.setCoordinate(52, 13);
        to = {};
        to.setCoordinate(48, 12);
        req.setFrom(from);
        req.setTo(to);
        QTest::newRow("coordinate-based-default") << req << QUrl(s("https://reiseauskunft.bahn.de/bin/mgate.exe"))
            << QByteArray(R"({"auth":{"aid":"n91dB8Z77MLdoR0K","type":"AID"},"client":{"id":"DB","name":"DB Navigator","type":"AND","v":19040000},"ext":"DB.R20.12.b","formatted":false,"lang":"en","svcReqL":[{"cfg":{"polyEnc":"GPA"},"meth":"TripSearch","req":{"arrLocL":[{"crd":{"x":12000000,"y":48000000},"type":"C"}],"depLocL":[{"crd":{"x":13000000,"y":52000000},"type":"C"}],"extChgTime":-1,"getEco":false,"getIST":false,"getPasslist":true,"getPolyline":false,"getSimpleTrainComposition":true,"getTrainComposition":true,"numF":12,"outDate":"20230624","outFrwd":true,"outTime":"225800"}}],"ver":"1.18"})");

        req.setBackendIds({s("de_be_bvg")});
        req.setMaximumResults(4);
        req.setIncludeIntermediateStops(false);
        req.setIncludePaths(true);
        req.setDateTimeMode(JourneyRequest::Arrival);
        req.setAccessModes({ IndividualTransport::Walk, IndividualTransport::Bike });
        req.setEgressModes({ IndividualTransport::Walk, IndividualTransport::Bike });
        QTest::newRow("arrival-with-access-mode") << req << QUrl(s("https://bvg-apps.hafas.de/bin/mgate.exe"))
            << QByteArray(R"({"auth":{"aid":"YoJ05NartnanEGCj","type":"AID"},"client":{"id":"BVG","type":"AND"},"ext":"BVG.1","formatted":false,"lang":"en","svcReqL":[{"cfg":{"polyEnc":"GPA"},"meth":"TripSearch","req":{"arrLocL":[{"crd":{"x":12000000,"y":48000000},"type":"C"}],"depLocL":[{"crd":{"x":13000000,"y":52000000},"type":"C"}],"extChgTime":-1,"getEco":false,"getIST":false,"getPasslist":false,"getPolyline":true,"getSimpleTrainComposition":true,"getTrainComposition":true,"jnyFltrL":[{"mode":"INC","type":"GROUP","value":"BIKE_OEV_BIKE"}],"numF":4,"outDate":"20230624","outFrwd":false,"outTime":"225800"}}],"ver":"1.44"})");
    }

    void testJourneyRequest()
    {
        QFETCH(JourneyRequest, request);
        QFETCH(QUrl, requestUrl);
        QFETCH(QByteArray, postData);

        m_nam.requests.clear();
        QVERIFY(request.isValid());

        auto reply = m_mgr.queryJourney(request);
        QSignalSpy finishedSpy(reply, &Reply::finished);
        QVERIFY(finishedSpy.wait());
        reply->deleteLater();
        QCOMPARE(reply->error(), Reply::NetworkError);
        QCOMPARE(m_nam.requests.size(), 1);
        QCOMPARE(m_nam.requests[0].op, QNetworkAccessManager::PostOperation);

        auto url = m_nam.requests[0].request.url();
        QVERIFY(url.isValid());
        QUrlQuery query(url);
        query.removeQueryItem(QLatin1String("checksum"));
        url.setQuery(query);
        QCOMPARE(url, requestUrl);
        qDebug().noquote() << m_nam.requests[0].data;
        QCOMPARE(m_nam.requests[0].data, postData);
    }

private:
    MockNetworkAccessManager m_nam;
    Manager m_mgr;
};

QTEST_GUILESS_MAIN(HafasMgateRequestTest)

#include "hafasmgaterequesttest.moc"
