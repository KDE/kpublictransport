/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_PLATFORMMODEL_H
#define KOSMINDOORMAP_PLATFORMMODEL_H

#include "kosmindoormap_export.h"

#include "platform.h"

#include <QAbstractItemModel>

namespace KOSMIndoorMap {

class MapData;

/** Lists all platforms/tracks and platform sections found in the current map.
 *  There's also the concept of (optional) arrival/departure platforms in here to highlight
 *  arriving/departing locations when used in context of a planned journey.
 */
class KOSMINDOORMAP_EXPORT PlatformModel : public QAbstractItemModel
{
    Q_OBJECT
    Q_PROPERTY(KOSMIndoorMap::MapData* mapData READ mapData WRITE setMapData NOTIFY mapDataChanged)
    Q_PROPERTY(bool isEmpty READ isEmpty NOTIFY mapDataChanged)

    /** Row indexes of the matched arrival/departure platforms, if found and/or set, otherwise @c -1. */
    Q_PROPERTY(int arrivalPlatformRow READ arrivalPlatformRow NOTIFY platformIndexChanged)
    Q_PROPERTY(int departurePlatformRow READ departurePlatformRow NOTIFY platformIndexChanged)
public:
    explicit PlatformModel(QObject *parent = nullptr);
    ~PlatformModel();

    MapData* mapData() const;
    void setMapData(MapData *data);

    bool isEmpty() const;

    enum Role {
        CoordinateRole = Qt::UserRole,
        ElementRole,
        LevelRole,
        TransportModeRole,
        LinesRole,
        ArrivalPlatformRole,
        DeparturePlatformRole,
    };
    Q_ENUM(Role)

    int columnCount(const QModelIndex &parent = {}) const override;
    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = {}) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    QHash<int, QByteArray> roleNames() const override;

    /** Match arrival/departure platform against what we found in the map data. */
    Q_INVOKABLE void setArrivalPlatform(const QString &name, KOSMIndoorMap::Platform::Mode mode);
    Q_INVOKABLE void setDeparturePlatform(const QString &name, KOSMIndoorMap::Platform::Mode mode);

    int arrivalPlatformRow() const;
    int departurePlatformRow() const;

Q_SIGNALS:
    void mapDataChanged();
    void platformIndexChanged();

private:
    void matchPlatforms();
    int matchPlatform(const Platform &platform) const;
    void createLabels();
    void setPlatformTag(int idx, OSM::TagKey key, bool enabled);

    std::vector<Platform> m_platforms;
    MapData *m_data = nullptr;
    struct {
        OSM::TagKey arrival;
        OSM::TagKey departure;
    } m_tagKeys;

    std::vector<OSM::UniqueElement> m_platformLabels;
    std::vector<std::vector<OSM::UniqueElement>> m_sectionsLabels;

    Platform m_arrivalPlatform;
    Platform m_departurePlatform;
    int m_arrivalPlatformRow = -1;
    int m_departurePlatformRow = -1;
};

}

#endif // KOSMINDOORMAP_PLATFORMMODEL_H
