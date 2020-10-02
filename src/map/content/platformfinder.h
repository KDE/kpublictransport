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
    std::vector<PlatformSection> sectionsForPath(const std::vector<const OSM::Node*> &path, const QString &platformName) const;
    Platform::Mode modeForElement(OSM::Element elem) const;

    void addPlatform(Platform &&platform);
    /** Similar to the above, but assuming @p platform can be merged with multiple existing ones. */
    void addPlatformArea(Platform &&platform);

    const MapData *m_data;
    struct {
        OSM::TagKey platform_ref;
        OSM::TagKey public_transport;
        OSM::TagKey railway;
        OSM::TagKey railway_platform_section;
        OSM::TagKey route;
    } m_tagKeys;
    void resolveTagKeys();
    void finalizeResult();

    QCollator m_collator;

    std::vector<Platform> m_platforms;
    std::vector<Platform> m_platformAreas;
};

}

#endif // KOSMINDOORMAP_PLATFORMFINDER_H
