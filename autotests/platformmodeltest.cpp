/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <map/loader/mapdata.h>
#include <map/loader/maploader.h>
#include <map/content/platformmodel.h>

#include <QTest>
#include <QAbstractItemModelTester>

using namespace KOSMIndoorMap;

class PlatformModelTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testPlatformModel()
    {
        MapLoader loader;
        loader.loadFromFile(QStringLiteral(SOURCE_DIR "/data/platforms/hamburg-altona.osm"));
        QCOMPARE(loader.isLoading(), false);
        QCOMPARE(loader.hasError(), false);

        auto mapData = loader.takeData();
        QVERIFY(!mapData.dataSet().nodes.empty());
        QVERIFY(!mapData.dataSet().ways.empty());
        QVERIFY(!mapData.dataSet().relations.empty());
        QVERIFY(mapData.boundingBox().height() > 0);
        QVERIFY(mapData.boundingBox().width() > 0);

        PlatformModel model;
        QAbstractItemModelTester modelTest(&model);

        model.setMapData(&mapData);
        model.setArrivalPlatform(QStringLiteral("10"), Platform::Rail);
        model.setDeparturePlatform(QStringLiteral("7"), Platform::Rail);
        QCOMPARE(model.rowCount(), 12);

        for (int i = 0; i < model.rowCount(); ++i) {
            const auto idx = model.index(i, 0);
            QVERIFY(!idx.data(Qt::DisplayRole).toString().isEmpty());
            QVERIFY(idx.data(PlatformModel::ElementRole).value<OSM::Element>().type() != OSM::Type::Null);

            const auto secCount = model.rowCount(idx);
            QVERIFY(secCount > 0 || !(idx.data(PlatformModel::DeparturePlatformRole).toBool() || idx.data(PlatformModel::ArrivalPlatformRole).toBool()));
            for (int j = 0; j < secCount; ++j) {
                const auto secIdx = model.index(j, 0, idx);
                QVERIFY(!secIdx.data(Qt::DisplayRole).toString().isEmpty());
                QVERIFY(secIdx.data(PlatformModel::ElementRole).value<OSM::Element>().type() != OSM::Type::Null);
            }
        }

        QVERIFY(model.departurePlatformRow() >= 0);
        QVERIFY(model.arrivalPlatformRow() >= 0);

        // fuzzy platform matching
        model.setArrivalPlatform(QStringLiteral("10 D-F"), Platform::Rail);
        model.setDeparturePlatform(QStringLiteral("9A-C"), Platform::Rail);
        QVERIFY(model.departurePlatformRow() >= 0);
        QVERIFY(model.arrivalPlatformRow() >= 0);

        // non-matching platforms
        model.setArrivalPlatform(QStringLiteral("13"), Platform::Rail);
        model.setDeparturePlatform(QStringLiteral("14 A-D"), Platform::Rail);
        QCOMPARE(model.departurePlatformRow(), -1);
        QCOMPARE(model.arrivalPlatformRow(), -1);

    }
};

QTEST_GUILESS_MAIN(PlatformModelTest)

#include "platformmodeltest.moc"
