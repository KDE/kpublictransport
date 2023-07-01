/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"
#include "backends/oebbvehiclelayoutparser.cpp"
#include "uic/uicrailwaycoach.cpp"

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class OebbParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testVehicleLayoutParse_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("departureFileName");

        QTest::newRow("rj-forward")
            << s(SOURCE_DIR "/data/oebb/rj-forward-input.json")
            << s(SOURCE_DIR "/data/oebb/rj-forward-departure.json");

        QTest::newRow("rj-no-platform-sectors")
            << s(SOURCE_DIR "/data/oebb/rj-no-platform-sectors-input.json")
            << s(SOURCE_DIR "/data/oebb/rj-no-platform-sectors-departure.json");

        QTest::newRow("ic-no-platform-data")
            << s(SOURCE_DIR "/data/oebb/ic-no-platform-data-input.json")
            << s(SOURCE_DIR "/data/oebb/ic-no-platform-data-departure.json");

        QTest::newRow("regionalexpress")
            << s(SOURCE_DIR "/data/oebb/regional-express-input.json")
            << s(SOURCE_DIR "/data/oebb/regional-express-departure.json");

        QTest::newRow("sbahn")
            << s(SOURCE_DIR "/data/oebb/sbahn-input.json")
            << s(SOURCE_DIR "/data/oebb/sbahn-departure.json");

        QTest::newRow("nightjet")
            << s(SOURCE_DIR "/data/oebb/nightjet-input.json")
            << s(SOURCE_DIR "/data/oebb/nightjet-departure.json");
    }

    void testVehicleLayoutParse()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, departureFileName);

        KPublicTransport::OebbVehicleLayoutParser parser;

        QVERIFY(parser.parse(Test::readFile(inFileName)));
        const auto departureJson = Stopover::toJson(parser.stopover);
        const auto departureRef = QJsonDocument::fromJson(Test::readFile(departureFileName)).object();
        QVERIFY(!departureJson.isEmpty());
        QVERIFY(Test::compareJson(departureFileName, departureJson, departureRef));
    }
};

QTEST_GUILESS_MAIN(OebbParserTest)

#include "oebbparsertest.moc"
