/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/Line>
#include <KPublicTransport/StopInformation>

#include <QTest>

using namespace Qt::Literals;
using namespace KPublicTransport;

class StopInformationTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testAddLine()
    {
        Line modeOnly;
        modeOnly.setMode(Line::Metro);

        StopInformation info;
        info.addLine(modeOnly);
        QCOMPARE(info.lines().size(), 1);
        info.addLine(modeOnly);
        QCOMPARE(info.lines().size(), 1);

        Line metro;
        metro.setMode(Line::Metro);
        metro.setName(u"U2"_s);
        info.addLine(metro);
        QCOMPARE(info.lines().size(), 1);
        QCOMPARE(info.lines()[0].name(), "U2"_L1);
        info.addLine(metro);
        info.addLine(modeOnly);
        QCOMPARE(info.lines().size(), 1);
        QCOMPARE(info.lines()[0].name(), "U2"_L1);

        metro.setName(u"U1"_s);
        info.addLine(metro);
        info.addLine(metro);
        info.addLine(modeOnly);
        QCOMPARE(info.lines().size(), 2);
        QCOMPARE(info.lines()[0].name(), "U1"_L1);

        modeOnly.setMode(Line::RapidTransit);
        info.addLine(modeOnly);
        info.addLine(modeOnly);
        info.addLine(metro);
        QCOMPARE(info.lines().size(), 3);
    }
};

QTEST_GUILESS_MAIN(StopInformationTest)

#include "stopinformationtest.moc"
