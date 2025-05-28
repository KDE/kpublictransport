/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_CLASSUTIL_H
#define KPUBLICTRANSPORT_CLASSUTIL_H

#include <kpublictransport_export.h>

#include "vehicle.h"

namespace KPublicTransport {

/** Utility functions for dealing with seating classes.
 *  @since 25.08
 */
class KPUBLICTRANSPORT_EXPORT ClassUtil {
    Q_GADGET
public:
    /** Try to determine class type from a textual representation of the class. */
    Q_INVOKABLE [[nodiscard]] static KPublicTransport::VehicleSection::Classes fromString(const QString &className);

    /** Human-readable/translated description of the given class(es). */
    Q_INVOKABLE [[nodiscard]] static QString displayName(KPublicTransport::VehicleSection::Classes classes);
};

}

#endif
