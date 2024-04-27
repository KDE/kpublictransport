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

    /** Name of an icon to represent this transport mode.
     *  This does not consider the Qualifier value.
     *  Can be an qrc: URL or a icon name compatbile with QIcon::fromTheme.
     */
    Q_PROPERTY(QString modeIconName READ modeIconName STORED false)

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
    [[nodiscard]] QString modeIconName() const;

    [[nodiscard]] bool operator==(const IndividualTransport &other) const;
    [[nodiscard]] bool operator!=(const IndividualTransport &other) const;

    /** Name of an icon to represent @p mode.
     *  Can be an qrc: URL or a icon name compatbile with QIcon::fromTheme.
     */
    Q_INVOKABLE [[nodiscard]] static QString modeIconName(KPublicTransport::IndividualTransport::Mode mode);

    /** Serializes one object to JSON. */
    [[nodiscard]] static QJsonObject toJson(const IndividualTransport &it);
    /** Serializes a vector of objects to JSON. */
    [[nodiscard]] static QJsonArray toJson(const std::vector<IndividualTransport> &its);
    /** Deserialize an object from JSON. */
    [[nodiscard]] static IndividualTransport fromJson(const QJsonObject &obj);
    /** Deserialize a list of journey from JSON. */
    [[nodiscard]] static std::vector<IndividualTransport> fromJson(const QJsonArray &array);

    /** @internal for QML bindings only */
    [[nodiscard]] static std::vector<IndividualTransport> fromVariant(const QVariantList &v);
};

}

Q_DECLARE_METATYPE(KPublicTransport::IndividualTransport)

#endif // KPUBLICTRANSPORT_INDIVIDUALTRANSPORT_H
