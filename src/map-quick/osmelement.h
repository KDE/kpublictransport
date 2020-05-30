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

#ifndef KOSMINDOORMAP_OSMELEMENT_H
#define KOSMINDOORMAP_OSMELEMENT_H

#include <osm/element.h>

#include <QMetaType>
#include <QUrl>

namespace KOSMIndoorMap {

/** QML wrapper around an OSM element. */
class OSMElement
{
    Q_GADGET
    Q_PROPERTY(bool isNull READ isNull)
    Q_PROPERTY(QString name READ name)
    /** Assembled URL from the "wikipedia" tag value. */
    Q_PROPERTY(QUrl wikipediaUrl READ wikipediaUrl)
public:
    OSMElement();
    explicit OSMElement(OSM::Element e);
    ~OSMElement();

    bool isNull() const;
    QString name() const;
    QUrl wikipediaUrl() const;

    Q_INVOKABLE QString tagValue(const QString &key) const;

private:
    OSM::Element m_element;
};

}

Q_DECLARE_METATYPE(KOSMIndoorMap::OSMElement)

#endif // KOSMINDOORMAP_OSMELEMENT_H
