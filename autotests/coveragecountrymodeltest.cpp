/*
    SPDX-FileCopyrightText: Ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/CoverageCountryModel>
#include <KPublicTransport/Manager>

#include <QAbstractItemModelTester>
#include <QStandardPaths>
#include <QTest>

using namespace Qt::Literals;
using namespace KPublicTransport;

class CoverageCountryModelTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        QStandardPaths::setTestModeEnabled(true);
    }

    void testModel()
    {
        Manager mgr;
        CoverageCountryModel model;
        QAbstractItemModelTester modelTest(&model);
        QCOMPARE(model.rowCount(), 0);
        model.setManager(&mgr);
        auto rowCount = model.rowCount();
        QVERIFY(rowCount > 10);

        mgr.setBackendEnabled(u"un_transitous"_s, false);
        QCOMPARE_LT(model.rowCount(), rowCount);

        mgr.setBackendsEnabledByDefault(false);
        QCOMPARE(model.rowCount(), 0);

        mgr.setBackendEnabled(u"at_9_wien"_s, true);
        QCOMPARE(model.rowCount(), 1);
        QCOMPARE(model.data(model.index(0, 0), CoverageCountryModel::CountryCodeRole).toString(), "AT"_L1);

        mgr.setBackendsEnabledByDefault(true);
        QCOMPARE_GT(model.rowCount(), 1);

        mgr.setBackendEnabled(u"un_transitous"_s, true);
        QVERIFY(model.rowCount() > 10);
    }
};

QTEST_GUILESS_MAIN(CoverageCountryModelTest)

#include "coveragecountrymodeltest.moc"
