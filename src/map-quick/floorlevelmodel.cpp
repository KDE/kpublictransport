/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "floorlevelmodel.h"

#include <KOSMIndoorMap/MapData>

using namespace KOSMIndoorMap;

FloorLevelModel::FloorLevelModel(QObject *parent)
    : QAbstractListModel(parent)
{
    connect(this, &QAbstractItemModel::modelReset, this, &FloorLevelModel::contentChanged);
}

FloorLevelModel::~FloorLevelModel() = default;

void FloorLevelModel::setMapData(MapData *data)
{
    beginResetModel();
    m_level.clear();
    if (data) {
        for (const auto &l : data->m_levelMap) {
            if (l.first.isFullLevel()) {
                m_level.push_back(l.first);
            }
        }
    }
    endResetModel();
}

int FloorLevelModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return m_level.size();
}

QVariant FloorLevelModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return {};
    }

    switch (role) {
        case Qt::DisplayRole:
            return m_level[index.row()].name();
        case MapLevelRole:
            return QVariant::fromValue(m_level[index.row()]);
    }

    return {};
}

int FloorLevelModel::rowForLevel(int level) const
{
    for (auto it = m_level.begin(); it != m_level.end(); ++it) {
        if ((*it).numericLevel() == level) {
            return std::distance(m_level.begin(), it);
        }
    }
    return -1;
}

int FloorLevelModel::levelForRow(int row) const
{
    return m_level[row].numericLevel();
}

bool FloorLevelModel::hasFloorLevelBelow(int level) const
{
    if (m_level.empty()) {
        return false;
    }
    return m_level.back().numericLevel() != level;
}

int FloorLevelModel::floorLevelBelow(int level) const
{
    for (auto it = m_level.begin(); it != m_level.end(); ++it) {
        if ((*it).numericLevel() == level && std::next(it) != m_level.end()) {
            ++it;
            return (*it).numericLevel();
        }
    }
    return 0;
}

bool FloorLevelModel::hasFloorLevelAbove(int level) const
{
    if (m_level.empty()) {
        return false;
    }

    return m_level.front().numericLevel() != level;
}

int FloorLevelModel::floorLevelAbove(int level) const
{
    for (auto it = std::next(m_level.begin()); it != m_level.end(); ++it) {
        if ((*it).numericLevel() == level) {
            --it;
            return (*it).numericLevel();
        }
    }
    return 0;
}

bool FloorLevelModel::hasName(int level) const
{
    for (auto it = m_level.begin(); it != m_level.end(); ++it) {
        if ((*it).numericLevel() == level) {
            return (*it).hasName();
        }
    }
    return false;
}

QString FloorLevelModel::name(int level) const
{
    for (auto it = m_level.begin(); it != m_level.end(); ++it) {
        if ((*it).numericLevel() == level) {
            return (*it).name();
        }
    }
    return {};
}

bool FloorLevelModel::hasFloorLevels() const
{
    return rowCount() > 1;
}
