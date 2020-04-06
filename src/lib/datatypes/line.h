/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef KPUBLICTRANSPORT_LINE_H
#define KPUBLICTRANSPORT_LINE_H

#include "datatypes.h"
#include "location.h"

namespace KPublicTransport {

class Line;
class LinePrivate;
class LineMetaData;
namespace LineUtil{
void setMetaData(Line&, LineMetaData);
}

/** A public transport line. */
class KPUBLICTRANSPORT_EXPORT Line
{
    KPUBLICTRANSPORT_GADGET(Line)

public:
    enum Mode { // ### direct copy from Navitia, we maybe can reduce that a bit
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

public:
    bool hasColor() const;
    bool hasTextColor() const;
    QString logo() const;
    bool hasLogo() const;
    QString modeLogo() const;
    bool hasModeLogo() const;

    /** Checks if to instances refer to the same line (which does not necessarily mean they are exactly equal). */
    static bool isSame(const Line &lhs, const Line &rhs);

    /** Merge two Line instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    static Line merge(const Line &lhs, const Line &rhs);

    /** Serializes one object to JSON. */
    static QJsonObject toJson(const Line &l);
    /** Deserialize an object from JSON. */
    static Line fromJson(const QJsonObject &obj);

private:
    friend void LineUtil::setMetaData(Line&, LineMetaData);
    void setMetaData(LineMetaData metaData);
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

public:
    /** Checks if to instances refer to the same route (which does not necessarily mean they are exactly equal). */
    static bool isSame(const Route &lhs, const Route &rhs);

    /** Merge two Route instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    static Route merge(const Route &lhs, const Route &rhs);

    /** Serializes one object to JSON. */
    static QJsonObject toJson(const Route &r);
    /** Deserialize an object from JSON. */
    static Route fromJson(const QJsonObject &obj);
};

}

Q_DECLARE_METATYPE(KPublicTransport::Line)
Q_DECLARE_METATYPE(KPublicTransport::Route)

#endif // KPUBLICTRANSPORT_LINE_H
