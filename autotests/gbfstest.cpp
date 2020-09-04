/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

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
