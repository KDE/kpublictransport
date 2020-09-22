/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "floorlevelchangemodel.h"

#include "loader/levelparser.h"
#include "loader/mapdata.h"

#include <QDebug>

using namespace KOSMIndoorMap;

FloorLevelChangeModel::FloorLevelChangeModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

FloorLevelChangeModel::~FloorLevelChangeModel() = default;

int FloorLevelChangeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return m_levels.size();
}

QVariant FloorLevelChangeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return {};
    }

    switch (role) {
        case Qt::DisplayRole:
            return m_levels[index.row()].name();
        case FloorLevelRole:
            return m_levels[index.row()].numericLevel();
        case CurrentFloorRole:
            return m_levels[index.row()].numericLevel() == m_currentFloorLevel;
    }
    return {};
}

QHash<int, QByteArray> FloorLevelChangeModel::roleNames() const
{
    auto n = QAbstractListModel::roleNames();
    n.insert(FloorLevelRole, "floorLevel");
    n.insert(CurrentFloorRole, "isCurrentFloor");
    return n;
}

int FloorLevelChangeModel::currentFloorLevel() const
{
    return m_currentFloorLevel;
}

void FloorLevelChangeModel::setCurrentFloorLevel(int level)
{
    if (m_currentFloorLevel == level) {
        return;
    }
    m_currentFloorLevel = level;
    if (!m_levels.empty()) {
        emit dataChanged(index(0, 0), index(rowCount() - 1, 0));
    }
    emit contentChanged();
}

FloorLevelModel* FloorLevelChangeModel::floorLevelModel() const
{
    return m_floorLevelModel;
}

void FloorLevelChangeModel::setFloorLevelModel(FloorLevelModel *floorLevelModel)
{
    if (m_floorLevelModel == floorLevelModel) {
        return;
    }

    m_floorLevelModel = floorLevelModel;
    emit contentChanged();
}

OSMElement FloorLevelChangeModel::element() const
{
    return OSMElement(m_element);
}

void FloorLevelChangeModel::setElement(const OSMElement &element)
{
    if (m_element == element.element()) {
        return;
    }

    beginResetModel();
    m_element = element.element();
    m_levels.clear();

    LevelParser::parse(m_element.tagValue("level", "repeat_on"), m_element, [this](int level, OSM::Element e) {
        Q_UNUSED(e);
        // TODO get the floor level model in here and retrieve the full MapLevel object from there, so we have proper names for the floors
        MapLevel ml(level);
        if (ml.isFullLevel()) {
            appendFloorLevel(level);
        } else {
            appendFloorLevel(ml.fullLevelBelow());
            appendFloorLevel(ml.fullLevelAbove());
        }
    });
    std::sort(m_levels.begin(), m_levels.end());
    m_levels.erase(std::unique(m_levels.begin(), m_levels.end()), m_levels.end());
    qDebug() << "currently on" << m_currentFloorLevel << "can change to" << m_levels.size() << "levels";
    for (const auto &l : m_levels) {
        qDebug() << "  " << l.numericLevel();
    }

    endResetModel();
    emit contentChanged();
}

void FloorLevelChangeModel::appendFloorLevel(int level)
{
    if (!m_floorLevelModel) {
        m_levels.push_back(MapLevel(level));
    } else {
        const auto row = m_floorLevelModel->rowForLevel(level);
        if (row >= 0) {
            const auto idx = m_floorLevelModel->index(row, 0);
            m_levels.push_back(m_floorLevelModel->data(idx, FloorLevelModel::MapLevelRole).value<MapLevel>());
        }
    }
}

bool FloorLevelChangeModel::hasSingleLevelChange() const
{
    if (m_levels.size() != 2) {
        return false;
    }
    return m_levels[0].numericLevel() == m_currentFloorLevel || m_levels[1].numericLevel() == m_currentFloorLevel;
}

int FloorLevelChangeModel::destinationLevel() const
{
    if (m_levels.size() != 2) {
        return 0;
    }
    return m_levels[0].numericLevel() == m_currentFloorLevel ? m_levels[1].numericLevel() : m_levels[0].numericLevel();
}

QString FloorLevelChangeModel::destinationLevelName() const
{
    if (m_levels.size() != 2) {
        return {};
    }
    return m_levels[0].numericLevel() == m_currentFloorLevel ? m_levels[1].name() : m_levels[0].name();
}

bool FloorLevelChangeModel::hasMultipleLevelChanges() const
{
    return m_levels.size() > 1;
}
