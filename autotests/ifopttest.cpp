/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../src/lib/ifopt/ifoptutil.cpp"

#include <QJsonDocument>
#include <QJsonObject>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class IfoptTest: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testIsValid_data()
    {
        QTest::addColumn<QString>("ifopt");
        QTest::addColumn<bool>("valid");

        QTest::newRow("empty") << QString() << false;
        QTest::newRow("quay") << s("de:08115:4512:5:B") << true;
        QTest::newRow("prefix") << s("hbg:de:08115:4512:2:1") << false;
        QTest::newRow("level") << s("de:08115:4512:1") << true;
        QTest::newRow("stop_place") << s("de:05315:11201") << true;
        QTest::newRow("admin_area") << s("de:05111") << false;
        QTest::newRow("country") << s("de") << false;

        QTest::newRow("colons") << s("::::") << false;
        QTest::newRow("missing element") << s("de:08115::5:B") << false;
        QTest::newRow("missing country") << s(":05111:18995:2:2") << false;
        QTest::newRow("trailing colon") << s("de:05315:11201:") << false;
        QTest::newRow("too many elements") << s("de:08115:4512:2:1:42") << false;
    }

    void testIsValid()
    {
        QFETCH(QString, ifopt);
        QFETCH(bool, valid);
        QCOMPARE(IfoptUtil::isValid(ifopt), valid);
    }
};

QTEST_APPLESS_MAIN(IfoptTest)

#include "ifopttest.moc"
