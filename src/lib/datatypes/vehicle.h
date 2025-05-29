/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_VEHICLE_H
#define KPUBLICTRANSPORT_VEHICLE_H

#include "kpublictransport_export.h"

#include "datatypes.h"
#include "feature.h"
#include "load.h"

namespace KPublicTransport {

class VehicleSectionPrivate;

/** Information about a part of a vehicle.
 *  This typically describes a coach of a train.
 *  @see Vehicle
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
        Engine, ///< train engine, not accessible by passengers, only shown for orientation
        PowerCar, ///< power car of a train, similar to Engine, distinction exists just for better visualization
        ControlCar, ///< usually at the head of the train, but accessible for passengers and the same way as a PassengerCar
        PassengerCar, ///< passenger car of a train
        RestaurantCar, ///< full-car restaurant
        SleepingCar, ///< sleeping passenger car of an overnight train
        CouchetteCar, ///< couchette passenger car of an overnight train
        CarTransportCar, ///< car for transporting cars
    };
    Q_ENUM(Type)
    /** Type of this vehicle section. */
    KPUBLICTRANSPORT_PROPERTY(Type, type, setType)

    /** Translated humand readable name of vehicle section type.
     *  @since 25.08
     */
    Q_PROPERTY(QString typeName READ typeName STORED false)
    [[nodiscard]] QString typeName() const;

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

    /** Translated human readable names of the seating classes of this section.
     *  @since 25.08
     */
    Q_PROPERTY(QString classesName READ classesName STORED false)
    [[nodiscard]] QString classesName() const;

    /** Features of this section, for consumption by QML. */
    Q_PROPERTY(std::vector<KPublicTransport::Feature> sectionFeatures READ sectionFeatures STORED false)

    [[nodiscard]] const std::vector<KPublicTransport::Feature>& sectionFeatures() const;
    [[nodiscard]] std::vector<KPublicTransport::Feature>&& takeSectionFeatures();
    void setSectionFeatures(std::vector<KPublicTransport::Feature> &&features);

    /** Returns the first feature of type @p type.
     *  Returns an invalid feature of no feature of that type exists.
     */
    Q_INVOKABLE [[nodiscard]] KPublicTransport::Feature feature(KPublicTransport::Feature::Type type) const;

    /** Number of decks in this vehicle section. */
    KPUBLICTRANSPORT_PROPERTY(int, deckCount, setDeckCount)

    /** Vehicle section side.
     *  Front is towards the smaller platform coordinate, Back is the opposite direction.
     */
    enum Side {
        NoSide = 0,
        Front = 1,
        Back = 2
    };
    Q_DECLARE_FLAGS(Sides, Side)
    Q_FLAG(Sides)
    /** Sides on which this vehicle section is connected to neighboring sections
     *  in a way that passengers can move between those sections.
     *  This matters for example for a double segment train with to control cars
     *  in the middle of its full layout.
     */
    KPUBLICTRANSPORT_PROPERTY(Sides, connectedSides, setConnectedSides)

    /** Distruption affecting this coach.
     *  Disruption::NoService here means the coach is closed.
     */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Disruption::Effect, disruptionEffect, setDisruptionEffect)

    /** Occupancy level for this coach. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Load::Category, load, setLoad)

    /** Name of the platform section(s) this coach is position in.
     *  This is primarily meant as a fallback when exact platform positions aren't available.
     */
    KPUBLICTRANSPORT_PROPERTY(QString, platformSectionName, setPlatformSectionName)

    /** Returns @c true if this vehicle section has a valid platform position set. */
    [[nodiscard]] bool hasPlatformPosition() const;

    /** Returns a suitable icon to represent the coach type.
     *  Can be a qrc: URL, an XDG icon name or empty.
     *  @since 24.08
     */
    Q_INVOKABLE [[nodiscard]] static QString vehicleTypeIconName(KPublicTransport::VehicleSection::Type type);

    /** A suitable icon representing the coach.
     *  Can be a qrc: URL, an XDG icon name or empty.
     *  @since 24.08
     */
    Q_PROPERTY(QString iconName READ iconName STORED false)
    [[nodiscard]] QString iconName() const;

    /** Merge two VehicleSection instances. */
    [[nodiscard]] static VehicleSection merge(const VehicleSection &lhs, const VehicleSection &rhs);

    /** Serializes one vehicle section to JSON. */
    [[nodiscard]] static QJsonObject toJson(const VehicleSection &section);
    /** Serializes a vector of vehicle sections to JSON. */
    [[nodiscard]] static QJsonArray toJson(const std::vector<VehicleSection> &sections);
    /** Deserialize an object from JSON. */
    [[nodiscard]] static VehicleSection fromJson(const QJsonObject &obj);
    /** Deserialize a vector of vehicle sections from JSON. */
    [[nodiscard]] static std::vector<VehicleSection> fromJson(const QJsonArray &array);

private:
    [[nodiscard]] QVariantList featureList() const;
};

class VehiclePrivate;

/** Information about the vehicle used on a journey.
 *  This is typically only available for trains, and describes their coach layout.
 *
 *  A vehicle object always is tied to a specific Platform object, to which all positions
 *  refer to.
 *  @see Platform
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

    /** Relative position [0-1] of the begin of this vehicle on the platform.
     *  0 representing the begin of the platform in platform coordinate (@see Platform), 1 being the opposite end.
     */
    Q_PROPERTY(float platformPositionBegin READ platformPositionBegin STORED false)
    /** Relative position [0-1] of the end of this vehicle on the platform.
     *  0 representing the begin of the platform in platform coordinate (@see Platform), 1 being the opposite end.
     */
    Q_PROPERTY(float platformPositionEnd READ platformPositionEnd STORED false)

    /** Features of this vehicle as a whole, not including the features of individual sections. */
    Q_PROPERTY(std::vector<KPublicTransport::Feature> features READ features)

    /** Features of the entire vehicle including a union of all features of the individual sections. */
    Q_PROPERTY(std::vector<KPublicTransport::Feature> combinedFeatures READ combinedFeatures STORED false)

    /** Aggrgated occupancy information from all sections. */
    Q_PROPERTY(std::vector<KPublicTransport::LoadInfo> aggregatedOccupancy READ aggregatedOccupancy STORED false)

public:
    /** Returns @c true if this object contains no information beyond the default values. */
    [[nodiscard]] bool isEmpty() const;

    /** The vehicle sections. */
    [[nodiscard]] const std::vector<VehicleSection>& sections() const;
    /** Moves the vehicle sections out of this object. */
    [[nodiscard]] std::vector<VehicleSection>&& takeSections();
    /** Sets the vehicle sections. */
    void setSections(std::vector<VehicleSection> &&sections);
    void setSections(const std::vector<VehicleSection> &sections);

    [[nodiscard]] float platformPositionBegin() const;
    [[nodiscard]] float platformPositionEnd() const;

    /** Returns the center position of the vehicle section named @p sectionName
     *  in relative platform coordinates.
     *  Useful for centering a view on a selected section for example.
     */
    Q_INVOKABLE [[nodiscard]] float platformPositionForSection(const QString &sectionName) const;

    /** Checks whether all vehicle sections have platform positions set. */
    [[nodiscard]] bool hasPlatformPositions() const;
    /** Check whether all vehicle sections have platform section names set. */
    [[nodiscard]] bool hasPlatformSectionNames() const;

    /** Vehicle features. */
    [[nodiscard]] const std::vector<KPublicTransport::Feature>& features() const;
    [[nodiscard]] std::vector<KPublicTransport::Feature>&& takeFeatures();
    void setFeatures(std::vector<KPublicTransport::Feature> &&features);

    /** Combined vehicle features. */
    [[nodiscard]] std::vector<KPublicTransport::Feature> combinedFeatures() const;

    /** Aggregated occupancy information. */
    [[nodiscard]] std::vector<KPublicTransport::LoadInfo> aggregatedOccupancy() const;

    /** Merge two Vehicle instances. */
    [[nodiscard]] static Vehicle merge(const Vehicle &lhs, const Vehicle &rhs);

    /** Serializes one vehicle object to JSON. */
    [[nodiscard]] static QJsonObject toJson(const Vehicle &vehicle);
    /** Serializes multiple vehicle objects to JSON. */
    [[nodiscard]] static QJsonArray toJson(const std::vector<Vehicle> &vehicles);
    /** Deserialize an object from JSON. */
    [[nodiscard]] static Vehicle fromJson(const QJsonObject &obj);
    /** Deserialize multiple objects from JSON. */
    [[nodiscard]] static std::vector<Vehicle> fromJson(const QJsonArray &array);

private:
    [[nodiscard]] QVariantList sectionsVariant() const;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(VehicleSection::Classes)
Q_DECLARE_OPERATORS_FOR_FLAGS(VehicleSection::Sides)

}

Q_DECLARE_METATYPE(KPublicTransport::VehicleSection)
Q_DECLARE_METATYPE(KPublicTransport::Vehicle)

#endif // KPUBLICTRANSPORT_VEHICLE_H
