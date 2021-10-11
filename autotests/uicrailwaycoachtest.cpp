/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../src/lib/uic/uicrailwaycoach.cpp"

#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class UicRailwayCoachTest: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testClasses()
    {
        QCOMPARE(UicRailwayCoach::coachClass(QString(), QString()), VehicleSection::UnknownClass);
        QCOMPARE(UicRailwayCoach::coachClass(u"738029947087", u"Bpmbz"), VehicleSection::SecondClass);
        QCOMPARE(UicRailwayCoach::coachClass(u"738029947087", QString()), VehicleSection::SecondClass);
        QCOMPARE(UicRailwayCoach::coachClass(QString(), u"Afmpz"), VehicleSection::FirstClass);
        QCOMPARE(UicRailwayCoach::coachClass(QString(), u"WRmz"), VehicleSection::UnknownClass);
        QCOMPARE(UicRailwayCoach::coachClass(QString(), u"DABpza"), VehicleSection::SecondClass | VehicleSection::FirstClass);
    }

    void testDeckCount()
    {
        QCOMPARE(UicRailwayCoach::deckCount(QString(), QString()), 1);
        QCOMPARE(UicRailwayCoach::deckCount(u"738029947087", u"Bpmbz"), 1);
        QCOMPARE(UicRailwayCoach::deckCount(u"738029947087", QString()), 1);
        QCOMPARE(UicRailwayCoach::deckCount(QString(), u"Afmpz"), 1);
        QCOMPARE(UicRailwayCoach::deckCount(QString(), u"DABpza"), 2);
    }

    void testFeatures()
    {
        QCOMPARE(UicRailwayCoach::features(QString(), QString()), VehicleSection::NoFeatures);
        QCOMPARE(UicRailwayCoach::features(u"738029947087", u"Bpmbz"), VehicleSection::AirConditioning | VehicleSection::WheelchairAccessible);
        QCOMPARE(UicRailwayCoach::features(u"738029947087", QString()), VehicleSection::AirConditioning);
        QCOMPARE(UicRailwayCoach::features(u"738180907342", u"Afmpz"), VehicleSection::AirConditioning);
        QCOMPARE(UicRailwayCoach::features(QString(), u"WRmz"), VehicleSection::Restaurant);
        QCOMPARE(UicRailwayCoach::features(u"938054112686", u"WRmz"), VehicleSection::Restaurant);
        QCOMPARE(UicRailwayCoach::features(u"508086818566", u"DBpbzfa"), VehicleSection::WheelchairAccessible | VehicleSection::AirConditioning);
        QCOMPARE(UicRailwayCoach::features(u"738185905341", u"ARbmpz"), VehicleSection::Restaurant | VehicleSection::WheelchairAccessible | VehicleSection::AirConditioning);
        QCOMPARE(UicRailwayCoach::features(u"508086818566", QString()), VehicleSection::NoFeatures);
        QCOMPARE(UicRailwayCoach::features(u"918061465699", u"E1465"), VehicleSection::NoFeatures);
    }

    void testType()
    {
        QCOMPARE(UicRailwayCoach::type(QString(), QString()), VehicleSection::UnknownType);
        QCOMPARE(UicRailwayCoach::type(u"738029947087", u"Bpmbz"), VehicleSection::PassengerCar);
        QCOMPARE(UicRailwayCoach::type(u"738029947087", QString()), VehicleSection::PassengerCar);
        QCOMPARE(UicRailwayCoach::type(u"738180907342", u"Afmpz"), VehicleSection::ControlCar);
        QCOMPARE(UicRailwayCoach::type(QString(), u"WRmz"), VehicleSection::RestaurantCar);
        QCOMPARE(UicRailwayCoach::type(u"938054112686", u"WRmz"), VehicleSection::RestaurantCar);
        QCOMPARE(UicRailwayCoach::type(u"508086818566", u"DBpbzfa"), VehicleSection::ControlCar);
        QCOMPARE(UicRailwayCoach::type(u"738185905341", u"ARbmpz"), VehicleSection::PassengerCar);
        QCOMPARE(UicRailwayCoach::type(u"918111162346", u"TZF"), VehicleSection::Engine);
        QCOMPARE(UicRailwayCoach::type(u"918061465699", u"E1465"), VehicleSection::Engine);
        QEXPECT_FAIL("", "not detectable?", Continue);
        QCOMPARE(UicRailwayCoach::type(u"938054020061", u"I4020"), VehicleSection::PowerCar);
        QCOMPARE(UicRailwayCoach::type(u"938058080061", u"Bpmzf"), VehicleSection::ControlCar);
    }
};

QTEST_APPLESS_MAIN(UicRailwayCoachTest)

#include "uicrailwaycoachtest.moc"
