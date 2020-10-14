/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_PENWIDTHUTIL_P_H
#define KOSMINDOORMAP_PENWIDTHUTIL_P_H

#include "kosmindoormap_export.h"

#include "scenegraphitem.h"

#include <osm/element.h>

namespace KOSMIndoorMap {

class MapCSSDeclaration;

/** Determine pen width based on a MapCSS declaration and OSM element tag information. */
namespace PenWidthUtil
{
    /** @internal only exported for unit tests. */
    KOSMINDOORMAP_EXPORT double penWidth(OSM::Element e, const MapCSSDeclaration *decl, Unit &unit);
}

}

#endif // KOSMINDOORMAP_PENWIDTHUTIL_P_H
