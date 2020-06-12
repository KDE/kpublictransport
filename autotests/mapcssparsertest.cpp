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

#include <map/style/mapcssparser.h>
#include <map/style/mapcssstyle.h>

#include <QFile>
#include <QTest>

using namespace KOSMIndoorMap;

class MapCSSParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testParse()
    {
        MapCSSParser p;
        const auto style = p.parse(QStringLiteral(SOURCE_DIR "/data/mapcss/parser-test.mapcss"));
        QVERIFY(!p.hasError());

        QFile outFile(QStringLiteral(SOURCE_DIR "/data/mapcss/parser-test.mapcss.out"));
        QVERIFY(outFile.open(QFile::WriteOnly));
        style.write(&outFile);
    }

    void testBuiltInStyles_data()
    {
        QTest::addColumn<QString>("style");

        QTest::newRow("common") << QStringLiteral(SOURCE_DIR "/../src/map/assets/css/breeze-common.mapcss");
        QTest::newRow("light") << QStringLiteral(SOURCE_DIR "/../src/map/assets/css/breeze-light.mapcss");
        QTest::newRow("dark") << QStringLiteral(SOURCE_DIR "/../src/map/assets/css/breeze-dark.mapcss");
        QTest::newRow("diagnostic") << QStringLiteral(SOURCE_DIR "/../src/map/assets/css/diagnostic.mapcss");
    }
    void testBuiltInStyles()
    {
        QFETCH(QString, style);
        MapCSSParser p;
        const auto s = p.parse(style);
        QVERIFY(!p.hasError());
    }
};

QTEST_GUILESS_MAIN(MapCSSParserTest)

#include "mapcssparsertest.moc"
