/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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

void MapCSSStyle::evaluateCanvas(const MapCSSState &state, MapCSSResult &result) const
{
    result.clear();
    for (const auto &rule : m_rules) {
        rule->evaluateCanvas(state, result);
    }
}

void MapCSSStyle::write(QIODevice *out) const
{
    for (const auto &rule : m_rules) {
        rule->write(out);
    }
}
