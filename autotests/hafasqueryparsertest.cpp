/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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
        HafasQueryParser p;
        const auto res = p.parseQueryJourneyResponse(readFile(SOURCE_DIR "/data/hafas/journey-binary-error.bin.gz"));
        QVERIFY(res.empty());
        QCOMPARE(p.error(), Reply::NotFoundError);
    }

    void testParseLocationByCoordinateResponse()
    {
        HafasQueryParser p;
        p.setLocationIdentifierTypes(s("testId"));
        const auto res = p.parseQueryLocationResponse(readFile(SOURCE_DIR "/data/hafas/query-location-response.json"));
        QCOMPARE(res.size(), 1);
        QCOMPARE(p.error(), Reply::NoError);

        const auto loc = res[0];
        QCOMPARE(loc.name(), s("Frankfurt (Main) Hauptbahnhof"));
        QCOMPARE(loc.identifier(s("testId")), s("3000010"));
        QCOMPARE((int)loc.latitude(), 50);
        QCOMPARE((int)loc.longitude(), 8);
    }
};

QTEST_GUILESS_MAIN(HafasQueryParserTest)

#include "hafasqueryparsertest.moc"
