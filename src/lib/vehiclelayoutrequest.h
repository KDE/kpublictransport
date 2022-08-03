/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
class VehicleLayoutRequestPrivate;

/** Describes a query for vehicle layout information. */
class KPUBLICTRANSPORT_EXPORT VehicleLayoutRequest
{
    KPUBLICTRANSPORT_GADGET(VehicleLayoutRequest)

    /** The stopover vehicle and platform layout information are requested for. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Stopover, stopover, setStopover)

public:
    /** Creates a vehicle layout request for the given stopover. */
    explicit VehicleLayoutRequest(const Stopover &stopover);

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
