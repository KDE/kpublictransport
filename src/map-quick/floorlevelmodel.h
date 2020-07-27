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

#ifndef KOSMINDOORMAP_FLOORLEVELMODEL_H
#define KOSMINDOORMAP_FLOORLEVELMODEL_H

#include <QAbstractListModel>

#include <vector>

namespace KOSMIndoorMap {

class MapData;
class MapLevel;

/** Floor level model. */
class FloorLevelModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool hasFloorLevels READ hasFloorLevels NOTIFY contentChanged)

public:
    explicit FloorLevelModel(QObject *parent = nullptr);
    ~FloorLevelModel();

    void setMapData(MapData *data);

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    /** Maps a floor level to a model row index. */
    Q_INVOKABLE int rowForLevel(int level) const;
    /** Mapps a row index to a floor level. */
    Q_INVOKABLE int levelForRow(int row) const;

    /** Returns @c true when we can still go further down. */
    Q_INVOKABLE bool hasFloorLevelBelow(int level) const;
    /** Returns the floor level below @p level. */
    Q_INVOKABLE int floorLevelBelow(int level) const;
    /** Returns @c true when we can still go further up. */
    Q_INVOKABLE bool hasFloorLevelAbove(int level) const;
    /** Returns the floor level above @p level. */
    Q_INVOKABLE int floorLevelAbove(int level) const;

    /** Returns whether the given floor level has an explicit name
     *  obtained from the OSM data.
     */
    Q_INVOKABLE bool hasName(int level) const;
    /** Returns the name for the floor @p level.
     *  This is either an explicitly determined name from the OSM data
     *  or a numeric representation of the floor.
     */
    Q_INVOKABLE QString name(int level) const;

    /** We have more than the base/outdoor floor levels. */
    bool hasFloorLevels() const;

Q_SIGNALS:
    void contentChanged();

private:
    std::vector<MapLevel> m_level;
};

}

#endif // KOSMINDOORMAP_FLOORLEVELMODEL_H
