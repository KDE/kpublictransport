/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"

#include "backends/deutschebahnvehiclelayoutparser.cpp"
#include "backends/deutschebahnproducts.cpp"
#include "datatypes/featureutil.cpp"
#include "uic/uicrailwaycoach.cpp"

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class DbParserTest : public QObject
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
    void initTestCase()
    {
        qputenv("TZ", "UTC");
        qRegisterMetaType<Disruption::Effect>();
    }

    void testVehicleLayoutParse_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("departureFileName");

        QTest::newRow("valid-double-segment-ice")
            << s(SOURCE_DIR "/data/deutschebahn/double-segment-ice-input.json")
            << s(SOURCE_DIR "/data/deutschebahn/double-segment-ice-departure.json");

        QTest::newRow("valid-double-deck-ic")
            << s(SOURCE_DIR "/data/deutschebahn/double-deck-ic-input.json")
            << s(SOURCE_DIR "/data/deutschebahn/double-deck-ic-departure.json");

        QTest::newRow("no-position")
            << s(SOURCE_DIR "/data/deutschebahn/no-position-input.json")
            << s(SOURCE_DIR "/data/deutschebahn/no-position-departure.json");

            QTest::newRow("regionalexpress")
            << s(SOURCE_DIR "/data/deutschebahn/regionalexpress-input.json")
            << s(SOURCE_DIR "/data/deutschebahn/regionalexpress-departure.json");
    }

    void testVehicleLayoutParse()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, departureFileName);

        KPublicTransport::DeutscheBahnVehicleLayoutParser parser;

        QVERIFY(parser.parse(readFile(inFileName)));
        QCOMPARE(parser.error, Reply::NoError);
        QVERIFY(parser.errorMessage.isEmpty());

        const auto departureJson = Stopover::toJson(parser.stopover);
        const auto departureRef = QJsonDocument::fromJson(readFile(departureFileName)).object();
        QVERIFY(!departureJson.isEmpty());
        QVERIFY(Test::compareJson(departureFileName, departureJson, departureRef));
    }

    void testVehicleLayoutParseFailure()
    {
        KPublicTransport::DeutscheBahnVehicleLayoutParser parser;

        QVERIFY(!parser.parse(readFile(QStringLiteral(SOURCE_DIR "/data/deutschebahn/not-found-error.json"))));
        QCOMPARE(parser.error, Reply::NotFoundError);
        QVERIFY(!parser.errorMessage.isEmpty());
    }
};

QTEST_GUILESS_MAIN(DbParserTest)

#include "deutschebahntest.moc"
