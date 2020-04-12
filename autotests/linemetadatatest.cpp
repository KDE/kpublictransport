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

class LineMetaDataTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testLookup()
    {
        auto l = LineMetaData::find(52.52, 13.40, QStringLiteral("U1"), Line::Metro);
        QVERIFY(!l.isNull());
        QCOMPARE(l.name(), QLatin1String("U1"));
        QCOMPARE(l.color(), QColor(0xff52b447));
        QCOMPARE(l.logoUrl().toString(QUrl::FullyEncoded), QLatin1String("https://commons.wikimedia.org/wiki/Special:Redirect/file/Berlin%20U1.svg"));
        QCOMPARE(l.mode(), Line::Metro);
        QCOMPARE(l.modeLogoUrl().toString(QUrl::FullyEncoded), QLatin1String("https://commons.wikimedia.org/wiki/Special:Redirect/file/U-Bahn.svg"));

        l = LineMetaData::find(52.52, 13.40,  QStringLiteral("S 7"), Line::RapidTransit);
        QVERIFY(!l.isNull());
        QCOMPARE(l.name(), QLatin1String("S7"));
        QVERIFY(!l.logoUrl().isEmpty());
        QCOMPARE(l.mode(), Line::RapidTransit);
        QCOMPARE(l.modeLogoUrl().toString(QUrl::FullyEncoded), QLatin1String("https://commons.wikimedia.org/wiki/Special:Redirect/file/S-Bahn-Logo.svg"));

        l = LineMetaData::find(52.52, 13.40,  QStringLiteral("S 7"), Line::Train);
        QVERIFY(!l.isNull());
        QCOMPARE(l.name(), QLatin1String("S7"));
        QCOMPARE(l.mode(), Line::RapidTransit);

        l = LineMetaData::find(48.13, 11.58,  QStringLiteral("S1"), Line::RapidTransit);
        QVERIFY(!l.isNull());
        QCOMPARE(l.name(), QLatin1String("S1"));
        QCOMPARE(l.mode(), Line::RapidTransit);
        QCOMPARE(l.logoUrl().toString(QUrl::FullyEncoded), QLatin1String("https://commons.wikimedia.org/wiki/Special:Redirect/file/M%C3%BCnchen%20S1.svg"));
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
