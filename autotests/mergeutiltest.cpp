/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../src/lib/datatypes/mergeutil.cpp"

#include <QDateTime>
#include <QTest>
#include <QTimeZone>

using namespace KPublicTransport;

class MergeUtilTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC-8"); // something far away from the test data, to be sure local TZ doesn't interfere
    }

    void testDateTimeDistance_data()
    {
        QTest::addColumn<QDateTime>("lhs");
        QTest::addColumn<QDateTime>("rhs");
        QTest::addColumn<int>("dist");

        QTest::newRow("empty") << QDateTime() << QDateTime() << 0;
        QTest::newRow("local vs tz eq") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul")) << 0;
        QTest::newRow("local vs tz diff") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime({1970, 1, 1}, {13, 23}, QTimeZone("Asia/Seoul")) << 3600;
        QTest::newRow("local vs offset eq") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone::fromSecondsAheadOfUtc(7200)) << 0;
        QTest::newRow("local vs offset diff") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime({1970, 1, 1}, {13, 23}, QTimeZone::fromSecondsAheadOfUtc(7200)) << 3600;
        QTest::newRow("offset vs tz eq") << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone::fromSecondsAheadOfUtc(9 * 3600)) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul")) << 0;
        QTest::newRow("offset vs tz diff") << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone::fromSecondsAheadOfUtc(9 * 3600)) << QDateTime({1970, 1, 1}, {13, 23}, QTimeZone("Asia/Seoul")) << 3600;
    }

    void testDateTimeDistance()
    {
        QFETCH(QDateTime, lhs);
        QFETCH(QDateTime, rhs);
        QFETCH(int, dist);

        QCOMPARE(MergeUtil::distance(lhs, rhs), dist);
        QCOMPARE(MergeUtil::distance(rhs, lhs), dist);

        QCOMPARE(MergeUtil::isBefore(lhs, rhs), dist > 0);
        QCOMPARE(MergeUtil::isBefore(rhs, lhs), dist < 0);
    }

    void testDateTimeMerge_data()
    {
        QTest::addColumn<QDateTime>("lhs");
        QTest::addColumn<QDateTime>("rhs");
        QTest::addColumn<QDateTime>("result");

        QTest::newRow("empty") << QDateTime() << QDateTime() << QDateTime();
        QTest::newRow("invalid") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime() << QDateTime({1970, 1, 1}, {12, 23});
        QTest::newRow("local vs tz") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul")) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul"));
        QTest::newRow("local vs offset") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone::fromSecondsAheadOfUtc(7200)) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone::fromSecondsAheadOfUtc(7200));
        QTest::newRow("offset vs tz") << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone::fromSecondsAheadOfUtc(9 * 3600)) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul")) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul"));
    }

    void testDateTimeMerge()
    {
        QFETCH(QDateTime, lhs);
        QFETCH(QDateTime, rhs);
        QFETCH(QDateTime, result);

        QCOMPARE(MergeUtil::mergeDateTimeEqual(lhs, rhs), result);
        QCOMPARE(MergeUtil::mergeDateTimeEqual(rhs, lhs), result);
    }

    void testDateTimeMax_data()
    {
        QTest::addColumn<QDateTime>("lhs");
        QTest::addColumn<QDateTime>("rhs");
        QTest::addColumn<QDateTime>("result");

        QTest::newRow("empty") << QDateTime() << QDateTime() << QDateTime();
        QTest::newRow("invalid") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime() << QDateTime({1970, 1, 1}, {12, 23});
        QTest::newRow("local vs tz eq") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul")) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul"));
        QTest::newRow("local vs tz gt") << QDateTime({1970, 1, 1}, {14, 23}) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul")) << QDateTime({1970, 1, 1}, {14, 23}, QTimeZone("Asia/Seoul"));
        QTest::newRow("local vs tz lt") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime({1970, 1, 1}, {14, 23}, QTimeZone("Asia/Seoul")) << QDateTime({1970, 1, 1}, {14, 23}, QTimeZone("Asia/Seoul"));
        QTest::newRow("local vs offset eq") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone::fromSecondsAheadOfUtc(7200)) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone::fromSecondsAheadOfUtc(7200));
        QTest::newRow("local vs offset gt") << QDateTime({1970, 1, 1}, {15, 23}) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone::fromSecondsAheadOfUtc(7200)) << QDateTime({1970, 1, 1}, {15, 23}, QTimeZone::fromSecondsAheadOfUtc(7200));
        QTest::newRow("local vs offset lt") << QDateTime({1970, 1, 1}, {12, 23}) << QDateTime({1970, 1, 1}, {15, 23}, QTimeZone::fromSecondsAheadOfUtc(7200)) << QDateTime({1970, 1, 1}, {15, 23}, QTimeZone::fromSecondsAheadOfUtc(7200));
        QTest::newRow("offset vs tz eq") << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone::fromSecondsAheadOfUtc(9 * 3600)) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul")) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul"));
        QTest::newRow("offset vs tz gt") << QDateTime({1970, 1, 1}, {14, 23}, QTimeZone::fromSecondsAheadOfUtc(9 * 3600)) << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone("Asia/Seoul")) << QDateTime({1970, 1, 1}, {14, 23}, QTimeZone("Asia/Seoul"));
        QTest::newRow("offset vs tz lt") << QDateTime({1970, 1, 1}, {12, 23}, QTimeZone::fromSecondsAheadOfUtc(9 * 3600)) << QDateTime({1970, 1, 1}, {14, 23}, QTimeZone("Asia/Seoul")) << QDateTime({1970, 1, 1}, {14, 23}, QTimeZone("Asia/Seoul"));
    }

    void testDateTimeMax()
    {
        QFETCH(QDateTime, lhs);
        QFETCH(QDateTime, rhs);
        QFETCH(QDateTime, result);

        QCOMPARE(MergeUtil::mergeDateTimeMax(lhs, rhs), result);
        QCOMPARE(MergeUtil::mergeDateTimeMax(rhs, lhs), result);
    }
};

QTEST_GUILESS_MAIN(MergeUtilTest)

#include "mergeutiltest.moc"
