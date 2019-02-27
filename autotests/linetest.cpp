/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#include <KPublicTransport/Line>

#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class LineTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testLineCompare_data()
    {
        QTest::addColumn<QString>("lhsModeName");
        QTest::addColumn<QString>("lhsName");
        QTest::addColumn<QString>("rhsModeName");
        QTest::addColumn<QString>("rhsName");

        QTest::newRow("identical") << s("S") << s("7") << s("S") << s("7");
        QTest::newRow("mode empty") << s("") << s("S7") << s("") << s("S7");
        QTest::newRow("mode only") << s("R") << s("") << s("R") << s("");

        // TODO
        //QTest::newRow("space") << s("") << s("S7") << s("") << s("S 7");
    }

    void testLineCompare()
    {
        QFETCH(QString, lhsModeName);
        QFETCH(QString, lhsName);
        QFETCH(QString, rhsModeName);
        QFETCH(QString, rhsName);

        Line l, r;
        l.setModeString(lhsModeName);
        l.setName(lhsName);
        r.setModeString(rhsModeName);
        r.setName(rhsName);
        QVERIFY(Line::isSame(l, r));
    }
};

QTEST_GUILESS_MAIN(LineTest)

#include "linetest.moc"
