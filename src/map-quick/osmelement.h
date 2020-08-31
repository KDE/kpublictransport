/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
public:
    OSMElement();
    explicit OSMElement(OSM::Element e);
    ~OSMElement();

    bool isNull() const;
    QString name() const;

    Q_INVOKABLE QString tagValue(const QString &key) const;

    // @internal
    OSM::Element element() const;

private:
    OSM::Element m_element;
};

}

Q_DECLARE_METATYPE(KOSMIndoorMap::OSMElement)

#endif // KOSMINDOORMAP_OSMELEMENT_H
