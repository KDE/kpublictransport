/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "equipment.h"

#include "datatypes_p.h"
#include "json_p.h"
#include "notesutil_p.h"
#include "path.h"

using namespace KPublicTransport;
using namespace Qt::Literals;

namespace KPublicTransport {

class EquipmentPrivate : public QSharedData
{
public:
    Equipment::Type type = Equipment::Unknown;
    Disruption::Effect disruptionEffect = Disruption::NormalService;
    QStringList notes;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(Equipment)
KPUBLICTRANSPORT_MAKE_PROPERTY(Equipment, Equipment::Type, type, setType)
KPUBLICTRANSPORT_MAKE_PROPERTY(Equipment, Disruption::Effect, disruptionEffect, setDisruptionEffect)
KPUBLICTRANSPORT_MAKE_PROPERTY(Equipment, QStringList, notes, setNotes)

void Equipment::addNote(const QString& note)
{
    const auto n = NotesUtil::normalizeNote(note);
    const auto idx = NotesUtil::needsAdding(d->notes, n);
    if (idx >= 0) {
        d.detach();
        NotesUtil::performAdd(d->notes, n, idx);
    }
}

QString Equipment::iconName() const
{
    switch (d->type) {
        case Elevator:
            return PathSection::maneuverIconName(PathSection::Elevator);
        case Escalator:
            return PathSection::maneuverIconName(PathSection::Escalator);
        case Unknown:
            break;
    }

    return u"map-symbolic"_s;
}

QJsonObject Equipment::toJson(const Equipment &equipment)
{
    return Json::toJson(equipment);
}

Equipment Equipment::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<Equipment>(obj);
}

#include "moc_equipment.cpp"
