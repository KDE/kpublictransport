/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LINE_H
#define KPUBLICTRANSPORT_LINE_H

#include "datatypes.h"
#include "location.h"

namespace KPublicTransport {

class Line;
class LinePrivate;

/** A public transport line. */
class KPUBLICTRANSPORT_EXPORT Line
{
    KPUBLICTRANSPORT_GADGET(Line)

public:
    /** Mode of transportation.
     *  @toto direct copy from Navitia, we maybe can reduce that a bit
     */
    enum Mode {
        Unknown,
        Air,
        Boat,
        Bus,
        BusRapidTransit,
        Coach,
        Ferry,
        Funicular,
        LocalTrain,
        LongDistanceTrain,
        Metro,
        RailShuttle,
        RapidTransit,
        Shuttle,
        Taxi,
        Train,
        Tramway,
        RideShare, ///< peer-to-peer ride sharing/car pooling
    };
    Q_ENUM(Mode)

    /** Name of the line. */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)
    /** Color of the line. */
    KPUBLICTRANSPORT_PROPERTY(QColor, color, setColor)
    /** @c true if a line color is set. */
    Q_PROPERTY(bool hasColor READ hasColor STORED false)
    /** Text color to use on top of the line color. */
    KPUBLICTRANSPORT_PROPERTY(QColor, textColor, setTextColor)
    /** @c true if a text color is set. */
    Q_PROPERTY(bool hasTextColor READ hasTextColor STORED false)
    /** Type of transport. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Line::Mode, mode, setMode)
    /** Human readable representation of the type of transport.
     *  This is not necessarily a simple 1:1 mapping from mode, but can contain
     *  e.g. a product name.
     */
    KPUBLICTRANSPORT_PROPERTY(QString, modeString, setModeString)
    /** Path of a local file containing the line logo.
     *  A line logo is typically a simple icon containing the short line name
     *  and color.
     *  This is downloaded on demand, and therefore might not be available
     *  immediately.
     */
    Q_PROPERTY(QString logo READ logo STORED false)
    /** @c true if the line has a logo. */
    Q_PROPERTY(bool hasLogo READ hasLogo STORED false)

    /** Path of a local file containing the line mode logo.
     *  A mode logo is the logo of the mode of transportation, or "product"
     *  this line belongs to, such as the general logo for a subway or metro
     *  service of this operator or in this city.
     *  This is downloaded on demand, and therefore might not be available
     *  immediately.
     */
    Q_PROPERTY(QString modeLogo READ modeLogo STORED false)
    /** @c true if the line has a mode logo. */
    Q_PROPERTY(bool hasModeLogo READ hasModeLogo STORED false)

    /** Name of the operator running this line. */
    KPUBLICTRANSPORT_PROPERTY(QString, operatorName, setOperatorName)

    /** Generic icon for the line mode.
     *  @see modeIconName(Line::Mode)
     */
    Q_PROPERTY(QString modeIconName READ modeIconName STORED false)

    /** The best available icon for this line.
     *  Either the line logo, mode logo or generic mode icon.
     *  Can be a file: or qrc: URI or a XDG icon name.
     */
    Q_PROPERTY(QString iconName READ iconName STORED false)
public:
    [[nodiscard]] bool hasColor() const;
    [[nodiscard]] bool hasTextColor() const;
    [[nodiscard]] QString logo() const;
    [[nodiscard]] bool hasLogo() const;
    [[nodiscard]] QString modeLogo() const;
    [[nodiscard]] bool hasModeLogo() const;
    [[nodiscard]] QString modeIconName() const;
    [[nodiscard]] QString iconName() const;

    /** Name of an icon to represent @p mode.
     *  Can be an qrc: URL or a icon name compatbile with QIcon::fromTheme.
     */
    Q_INVOKABLE [[nodiscard]] static QString modeIconName(KPublicTransport::Line::Mode mode);

    /** Look up line meta data and apply what is found.
     *  @param location A location on or close to the line.
     *  @param download When set to @c true, not yet locally present logo URLs are retrieved.
     */
    void applyMetaData(const Location &location, bool download);

    /** Checks if to instances refer to the same line (which does not necessarily mean they are exactly equal). */
    [[nodiscard]] static bool isSame(const Line &lhs, const Line &rhs);

    /** Merge two Line instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    [[nodiscard]] static Line merge(const Line &lhs, const Line &rhs);

    /** Serializes one object to JSON. */
    [[nodiscard]] static QJsonObject toJson(const Line &l);
    /** Deserialize an object from JSON.
     *  @note Line meta data isn't serialized, so you might need to call applyLineMetaData() again
     *  after loading a line.
     */
    [[nodiscard]] static Line fromJson(const QJsonObject &obj);
};

class RoutePrivate;

/** A route of a public transport line. */
class KPUBLICTRANSPORT_EXPORT Route
{
    KPUBLICTRANSPORT_GADGET(Route)
    /** Line this route belongs to. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Line, line, setLine)
    /** Direction of the route.
     *  The direction of the the route is what is displayed on front of a train for example.
     *  For directional lines it matches the destination. For circular lines there is no destination
     *  however, the direction is then clockwise" for example.
     */
    KPUBLICTRANSPORT_PROPERTY(QString, direction, setDirection)
    /** Destination of the route.
     *  If this is set it should match the direction of the line. Circular lines for example do
     *  not have a destination location though.
     */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Location, destination, setDestination)

    /** Name of the route.
     *  This is not to be confused with the name of the line, which is the much more commonly used
     *  value. Use this only if both are in use and you know which one is which, otherwise default
     *  to the line name.
     *  @see Line::name.
     */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)

public:
    /** Checks if to instances refer to the same route (which does not necessarily mean they are exactly equal). */
    [[nodiscard]] static bool isSame(const Route &lhs, const Route &rhs);

    /** Merge two Route instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    [[nodiscard]] static Route merge(const Route &lhs, const Route &rhs);

    /** Serializes one object to JSON. */
    [[nodiscard]] static QJsonObject toJson(const Route &r);
    /** Deserialize an object from JSON. */
    [[nodiscard]] static Route fromJson(const QJsonObject &obj);
};

}

Q_DECLARE_METATYPE(KPublicTransport::Line)
Q_DECLARE_METATYPE(KPublicTransport::Route)

#endif // KPUBLICTRANSPORT_LINE_H
