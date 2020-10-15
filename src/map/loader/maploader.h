/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_MAPLOADER_H
#define KOSMINDOORMAP_MAPLOADER_H

#include "kosmindoormap_export.h"

#include <QObject>

#include <memory>

/** OSM-based multi-floor indoor maps for buildings. */
namespace KOSMIndoorMap {

class MapData;
class MapLoaderPrivate;
class Tile;

/** Loader for OSM data for a single station or airport. */
class KOSMINDOORMAP_EXPORT MapLoader : public QObject
{
    Q_OBJECT
    /** Indicates we are downloading content. Use for progress display. */
    Q_PROPERTY(bool isLoading READ isLoading NOTIFY isLoadingChanged)
public:
    explicit MapLoader(QObject *parent = nullptr);
    ~MapLoader();

    /** Load a single O5M or OSM PBF file. */
    Q_INVOKABLE void loadFromFile(const QString &fileName);
    /** Load map for the given coordinates.
     *  This can involve online access.
     */
    Q_INVOKABLE void loadForCoordinate(double lat, double lon);
    /** Same as the above, but ensureing the requested data is cached until @p ttl. */
    void loadForCoordinate(double lat, double lon, const QDateTime &ttl);

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
    Tile makeTile(uint32_t x, uint32_t y) const;

    std::unique_ptr<MapLoaderPrivate> d;
};

}

#endif // KOSMINDOORMAP_MAPLOADER_H
