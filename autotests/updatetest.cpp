/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kpublictransport_version.h"

#include "mocknetworkaccessmanager.h"

#include "../src/lib/update/manifest.cpp"
#include "../src/lib/update/updatestate.cpp"
#include "../src/lib/http/useragent.cpp"

#include <KPublicTransport/Backend>
#include <KPublicTransport/Manager>

#include <QDir>
#include <QFile>
#include <QSignalSpy>
#include <QStandardPaths>
#include <QTest>
#include <QVersionNumber>

namespace KPublicTransport {
class UpdateTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase()
    {
        qunsetenv("XDG_DATA_DIRS");
        qputenv("KPUBLICTRANSPORT_UPDATE_SERVER", "http://localhost:8080/"); // doesn't actually need to work, this all goes to a mock QNAM anyway
        QStandardPaths::setTestModeEnabled(true);
        QVERIFY(!UpdateState::stateFilePath().isEmpty());
        QFile::remove(UpdateState::stateFilePath());
        QVERIFY(!UpdateState::basePath().isEmpty());
        QDir(UpdateState::basePath()).removeRecursively();
    }

    void testVersionCompare()
    {
        // ensure QVersionNumber follows how our versioning works
        QCOMPARE_LT(QVersionNumber::fromString("25.04.1"), QVersionNumber::fromString("25.08.0"));
        QCOMPARE_LT(QVersionNumber::fromString("25.04.1.5"), QVersionNumber::fromString("25.08.0"));
        QCOMPARE_LT(QVersionNumber(25, 7, 71), QVersionNumber::fromString("255.08.0.2"));

        QCOMPARE_LT(QVersionNumber(25, 7, 71), QVersionNumber::fromString("25.07.71.0"));
    }

    void testLocalVersion()
    {
        UpdateState s;
        QCOMPARE(s.fileVersion(u"networks/un_transitous.json"_s), QVersionNumber({KPUBLICTRANSPORT_VERSION_MAJOR, KPUBLICTRANSPORT_VERSION_MINOR, KPUBLICTRANSPORT_VERSION_PATCH}));
        QCOMPARE(s.fileVersion(u"networks/un_non_existing.json"_s), QVersionNumber());
    }

    void testUpdateNoManifestChange()
    {
        MockNetworkAccessManager nam;
        nam.replies.push({.error = QNetworkReply::NoError, .statusCode = 304});

        Manager mgr;
        QCOMPARE(mgr.updateResult(), UpdateResult::NoError);
        mgr.setNetworkAccessManager(&nam);
        QSignalSpy updateSpy(&mgr, &Manager::updateResultChanged);
        mgr.checkForUpdates();
        QCOMPARE(updateSpy.size(), 1);
        QCOMPARE(mgr.updateResult(), UpdateResult::InProgress);
        QVERIFY(updateSpy.wait());
        QCOMPARE(mgr.updateResult(), UpdateResult::NoUpdate);

        QCOMPARE(nam.requests.size(), 1);
        QVERIFY(nam.requests[0].request.url().path().endsWith("manifest"_L1));
    }

    void testUpdate()
    {
        QVERIFY(UpdateState::isEnabled());

        UpdateState s;
        QCOMPARE(s.lastUpdate().isValid(), false);

        MockNetworkAccessManager nam;
        nam.replies.push({.error = QNetworkReply::NoError, .statusCode = 200, .data = R"({"version":2,"entries":[
            {"name":"networks/un_transitous.json","version":"25.04.1.3" },
            {"name":"networks/geometry/un_transitous_regular.geojson","version":"25.07.40" },
            {"name":"networks/geometry/un_transitous_any.geojson","version":"125.07.40","minSupportedVersion":"124.07.1" },
            {"name":"networks/de_db.json","version":"243.12.3.4","source":"networks/de_db-243.12.3.4.json"},
            {"name":"../../etc/passwd","version":"1.0"}
        ]})", .headers = {{"Last-Modified", "Tue, 25 Mar 2025 21:26:21 GMT"}} });
        nam.replies.push({.error = QNetworkReply::NoError, .statusCode = 200, .data = R"({"active":false})"});
        nam.replies.push({.error = QNetworkReply::NoError, .statusCode = 304});

        {
            Manager mgr;
            std::ignore = mgr.backends(); // trigger loading so we can observe reloading
            mgr.setNetworkAccessManager(&nam);
            QSignalSpy updateSpy(&mgr, &Manager::updateResultChanged);
            QSignalSpy backendChangeSpy(&mgr, &Manager::backendsChanged);
            QCOMPARE(mgr.updateResult(), UpdateResult::NoError);
            mgr.checkForUpdates();
            QCOMPARE(mgr.updateResult(), UpdateResult::InProgress);
            QVERIFY(updateSpy.wait());
            QCOMPARE(mgr.updateResult(), UpdateResult::UpdateSuccessful);
            QCOMPARE(backendChangeSpy.size(), 1);

            QCOMPARE(nam.requests.size(), 2);
            QVERIFY(nam.requests[1].request.url().path().endsWith("/networks/de_db-243.12.3.4.json"_L1));

            QVERIFY(std::ranges::none_of(mgr.backends(), [](const auto &b) { return b.identifier() == "de_db"_L1; }));
        }

        nam.requests.clear();
        {
            Manager mgr;
            mgr.setNetworkAccessManager(&nam);
            QSignalSpy updateSpy(&mgr, &Manager::updateResultChanged);
            mgr.checkForUpdates(true);
            QCOMPARE(mgr.updateResult(), UpdateResult::InProgress);
            QVERIFY(updateSpy.wait());
            QCOMPARE(mgr.updateResult(), UpdateResult::NoUpdate);

            QCOMPARE(nam.requests.size(), 1);
            QCOMPARE(nam.requests[0].request.header(QNetworkRequest::IfModifiedSinceHeader).toDateTime(), QDateTime({2025, 3, 25}, {21, 26, 21}, QTimeZone::UTC));
        }

        nam.requests.clear();
        {
            Manager mgr;
            mgr.setNetworkAccessManager(&nam);
            QSignalSpy updateSpy(&mgr, &Manager::updateResultChanged);
            mgr.checkForUpdates(); // last update is recent, should not do anything
            QCOMPARE(mgr.updateResult(), UpdateResult::NoUpdate);
            QCOMPARE(nam.requests.size(), 0);
        }

        QCOMPARE(s.fileVersion(u"networks/de_db.json"_s), QVersionNumber::fromString("243.12.3.4"));
        QCOMPARE(s.lastUpdate().isValid(), true);
        QVERIFY(s.lastUpdate() <= QDateTime::currentDateTime());

        UpdateState::purgeObsoleteFiles(QVersionNumber(254, 0, 0));
        QCOMPARE(s.fileVersion(u"networks/de_db.json"_s), QVersionNumber({KPUBLICTRANSPORT_VERSION_MAJOR, KPUBLICTRANSPORT_VERSION_MINOR, KPUBLICTRANSPORT_VERSION_PATCH}));
    }

    void testManifestNetworkError()
    {
        MockNetworkAccessManager nam;
        nam.replies.push({});

        Manager mgr;
        mgr.setNetworkAccessManager(&nam);
        QSignalSpy updateSpy(&mgr, &Manager::updateResultChanged);
        mgr.checkForUpdates(true);
        QVERIFY(updateSpy.wait());
        QCOMPARE(nam.requests.size(), 1);
        QCOMPARE(mgr.updateResult(), UpdateResult::NetworkError);
    }

    void testDisabledUpdate()
    {
        qputenv("KPUBLICTRANSPORT_UPDATE_SERVER", "none");
        MockNetworkAccessManager nam;

        QVERIFY(!UpdateState::isEnabled());

        Manager mgr;
        QCOMPARE(mgr.updateResult(), UpdateResult::UpdatesDisabled);
        mgr.setNetworkAccessManager(&nam);
        QSignalSpy updateSpy(&mgr, &Manager::updateResultChanged);
        mgr.checkForUpdates(true);
        QVERIFY(updateSpy.wait());
        QCOMPARE(mgr.updateResult(), UpdateResult::UpdatesDisabled);
        QCOMPARE(nam.requests.size(), 0);

        qunsetenv("KPUBLICTRANSPORT_UPDATE_SERVER");
    }
};
}

QTEST_GUILESS_MAIN(KPublicTransport::UpdateTest)

#include "updatetest.moc"
