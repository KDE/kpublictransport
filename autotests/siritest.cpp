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
        QCOMPARE(Siri::Mode::fromString(u"rail", {}), Line::Train);
        QCOMPARE(Siri::Mode::fromString(u"rail", u"highSpeedRail"), Line::LongDistanceTrain);
        QCOMPARE(Siri::Mode::fromString({}, u"local"), Line::LocalTrain);
        QCOMPARE(Siri::Mode::fromString({}, u"localBus"), Line::Bus);
        QCOMPARE(Siri::Mode::fromString(u"foo", u"bar"), Line::Unknown);
        QCOMPARE(Siri::Mode::fromString(u"metro", u"newMetroServer"), Line::Metro);

        QCOMPARE(Siri::Mode::toString(Siri::Mode::VehicleMode::bus), "bus");
        QCOMPARE(Siri::Mode::toString(Siri::Mode::CoachSubmode::internationalCoach), "internationalCoach");
    }
};

QTEST_APPLESS_MAIN(SiriTest)

#include "siritest.moc"
