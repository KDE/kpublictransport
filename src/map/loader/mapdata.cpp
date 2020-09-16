/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mapdata.h"

#include "style/mapcssparser.h"
#include "style/mapcssresult.h"
#include "style/mapcssstate.h"
#include "style/mapcssstyle.h"

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
MapData::MapData(MapData&&) = default;
MapData::~MapData() = default;

MapData& MapData::operator=(MapData&&) = default;

const OSM::DataSet& MapData::dataSet() const
{
    return m_dataSet;
}

OSM::DataSet& MapData::dataSet()
{
    return m_dataSet;
}

void MapData::setDataSet(OSM::DataSet &&dataSet)
{
    m_dataSet = std::move(dataSet);

    m_levelRefTag = m_dataSet.tagKey("level:ref");
    m_nameTag = m_dataSet.tagKey("name");

    m_levelMap.clear();
    m_bbox = {};

    processElements();
    filterLevels();
}

OSM::BoundingBox MapData::boundingBox() const
{
    return m_bbox;
}

void MapData::setBoundingBox(OSM::BoundingBox bbox)
{
    m_bbox = bbox;
}

void MapData::processElements()
{
    const auto levelTag = m_dataSet.tagKey("level");
    const auto repeatOnTag = m_dataSet.tagKey("repeat_on");

    MapCSSParser p;
    auto filter = p.parse(QStringLiteral(":/org.kde.kosmindoormap/assets/css/input-filter.mapcss"));
    if (p.hasError()) {
        qWarning() << p.errorMessage();
    }
    filter.compile(m_dataSet);
    MapCSSResult filterResult;

    OSM::for_each(m_dataSet, [&](auto e) {
        // discard everything here that is tag-less (and thus likely part of a higher-level geometry)
        if (!e.hasTags()) {
            return;
        }

        // apply the input filter, anything that explicitly got opacity 0 will be discarded
        bool isDependentElement = false;
        MapCSSState filterState;
        filterState.element = e;
        filter.evaluate(filterState, filterResult);
        if (auto prop = filterResult.declaration(MapCSSDeclaration::Opacity)) {
            if (prop->doubleValue() == 0.0) {
                qDebug() << "input filter dropped" << e.url();
                return;
            }
            // anything that doesn't work on its own is a "dependent element"
            // we discard levels only containing dependent elements, but we retain all of them if the
            // level contains an element we are sure about that we can display it
            if (prop->doubleValue() < 1.0) {
                isDependentElement = true;
            }
        }

        // bbox computation
        e.recomputeBoundingBox(m_dataSet);
        m_bbox = OSM::unite(e.boundingBox(), m_bbox);

        // level parsing
        auto level = e.tagValue(levelTag);
        if (level.isEmpty()) {
            level = e.tagValue(repeatOnTag);
        }

        if (level.isEmpty()) { // level-less -> outdoor
            m_levelMap[MapLevel{}].push_back(e);
            if (isDependentElement) {
                m_dependentElementCounts[MapLevel{}]++;
            }
        } else {
            parseLevel(std::move(level), e, isDependentElement);
        }
    });
}

// @see https://wiki.openstreetmap.org/wiki/Key:level
// @see https://wiki.openstreetmap.org/wiki/Simple_Indoor_Tagging#Multi-level_features_and_repeated_features
void MapData::parseLevel(QByteArray &&level, OSM::Element e, bool isDependentElement)
{
    int rangeBegin = std::numeric_limits<int>::max();
    int numStartIdx = -1;

    for (int i = 0; i < level.size(); ++i) {
        auto c = level[i];

        if (c == ',') { // fix decimal separator errors
            qDebug() << "syntax error in level tag:" << level << e.url();
            c = '.';
        }

        if (std::isdigit(c) || c == '.') {
            if (numStartIdx < 0) {
                numStartIdx = i;
            }
            continue;
        }

        if (c == ';') {
            const auto l = std::atof(level.constData() + numStartIdx) * 10;
            if (rangeBegin < l) {
                for (int j = rangeBegin; j < l; j += 10) {
                    addElement(j, e, isDependentElement);
                }
                rangeBegin = std::numeric_limits<int>::max();
            } else {
                addElement(l, e, isDependentElement);
            }
            numStartIdx = -1;
            continue;
        }

        if (c == QLatin1Char('-')) {
            if (numStartIdx < 0) {
                numStartIdx = i;
            } else {
                rangeBegin = std::atof(level.constData() + numStartIdx) * 10;
                numStartIdx = -1;
            }
        }
    }

    const auto l = std::atof(level.constData() + numStartIdx) * 10;
    if (rangeBegin < l) {
        for (int j = rangeBegin; j < l; j += 10) {
            addElement(j, e, isDependentElement);
        }
    } else {
        addElement(l, e, isDependentElement);
    }
}

void MapData::addElement(int level, OSM::Element e, bool isDependentElement)
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
    if (isDependentElement) {
        m_dependentElementCounts[l]++;
    }
}

static bool isPlausibleLevelName(const QByteArray &s)
{
    return !s.isEmpty() && !s.contains(';');
}

QString MapData::levelName(OSM::Element e)
{
    const auto n = e.tagValue(m_levelRefTag);
    if (isPlausibleLevelName(n)) {
        return QString::fromUtf8(n);
    }

    if (e.type() == OSM::Type::Relation) {
        const auto isLevelRel = std::all_of(e.relation()->members.begin(), e.relation()->members.end(), [](const auto &mem) {
            return std::strcmp(mem.role().name(), "shell") == 0 || std::strcmp(mem.role().name(), "buildingpart") == 0;
        });
        if (isLevelRel) {
            const auto n = e.tagValue(m_nameTag);
            if (isPlausibleLevelName(n)) {
                return QString::fromUtf8(n);
            }
        }
    }

    return {};
}

void MapData::filterLevels()
{
    // remove all levels that don't contain something we are sure would make a meaningful output
    for (auto it = m_levelMap.begin(); it != m_levelMap.end();) {
        if (m_dependentElementCounts[(*it).first] == (*it).second.size()) {
            it = m_levelMap.erase(it);
        } else {
            ++it;
        }
    }
    m_dependentElementCounts.clear();
}
