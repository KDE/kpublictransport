/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "stopoverrequest.h"
#include "requestcontext_p.h"
#include "datatypes/datatypes_p.h"
#include "datatypes/json_p.h"
#include "datatypes/locationutil_p.h"

#include <KPublicTransport/Location>

#include <QDateTime>
#include <QSharedData>

using namespace KPublicTransport;

enum { DepartureCacheTimeResolution = 60 }; // in seconds

namespace KPublicTransport {
class StopoverRequestPrivate : public QSharedData {
public:
    Location stop;
    QDateTime dateTime;
    StopoverRequest::Mode mode = StopoverRequest::QueryDeparture;
    std::vector<RequestContext> contexts;
    QStringList backendIds;
    bool downloadAssets = false;
    int maximumResults = 12;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(StopoverRequest)
KPUBLICTRANSPORT_MAKE_PROPERTY(StopoverRequest, Location, stop, setStop)
KPUBLICTRANSPORT_MAKE_PROPERTY(StopoverRequest, StopoverRequest::Mode, mode, setMode)
KPUBLICTRANSPORT_MAKE_PROPERTY(StopoverRequest, bool, downloadAssets, setDownloadAssets)
KPUBLICTRANSPORT_MAKE_PROPERTY(StopoverRequest, int, maximumResults, setMaximumResults)

StopoverRequest::StopoverRequest(const Location &stop)
    : d(new StopoverRequestPrivate)
{
    d->stop = stop;
}

bool StopoverRequest::isValid() const
{
    return !d->stop.isEmpty();
}

QDateTime StopoverRequest::dateTime() const
{
    if (!d->dateTime.isValid()) {
        d->dateTime = QDateTime::currentDateTime();
    }
    return d->dateTime;
}

void StopoverRequest::setDateTime(const QDateTime &dt)
{
    d.detach();
    d->dateTime = dt;
}

RequestContext StopoverRequest::context(const AbstractBackend *backend) const
{
    const auto it = std::lower_bound(d->contexts.begin(), d->contexts.end(), backend);
    if (it != d->contexts.end() && (*it).backend == backend) {
        return *it;
    }

    RequestContext context;
    context.backend = backend;
    return context;
}

const std::vector<RequestContext>& StopoverRequest::contexts() const
{
    return d->contexts;
}

void StopoverRequest::setContext(const AbstractBackend *backend, RequestContext &&context)
{
    d.detach();
    const auto it = std::lower_bound(d->contexts.begin(), d->contexts.end(), backend);
    if (it != d->contexts.end() && (*it).backend == backend) {
        (*it) = std::move(context);
    } else {
        d->contexts.insert(it, std::move(context));
    }
}

void StopoverRequest::purgeLoops(const StopoverRequest &baseRequest)
{
    RequestContext::purgeLoops(d->contexts, baseRequest.contexts());
}

QJsonObject StopoverRequest::toJson(const StopoverRequest &req)
{
    auto obj = Json::toJson(req);
    obj.insert(QStringLiteral("stop"), Location::toJson(req.stop()));
    return obj;
}

QStringList StopoverRequest::backendIds() const
{
    return d->backendIds;
}

void StopoverRequest::setBackendIds(const QStringList &backendIds)
{
    d.detach();
    d->backendIds = backendIds;
}

QString StopoverRequest::cacheKey() const
{
    return QString::number(d->dateTime.toSecsSinceEpoch() / DepartureCacheTimeResolution) + QLatin1Char('_')
        + LocationUtil::cacheKey(d->stop)
        + QLatin1Char('_') + (d->mode == StopoverRequest::QueryArrival ? QLatin1Char('A') : QLatin1Char('D'));
}

#include "moc_stopoverrequest.cpp"
