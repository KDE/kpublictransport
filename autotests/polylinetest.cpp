/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <geo/polylinedecoder_p.h>

#include <QTest>

#include <iostream>

using namespace KPublicTransport;

class PolylineDecoderTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testDecode()
    {
        PolylineDecoder<2> decoder("_p~iF~ps|U_ulLnnqC_mqNvxq`@");

        QCOMPARE(decoder.canReadMore(), true);
        QCOMPARE(decoder.readNextDouble(), 38.5);
        QCOMPARE(decoder.canReadMore(), true);
        QCOMPARE(decoder.readNextDouble(), -120.2);
        QCOMPARE(decoder.canReadMore(), true);
        QCOMPARE(decoder.readNextDouble(), 40.7);
        QCOMPARE(decoder.canReadMore(), true);
        QCOMPARE(decoder.readNextDouble(), -120.95);
        QCOMPARE(decoder.canReadMore(), true);
        QCOMPARE(decoder.readNextDouble(), 43.252);
        QCOMPARE(decoder.canReadMore(), true);
        QCOMPARE(decoder.readNextDouble(), -126.453);
        QCOMPARE(decoder.canReadMore(), false);
    }

    void testEmpty()
    {
        PolylineDecoder<2> decoder("");
        QCOMPARE(decoder.canReadMore(), false);
    }

    void testZero()
    {
        PolylineDecoder<1> decoder("???");
        QCOMPARE(decoder.canReadMore(), true);
        QCOMPARE(decoder.readNextInt(), 0);
        QCOMPARE(decoder.readNextDouble(), 0.0);
        QCOMPARE(decoder.readNextDouble(), 0.0);
        QCOMPARE(decoder.canReadMore(), false);
    }

    void testNonDifferential()
    {
        PolylineDecoder<1, false>  decoder("NL");
        QCOMPARE(decoder.canReadMore(), true);
        QCOMPARE(decoder.readNextInt(), -8);
        QCOMPARE(decoder.readNextInt(), -7);
        QCOMPARE(decoder.canReadMore(), false);
    }

#if 0
    void dumpEncoded() // mostly for manual testing
    {
        PolylineDecoder<1> decoder("?cAclA}K{P?gTwE?e@qNyMuEiWmVyNgAuBgAyJqHy[{MsQeWM?eF");
        while (decoder.canReadMore()) {
            for (int i = 0; i < decoder.dimensions(); ++i) {
                std::cout << decoder.readNextDouble() << " ";
            }
            std::cout << std::endl;
        }
    }
#endif
};

QTEST_GUILESS_MAIN(PolylineDecoderTest)

#include "polylinetest.moc"
