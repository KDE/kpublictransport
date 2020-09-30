/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_PLATFORMFINDER_H
#define KOSMINDOORMAP_PLATFORMFINDER_H

#include "platform.h"

#include <QCollator>

namespace KOSMIndoorMap {

class MapData;

/** Identifies public transport platforms in OSM data. */
class PlatformFinder
{
public:
    explicit PlatformFinder();
    ~PlatformFinder();

    std::vector<Platform> find(const MapData *data);

private:
    void scanRoute(OSM::Element e, OSM::Element route);
    void scanRoute(const OSM::Node &node, OSM::Element route);
    void addPlatform(Platform &&platform);
    bool comparePlatform(const Platform &lhs, const Platform &rhs);

    const MapData *m_data;
    struct {
        OSM::TagKey public_transport;
        OSM::TagKey railway;
        OSM::TagKey route;
    } m_tagKeys;
    void resolveTagKeys();
    void finalizeResult();

    QCollator m_collator;

    std::vector<Platform> m_platforms;
};

}

#endif // KOSMINDOORMAP_PLATFORMFINDER_H
