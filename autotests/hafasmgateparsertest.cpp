/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#include <KPublicTransport/Journey>
#include <KPublicTransport/HafasMgateParser>
#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class HafasMgateParserTest : public QObject
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

    void testParseGeneralError_data()
    {
        QTest::addColumn<QString>("input");
        QTest::newRow("version") << s(SOURCE_DIR "/data/hafas/error-invalid-version.json");
        QTest::newRow("parse-clientId") << s(SOURCE_DIR "/data/hafas/error-parse-clientId.json");
        QTest::newRow("parse-stbFilterEquiv") << s(SOURCE_DIR "/data/hafas/error-parse-stbFilterEquiv.json");
        QTest::newRow("parse-empty") << s(SOURCE_DIR "/data/hafas/error-parse-empty.json");
    }

    void testParseGeneralError()
    {
        QFETCH(QString, input);

        {
            HafasMgateParser p;
            p.parseLocations(readFile(input));
            QCOMPARE(p.error(), Reply::UnknownError);
            QVERIFY(!p.errorMessage().isEmpty());
        }

        {
            HafasMgateParser p;
            p.parseDepartures(readFile(input));
            QCOMPARE(p.error(), Reply::UnknownError);
            QVERIFY(!p.errorMessage().isEmpty());
        }

        {
            HafasMgateParser p;
            p.parseJourneys(readFile(input));
            QCOMPARE(p.error(), Reply::UnknownError);
            QVERIFY(!p.errorMessage().isEmpty());
        }
    }

    void testParseDepartureError()
    {
        HafasMgateParser p;
        const auto res = p.parseDepartures(readFile(s(SOURCE_DIR "/data/hafas/stationboard-error-response.json")));
        QVERIFY(res.empty());
        QCOMPARE(p.error(), Reply::NotFoundError);
        QVERIFY(!p.errorMessage().isEmpty());
    }

    void parseDateTime_data()
    {
        QTest::addColumn<QString>("date");
        QTest::addColumn<QString>("time");
        QTest::addColumn<QJsonValue>("tzOffset");
        QTest::addColumn<QDateTime>("dt");

        QTest::newRow("empty") << QString() << QString() << QJsonValue() << QDateTime();
        QTest::newRow("same day") << s("20190105") << s("142100") << QJsonValue() << QDateTime({2019, 1, 5}, {14, 21});
        QTest::newRow("next day") << s("20190105") << s("01142100") << QJsonValue() << QDateTime({2019, 1, 6}, {14, 21});
        QTest::newRow("same day offset") << s("20190105") << s("142100") << QJsonValue(120) << QDateTime({2019, 1, 5}, {14, 21}, Qt::OffsetFromUTC, 7200);
        QTest::newRow("next day offset") << s("20190105") << s("01142100") << QJsonValue(-120) << QDateTime({2019, 1, 6}, {14, 21}, Qt::OffsetFromUTC, -7200);
    }

    void parseDateTime()
    {
        QFETCH(QString, date);
        QFETCH(QString, time);
        QFETCH(QJsonValue, tzOffset);
        QFETCH(QDateTime, dt);
        QCOMPARE(HafasMgateParser::parseDateTime(date, QJsonValue(time), tzOffset), dt);
    }

    void testParseDepartures_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("de-nw-avv-canceled-departures")
            << s(SOURCE_DIR "/data/hafas/canceled-departures.in.json")
            << s(SOURCE_DIR "/data/hafas/canceled-departures.out.json");
    }

    void testParseDepartures()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        HafasMgateParser p;
        p.setLocationIdentifierTypes(QStringLiteral("unit-test"));
        const auto res = p.parseDepartures(readFile(inFileName));
        const auto jsonRes = Stopover::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QVERIFY(!jsonRes.empty());
        QCOMPARE(jsonRes, ref);
    }
};

QTEST_GUILESS_MAIN(HafasMgateParserTest)

#include "hafasmgateparsertest.moc"
