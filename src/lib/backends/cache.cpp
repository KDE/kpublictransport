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
#include "datatypes/vehiclelayoutresult_p.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/Journey>
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

template <typename T>
static void addCacheEntry(const QString &typeName, const QString &backendId, const QString &cacheKey, const std::vector<T> &data, const std::vector<Attribution> &attribution, std::chrono::seconds ttl)
{
   const auto dir = cachePath(backendId, typeName);
    QDir().mkpath(dir);
    QFile f(dir + cacheKey + locationExtension());
    f.open(QFile::WriteOnly | QFile::Truncate);
    f.write(QJsonDocument(T::toJson(data)).toJson());
    f.close();
    // mtime changes need to be done without content changes to take effect
    f.open(QFile::WriteOnly | QFile::Append);
    f.setFileTime(QDateTime::currentDateTimeUtc().addSecs(ttl.count()), QFile::FileModificationTime);
    f.close();

    if (!attribution.empty()) {
        QFile f(dir + cacheKey + attributionExtension());
        f.open(QFile::WriteOnly | QFile::Truncate);
        f.write(QJsonDocument(Attribution::toJson(attribution)).toJson());
        f.close();
        // mtime changes need to be done without content changes to take effect
        f.open(QFile::WriteOnly | QFile::Append);
        f.setFileTime(QDateTime::currentDateTimeUtc().addSecs(ttl.count()), QFile::FileModificationTime);
        f.close();
    }
}

static void addNegativeCacheEntry(const QString &typeName, const QString &backendId, const QString &cacheKey, std::chrono::seconds ttl)
{
    const auto dir = cachePath(backendId, typeName);
    QDir().mkpath(dir);
    QFile f(dir + cacheKey + locationExtension());
    f.open(QFile::WriteOnly | QFile::Truncate);
    f.setFileTime(QDateTime::currentDateTimeUtc().addSecs(ttl.count()), QFile::FileModificationTime);
    // empty file is used as indicator for a negative hit
}

template <typename T>
static CacheEntry<T> lookup(const QString &typeName, const QString &backendId, const QString &cacheKey)
{
    CacheEntry<T> entry;

    const auto dir = cachePath(backendId, typeName);
    QFile f (dir + cacheKey + locationExtension());
    if (!f.open(QFile::ReadOnly)) {
        entry.type = CacheHitType::Miss;
        return entry;
    }

    // check if this entry is still valid before using it
    if (f.fileTime(QFile::FileModificationTime) < QDateTime::currentDateTimeUtc()) {
        qDebug() << "expiring cache entry" << f.fileName();
        f.close();
        f.remove();
        entry.type = CacheHitType::Miss;
        return entry;
    }

    if (f.size() == 0) {
        entry.type = CacheHitType::Negative;
        return entry;
    }

    entry.type = CacheHitType::Positive;
    entry.data = T::fromJson(QJsonDocument::fromJson(f.readAll()).array());

    QFile attrFile (dir + cacheKey + attributionExtension());
    if (attrFile.open(QFile::ReadOnly)) {
        entry.attributions = Attribution::fromJson(QJsonDocument::fromJson(attrFile.readAll()).array());
    }

    return entry;
}

void Cache::addLocationCacheEntry(const QString &backendId, const QString &cacheKey, const std::vector<Location> &data, const std::vector<Attribution> &attribution, std::chrono::seconds ttl)
{
    addCacheEntry(QStringLiteral("location"), backendId, cacheKey, data, attribution, ttl);
}

void Cache::addNegativeLocationCacheEntry(const QString &backendId, const QString &cacheKey, std::chrono::seconds ttl)
{
    addNegativeCacheEntry(QStringLiteral("location"), backendId, cacheKey, ttl);
}

CacheEntry<Location> Cache::lookupLocation(const QString &backendId, const QString &cacheKey)
{
    return lookup<Location>(QStringLiteral("location"), backendId, cacheKey);
}

void Cache::addNegativeDepartureCacheEntry(const QString &backendId, const QString &cacheKey, std::chrono::seconds ttl)
{
    addNegativeCacheEntry(QStringLiteral("departure"), backendId, cacheKey, ttl);
}

CacheEntry<Departure> Cache::lookupDeparture(const QString &backendId, const QString &cacheKey)
{
    return lookup<Departure>(QStringLiteral("departure"), backendId, cacheKey);
}

void Cache::addNegativeJourneyCacheEntry(const QString &backendId, const QString &cacheKey, std::chrono::seconds ttl)
{
    addNegativeCacheEntry(QStringLiteral("journey"), backendId, cacheKey, ttl);
}

CacheEntry<Journey> Cache::lookupJourney(const QString &backendId, const QString &cacheKey)
{
    return lookup<Journey>(QStringLiteral("journey"), backendId, cacheKey);
}

void Cache::addVehicleLayoutCacheEntry(const QString &backendId, const QString &cacheKey, const VehicleLayoutResult &data, const std::vector<Attribution> &attributions, std::chrono::seconds ttl)
{
    addCacheEntry<VehicleLayoutResult>(QStringLiteral("vehicle"), backendId, cacheKey, {data}, attributions, ttl);
}

void Cache::addNegativeVehicleLayoutCacheEntry(const QString& backendId, const QString& cacheKey, std::chrono::seconds ttl)
{
    addNegativeCacheEntry(QStringLiteral("vehicle"), backendId, cacheKey, ttl);
}

CacheEntry<VehicleLayoutResult> Cache::lookupVehicleLayout(const QString &backendId, const QString &cacheKey)
{
    return lookup<VehicleLayoutResult>(QStringLiteral("vehicle"), backendId, cacheKey);
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
