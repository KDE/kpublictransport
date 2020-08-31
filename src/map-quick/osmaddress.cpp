/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
    return QString::fromUtf8(m_element.tagValue("addr:street", "contact:street", "addr:housename"));
}

QString OSMAddress::houseNumber() const
{
    return QString::fromUtf8(m_element.tagValue("addr:housenumber", "contact:housenumber"));
}

QString OSMAddress::postalCode() const
{
    return QString::fromUtf8(m_element.tagValue("addr:postcode", "contact:postcode"));
}

QString OSMAddress::city() const
{
    return QString::fromUtf8(m_element.tagValue("addr:city", "contact:city"));
}

QString OSMAddress::state() const
{
    return QString::fromUtf8(m_element.tagValue("addr:state"));
}

QString OSMAddress::country() const
{
    return QString::fromUtf8(m_element.tagValue("addr:country", "contact:country"));
}
