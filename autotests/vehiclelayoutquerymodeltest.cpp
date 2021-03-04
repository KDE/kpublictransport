/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/Manager>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/VehicleLayoutQueryModel>

#include <QAbstractItemModelTester>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSignalSpy>
#include <QTest>

using namespace KPublicTransport;

class VehicleLayoutQueryModelTest : public QObject
{
    Q_OBJECT
private:
    QByteArray readFile(const QString &fn)
    {
        QFile f(fn);
        f.open(QFile::ReadOnly);
        return f.readAll();
    }

private Q_SLOTS:
    void testCoachPositionInterpolation()
    {
        Manager ptMgr;

        VehicleLayoutQueryModel model;
        QAbstractItemModelTester modelTest(&model);
        model.setManager(&ptMgr);
        QSignalSpy resetSpy(&model, &QAbstractItemModel::modelReset);

        const auto inVec = Vehicle::fromJson(QJsonDocument::fromJson(readFile(QStringLiteral(SOURCE_DIR "/data/hafas/rem-I-JF-sbb-ic-train-formation-bern-vehicle.json"))).object());
        QCOMPARE(inVec.sections().size(), 10);
        QVERIFY(!inVec.hasPlatformPositions());
        QVERIFY(inVec.hasPlatformSectionNames());
        const auto inPlat = Platform::fromJson(QJsonDocument::fromJson(readFile(QStringLiteral(SOURCE_DIR "/data/hafas/rem-I-XP-sbb-platform-bern.json"))).object());
        QVERIFY(!inPlat.sections().empty());

        Stopover s;
        s.setVehicleLayout(inVec);
        s.setPlatformLayout(inPlat);
        s.setScheduledDepartureTime(QDateTime::currentDateTime());
        Line line;
        line.setName(QStringLiteral("IC 8"));
        Route route;
        route.setLine(line);
        s.setRoute(route);

        VehicleLayoutRequest req(s);
        QVERIFY(req.isValid());
        model.setRequest(req);
        QVERIFY(resetSpy.wait(10)); // query is started, initial requested data is set
        QCOMPARE(model.rowCount(), 10);
        resetSpy.clear();
        QVERIFY(resetSpy.wait(10)); // query finished, interpolation is triggered
        QCOMPARE(model.rowCount(), 10);

        for (int i = 0; i < model.rowCount(); ++i) {
            const auto idx = model.index(i, 0);
            const auto sec = idx.data(VehicleLayoutQueryModel::VehicleSectionRole).value<VehicleSection>();
            QVERIFY(sec.hasPlatformPosition());
            QCOMPARE(sec.name(), inVec.sections()[i].name());
        }
    }
};

QTEST_GUILESS_MAIN(VehicleLayoutQueryModelTest)

#include "vehiclelayoutquerymodeltest.moc"
