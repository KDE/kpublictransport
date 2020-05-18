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

#ifndef KOSMINDOORMAP_MAPCSSRULE_H
#define KOSMINDOORMAP_MAPCSSRULE_H

#include "mapcssdeclaration.h"
#include "mapcssselector.h"

#include <memory>
#include <vector>

class QIODevice;

namespace KOSMIndoorMap {

class MapCSSResult;
class MapCSSState;

/** A single MapCSS rule. */
class MapCSSRule
{
public:
    explicit MapCSSRule();
    ~MapCSSRule();

    /** Rule evaluation, @see MapCSSStyle. */
    void evaluate(const MapCSSState &state, MapCSSResult &result) const;
    /** Evaluation of canvas rules. */
    void evaluateCanvas(MapCSSResult &result) const;

    /** Write this rule to @p out. */
    void write(QIODevice *out) const;

    /* @internal used by the parser */
    void setSelector(MapCSSSelector *selector);
    void addDeclaration(MapCSSDeclaration *decl);

    // TODO private
    std::unique_ptr<MapCSSSelector> m_selector;
    std::vector<std::unique_ptr<MapCSSDeclaration>> m_declarations;
};

}

#endif // KOSMINDOORMAP_MAPCSSRULE_H
