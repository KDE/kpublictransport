/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#include "../src/map-quick/osmelementinformationmodel.h"

#include <osm/xmlparser.h>

#include <QAbstractItemModelTester>
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTest>

using namespace KOSMIndoorMap;

void initLocale()
{
    qputenv("LC_ALL", "en_US.utf-8");
    qputenv("TZ", "UTC");
}

Q_CONSTRUCTOR_FUNCTION(initLocale)

class OSMElementInfoModelTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testModel_data()
    {
        QTest::addColumn<QString>("osmFile");
        QTest::addColumn<QString>("modelFile");

        QDir dir(QStringLiteral(SOURCE_DIR "/data/osminfomodel/"));
        const auto lst = dir.entryList(QStringList(QStringLiteral("*.xml")), QDir::Files | QDir::Readable | QDir::NoSymLinks);
        for (const auto &file : lst) {
            const auto base = file.left(file.size() - 4);
            QTest::newRow(base.toLatin1().constData()) << (dir.path() + QLatin1Char('/') + file) << (dir.path() + QLatin1Char('/') + base + QLatin1String(".json"));
        }
    }

    void testModel()
    {
        // verify the locale matches what the test data expects
        // this is a workaround for test failures on OBS
        if (QLocale().createSeparatedList({QStringLiteral("A"), QStringLiteral("B")}) != QLatin1String("A and B")) {
            QSKIP("locale doesn't behave as expected!");
        }

        QFETCH(QString, osmFile);
        QFETCH(QString, modelFile);

        QFile inFile(osmFile);
        QVERIFY(inFile.open(QFile::ReadOnly));

        OSM::DataSet dataSet;
        OSM::XmlParser p(&dataSet);
        p.parse(&inFile);
        QCOMPARE(dataSet.nodes.size(), 1);

        OSMElementInformationModel model;
        QAbstractItemModelTester modelTest(&model);
        model.setElement(OSMElement(OSM::Element(&dataSet.nodes[0])));

        QJsonObject top;
        top.insert(QStringLiteral("name"), model.name());
        QJsonArray modelContent;
        for (int row = 0; row < model.rowCount(); ++row) {
            const auto idx = model.index(row);
            QJsonObject modelRow;
            for (auto role : {OSMElementInformationModel::KeyLabelRole, OSMElementInformationModel::ValueRole, OSMElementInformationModel::ValueUrlRole, OSMElementInformationModel::CategoryLabelRole}) {
                if (!idx.data(role).toString().isEmpty()) {
                    modelRow.insert(QString::fromUtf8(model.roleNames().value(role)), idx.data(role).toString());
                }
            }
            modelContent.push_back(modelRow);
        }
        top.insert(QStringLiteral("content"), modelContent);

        model.clear();
        QCOMPARE(model.rowCount(), 0);

        QFile refFile(modelFile);
        QVERIFY(refFile.open(QFile::ReadOnly));
        const auto refContent = QJsonDocument::fromJson(refFile.readAll()).object();
        if (top != refContent) {
            qDebug().noquote() << QJsonDocument(top).toJson();
        }
        QCOMPARE(top, refContent);
    }
};

QTEST_GUILESS_MAIN(OSMElementInfoModelTest)

#include "osmelementinfomodeltest.moc"
