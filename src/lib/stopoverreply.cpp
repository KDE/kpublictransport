/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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
    }

    // if this is a backend with a static timezone, apply this to the result
    if (backend->timeZone().isValid()) {
        for (auto &dep : res) {
            StopoverUtil::applyTimeZone(dep, backend->timeZone());
        }
    }

    // augment line information
    for (auto &dep : res) {
        StopoverUtil::applyMetaData(dep, request().downloadAssets());
    }

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
