/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_PENWIDTHUTIL_H
#define KOSMINDOORMAP_PENWIDTHUTIL_H

#include "scenegraphitem.h"

#include <osm/element.h>

namespace KOSMIndoorMap {

class MapCSSDeclaration;

/** Determine pen width based on a MapCSS declaration and OSM element tag information. */
namespace PenWidthUtil
{
    double penWidth(OSM::Element e, const MapCSSDeclaration *decl, Unit &unit);
}

}

#endif // KOSMINDOORMAP_PENWIDTHUTIL_H
