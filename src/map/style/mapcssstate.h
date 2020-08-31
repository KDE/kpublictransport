/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_MAPCSSSTATE_H
#define KOSMINDOORMAP_MAPCSSSTATE_H

#include <osm/element.h>

namespace KOSMIndoorMap {

/** Style evaluation state. */
class MapCSSState
{
public:
    OSM::Element element;
    double zoomLevel = 0.0;
};

}

#endif // KOSMINDOORMAP_MAPCSSSTATE_H
