/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <QDirIterator>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTest>
#include <QTimeZone>

class NetworkConfigTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:

    void testConfig_data()
    {
        QTest::addColumn<QString>("fileName");
        QDirIterator it(QStringLiteral(SOURCE_DIR "/../src/lib/networks/"), {QStringLiteral("*.json")});
        while (it.hasNext()) {
            it.next();
            QTest::newRow(it.fileName().toLatin1().constData()) << it.fileInfo().absoluteFilePath();
        }
    }

    void testConfig()
    {
        QFETCH(QString, fileName);
        QFile f(fileName);
        QVERIFY(f.open(QFile::ReadOnly));

        QJsonParseError docError;
        const auto doc = QJsonDocument::fromJson(f.readAll(), &docError);
        if (docError.error != QJsonParseError::NoError) {
            qWarning() << "JSON parser error in" << fileName << docError.errorString();
        }
        QCOMPARE(docError.error, QJsonParseError::NoError);

        const auto top = doc.object();
        QVERIFY(!top.isEmpty());
        QVERIFY(!top.value(QLatin1String("type")).toObject().isEmpty());

        const auto tz = top.value(QLatin1String("timezone")).toString();
        if (!tz.isEmpty()) {
            QVERIFY(QTimeZone(tz.toUtf8()).isValid());
        }
    }
};

QTEST_GUILESS_MAIN(NetworkConfigTest)

#include "networkconfigtest.moc"
