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
        QTest::addColumn<int>("uicStop");
        QTest::addColumn<QString>("outFileName");

        QTest::newRow("ic5")
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-ic5.in.json"_s << 8503016
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-ic5.out.json"_s;
        QTest::newRow("s2-platform")
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-s2.in.json"_s << 8509000
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-s2-platform.out.json"_s;
        QTest::newRow("s2-no-platform")
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-s2.in.json"_s << 8509180
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-s2-noplatform.out.json"_s;
        QTest::newRow("ic8-forward")
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-ic8.in.json"_s << 8501609
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-ic8-forward.out.json"_s;
        QTest::newRow("ic8-backward")
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-ic8.in.json"_s << 8503000
            << u"" SOURCE_DIR "/data/opentransportswiss/formation-ic8-backward.out.json"_s;

    }

    void testVehicleLayoutParse()
    {
        QFETCH(QString, inFileName);
        QFETCH(int, uicStop);
        QFETCH(QString, outFileName);

        KPublicTransport::OpenTransportSwissFormationParser parser;

        QVERIFY(parser.parse(Test::readFile(inFileName), u"test_id"_s, uicStop));
        const auto stopJson = Stopover::toJson(parser.stopover);
        const auto stopRef = QJsonDocument::fromJson(Test::readFile(outFileName)).object();
        QVERIFY(!stopJson.isEmpty());
        QVERIFY(Test::compareJson(outFileName, stopJson, stopRef));
    }

    void testParseError()
    {
        KPublicTransport::OpenTransportSwissFormationParser parser;
        QVERIFY(!parser.parse(Test::readFile(u"" SOURCE_DIR "/data/opentransportswiss/formation-error.in.json"_s), u"test_id"_s, 8503016));
        QCOMPARE(parser.errorMsg, "There were no formation data."_L1);
    }
};

QTEST_GUILESS_MAIN(OpenTransportSwissFormationTest)

#include "opentransportswissformationtest.moc"
