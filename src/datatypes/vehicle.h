/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_VEHICLE_H
#define KPUBLICTRANSPORT_VEHICLE_H

#include <kpublictransport_export.h>

#include "datatypes.h"

namespace KPublicTransport {

class VehicleSectionPrivate;

/** Information about a part of a vehicle.
 *  This typically describes a coach of a train.
 */
class KPUBLICTRANSPORT_EXPORT VehicleSection
{
    KPUBLICTRANSPORT_GADGET(VehicleSection)

    /** Human readable identifier of this section, typically the coach number.
     *  Can be empty for sections closed to passengers, such as train engines.
     */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)

    /** Relative position [0-1] of the begin of this vehicle section on the platform.
     *  0 representing the begin of the platform in platform coordinate (@see Platform), 1 being the opposite end.
     */
    KPUBLICTRANSPORT_PROPERTY(float, platformPositionBegin, setPlatformPositionBegin)
    /** Relative position [0-1] of the end of this vehicle section on the platform.
     *  0 representing the begin of the platform in platform coordinate (@see Platform), 1 being the opposite end.
     */
    KPUBLICTRANSPORT_PROPERTY(float, platformPositionEnd, setPlatformPositionEnd)

    /** Vehicle section type. */
    enum Type {
        UnknownType, ///< no information about the vehicle section type available
        Engine, ///< train engine, not accessible by passenders, only shown for orientation
        PowerCar, ///< power car of a train, similar to Engine, distinction exists just for better visualization
        ControlCar, ///< usually at the head of the train, but accessible for passengers and the same way as a PassengerCar
        PassengerCar, ///< passenger car of a train
        RestaurantCar, ///< full-car restaurant
    };
    Q_ENUM(Type)
    /** Type of this vehicle section. */
    KPUBLICTRANSPORT_PROPERTY(Type, type, setType)

    /** Classes available in a vehicle section. */
    enum Class {
        UnknownClass = 0,
        FirstClass = 1, ///< 1st class
        SecondClass = 2, ///< 2nd class
        ThirdClass = 4 ///< 3rd class
    };
    Q_DECLARE_FLAGS(Classes, Class)
    Q_FLAG(Classes)
    /** Classes available in this vehicle section.
     *  Can be more than one.
     */
    KPUBLICTRANSPORT_PROPERTY(Classes, classes, setClasses)

    /** Amenities or other features availbale in a vehicle section. */
    enum Feature {
        NoFeatures = 0,
        AirConditioning = 1, ///< vehicle section is air conditioned
        Restaurant = 2, ///< vehicle has a place to obtain food/drinks (but not necessarily a full-scale RestaurantCar)
        ToddlerArea = 4, ///< vehicle section contains infrastructure for toddler maintenance
        WheelchairAccessible = 8, ///< wheelchair access supported
        SilentArea = 16, ///< wishful thinking usually
        BikeStorage = 32, ///< vehicle section contains space for bikes
        // TODO there's a few more we get from DB
    };
    Q_DECLARE_FLAGS(Features, Feature)
    Q_FLAG(Features)
    /** Features available in this vehicle section.
     *  Can be more than one.
     */
    KPUBLICTRANSPORT_PROPERTY(Features, features, setFeatures)
    /** Feature flag as a variant list, for consumption in QML. */
    Q_PROPERTY(QVariantList featureList READ featureList STORED false)

    // TODO where to put deck number?

    /** Serializes one vehicle section to JSON. */
    static QJsonObject toJson(const VehicleSection &section);
    /** Serializes a vector of vehicle sections to JSON. */
    static QJsonArray toJson(const std::vector<VehicleSection> &sections);
    /** Deserialize an object from JSON. */
    static VehicleSection fromJson(const QJsonObject &obj);
    /** Deserialize a vector of vehicle sections from JSON. */
    static std::vector<VehicleSection> fromJson(const QJsonArray &array);

private:
    QVariantList featureList() const;
};

class VehiclePrivate;

/** Information about the vehicle used on a journey.
 *  This is typically only available for trains, and describes their coach layout.
 */
class KPUBLICTRANSPORT_EXPORT Vehicle
{
    KPUBLICTRANSPORT_GADGET(Vehicle)
    /** Human readable identifier of this vehicle, typically a train number. */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)

    /** Direction of travel. */
    enum Direction {
        UnknownDirection,
        Forward, ///< vehicle departs toward the 0 platform coordinate
        Backward ///< vehicle departs toward the 1 platforma coordinate
    };
    Q_ENUM(Direction)
    /** Direction of travel of this vehicle. */
    KPUBLICTRANSPORT_PROPERTY(Direction, direction, setDirection)

    /** Journey sections for consumption by QML. */
    Q_PROPERTY(QVariantList sections READ sectionsVariant)

public:
    /** The vehicle sections. */
    const std::vector<VehicleSection>& sections() const;
    /** Moves the vehicle sections out of this object. */
    std::vector<VehicleSection>&& takeSections();
    /** Sets the vehicle sections. */
    void setSections(std::vector<VehicleSection> &&sections);

    /** Serializes one vehicle object to JSON. */
    static QJsonObject toJson(const Vehicle &vehicle);
    /** Deserialize an object from JSON. */
    static Vehicle fromJson(const QJsonObject &obj);

private:
    QVariantList sectionsVariant() const;
};

}

Q_DECLARE_OPERATORS_FOR_FLAGS(KPublicTransport::VehicleSection::Classes)
Q_DECLARE_OPERATORS_FOR_FLAGS(KPublicTransport::VehicleSection::Features)
Q_DECLARE_METATYPE(KPublicTransport::VehicleSection)
Q_DECLARE_METATYPE(KPublicTransport::Vehicle)

#endif // KPUBLICTRANSPORT_VEHICLE_H
