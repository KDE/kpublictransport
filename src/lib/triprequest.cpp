/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "triprequest.h"

#include "datatypes/datatypes_p.h"
#include "datatypes//json_p.h"

#include <KPublicTransport/Journey>

#include <QJsonObject>

using namespace Qt::Literals;

namespace KPublicTransport {
class TripRequestPrivate : public QSharedData {
public:
    JourneySection journeySection;
    QStringList backendIds;
    bool downloadAssets;
};
}

using namespace KPublicTransport;

KPUBLICTRANSPORT_MAKE_GADGET(TripRequest)
KPUBLICTRANSPORT_MAKE_PROPERTY(TripRequest, JourneySection, journeySection, setJourneySection)
KPUBLICTRANSPORT_MAKE_PROPERTY(TripRequest, QStringList, backendIds, setBackendIds)
KPUBLICTRANSPORT_MAKE_PROPERTY(TripRequest, bool, downloadAssets, setDownloadAssets)

TripRequest::TripRequest(const JourneySection &journeySection)
    : d(new TripRequestPrivate)
{
    d->journeySection = journeySection;
}

bool TripRequest::isValid() const
{
    return d->journeySection.mode() != JourneySection::Invalid;
}

QJsonObject TripRequest::toJson(const TripRequest &req)
{
    QJsonObject obj = Json::toJson(req);
    obj.insert("journeySection"_L1, JourneySection::toJson(req.journeySection()));
    return obj;
}

#include "moc_triprequest.cpp"
