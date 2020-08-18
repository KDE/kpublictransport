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

#include <KPublicTransport/BackendModel>
#include <KPublicTransport/Manager>

#include <QAbstractItemModelTester>
#include <QSignalSpy>
#include <QStandardPaths>
#include <QTest>

using namespace KPublicTransport;

class BackendTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
        QStandardPaths::setTestModeEnabled(true);
    }

    void testBackendModel()
    {
        BackendModel model;
        QAbstractItemModelTester modelTest(&model);

        Manager mgr;
        model.setManager(&mgr);
        QVERIFY(model.rowCount() > 20);
        QSignalSpy dataChangedSpy(&model, &QAbstractItemModel::dataChanged);

        mgr.setAllowInsecureBackends(false);
        for (auto i = 0; i < model.rowCount(); ++i) {
            const auto idx = model.index(i, 0);
            QVERIFY(!idx.data(BackendModel::IdentifierRole).toString().isEmpty());
            QCOMPARE(idx.data(BackendModel::SecureRole).type(), QVariant::Bool);
            QVERIFY(!idx.data(BackendModel::NameRole).toString().isEmpty());
            QVERIFY(!idx.data(BackendModel::DescriptionRole).toString().isEmpty());
            QCOMPARE(idx.data(BackendModel::SecureRole), idx.data(BackendModel::ItemEnabledRole));
            if (!idx.data(BackendModel::SecureRole).toBool()) {
                QVERIFY(!idx.data(BackendModel::BackendEnabledRole).toBool());
            }
        }

        QCOMPARE(dataChangedSpy.size(), 0);
        mgr.setAllowInsecureBackends(true);
        QCOMPARE(dataChangedSpy.size(), 1);
        for (auto i = 0; i < model.rowCount(); ++i) {
            const auto idx = model.index(i, 0);
            QVERIFY(idx.data(BackendModel::ItemEnabledRole).toBool());
            QVERIFY(idx.data(BackendModel::BackendEnabledRole).toBool());
        }

        QCOMPARE(mgr.isBackendEnabled(QStringLiteral("un_navitia")), true);
        QCOMPARE(mgr.isBackendEnabled(QStringLiteral("fr_sncf")), true);
        for (auto i = 0; i < model.rowCount(); ++i) {
            const auto idx = model.index(i, 0);
            if (idx.data(BackendModel::IdentifierRole).toString() == QLatin1String("un_navitia")) {
                model.setData(idx, Qt::Unchecked, Qt::CheckStateRole);
                model.setData(idx, true, BackendModel::BackendEnabledRole);

                QCOMPARE(idx.data(Qt::CheckStateRole).toInt(), Qt::Checked);
                QCOMPARE(idx.data(BackendModel::BackendEnabledRole).toBool(), true);
            }
            if (idx.data(BackendModel::IdentifierRole).toString() == QLatin1String("fr_sncf")) {
                model.setData(idx, false, BackendModel::BackendEnabledRole);

                QCOMPARE(idx.data(Qt::CheckStateRole).toInt(), Qt::Unchecked);
                QCOMPARE(idx.data(BackendModel::BackendEnabledRole).toBool(), false);
            }
        }
        QCOMPARE(dataChangedSpy.size(), 4);
        QCOMPARE(mgr.isBackendEnabled(QStringLiteral("un_navitia")), true);
        QCOMPARE(mgr.isBackendEnabled(QStringLiteral("fr_sncf")), false);

        QCOMPARE(mgr.enabledBackends(), QStringList(QStringLiteral("un_navitia")));
        QCOMPARE(mgr.disabledBackends(), QStringList(QStringLiteral("fr_sncf")));
        mgr.setBackendEnabled(QStringLiteral("un_navitia"), true);
        mgr.setBackendEnabled(QStringLiteral("fr_sncf"), false);
        QCOMPARE(mgr.enabledBackends(), QStringList(QStringLiteral("un_navitia")));
        QCOMPARE(mgr.disabledBackends(), QStringList(QStringLiteral("fr_sncf")));
        mgr.setBackendEnabled(QStringLiteral("un_navitia"), false);
        mgr.setBackendEnabled(QStringLiteral("fr_sncf"), true);
        QCOMPARE(mgr.disabledBackends(), QStringList(QStringLiteral("un_navitia")));
        QCOMPARE(mgr.enabledBackends(), QStringList(QStringLiteral("fr_sncf")));
    }
};

QTEST_GUILESS_MAIN(BackendTest)

#include "backendtest.moc"
