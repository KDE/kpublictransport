/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
