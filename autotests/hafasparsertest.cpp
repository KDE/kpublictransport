/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backends/hafasparser.h"

#include <KPublicTransport/Location>

#include <qtest.h>

using namespace Qt::Literals;
using namespace KPublicTransport;

class TestHafasParser : public HafasParser {};

class HafasParserTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testParseoLocationIdentifier()
    {
        TestHafasParser p;
        p.setLocationIdentifierTypes(u"test"_s, u"ibnr"_s);
        p.setStandardLocationIdentfierCountries({80, 81, 82});

        auto loc = p.fromLocationId(u"A=1@O=Berlin Hbf@X=13369549@Y=52525589@L=8098160@a=128@"_s);
        QCOMPARE(loc.type(), Location::Stop);
        QCOMPARE(loc.name(), "Berlin Hbf"_L1);
        QCOMPARE(loc.latitude(), 52.525589);
        QCOMPARE(loc.longitude(), 13.369549);
        QCOMPARE(loc.identifier(u"ibnr"_s), "8098160"_L1);
        QCOMPARE(loc.identifier(u"hafas"_s), "A=1@O=Berlin Hbf@X=13369549@Y=52525589@L=8098160@a=128@"_L1);

        loc = p.fromLocationId(u"A=1@O=Hamburg Hbf@X=10006909@Y=53552733@U=80@L=8002549@B=1@p=1733178662@i=U×008001071@"_s);
        QCOMPARE(loc.type(), Location::Stop);
        QCOMPARE(loc.name(), "Hamburg Hbf"_L1);
        QCOMPARE(loc.hasCoordinate(), true);
        QCOMPARE(loc.identifier(u"uic"_s), "8001071"_L1);

        loc = p.fromLocationId(u"A=2@O=Berlin - Kreuzberg, Prinzenstraße 84@H=84@X=13410225@Y=52503062@U=92@L=980131297@"_s);
        QCOMPARE(loc.type(), Location::Address);
        QCOMPARE(loc.name(), u"Berlin - Kreuzberg, Prinzenstraße 84");
        QCOMPARE(loc.hasCoordinate(), true);
        QCOMPARE(loc.identifier(u"ibnr"_s), QString());

        loc = p.fromLocationId(u"A=4@O=Berlin, Ming Dynastie (Gastronomie)@X=13417713@Y=52513598@U=91@L=991524662@"_s);
        QCOMPARE(loc.type(), Location::Place); // POI
        QCOMPARE(loc.name(), "Berlin, Ming Dynastie (Gastronomie)"_L1);
        QCOMPARE(loc.hasCoordinate(), true);
        QCOMPARE(loc.identifier(u"ibnr"_s), QString());
    }
};

QTEST_GUILESS_MAIN(HafasParserTest)

#include "hafasparsertest.moc"
