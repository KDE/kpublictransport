/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_PLATFORMLAYOUT_H
#define KPUBLICTRANSPORT_PLATFORMLAYOUT_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Vehicle>

namespace KPublicTransport {

class Stopover;

/** Methods for determining positions on a platform.
 *
 *  The sectionsFor* method return a platform section range expression consumable by
 *  e.g. KOSMIndoorMaps.
 */
class KPUBLICTRANSPORT_EXPORT PlatformLayout
{
public:
    /** Returns all platform sections the given vehicle has coaches stopping at.
     *  This excludes powercars and engines.
     */
    static QString sectionsForVehicle(const Stopover &stopover);

    /** Returns all platform sections the given vehicle has coaches of class @cls at. */
    static QString sectionsForClass(const Stopover &stopover, VehicleSection::Class cls);

    /** Returns all platform sections the coach @p coachName stops at. */
    static QString sectionsForVehicleSection(const Stopover &stopover, const QString &coachName);
};

}

#endif // KPUBLICTRANSPORT_PLATFORMLAYOUT_H
