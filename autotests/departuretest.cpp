/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#include <KPublicTransport/Departure>

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

        const auto lhs = Departure::fromJson(QJsonDocument::fromJson(readFile(baseName + QLatin1String(".lhs.json"))).object());
        const auto rhs = Departure::fromJson(QJsonDocument::fromJson(readFile(baseName + QLatin1String(".rhs.json"))).object());
        const auto expected = QJsonDocument::fromJson(readFile(baseName + QLatin1String(".merged.json")));

        QVERIFY(Departure::isSame(lhs, rhs));
        QVERIFY(Departure::isSame(rhs, lhs));

        // TODO: merging is not yet properly symmetric
        const auto mergedL2R = Departure::merge(lhs, rhs);
        qDebug().noquote() << QJsonDocument(Departure::toJson(mergedL2R)).toJson();
        //QCOMPARE(QJsonDocument(Departure::toJson(mergedL2R)), expected);
        const auto mergedR2L = Departure::merge(rhs, lhs);
        qDebug().noquote() << QJsonDocument(Departure::toJson(mergedR2L)).toJson();
        //QCOMPARE(QJsonDocument(Departure::toJson(mergedR2L)), expected);
    }
};

QTEST_GUILESS_MAIN(DepartureTest)

#include "departuretest.moc"
