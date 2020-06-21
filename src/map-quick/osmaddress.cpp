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

#include "osmaddress.h"

using namespace KOSMIndoorMap;

OSMAddress::OSMAddress() = default;
OSMAddress::OSMAddress(OSM::Element elem)
    : m_element(elem)
{
}

OSMAddress::~OSMAddress() = default;

QString OSMAddress::street() const
{
    return m_element.tagValue("addr:street", "contact:street");
}

QString OSMAddress::houseNumber() const
{
    return m_element.tagValue("addr:housenumber", "contact:housenumber");
}

QString OSMAddress::postalCode() const
{
    return m_element.tagValue("addr:postcode", "contact:postcode");
}

QString OSMAddress::city() const
{
    return m_element.tagValue("addr:city", "contact:city");
}

QString OSMAddress::country() const
{
    return m_element.tagValue("addr:country", "contact:country");
}
