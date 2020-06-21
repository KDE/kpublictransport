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

#ifndef KOSMINDOORMAP_OSMADDRESS_H
#define KOSMINDOORMAP_OSMADDRESS_H

#include <osm/element.h>

namespace KOSMIndoorMap {

/** Postal address from OSM data. */
class OSMAddress
{
    Q_GADGET
    Q_PROPERTY(QString street READ street)
    Q_PROPERTY(QString houseNumber READ houseNumber)
    Q_PROPERTY(QString postalCode READ postalCode)
    Q_PROPERTY(QString city READ city)
    Q_PROPERTY(QString country READ country)

public:
    explicit OSMAddress();
    explicit OSMAddress(OSM::Element elem);
    ~OSMAddress();

    QString street() const;
    QString houseNumber() const;
    QString postalCode() const;
    QString city() const;
    QString country() const;

private:
    OSM::Element m_element;
};

}

Q_DECLARE_METATYPE(KOSMIndoorMap::OSMAddress)

#endif // KOSMINDOORMAP_OSMADDRESS_H
