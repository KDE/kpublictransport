/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "equipmentutil.h"
#include "notesutil_p.h"

#include <KPublicTransport/Equipment>

using namespace KPublicTransport;

Equipment EquipmentUtil::merge(const Equipment &lhs, const Equipment &rhs)
{
    auto e = lhs;
    e.setDisruptionEffect(std::max(lhs.disruptionEffect(), rhs.disruptionEffect()));
    e.setNotes(NotesUtil::mergeNotes(lhs.notes(), rhs.notes()));
    e.setType(std::max(lhs.type(), rhs.type()));
    return e;
}
