/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#include "cache.h"
#include "logging.h"
#include "datatypes/attributionutil_p.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/Location>

#include <QDateTime>
#include <QDebug>
#include <QDir>
#include <QDirIterator>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>

using namespace KPublicTransport;

static QString cacheBasePath()
{
    return QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.kpublictransport/backends/");
}

static QString cachePath(const QString &backendId, const QString &contentType)
{
    return cacheBasePath() + backendId + QLatin1Char('/') + contentType + QLatin1Char('/');
}

static QString locationExtension()
{
    return QStringLiteral(".json");
}

static QString attributionExtension()
{
    return QStringLiteral(".attribution");
}

void Cache::addLocationCacheEntry(const QString &backendId, const QString &cacheKey, const std::vector<Location> &data, const std::vector<Attribution> &attribution)
{
    const auto dir = cachePath(backendId, QStringLiteral("location"));
    QDir().mkpath(dir);
    QFile f(dir + cacheKey + locationExtension());
    f.open(QFile::WriteOnly | QFile::Truncate);
    f.write(QJsonDocument(Location::toJson(data)).toJson());

    if (!attribution.empty()) {
        QFile f(dir + cacheKey + attributionExtension());
        f.open(QFile::WriteOnly | QFile::Truncate);
        f.write(QJsonDocument(Attribution::toJson(attribution)).toJson());
    }
}

void Cache::addNegativeLocationCacheEntry(const QString &backendId, const QString &cacheKey)
{
    const auto dir = cachePath(backendId, QStringLiteral("location"));
    QDir().mkpath(dir);
    QFile f(dir + cacheKey + locationExtension());
    f.open(QFile::WriteOnly | QFile::Truncate);
    // empty file is used as indicator for a negative hit
}

CacheEntry<Location> Cache::lookupLocation(const QString &backendId, const QString &cacheKey)
{
    CacheEntry<Location> entry;

    const auto dir = cachePath(backendId, QStringLiteral("location"));
    QFile f (dir + cacheKey + locationExtension());
    if (!f.open(QFile::ReadOnly)) {
        entry.type = CacheHitType::Miss;
        return entry;
    }

    if (f.size() == 0) {
        entry.type = CacheHitType::Negative;
        return entry;
    }

    entry.type = CacheHitType::Positive;
    entry.data = Location::fromJson(QJsonDocument::fromJson(f.readAll()).array());

    QFile attrFile (dir + cacheKey + attributionExtension());
    if (attrFile.open(QFile::ReadOnly)) {
        entry.attributions = Attribution::fromJson(QJsonDocument::fromJson(attrFile.readAll()).array());
    }

    return entry;
}

void Cache::addNegativeDepartureCacheEntry(const QString &backendId, const QString &cacheKey)
{
    const auto dir = cachePath(backendId, QStringLiteral("departure"));
    QDir().mkpath(dir);
    QFile f(dir + cacheKey + locationExtension());
    f.open(QFile::WriteOnly | QFile::Truncate);
    // empty file is used as indicator for a negative hit
}

CacheEntry<Departure> Cache::lookupDeparture(const QString &backendId, const QString &cacheKey)
{
    CacheEntry<Departure> entry;

    const auto dir = cachePath(backendId, QStringLiteral("departure"));
    QFile f (dir + cacheKey + locationExtension());
    if (!f.open(QFile::ReadOnly)) {
        entry.type = CacheHitType::Miss;
        return entry;
    }

    if (f.size() == 0) {
        entry.type = CacheHitType::Negative;
        return entry;
    }

    entry.type = CacheHitType::Positive;
    entry.data = Departure::fromJson(QJsonDocument::fromJson(f.readAll()).array());

    QFile attrFile (dir + cacheKey + attributionExtension());
    if (attrFile.open(QFile::ReadOnly)) {
        entry.attributions = Attribution::fromJson(QJsonDocument::fromJson(attrFile.readAll()).array());
    }

    return entry;
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
        } else if (it.fileInfo().lastModified().addDays(30) < now) {
            qCDebug(Log) << "removing expired cache entry" << it.fileName();
            QDir(path).remove(it.filePath());
        }
    }
}

void Cache::expire()
{
    expireRecursive(cacheBasePath());
}

void Cache::allCachedAttributions(std::vector<Attribution> &attrs)
{
    QDirIterator it(cacheBasePath(), {QLatin1Char('*') + attributionExtension()}, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        QFile f(it.filePath());
        f.open(QFile::ReadOnly);
        auto cached = Attribution::fromJson(QJsonDocument::fromJson(f.readAll()).array());
        AttributionUtil::merge(attrs, std::move(cached));
    }
}
