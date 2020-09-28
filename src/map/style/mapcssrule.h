/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_MAPCSSRULE_H
#define KOSMINDOORMAP_MAPCSSRULE_H

#include "mapcssdeclaration.h"
#include "mapcssselector.h"

#include <memory>
#include <vector>

class QIODevice;

namespace OSM {
class DataSet;
}

namespace KOSMIndoorMap {

class MapCSSResult;
class MapCSSState;

/** A single MapCSS rule. */
class MapCSSRule
{
public:
    explicit MapCSSRule();
    ~MapCSSRule();

    /** Perform tag key resolution. */
    void compile(const OSM::DataSet &dataSet);

    /** Rule evaluation, @see MapCSSStyle. */
    void evaluate(const MapCSSState &state, MapCSSResult &result) const;
    /** Evaluation of canvas rules. */
    void evaluateCanvas(const MapCSSState &state, MapCSSResult &result) const;

    /** Write this rule to @p out. */
    void write(QIODevice *out) const;

    /* @internal used by the parser */
    void setSelector(MapCSSSelector *selector);
    void addDeclaration(MapCSSDeclaration *decl);

private:
    std::unique_ptr<MapCSSSelector> m_selector;
    std::vector<std::unique_ptr<MapCSSDeclaration>> m_declarations;
};

}

#endif // KOSMINDOORMAP_MAPCSSRULE_H
