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

#include "floorlevelmodel.h"

#include <KOSMIndoorMap/MapData>

using namespace KOSMIndoorMap;

FloorLevelModel::FloorLevelModel(QObject *parent)
    : QAbstractListModel(parent)
{
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

    if (role == Qt::DisplayRole) {
        return m_level[index.row()].name();
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
