/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <knowledgedb/linemetadata.h>

#include <QObject>
#include <QTest>

using namespace Qt::Literals;
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

        QTest::newRow("Berlin U1") << 52.52 << 13.40 << u"U1"_s << Line::Metro << QColor(0xff7dad4c) << u"Berlin%20transit%20icons%20-%20U1.svg"_s << u"U-Bahn.svg"_s;
        QTest::newRow("Berlin S7") << 52.52 << 13.40 << s("S7") << Line::RapidTransit << QColor(0xff8070b7) << s("Berlin%20transit%20icons%20-%20S7.svg") << s("S-Bahn-Logo.svg");
        QTest::newRow("Berlin FEX") << 52.52 << 13.40 << s("FEX") << Line::LocalTrain << QColor() << s("FEX%20VBB%20(2021).png") << QString();
        QTest::newRow("Berlin RE1") << 52.52 << 13.40 << s("RE1") << Line::LocalTrain << QColor(0xffff0000) << s("RE1%20VBB%20(2021).png") << QString();
        QTest::newRow("Munich S1") << 48.13 << 11.58 << s("S1") << Line::RapidTransit << QColor(0xff36caec) << s("M%C3%BCnchen%20S1.svg") << s("S-Bahn-Logo.svg");
        QTest::newRow("Munich S3") << 48.13 << 11.58 << s("S3") << Line::RapidTransit << QColor(0xff862996) << s("M%C3%BCnchen%20S3.svg") << s("S-Bahn-Logo.svg");
        QTest::newRow("Munich U3") << 48.13 << 11.58 << s("U3") << Line::Metro << QColor(0xffe66432) << s("M%C3%BCnchen%20U3.svg") << s("U-Bahnlogo%20M%C3%BCnchen.svg");
        QTest::newRow("Nurnberg S2") << 49.44 << 11.08 << s("S2") << Line::RapidTransit << QColor(0xff65b949) << QString() << s("S-Bahn-Logo.svg");
        QTest::newRow("Nurnberg U2") << 49.44 << 11.08 << s("U2") << Line::Metro << QColor(0xffff0000) << s("N%C3%BCrnberg%20U2.svg") << s("U-Bahn.svg");
        QTest::newRow("Nurnberg tram 5") << 49.44 << 11.08 << u"5"_s << Line::Tramway << QColor(0xff8b539d) << u"N%C3%BCrnberg%20T5.png"_s << u"Tram%20N%C3%BCrnberg%20Logo.png"_s;
        QTest::newRow("Frankfurt U8") << 50.1 << 8.66 << s("U8") << Line::Metro << QColor(0xffc77db5) << s("Frankfurt%20U8.svg") << s("U-Bahn.svg");
        QTest::newRow("Brussels 2") << 50.83 << 4.33 << s("2") << Line::Metro << QColor(0xffed6c23) << s("STIB-MIVB%20Line%202.svg") << s("Brussels%20Metro%20Logo.svg");
        QTest::newRow("Brussels 82") << 50.83 << 4.33 << s("82") << Line::Tramway << QColor(0xff91bee7) << s("STIB-MIVB%20Line%2082.svg") << s("Brussels%20tramway%20icon.svg");
        QTest::newRow("Brussels S6") << 50.83 << 4.33 << s("S6") << Line::RapidTransit << QColor(0xff965f26) << QString() << s("NMBS%20S-Trein%20logo.svg");
        QTest::newRow("Brussels S10") << 50.83 << 4.33 << s("S10") << Line::RapidTransit << QColor(0xff000000) << QString() << s("NMBS%20S-Trein%20logo.svg");
        QTest::newRow("Paris RER C") << 48.84 << 2.37 << s("C") << Line::RapidTransit << QColor(0xfffcd946) << s("Paris%20transit%20icons%20-%20RER%20C.svg") << s("Paris%20transit%20icons%20-%20RER.svg");
        QTest::newRow("Paris RER D") << 48.84 << 2.37 << u"D"_s << Line::RapidTransit << QColor(0xff00824e) << u"Paris%20transit%20icons%20-%20RER%20D.svg"_s << u"Paris%20transit%20icons%20-%20RER.svg"_s;
        QTest::newRow("Paris Metro 1") << 48.84 << 2.37 << u"1"_s << Line::Metro << QColor(0xffffbe00) << u"Paris%20transit%20icons%20-%20M%C3%A9tro%201.svg"_s << u"Paris%20transit%20icons%20-%20M%C3%A9tro.svg"_s;
        QTest::newRow("Paris tram 1") << 48.84 << 2.37 << s("T1") << Line::Tramway << QColor(0xff216eb4) << s("Paris%20transit%20icons%20-%20Tram%201.svg") << s("Paris%20transit%20icons%20-%20Tram.svg");
        QTest::newRow("Milano M5") << 45.48 << 9.18 << s("M5") << Line::Metro << QColor(0xffb395d0) << s("Milano%20linea%20M5.svg") << s("Logo%20Metropolitane%20Italia.svg");
        QTest::newRow("Milano S1") << 45.48 << 9.18 << u"S1"_s << Line::RapidTransit << QColor(0xffee333e) << u"Milano%20S1.svg"_s << u"Linee%20S%20di%20Milano.svg"_s;
        QTest::newRow("Hannover S1") << 52.37 << 9.74 << s("S1") << Line::RapidTransit << QColor(0xff7760b0) << s("Hannover%20S1.svg") << s("S-Bahn-Logo.svg");
        QTest::newRow("Magdeburg S1") << 52.13 << 11.62 << s("S 1") << Line::RapidTransit << QColor(0xff408040) << QString() << s("S-Bahn-Logo.svg");
        QTest::newRow("Magdeburg 1") << 52.13 << 11.62 << s("1") << Line::Tramway << QColor(0xffb6005c) << s("Magdeburg%20Tram%201%20(2021).png") << QString();
        QTest::newRow("Vienna U1") << 48.18 << 16.37 << s("U1") << Line::Metro << QColor(0xffe20613) << s("Wien%20U1.svg") << s("U-Bahn%20Wien.svg");
        QTest::newRow("Vienna S1") << 48.18 << 16.37 << s("S1") << Line::RapidTransit << QColor(0xff159dd9) << s("S1%20Wien.svg") << s("S-Bahn%20Wien.svg");
        QTest::newRow("Hamburg U1") << 53.55 << 10.0 << s("U1") << Line::Metro << QColor(0xff0066b3) << s("Hamburg%20U1.svg") << s("U-Bahn.svg");
        QTest::newRow("Hamburg S1") << 53.55 << 10.0 << s("S1") << Line::RapidTransit << QColor(0xff33b540) << s("Hamburg%20S1.svg") << s("S-Bahn-Logo.svg");
        QTest::newRow("Copenhagen A") << 55.67 << 12.56 << s("A") << Line::RapidTransit << QColor(0xff00bfff) << s("S-train%20service%20A.svg") << s("S-tog.svg");
        QTest::newRow("Cologne S11") << 50.94 << 6.97 << s("S11") << Line::RapidTransit << QColor(0xffef7c00) << s("NRW%20S11.svg") << s("S-Bahn-Logo.svg");
        QTest::newRow("Stuttgart S1") << 48.78 << 9.18 << s("S1") << Line::RapidTransit << QColor(0xff5c8e3c) << s("S1%20S-Bahn%20Stuttgart%20Logo%20(2021).svg") << s("S-Bahn-Logo.svg");
        QTest::newRow("Stuttgart U6") << 48.78 << 9.18 << s("U6") << Line::RapidTransit << QColor(0xffec008c) << u"Stuttgart%20U6.svg"_s << u"Logo%20Stadtbahn%20Stuttgart.svg"_s;
        QTest::newRow("Barcelona L1") << 41.37 << 2.13 << s("L1") << Line::Metro << QColor(0xffe33638) << s("L1%20barcelona.svg") << s("Barcelona%20Metro%20Logo.svg");
        QTest::newRow("Toulouse Metro A") << 43.6 << 1.44 << s("A") << Line::Metro << QColor(0xffdb001b) << s("Toulouse%20line%20A%20symbol.svg") << s("Toulouse%20%22M%22%20symbol.svg");
        QTest::newRow("San Francisco BART Yellow") << 37.77 << -122.41 << s("Yellow") << Line::Metro << QColor(0xffffe800) << QString() << s("Bart-logo.svg");
        QTest::newRow("Augsburg tram 3") << 48.33 << 10.89 << s("3") << Line::Tramway << QColor(0xffef7c00) << s("Augsburg%20Tram%203.svg") << QString();
        QTest::newRow("Oslo T-Bane 4") << 59.94 << 10.76 << s("4") << Line::Metro << QColor(0xff0054a6) << s("Oslo%20Metro%204.svg") << s("Oslo%20T-bane%20Logo.svg");
        QTest::newRow("Oslo tram 12") << 59.94 << 10.76 << s("12") << Line::Tramway << QColor(0xffa166aa) << s("Oslo%20Tramway%20new%2012.svg") << QString();
        QTest::newRow("Prague C") << 50.07 << 14.47 << u"C"_s << Line::Metro << QColor(0xffcf003d) << u"Linka%20C%20(Praha).svg"_s << u"Prague%20metro%20logo%20without%20padding.svg"_s;
        QTest::newRow("Bonn tram 61") << 50.73 << 7.1 << u"61"_s << Line::Tramway << QColor(0xff98c000) << QString() << QString();
        QTest::newRow("Rome Metro A") << 41.8989 << 12.5089 << s("A") << Line::Metro << QColor(0xfff68b1f) << s("Metropolitana%20di%20Roma%20-%20logo%20linea%20A.svg") << s("Logo%20Metropolitane%20Italia.svg");
        QTest::newRow("Gotenburg tram 6") << 57.7 << 11.96 << s("6") << Line::Tramway << QColor(0xfffa8719) << s("Sp%C3%A5rvagnslinje%206.svg") << QString();
        QTest::newRow("Amsterdam line 54") << 52.37 << 4.9 << u"54"_s << Line::Metro << QColor(0xfffcfb05) << u"Amsterdam%20transit%20icons%20-%20Metro%2054.svg"_s << u"Amsterdam%20metro%20logo.svg"_s;
        QTest::newRow("Thessaloniki metro 2") << 40.64 << 22.93 << s("2") << Line::Metro << QColor(0xff0070ff) << s("Thessaloniki%20Metro%20Line%202.svg") << QString();
        QTest::newRow("Graz S5") <<  47.1 << 15.4 << s("S5") << Line::RapidTransit << QColor(0xff8d1d81) << s("S5%20Steiermark.svg") << s("S-Bahn%20Austria.svg");
        QTest::newRow("Zurich IC 1") << 47.37 << 8.54 << s("IC 1") << Line::LongDistanceTrain << QColor(0xffe43d2e) << s("IC%201%20logo.svg") << QString();
        QTest::newRow("Wuerzburg Tram 1") << 49.80 << 9.93 << u"1"_s << Line::Tramway << QColor(0xffffbb00) << QString() << QString();
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
        auto l = LineMetaData::find(52.52, 13.40,  QStringLiteral("S 7"), Line::Train);
        QVERIFY(!l.isNull());
        QCOMPARE(l.name(), QLatin1String("S7"));
        QCOMPARE(l.mode(), Line::RapidTransit);

        // Stuttgart U-Bahn has ambiguities on its mode (tram/metro/rapidtransit)
        l = LineMetaData::find(48.78, 9.18,  QStringLiteral("U 6"), Line::Tramway);
        QVERIFY(!l.isNull());
        QCOMPARE(l.name(), QLatin1String("U6"));
        QVERIFY(l.color().isValid());
        QVERIFY(!l.logoUrl().isEmpty());
    }

    void testNegativeLookup()
    {
        auto l = LineMetaData::find(0.0f, -89.0, QStringLiteral("U1"), Line::Metro);
        QVERIFY(l.isNull());

        l = LineMetaData::find(52.52f, 13.40f, QStringLiteral("U11"), Line::Metro);
        QVERIFY(l.isNull());

        l = LineMetaData::find(52.52, 13.40, QStringLiteral("U1"), Line::Bus);
        QVERIFY(l.isNull());
    }
};

QTEST_GUILESS_MAIN(LineMetaDataTest)

#include "linemetadatatest.moc"
