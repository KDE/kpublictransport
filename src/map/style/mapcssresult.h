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

#ifndef KOSMINDOORMAP_MAPCSSRESULT_H
#define KOSMINDOORMAP_MAPCSSRESULT_H

#include "mapcssdeclaration.h"

#include <vector>

namespace KOSMIndoorMap {

/** Result of MapCSS stylesheet evaluation. */
class MapCSSResult
{
public:
    explicit MapCSSResult();
    ~MapCSSResult();

    void clear();

    /** Returns @c true if an area/polygon needs to be drawn. */
    bool hasAreaProperties() const;
    /** Returns @c true if a way/line needs to be drawn. */
    bool hasLineProperties() const;
    /** Returns @c true if a label needs to be drawn. */
    bool hasLabelProperties() const;

    /** Returns the declaration for property @prop, or @c nullptr is this property isn't set. */
    const MapCSSDeclaration* declaration(MapCSSDeclaration::Property prop) const;
    /** The active declarations for the queried element. */
    std::vector<const MapCSSDeclaration*> declarations() const;

    /** @internal */
    void addDeclaration(const MapCSSDeclaration *decl);

private:
    std::vector<const MapCSSDeclaration*> m_declarations;
    int m_flags = 0;
};

}

#endif // KOSMINDOORMAP_MAPCSSRESULT_H
