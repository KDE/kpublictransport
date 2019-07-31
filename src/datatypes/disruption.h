/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef KPUBLICTRANSPORT_DISRUPTION_H
#define KPUBLICTRANSPORT_DISRUPTION_H

#include "kpublictransport_export.h"

#include <QMetaType>

namespace KPublicTransport {

/** Disruption information for a Departure or a JourneySection.
 *  This follows how Navitia models disruptions which follows how GTFS-rt models disruptions.
 *  @see https://developers.google.com/transit/gtfs-realtime/reference/#message-alert
 */
namespace Disruption
{
    KPUBLICTRANSPORT_EXPORT Q_NAMESPACE

    /** Disruption effects, numerical sorted so that higher values imply more severe disruptions. */
    enum Effect {
        NormalService = 0,
        NoService = 1024
    };

    Q_ENUM_NS(Effect)
}

}

#endif // KPUBLICTRANSPORT_DISRUPTION_H
