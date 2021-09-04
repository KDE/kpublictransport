/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <../src/lib/gbfs/gbfs.cpp>
#include <gbfs/gbfsservice.h>

#include <QObject>
#include <QStandardPaths>
#include <QTest>

using namespace KPublicTransport;

#define s(x) QStringLiteral(x)

class GbfsTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        QStandardPaths::setTestModeEnabled(true);
    }

    void testFileType()
    {
        QCOMPARE(GBFS::typeForKeyName(u"system_information"), GBFS::SystemInformation);
        QCOMPARE(GBFS::typeForKeyName(u"geofencing_zones"), GBFS::GeofencingZones);
        QCOMPARE(GBFS::typeForKeyName(u"geofencing_zones.json"), GBFS::GeofencingZones);
        QCOMPARE(GBFS::typeForKeyName(u"geofencing_zones_information"), GBFS::Unknown);
    }

    void testGenerateSystemId()
    {
        GBFSService service;
        service.discoveryUrl = QUrl(QStringLiteral("https://mds-global-dud.neuron-mobility.com/gbfs/2/"));
        QVERIFY(service.systemId.isEmpty());
        service.generateSystemId();
        QCOMPARE(service.systemId, QLatin1String("GAFF_F5kMPFE5ZO2iFmAU0AgBcc="));
    }

    void testServiceRepo()
    {
        const auto &services = GBFSServiceRepository::services();
        QVERIFY(services.size() > 200);
        for (const auto &s : services) {
            QVERIFY(!s.systemId.isEmpty());
            QVERIFY(!s.boundingBox.isEmpty());
            QVERIFY(!s.discoveryUrl.isEmpty());
        }
    }
};

QTEST_GUILESS_MAIN(GbfsTest)

#include "gbfstest.moc"
