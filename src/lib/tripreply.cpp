/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "tripreply.h"

#include "logging.h"
#include "reply_p.h"
#include "triprequest.h"

#include "backends/abstractbackend.h"
#include "backends/cache.h"
#include "datatypes/journeyutil_p.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Stopover>

namespace KPublicTransport {
class TripReplyPrivate: public ReplyPrivate {
public:
    void finalizeResult() override {}

    TripRequest request;
    JourneySection trip;
    qsizetype beginIdx = -1;
    qsizetype endIdx = -1;
};
}

using namespace KPublicTransport;

TripReply::TripReply(const TripRequest &req, QObject *parent)
    : Reply(new TripReplyPrivate, parent)
{
    Q_D(TripReply);
    d->request = req;
    d->trip = req.journeySection();
    d->beginIdx = 0;
    d->endIdx = (qsizetype)d->trip.intermediateStops().size() + 1;
}

TripReply::~TripReply() = default;

TripRequest TripReply::request() const
{
    Q_D(const TripReply);
    return d->request;
}

JourneySection TripReply::trip() const
{
    Q_D(const TripReply);
    return d->trip;
}

JourneySection TripReply::journeySection() const
{
    Q_D(const TripReply);
    auto partialTrip = d->request.journeySection();

    // do we have enough to go on to cut out a partial trip? is that even needed?
    if (partialTrip.from().name().isEmpty() || partialTrip.to().name().isEmpty() || JourneySection::isSame(partialTrip, d->trip) || d->trip.intermediateStops().empty()) {
        return d->trip;
    }

    if (d->beginIdx < 0 || d->endIdx < 0) {
        return d->trip;
    }
    partialTrip = d->trip.subsection(d->beginIdx, d->endIdx);
    partialTrip.setRoute(d->trip.route());
    return partialTrip;
}

qsizetype TripReply::journeySectionBegin() const
{
    Q_D(const TripReply);
    return d->beginIdx;
}

qsizetype TripReply::journeySectionEnd() const
{
    Q_D(const TripReply);
    return d->endIdx;
}

void TripReply::addResult(const AbstractBackend *backend, JourneySection &&journeySection)
{
    Q_D(TripReply);
    JourneyUtil::propagateTimeZones(journeySection);

    if (JourneySection::isSame(journeySection, d->trip)) {
        d->trip = JourneySection::merge(d->trip, journeySection);
    } else {
        auto route = Route::merge(d->trip.route(), journeySection.route());
        d->trip = journeySection;
        d->trip.setRoute(route);
    }
    d->beginIdx = d->trip.indexOfStopover(d->request.journeySection().departure());
    d->endIdx = d->trip.indexOfStopover(d->request.journeySection().arrival());

    JourneyUtil::postProcessPath(d->trip);
    d->trip.applyMetaData(request().downloadAssets());

    // apply static attributions if @p backend contributed to the results (can be nullptr for emulated results!)
    if (backend) {
        addAttribution(backend->attribution());
    }

    d->pendingOps--;
    d->emitFinishedIfDone(this);
}

void TripReply::addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg)
{
    if (error == Reply::NotFoundError) {
        // TODO add negative cache entry
    } else {
        qCDebug(Log) << backend->backendId() << error << errorMsg;
    }
    Reply::addError(error, errorMsg);
}

#include "moc_tripreply.cpp"
