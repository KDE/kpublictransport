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

#include "mapcssstyle.h"
#include "mapcssparser.h"
#include "mapcssresult.h"
#include "mapcssstate.h"

#include <QDebug>
#include <QIODevice>

using namespace KOSMIndoorMap;

MapCSSStyle::MapCSSStyle() = default;
MapCSSStyle::MapCSSStyle(MapCSSStyle&&) = default;
MapCSSStyle::~MapCSSStyle() = default;
MapCSSStyle& MapCSSStyle::operator=(MapCSSStyle&&) = default;

void MapCSSStyle::compile(const OSM::DataSet &dataSet)
{
    for (const auto &rule : m_rules) {
        rule->compile(dataSet);
    }
}

void MapCSSStyle::evaluate(const MapCSSState &state, MapCSSResult &result) const
{
    result.clear();
    for (const auto &rule : m_rules) {
        rule->evaluate(state, result);
    }
}

void MapCSSStyle::evaluateCanvas(MapCSSResult &result) const
{
    result.clear();
    for (const auto &rule : m_rules) {
        rule->evaluateCanvas(result);
    }
}

void MapCSSStyle::write(QIODevice *out) const
{
    for (const auto &rule : m_rules) {
        rule->write(out);
    }
}
