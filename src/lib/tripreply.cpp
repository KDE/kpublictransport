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
};
}

using namespace KPublicTransport;

TripReply::TripReply(const TripRequest &req, QObject *parent)
    : Reply(new TripReplyPrivate, parent)
{
    Q_D(TripReply);
    d->request = req;
    d->trip = req.journeySection();
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

    const auto &stopovers = d->trip.intermediateStops();
    auto it = stopovers.begin();
    if (!Stopover::isSame(partialTrip.departure(), d->trip.departure())) {
        for (; it != stopovers.end(); ++it) {
            if (Stopover::isSame(partialTrip.departure(), *it)) {
                partialTrip.setDeparture(*it);
                break;
            }
        }
        if (it == stopovers.end()) {
            return d->trip;
        }
        ++it;
    }

    auto it2 = it;
    for (; it2 != stopovers.end(); ++it2) {
        if (Stopover::isSame(partialTrip.arrival(), *it2)) {
            partialTrip.setArrival(*it2);
            break;
        }
    }
    if (it2 == stopovers.end() && !Stopover::isSame(partialTrip.arrival(), d->trip.arrival())) {
        return d->trip;
    }

    partialTrip.setIntermediateStops({it, it2});
    partialTrip.setRoute(d->trip.route());

    auto path = d->trip.path();
    auto pathSections = path.takeSections();
    bool foundStart = false, foundEnd = false;
    for (auto secIt = pathSections.begin(); secIt != pathSections.end();) {
        auto poly = (*secIt).path();
        auto polyItBegin = poly.begin();
        auto polyItEnd = poly.end();
        bool foundEndNow = false;
        for (auto polyIt = polyItBegin; polyIt != poly.end() && !foundEnd; ++polyIt) {
            if (!foundStart && Location::distance((*polyIt).y(), (*polyIt).x(), partialTrip.from().latitude(), partialTrip.from().longitude()) < 50) {
                polyItBegin = polyIt;
                foundStart = true;
            }
            if (foundStart && !foundEnd && Location::distance((*polyIt).y(), (*polyIt).x(), partialTrip.to().latitude(), partialTrip.to().longitude()) < 50) {
                polyItEnd = std::next(polyIt);
                foundEndNow = true;
                break;
            }
        }

        if (!foundStart || foundEnd) {
            secIt = pathSections.erase(secIt);
        } else {
            (*secIt).setPath({polyItBegin, polyItEnd});
            ++secIt;
            if (foundEndNow) {
                foundEnd = true;
            }
        }
    }
    path.setSections(std::move(pathSections));
    partialTrip.setPath(path);

    return partialTrip;
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
