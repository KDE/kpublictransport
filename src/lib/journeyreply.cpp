/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "journeyreply.h"
#include "reply_p.h"
#include "journeyrequest.h"
#include "requestcontext_p.h"
#include "logging.h"
#include "backends/abstractbackend.h"
#include "backends/cache.h"
#include "datatypes/journeyutil_p.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>

#include <QDateTime>
#include <QTimeZone>

using namespace KPublicTransport;

namespace KPublicTransport {
class JourneyReplyPrivate : public ReplyPrivate {
public:
    void finalizeResult() override;
    bool needToWaitForAssets() const override;
    static void postProcessJourneys(std::vector<Journey> &journeys);

    JourneyRequest request;
    JourneyRequest nextRequest;
    JourneyRequest prevRequest;
    std::vector<Journey> journeys;
};
}

void JourneyReplyPrivate::finalizeResult()
{
    if (journeys.empty()) {
        return;
    }

    error = Reply::NoError;
    errorMsg.clear();

    // merge results, aligned by first transport departure
    std::sort(journeys.begin(), journeys.end(), JourneyUtil::firstTransportDepartureLessThan);
    for (auto it = journeys.begin(); it != journeys.end(); ++it) {
        for (auto mergeIt = it + 1; mergeIt != journeys.end();) {
            if (!JourneyUtil::firstTransportDepartureEqual(*it, *mergeIt)) {
                break;
            }

            if (Journey::isSame(*it, *mergeIt)) {
                *it = Journey::merge(*it, *mergeIt);
                mergeIt = journeys.erase(mergeIt);
            } else {
                ++mergeIt;
            }
        }
    }

    // sort by departure time for display
    std::sort(journeys.begin(), journeys.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.scheduledDepartureTime() < rhs.scheduledDepartureTime();
    });

    nextRequest.purgeLoops(request);
    prevRequest.purgeLoops(request);
}

bool JourneyReplyPrivate::needToWaitForAssets() const
{
    return request.downloadAssets();
}

static bool isPointlessSection(const JourneySection &section)
{
    if (section.mode() == JourneySection::Waiting) {
        return section.duration() < 60;
    }
    if (section.mode() == JourneySection::Walking) {
        return section.duration() < 60 && section.path().isEmpty();
    }
    return false;
}

static bool isImplausibleSection(const JourneySection &section)
{
    if ((section.mode() == JourneySection::Transfer || section.mode() == JourneySection::Walking)
        && section.from().hasCoordinate() && section.to().hasCoordinate())
    {
        const auto distance = Location::distance(section.from(), section.to());
        if (section.duration() > 0 && (distance / section.duration()) > 30) {
            qCDebug(Log) << "discarding journey based on insane transfer/walking speed:" << (distance / section.duration()) << "m/s";
            return true;
        }
        if (distance > 100000) {
            qCDebug(Log) << "discarding journey with insane transfer/walking distance:" << distance << "m" << section.from().name() << section.to().name();
            return true;
        }
    }
    return false;
}

void JourneyReplyPrivate::postProcessJourneys(std::vector<Journey> &journeys)
{
    // try to fill gaps in timezone data
    for (auto &journey : journeys) {
        auto sections = journey.takeSections();
        for (auto &section : sections) {
            if (section.mode() == JourneySection::Walking) {
                if (!section.from().timeZone().isValid() && section.to().timeZone().isValid()) {
                    auto from = section.from();
                    from.setTimeZone(section.to().timeZone());
                    section.setFrom(from);
                    auto dt = section.scheduledDepartureTime();
                    dt.setTimeZone(from.timeZone());
                    section.setScheduledDepartureTime(dt);
                }
                if (section.from().timeZone().isValid() && !section.to().timeZone().isValid()) {
                    auto to = section.to();
                    to.setTimeZone(section.from().timeZone());
                    section.setTo(to);
                    auto dt = section.scheduledArrivalTime();
                    dt.setTimeZone(to.timeZone());
                    section.setScheduledArrivalTime(dt);
                }
            }
        }
        journey.setSections(std::move(sections));
    }

    // clean up non-transport sections
    for (auto &journey : journeys) {
        auto sections = journey.takeSections();

        // merge adjacent walking sections (yes, we do get that from backends...)
        for (auto it = sections.begin(); it != sections.end();) {
            if (it == sections.begin()) {
                ++it;
                continue;
            }
            auto prevIt = it - 1;
            if ((*it).mode() == JourneySection::Walking && (*prevIt).mode() == JourneySection::Walking) {
                (*prevIt).setTo((*it).to());
                (*prevIt).setScheduledArrivalTime((*it).scheduledArrivalTime());
                (*prevIt).setExpectedArrivalTime((*it).expectedArrivalTime());
                (*prevIt).setDistance((*prevIt).distance() + (*it).distance());
                it = sections.erase(it);
                continue;
            }

            ++it;
        }

        // remove pointless sections such as 0-length walks
        sections.erase(std::remove_if(sections.begin(), sections.end(), isPointlessSection), sections.end());

        // remove implausible paths
        for (auto &section : sections) {
            if (!section.from().hasCoordinate() || !section.to().hasCoordinate() || section.path().isEmpty()) {
                continue;
            }

            const auto pointDist = Location::distance(section.from(), section.to());
            const auto pathDist = section.path().distance();
            if (pathDist > pointDist * 10) {
                qCDebug(Log) << "Dropping implausibly long path:" << pointDist << pathDist;
                section.setPath({});
            }
        }

        journey.setSections(std::move(sections));
    }

    // remove empty or implausible journeys
    journeys.erase(std::remove_if(journeys.begin(), journeys.end(), [](const auto &journey) {
        return journey.sections().empty() || std::any_of(journey.sections().begin(), journey.sections().end(), isImplausibleSection);
    }), journeys.end());
}

JourneyReply::JourneyReply(const JourneyRequest &req, QObject *parent)
    : Reply(new JourneyReplyPrivate, parent)
{
    Q_D(JourneyReply);
    d->request = req;
    d->nextRequest = req;
    d->prevRequest = req;
}

JourneyReply::~JourneyReply() = default;

JourneyRequest JourneyReply::request() const
{
    Q_D(const JourneyReply);
    return d->request;
}

const std::vector<Journey>& JourneyReply::result() const
{
    Q_D(const JourneyReply);
    return d->journeys;
}

std::vector<Journey>&& JourneyReply::takeResult()
{
    Q_D(JourneyReply);
    return std::move(d->journeys);
}

JourneyRequest JourneyReply::nextRequest() const
{
    Q_D(const JourneyReply);
    if (d->nextRequest.contexts().empty()) {
        return {};
    }
    return d->nextRequest;
}

JourneyRequest JourneyReply::previousRequest() const
{
    Q_D(const JourneyReply);
    if (d->prevRequest.contexts().empty()) {
        return {};
    }
    return d->prevRequest;
}

void JourneyReply::addResult(const AbstractBackend *backend, std::vector<Journey> &&res)
{
    Q_D(JourneyReply);
    d->postProcessJourneys(res);

    // update context for next/prev requests
    // do this first, before res gets moved from below
    if (d->request.dateTimeMode() == JourneyRequest::Departure && !res.empty()) {
        // we create a context for later queries here in any case, since we can emulate that generically without backend support
        auto context = d->nextRequest.context(backend);
        context.type = RequestContext::Next;
        for (const auto &jny : res) {
            context.dateTime = std::max(context.dateTime, jny.scheduledDepartureTime());
        }
        d->nextRequest.setContext(backend, std::move(context));

        context = d->prevRequest.context(backend);
        context.type = RequestContext::Previous;
        context.dateTime = res[0].scheduledArrivalTime(); // "invalid" is the minimum...
        for (const auto &jny : res) {
            context.dateTime = std::min(context.dateTime, jny.scheduledArrivalTime());
        }
        d->prevRequest.setContext(backend, std::move(context));
    }

    // if this is a backend with a static timezone, apply this to the result
    if (backend->timeZone().isValid()) {
        for (auto &jny : res) {
            JourneyUtil::applyTimeZone(jny, backend->timeZone());
        }
    }

    // apply line meta data
    for (auto &jny : res) {
        jny.applyMetaData(request().downloadAssets());
    }

    // cache negative hits, positive ones are too short-lived
    if (res.empty()) {
        Cache::addNegativeDepartureCacheEntry(backend->backendId(), request().cacheKey());
    }

    // apply static attributions if @p backend contributed to the results
    addAttribution(backend->attribution());

    // update result
    if (!res.empty()) {
        if (d->journeys.empty()) {
            d->journeys = std::move(res);
        } else {
            d->journeys.insert(d->journeys.end(), res.begin(), res.end());
        }
        d->emitUpdated(this);
    }

    d->pendingOps--;
    d->emitFinishedIfDone(this);
}

void JourneyReply::setNextContext(const AbstractBackend *backend, const QVariant &data)
{
    Q_D(JourneyReply);
    auto context = d->nextRequest.context(backend);
    context.type = RequestContext::Next;
    context.backendData = data;
    d->nextRequest.setContext(backend, std::move(context));
}

void JourneyReply::setPreviousContext(const AbstractBackend *backend, const QVariant &data)
{
    Q_D(JourneyReply);
    auto context = d->prevRequest.context(backend);
    context.type = RequestContext::Previous;
    context.backendData = data;
    d->prevRequest.setContext(backend, std::move(context));
}

void JourneyReply::addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg)
{
    if (error == Reply::NotFoundError) {
        Cache::addNegativeJourneyCacheEntry(backend->backendId(), request().cacheKey());
    } else {
        qCDebug(Log) << backend->backendId() << error << errorMsg;
    }
    Reply::addError(error, errorMsg);
}
