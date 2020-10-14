/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "maploader.h"
#include "boundarysearch.h"
#include "logging.h"
#include "mapdata.h"
#include "marblegeometryassembler_p.h"
#include "tilecache_p.h"

#include <osm/datatypes.h>
#include <osm/datasetmergebuffer.h>
#include <osm/element.h>
#include <osm/o5mparser.h>
#include <osm/osmpbfparser.h>
#include <osm/xmlparser.h>

#include <QDateTime>
#include <QElapsedTimer>
#include <QFile>
#include <QRect>
#include <QUrl>

enum {
    TileZoomLevel = 17
};

inline void initResources()  // needs to be outside of a namespace
{
    Q_INIT_RESOURCE(assets);
}

namespace KOSMIndoorMap {
class MapLoaderPrivate {
public:
    OSM::DataSet m_dataSet;
    OSM::DataSetMergeBuffer m_mergeBuffer;
    MarbleGeometryAssembler m_marbleMerger;
    MapData m_data;
    TileCache m_tileCache;
    OSM::BoundingBox m_tileBbox;
    QRect m_loadedTiles;
    std::vector<Tile> m_pendingTiles;
    BoundarySearch m_boundarySearcher;
    QDateTime m_ttl;

    QString m_errorMessage;
};
}

using namespace KOSMIndoorMap;

MapLoader::MapLoader(QObject *parent)
    : QObject(parent)
    , d(new MapLoaderPrivate)
{
    initResources();
    connect(&d->m_tileCache, &TileCache::tileLoaded, this, &MapLoader::downloadFinished);
    connect(&d->m_tileCache, &TileCache::tileError, this, &MapLoader::downloadFailed);
    d->m_tileCache.expire();
}

MapLoader::~MapLoader() = default;

void MapLoader::loadFromFile(const QString &fileName)
{
    QElapsedTimer loadTime;
    loadTime.start();

    d->m_errorMessage.clear();
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
    d->m_data.setDataSet(std::move(ds));
    qCDebug(Log) << "o5m loading took" << loadTime.elapsed() << "ms";
    Q_EMIT done();
}

void MapLoader::loadForCoordinate(double lat, double lon)
{
    loadForCoordinate(lat, lon, {});
}

void MapLoader::loadForCoordinate(double lat, double lon, const QDateTime &ttl)
{
    d->m_ttl = ttl;
    d->m_tileBbox = {};
    d->m_pendingTiles.clear();
    d->m_boundarySearcher.init(OSM::Coordinate(lat, lon));
    d->m_errorMessage.clear();
    d->m_marbleMerger.setDataSet(&d->m_dataSet);

    auto tile = Tile::fromCoordinate(lat, lon, TileZoomLevel);
    d->m_loadedTiles = QRect(tile.x, tile.y, 1, 1);
    d->m_pendingTiles.push_back(std::move(tile));
    downloadTiles();
}

MapData&& MapLoader::takeData()
{
    return std::move(d->m_data);
}

void MapLoader::downloadTiles()
{
    for (const auto &tile : d->m_pendingTiles) {
        d->m_tileCache.ensureCached(tile);
    }
    if (d->m_tileCache.pendingDownloads() == 0) {
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
    if (d->m_tileCache.pendingDownloads() > 0) {
        return;
    }
    loadTiles();
}

void MapLoader::loadTiles()
{
    QElapsedTimer loadTime;
    loadTime.start();

    OSM::O5mParser p(&d->m_dataSet);
    p.setMergeBuffer(&d->m_mergeBuffer);
    for (const auto &tile : d->m_pendingTiles) {
        const auto fileName = d->m_tileCache.cachedTile(tile);
        qCDebug(Log) << "loading tile" << fileName;
        QFile f(fileName);
        if (!f.open(QFile::ReadOnly)) {
            qWarning() << f.fileName() << f.errorString();
            break;
        }
        const auto data = f.map(0, f.size());
        p.parse(data, f.size());
        d->m_marbleMerger.merge(&d->m_mergeBuffer);

        d->m_tileBbox = OSM::unite(d->m_tileBbox, tile.boundingBox());
    }
    d->m_pendingTiles.clear();

    const auto bbox = d->m_boundarySearcher.boundingBox(d->m_dataSet);
    qCDebug(Log) << "needed bbox:" << bbox << "got:" << d->m_tileBbox << d->m_loadedTiles;

    // expand left and right
    if (bbox.min.longitude < d->m_tileBbox.min.longitude) {
        d->m_loadedTiles.setLeft(d->m_loadedTiles.left() - 1);
        for (int y = d->m_loadedTiles.top(); y <= d->m_loadedTiles.bottom(); ++y) {
            d->m_pendingTiles.push_back(makeTile(d->m_loadedTiles.left(), y));
        }
    }
    if (bbox.max.longitude > d->m_tileBbox.max.longitude) {
        d->m_loadedTiles.setRight(d->m_loadedTiles.right() + 1);
        for (int y = d->m_loadedTiles.top(); y <= d->m_loadedTiles.bottom(); ++y) {
            d->m_pendingTiles.push_back(makeTile(d->m_loadedTiles.right(), y));
        }
    }

    // expand top/bottom: note that geographics and slippy map tile coordinates have a different understanding on what is "top"
    if (bbox.max.latitude > d->m_tileBbox.max.latitude) {
        d->m_loadedTiles.setTop(d->m_loadedTiles.top() - 1);
        for (int x = d->m_loadedTiles.left(); x <= d->m_loadedTiles.right(); ++x) {
            d->m_pendingTiles.push_back(makeTile(x, d->m_loadedTiles.top()));
        }
    }
    if (bbox.min.latitude < d->m_tileBbox.min.latitude) {
        d->m_loadedTiles.setBottom(d->m_loadedTiles.bottom() + 1);
        for (int x = d->m_loadedTiles.left(); x <= d->m_loadedTiles.right(); ++x) {
            d->m_pendingTiles.push_back(makeTile(x, d->m_loadedTiles.bottom()));
        }
    }

    if (!d->m_pendingTiles.empty()) {
        downloadTiles();
        return;
    }

    d->m_marbleMerger.finalize();
    d->m_data.setDataSet(std::move(d->m_dataSet));
    d->m_data.setBoundingBox(bbox);

    qCDebug(Log) << "o5m loading took" << loadTime.elapsed() << "ms";
    Q_EMIT isLoadingChanged();
    Q_EMIT done();
}

Tile MapLoader::makeTile(uint32_t x, uint32_t y) const
{
    auto tile = Tile(x, y, TileZoomLevel);
    tile.ttl = d->m_ttl;
    return tile;
}

void MapLoader::downloadFailed(Tile tile, const QString& errorMessage)
{
    Q_UNUSED(tile);
    d->m_errorMessage = errorMessage;
    d->m_tileCache.cancelPending();
    Q_EMIT isLoadingChanged();
    Q_EMIT done();
}

bool MapLoader::isLoading() const
{
    return d->m_tileCache.pendingDownloads() > 0;
}

bool MapLoader::hasError() const
{
    return !d->m_errorMessage.isEmpty();
}

QString MapLoader::errorMessage() const
{
    return d->m_errorMessage;
}
