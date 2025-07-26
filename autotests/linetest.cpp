/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/Line>

#include <QTest>

#define s(x) QStringLiteral(x)

using namespace Qt::Literals;
using namespace KPublicTransport;

class LineTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testLineCompare_data()
    {
        QTest::addColumn<QString>("lhsModeName");
        QTest::addColumn<QString>("lhsName");
        QTest::addColumn<QString>("rhsModeName");
        QTest::addColumn<QString>("rhsName");

        QTest::newRow("identical") << s("S") << s("7") << s("S") << s("7");
        QTest::newRow("mode empty") << QString() << s("S7") << QString() << s("S7");
        QTest::newRow("mode only") << s("R") << QString() << s("R") << QString();

        QTest::newRow("space") << QString() << s("S7") << QString() << s("S 7");
        QTest::newRow("mode vs name") << s("RER") << s("A") << QString() << s("RER A");
        QTest::newRow("case folding") << s("RER") << s("A") << s("Rer") << s("A");

        QTest::newRow("missing mode") << s("Train") << s("A") << QString() << s("A");
        QTest::newRow("line vs train") << QString() << s("S7") << QString() << s("S 7 (Train no.123465)");

        QTest::newRow("prefix") << s("R") << s("123") << s("R") << QString();
        QTest::newRow("suffix") << QString() << s("Bus X7") << QString() << s("X7");

        QTest::newRow("unicode") << QString() << s("〇") << QString() << s("〇");

        QTest::newRow("special char") << QString() << s("<6>") << QString() << s("<6>");

        QTest::newRow("TGV INOUI") << QString() << s("TGV INOUI 8501") << QString() << s("TGV 8501");

        QTest::newRow("ic-name-suffic") << QString() << u"IC 19792"_s << QString() << u"IC 19792 KÉK HULLÁM"_s;
    }

    void testLineCompare()
    {
        QFETCH(QString, lhsModeName);
        QFETCH(QString, lhsName);
        QFETCH(QString, rhsModeName);
        QFETCH(QString, rhsName);

        Line l, r;
        l.setModeString(lhsModeName);
        l.setName(lhsName);
        r.setModeString(rhsModeName);
        r.setName(rhsName);
        QVERIFY(Line::isSame(l, r));
        QVERIFY(Line::isSame(r, l));
    }

    void testLineCompareNegative_data()
    {
        QTest::addColumn<QString>("lhsModeName");
        QTest::addColumn<QString>("lhsName");
        QTest::addColumn<QString>("rhsModeName");
        QTest::addColumn<QString>("rhsName");

        QTest::newRow("mismatch") << s("S") << s("7") << s("S") << s("5");
        QTest::newRow("non-separated prefix") << QString() << s("S7") << QString() << s("S75");
        QTest::newRow("non-separated suffix") << QString() << s("7") << QString() << s("S47");
    }

    void testLineCompareNegative()
    {
        QFETCH(QString, lhsModeName);
        QFETCH(QString, lhsName);
        QFETCH(QString, rhsModeName);
        QFETCH(QString, rhsName);

        Line l, r;
        l.setModeString(lhsModeName);
        l.setName(lhsName);
        r.setModeString(rhsModeName);
        r.setName(rhsName);
        QVERIFY(!Line::isSame(l, r));
        QVERIFY(!Line::isSame(r, l));
    }

    void testLineNameMerge_data()
    {
        QTest::addColumn<QString>("lhsModeName");
        QTest::addColumn<QString>("lhsName");
        QTest::addColumn<QString>("rhsModeName");
        QTest::addColumn<QString>("rhsName");
        QTest::addColumn<QString>("resModeName");
        QTest::addColumn<QString>("resName");

        QTest::newRow("identical") << s("S") << s("7") << s("S") << s("7") << s("S") << s("7");
        QTest::newRow("space") << QString() << s("S7") << QString() << s("S 7") << QString() << s("S 7");
        QTest::newRow("line vs vehicle") << QString() << s("RB 14") << QString() << s("RB 12345") << QString() << s("RB 12345");

        QTest::newRow("mode vs name") << s("Bus") << s("X7") << QString() << s("Bus X7") << s("Bus") << s("X7");
    }

    void testLineNameMerge()
    {
        QFETCH(QString, lhsModeName);
        QFETCH(QString, lhsName);
        QFETCH(QString, rhsModeName);
        QFETCH(QString, rhsName);
        QFETCH(QString, resModeName);
        QFETCH(QString, resName);

        Line l, r;
        l.setModeString(lhsModeName);
        l.setName(lhsName);
        r.setModeString(rhsModeName);
        r.setName(rhsName);

        const auto mergeL2R = Line::merge(l, r);
        QCOMPARE(mergeL2R.modeString(), resModeName);
        QCOMPARE(mergeL2R.name(), resName);

        const auto mergeR2L = Line::merge(r, l);
        QCOMPARE(mergeR2L.modeString(), resModeName);
        QCOMPARE(mergeR2L.name(), resName);
    }

    void testLineModeMerge_data()
    {
        QTest::addColumn<Line::Mode>("lhsMode");
        QTest::addColumn<Line::Mode>("rhsMode");
        QTest::addColumn<Line::Mode>("mergedMode");

        QTest::newRow("identical") << Line::Train << Line::Train << Line::Train;
        QTest::newRow("local train") << Line::LocalTrain << Line::Train << Line::LocalTrain;
        QTest::newRow("long distance train") << Line::LongDistanceTrain << Line::Train << Line::LongDistanceTrain;
        QTest::newRow("one unknown") << Line::Unknown << Line::Train << Line::Train;
    }

    void testLineModeMerge()
    {
        QFETCH(Line::Mode, lhsMode);
        QFETCH(Line::Mode, rhsMode);
        QFETCH(Line::Mode, mergedMode);

        Line l, r;
        l.setMode(lhsMode);
        r.setMode(rhsMode);

        QVERIFY(Line::isSame(l, r));
        QVERIFY(Line::isSame(r, l));
        QCOMPARE(Line::merge(l, r).mode(), mergedMode);
        QCOMPARE(Line::merge(r, l).mode(), mergedMode);
    }
};

QTEST_GUILESS_MAIN(LineTest)

#include "linetest.moc"
