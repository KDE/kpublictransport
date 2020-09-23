/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mapcssrule.h"
#include "mapcssresult.h"
#include "mapcssstate.h"

#include <QDebug>
#include <QIODevice>

using namespace KOSMIndoorMap;

MapCSSRule::MapCSSRule() = default;
MapCSSRule::~MapCSSRule() = default;

void MapCSSRule::compile(const OSM::DataSet &dataSet)
{
    m_selector->compile(dataSet);
    for (const auto &decl : m_declarations) {
        decl->compile(dataSet);
    }
}

void MapCSSRule::evaluate(const MapCSSState &state, MapCSSResult &result) const
{
    // TODO how do we deal with chained selectors here??
    if (!m_selector->matches(state)) {
        return;
    }

    for (const auto &decl : m_declarations) {
        if (decl->type() == MapCSSDeclaration::PropertyDeclaration) {
            result.addDeclaration(decl.get());
        }
    }
}

void MapCSSRule::evaluateCanvas(MapCSSResult &result) const
{
    if (m_selector->matchesCanvas()) {
        for (const auto &decl : m_declarations) {
            result.addDeclaration(decl.get());
        }
    }
}

void MapCSSRule::write(QIODevice *out) const
{
    m_selector->write(out);
    out->write("\n{\n");
    for (const auto &decl : m_declarations) {
        decl->write(out);
    }
    out->write("}\n\n");
}

void MapCSSRule::setSelector(MapCSSSelector *selector)
{
    m_selector.reset(selector);
}

void MapCSSRule::addDeclaration(MapCSSDeclaration *decl)
{
    std::unique_ptr<MapCSSDeclaration> declPtr(decl);
    if (declPtr->isValid()) {
        m_declarations.push_back(std::move(declPtr));
    }
}
