/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../src/lib/datatypes/json_p.h"

#include <KPublicTransport/Vehicle>

#include <QObject>
#include <QTest>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

class JsonTest: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testFlags()
    {
        QCOMPARE(Json::flagsFromJson<VehicleSection::Sides>(QJsonValue("Front|Back"_L1)), VehicleSection::Front | VehicleSection::Back);
    }
};

QTEST_APPLESS_MAIN(JsonTest)

#include "jsontest.moc"
