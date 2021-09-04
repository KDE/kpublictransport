/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../src/lib/gbfs/gbfsreader.cpp"

#include <QJsonDocument>
#include <QJsonObject>
#include <QTest>

#include <cmath>

using namespace KPublicTransport;

class GBFSReaderTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testReadCoords()
    {
        auto obj = QJsonDocument::fromJson("{\"lat\":48.396619,\"lon\":9.990212}").object();
        QCOMPARE(obj.size(), 2);
        QCOMPARE(GBFSReader::readLatitude(obj), 48.396619);
        QCOMPARE(GBFSReader::readLongitude(obj), 9.990212);
        obj = QJsonDocument::fromJson("{\"lat\":\"41.4852\",\"lon\":\"-81.8039\",\"vehicle_type\":\"scooter\"}").object();
        QCOMPARE(obj.size(), 3);
        QCOMPARE(GBFSReader::readLatitude(obj), 41.4852);
        QCOMPARE(GBFSReader::readLongitude(obj), -81.8039);
        obj = {};
        QCOMPARE(GBFSReader::readLatitude(obj), NAN);
        QCOMPARE(GBFSReader::readLongitude(obj), NAN);
    }
};

QTEST_APPLESS_MAIN(GBFSReaderTest)

#include "gbfsreadertest.moc"
