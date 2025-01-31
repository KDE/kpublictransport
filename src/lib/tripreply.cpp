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

    // find the closest points on the path to the departure/arrival locations
    // we have to expect aribitrarly broken/imprecise data here...
    qsizetype beginSection = -1, beginPoint = -1, endSection = -1, endPoint = -1;
    double beginMinDist = std::numeric_limits<double>::max(), endMinDist = std::numeric_limits<double>::max();
    for (std::size_t i = 0; i < pathSections.size(); ++i) {
        const auto poly = pathSections[i].path();
        for (qsizetype j = 0; j < poly.size(); ++j) {
            const auto p = poly[j];
            if (const auto d = Location::distance(p.y(), p.x(), partialTrip.from().latitude(), partialTrip.from().longitude()); d <beginMinDist) {
                beginSection = (qsizetype)i;
                beginPoint = j;
                beginMinDist = d;
            }
            if (const auto d = Location::distance(p.y(), p.x(), partialTrip.to().latitude(), partialTrip.to().longitude()); d <endMinDist) {
                endSection = (qsizetype)i;
                endPoint = j;
                endMinDist = d;
            }
        }
    }

    // if we found something, truncate path accordingly
    if (std::tie(beginSection, beginPoint) < std::tie(endSection, endPoint)) {
        // start cutting from the end, as otherwise the end indices become invalid!
        pathSections.erase(pathSections.begin() + endSection + 1, pathSections.end());
        pathSections.erase(pathSections.begin(), pathSections.begin() + beginSection);

        auto poly = pathSections.back().path();
        poly.erase(poly.begin() + endPoint + 1, poly.end());
        pathSections.back().setPath(poly);

        poly = pathSections.front().path();
        poly.erase(poly.begin(), poly.begin() + beginPoint);
        pathSections.front().setPath(poly);

        path.setSections(std::move(pathSections));
        partialTrip.setPath(path);
    }

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
