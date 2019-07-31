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
