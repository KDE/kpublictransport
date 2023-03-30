/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/PlatformLayout>
#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class PlatformLayoutTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testLayout()
    {
        QFile f(s(SOURCE_DIR "/data/deutschebahn/double-segment-ice-departure.json"));
        QVERIFY(f.open(QFile::ReadOnly));
        const auto stopover = Stopover::fromJson(QJsonDocument::fromJson(f.readAll()).object());
        QVERIFY(!stopover.platformLayout().sections().empty());
        QVERIFY(!stopover.vehicleLayout().sections().empty());

        PlatformLayout layout;
        QCOMPARE(layout.sectionsForVehicle(stopover), s("A-F"));
        QCOMPARE(layout.sectionsForClass(stopover, VehicleSection::SecondClass), s("A-F"));
        QCOMPARE(layout.sectionsForClass(stopover, VehicleSection::FirstClass), s("C-D,F"));
        QCOMPARE(layout.sectionsForVehicleSection(stopover, s("21")), s("A"));
        QCOMPARE(layout.sectionsForVehicleSection(stopover, s("32")), s("D-E"));
        QCOMPARE(layout.sectionsForVehicleSection(stopover, s("42")), QString());
    }
};

QTEST_GUILESS_MAIN(PlatformLayoutTest)

#include "platformlayouttest.moc"
