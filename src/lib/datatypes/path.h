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

    /** Floor level change during this path section.
     *  Negative values indicate going down, positive values indicate going up
     */
    KPUBLICTRANSPORT_PROPERTY(int, floorLevelChange, setFloorLevelChange)

public:
    /** Maneuver associated with a path section. */
    enum Maneuver {
        Move, ///< Move/drive with the default mode of transport for this path
        Stairs, ///< Walk up or down stairs
        Elevator, ///< Take an elevator
        Escalator, ///< Take an escalator
    };
    Q_ENUM(Maneuver)
    /** Movement maneuver for this path section. */
    KPUBLICTRANSPORT_PROPERTY(Maneuver, maneuver, setManeuver)

public:
    /** Length of this path section in meters. */
    [[nodiscard]] int distance() const;
    /** The overall direction of this section in degree.
     *  @returns 0-359 for valid results, -1 for sections with no direction (e.g. points).
     */
    [[nodiscard]] int direction() const;

    /** First point on the path of this section. */
    [[nodiscard]] QPointF startPoint() const;
    /** Last point on the path of this section. */
    [[nodiscard]] QPointF endPoint() const;

    /** Serializes one path section section to JSON. */
    [[nodiscard]] static QJsonObject toJson(const PathSection &section);
    /** Serializes a vector of path sections to JSON. */
    [[nodiscard]] static QJsonArray toJson(const std::vector<PathSection> &sections);
    /** Deserialize an object from JSON. */
    [[nodiscard]] static PathSection fromJson(const QJsonObject &obj);
    /** Deserialize a vector of path sections from JSON. */
    [[nodiscard]] static std::vector<PathSection> fromJson(const QJsonArray &array);
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
    [[nodiscard]] bool isEmpty() const;

    /** The path sections. */
    [[nodiscard]] const std::vector<PathSection>& sections() const;
    /** Moves the path sections out of this object. */
    [[nodiscard]] std::vector<PathSection>&& takeSections();
    /** Sets the path sections. */
    void setSections(std::vector<PathSection> &&sections);

    /** Length of this path in meters. */
    [[nodiscard]] int distance() const;

    /** First point on this path. */
    [[nodiscard]] QPointF startPoint() const;
    /** Last point on this path. */
    [[nodiscard]] QPointF endPoint() const;

    /** Serializes one path object to JSON. */
    [[nodiscard]] static QJsonObject toJson(const Path &path);
    /** Deserialize an object from JSON. */
    [[nodiscard]] static Path fromJson(const QJsonObject &obj);

private:
    [[nodiscard]] int sectionCount() const;
};

}

Q_DECLARE_METATYPE(KPublicTransport::PathSection)
Q_DECLARE_METATYPE(std::vector<KPublicTransport::PathSection>)
Q_DECLARE_METATYPE(KPublicTransport::Path)

#endif // KPUBLICTRANSPORT_PATH_H
