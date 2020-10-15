/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_MAPCSSRESULT_P_H
#define KOSMINDOORMAP_MAPCSSRESULT_P_H

#include "mapcssdeclaration_p.h"

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
    const std::vector<const MapCSSDeclaration*>& declarations() const;

    /** @internal */
    void addDeclaration(const MapCSSDeclaration *decl);

private:
    std::vector<const MapCSSDeclaration*> m_declarations;
    int m_flags = 0;
};

}

#endif // KOSMINDOORMAP_MAPCSSRESULT_P_H
