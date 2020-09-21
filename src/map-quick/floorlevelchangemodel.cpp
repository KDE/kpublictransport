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
    // TODO
    return {};
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
            m_levels.push_back(ml);
        } else {
            m_levels.push_back(MapLevel(ml.fullLevelBelow()));
            m_levels.push_back(MapLevel(ml.fullLevelAbove()));
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

bool FloorLevelChangeModel::hasMultipleLevelChanges() const
{
    return m_levels.size() > 1;
}
