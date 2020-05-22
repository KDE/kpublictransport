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

#include "mapcssrule.h"
#include "mapcssresult.h"
#include "mapcssstate.h"

#include <QDebug>
#include <QIODevice>

using namespace KOSMIndoorMap;

MapCSSRule::MapCSSRule() = default;
MapCSSRule::~MapCSSRule() = default;

void MapCSSRule::evaluate(const MapCSSState &state, MapCSSResult &result) const
{
    // TODO how do we deal with chained selectors here??
    if (!m_selector->matches(state)) {
        return;
    }

    for (const auto &decl : m_declarations) {
        result.addDeclaration(decl.get());
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
    if (declPtr->property() != MapCSSDeclaration::Unknown) {
        m_declarations.push_back(std::move(declPtr));
    }
}
