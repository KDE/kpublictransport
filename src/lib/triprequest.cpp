/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "triprequest.h"

#include "datatypes/datatypes_p.h"
#include "datatypes//json_p.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Stopover>

#include <QJsonObject>

using namespace Qt::Literals;

namespace KPublicTransport {
class TripRequestPrivate : public QSharedData {
public:
    JourneySection journeySection;
    Stopover stopover;
    QStringList backendIds;
    bool downloadAssets;
};
}

using namespace KPublicTransport;

KPUBLICTRANSPORT_MAKE_GADGET(TripRequest)
KPUBLICTRANSPORT_MAKE_PROPERTY(TripRequest, JourneySection, journeySection, setJourneySection)
KPUBLICTRANSPORT_MAKE_PROPERTY(TripRequest, Stopover, stopover, setStopover)
KPUBLICTRANSPORT_MAKE_PROPERTY(TripRequest, QStringList, backendIds, setBackendIds)
KPUBLICTRANSPORT_MAKE_PROPERTY(TripRequest, bool, downloadAssets, setDownloadAssets)

TripRequest::TripRequest(const JourneySection &journeySection)
    : d(new TripRequestPrivate)
{
    d->journeySection = journeySection;
}

TripRequest::TripRequest(const Stopover &stopover)
    : d(new TripRequestPrivate)
{
    d->stopover = stopover;
}

bool TripRequest::isValid() const
{
    return d->stopover.hasTripIdentifiers() || d->journeySection.mode() != JourneySection::Invalid;
}

QString TripRequest::identifier(QAnyStringView identifierType) const
{
    return d->stopover.hasTripIdentifiers() ? d->stopover.tripIdentifier(identifierType) : d->journeySection.identifier(identifierType);
}

bool TripRequest::hasIdentifiers() const
{
    return d->journeySection.hasIdentifiers() || d->stopover.hasTripIdentifiers();
}

QJsonObject TripRequest::toJson(const TripRequest &req)
{
    QJsonObject obj = Json::toJson(req);
    if (req.stopover().hasTripIdentifiers()) {
        obj.insert("stopover"_L1, Stopover::toJson(req.stopover()));
    } else {
        obj.insert("journeySection"_L1, JourneySection::toJson(req.journeySection()));
    }
    return obj;
}

#include "moc_triprequest.cpp"
