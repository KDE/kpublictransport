/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <siri/duration.cpp>
#include <siri/mode.h>

#include <QTest>

using namespace Qt::Literals;
using namespace KPublicTransport;

class SiriTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testDuration_data()
    {
        QTest::addColumn<QString>("duration");
        QTest::addColumn<int>("seconds");

        QTest::newRow("empty") << QString() << 0;
        QTest::newRow("min-only-1") << u"PT4M"_s << 4*60;
        QTest::newRow("min-only-2") << u"PT45M"_s << 45*60;
        QTest::newRow("time-full") << u"PT3H14M30S"_s << 11670;

        QTest::newRow("no-P") << u"4M"_s << 0;
        QTest::newRow("no-unit") << u"PT4"_s << 0;
    }

    void testDuration()
    {
        QFETCH(QString, duration);
        QFETCH(int, seconds);
        QCOMPARE(Siri::fromDuration(duration), std::chrono::seconds(seconds));
    }

    void testMode()
    {
        QCOMPARE(Siri::Mode::fromString(u"rail", {}).toMode(), Line::Train);
        QCOMPARE(Siri::Mode::fromString(u"rail", u"highSpeedRail").toMode(), Line::LongDistanceTrain);
        QCOMPARE(Siri::Mode::fromString({}, u"local").toMode(), Line::LocalTrain);
        QCOMPARE(Siri::Mode::fromString({}, u"localBus").toMode(), Line::Bus);
        QCOMPARE(Siri::Mode::fromString(u"foo", u"bar").toMode(), Line::Unknown);
        QCOMPARE(Siri::Mode::fromString(u"metro", u"newMetroServer").toMode(), Line::Metro);

        QCOMPARE(Siri::Mode::toString(Siri::Mode::VehicleMode::bus), "bus");
        QCOMPARE(Siri::Mode::toString(Siri::Mode::CoachSubmode::internationalCoach), "internationalCoach");

        auto m = Siri::Mode::fromMode(Line::Tramway);
        QCOMPARE(m.size(), 1);
        QCOMPARE(m[0].mode(), Siri::Mode::VehicleMode::tram);
        QVERIFY(!m[0].hasSubmode());

        m = Siri::Mode::fromMode(Line::Bus);
        QCOMPARE(m.size(), 2);
        QCOMPARE(m[0].mode(), Siri::Mode::VehicleMode::bus);
        QCOMPARE(m[1].mode(), Siri::Mode::VehicleMode::trolleybus);

        m = Siri::Mode::fromMode(Line::LongDistanceTrain);
        QCOMPARE(m.size(), 5);
        QCOMPARE(m[0].mode(), Siri::Mode::VehicleMode::rail);
        QCOMPARE(m[0].hasSubmode(), true);
        QCOMPARE(std::get<Siri::Mode::RailSubmode>(*m[0].submode()), Siri::Mode::RailSubmode::highSpeedRail);
        QCOMPARE(m[1].mode(), Siri::Mode::VehicleMode::rail);
        QCOMPARE(std::get<Siri::Mode::RailSubmode>(*m[1].submode()), Siri::Mode::RailSubmode::longDistance);
        QCOMPARE(m[1].hasSubmode(), true);

        const Siri::Mode hsr{Siri::Mode::VehicleMode::rail, Siri::Mode::RailSubmode::highSpeedRail};
        const Siri::Mode ldr{Siri::Mode::VehicleMode::rail, Siri::Mode::RailSubmode::longDistance};
        QCOMPARE_EQ(hsr, hsr);
        QCOMPARE_LT(hsr, ldr);
        QCOMPARE_GT(ldr, hsr);
        QCOMPARE_NE(ldr, hsr);
        const Siri::Mode rm{Siri::Mode::VehicleMode::rail};
        QCOMPARE_NE(rm, hsr);
        QCOMPARE_LT(rm, hsr);

        auto modes = Siri::Mode::fromModes({Line::LongDistanceTrain, Line::LocalTrain, Line::Train});
        QCOMPARE(modes.size(), 2);
        QCOMPARE(modes[0].mode(), Siri::Mode::VehicleMode::rail);
        QCOMPARE(modes[0].hasSubmode(), false);
        QCOMPARE(modes[1].mode(), Siri::Mode::VehicleMode::monorail);
        QCOMPARE(modes[1].hasSubmode(), false);

        auto modes1 = Siri::Mode::fromModes({Line::LongDistanceTrain, Line::LocalTrain});
        auto modes2 = Siri::Mode::fromModes({Line::LocalTrain});
        QCOMPARE(modes2.size(), 2); // local, regional
        modes = Siri::Mode::intersection(modes1, modes2);
        QCOMPARE(modes.size(), 2);
        QCOMPARE(modes[0].hasSubmode(), true);
        QCOMPARE(std::get<Siri::Mode::RailSubmode>(*modes[0].submode()), Siri::Mode::RailSubmode::local);
        auto modesReverse = Siri::Mode::intersection(modes2, modes1);
        QCOMPARE(modes, modesReverse);

        modes1 = {Siri::Mode(Siri::Mode::VehicleMode::rail)};
        modes2 = {Siri::Mode(Siri::Mode::VehicleMode::rail, Siri::Mode::RailSubmode::local)};
        modes = Siri::Mode::intersection(modes1, modes2);
        QCOMPARE(modes.size(), 1);
        QCOMPARE(modes[0].hasSubmode(), true);
        QCOMPARE(std::get<Siri::Mode::RailSubmode>(*modes[0].submode()), Siri::Mode::RailSubmode::local);
    }
};

QTEST_APPLESS_MAIN(SiriTest)

#include "siritest.moc"
