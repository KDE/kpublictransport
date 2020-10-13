/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_MAPDATA_H
#define KOSMINDOORMAP_MAPDATA_H

#include "kosmindoormap_export.h"

#include <osm/datatypes.h>
#include <osm/element.h>

#include <QMetaType>

#include <map>
#include <vector>

namespace KOSMIndoorMap {

/** A floor level. */
class KOSMINDOORMAP_EXPORT MapLevel
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
    /** In case this is not a full level, this returns the numeric values of the full levels above/below. */
    int fullLevelBelow() const;
    int fullLevelAbove() const;

    int numericLevel() const;

private:
    int m_level = 0;
    QString m_levelName;
};
}

Q_DECLARE_METATYPE(KOSMIndoorMap::MapLevel)

namespace KOSMIndoorMap {

/** Raw OSM map data, separated by levels. */
class KOSMINDOORMAP_EXPORT MapData
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
