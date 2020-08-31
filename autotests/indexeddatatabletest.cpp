/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <../src/generator/indexeddatatable.cpp>

#include <QTest>

#define S(x) QStringLiteral(x)

class IndexedDataTableTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testSuffixCompression()
    {
        StringTable strTab;

        // suffix
        strTab.addString(S("M4"));
        strTab.addString(S("4"));
        QCOMPARE(strTab.stringOffset(S("M4")), 0);
        QCOMPARE(strTab.stringOffset(S("4")), 1);

        // prefix
        strTab.addString(S("S7"));
        QCOMPARE(strTab.stringOffset(S("S7")), 3);
        strTab.addString(S("S75"));
        QCOMPARE(strTab.stringOffset(S("S7")), 3);
        QCOMPARE(strTab.stringOffset(S("S75")), 6);

        // suffix upgrade
        strTab.addString(S("XS75"));
        QCOMPARE(strTab.stringOffset(S("XS75")), 6);
        QCOMPARE(strTab.stringOffset(S("S75")), 7);

        // empty entry
        strTab.addString(QString()); // should not add
        QCOMPARE(strTab.stringOffset(QString()), 2); // first teriminator element
    }
};

QTEST_GUILESS_MAIN(IndexedDataTableTest)

#include "indexeddatatabletest.moc"
