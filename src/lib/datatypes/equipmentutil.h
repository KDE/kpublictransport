/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_EQUIPMENTUTIL_P_H
#define KPUBLICTRANSPORT_EQUIPMENTUTIL_P_H

namespace KPublicTransport {

class Equipment;

/** Utilities for working with Equipment instances. */
namespace EquipmentUtil
{
    Equipment merge(const Equipment &lhs, const Equipment &rhs);
}

}

#endif // KPUBLICTRANSPORT_EQUIPMENTUTIL_P_H
