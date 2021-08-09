/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_PATH_H
#define KPUBLICTRANSPORT_PATH_H

#include "kpublictransport_export.h"
#include "datatypes.h"

#include <QPolygonF>

namespace KPublicTransport {

class PathSectionPrivate;

/** A section of a Path.
 *  A path section consists of a poly-line of geo-coordinates to follow,
 *  an initial maneuver instructions as well as additional properties for
 *  this part of the path, such as the floor level.
 */
class KPUBLICTRANSPORT_EXPORT PathSection
{
    KPUBLICTRANSPORT_GADGET(PathSection)
    /** The geo coordinate poly-line followed by this path section. */
    KPUBLICTRANSPORT_PROPERTY(QPolygonF, path, setPath)
    /** Human-readable description of this path segment. */
    KPUBLICTRANSPORT_PROPERTY(QString, description, setDescription)

    // TODO add more properties: maneuver instructions, floor level

    /** The length of this path section in meters. */
    Q_PROPERTY(int distance READ distance STORED false)
    /** The overall direction of this section in degree. */
    Q_PROPERTY(int direction READ direction STORED false)

public:
    /** Length of this path section in meters. */
    int distance() const;
    /** The overall direction of this section in degree.
     *  @returns 0-359 for valid results, -1 for sections with no direction (e.g. points).
     */
    int direction() const;

    /** First point on the path of this section. */
    QPointF startPoint() const;
    /** Last point on the path of this section. */
    QPointF endPoint() const;

    /** Serializes one path section section to JSON. */
    static QJsonObject toJson(const PathSection &section);
    /** Serializes a vector of path sections to JSON. */
    static QJsonArray toJson(const std::vector<PathSection> &sections);
    /** Deserialize an object from JSON. */
    static PathSection fromJson(const QJsonObject &obj);
    /** Deserialize a vector of path sections from JSON. */
    static std::vector<PathSection> fromJson(const QJsonArray &array);
};

class PathPrivate;

/** A path followed by any kind of location change.
 *  This can be the way a train or bus takes, routing instructions
 *  for taking a rental vehicle, or instructions for transferring at
 *  a train station.
 *
 *  A path consists of one or more PathSection.
 */
class KPUBLICTRANSPORT_EXPORT Path
{
    KPUBLICTRANSPORT_GADGET(Path)

    /** Access to path sections for QML. */
    Q_PROPERTY(std::vector<KPublicTransport::PathSection> sections READ sections)
    /** Number of path sections for QML. */
    Q_PROPERTY(int sectionCount READ sectionCount STORED false)

    /** The length of this path in meters. */
    Q_PROPERTY(int distance READ distance STORED false)

public:
    /** Returns @c true if this is an empty/not-set path. */
    bool isEmpty() const;

    /** The path sections. */
    const std::vector<PathSection>& sections() const;
    /** Moves the path sections out of this object. */
    std::vector<PathSection>&& takeSections();
    /** Sets the path sections. */
    void setSections(std::vector<PathSection> &&sections);

    /** Length of this path in meters. */
    int distance() const;

    /** First point on this path. */
    QPointF startPoint() const;
    /** Last point on this path. */
    QPointF endPoint() const;

    /** Serializes one path object to JSON. */
    static QJsonObject toJson(const Path &path);
    /** Deserialize an object from JSON. */
    static Path fromJson(const QJsonObject &obj);

private:
    int sectionCount() const;
};

}

Q_DECLARE_METATYPE(KPublicTransport::PathSection)
Q_DECLARE_METATYPE(std::vector<KPublicTransport::PathSection>)
Q_DECLARE_METATYPE(KPublicTransport::Path)

#endif // KPUBLICTRANSPORT_PATH_H
