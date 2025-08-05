/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/LocationHistoryModel>

#include <QAbstractItemModelTester>
#include <QStandardPaths>
#include <QTest>

using namespace KPublicTransport;

class LocationHistoryModelTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        QStandardPaths::setTestModeEnabled(true);
    }

    void testHistoryModel()
    {
        {
            LocationHistoryModel model;
            QAbstractItemModelTester modelTest(&model);

            model.clear();
            QCOMPARE(model.rowCount(), 0);

            Location loc;
            loc.setName(QStringLiteral("Randa"));
            loc.setCoordinate(46.09901, 7.78315);
            model.addLocation(loc);
            QCOMPARE(model.rowCount(), 1);

            auto idx = model.index(0, 0);
            QCOMPARE(model.data(idx, LocationHistoryModel::LocationRole).value<Location>().name(), QLatin1String("Randa"));
            QCOMPARE(model.data(idx, LocationHistoryModel::LastUsedRole).value<QDateTime>().date(), QDate::currentDate());
            QCOMPARE(model.data(idx, LocationHistoryModel::UseCountRole).toInt(), 1);

            loc.setIdentifier(QStringLiteral("uic"), QStringLiteral("8501687"));
            model.addLocation(loc);
            QCOMPARE(model.rowCount(), 1);
            idx = model.index(0, 0);
            QCOMPARE(model.data(idx, LocationHistoryModel::LocationRole).value<Location>().name(), QLatin1String("Randa"));
            QCOMPARE(model.data(idx, LocationHistoryModel::LocationRole).value<Location>().identifier(QStringLiteral("uic")), QLatin1String("8501687"));
            QCOMPARE(model.data(idx, LocationHistoryModel::LastUsedRole).value<QDateTime>().date(), QDate::currentDate());
            QCOMPARE(model.data(idx, LocationHistoryModel::UseCountRole).toInt(), 2);

            Location loc2;
            loc2.setName(QStringLiteral("Brussels Gare du Midi"));
            loc2.setCoordinate(50.83588, 4.33620);
            model.addLocation(loc2);
            QCOMPARE(model.rowCount(), 2);
            idx = model.index(1, 0);
            QCOMPARE(model.data(idx, LocationHistoryModel::LocationRole).value<Location>().name(), QLatin1String("Brussels Gare du Midi"));
            QCOMPARE(model.data(idx, LocationHistoryModel::UseCountRole).toInt(), 1);

            QVERIFY(model.removeRow(1));
            QCOMPARE(model.rowCount(), 1);
            idx = model.index(0, 0);
            QCOMPARE(model.data(idx, LocationHistoryModel::LocationRole).value<Location>().name(), QLatin1String("Randa"));
        }
        {
            LocationHistoryModel model;
            QAbstractItemModelTester modelTest(&model);
            QCOMPARE(model.rowCount(), 1);
            auto idx = model.index(0, 0);
            QCOMPARE(model.data(idx, LocationHistoryModel::LocationRole).value<Location>().name(), QLatin1String("Randa"));
            QCOMPARE(model.data(idx, LocationHistoryModel::LastUsedRole).value<QDateTime>().date(), QDate::currentDate());
            QCOMPARE(model.data(idx, LocationHistoryModel::UseCountRole).toInt(), 2);

            model.importEntry(R"({"useCount": 3, "lastUse": "2025-08-05T17:00:00Z", "location": {"name": "Randa", "longitude": 7.78315, "latitute": 46.099}})");
            QCOMPARE(model.rowCount(), 1);
            QCOMPARE(model.data(idx, LocationHistoryModel::UseCountRole).toInt(), 3);
        }
    }
};

QTEST_GUILESS_MAIN(LocationHistoryModelTest)

#include "locationhistorymodeltest.moc"
