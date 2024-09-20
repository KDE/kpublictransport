/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "testhelpers.h"
#include "geo/geojson.cpp"
#include "backends/accessibilitycloudparser.cpp"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTest>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class AccessibilityCloudTest : public QObject
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
    void testParseLocation_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("refFileName");
        QTest::addColumn<QString>("attrFileName");

        QTest::newRow("equipment")
            << s(SOURCE_DIR "/data/a11y-cloud/equipment.in.json")
            << s(SOURCE_DIR "/data/a11y-cloud/equipment.out.json")
            << s(SOURCE_DIR "/data/a11y-cloud/equipment.attribution.json");
    }

    void testParseLocation()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, refFileName);
        QFETCH(QString, attrFileName);

        AccessibilityCloudParser p;
        QVERIFY(p.parseLocations(readFile(inFileName)));
        const auto jsonRes = Location::toJson(p.locations);

        const auto ref = QJsonDocument::fromJson(readFile(refFileName)).array();
        QVERIFY(Test::compareJson(refFileName, jsonRes, ref));

        const auto attrRes = Attribution::toJson(p.attributions);
        const auto attrRef = QJsonDocument::fromJson(readFile(attrFileName)).array();
        QVERIFY(Test::compareJson(attrFileName, attrRes, attrRef));
    }
};

QTEST_GUILESS_MAIN(AccessibilityCloudTest)

#include "accessibilitycloudtest.moc"
