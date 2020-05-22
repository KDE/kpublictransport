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

#include "mapdata.h"

using namespace KOSMIndoorMap;

MapLevel::MapLevel(int level)
    : m_level(level)
{
}

MapLevel::~MapLevel() = default;

bool MapLevel::operator<(const MapLevel &other) const
{
    return m_level > other.m_level;
}

bool MapLevel::operator==(const MapLevel &other) const
{
    return m_level == other.m_level;
}

bool MapLevel::hasName() const
{
    return !m_levelName.isEmpty();
}

QString MapLevel::name() const
{
    if (m_levelName.isEmpty()) {
        return QString::number(m_level / 10);
    }
    return m_levelName;
}

void MapLevel::setName(const QString &name)
{
    m_levelName = name;
}

bool MapLevel::isFullLevel() const
{
    return m_level % 10 == 0;
}

int MapLevel::numericLevel() const
{
    return m_level;
}


MapData::MapData() = default;
MapData::~MapData() = default;

const OSM::DataSet& MapData::dataSet() const
{
    return m_dataSet;
}

void MapData::setDataSet(OSM::DataSet &&dataSet)
{
    m_dataSet = std::move(dataSet);
    m_levelMap.clear();
    determineLevels();
    filterLevels();
}

void MapData::determineLevels()
{
    OSM::for_each(m_dataSet, [this](auto e) {
        auto level = e.tagValue("level");
        if (level.isEmpty()) {
            level = e.tagValue("repeat_on");
        }

        if (level.isEmpty()) { // level-less -> outdoor
            m_levelMap[MapLevel{}].push_back(e);
            return;
        }

        parseLevel(std::move(level), e);
    });
}

// @see https://wiki.openstreetmap.org/wiki/Key:level
// @see https://wiki.openstreetmap.org/wiki/Simple_Indoor_Tagging#Multi-level_features_and_repeated_features
void MapData::parseLevel(QString &&level, OSM::Element e)
{
    int rangeBegin = std::numeric_limits<int>::max();
    int numStartIdx = -1;

    for (int i = 0; i < level.size(); ++i) {
        auto c = level[i];

        if (c == QLatin1Char(',')) { // fix decimal separator errors
            c = QLatin1Char('.');
        }

        if (c.isDigit() || c == QLatin1Char('.')) {
            if (numStartIdx < 0) {
                numStartIdx = i;
            }
            continue;
        }

        if (c == QLatin1Char(';')) {
            const auto l = QStringRef(&level, numStartIdx, i - numStartIdx).toFloat() * 10;
            if (rangeBegin < l) {
                for (int j = rangeBegin; j < l; j += 10) {
                    addElement(j, e);
                }
                rangeBegin = std::numeric_limits<int>::max();
            } else {
                addElement(l, e);
            }
            numStartIdx = -1;
            continue;
        }

        if (c == QLatin1Char('-')) {
            if (numStartIdx < 0) {
                numStartIdx = i;
            } else {
                rangeBegin = QStringRef(&level, numStartIdx, i - numStartIdx).toFloat() * 10;
                numStartIdx = -1;
            }
        }
    }

    const auto l = QStringRef(&level, numStartIdx, level.size() - numStartIdx).toFloat() * 10;
    if (rangeBegin < l) {
        for (int j = rangeBegin; j < l; j += 10) {
            addElement(j, e);
        }
    } else {
        addElement(l, e);
    }
}

void MapData::addElement(int level, OSM::Element e)
{
    MapLevel l(level);
    auto it = m_levelMap.find(l);
    if (it == m_levelMap.end()) {
        l.setName(levelName(e));
        m_levelMap[l] = {e};
    } else {
        if (!(*it).first.hasName()) {
            // name does not influence op< behavior, so modifying the key here is safe
            const_cast<MapLevel&>((*it).first).setName(levelName(e));
        }
        (*it).second.push_back(e);
    }
}

QString MapData::levelName(OSM::Element e)
{
    const auto n = e.tagValue("level:ref");
    if (!n.isEmpty()) {
        return n;
    }

    if (e.type() == OSM::Type::Relation) {
        const auto isLevelRel = std::all_of(e.relation()->members.begin(), e.relation()->members.end(), [](const auto &mem) {
            return mem.role == QLatin1String("shell") || mem.role == QLatin1String("buildingpart");
        });
        if (isLevelRel) {
            return e.tagValue("name");
        }
    }

    return {};
}

void MapData::filterLevels()
{
    // remove all-node levels as we can't display anything meaningfully there
    for (auto it = m_levelMap.begin(); it != m_levelMap.end();) {
        const auto isNonVisual = std::all_of((*it).second.begin(), (*it).second.end(), [](auto e) {
            return e.type() == OSM::Type::Node || (e.type() == OSM::Type::Relation && e.tagValue("type") != QLatin1String("multipolygon"));
        });
        if (isNonVisual) {
            it = m_levelMap.erase(it);
        } else {
            ++it;
        }
    }
}
