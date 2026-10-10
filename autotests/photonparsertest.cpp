/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"
#include "backends/photonparser.cpp"
#include "geo/geojson.cpp"

#include <KPublicTransport/Location>

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>

using namespace Qt::Literals;
using namespace KPublicTransport;

class PhotonParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testLocationParse_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("balatonalm")
            << u"" SOURCE_DIR "/data/photon/balatonalm.in.json"_s
            << u"" SOURCE_DIR "/data/photon/balatonalm.out.json"_s;
        QTest::newRow("dresden")
            << u"" SOURCE_DIR "/data/photon/dresden.in.json"_s
            << u"" SOURCE_DIR "/data/photon/dresden.out.json"_s;
    }

    void testLocationParse()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        const auto locs = KPublicTransport::PhotonParser::parseLocations(Test::readFile(inFileName));
        const auto locsRef = QJsonDocument::fromJson(Test::readFile(outFileName)).array();
        QVERIFY(Test::compareJson(outFileName, Location::toJson(locs), locsRef));
    }
};

QTEST_GUILESS_MAIN(PhotonParserTest)

#include "photonparsertest.moc"

