/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "maploader.h"
#include "boundarysearch.h"
#include "logging.h"

#include <osm/element.h>
#include <osm/o5mparser.h>
#include <osm/osmpbfparser.h>
#include <osm/xmlparser.h>

#include <QDateTime>
#include <QElapsedTimer>
#include <QFile>
#include <QUrl>

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
    connect(&m_tileCache, &TileCache::tileError, this, &MapLoader::downloadFailed);
    m_tileCache.expire();
}

MapLoader::~MapLoader() = default;

void MapLoader::loadFromFile(const QString &fileName)
{
    QElapsedTimer loadTime;
    loadTime.start();

    m_errorMessage.clear();
    QFile f(fileName.contains(QLatin1Char(':')) ? QUrl::fromUserInput(fileName).toLocalFile() : fileName);
    if (!f.open(QFile::ReadOnly)) {
        qCritical() << f.fileName() << f.errorString();
        return;
    }
    const auto data = f.map(0, f.size());

    OSM::DataSet ds;
    if (fileName.endsWith(QLatin1String(".osm.pbf"))) {
        OSM::OsmPbfParser p(&ds);
        p.parse(data, f.size());
    } else if (fileName.endsWith(QLatin1String(".osm"))) {
        qDebug() << fileName << f.pos() <<f.size();
        OSM::XmlParser p(&ds);
        p.parse(&f);
    } else {
        OSM::O5mParser p(&ds);
        p.parse(data, f.size());
    }
    m_data.setDataSet(std::move(ds));
    qCDebug(Log) << "o5m loading took" << loadTime.elapsed() << "ms";
    Q_EMIT done();
}

void MapLoader::loadForCoordinate(double lat, double lon)
{
    loadForCoordinate(lat, lon, {});
}

void MapLoader::loadForCoordinate(double lat, double lon, const QDateTime &ttl)
{
    m_ttl = ttl;
    m_tileBbox = {};
    m_pendingTiles.clear();
    m_boundarySearcher.init(OSM::Coordinate(lat, lon));
    m_errorMessage.clear();
    m_marbleMerger.setDataSet(&m_dataSet);

    auto tile = Tile::fromCoordinate(lat, lon, TileZoomLevel);
    m_loadedTiles = QRect(tile.x, tile.y, 1, 1);
    m_pendingTiles.push_back(std::move(tile));
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
        // still go through the event loop when having everything cached already
        // this makes outside behavior more identical in both cases, and avoids
        // signal connection races etc.
        QMetaObject::invokeMethod(this, &MapLoader::loadTiles, Qt::QueuedConnection);
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
        qCDebug(Log) << "loading tile" << fileName;
        QFile f(fileName);
        if (!f.open(QFile::ReadOnly)) {
            qWarning() << f.fileName() << f.errorString();
            break;
        }
        const auto data = f.map(0, f.size());
        p.parse(data, f.size());
        m_marbleMerger.merge(&m_mergeBuffer);

        m_tileBbox = OSM::unite(m_tileBbox, tile.boundingBox());
    }
    m_pendingTiles.clear();

    const auto bbox = m_boundarySearcher.boundingBox(m_dataSet);
    qCDebug(Log) << "needed bbox:" << bbox << "got:" << m_tileBbox << m_loadedTiles;

    // expand left and right
    if (bbox.min.longitude < m_tileBbox.min.longitude) {
        m_loadedTiles.setLeft(m_loadedTiles.left() - 1);
        for (int y = m_loadedTiles.top(); y <= m_loadedTiles.bottom(); ++y) {
            m_pendingTiles.push_back(makeTile(m_loadedTiles.left(), y));
        }
    }
    if (bbox.max.longitude > m_tileBbox.max.longitude) {
        m_loadedTiles.setRight(m_loadedTiles.right() + 1);
        for (int y = m_loadedTiles.top(); y <= m_loadedTiles.bottom(); ++y) {
            m_pendingTiles.push_back(makeTile(m_loadedTiles.right(), y));
        }
    }

    // expand top/bottom: note that geographics and slippy map tile coordinates have a different understanding on what is "top"
    if (bbox.max.latitude > m_tileBbox.max.latitude) {
        m_loadedTiles.setTop(m_loadedTiles.top() - 1);
        for (int x = m_loadedTiles.left(); x <= m_loadedTiles.right(); ++x) {
            m_pendingTiles.push_back(makeTile(x, m_loadedTiles.top()));
        }
    }
    if (bbox.min.latitude < m_tileBbox.min.latitude) {
        m_loadedTiles.setBottom(m_loadedTiles.bottom() + 1);
        for (int x = m_loadedTiles.left(); x <= m_loadedTiles.right(); ++x) {
            m_pendingTiles.push_back(makeTile(x, m_loadedTiles.bottom()));
        }
    }

    if (!m_pendingTiles.empty()) {
        downloadTiles();
        return;
    }

    m_marbleMerger.finalize();
    m_data.setDataSet(std::move(m_dataSet));
    m_data.setBoundingBox(bbox);

    qCDebug(Log) << "o5m loading took" << loadTime.elapsed() << "ms";
    Q_EMIT isLoadingChanged();
    Q_EMIT done();
}

Tile MapLoader::makeTile(uint32_t x, uint32_t y) const
{
    auto tile = Tile(x, y, TileZoomLevel);
    tile.ttl = m_ttl;
    return tile;
}

void MapLoader::downloadFailed(Tile tile, const QString& errorMessage)
{
    Q_UNUSED(tile);
    m_errorMessage = errorMessage;
    m_tileCache.cancelPending();
    Q_EMIT isLoadingChanged();
    Q_EMIT done();
}

bool MapLoader::isLoading() const
{
    return m_tileCache.pendingDownloads() > 0;
}

bool MapLoader::hasError() const
{
    return !m_errorMessage.isEmpty();
}

QString MapLoader::errorMessage() const
{
    return m_errorMessage;
}
