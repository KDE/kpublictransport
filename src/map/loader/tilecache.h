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

#ifndef KOSMINDOORMAP_TILECACHE_H
#define KOSMINDOORMAP_TILECACHE_H

#include <QObject>

class QNetworkAccessManager;

namespace KOSMIndoorMap {

/** Identifier of a slippy map tile.
 *  @see https://wiki.openstreetmap.org/wiki/Slippy_map_tilenames
 */
class Tile
{
public:
    static Tile fromCoordinate(double lat, double lon, uint8_t z);

    uint32_t x = 0;
    uint32_t y = 0;
    uint8_t z = 0;
};

/** OSM vector tile downloading and cache management. */
class TileCache : public QObject
{
    Q_OBJECT
public:
    explicit TileCache(QObject *parent = nullptr);
    ~TileCache();

    /** Returns the path to the cached content of @p tile, if present locally. */
    QString cachedTile(Tile tile) const;

    /** Triggers the download of tile @p tile. */
    void downloadTile(Tile tile);

private:
    QString cachePath(Tile tile) const;

    QNetworkAccessManager *m_nam;
};

}

#endif // KOSMINDOORMAP_TILECACHE_H
