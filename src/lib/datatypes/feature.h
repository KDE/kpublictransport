/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_FEATURE_H
#define KPUBLICTRANSPORT_FEATURE_H

#include "kpublictransport_export.h"
#include "datatypes.h"
#include "disruption.h"

namespace KPublicTransport {

class FeaturePrivate;

/** An amenity, facility or other relevant property of a vehicle (train, bus, etc),
 *  vehicle part (e.g. train coach) or location.
 */
class KPUBLICTRANSPORT_EXPORT Feature {
    KPUBLICTRANSPORT_GADGET(Feature)

    /** A short human-readable label of this feature. */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)

    /** A short humand-readable label for this feature.
     *  Unlike name this returns a default label depending on the type
     *  of the feature, even if the data source for this didn't provide
     *  a name.
     */
    Q_PROPERTY(QString displayName READ displayName STORED false)

    /** An optional longer human-readable description.
     *  Strongly recommended e.g. for features with limited/condicational
     *  availability or with type @c Other.
     */
    KPUBLICTRANSPORT_PROPERTY(QString, description, setDescription)

    /** Type of the feature. */
    enum Type {
        NoFeature, ///< uninitialized/null
        AirConditioning, ///< area is air conditioned
        Restaurant, ///< a place to obtain food/drinks
        ToddlerArea, ///< infrastructure for toddler maintenance
        FamilyArea, ///< area dedicated for travelers with kids
        WheelchairAccessible, ///< wheelchair access possible
        SilentArea, ///< wishful thinking usually
        BusinessArea,
        BikeStorage, ///< vehicle contains space for bikes
        Toilet,
        WheelchairAccessibleToilet, ///< wheelchair accessible toilet
        InformationPoint, ///< a place to obtain information from a human
        WiFi, ///< Freely usable Wi-Fi network
        PowerSockets, ///< Power sockets for passenger use
        Other, ///< none of the above
    };
    Q_ENUM(Type)
    KPUBLICTRANSPORT_PROPERTY(Type, type, setType)

    /** Availability of the feature. */
    enum Availability {
        Unknown,
        Available,
        Unavailable, ///< It is known the specified feature does not exist (!= features is (temporarily) disrupted)
        Limited, ///< e.g. limited quantity
        Conditional, ///< e.g. feature is available only on explicit reservation or with a specific ticket/tariff
    };
    Q_ENUM(Availability)
    KPUBLICTRANSPORT_PROPERTY(Availability, availability, setAvailability)

    /** Distruption effects on the feature. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Disruption::Effect, disruptionEffect, setDisruptionEffect)

    /** Amount of instances of this feature.
     *  Eg. number of seats/spaces, 0 if unknown.
     */
    KPUBLICTRANSPORT_PROPERTY(int, quantity, setQuantity)

public:
    /** Convenience constructor for a Feature of type @p type and availability @p availability. */
    explicit Feature(Type type, Availability availability = Available);

    [[nodiscard]] QString displayName() const;

    /** Generic display name for feature of @p type. */
    [[nodiscard]] static QString typeDisplayName(KPublicTransport::Feature::Type type);

    /** Serializes one object to JSON. */
    [[nodiscard]] static QJsonObject toJson(const Feature &feature);
    /** Serializes a vector of features to JSON. */
    [[nodiscard]] static QJsonArray toJson(const std::vector<Feature> &features);
    /** Deserialize an object from JSON. */
    [[nodiscard]] static Feature fromJson(const QJsonObject &obj);
    /** Deserialize a vector of features from JSON. */
    [[nodiscard]] static std::vector<Feature> fromJson(const QJsonArray &array);

    /** Returns @c true if both features refer to the same thing.
     *  This doesn't mean they are identical, nor does this consider the context
     *  a feature belongs to.
     */
    [[nodiscard]] static bool isSame(const Feature &lhs, const Feature &rhs);
    /** Merge two features referring to the same thing. */
    [[nodiscard]] static Feature merge(const Feature &lhs, const Feature &rhs);
};

}

#endif
