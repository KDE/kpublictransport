/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"

#include "backends/deutschebahnvehiclelayoutparser.cpp"
#include "backends/deutschebahnproducts.cpp"
#include "datatypes/featureutil.cpp"
#include "uic/uicrailwaycoach.cpp"

#include <QDirIterator>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

using namespace Qt::Literals;
using namespace KPublicTransport;

class DbParserTest : public QObject
{
    Q_OBJECT
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

        QDirIterator it(QStringLiteral(SOURCE_DIR "/data/deutschebahn/"), {u"*.json"_s});
        while (it.hasNext()) {
            it.next();
            if (it.fileName().endsWith("-input.json"_L1)) {
                QTest::newRow(it.fileName().toLatin1().constData()) << it.fileName() << it.fileName().left(it.fileName().size() - 10) + "departure.json"_L1;
            }
        }
    }

    void testVehicleLayoutParse()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, departureFileName);

        const auto result = KPublicTransport::DeutscheBahnVehicleLayoutParser::parse(Test::readFile(QLatin1StringView(SOURCE_DIR "/data/deutschebahn/") + inFileName));

        const auto departureJson = Stopover::toJson(result);
        const auto departureRef = QJsonDocument::fromJson(Test::readFile(QLatin1StringView(SOURCE_DIR "/data/deutschebahn/") + departureFileName)).object();
        QVERIFY(!departureJson.isEmpty());
        QVERIFY(Test::compareJson(QLatin1StringView(SOURCE_DIR "/data/deutschebahn/") + departureFileName, departureJson, departureRef));
    }
};

QTEST_GUILESS_MAIN(DbParserTest)

#include "deutschebahntest.moc"
