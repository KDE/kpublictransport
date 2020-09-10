/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <kgraphqlminimizer_p.h>

#include <QObject>
#include <QTest>

#define B(x) QByteArray(x)

class KGraphQLMinimizerTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testMinimize_data()
    {
        QTest::addColumn<QByteArray>("in");
        QTest::addColumn<QByteArray>("out");

        QTest::newRow("empty") << B("") << B("");
        QTest::newRow("leading comment") << B("# bla\nquery") << B("query");
        QTest::newRow("inline comment") << B("query # comment\n{}") << B("query\n{}");
        QTest::newRow("indent") << B("{\n  __schema {\n    types {\n   name\n   }\n}") << B("{\n__schema {\ntypes {\nname\n}\n}");
    }

    void testMinimize()
    {
        QFETCH(QByteArray, in);
        QFETCH(QByteArray, out);

        KGraphQLMinimizer m;
        QCOMPARE(m.minimizeQuery(in), out);
    }
};

QTEST_GUILESS_MAIN(KGraphQLMinimizerTest)

#include "kgraphqlminimizertest.moc"
