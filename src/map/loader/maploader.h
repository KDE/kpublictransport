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

#ifndef KOSMINDOORMAP_MAPLOADER_H
#define KOSMINDOORMAP_MAPLOADER_H

#include "mapdata.h"
#include "tilecache.h"

#include <osm/datatypes.h>

#include <QObject>

namespace KOSMIndoorMap {

/** Loader for OSM data for a single station or airport. */
class MapLoader : public QObject
{
    Q_OBJECT
public:
    explicit MapLoader(QObject *parent = nullptr);
    ~MapLoader();

    /** Load a single O5M file. */
    void loadFromO5m(const QString &fileName);
    /** Load map for the given coordinates.
     *  This can involve online access.
     */
    void loadForCoordinate(double lat, double lon);

    /** Take out the completely loaded result.
     *  Do this before loading the next map with the same loader.
     */
    MapData&& takeData();

Q_SIGNALS:
    /** Emitted when the requested data has been loaded. */
    void done();

private:
    void downloadFinished();
    void loadTiles();

    MapData m_data;
    TileCache m_tileCache;
    Tile m_topLeft;
    Tile m_bottomRight;
};

}

#endif // KOSMINDOORMAP_MAPLOADER_H
