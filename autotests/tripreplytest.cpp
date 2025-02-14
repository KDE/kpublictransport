/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/TripReply>
#include <KPublicTransport/TripRequest>

#include <QJsonDocument>
#include <QJsonObject>
#include <QTest>

namespace KPublicTransport {

class TripReplyTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testTripMerge_data()
    {
        QTest::addColumn<int>("begin");
        QTest::addColumn<int>("end");

        QTest::newRow("strict-subset") << 2 << 5;
        QTest::newRow("full") << -1 << 27;
        QTest::newRow("prefix") << -1 << 8;
        QTest::newRow("suffix") << 7 << 27;
        QTest::newRow("single-step") << 3 << 4;
        QTest::newRow("single-step-prefix") << -1 << 0;
        QTest::newRow("single-step-suffix") << 26 << 27;
    }

    void testTripMerge()
    {
        QFETCH(int, begin);
        QFETCH(int, end);

        const auto fullTrip = JourneySection::fromJson(QJsonDocument::fromJson(Test::readFile(QStringLiteral(SOURCE_DIR "/data/otp/de-stadtnavi-trip.out.json"))).object());

        JourneySection partialTrip;
        partialTrip.setDeparture(begin >= 0 ? fullTrip.intermediateStops()[begin] : fullTrip.departure());
        partialTrip.setArrival(end < (int)fullTrip.intermediateStops().size() ? fullTrip.intermediateStops()[end] : fullTrip.arrival());
        partialTrip.setMode(JourneySection::PublicTransport);

        TripRequest req(partialTrip);;

        TripReply reply(req);
        reply.addResult(nullptr, JourneySection(fullTrip));

        QVERIFY(JourneySection::isSame(reply.trip(), fullTrip));
        QVERIFY(JourneySection::isSame(reply.journeySection(), partialTrip));
        QVERIFY(Route::isSame(fullTrip.route(), reply.journeySection().route()));
        QCOMPARE(reply.journeySection().intermediateStops().size(), end - begin - 1);

        QCOMPARE(reply.trip().path().sections().size(), 1);
        QCOMPARE(reply.trip().path().sections()[0].path().isEmpty(), false);
        QCOMPARE(reply.journeySection().path().sections().size(), 1);
        QCOMPARE(reply.journeySection().path().sections()[0].path().isEmpty(), false);

        const auto path = reply.journeySection().path().sections()[0].path();
        QVERIFY(std::ranges::all_of(path, [](const auto &p) { return p.x() > 0 && p.y() > 0; }));

        const auto stops = reply.journeySection().intermediateStops();
        QVERIFY(std::ranges::none_of(stops, [partialTrip](const auto &s) { return Stopover::isSame(s, partialTrip.departure()); }));
        QVERIFY(std::ranges::none_of(stops, [partialTrip](const auto &s) { return Stopover::isSame(s, partialTrip.arrival()); }));
    }
};

}

QTEST_GUILESS_MAIN(KPublicTransport::TripReplyTest)

#include "tripreplytest.moc"
