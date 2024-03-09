/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../src/lib/datatypes/featureutil.cpp"

#include <QTest>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

class FeatureTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testMerge()
    {
        std::vector<Feature> f1s = { Feature{ Feature::AirConditioning, Feature::Available }, Feature{ Feature::WiFi, Feature::Conditional } };
        std::vector<Feature> f2s = { Feature{ Feature::AirConditioning, Feature::Unknown }, Feature{ Feature::WiFi, Feature::Available } };
        auto fs = FeatureUtil::merge(f1s, f2s);
        QCOMPARE(fs.size(), 2);
        QCOMPARE(fs[0].type(), Feature::AirConditioning);
        QCOMPARE(fs[0].availability(), Feature::Available);
        QCOMPARE(fs[1].type(), Feature::WiFi);
        QCOMPARE(fs[1].availability(), Feature::Conditional);

        f1s = { Feature{ Feature::Restaurant, Feature::Available }, Feature{ Feature::InformationPoint, Feature::Limited } };
        f2s = { Feature{ Feature::AirConditioning, Feature::Unknown }, Feature{ Feature::WiFi, Feature::Available } };
        fs = FeatureUtil::merge(f1s, f2s);
        QCOMPARE(fs.size(), 4);
        QCOMPARE(fs[0].type(), Feature::AirConditioning);
        QCOMPARE(fs[0].availability(), Feature::Unknown);
        QCOMPARE(fs[1].type(), Feature::Restaurant);
        QCOMPARE(fs[1].availability(), Feature::Available);
        QCOMPARE(fs[2].type(), Feature::InformationPoint);
        QCOMPARE(fs[2].availability(), Feature::Limited);
        QCOMPARE(fs[3].type(), Feature::WiFi);
        QCOMPARE(fs[3].availability(), Feature::Available);

        Feature f1{ Feature::Other, Feature::Unknown };
        f1.setName(u"somefeature"_s);
        Feature f2{ Feature::Other, Feature::Available };
        f2.setName(u"SOMEFEATURE"_s);
        f2.setDescription(u"This explains what this feature is."_s);
        fs = FeatureUtil::merge({ f1 }, { f2 });
        QCOMPARE(fs.size(), 1);
        QCOMPARE(fs[0].type(), Feature::Other);
        QCOMPARE(fs[0].availability(), Feature::Available);
        QVERIFY(!fs[0].name().isEmpty());
        QVERIFY(!fs[0].description().isEmpty());
    }
};

QTEST_GUILESS_MAIN(FeatureTest)

#include "featuretest.moc"
