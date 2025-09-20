/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"
#include "backends/hafasqueryparser.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>

#include <QFile>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace Qt::Literals;
using namespace KPublicTransport;

class HafasQueryParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testParseJourneyError()
    {
#if Q_BYTE_ORDER == Q_BIG_ENDIAN
        QSKIP("not supported on big endian systems yet!", SkipAll);
#endif
        HafasQueryParser p;
        const auto res = p.parseQueryJourneyResponse(Test::readFile(SOURCE_DIR "/data/hafas/journey-binary-error.bin.gz"));
        QVERIFY(res.empty());
        QCOMPARE(p.error(), Reply::NotFoundError);
    }

    void testParseJourney()
    {
#if Q_BYTE_ORDER == Q_BIG_ENDIAN
        QSKIP("not supported on big endian systems yet!", SkipAll);
#endif

        QFile f(u"" SOURCE_DIR "/data/hafas/journey-railteam.bin.gz"_s);
        QVERIFY(f.open(QFile::ReadOnly));
        const auto data = f.readAll(); // can't use Test::readFile here as that assumes text files!

        HafasQueryParser p;
        const auto res = p.parseQueryJourneyResponse(data);
        QVERIFY(!res.empty());
        QCOMPARE(p.error(), Reply::NoError);

        const auto jsonRes = Journey::toJson(res);
        const auto ref = QJsonDocument::fromJson(Test::readFile(u"" SOURCE_DIR "/data/hafas/journey-railteam.json"_s)).array();

        QVERIFY(!jsonRes.empty());
        QVERIFY(Test::compareJson(u"" SOURCE_DIR "/data/hafas/journey-railteam.json"_s, jsonRes, ref));
    }

    void testParseLocationByCoordinateResponse()
    {
        HafasQueryParser p;
        p.setLocationIdentifierTypes(s("testId"));
        auto res = p.parseQueryLocationResponse(Test::readFile(SOURCE_DIR "/data/hafas/query-location-response.json"));
        QCOMPARE(res.size(), 1);
        QCOMPARE(p.error(), Reply::NoError);

        auto loc = res[0];
        QCOMPARE(loc.name(), s("Frankfurt (Main) Hauptbahnhof"));
        QCOMPARE(loc.identifier(s("testId")), s("3000010"));
        QCOMPARE((int)loc.latitude(), 50);
        QCOMPARE((int)loc.longitude(), 8);

        res = p.parseQueryLocationResponse(Test::readFile(SOURCE_DIR "/data/hafas/query-location-response-sbb-broken-json.json"));
        QCOMPARE(res.size(), 1);
        QCOMPARE(p.error(), Reply::NoError);

        loc = res[0];
        QCOMPARE(loc.name(), s("Randa"));
        QCOMPARE(loc.identifier(s("testId")), s("8501687"));
        QCOMPARE((int)loc.latitude(), 46);
        QCOMPARE((int)loc.longitude(), 7);
    }
};

QTEST_GUILESS_MAIN(HafasQueryParserTest)

#include "hafasqueryparsertest.moc"
