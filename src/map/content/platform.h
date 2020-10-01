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
struct PlatformSection {
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
    OSM::Element track() const;
    void setTrack(OSM::Element track);

    // TODO - clean up once PlatformModel is ported to PlatformFinder
    enum Mode {
        Rail,
        Subway,
        Tram,
        Bus,
    };
    Mode mode = Rail;
    Q_ENUM(Mode)
    QStringList lines;
    std::vector<PlatformSection> sections;

    /** Checks if two instances refer to the same platform. */
    static bool isSame(const Platform &lhs, const Platform &rhs, const OSM::DataSet &dataSet);
    /** Merge two platform objects. */
    static Platform merge(const Platform &lhs, const Platform &rhs);

private:
    QString m_name;
    OSM::Element m_stopPoint;
    OSM::Element m_edge;
    OSM::Element m_area;
    OSM::Element m_track;
    int m_level = std::numeric_limits<int>::min(); // INT_MIN indicates not set, needed for merging
};

}

Q_DECLARE_METATYPE(KOSMIndoorMap::Platform)

#endif // KOSMINDOORMAP_PLATFORM_H
