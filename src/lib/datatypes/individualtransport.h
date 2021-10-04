/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_INDIVIDUALTRANSPORT_H
#define KPUBLICTRANSPORT_INDIVIDUALTRANSPORT_H

#include "kpublictransport_export.h"
#include "datatypes.h"

namespace KPublicTransport {

class IndividualTransportPrivate;

/** Individual transport mode details for a journey section, and for specifying journey requests. */
class KPUBLICTRANSPORT_EXPORT IndividualTransport
{
    KPUBLICTRANSPORT_GADGET(IndividualTransport)
public:
    /** Mode of (individual) transportation. */
    enum Mode {
        Walk,
        Bike,
        Car
    };
    Q_ENUM(Mode)
    KPUBLICTRANSPORT_PROPERTY(Mode, mode, setMode)

public:
    /** Qualifier on how the mode of transport is used. */
    enum Qualifier {
        None, ///< not applicable, or bike is taken on public transport legs.
        Park, ///< for access legs, vehicle is parked before taking public transport.
        Rent, ///< use a rental vehicle
        Dropoff, ///< for access legs: vehicle is not taken onto public transport but also doesn't need parking
        Pickup, ///<  for egress legs: vehicle is available at the last public transport leg
    };
    Q_ENUM(Qualifier)
    KPUBLICTRANSPORT_PROPERTY(Qualifier, qualifier, setQualifier)

public:
    IndividualTransport(Mode mode, Qualifier qualifier = None);

    bool operator==(const IndividualTransport &other) const;

    /** Serializes one object to JSON. */
    static QJsonObject toJson(const IndividualTransport &it);
    /** Serializes a vector of objects to JSON. */
    static QJsonArray toJson(const std::vector<IndividualTransport> &its);
    /** Deserialize an object from JSON. */
    static IndividualTransport fromJson(const QJsonObject &obj);
    /** Deserialize a list of journey from JSON. */
    static std::vector<IndividualTransport> fromJson(const QJsonArray &array);

    /** @internal for QML bindings only */
    static std::vector<IndividualTransport> fromVariant(const QVariantList &v);
};

}

Q_DECLARE_METATYPE(KPublicTransport::IndividualTransport)

#endif // KPUBLICTRANSPORT_INDIVIDUALTRANSPORT_H
