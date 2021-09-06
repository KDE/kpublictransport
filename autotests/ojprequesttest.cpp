/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backends/openjourneyplannerrequestbuilder.cpp"

#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/StopoverRequest>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class OjpRequestTest : public QObject
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
        builder.setTestMode(true);
        const auto res = builder.buildLocationInformationRequest(request);
        const auto ref = readFile(refFileName);
        if (res != ref) {
            qDebug().noquote() << res;
        }
        QVERIFY(!res.isEmpty());
        QCOMPARE(res, ref);
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
        req.setDateTime(QDateTime({2020, 9, 6}, {20, 54}, Qt::UTC));
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
        builder.setTestMode(true);
        const auto res = builder.buildStopEventRequest(request);
        const auto ref = readFile(refFileName);
        if (res != ref) {
            qDebug().noquote() << res;
        }
        QVERIFY(!res.isEmpty());
        QCOMPARE(res, ref);
    }
};

QTEST_GUILESS_MAIN(OjpRequestTest)

#include "ojprequesttest.moc"
