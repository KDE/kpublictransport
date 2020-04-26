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

#include "stopoverrequest.h"
#include "requestcontext_p.h"
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
};
}

StopoverRequest::StopoverRequest()
    : d(new StopoverRequestPrivate)
{
}

StopoverRequest::StopoverRequest(const Location &stop)
    : d(new StopoverRequestPrivate)
{
    d->stop = stop;
}

StopoverRequest::StopoverRequest(StopoverRequest&&) noexcept = default;
StopoverRequest::StopoverRequest(const StopoverRequest&) = default;
StopoverRequest::~StopoverRequest() = default;
StopoverRequest& StopoverRequest::operator=(const StopoverRequest&) = default;

bool StopoverRequest::isValid() const
{
    return !d->stop.isEmpty();
}

Location StopoverRequest::stop() const
{
    return d->stop;
}

void StopoverRequest::setStop(const Location &stop)
{
    d.detach();
    d->stop = stop;
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

StopoverRequest::Mode StopoverRequest::mode() const
{
    return d->mode;
}

void StopoverRequest::setMode(StopoverRequest::Mode mode)
{
    d.detach();
    d->mode = mode;
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

bool StopoverRequest::downloadAssets() const
{
    return d->downloadAssets;
}

void StopoverRequest::setDownloadAssets(bool downloadAssets)
{
    d.detach();
    d->downloadAssets = downloadAssets;
}

QString StopoverRequest::cacheKey() const
{
    return QString::number(d->dateTime.toSecsSinceEpoch() / DepartureCacheTimeResolution) + QLatin1Char('_')
        + LocationUtil::cacheKey(d->stop)
        + QLatin1Char('_') + (d->mode == StopoverRequest::QueryArrival ? QLatin1Char('A') : QLatin1Char('D'));
}

#include "moc_stopoverrequest.cpp"
