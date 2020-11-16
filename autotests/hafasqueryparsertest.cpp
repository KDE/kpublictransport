/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backends/hafasqueryparser.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>

#include <QFile>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class HafasQueryParserTest : public QObject
{
    Q_OBJECT
private:
    QByteArray readFile(const char *fn)
    {
        QFile f(QString::fromUtf8(fn));
        f.open(QFile::ReadOnly);
        return f.readAll();
    }

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
        const auto res = p.parseQueryJourneyResponse(readFile(SOURCE_DIR "/data/hafas/journey-binary-error.bin.gz"));
        QVERIFY(res.empty());
        QCOMPARE(p.error(), Reply::NotFoundError);
    }

    void testParseLocationByCoordinateResponse()
    {
        HafasQueryParser p;
        p.setLocationIdentifierTypes(s("testId"));
        auto res = p.parseQueryLocationResponse(readFile(SOURCE_DIR "/data/hafas/query-location-response.json"));
        QCOMPARE(res.size(), 1);
        QCOMPARE(p.error(), Reply::NoError);

        auto loc = res[0];
        QCOMPARE(loc.name(), s("Frankfurt (Main) Hauptbahnhof"));
        QCOMPARE(loc.identifier(s("testId")), s("3000010"));
        QCOMPARE((int)loc.latitude(), 50);
        QCOMPARE((int)loc.longitude(), 8);

        res = p.parseQueryLocationResponse(readFile(SOURCE_DIR "/data/hafas/query-location-response-sbb-broken-json.json"));
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
