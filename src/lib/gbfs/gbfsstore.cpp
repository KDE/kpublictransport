/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsstore.h"
#include "logging.h"

#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>
#include <QUrl>

#include <cassert>
#include <chrono>

using namespace KPublicTransport;

struct {
    const std::chrono::seconds ttl;
} static constexpr const file_ttl_map[] = {
    { std::chrono::hours(24 * 5) },
    { std::chrono::hours(24 * 5) },
    { std::chrono::hours(24 * 5) },
    { std::chrono::minutes(5) },
    { std::chrono::minutes(5) },
    { std::chrono::hours(24 * 5) },
    { std::chrono::hours(24 * 5) },
    { std::chrono::hours(24 * 5) },
    { std::chrono::hours(24 * 5) },
    { std::chrono::hours(24 * 5) },
    { std::chrono::hours(24 * 5) },
    { std::chrono::hours(24 * 5) },
    { std::chrono::hours(24 * 5) },
};

static_assert((sizeof(file_ttl_map) / sizeof(file_ttl_map[0])) == GBFS::Unknown, "");

GBFSStore::GBFSStore() = default;

GBFSStore::GBFSStore(const QString &systemId)
    : m_systemId(systemId)
{
}

GBFSStore::~GBFSStore() = default;

bool GBFSStore::isValid() const
{
    return !m_systemId.isEmpty();
}

bool GBFSStore::hasData(GBFS::FileType type) const
{
    const auto name = fileName(type);
    return QFile::exists(name);
}

bool GBFSStore::hasCurrentData(GBFS::FileType type) const
{
    const auto name = fileName(type);
    QFileInfo fi(name);
    return fi.exists() && fi.fileTime(QFile::FileModificationTime) >= QDateTime::currentDateTime();
}

void GBFSStore::storeData(GBFS::FileType type, const QJsonDocument &doc)
{
    const auto name = fileName(type);
    QFile f(name);
    if (!f.open(QFile::WriteOnly)) {
        qWarning() << f.errorString() << f.fileName();
        return;
    }
    f.write(doc.toJson(QJsonDocument::Compact));
    f.close();

    // mtime changes need to be done without content changes to take effect
    const auto ttl = std::max(std::chrono::seconds(doc.object().value(QLatin1String("ttl")).toInt()), file_ttl_map[type].ttl);
    f.open(QFile::WriteOnly | QFile::Append);
    f.setFileTime(QDateTime::currentDateTimeUtc().addSecs(ttl.count()), QFile::FileModificationTime);
    f.close();
}

QJsonDocument GBFSStore::loadData(GBFS::FileType type) const
{
    const auto name = fileName(type);
    QFile f(name);
    if (!f.open(QFile::ReadOnly)) {
        qWarning() << f.errorString() << f.fileName();
        return {};
    }
    return QJsonDocument::fromJson(f.readAll());
}

static void expireRecursive(const QString &path)
{
    const auto now = QDateTime::currentDateTime();
    QDirIterator it(path, QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    while (it.hasNext()) {
        it.next();

        if (it.fileInfo().isDir()) {
            expireRecursive(it.filePath());
            if (QDir(it.filePath()).isEmpty()) {
                qCDebug(Log) << "removing empty cache directory" << it.fileName();
                QDir(path).rmdir(it.filePath());
            }
        } else if (it.fileInfo().lastModified() < now) {
            qCDebug(Log) << "removing expired cache entry" << it.filePath();
            QDir(path).remove(it.filePath());
        }
    }
}

void GBFSStore::expire()
{
    expireRecursive(QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.kpublictransport/gbfs/feeds/"));
}

QString GBFSStore::fileName(GBFS::FileType type) const
{
    assert(!m_systemId.isEmpty());
    QString path = QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.kpublictransport/gbfs/feeds/") + m_systemId;
    QDir().mkpath(path);
    path += QLatin1Char('/') + QString::fromUtf8(GBFS::keyNameForType(type)) + QLatin1String(".json");
    return path;
}
