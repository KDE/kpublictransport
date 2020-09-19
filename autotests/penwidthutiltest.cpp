/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <map/scene/penwidthutil.h>
#include <map/style/mapcssdeclaration.h>
#include <osm/element.h>

#include <QTest>

using namespace KOSMIndoorMap;

Q_DECLARE_METATYPE(KOSMIndoorMap::Unit)

class PenWidthUtilTest: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void penWidthExplicit_data()
    {
        QTest::addColumn<double>("cssValue");
        QTest::addColumn<QString>("cssUnit");
        QTest::addColumn<double>("expectedWidth");
        QTest::addColumn<Unit>("expectedUnit");

        QTest::newRow("none") << 42.0 << QString() << 42.0 << Unit::Pixel;
        QTest::newRow("css meter") << 42.0 << "m" << 42.0 << Unit::Meter;
        QTest::newRow("css px") << 42.0 << "px" << 42.0 << Unit::Pixel;
    }
    void penWidthExplicit()
    {
        QFETCH(double, cssValue);
        QFETCH(QString, cssUnit);
        QFETCH(double, expectedWidth);
        QFETCH(Unit, expectedUnit);

        MapCSSDeclaration decl;
        decl.setDoubleValue(cssValue);
        if (!cssUnit.isEmpty()) {
            decl.setUnit(qPrintable(cssUnit), cssUnit.size());
        }

        OSM::Node n;
        Unit resultUnit;
        const auto result = PenWidthUtil::penWidth(OSM::Element(&n), &decl, resultUnit);
        QCOMPARE(result, expectedWidth);
        QCOMPARE(resultUnit, expectedUnit);
    }

    void penWidthFromTagTest_data()
    {
        QTest::addColumn<QString>("keyName");
        QTest::addColumn<QString>("tagValue");
        QTest::addColumn<double>("expectedWidth");
        QTest::addColumn<Unit>("penUnit");

        QTest::newRow("meter explicit") << "width" << "42m" << 42.0 << Unit::Meter;
        QTest::newRow("meter implicit") << "width" << "42" << 42.0 << Unit::Meter;
        QTest::newRow("feet 1") << "width" << "42ft" << 12.8016 << Unit::Meter;
        QTest::newRow("feet 2") << "width" << "42 ft" << 12.8016 << Unit::Meter;
        QTest::newRow("implicit mm") << "gauge" << "1435" << 1.435 << Unit::Meter;
        QTest::newRow("gauge explicit") << "gauge" << "1m" << 1.0 << Unit::Meter;
        QTest::newRow("multi gauge") << "gauge" << "1000;1435" << 1.435 << Unit::Meter;
    }

    void penWidthFromTagTest()
    {
        QFETCH(QString, keyName);
        QFETCH(QString, tagValue);
        QFETCH(double, expectedWidth);
        QFETCH(Unit, penUnit);

        OSM::DataSet dataSet;
        const auto tagKey = dataSet.makeTagKey(qPrintable(keyName));
        OSM::Node node;
        node.id = -1;
        OSM::setTagValue(node, tagKey, tagValue.toUtf8());

        MapCSSDeclaration decl;
        decl.setPropertyName("width", 5);
        decl.setIdentifierValue(qPrintable(keyName), keyName.size());
        decl.compile(dataSet);

        Unit resultUnit;
        const auto w = PenWidthUtil::penWidth(OSM::Element(&node), &decl, resultUnit);
        QEXPECT_FAIL("multi gauge", "not correctly parsed yet", Continue);
        QCOMPARE(w, expectedWidth);
        QCOMPARE(penUnit, resultUnit);
    }
};

QTEST_GUILESS_MAIN(PenWidthUtilTest)

#include "penwidthutiltest.moc"
