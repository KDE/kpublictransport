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

#include "backends/deutschebahnvehiclelayoutparser.cpp"

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class DbParserTest : public QObject
{
    Q_OBJECT
private:
    QByteArray readFile(const QString &fn)
    {
        QFile f(fn);
        f.open(QFile::ReadOnly);
        return f.readAll();
    }

private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testVehicleLayoutParse_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("vehicleFileName");

        QTest::newRow("valid-double-segment-ice")
            << s(SOURCE_DIR "/data/deutschebahn/double-segment-ice-input.json")
            << s(SOURCE_DIR "/data/deutschebahn/double-segment-ice-vehicle.json");
    }

    void testVehicleLayoutParse()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, vehicleFileName);

        KPublicTransport::DeutscheBahnVehicleLayoutParser parser;

        QVERIFY(parser.parse(readFile(inFileName)));
        const auto vehicleJson = Vehicle::toJson(parser.vehicle);

        const auto vehicleRef = QJsonDocument::fromJson(readFile(vehicleFileName)).object();

        if (vehicleJson != vehicleRef) {
            qDebug().noquote() << QJsonDocument(vehicleJson).toJson();
        }
        QVERIFY(!vehicleJson.isEmpty());
        QCOMPARE(vehicleJson, vehicleRef);
    }
};

QTEST_GUILESS_MAIN(DbParserTest)

#include "deutschebahntest.moc"
