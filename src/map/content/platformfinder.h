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
class MapLevel;

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
    std::vector<PlatformSection> sectionsForPath(const std::vector<const OSM::Node*> &path, const QString &platformName) const;
    Platform::Mode modeForElement(OSM::Element elem) const;
    int levelForPlatform(const MapLevel &ml, OSM::Element e) const;

    void addPlatform(Platform &&platform);

    const MapData *m_data;
    struct {
        OSM::TagKey level;
        OSM::TagKey platform_ref;
        OSM::TagKey platform_colon_ref; // platform:ref vs platform_ref above...
        OSM::TagKey public_transport;
        OSM::TagKey railway;
        OSM::TagKey railway_platform_section;
        OSM::TagKey route;
    } m_tagKeys;
    void resolveTagKeys();
    /** Tries to merge m_platformAreas into m_platforms. */
    void mergePlatformAreas();
    void finalizeResult();

    QCollator m_collator;

    std::vector<Platform> m_platforms;
    std::vector<Platform> m_platformAreas;
    std::vector<Platform> m_floatingSections;
};

}

#endif // KOSMINDOORMAP_PLATFORMFINDER_H
