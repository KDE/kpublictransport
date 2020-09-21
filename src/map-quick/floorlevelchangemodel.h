/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_FLOORLEVELCHANGEMODEL_H
#define KOSMINDOORMAP_FLOORLEVELCHANGEMODEL_H

#include "osmelement.h"

#include <osm/element.h>

#include <QAbstractListModel>

#include <vector>

namespace KOSMIndoorMap {

class MapLevel;

/** Floor level changes on steps or elevators. */
class FloorLevelChangeModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int currentFloorLevel READ currentFloorLevel WRITE setCurrentFloorLevel NOTIFY contentChanged)
    Q_PROPERTY(KOSMIndoorMap::OSMElement element READ element WRITE setElement NOTIFY contentChanged)

    /** The current element changes to a single other floor, ie. typically stairs or a ramp. */
    Q_PROPERTY(bool hasSingleLevelChange READ hasSingleLevelChange NOTIFY contentChanged)
    /** The destination level for a single level change. */
    Q_PROPERTY(int destinationLevel READ destinationLevel NOTIFY contentChanged)

    /** The current element changes to multiple levels based on users choice, ie. typically an elevator.
     *  The model in this case provides the levels that are reachable.
     */
    Q_PROPERTY(bool hasMultipleLevelChanges READ hasMultipleLevelChanges NOTIFY contentChanged)

public:
    explicit FloorLevelChangeModel(QObject *parent = nullptr);
    ~FloorLevelChangeModel();

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    int currentFloorLevel() const;
    void setCurrentFloorLevel(int level);
    OSMElement element() const;
    void setElement(const OSMElement &element);

    bool hasSingleLevelChange() const;
    int destinationLevel() const;
    bool hasMultipleLevelChanges() const;

Q_SIGNALS:
    void contentChanged();

private:
    int m_currentFloorLevel = 0;
    OSM::Element m_element;
    std::vector<MapLevel> m_levels;
};

}

#endif // KOSMINDOORMAP_FLOORLEVELCHANGEMODEL_H
