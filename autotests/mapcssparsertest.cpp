/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
        QVERIFY(p.errorMessage().isEmpty());
    }
};

QTEST_GUILESS_MAIN(MapCSSParserTest)

#include "mapcssparsertest.moc"
