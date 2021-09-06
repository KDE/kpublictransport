/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backends/openjourneyplannerparser.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QLocale>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class OjpParserTest : public QObject
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
    }

    void testParseLocations_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("ch-location-by-coord")
            << s(SOURCE_DIR "/data/ojp/ch-location-by-coord.xml")
            << s(SOURCE_DIR "/data/ojp/ch-location-by-coord.json");
    }

    void testParseLocations()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        OpenJourneyPlannerParser p;
        const auto res = p.parseLocationInformationResponse(readFile(inFileName));
        const auto jsonRes = Location::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();
        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }

    void testParseStopover_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("ch-stopover-departure")
            << s(SOURCE_DIR "/data/ojp/ch-stopover-departure.xml")
            << s(SOURCE_DIR "/data/ojp/ch-stopover-departure.json");
    }

    void testParseStopover()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        OpenJourneyPlannerParser p;
        const auto res = p.parseStopEventResponse(readFile(inFileName));
        const auto jsonRes = Stopover::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();
        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }
};

QTEST_GUILESS_MAIN(OjpParserTest)

#include "ojpparsertest.moc"
