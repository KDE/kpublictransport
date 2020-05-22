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

#ifndef KOSMINDOORMAP_MAPDATA_H
#define KOSMINDOORMAP_MAPDATA_H

#include <osm/datatypes.h>
#include <osm/element.h>

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
    ~MapData();

    const OSM::DataSet& dataSet() const;
    void setDataSet(OSM::DataSet &&dataSet);

    OSM::BoundingBox boundingBox() const;

    // TODO efficient access API for this
    std::map<MapLevel, std::vector<OSM::Element>> m_levelMap;

private:
    void processElements();
    void parseLevel(QString &&level, OSM::Element e);
    void addElement(int level, OSM::Element e);
    QString levelName(OSM::Element e);
    void filterLevels();

    OSM::DataSet m_dataSet;
    OSM::BoundingBox m_bbox;
};

}

#endif // KOSMINDOORMAP_MAPDATA_H
