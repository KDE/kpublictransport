/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_PLATFORM_H
#define KOSMINDOORMAP_PLATFORM_H

#include <osm/element.h>

#include <QMetaType>
#include <QStringList>

#include <limits>
#include <vector>

namespace KOSMIndoorMap {

/** A railway platform section. */
class PlatformSection
{
public:
    /** Platform section has enough data to work with. */
    bool isValid() const;

    QString name;
    OSM::Element position;
};

/** A railway platform/track. */
class Platform {
    Q_GADGET
public:
    explicit Platform();
    ~Platform();

    /** Platform has enough data to work with. */
    bool isValid() const;

    /** User-visible name of the platform. */
    QString name() const;
    void setName(const QString &name);

    /** Floor level. */
    int level() const;
    bool hasLevel() const;
    void setLevel(int level);

    /** A singular position for this platform (typically the stop position).
     *  This can be useful for positining views or labels.
     */
    OSM::Coordinate position() const;
    OSM::Element stopPoint() const;
    void setStopPoint(OSM::Element stop);

    /** The platform edge path. */
    OSM::Element edge() const;
    void setEdge(OSM::Element edge);

    /** The platform area.
     *  This is often shared between multiple tracks.
     */
    OSM::Element area() const;
    void setArea(OSM::Element area);

    /** The (railway) track this platform is serving. */
    const std::vector<OSM::Element>& track() const;
    void setTrack(std::vector<OSM::Element> &&track);
    std::vector<OSM::Element>&& takeTrack();

    /** Platform sections. */
    const std::vector<PlatformSection>& sections() const;
    void setSections(std::vector<PlatformSection> &&sections);
    std::vector<PlatformSection>&& takeSections();

    /** Transportation mode served by a platform. */
    enum Mode {
        Unknown,
        Rail,
        LightRail,
        Subway,
        Tram,
        Bus,
    };
    Q_ENUM(Mode)
    Mode mode() const;
    void setMode(Mode mode);

    // TODO - clean up once PlatformModel is ported to PlatformFinder
    QStringList lines;

    /** Checks if two instances refer to the same platform. */
    static bool isSame(const Platform &lhs, const Platform &rhs, const OSM::DataSet &dataSet);
    /** Merge two platform objects. */
    static Platform merge(const Platform &lhs, const Platform &rhs, const OSM::DataSet &dataSet);

    /** Checks if @p name is a plausible name for a platform. */
    static bool isPlausibleName(const QString &name);
    /** Returns the preferred platform name given two possible alternatives. */
    static QString preferredName(const QString &lhs, const QString &rhs);

private:
    QString m_name;
    OSM::Element m_stopPoint;
    OSM::Element m_edge;
    OSM::Element m_area;
    std::vector<OSM::Element> m_track;
    Mode m_mode = Rail; // TODO should eventually be "Unknown"
    int m_level = std::numeric_limits<int>::min(); // INT_MIN indicates not set, needed for merging
    std::vector<PlatformSection> m_sections;

    static void appendSection(std::vector<PlatformSection> &sections, const Platform &p, PlatformSection &&sec, std::vector<const OSM::Node*> &edgePath, const OSM::DataSet &dataSet);
    static double maxSectionDistance(const Platform &p, const std::vector<PlatformSection> &sections, const OSM::DataSet &dataSet);
};

}

Q_DECLARE_METATYPE(KOSMIndoorMap::Platform)

#endif // KOSMINDOORMAP_PLATFORM_H
