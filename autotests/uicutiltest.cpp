/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../src/lib/uic/uicutil.cpp"

#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class UicUtilTest: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void tesIsStationId()
    {
        QVERIFY(UicUtil::isStationId(u"8501687"));
        QVERIFY(UicUtil::isStationId(u"8501687", {80, 85}));
        QVERIFY(UicUtil::isStationId(u"008501687", {80, 85}));

        QVERIFY(!UicUtil::isStationId(u"850012A", {80, 85}));
        QVERIFY(!UicUtil::isStationId(u"8501687", {80, 81}));
        QVERIFY(!UicUtil::isStationId(u"008501687"));
        QVERIFY(!UicUtil::isStationId(u"851587"));
        QVERIFY(!UicUtil::isStationId(u"85016870"));
    }
};

QTEST_APPLESS_MAIN(UicUtilTest)

#include "uicutiltest.moc"
