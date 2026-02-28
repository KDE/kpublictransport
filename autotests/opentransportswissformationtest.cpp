/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"
#include "backends/opentransportswissformationparser.cpp"
#include "datatypes/featureutil.cpp"
#include "uic/uicrailwaycoach.cpp"

#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

using namespace Qt::Literals;
using namespace KPublicTransport;

class OpenTransportSwissFormationTest : public QObject
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
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("ic5")
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-ic5.in.json"_s
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-ic5.out.json"_s;
    }

    void testVehicleLayoutParse()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, outFileName);

        KPublicTransport::OpenTransportSwissFormationParser parser;

        QVERIFY(parser.parse(Test::readFile(inFileName), u"test_id"_s));
        const auto stopJson = Stopover::toJson(parser.stopover);
        const auto stopRef = QJsonDocument::fromJson(Test::readFile(outFileName)).object();
        QVERIFY(!stopJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, stopJson, stopRef));
    }

    void testParseError()
    {
        KPublicTransport::OpenTransportSwissFormationParser parser;
        QVERIFY(!parser.parse(Test::readFile(u"" SOURCE_DIR "/data/opentransportswiss/formation-error.in.json"_s), u"test_id"_s));
        QCOMPARE(parser.errorMsg, "There were no formation data."_L1);
    }
};

QTEST_GUILESS_MAIN(OpenTransportSwissFormationTest)

#include "opentransportswissformationtest.moc"
