/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../src/lib/uic/uicstationcode.cpp"

#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class UicUtilTest: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void tesIsStationId()
    {
        QVERIFY(UicStationCode::isValid(u"8501687"));
        QVERIFY(UicStationCode::isValid(u"8501687", {80, 85}));
        QVERIFY(UicStationCode::isValid(u"008501687", {80, 85}));

        QVERIFY(!UicStationCode::isValid(u"850012A", {80, 85}));
        QVERIFY(!UicStationCode::isValid(u"8501687", {80, 81}));
        QVERIFY(!UicStationCode::isValid(u"008501687"));
        QVERIFY(!UicStationCode::isValid(u"851587"));
        QVERIFY(!UicStationCode::isValid(u"85016870"));
    }
};

QTEST_APPLESS_MAIN(UicUtilTest)

#include "uicstationcodetest.moc"
