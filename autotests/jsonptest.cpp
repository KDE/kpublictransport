/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../src/lib/json/jsonp_p.h"

#include <QObject>
#include <QTest>

using namespace KPublicTransport;

class JsonPTest: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testDecode_data()
    {
        QTest::addColumn<QByteArray>("in");
        QTest::addColumn<QByteArray>("out");

        QTest::newRow("empty") << QByteArray() << QByteArray();
        QTest::newRow("minimal-wrapped-object") << QByteArray("({});") << QByteArray("{}");
        QTest::newRow("wrapped-object") << QByteArray("parseJson({\"content\":{}, \"array\":[]});") << QByteArray("{\"content\":{}, \"array\":[]}");
        QTest::newRow("minimal-wrapped-array") << QByteArray("([]);") << QByteArray("[]");
        QTest::newRow("wrapped-array") << QByteArray("parseJson([{\"content\":{}, \"array\":[]}]);") << QByteArray("[{\"content\":{}, \"array\":[]}]");
        QTest::newRow("unwrapped-object") << QByteArray("{\"content\":{}, \"array\":[]}") << QByteArray("{\"content\":{}, \"array\":[]}");
        QTest::newRow("unwrapped-array") << QByteArray("[{\"content\":{}, \"array\":[]}]") << QByteArray("[{\"content\":{}, \"array\":[]}]");

        QTest::newRow("invalid-object") << QByteArray("}{") << QByteArray("}{");
        QTest::newRow("invalid-array") << QByteArray("][") << QByteArray("][");

        QTest::newRow("invalid") << QByteArray("{[") << QByteArray("{[");
        QTest::newRow("invalid-mismatch") << QByteArray("{]") << QByteArray("{]");
    }

    void testDecode()
    {
        QFETCH(QByteArray, in);
        QFETCH(QByteArray, out);

        QCOMPARE(JsonP::decode(in), out);
    }
};

QTEST_APPLESS_MAIN(JsonPTest)

#include "jsonptest.moc"
