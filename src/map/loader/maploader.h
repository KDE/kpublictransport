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

#ifndef KOSMINDOORMAP_MAPLOADER_H
#define KOSMINDOORMAP_MAPLOADER_H

#include <osm/datatypes.h>

namespace KOSMIndoorMap {

/** Loader for OSM data.
 *  Largely temporary, until we have a proper solution on how to actually get the required data.
 */
class MapLoader
{
public:
    void loadFromOsmXml(const QString &fileName);

    OSM::DataSet m_dataSet;
    QStringList m_levels;

private:
    void determineLevels();
};

}

#endif // KOSMINDOORMAP_MAPLOADER_H
