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

#include "maploader.h"
#include "boundarysearch.h"

#include <osm/element.h>
#include <osm/o5mparser.h>

#include <QDebug>
#include <QElapsedTimer>
#include <QFile>

enum {
    TileZoomLevel = 17
};

inline void initResources()  // needs to be outside of a namespace
{
    Q_INIT_RESOURCE(assets);
}

using namespace KOSMIndoorMap;

MapLoader::MapLoader(QObject *parent)
    : QObject(parent)
{
    initResources();
    connect(&m_tileCache, &TileCache::tileLoaded, this, &MapLoader::downloadFinished);
}

MapLoader::~MapLoader() = default;

void MapLoader::loadFromO5m(const QString &fileName)
{
    QElapsedTimer loadTime;
    loadTime.start();

    QFile f(fileName);
    if (!f.open(QFile::ReadOnly)) {
        qCritical() << f.fileName() << f.errorString();
        return;
    }
    const auto data = f.map(0, f.size());

    OSM::DataSet ds;
    OSM::O5mParser p(&ds);
    p.parse(data, f.size());
    m_data.setDataSet(std::move(ds));
    qDebug() << "o5m loading took" << loadTime.elapsed() << "ms";
    Q_EMIT done();
}

void MapLoader::loadForCoordinate(double lat, double lon)
{
    m_tileBbox = {};
    m_pendingTiles.clear();
    m_boundarySearcher.init(OSM::Coordinate(lat, lon));

    const auto tile = Tile::fromCoordinate(lat, lon, TileZoomLevel);
    m_pendingTiles.push_back(tile);
    m_loadedTiles = QRect(tile.x, tile.y, 1, 1);
    downloadTiles();
}

MapData&& MapLoader::takeData()
{
    return std::move(m_data);
}

void MapLoader::downloadTiles()
{
    for (const auto &tile : m_pendingTiles) {
        m_tileCache.ensureCached(tile);
    }
    if (m_tileCache.pendingDownloads() == 0) {
        loadTiles();
    } else {
        Q_EMIT isLoadingChanged();
    }
}

void MapLoader::downloadFinished()
{
    if (m_tileCache.pendingDownloads() > 0) {
        return;
    }
    loadTiles();
}

void MapLoader::loadTiles()
{
    QElapsedTimer loadTime;
    loadTime.start();

    OSM::O5mParser p(&m_dataSet);
    p.setMergeBuffer(&m_mergeBuffer);
    for (const auto &tile : m_pendingTiles) {
        const auto fileName = m_tileCache.cachedTile(tile);
        qDebug() << fileName;
        QFile f(fileName);
        if (!f.open(QFile::ReadOnly)) {
            qWarning() << f.fileName() << f.errorString();
            break;
        }
        const auto data = f.map(0, f.size());
        p.parse(data, f.size());
        m_marbleMerger.merge(&m_dataSet, &m_mergeBuffer);

        m_tileBbox = OSM::unite(m_tileBbox, tile.boundingBox());
    }
    m_pendingTiles.clear();

    const auto bbox = m_boundarySearcher.boundingBox(m_dataSet);
    qDebug() << "needed bbox:" << bbox << "got:" << m_tileBbox << m_loadedTiles;

    // expand left and right
    if (bbox.min.longitude < m_tileBbox.min.longitude) {
        m_loadedTiles.setLeft(m_loadedTiles.left() - 1);
        for (int y = m_loadedTiles.top(); y <= m_loadedTiles.bottom(); ++y) {
            m_pendingTiles.push_back(Tile(m_loadedTiles.left(), y, TileZoomLevel));
        }
    }
    if (bbox.max.longitude > m_tileBbox.max.longitude) {
        m_loadedTiles.setRight(m_loadedTiles.right() + 1);
        for (int y = m_loadedTiles.top(); y <= m_loadedTiles.bottom(); ++y) {
            m_pendingTiles.push_back(Tile(m_loadedTiles.right(), y, TileZoomLevel));
        }
    }

    // expand top/bottom: note that geographics and slippy map tile coordinates have a different understanding on what is "top"
    if (bbox.max.latitude > m_tileBbox.max.latitude) {
        m_loadedTiles.setTop(m_loadedTiles.top() - 1);
        for (int x = m_loadedTiles.left(); x <= m_loadedTiles.right(); ++x) {
            m_pendingTiles.push_back(Tile(x, m_loadedTiles.top(), TileZoomLevel));
        }
    }
    if (bbox.min.latitude < m_tileBbox.min.latitude) {
        m_loadedTiles.setBottom(m_loadedTiles.bottom() + 1);
        for (int x = m_loadedTiles.left(); x <= m_loadedTiles.right(); ++x) {
            m_pendingTiles.push_back(Tile(x, m_loadedTiles.bottom(), TileZoomLevel));
        }
    }

    if (!m_pendingTiles.empty()) {
        downloadTiles();
        return;
    }

    m_marbleMerger.finalize(&m_dataSet, &m_mergeBuffer);
    m_data.setDataSet(std::move(m_dataSet));
    m_data.setBoundingBox(bbox);

    qDebug() << "o5m loading took" << loadTime.elapsed() << "ms";
    Q_EMIT isLoadingChanged();
    Q_EMIT done();
}

bool MapLoader::isLoading() const
{
    return m_tileCache.pendingDownloads() > 0;
}
