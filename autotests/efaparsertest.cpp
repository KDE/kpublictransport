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

#include "backends/efaparser.h"

#include <KPublicTransport/Location>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class EfaParserTest : public QObject
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

    void testParseLocation_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("vgn-by-coord")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-vgn-by-coord.xml")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-vgn-by-coord.json");
        QTest::newRow("chicago-by-name")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-chicago-by-name.xml")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-chicago-by-name.json");
        QTest::newRow("tfi-alternate-format")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-alternate-tfi-by-name.xml")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-full-alternate-tfi-by-name.json");
    }

    void testParseLocation()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        KPublicTransport::EfaParser parser;
        parser.setLocationIdentifierType(s("testid"));

        const auto res = parser.parseStopFinderResponse(readFile(inFileName));
        const auto jsonRes = Location::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QCOMPARE(jsonRes, ref);
    }

#if 0
    void testParseCompactLocation_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");

        QTest::newRow("by-by-name")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-compact-by-by-name.xml")
            << s(SOURCE_DIR "/data/efa/stopfinder-response-compact-by-by-name.json");
    }

    void testParseCompactLocation()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);

        KPublicTransport::EfaCompactParser parser;
        parser.setLocationIdentifierType(s("testid"));

        const auto res = parser.parseStopFinderResponse(readFile(inFileName));
        const auto jsonRes = Location::toJson(res);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();

        if (jsonRes != ref) {
            qDebug().noquote() << QJsonDocument(jsonRes).toJson();
        }
        QCOMPARE(jsonRes, ref);
    }
#endif
};

QTEST_GUILESS_MAIN(EfaParserTest)

#include "efaparsertest.moc"
