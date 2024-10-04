/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_EQUIPMENT_H
#define KPUBLICTRANSPORT_EQUIPMENT_H

#include "kpublictransport_export.h"

#include "datatypes.h"
#include "disruption.h"

#include <QStringList>

class QJsonObject;

namespace KPublicTransport {

class EquipmentPrivate;

/** Status information about equipment such as elevators or escalators. */
class KPUBLICTRANSPORT_EXPORT Equipment
{
    KPUBLICTRANSPORT_GADGET(Equipment)
public:
    /** Type of equipment. */
    enum Type {
        Unknown,
        Elevator,
        Escalator,
    };
    Q_ENUM(Type)
    KPUBLICTRANSPORT_PROPERTY(Type, type, setType)

    /** Disruption effect on this section, if any. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Disruption::Effect, disruptionEffect, setDisruptionEffect)
    /** General human-readable notes on this service, e.g. details about a disruption. */
    KPUBLICTRANSPORT_PROPERTY(QStringList, notes, setNotes)

    /** An icon representing the equipment type.
     *  Can be a qrc: URL or XDG icon name.
     */
    Q_PROPERTY(QString iconName READ iconName STORED false)

public:
    /** Adds a note. This will check for duplicates and normalize the notes. */
    void addNote(const QString &note);

    [[nodiscard]] QString iconName() const;

    /** Serializes one object to JSON. */
    static QJsonObject toJson(const Equipment &equipment);
    /** Deserialize an object from JSON. */
    static Equipment fromJson(const QJsonObject &obj);
};

}

Q_DECLARE_METATYPE(KPublicTransport::Equipment)

#endif // KPUBLICTRANSPORT_EQUIPMENT_H
