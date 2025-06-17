/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "updatestate_p.h"

#include "kpublictransport_version.h"
#include "manifest_p.h"

#include "http/useragent_p.h"

#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSettings>
#include <QStandardPaths>
#include <QUrl>
#include <QVersionNumber>

#include <cassert>

using namespace Qt::Literals;
using namespace KPublicTransport;

QString UpdateState::basePath()
{
    return QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "/org.kde.kpublictransport/update/"_L1;
}

QString UpdateState::manifestPath()
{
    return basePath() + "manifest"_L1;
}

QString UpdateState::stateFilePath()
{
    return QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "/org.kde.kpublictransport/updatestate.conf"_L1;
}

#ifndef Q_OS_ANDROID
QString UpdateState::lockFilePath()
{
    return QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "/org.kde.kpublictransport/update.lock"_L1;
}
#endif

[[nodiscard]] static QString defaultUpdateUrl()
{
    // TODO disabled until we have resolved the CDN caching issues
    // return u"https://autoconfig.kde.org/kpublictransport/"_s;
    return QString();
}

QUrl UpdateState::remoteUrl(QStringView filePath)
{
    const auto baseUrl = qEnvironmentVariable("KPUBLICTRANSPORT_UPDATE_SERVER", defaultUpdateUrl());
    QUrl url(baseUrl);
    if (!url.isValid() || (url.scheme() != "https"_L1 && url.scheme() != "http"_L1)) {
        return {};
    }
    auto path = url.path();
    if (!path.endsWith('/'_L1)) {
        path += '/'_L1;
    }
    path += filePath;
    url.setPath(path);

    return url;
}

bool UpdateState::isEnabled()
{
    return remoteUrl(QString()).isValid();
}

QVersionNumber UpdateState::currentVersion()
{
    return QVersionNumber({KPUBLICTRANSPORT_VERSION_MAJOR, KPUBLICTRANSPORT_VERSION_MINOR, KPUBLICTRANSPORT_VERSION_PATCH});
}

QDateTime UpdateState::lastUpdate()
{
    const QSettings state(stateFilePath(), QSettings::IniFormat);
    return state.value("Timestamp").toDateTime();
}

QNetworkRequest UpdateState::manifestRequest() const
{
    QNetworkRequest req(remoteUrl(u"manifest"));
    req.setHeader(QNetworkRequest::UserAgentHeader, Http::userAgent().toUtf8());

    const QSettings state(stateFilePath(), QSettings::IniFormat);
    if (const auto lastMod = state.value("Last-Modified", QString()).toDateTime(); !lastMod.isNull()) {
        req.setHeader(QNetworkRequest::IfModifiedSinceHeader, lastMod);
    }
    if (const auto etag = state.value("ETag", QString()).toString(); !etag.isEmpty()) {
        req.setHeader(QNetworkRequest::IfNoneMatchHeader, etag);
    }

    return req;
}

std::expected<bool, UpdateResult::Type> UpdateState::handleManifestReply(QNetworkReply *reply)
{
    reply->deleteLater();

    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << reply->errorString() << reply->request().url();
        return std::unexpected(UpdateResult::NetworkError);
    }

    // we still have the current version
    if (reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 304) {
        return false;
    }

    QDir().mkpath(basePath());

    QFile f(manifestPath());
    if (!f.open(QFile::WriteOnly | QFile::Truncate)) {
        qWarning() << f.errorString() << f.fileName();
        return std::unexpected(UpdateResult::FilesystemError);
    }

    f.write(reply->readAll());

    QSettings state(stateFilePath(), QSettings::IniFormat);
    if (const auto lastMod = reply->header(QNetworkRequest::LastModifiedHeader).toDateTime(); !lastMod.isNull()) {
        state.setValue("Last-Modified", lastMod);
    }
    if (const auto etag = reply->header(QNetworkRequest::ETagHeader).toString(); !etag.isEmpty()) {
        state.setValue("ETag", etag);
    }
    state.setValue("Timestamp", QDateTime::currentDateTime());

    return true;
}

QVersionNumber UpdateState::fileVersion(const QString &path) const
{
    assert(!path.isEmpty());

    if (QFile::exists(basePath() + path)) {
        QFile f(basePath() + path + ".version"_L1);
        if (f.open(QFile::ReadOnly)) {
            const auto obj = QJsonDocument::fromJson(f.readAll()).object();
            const auto v = QVersionNumber::fromString(obj.value("version"_L1).toString());
            if (!v.isNull()) {
                return v;
            }
        }
    }

    if (QFile::exists(":/org.kde.kpublictransport/"_L1 + path)) {
        return UpdateState::currentVersion();
    }

    return QVersionNumber();
}

void UpdateState::purgeObsoleteFiles(const QVersionNumber &version)
{
    QStringList toRemove;
    for (QDirIterator it(basePath(), QDir::Files, QDirIterator::Subdirectories); it.hasNext();) {
        it.next();
        if (it.fileName().endsWith(".version"_L1)) {
            continue;
        }
        QFile f(it.filePath() + ".version"_L1);
        if (f.open(QFile::ReadOnly)) {
            const auto obj = QJsonDocument::fromJson(f.readAll()).object();
            const auto v = QVersionNumber::fromString(obj.value("version"_L1).toString());
            if (v <= version) {
                toRemove.push_back(it.filePath());
            }
        }
    }

    for (const auto &s :toRemove) {
        qDebug() << "removing obsolte file:" << s;
        QFile::remove(s);
        QFile::remove(s + ".version"_L1);
    }
}

QNetworkRequest UpdateState::fileRequest(const ManifestEntry &entry) const
{
    QNetworkRequest req(remoteUrl(entry.source()));
    req.setHeader(QNetworkRequest::UserAgentHeader, Http::userAgent().toUtf8());
    return req;
}

UpdateResult::Type UpdateState::handleFileReply(const ManifestEntry &entry, QNetworkReply *reply)
{
    reply->deleteLater();

    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << reply->errorString() << reply->request().url();
        return UpdateResult::NetworkError;
    }

    // create target directory
    const QFileInfo fi(basePath() + entry.fileName());
    QDir().mkpath(fi.absolutePath());
    const QFileInfo dirFi(fi.absolutePath());

    // verify we are not writing outside of basePath()
    // this is already protected against in Manifest, but better safe than sorry
    if (!dirFi.canonicalFilePath().startsWith(basePath())) {
        qWarning() << "Blocking write outside of base dir:" << dirFi.canonicalFilePath() << basePath();
        return UpdateResult::FilesystemError;
    }

    QFile f(fi.absoluteFilePath());
    if (!f.open(QFile::WriteOnly | QFile::Truncate)) {
        qWarning() << f.errorString() << f.fileName();
        return UpdateResult::FilesystemError;
    }
    f.write(reply->readAll());
    f.close();

    QFile versionFile(fi.absoluteFilePath() + ".version"_L1);
    if (!versionFile.open(QFile::WriteOnly | QFile::Truncate)) {
        qWarning() << versionFile.errorString() <<versionFile.fileName();
        return UpdateResult::FilesystemError;
    }

    QJsonObject obj({{"version"_L1, entry.fileVersion()}});
    versionFile.write(QJsonDocument(obj).toJson(QJsonDocument::Compact));
    return UpdateResult::UpdateSuccessful;
}
