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

#include <knowledgedb/linemetadata.h>

#include <QObject>
#include <QTest>

using namespace KPublicTransport;

#define s(x) QStringLiteral(x)

class LineMetaDataTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testLookup_data()
    {
        QTest::addColumn<double>("latitude");
        QTest::addColumn<double>("longitude");
        QTest::addColumn<QString>("name");
        QTest::addColumn<Line::Mode>("mode");
        QTest::addColumn<QColor>("color");
        QTest::addColumn<QString>("logo");
        QTest::addColumn<QString>("product");

        QTest::newRow("Berlin U1") << 52.52 << 13.40 << s("U1") << Line::Metro << QColor(0xff52b447) << s("Berlin%20U1.svg") << s("U-Bahn.svg");
        QTest::newRow("Berlin S7") << 52.52 << 13.40 << s("S7") << Line::RapidTransit << QColor(0xff8070b7) << s("Berlin%20S7.svg") << s("S-Bahn-Logo.svg");
        QTest::newRow("Munich S1") << 48.13 << 11.58 << s("S1") << Line::RapidTransit << QColor(0xff36caec) << s("M%C3%BCnchen%20S1.svg") << s("S-Bahn-Logo.svg");
        QTest::newRow("Munich S3") << 48.13 << 11.58 << s("S3") << Line::RapidTransit << QColor(0xff862996) << s("M%C3%BCnchen%20S3.svg") << s("S-Bahn-Logo.svg");
        QTest::newRow("Nurnberg S2") << 49.44 << 11.08 << s("S2") << Line::RapidTransit << QColor(0xff65b949) << QString() << s("S-Bahn-Logo.svg");
        QTest::newRow("Nurnberg U2") << 49.44 << 11.08 << s("U2") << Line::Metro << QColor(0xffff0000) << s("N%C3%BCrnberg%20U2.svg") << s("U-Bahn.svg");
        QTest::newRow("Frankfurt U8") << 50.1 << 8.66 << s("U8") << Line::Metro << QColor(0xffc77db5) << s("Frankfurt%20U8.svg") << s("U-Bahn.svg");
        QTest::newRow("Brussels 2") << 50.83 << 4.33 << s("2") << Line::Metro << QColor(0xfff57000) << s("STIB-MIVB%20Line%202.svg") << s("Brussels%20Metro%20Logo.svg");
        QTest::newRow("Brussels 82") << 50.83 << 4.33 << s("82") << Line::Tramway << QColor(0xff9ebfe3) << s("STIB-MIVB%20Line%2082.svg") << s("Brussels%20tramway%20icon.svg");
        QTest::newRow("Brussels S6") << 50.83 << 4.33 << s("S6") << Line::RapidTransit << QColor(0xff965f26) << QString() << s("NMBS%20S-Trein%20logo.svg");
        QTest::newRow("Brussels S10") << 50.83 << 4.33 << s("S10") << Line::RapidTransit << QColor(0xffff1f20) << QString() << s("NMBS%20S-Trein%20logo.svg");
        QTest::newRow("Paris RER C") << 48.84 << 2.37 << s("C") << Line::RapidTransit << QColor(0xfffcd946) << s("Paris%20RER%20C%20icon.svg") << s("RER.svg");
        QTest::newRow("Paris RER D") << 48.84 << 2.37 << s("D") << Line::RapidTransit << QColor(0xff5e9620) << s("Paris%20RER%20D%20icon.svg") << s("RER.svg");
        QTest::newRow("Paris Metro 1") << 48.84 << 2.37 << s("1") << Line::Metro << QColor(0xfff2c931) << s("Paris%20Metro%201.svg") << s("Metro-M.svg");
        QTest::newRow("Milano M5") << 45.48 << 9.18 << s("M5") << Line::Metro << QColor(0xff7956a3) << s("Milano%20linea%20M5.svg") << s("Logo%20Metropolitane%20Italia.svg");
        QTest::newRow("Milano S1") << 45.48 << 9.18 << s("S1") << Line::RapidTransit << QColor(0xffde3d30) << s("Milano%20S1.svg") << s("Linee%20S%20di%20Milano.svg");
        QTest::newRow("Hannover S1") << 52.37 << 9.74 << s("S1") << Line::RapidTransit << QColor(0xff7760b0) << QString() << s("S-Bahn-Logo.svg");
        QTest::newRow("Magdeburg S1") << 52.13 << 11.62 << s("S 1") << Line::RapidTransit << QColor(0xff408040) << QString() << s("S-Bahn-Logo.svg");
        QTest::newRow("Magdeburg 1") << 52.13 << 11.62 << s("1") << Line::Tramway << QColor(0xffb6005c) << QString() << QString();
        QTest::newRow("Vienna U1") << 48.18 << 16.37 << s("U1") << Line::Metro << QColor(0xffe20613) << s("Wien%20U1.svg") << s("U-Bahn%20Wien.svg");
        QTest::newRow("Vienna S1") << 48.18 << 16.37 << s("S1") << Line::RapidTransit << QColor(0xff343593) << QString() << s("S-Bahn%20Austria.svg");
        QTest::newRow("Hamburg U1") << 53.55 << 10.0 << s("U1") << Line::Metro << QColor(0xff0066b3) << s("Hamburg%20U1.svg") << s("U-Bahn.svg");
        QTest::newRow("Hamburg S1") << 53.55 << 10.0 << s("S1") << Line::RapidTransit << QColor(0xff33b540) << s("Hamburg%20S1.svg") << s("S-Bahn-Logo.svg");
        QTest::newRow("Copenhagen A") << 55.67 << 12.56 << s("A") << Line::RapidTransit << QColor(0xff00bfff) << s("S-train%20service%20A.svg") << s("S-tog.svg");
        QTest::newRow("Cologne S11") << 50.94 << 6.97 << s("S11") << Line::RapidTransit << QColor(0xffef7c00) << QString() << s("S-Bahn-Logo.svg");
        QTest::newRow("Stuttgart S1") << 48.78 << 9.18 << s("S1") << Line::RapidTransit << QColor(0xff5c8e3c) << QString() << s("S-Bahn-Logo.svg");
        QTest::newRow("Barcelona L1") << 41.37 << 2.13 << s("L1") << Line::Metro << QColor(0xffe33638) << QString() << s("Barcelona%20Metro%20Logo.svg");
        QTest::newRow("Toulouse Metro A") << 43.6 << 1.44 << s("A") << Line::Metro << QColor(0xffdb001b) << QString() << QString();
        QTest::newRow("San Francisco BART Yellow") << 37.77 << -122.41 << s("Yellow") << Line::Metro << QColor(0xffffe800) << QString() << s("Bart-logo.svg");
    }

    void testLookup()
    {
        QFETCH(double, latitude);
        QFETCH(double, longitude);
        QFETCH(QString, name);
        QFETCH(Line::Mode, mode);
        QFETCH(QColor, color);
        QFETCH(QString, logo);
        QFETCH(QString, product);

        const auto l = LineMetaData::find(latitude, longitude, name, mode);
        QVERIFY(!l.isNull());

        QCOMPARE(l.name(), name);
        QCOMPARE(l.mode(), mode);
        QCOMPARE(l.color(), color);

        if (logo.isEmpty()) {
            QCOMPARE(l.logoUrl(), QUrl());
        } else {
            QEXPECT_FAIL("Munich S3", "waiting for OSM update", Continue);
            QCOMPARE(l.logoUrl().toString(QUrl::FullyEncoded), QString(QLatin1String("https://commons.wikimedia.org/wiki/Special:Redirect/file/") + logo));
        }

        if (product.isEmpty()) {
            QCOMPARE(l.modeLogoUrl(), QUrl());
        } else {
            QCOMPARE(l.modeLogoUrl().toString(QUrl::FullyEncoded), QString(QLatin1String("https://commons.wikimedia.org/wiki/Special:Redirect/file/") + product));
        }
    }

    void testLookupSpecial()
    {
        const auto l = LineMetaData::find(52.52, 13.40,  QStringLiteral("S 7"), Line::Train);
        QVERIFY(!l.isNull());
        QCOMPARE(l.name(), QLatin1String("S7"));
        QCOMPARE(l.mode(), Line::RapidTransit);
    }

    void testNegativeLookup()
    {
        auto l = LineMetaData::find(0.0f, -89.0, QStringLiteral("U1"), Line::Metro);
        QVERIFY(l.isNull());

        l = LineMetaData::find(52.52f, 13.40f, QStringLiteral("U11"), Line::Metro);
        QVERIFY(l.isNull());

        l = LineMetaData::find(52.52, 13.40, QStringLiteral("U1"), Line::Tramway);
        QVERIFY(l.isNull());
    }
};

QTEST_GUILESS_MAIN(LineMetaDataTest)

#include "linemetadatatest.moc"
