/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <map/loader/levelparser_p.h>

#include <osm/element.h>

#include <QTest>

using namespace KOSMIndoorMap;

class LevelParserTest: public QObject
{
    Q_OBJECT
    using LV = QVector<int>;
private Q_SLOTS:
    void testLevelParse_data()
    {
        QTest::addColumn<QString>("input");
        QTest::addColumn<LV>("levels");

        QTest::newRow("empty") << "" << LV{};
        QTest::newRow("0") << "0" << LV{0};
        QTest::newRow("1") << "1" << LV{10};
        QTest::newRow("-1") << "-1" << LV{-10};

        QTest::newRow("-1;0") << "-1;0" << LV{-10,0};
        QTest::newRow("0.5") << "0.5" << LV{5};
        QTest::newRow("0.5;0.7") << "0.5;0.7" << LV{5,7};
        QTest::newRow("0;-1") << "0;-1" << LV{0,-10};

        QTest::newRow("1-3") << "1-3" << LV{10,20,30};
        QTest::newRow("-1-5") << "-1-5" << LV{-10,0,10,20,30,40,50};
        QTest::newRow("-4--2") << "-4--2" << LV{-40,-30,-20};
        QTest::newRow("0-6") << "0-6" << LV{0,10,20,30,40,50,60};

        QTest::newRow("0;2-3") << "0;2-3" << LV{0,20,30};
        QTest::newRow("0;2-3;5") << "0;2-3;5" << LV{0,20,30,50};

        // invalid but we have workarounds for this
        QTest::newRow("1,5") << "1,5" << LV{15};
    }

    void testLevelParse()
    {
        QFETCH(QString, input);
        QFETCH(LV, levels);

        OSM::Element e;
        LV result;
        LevelParser::parse(input.toUtf8(), e, [&result](int level, OSM::Element e) {
            Q_UNUSED(e);
            result.push_back(level);
        });

        if (result != levels) {
            qDebug() << result << levels;
        }
        QCOMPARE(result, levels);
    }
};

QTEST_GUILESS_MAIN(LevelParserTest)

#include "levelparsertest.moc"
