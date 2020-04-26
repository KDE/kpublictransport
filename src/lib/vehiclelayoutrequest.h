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

#ifndef KPUBLICTRANSPORT_VEHICLELAYOUTREQUEST_H
#define KPUBLICTRANSPORT_VEHICLELAYOUTREQUEST_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Datatypes>

#include <QDateTime>
#include <QMetaType>
#include <QSharedDataPointer>

namespace KPublicTransport {

class Stopover;
class JourneySection;
class VehicleLayoutRequestPrivate;

/** Describes a query for vehicle layout information. */
class KPUBLICTRANSPORT_EXPORT VehicleLayoutRequest
{
    KPUBLICTRANSPORT_GADGET(VehicleLayoutRequest)

    // TODO properties for manual setup

    // TODO should this really be exposed? we need the location for the geo filter though, if available
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Stopover, departure, setDeparture)

public:
    /** Creates a vehicle layout request for the given departure. */
    explicit VehicleLayoutRequest(const Stopover &dep);
    /** Create a vehilce layout request for the departure of the given journey section. */
    explicit VehicleLayoutRequest(const JourneySection &section);

    /** Create a vehicle layout request from a JourneySection out of QML. */
    Q_INVOKABLE KPublicTransport::VehicleLayoutRequest fromJourneySection(const KPublicTransport::JourneySection &section) const;

    /** Returns @c true if this is a valid request, that is it has enough parameters set to perform a query. */
    bool isValid() const;

    /** Unique string representation used for caching results. */
    QString cacheKey() const;

    /** Identifiers of the backends that should be queried.
     *  @see setBackendIds()
     */
    QStringList backendIds() const;
    /** Set identifiers of backends that should be queried.
     *  Settings this is only needed when you want explicit control over this, leaving
     *  this empty picks suitable backends automatically.
     */
    void setBackendIds(const QStringList &backendIds);

    ///@cond internal
    static QJsonObject toJson(const VehicleLayoutRequest &req);
    ///@endcond
};

}

Q_DECLARE_METATYPE(KPublicTransport::VehicleLayoutRequest)

#endif // KPUBLICTRANSPORT_VEHICLELAYOUTREQUEST_H
