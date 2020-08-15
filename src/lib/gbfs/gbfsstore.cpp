/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsstore.h"

#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSettings>
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
    { std::chrono::minutes(5) }
};

static_assert((sizeof(file_ttl_map) / sizeof(file_ttl_map[0])) == GBFS::Unknown, "");

GBFSStore::GBFSStore() = default;

GBFSStore::GBFSStore(const QString &systemId)
    : m_systemId(systemId)
{
}

GBFSStore::~GBFSStore() = default;

static QString encodeIdMapKey(const QUrl &url)
{
    return QString::fromUtf8(QUrl::toPercentEncoding(url.toString()));
}

QString GBFSStore::systemIdForUrl(const QUrl &url)
{
    QSettings settings(QSettings::UserScope, QStringLiteral("KDE"), QStringLiteral("org.kde.kpublictransport.gbfs"));
    settings.beginGroup(QStringLiteral("SystemIdMap"));
    return settings.value(encodeIdMapKey(url)).toString();
}

void GBFSStore::setSystemIdForUrl(const QUrl &url, const QString &systemId)
{
    QSettings settings(QSettings::UserScope, QStringLiteral("KDE"), QStringLiteral("org.kde.kpublictransport.gbfs"));
    settings.beginGroup(QStringLiteral("SystemIdMap"));
    return settings.setValue(encodeIdMapKey(url), systemId);
}

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

void GBFSStore::expire()
{
    // TODO
}

QString GBFSStore::fileName(GBFS::FileType type) const
{
    assert(!m_systemId.isEmpty());
    QString path = QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.kpublictransport/gbfs/") + m_systemId;
    QDir().mkpath(path);
    path += QLatin1Char('/') + QString::fromUtf8(GBFS::keyNameForType(type)) + QLatin1String(".json");
    return path;
}
