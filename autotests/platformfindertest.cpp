/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <map/loader/mapdata.h>
#include <map/loader/maploader.h>
#include <map/content/platformfinder.h>

#include <QProcess>
#include <QTest>

using namespace KOSMIndoorMap;

class PlatformFinderTest : public QObject
{
    Q_OBJECT
private:
    void writeElement(QIODevice *device, OSM::Element elem)
    {
        switch (elem.type()) {
            case OSM::Type::Null:
                device->write("<null>");
                break;
            case OSM::Type::Node:
                device->write("n" + QByteArray::number((qlonglong)elem.id()));
                break;
            case OSM::Type::Way:
                if (elem.id() >= 0) {
                    device->write("w" + QByteArray::number((qlonglong)elem.id()));
                } else {
                    device->write("<synthetic way>");
                }
                break;
            case OSM::Type::Relation:
                if (elem.id() >= 0) {
                    device->write("r" + QByteArray::number((qlonglong)elem.id()));
                } else {
                    device->write("<synthetic relation>");
                }
                break;
        }
    }

private Q_SLOTS:
    void initTestCase()
    {
        QLocale::setDefault(QLocale(QLocale::English, QLocale::LatinScript, QLocale::UnitedStates));
    }

    void testPlatformFinder_data()
    {
        QTest::addColumn<QString>("input");
        QTest::addColumn<QString>("expected");

        // has platform_edge and platform section tags
        QTest::newRow("hamburg-altona") << (SOURCE_DIR "/data/platforms/hamburg-altona.osm") << (SOURCE_DIR "/data/platforms/hamburg-altona.platforms");
    }

    void testPlatformFinder()
    {
        QFETCH(QString, input);
        QFETCH(QString, expected);

        MapLoader loader;
        loader.loadFromFile(input);
        QCOMPARE(loader.isLoading(), false);
        QCOMPARE(loader.hasError(), false);

        const auto mapData = loader.takeData();
        QVERIFY(!mapData.dataSet().nodes.empty());
        QVERIFY(!mapData.dataSet().ways.empty());
        QVERIFY(!mapData.dataSet().relations.empty());
        QVERIFY(mapData.boundingBox().height() > 0);
        QVERIFY(mapData.boundingBox().width() > 0);

        PlatformFinder finder;
        const auto result = finder.find(&mapData);
        QVERIFY(!result.empty());

        QFile expectedFile(expected);
        QVERIFY(expectedFile.open(QFile::ReadOnly));
        const auto expectedPlatforms = expectedFile.readAll();

        QFile outFile(QFileInfo(expected).fileName());
        QVERIFY(outFile.open(QFile::ReadWrite | QFile::Truncate));

        for (const auto &platform : result) {
            outFile.write(platform.name().toUtf8() + "\n");
            outFile.write("  position: " + QByteArray::number(platform.position().latitude) + " " + QByteArray::number(platform.position().longitude) + "\n");
            outFile.write("  edge: ");
            writeElement(&outFile, platform.edge());
            outFile.write("\n");
            outFile.write("  area: ");
            writeElement(&outFile, platform.area());
            outFile.write("\n");
            outFile.write("  track: ");
            writeElement(&outFile, platform.track());
            outFile.write("\n");
            outFile.write("  level: " + QByteArray::number(platform.level()) + "\n");
            outFile.write("  mode: " + QByteArray::number(platform.mode) + "\n");
            //outFile.write("  " + platform.lines.join(QLatin1Char('|')).toUtf8() + "\n");
        }
        outFile.seek(0);
        const auto platforms = outFile.readAll();

        if (platforms != expectedPlatforms) {
            QProcess proc;
            proc.setProcessChannelMode(QProcess::ForwardedChannels);
            proc.start(QStringLiteral("diff"), {QStringLiteral("-u"), expectedFile.fileName(), outFile.fileName()});
            proc.waitForFinished();
        }
        QVERIFY(platforms == expectedPlatforms);
    }
};

QTEST_GUILESS_MAIN(PlatformFinderTest)

#include "platformfindertest.moc"
