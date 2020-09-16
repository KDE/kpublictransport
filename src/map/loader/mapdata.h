/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_MAPDATA_H
#define KOSMINDOORMAP_MAPDATA_H

#include <osm/datatypes.h>
#include <osm/element.h>

#include <QMetaType>

#include <map>
#include <vector>

namespace KOSMIndoorMap {

/** A floor level. */
class MapLevel
{
public:
    explicit MapLevel(int level = 0);
    ~MapLevel();

    bool operator<(const MapLevel &other) const;
    bool operator==(const MapLevel &other) const;

    bool hasName() const;
    QString name() const;
    void setName(const QString &name);
    bool isFullLevel() const;

    int numericLevel() const;

private:
    int m_level = 0;
    QString m_levelName;
};
}

namespace KOSMIndoorMap {

/** Raw OSM map data, separated by levels. */
class MapData
{
public:
    explicit MapData();
    MapData(const MapData&) = delete;
    MapData(MapData&&);
    ~MapData();

    MapData& operator=(const MapData&) = delete;
    MapData& operator=(MapData&&);

    const OSM::DataSet& dataSet() const;
    OSM::DataSet& dataSet();
    void setDataSet(OSM::DataSet &&dataSet);

    OSM::BoundingBox boundingBox() const;
    void setBoundingBox(OSM::BoundingBox bbox);

    // TODO efficient access API for this
    std::map<MapLevel, std::vector<OSM::Element>> m_levelMap;

private:
    void processElements();
    void parseLevel(QByteArray &&level, OSM::Element e, bool isDependentElement);
    void addElement(int level, OSM::Element e, bool isDependentElement);
    QString levelName(OSM::Element e);
    void filterLevels();

    OSM::DataSet m_dataSet;
    OSM::BoundingBox m_bbox;

    OSM::TagKey m_levelRefTag;
    OSM::TagKey m_nameTag;

    std::map<MapLevel, std::size_t> m_dependentElementCounts;
};

}

Q_DECLARE_METATYPE(KOSMIndoorMap::MapData*)

#endif // KOSMINDOORMAP_MAPDATA_H
