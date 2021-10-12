/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backends/oebbvehiclelayoutparser.cpp"
#include "uic/uicrailwaycoach.cpp"

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QProcess>
#include <QTest>
#include <QTimeZone>

#define s(x) QStringLiteral(x)

using namespace KPublicTransport;

class OebbParserTest : public QObject
{
    Q_OBJECT
private:
    QByteArray readFile(const QString &fn)
    {
        QFile f(fn);
        f.open(QFile::ReadOnly);
        return f.readAll();
    }

    template <typename T>
    inline void diffJson(const QString &refFile, const T &output, const T &ref)
    {
        if (output != ref) {
            QFile failFile(refFile + QLatin1String(".fail"));
            QVERIFY(failFile.open(QFile::WriteOnly));
            failFile.write(QJsonDocument(output).toJson());
            failFile.close();

            QProcess proc;
            proc.setProcessChannelMode(QProcess::ForwardedChannels);
            proc.start(QStringLiteral("diff"), {QStringLiteral("-u"), refFile, failFile.fileName()});
            QVERIFY(proc.waitForFinished());
        }
    }

private Q_SLOTS:
    void initTestCase()
    {
        qputenv("TZ", "UTC");
    }

    void testVehicleLayoutParse_data()
    {
        QTest::addColumn<QString>("inFileName");
        QTest::addColumn<QString>("departureFileName");

        QTest::newRow("rj-forward")
            << s(SOURCE_DIR "/data/oebb/rj-forward-input.json")
            << s(SOURCE_DIR "/data/oebb/rj-forward-departure.json");

        QTest::newRow("rj-no-platform-sectors")
            << s(SOURCE_DIR "/data/oebb/rj-no-platform-sectors-input.json")
            << s(SOURCE_DIR "/data/oebb/rj-no-platform-sectors-departure.json");

        QTest::newRow("ic-no-platform-data")
            << s(SOURCE_DIR "/data/oebb/ic-no-platform-data-input.json")
            << s(SOURCE_DIR "/data/oebb/ic-no-platform-data-departure.json");
    }

    void testVehicleLayoutParse()
    {
        QFETCH(QString, inFileName);
        QFETCH(QString, departureFileName);

        KPublicTransport::OebbVehicleLayoutParser parser;

        QVERIFY(parser.parse(readFile(inFileName)));
        const auto departureJson = Stopover::toJson(parser.stopover);
        const auto departureRef = QJsonDocument::fromJson(readFile(departureFileName)).object();
        if (departureJson != departureRef) {
            diffJson(departureFileName, departureJson, departureRef);
        }
        QVERIFY(!departureJson.isEmpty());
        QCOMPARE(departureJson, departureRef);
    }
};

QTEST_GUILESS_MAIN(OebbParserTest)

#include "oebbparsertest.moc"
