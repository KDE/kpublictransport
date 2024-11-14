/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Backend>
#include <KPublicTransport/Manager>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/Location>
#include <KPublicTransport/StopoverReply>
#include <KPublicTransport/StopoverRequest>
#include <KPublicTransport/VehicleLayoutRequest>
#include <KPublicTransport/VehicleLayoutReply>

#include <QSignalSpy>
#include <QTest>

using namespace KPublicTransport;

class PublicTransportManagerTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testQueryLocation()
    {
        Manager mgr;
        auto reply = mgr.queryLocation({});
        QVERIFY(reply);
        QSignalSpy spy(reply, &Reply::finished);
        QVERIFY(spy.wait(100));
        QCOMPARE(spy.size(), 1);
        QCOMPARE(reply->error(), Reply::InvalidRequest);
        delete reply;
    }

    void testInvalidQueryJourney_data()
    {
        QTest::addColumn<JourneyRequest>("request");
        QTest::newRow("empty") << JourneyRequest();

        Location loc;
        loc.setCoordinate(52.0, 13.0);
        JourneyRequest req;
        req.setFrom(loc);
        QTest::newRow("only from") << req;

        req.setFrom({});
        req.setTo(loc);
        QTest::newRow("only to") << req;
    }

    void testInvalidQueryJourney()
    {
        QFETCH(JourneyRequest, request);
        Manager mgr;
        auto reply = mgr.queryJourney(request);
        QVERIFY(reply);
        QSignalSpy spy(reply, &Reply::finished);
        QVERIFY(spy.wait(100));
        QCOMPARE(spy.size(), 1);
        QCOMPARE(reply->error(), Reply::InvalidRequest);
        delete reply;
    }

    void testQueryDepartures()
    {
        Manager mgr;
        auto reply = mgr.queryStopover({});
        QVERIFY(reply);
        QSignalSpy spy(reply, &Reply::finished);
        QVERIFY(spy.wait(100));
        QCOMPARE(spy.size(), 1);
        QCOMPARE(reply->error(), Reply::InvalidRequest);
        delete reply;
    }

    void testAttributions()
    {
        Manager mgr;
        QVERIFY(mgr.attributions().size() > 0);
    }

    void testInvalidVehicleLayoutQuery()
    {
        Manager mgr;
        auto reply = mgr.queryVehicleLayout(VehicleLayoutRequest());
        QVERIFY(reply);
        QSignalSpy spy(reply, &Reply::finished);
        QVERIFY(spy.wait(100));
        QCOMPARE(spy.size(), 1);
        QCOMPARE(reply->error(), Reply::InvalidRequest);
        delete reply;
    }

    void testReload()
    {
        Manager mgr;
        const auto backends = mgr.backends();
        const auto attributions = mgr.attributions();
        QVERIFY(!backends.empty());
        QVERIFY(!attributions.empty());

        mgr.reload();
        QCOMPARE(mgr.backends().size(), backends.size());
        QCOMPARE(mgr.attributions().size(), attributions.size());
    }
};

QTEST_GUILESS_MAIN(PublicTransportManagerTest)

#include "publictransportmanagertest.moc"
