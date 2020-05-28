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

void TileCache::downloadTile(Tile tile)
{
    //  TODO queue multiple requests and process at most N in parallel

    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(QStringLiteral("maps.kde.org"));
    url.setPath(QLatin1String("/earth/vectorosm/v1/") + QString::number(tile.z) + QLatin1Char('/') + QString::number(tile.x) + QLatin1Char('/') + QString::number(tile.y) + QLatin1String(".o5m"));

    // TODO stream incoming data to the final destination (or a file with a .part suffix to avoid reads while downlaoding)

    QNetworkRequest req(url);
    auto reply = m_nam->get(req);
    qDebug() << reply << url;
    connect(reply, &QNetworkReply::finished, this, [this, reply, tile]() {
        reply->deleteLater();
        qDebug() << reply->errorString() << reply->url();

        QFileInfo fi(cachePath(tile));
        QDir().mkpath(fi.absolutePath());
        QFile f(fi.absoluteFilePath());
        if (!f.open(QFile::WriteOnly)) {
            qWarning() << f.fileName() << f.errorString();
            return;
        }
        f.write(reply->readAll());
    });
}

QString TileCache::cachePath(Tile tile) const
{
    return QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation)
        + QLatin1String("/org.kde.osm/vectorosm/")
        + QString::number(tile.z) + QLatin1Char('/')
        + QString::number(tile.x) + QLatin1Char('/')
        + QString::number(tile.y) + QLatin1String(".o5m");
}
