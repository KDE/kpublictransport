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

#include <QCryptographicHash>
#include <QDateTime>
#include <QMetaEnum>
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
    std::vector<Line::Mode> lineModes;
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

const std::vector<Line::Mode>& StopoverRequest::lineModes() const
{
    return d->lineModes;
}

void StopoverRequest::setLineModes(std::vector<Line::Mode> &&lineModes)
{
    d.detach();
    d->lineModes = std::move(lineModes);
    std::sort(d->lineModes.begin(), d->lineModes.end());
    d->lineModes.erase(std::unique(d->lineModes.begin(), d->lineModes.end()), d->lineModes.end());
}

QVariantList StopoverRequest::lineModesVariant() const
{
    QVariantList l;
    l.reserve(d->lineModes.size());
    std::transform(d->lineModes.begin(), d->lineModes.end(), std::back_inserter(l), [](const Line::Mode &value) {
        return QVariant::fromValue<Line::Mode>(value);
    });
    return l;
}

void StopoverRequest::setLineModesVariant(const QVariantList &lineModes)
{
    auto l = std::move(d->lineModes);
    l.clear();
    l.reserve(lineModes.size());
    std::transform(lineModes.begin(), lineModes.end(), std::back_inserter(l), [](const auto &mode) { return static_cast<Line::Mode>(mode.toInt()); });
    setLineModes(std::move(l));
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
    obj.insert(QLatin1String("stop"), Location::toJson(req.stop()));
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
    QCryptographicHash hash(QCryptographicHash::Sha1);
    hash.addData(QByteArray::number(d->dateTime.toSecsSinceEpoch() / DepartureCacheTimeResolution));
    hash.addData(LocationUtil::cacheKey(d->stop).toUtf8());
    hash.addData(d->mode == StopoverRequest::QueryArrival ? "A" : "D");

    hash.addData("MODES");
    for (const auto &mode : d->lineModes) {
        hash.addData(QMetaEnum::fromType<Line::Mode>().valueToKey(mode));
    }

    return QString::fromUtf8(hash.result().toHex());
}

#include "moc_stopoverrequest.cpp"
