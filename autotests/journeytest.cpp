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

#include <KPublicTransport/Journey>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class JourneyTest : public QObject
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
    void testJourneyMerge_data()
    {
        QTest::addColumn<QString>("baseName");

        QDir dir(QStringLiteral(SOURCE_DIR "/data/journeys"));
        const auto lst = dir.entryList(QStringList(QStringLiteral("*.merged.json")), QDir::Files | QDir::Readable | QDir::NoSymLinks);
        for (const auto &file : lst) {
            const auto base = file.left(file.size() - 12);
            QTest::newRow(base.toLatin1().constData()) << (dir.path() + QLatin1Char('/') + base);
        }
    }

    void testJourneyMerge()
    {
        QFETCH(QString, baseName);

        const auto lhs = Journey::fromJson(QJsonDocument::fromJson(readFile(baseName + QLatin1String(".lhs.json"))).object());
        const auto rhs = Journey::fromJson(QJsonDocument::fromJson(readFile(baseName + QLatin1String(".rhs.json"))).object());
        const auto expected = QJsonDocument::fromJson(readFile(baseName + QLatin1String(".merged.json")));

        QVERIFY(Journey::isSame(lhs, rhs));
        QVERIFY(Journey::isSame(rhs, lhs));

        const auto mergedL2R = Journey::merge(lhs, rhs);
        if (Journey::toJson(mergedL2R) != expected.object()) {
            qDebug().noquote() << QJsonDocument(Journey::toJson(mergedL2R)).toJson();
        }
        QCOMPARE(QJsonDocument(Journey::toJson(mergedL2R)), expected);
        const auto mergedR2L = Journey::merge(rhs, lhs);
        if (Journey::toJson(mergedR2L) != expected.object()) {
            qDebug().noquote() << QJsonDocument(Journey::toJson(mergedR2L)).toJson();
        }
        QCOMPARE(QJsonDocument(Journey::toJson(mergedR2L)), expected);
    }
};

QTEST_GUILESS_MAIN(JourneyTest)

#include "journeytest.moc"
