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
        Unit resultUnit = Unit::Pixel;
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
        QTest::newRow("multi gauge 2") << "gauge" << "1435;1000" << 1.435 << Unit::Meter;
        QTest::newRow("cm") << "width" << "100 cm" << 1.0 << Unit::Meter;
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
        QCOMPARE(w, expectedWidth);
        QCOMPARE(penUnit, resultUnit);
    }

    void penWidthFromTagErrors_data()
    {
        QTest::addColumn<QString>("tagValue");

        QTest::newRow("empty") << QString();
        QTest::newRow("non-number") << "foo";
        QTest::newRow("unit only") << "ft";
    }

    void penWidthFromTagErrors()
    {
        QFETCH(QString, tagValue);

        OSM::DataSet dataSet;
        const auto tagKey = dataSet.makeTagKey("width");
        OSM::Node node;
        node.id = -1;
        OSM::setTagValue(node, tagKey, tagValue.toUtf8());

        MapCSSDeclaration decl;
        decl.setPropertyName("width", 5);
        decl.setIdentifierValue("width", 5);
        decl.compile(dataSet);

        Unit resultUnit;
        const auto w = PenWidthUtil::penWidth(OSM::Element(&node), &decl, resultUnit);
        QCOMPARE(w, 0.0);
    }
};

QTEST_GUILESS_MAIN(PenWidthUtilTest)

#include "penwidthutiltest.moc"
