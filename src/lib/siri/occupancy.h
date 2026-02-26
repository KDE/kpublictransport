/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_SIRI_OCCUPANCY_H
#define KPUBLICTRANSPORT_SIRI_OCCUPANCY_H

#include <KPublicTransport/Load>

namespace KPublicTransport {

/** Utilities for reading SIRI data. */
namespace Siri {

/** Convert a SIRI Occupancy Enum value to our own occupancy representation. */
Load::Category fromOccupancyEnum(QStringView occupancyEnumName);

}
}

#endif
