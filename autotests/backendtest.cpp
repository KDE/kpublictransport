/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/Backend>
#include <KPublicTransport/BackendModel>
#include <KPublicTransport/CoverageArea>
#include <KPublicTransport/Location>
#include <KPublicTransport/Manager>

#include <QAbstractItemModelTester>
#include <QSignalSpy>
#include <QStandardPaths>
#include <QTest>

using namespace Qt::Literals;
using namespace KPublicTransport;

class BackendTest : public QObject
{
    Q_OBJECT
private:
    Manager m_ptMgr; // for the benchmark

private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
        QStandardPaths::setTestModeEnabled(true);
    }

    void testCoverageData()
    {
        Manager mgr;
        for (const auto &b : mgr.backends()) {
            QVERIFY(!b.identifier().isEmpty());
            QVERIFY(!b.name().isEmpty());
            QVERIFY(!b.coverageArea(CoverageArea::Realtime).isEmpty() || !b.coverageArea(CoverageArea::Regular).isEmpty() || !b.coverageArea(CoverageArea::Any).isEmpty());

            for (const auto &type : {CoverageArea::Realtime, CoverageArea::Regular, CoverageArea::Any}) {
                const auto c = b.coverageArea(type);
                if (c.isEmpty()) {
                    continue;
                }

                QCOMPARE(c.type(), type);
                QVERIFY(c.regions().size() > 0);
            }
        }
    }

    void testCoverageHitDetection()
    {
        Manager mgr;
        auto b = *std::find_if(mgr.backends().begin(), mgr.backends().end(), [](const auto &b) { return b.identifier() == QLatin1String("de_db"); });
        QCOMPARE(b.identifier(), QLatin1String("de_db"));
        auto c = b.coverageArea(CoverageArea::Realtime);
        QVERIFY(!c.isEmpty());
        QVERIFY(!c.isGlobal());

        Location l1;
        l1.setCoordinate(52.5, 13.0);
        QVERIFY(c.coversLocation(l1));
        l1.setCoordinate(13.0, 52.5);
        QVERIFY(!c.coversLocation(l1));

        Location l2;
        l2.setCountry(QStringLiteral("DE"));
        QVERIFY(c.coversLocation(l2));
        l2.setCountry(QStringLiteral("NZ"));
        QVERIFY(!c.coversLocation(l2));

        b = *std::find_if(mgr.backends().begin(), mgr.backends().end(), [](const auto &b) { return b.identifier() == QLatin1String("un_gbfs"); });
        QCOMPARE(b.identifier(), QLatin1String("un_gbfs"));
        c = b.coverageArea(CoverageArea::Realtime);
        QVERIFY(!c.isEmpty());
        QVERIFY(c.isGlobal());

        QVERIFY(c.coversLocation(l1));
        QVERIFY(c.coversLocation(l2));
    }

    void testCoverageBenchmark()
    {
        Location loc;
        loc.setCoordinate(52.5, 13.0);
        QBENCHMARK {
            for (const auto &b : m_ptMgr.backends()) {
                for (const auto type : { CoverageArea::Realtime, CoverageArea::Regular, CoverageArea::Any }) {
                    const auto c = b.coverageArea(type);
                    c.coversLocation(loc);
                }
            }
        }
    }

    void testBackendModel_data()
    {
        QTest::addColumn<BackendModel::Mode>("mode");
        QTest::newRow("flat") << BackendModel::Flat;
        QTest::newRow("groupByCountry") << BackendModel::GroupByCountry;
    }

    void testBackendModel()
    {
        QFETCH(BackendModel::Mode, mode);

        BackendModel model;
        QAbstractItemModelTester modelTest(&model);

        Manager mgr;
        model.setManager(&mgr);
        model.setMode(mode);
        QVERIFY(model.rowCount() > 20);
        QSignalSpy dataChangedSpy(&model, &QAbstractItemModel::dataChanged);

        mgr.setAllowInsecureBackends(false);
        for (auto i = 0; i < model.rowCount(); ++i) {
            const auto idx = model.index(i, 0);
            const auto backendId = idx.data(BackendModel::IdentifierRole).toString();
            QVERIFY(!backendId.isEmpty());
            QCOMPARE(idx.data(BackendModel::SecureRole).userType(), QMetaType::Bool);
            QVERIFY(!idx.data(BackendModel::NameRole).toString().isEmpty());
            QVERIFY(!idx.data(BackendModel::DescriptionRole).toString().isEmpty());
            QCOMPARE(idx.data(BackendModel::SecureRole), idx.data(BackendModel::ItemEnabledRole));
            if (!idx.data(BackendModel::SecureRole).toBool() && !backendId.endsWith("_staging"_L1)) {
                QVERIFY(!idx.data(BackendModel::BackendEnabledRole).toBool());
            }
            QVERIFY(!idx.data(BackendModel::CountryCodeRole).toString().isEmpty());
        }

        QCOMPARE(dataChangedSpy.size(), 0);
        mgr.setAllowInsecureBackends(true);
        QCOMPARE(dataChangedSpy.size(), 1);
        for (auto i = 0; i < model.rowCount(); ++i) {
            const auto idx = model.index(i, 0);
            QVERIFY(idx.data(BackendModel::ItemEnabledRole).toBool());
            const auto backendId = idx.data(BackendModel::IdentifierRole).toString();
            QCOMPARE(idx.data(BackendModel::BackendEnabledRole).toBool(), !backendId.endsWith("_staging"_L1));
        }

        QCOMPARE(mgr.isBackendEnabled(QStringLiteral("un_transitous")), true);
        QCOMPARE(mgr.isBackendEnabled(QStringLiteral("de_db")), true);
        bool navitiaToggled = false;
        bool sncfToggled = false;
        for (auto i = 0; i < model.rowCount(); ++i) {
            const auto idx = model.index(i, 0);
            if (idx.data(BackendModel::IdentifierRole).toString() == QLatin1String("un_transitous") && !navitiaToggled) {
                model.setData(idx, Qt::Unchecked, Qt::CheckStateRole);
                model.setData(idx, true, BackendModel::BackendEnabledRole);
                navitiaToggled = true;

                QCOMPARE(idx.data(Qt::CheckStateRole).toInt(), Qt::Checked);
                QCOMPARE(idx.data(BackendModel::BackendEnabledRole).toBool(), true);
            }
            if (idx.data(BackendModel::IdentifierRole).toString() == QLatin1String("de_db") && !sncfToggled) {
                model.setData(idx, false, BackendModel::BackendEnabledRole);
                sncfToggled = true;

                QCOMPARE(idx.data(Qt::CheckStateRole).toInt(), Qt::Unchecked);
                QCOMPARE(idx.data(BackendModel::BackendEnabledRole).toBool(), false);
            }
        }
        QVERIFY(navitiaToggled);
        QVERIFY(sncfToggled);
        QCOMPARE(dataChangedSpy.size(), 4);
        QCOMPARE(mgr.isBackendEnabled(QStringLiteral("un_transitous")), true);
        QCOMPARE(mgr.isBackendEnabled(QStringLiteral("de_db")), false);

        QCOMPARE(mgr.enabledBackends(), QStringList(QStringLiteral("un_transitous")));
        QCOMPARE(mgr.disabledBackends(), QStringList(QStringLiteral("de_db")));
        mgr.setBackendEnabled(QStringLiteral("un_transitous"), true);
        mgr.setBackendEnabled(QStringLiteral("de_db"), false);
        QCOMPARE(mgr.enabledBackends(), QStringList(QStringLiteral("un_transitous")));
        QCOMPARE(mgr.disabledBackends(), QStringList(QStringLiteral("de_db")));
        mgr.setBackendEnabled(QStringLiteral("un_transitous"), false);
        mgr.setBackendEnabled(QStringLiteral("de_db"), true);
        QCOMPARE(mgr.disabledBackends(), QStringList(QStringLiteral("un_transitous")));
        QCOMPARE(mgr.enabledBackends(), QStringList(QStringLiteral("de_db")));
    }
};

QTEST_GUILESS_MAIN(BackendTest)

#include "backendtest.moc"
