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

#ifndef KOSMINDOORMAP_MAPCSSSTYLE_H
#define KOSMINDOORMAP_MAPCSSSTYLE_H

#include "mapcssrule.h"

#include <osm/element.h>

#include <memory>
#include <vector>

class QIODevice;

namespace OSM {
class DataSet;
}

namespace KOSMIndoorMap {

class MapCSSParser;
class MapCSSResult;

/** A parsed MapCSS style sheet.
 *  @see MapCSSParser::parse for how to obtain a valid instance
 */
class MapCSSStyle
{
public:
    /** Creates an invalid/empty style. */
    explicit MapCSSStyle();
    MapCSSStyle(const MapCSSStyle&) = delete;
    MapCSSStyle(MapCSSStyle&&);
    ~MapCSSStyle();

    MapCSSStyle& operator=(const MapCSSStyle&) = delete;
    MapCSSStyle& operator=(MapCSSStyle&&);

    /** Optimizes style sheet rules for application against @p dataSet.
     *  This does resolve tag keys and is therefore mandatory when changing the data set.
     */
    void compile(const OSM::DataSet &dataSet);

    /** Evaluates the style sheet for a given state @p state (OSM element, view state, element state, etc).
     *  The result is not returned but added to @p result for reusing allocated memory
     *  between evaluations.
     */
    void evaluate(const MapCSSState &state, MapCSSResult &result) const;

    /** Evaluate canvas style rules. */
    void evaluateCanvas(MapCSSResult &result) const;

    /** Write this style as MapCSS to @p out.
     *  Mainly used for testing.
     */
    void write(QIODevice *out) const;

private:
    friend class MapCSSParser;
    std::vector<std::unique_ptr<MapCSSRule>> m_rules;
};

}

#endif // KOSMINDOORMAP_MAPCSSSTYLE_H
