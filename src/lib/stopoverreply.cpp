/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "stopoverreply.h"
#include "logging.h"
#include "reply_p.h"
#include "requestcontext_p.h"
#include "stopoverrequest.h"
#include "backends/abstractbackend.h"
#include "backends/cache.h"
#include "datatypes/stopoverutil_p.h"

#include <KPublicTransport/Stopover>

#include <QNetworkReply>

using namespace KPublicTransport;

namespace KPublicTransport {
class StopoverReplyPrivate : public ReplyPrivate {
public:
    void finalizeResult() override;
    bool needToWaitForAssets() const override;

    StopoverRequest request;
    StopoverRequest nextRequest;
    StopoverRequest prevRequest;
    std::vector<Stopover> result;
};
}

void StopoverReplyPrivate::finalizeResult()
{
    if (result.empty()) {
        return;
    }
    error = Reply::NoError;
    errorMsg.clear();

    std::sort(result.begin(), result.end(), [this](const auto &lhs, const auto &rhs) {
            return StopoverUtil::timeLessThan(request, lhs, rhs);
    });

    for (auto it = result.begin(); it != result.end(); ++it) {
        for (auto mergeIt = it + 1; mergeIt != result.end();) {
            if (!StopoverUtil::timeEqual(request, (*it), (*mergeIt))) {
                break;
            }

            if (Stopover::isSame(*it, *mergeIt)) {
                *it = Stopover::merge(*it, *mergeIt);
                mergeIt = result.erase(mergeIt);
            } else {
                ++mergeIt;
            }
        }
    }

    nextRequest.purgeLoops(request);
    prevRequest.purgeLoops(request);
}

bool StopoverReplyPrivate::needToWaitForAssets() const
{
    return request.downloadAssets();
}

StopoverReply::StopoverReply(const StopoverRequest &req, QObject *parent)
    : Reply(new StopoverReplyPrivate, parent)
{
    Q_D(StopoverReply);
    d->request = req;
    d->nextRequest = req;
    d->prevRequest = req;
}

StopoverReply::~StopoverReply() = default;

StopoverRequest StopoverReply::request() const
{
    Q_D(const StopoverReply);
    return d->request;
}

const std::vector<Stopover>& StopoverReply::result() const
{
    Q_D(const StopoverReply);
    return d->result;
}

std::vector<Stopover>&& StopoverReply::takeResult()
{
    Q_D(StopoverReply);
    return std::move(d->result);
}

void StopoverReply::addResult(const AbstractBackend *backend, std::vector<Stopover> &&res)
{
    Q_D(StopoverReply);
    // update context for next/prev requests
    // do this first, before res gets moved from below
    if (d->request.mode() == StopoverRequest::QueryDeparture && !res.empty()) {
        // we create a context for later queries here in any case, since we can emulate that generically without backend support
        auto context = d->nextRequest.context(backend);
        context.type = RequestContext::Next;
        for (const auto &dep : res) {
            context.dateTime = std::max(context.dateTime, dep.scheduledDepartureTime());
        }
        d->nextRequest.setContext(backend, std::move(context));

        if (backend->hasCapability(AbstractBackend::CanQueryPreviousDeparture)) {
            context = d->prevRequest.context(backend);
            context.type = RequestContext::Previous;
            context.dateTime = res[0].scheduledDepartureTime();
            for (const auto &jny : res) {
                context.dateTime = std::min(context.dateTime, jny.scheduledDepartureTime());
            }
            d->prevRequest.setContext(backend, std::move(context));
        }
    } else if (d->request.mode() == StopoverRequest::QueryArrival && !res.empty()) {
        // CanQueryArrivals is assumed here, otherwise this request would not have been possible already
        auto context = d->nextRequest.context(backend);
        context.type = RequestContext::Next;
        for (const auto &dep : res) {
            context.dateTime = std::max(context.dateTime, dep.scheduledArrivalTime());
        }
        d->nextRequest.setContext(backend, std::move(context));

        if (backend->hasCapability(AbstractBackend::CanQueryPreviousDeparture)) {
            context = d->prevRequest.context(backend);
            context.type = RequestContext::Previous;
            context.dateTime = res[0].scheduledArrivalTime();
            for (const auto &jny : res) {
                context.dateTime = std::min(context.dateTime, jny.scheduledArrivalTime());
            }
            d->prevRequest.setContext(backend, std::move(context));
        }
    }

    // if this is a backend with a static timezone, apply this to the result
    if (backend->timeZone().isValid()) {
        for (auto &dep : res) {
            StopoverUtil::applyTimeZone(dep, backend->timeZone());
        }
    }

    // augment line information
    for (auto &dep : res) {
        dep.applyMetaData(request().downloadAssets());
    }

    // apply static attributions if @p backend contributed to the results
    addAttribution(backend->attribution());

    // cache negative hits, positive ones are too short-lived
    if (res.empty()) {
        Cache::addNegativeDepartureCacheEntry(backend->backendId(), request().cacheKey());
    }

    if (d->result.empty()) {
        d->result = std::move(res);
    } else {
        d->result.insert(d->result.end(), res.begin(), res.end());
    }

    d->pendingOps--;
    d->emitUpdated(this);
    d->emitFinishedIfDone(this);
}

StopoverRequest StopoverReply::nextRequest() const
{
    Q_D(const StopoverReply);
    if (d->nextRequest.contexts().empty()) {
        return {};
    }
    return d->nextRequest;
}

StopoverRequest StopoverReply::previousRequest() const
{
    Q_D(const StopoverReply);
    if (d->prevRequest.contexts().empty()) {
        return {};
    }
    return d->prevRequest;
}

void StopoverReply::setNextContext(const AbstractBackend *backend, const QVariant &data)
{
    Q_D(StopoverReply);
    auto context = d->nextRequest.context(backend);
    context.type = RequestContext::Next;
    context.backendData = data;
    d->nextRequest.setContext(backend, std::move(context));
}

void StopoverReply::setPreviousContext(const AbstractBackend *backend, const QVariant &data)
{
    Q_D(StopoverReply);
    auto context = d->prevRequest.context(backend);
    context.type = RequestContext::Previous;
    context.backendData = data;
    d->prevRequest.setContext(backend, std::move(context));
}

void StopoverReply::addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg)
{
    if (error == Reply::NotFoundError) {
        Cache::addNegativeDepartureCacheEntry(backend->backendId(), request().cacheKey());
    } else {
        qCDebug(Log) << backend->backendId() << error << errorMsg;
    }
    Reply::addError(error, errorMsg);
}
