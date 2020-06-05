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
    return m_element.tagValue("name", QLocale());
}

// TODO generalize for *:wikipedia tags
QUrl OSMElement::wikipediaUrl() const
{
    const auto wp = m_element.tagValue("wikipedia", QLocale());
    if (wp.isEmpty()) {
        return {};
    }

    const auto idx = wp.indexOf(QLatin1Char(':'));
    if (idx < 0) {
        return {};
    }

    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(wp.leftRef(idx) + QLatin1String(".wikipedia.org"));
    url.setPath(QLatin1String("/wiki/") + wp.midRef(idx + 1));
    return url;
}

QString OSMElement::tagValue(const QString &key) const
{
    return m_element.tagValue(key.toUtf8().constData());
}
