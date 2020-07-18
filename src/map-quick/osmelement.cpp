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

#include "osmelement.h"

using namespace KOSMIndoorMap;

OSMElement::OSMElement() = default;
OSMElement::OSMElement(OSM::Element e)
    : m_element(e)
{
}

OSMElement::~OSMElement() = default;

bool OSMElement::isNull() const
{
    return m_element.type() == OSM::Type::Null;
}

QString OSMElement::name() const
{
    return QString::fromUtf8(m_element.tagValue("name", QLocale()));
}

QString OSMElement::tagValue(const QString &key) const
{
    return QString::fromUtf8(m_element.tagValue(key.toUtf8().constData()));
}

OSM::Element OSMElement::element() const
{
    return m_element;
}
