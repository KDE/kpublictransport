/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "backends/opentripplannerparser.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class OtpParserTest : public QObject
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

    void testParseDepartures_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("fi-digitransit-departures")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-departure.in.json")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-departure.out.json");
    }

    void testParseDepartures()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        const auto res = OpenTripPlannerParser::parseDepartures(QJsonDocument::fromJson(readFile(inFileName)).object());
        const auto jsonRes = Departure::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }

    void testParseJourney_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("fi-digitransit-departures")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-journey.in.json")
            << s(SOURCE_DIR "/data/otp/fi-digitransit-journey.out.json");
    }

    void testParseJourney()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        const auto res = OpenTripPlannerParser::parseJourneys(QJsonDocument::fromJson(readFile(inFileName)).object());
        const auto jsonRes = Journey::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }
};

QTEST_GUILESS_MAIN(OtpParserTest)

#include "otpparsertest.moc"
