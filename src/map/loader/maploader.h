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

#include "boundarysearch.h"
#include "mapdata.h"
#include "marblegeometryassembler.h"
#include "tilecache.h"

#include <osm/datatypes.h>
#include <osm/datasetmergebuffer.h>

#include <QObject>
#include <QRect>

namespace KOSMIndoorMap {

/** Loader for OSM data for a single station or airport. */
class MapLoader : public QObject
{
    Q_OBJECT
    /** Indicates we are downloading content. Use for progress display. */
    Q_PROPERTY(bool isLoading READ isLoading NOTIFY isLoadingChanged)
public:
    explicit MapLoader(QObject *parent = nullptr);
    ~MapLoader();

    /** Load a single O5M file. */
    Q_INVOKABLE void loadFromO5m(const QString &fileName);
    /** Load map for the given coordinates.
     *  This can involve online access.
     */
    Q_INVOKABLE void loadForCoordinate(double lat, double lon);

    /** Take out the completely loaded result.
     *  Do this before loading the next map with the same loader.
     */
    MapData&& takeData();

    bool isLoading() const;

    bool hasError() const;
    QString errorMessage() const;

Q_SIGNALS:
    /** Emitted when the requested data has been loaded. */
    void done();
    void isLoadingChanged();

private:
    void downloadTiles();
    void downloadFinished();
    void downloadFailed(Tile tile, const QString &errorMessage);
    void loadTiles();

    OSM::DataSet m_dataSet;
    OSM::DataSetMergeBuffer m_mergeBuffer;
    MarbleGeometryAssembler m_marbleMerger;
    MapData m_data;
    TileCache m_tileCache;
    OSM::BoundingBox m_tileBbox;
    QRect m_loadedTiles;
    std::vector<Tile> m_pendingTiles;
    BoundarySearch m_boundarySearcher;

    QString m_errorMessage;
};

}

#endif // KOSMINDOORMAP_MAPLOADER_H
