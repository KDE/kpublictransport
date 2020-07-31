/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_PLATFORMMODEL_H
#define KOSMINDOORMAP_PLATFORMMODEL_H

#include <osm/element.h>

#include <QAbstractListModel>
#include <QCollator>

namespace KOSMIndoorMap {

class MapData;

/** A railway platform/track. */
class Platform {
    Q_GADGET
public:
    OSM::Element element;
    OSM::Element track;
    QString name;
    int level = 0;
    enum Mode {
        Rail,
        Subway,
        Tram,
        Bus,
    };
    Mode mode = Rail;
    QStringList lines;

    Q_ENUM(Mode)
};

/** A railway platform section. */
struct PlatformSection {
    // TODO
};

/** Lists all platforms/tracks and platform sections found in the current map.
 *  There's also the concept of (optional) arrival/departure platforms in here to highlight
 *  arriving/departing locations when used in context of a planned journey.
 */
class PlatformModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(const KOSMIndoorMap::MapData* mapData READ mapData WRITE setMapData NOTIFY mapDataChanged)
    Q_PROPERTY(bool isEmpty READ isEmpty NOTIFY mapDataChanged)

    /** Row indexes of the matched arrival/departure platforms, if found and/or set, otherwise @c -1. */
    Q_PROPERTY(int arrivalPlatformRow READ arrivalPlatformRow NOTIFY platformIndexChanged)
    Q_PROPERTY(int departurePlatformRow READ departurePlatformRow NOTIFY platformIndexChanged)
public:
    explicit PlatformModel(QObject *parent = nullptr);
    ~PlatformModel();

    const MapData* mapData() const;
    void setMapData(const MapData *data);

    bool isEmpty() const;

    enum Role {
        CoordinateRole = Qt::UserRole,
        LevelRole,
        TransportModeRole,
        LinesRole,
        ArrivalPlatformRole,
        DeparturePlatformRole,
    };
    Q_ENUM(Role)

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;
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
    void populateModel();
    void scanRoute(OSM::Element e, OSM::Element route);
    void scanRoute(const OSM::Node &node, OSM::Element route);
    void addPlatform(Platform &&platform);
    void matchPlatforms();
    int matchPlatform(const Platform &platform) const;

    static bool comparePlatform(const Platform &lhs, const Platform &rhs);

    std::vector<Platform> m_platforms;
    const MapData *m_data = nullptr;
    static QCollator m_collator;

    OSM::TagKey m_ptKey;

    Platform m_arrivalPlatform;
    Platform m_departurePlatform;
    int m_arrivalPlatformRow = -1;
    int m_departurePlatformRow = -1;
};

}

Q_DECLARE_METATYPE(KOSMIndoorMap::Platform)

#endif // KOSMINDOORMAP_PLATFORMMODEL_H
