/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_PLATFORMUTILS_P_H
#define KPUBLICTRANSPORT_PLATFORMUTILS_P_H

class QString;

namespace KPublicTransport {

/** Platform normalization utilities. */
namespace PlatformUtils
{
    /** Normalize platform names. */
    QString normalizePlatform(const QString &platform);

    /** Implementation for the "xPlatformChanged" properties in Journey and Departure. */
    bool platformChanged(const QString &scheduledPlatform, const QString &expectedPlatform);
}

}

#endif // KPUBLICTRANSPORT_PLATFORMUTILS_H
