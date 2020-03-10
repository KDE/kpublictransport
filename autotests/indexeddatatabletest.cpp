/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
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
