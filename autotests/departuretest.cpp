/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"

#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class DepartureTest : public QObject
{
    Q_OBJECT
private:
    QByteArray readFile(const QString &fn) const
    {
        QFile f(fn);
        f.open(QFile::ReadOnly);
        return f.readAll();
    }

private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "Europe/Helsinki"); // something exotic, ie. something not used in the test data
        qRegisterMetaType<Disruption::Effect>();
    }

    void testDepartureMerge_data()
    {
        QTest::addColumn<QString>("baseName");

        QDir dir(QStringLiteral(SOURCE_DIR "/data/departures"));
        const auto lst = dir.entryList(QStringList(QStringLiteral("*.merged.json")), QDir::Files | QDir::Readable | QDir::NoSymLinks);
        for (const auto &file : lst) {
            const auto base = file.left(file.size() - 12);
            QTest::newRow(base.toLatin1().constData()) << (dir.path() + QLatin1Char('/') + base);
        }
    }

    void testDepartureMerge()
    {
        QFETCH(QString, baseName);

        const auto lhs = Stopover::fromJson(QJsonDocument::fromJson(readFile(baseName + QLatin1String(".lhs.json"))).object());
        const auto rhs = Stopover::fromJson(QJsonDocument::fromJson(readFile(baseName + QLatin1String(".rhs.json"))).object());
        const auto expected = QJsonDocument::fromJson(readFile(baseName + QLatin1String(".merged.json"))).object();

        QVERIFY(Stopover::isSame(lhs, rhs));
        QVERIFY(Stopover::isSame(rhs, lhs));

        const auto mergedL2R = Stopover::merge(lhs, rhs);
        QVERIFY(Test::compareJson(baseName + QLatin1String(".merged.json"), Stopover::toJson(mergedL2R), expected));

        const auto mergedR2L = Stopover::merge(rhs, lhs);
        QVERIFY(Test::compareJson(baseName + QLatin1String(".merged.json"), Stopover::toJson(mergedR2L), expected));
    }
};

QTEST_GUILESS_MAIN(DepartureTest)

#include "departuretest.moc"
