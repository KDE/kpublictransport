/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_TRIPREQUEST_H
#define KPUBLICTRANSPORT_TRIPREQUEST_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Datatypes>

#include <QMetaType>
#include <QSharedDataPointer>

class QJsonObject;

namespace KPublicTransport {

class JourneySection;
class TripRequestPrivate;

/** Request for a single trip. That is, one specific run along a route.
 *  This is usually based on a JourneySection from a preceeding journey query.
 *
 *  @since 25.04
 */
class KPUBLICTRANSPORT_EXPORT TripRequest
{
    KPUBLICTRANSPORT_GADGET(TripRequest)
    /** A JourneySection for which the full trip is requested. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::JourneySection, journeySection, setJourneySection)
    /** Identifiers of backends that should be queried.
     *  Settings this is only needed when you want explicit control over this, leaving
     *  this empty picks suitable backends automatically.
     */
    KPUBLICTRANSPORT_PROPERTY(QStringList, backendIds, setBackendIds)

    /** Download graphic assets such as line logos for the data requested here.
     *  Default: @c false
     */
    KPUBLICTRANSPORT_PROPERTY(bool, downloadAssets, setDownloadAssets)

public:
    /** Create a TripRequest for @p journeySection. */
    TripRequest(const JourneySection &journeySection);

    /** Returns @c true if this is a valid request, that is it has enough parameters set to perform a query. */
    [[nodiscard]] bool isValid() const;

    ///@cond internal
    static QJsonObject toJson(const TripRequest &req);
    ///@endcond
};

}

#endif
