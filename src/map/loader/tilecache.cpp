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

#include "tilecache.h"
#include "logging.h"

#include <osm/datatypes.h>
#include <osm/geomath.h>

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QStandardPaths>
#include <QUrl>

#include <cmath>

using namespace KOSMIndoorMap;

Tile Tile::fromCoordinate(double lat, double lon, uint8_t z)
{
    Tile t;
    t.x = std::floor((lon + 180.0) / 360.0 * (1 << z));
    const auto latrad = OSM::degToRad(lat);
    t.y = std::floor((1.0 - std::asinh(std::tan(latrad)) / M_PI) / 2.0 * (1 << z));
    t.z = z;
    return t;
}

OSM::Coordinate Tile::topLeft() const
{
    const auto lon = x / (double)(1 << z) * 360.0 - 180.0;

    const auto n = M_PI - 2.0 * M_PI * y / (double)(1 << z);
    const auto lat = OSM::radToDeg(std::atan(0.5 * (std::exp(n) - std::exp(-n))));

    return OSM::Coordinate(lat, lon);
}

OSM::BoundingBox Tile::boundingBox() const
{
    Tile bottomRight = *this;
    ++bottomRight.x;
    ++bottomRight.y;

    const auto tl = topLeft();
    const auto br = bottomRight.topLeft();

    return OSM::BoundingBox(OSM::Coordinate(br.latitude, tl.longitude), OSM::Coordinate(tl.latitude, br.longitude));
}


TileCache::TileCache(QObject *parent)
    : QObject(parent)
    , m_nam(new QNetworkAccessManager(this))
{
    m_nam->setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);
    m_nam->enableStrictTransportSecurityStore(true, QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.osm/hsts/"));
    m_nam->setStrictTransportSecurityEnabled(true);
}

TileCache::~TileCache() = default;

QString TileCache::cachedTile(Tile tile) const
{
    const auto p = cachePath(tile);
    if (QFile::exists(p)) {
        return p;
    }
    return {};
}

void TileCache::ensureCached(Tile tile)
{
    if (!cachedTile(tile).isEmpty()) {
        return;
    }
    downloadTile(tile);
}

void TileCache::downloadTile(Tile tile)
{
    m_pendingDownloads.push_back(tile);
    downloadNext();
}

QString TileCache::cachePath(Tile tile) const
{
    return QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation)
        + QLatin1String("/org.kde.osm/vectorosm/")
        + QString::number(tile.z) + QLatin1Char('/')
        + QString::number(tile.x) + QLatin1Char('/')
        + QString::number(tile.y) + QLatin1String(".o5m");
}

void TileCache::downloadNext()
{
    if (m_output.isOpen() || m_pendingDownloads.empty()) {
        return;
    }

    const auto tile = m_pendingDownloads.front();
    m_pendingDownloads.pop_front();

    QFileInfo fi(cachePath(tile));
    QDir().mkpath(fi.absolutePath());
    m_output.setFileName(fi.absoluteFilePath() + QLatin1String(".part"));
    if (!m_output.open(QFile::WriteOnly)) {
        qCWarning(Log) << m_output.fileName() << m_output.errorString();
        return;
    }

    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(QStringLiteral("maps.kde.org"));
    url.setPath(QLatin1String("/earth/vectorosm/v1/") + QString::number(tile.z) + QLatin1Char('/') + QString::number(tile.x) + QLatin1Char('/') + QString::number(tile.y) + QLatin1String(".o5m"));

    QNetworkRequest req(url);
    auto reply = m_nam->get(req);
    connect(reply, &QNetworkReply::readyRead, this, [this, reply]() { dataReceived(reply); });
    connect(reply, &QNetworkReply::finished, this, [this, reply, tile]() { downloadFinished(reply, tile); });
}

void TileCache::dataReceived(QNetworkReply *reply)
{
    m_output.write(reply->read(reply->bytesAvailable()));
}

void TileCache::downloadFinished(QNetworkReply* reply, Tile tile)
{
    reply->deleteLater();
    m_output.close();

    if (reply->error() != QNetworkReply::NoError) {
        qCWarning(Log) << reply->errorString() << reply->url();
        m_output.remove();
        Q_EMIT tileError(tile, reply->errorString());
        downloadNext();
        return;
    }

    m_output.rename(cachePath(tile));

    Q_EMIT tileLoaded(tile);
    downloadNext();
}

int TileCache::pendingDownloads() const
{
    return m_pendingDownloads.size() + (m_output.isOpen() ? 1 : 0);
}

void TileCache::cancelPending()
{
    m_pendingDownloads.clear();
}
