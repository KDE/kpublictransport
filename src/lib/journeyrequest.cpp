/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "journeyrequest.h"
#include "requestcontext_p.h"
#include "datatypes/datatypes_p.h"
#include "datatypes/json_p.h"
#include "datatypes/locationutil_p.h"

#include <KPublicTransport/Location>

#include <QDateTime>
#include <QDebug>
#include <QSharedData>

#include <unordered_map>

using namespace KPublicTransport;

enum { JourneyCacheTimeResolution = 60 }; // in seconds

namespace KPublicTransport {
class JourneyRequestPrivate : public QSharedData {
public:
    Location from;
    Location to;
    QDateTime dateTime;
    std::vector<RequestContext> contexts;
    QStringList backendIds;
    JourneyRequest::DateTimeMode dateTimeMode = JourneyRequest::Departure;
    JourneySection::Modes modes = JourneySection::PublicTransport | JourneySection::RentedVehicle;
    int maximumResults = 12;
    bool downloadAssets = false;
    bool includeIntermediateStops = true;
    bool includePaths = false;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(JourneyRequest)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneyRequest, Location, from, setFrom)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneyRequest, Location, to, setTo)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneyRequest, JourneyRequest::DateTimeMode, dateTimeMode, setDateTimeMode)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneyRequest, bool, downloadAssets, setDownloadAssets)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneyRequest, JourneySection::Modes, modes, setModes)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneyRequest, int, maximumResults, setMaximumResults)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneyRequest, bool, includeIntermediateStops, setIncludeIntermediateStops)
KPUBLICTRANSPORT_MAKE_PROPERTY(JourneyRequest, bool, includePaths, setIncludePaths)

JourneyRequest::JourneyRequest(const Location &from, const Location &to)
    : d(new JourneyRequestPrivate)
{
    d->from = from;
    d->to = to;
}

bool JourneyRequest::isValid() const
{
    return !d->to.isEmpty() && !d->from.isEmpty();
}

QDateTime JourneyRequest::dateTime() const
{
    if (!d->dateTime.isValid()) {
        d->dateTime = QDateTime::currentDateTime();
    }
    return d->dateTime;
}

void JourneyRequest::setDateTime(const QDateTime& dt)
{
    d.detach();
    d->dateTime = dt;
}

void JourneyRequest::setDepartureTime(const QDateTime &dt)
{
    d.detach();
    d->dateTime = dt;
    d->dateTimeMode = Departure;
}

void JourneyRequest::setArrivalTime(const QDateTime &dt)
{
    d.detach();
    d->dateTime = dt;
    d->dateTimeMode = Arrival;
}

RequestContext JourneyRequest::context(const AbstractBackend *backend) const
{
    const auto it = std::lower_bound(d->contexts.begin(), d->contexts.end(), backend);
    if (it != d->contexts.end() && (*it).backend == backend) {
        return *it;
    }

    RequestContext context;
    context.backend = backend;
    return context;
}

const std::vector<RequestContext>& JourneyRequest::contexts() const
{
    return d->contexts;
}

void JourneyRequest::setContext(const AbstractBackend *backend, RequestContext &&context)
{
    d.detach();
    const auto it = std::lower_bound(d->contexts.begin(), d->contexts.end(), backend);
    if (it != d->contexts.end() && (*it).backend == backend) {
        (*it) = std::move(context);
    } else {
        d->contexts.insert(it, std::move(context));
    }
}

void JourneyRequest::purgeLoops(const JourneyRequest &baseRequest)
{
    RequestContext::purgeLoops(d->contexts, baseRequest.contexts());
}

QJsonObject JourneyRequest::toJson(const KPublicTransport::JourneyRequest &req)
{
    auto obj = Json::toJson(req);
    obj.insert(QStringLiteral("from"), Location::toJson(req.from()));
    obj.insert(QStringLiteral("to"), Location::toJson(req.to()));
    return obj;
}

QStringList JourneyRequest::backendIds() const
{
    return d->backendIds;
}

void JourneyRequest::setBackendIds(const QStringList &backendIds)
{
    d.detach();
    d->backendIds = backendIds;
}

QString JourneyRequest::cacheKey() const
{
    return QString::number(d->dateTime.toSecsSinceEpoch() / JourneyCacheTimeResolution) + QLatin1Char('_')
        + LocationUtil::cacheKey(d->from) + QLatin1Char('_')
        + LocationUtil::cacheKey(d->to) + QLatin1Char('_')
        + (d->dateTimeMode == JourneyRequest::Arrival ? QLatin1Char('A') : QLatin1Char('D'));
}

#include "moc_journeyrequest.cpp"
