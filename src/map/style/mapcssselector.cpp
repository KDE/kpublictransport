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

#include "mapcssselector.h"
#include "mapcsscondition.h"
#include "mapcssstate.h"

#include <QDebug>
#include <QIODevice>

#include <cmath>

using namespace KOSMIndoorMap;

MapCSSSelector::MapCSSSelector() = default;
MapCSSSelector::~MapCSSSelector() = default;

MapCSSBasicSelector::MapCSSBasicSelector() = default;
MapCSSBasicSelector::~MapCSSBasicSelector() = default;

bool MapCSSBasicSelector::matches(const MapCSSState &state) const
{
    switch (objectType) {
        case Node: if (state.element.type() != OSM::Type::Node) return false; break;
        case Way: if (state.element.type() != OSM::Type::Way) return false; break;
        case Relation: if (state.element.type() != OSM::Type::Relation) return false; break;
        // TODO should this include multi-polygon relations?
        case Area: if (state.element.type() != OSM::Type::Way || !state.element.way()->isClosed()) return false; break;
        case Line: if (state.element.type() != OSM::Type::Way || state.element.way()->isClosed()) return false; break;
        case Canvas: return false;
        case Any: break;
    }

    if (m_zoomLow > 0 && state.zoomLevel < m_zoomLow) {
        return false;
    }
    if (m_zoomHigh > 0 && std::ceil(state.zoomLevel) > m_zoomHigh) {
        return false;
    }

    return std::all_of(conditions.begin(), conditions.end(), [state](const auto &cond) { return cond->matches(state); });
}

bool MapCSSBasicSelector::matchesCanvas() const
{
    return objectType == Canvas;
}

void MapCSSBasicSelector::write(QIODevice *out) const
{
    switch (objectType) {
        case Node: out->write("node"); break;
        case Way: out->write("way"); break;
        case Relation: out->write("relation"); break;
        case Area: out->write("area"); break;
        case Line: out->write("line"); break;
        case Canvas: out->write("canvas"); break;
        case Any: out->write("*"); break;
    }

    if (m_zoomLow > 0 || m_zoomHigh > 0) {
        out->write("|z");
        if (m_zoomLow == m_zoomHigh) {
            out->write(QByteArray::number(m_zoomLow));
        } else {
            if (m_zoomLow > 0) {
                out->write(QByteArray::number(m_zoomLow));
            }
            out->write("-");
            if (m_zoomHigh > 0) {
                out->write(QByteArray::number(m_zoomHigh));
            }
        }
    }

    for (const auto &cond : conditions) {
        cond->write(out);
    }
}

void MapCSSBasicSelector::setZoomRange(int low, int high)
{
    m_zoomLow = low;
    m_zoomHigh = high;
}

void MapCSSBasicSelector::setConditions(MapCSSConditionHolder *conds)
{
    qDebug() << conds;
    if (!conds) {
        return;
    }
    conditions = std::move(conds->conditions);
    delete conds;
}


bool MapCSSChainedSelector::matches(const MapCSSState &state) const
{
    // TODO
    return false;
}

bool MapCSSChainedSelector::matchesCanvas() const
{
    // canvas cannot be chained
    return false;
}

void MapCSSChainedSelector::write(QIODevice *out) const
{
    assert(selectors.size() > 1);
    selectors[0]->write(out);
    for (auto it = std::next(selectors.begin()); it != selectors.end(); ++it) {
        out->write(" ");
        (*it)->write(out);
    }
}

MapCSSUnionSelector::MapCSSUnionSelector() = default;
MapCSSUnionSelector::~MapCSSUnionSelector() = default;

bool MapCSSUnionSelector::matches(const MapCSSState &state) const
{
    return std::any_of(selectors.begin(), selectors.end(), [state](const auto &selector) { return selector->matches(state); });
}

bool MapCSSUnionSelector::matchesCanvas() const
{
    return std::any_of(selectors.begin(), selectors.end(), [](const auto &selector) { return selector->matchesCanvas(); });
}

void MapCSSUnionSelector::write(QIODevice *out) const
{
    assert(selectors.size() > 1);
    selectors[0]->write(out);
    for (auto it = std::next(selectors.begin()); it != selectors.end(); ++it) {
        out->write(",\n");
        (*it)->write(out);
    }
}
