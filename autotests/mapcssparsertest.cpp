/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <map/style/mapcssparser.h>
#include <map/style/mapcssstyle.h>

#include <QFile>
#include <QProcess>
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

        QFile outFile(QStringLiteral("parser-test.mapcss.out"));
        QVERIFY(outFile.open(QFile::WriteOnly));
        style.write(&outFile);
        outFile.close();
        QVERIFY(outFile.open(QFile::ReadOnly));
        const auto b1 = outFile.readAll();

        QFile refFile(QStringLiteral(SOURCE_DIR "/data/mapcss/parser-test.mapcss.ref"));
        QVERIFY(refFile.open(QFile::ReadOnly));
        const auto b2 = refFile.readAll();

        if (b1 != b2) {
            QProcess proc;
            proc.setProcessChannelMode(QProcess::ForwardedChannels);
            proc.start(QStringLiteral("diff"), {QStringLiteral("-u"), outFile.fileName(), refFile.fileName()});
            proc.waitForFinished();
        }
        QVERIFY(b1 == b2);
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
