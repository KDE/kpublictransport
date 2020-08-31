/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
    Q_PROPERTY(QString state READ state)
    Q_PROPERTY(QString country READ country)

public:
    explicit OSMAddress();
    explicit OSMAddress(OSM::Element elem);
    ~OSMAddress();

    QString street() const;
    QString houseNumber() const;
    QString postalCode() const;
    QString city() const;
    QString state() const;
    QString country() const;

private:
    OSM::Element m_element;
};

}

Q_DECLARE_METATYPE(KOSMIndoorMap::OSMAddress)

#endif // KOSMINDOORMAP_OSMADDRESS_H
