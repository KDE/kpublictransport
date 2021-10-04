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

#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>
#include <QMetaEnum>
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

    std::vector<IndividualTransport> accessModes = { {IndividualTransport::Walk} };
    std::vector<IndividualTransport> egressModes = { {IndividualTransport::Walk} };
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
    obj.insert(QLatin1String("from"), Location::toJson(req.from()));
    obj.insert(QLatin1String("to"), Location::toJson(req.to()));
    obj.insert(QLatin1String("accessModes"), IndividualTransport::toJson(req.accessModes()));
    obj.insert(QLatin1String("egressModes"), IndividualTransport::toJson(req.egressModes()));
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

template <typename T>
static QVariantList toVariantList(const std::vector<T> &v)
{
    QVariantList l;
    l.reserve(v.size());
    std::transform(v.begin(), v.end(), std::back_inserter(l), &QVariant::fromValue<T>);
    return l;
}

const std::vector<IndividualTransport>& JourneyRequest::accessModes() const
{
    return d->accessModes;
}

QVariantList JourneyRequest::accessModesVariant() const
{
    return toVariantList(d->accessModes);
}

void JourneyRequest::setAccessModes(std::vector<IndividualTransport> &&accessModes)
{
    d.detach();
    d->accessModes = std::move(accessModes);
}

void JourneyRequest::setAccessModes(const QVariantList &accessModesVariant)
{
    d.detach();
    d->accessModes = IndividualTransport::fromVariant(accessModesVariant);
}

const std::vector<IndividualTransport>& JourneyRequest::egressModes() const
{
    return d->egressModes;
}

QVariantList JourneyRequest::egressModesVariant() const
{
    return toVariantList(d->egressModes);
}

void JourneyRequest::setEgressModes(std::vector<IndividualTransport>&& egressModes)
{
    d.detach();
    d->egressModes = std::move(egressModes);
}

void JourneyRequest::setEgressModes(const QVariantList &egressModesVariant)
{
    d.detach();
    d->egressModes = IndividualTransport::fromVariant(egressModesVariant);
}

QString JourneyRequest::cacheKey() const
{
    QCryptographicHash hash(QCryptographicHash::Sha1);
    hash.addData(QByteArray::number(d->dateTime.toSecsSinceEpoch() / JourneyCacheTimeResolution));
    hash.addData(LocationUtil::cacheKey(d->from).toUtf8());
    hash.addData(LocationUtil::cacheKey(d->to).toUtf8());
    hash.addData(d->dateTimeMode == JourneyRequest::Arrival ? "A" : "D", 1);
    hash.addData(QMetaEnum::fromType<JourneySection::Mode>().valueToKeys(d->modes));
    hash.addData(QByteArray::number(d->maximumResults));
    hash.addData(d->includeIntermediateStops ? "I" : "-");
    hash.addData(d->includePaths ? "P" : "-");

    hash.addData("ACCESS");
    for (const auto &it : d->accessModes) {
        hash.addData(QMetaEnum::fromType<IndividualTransport::Mode>().valueToKey(it.mode()));
        hash.addData(QMetaEnum::fromType<IndividualTransport::Qualifier>().valueToKey(it.qualifier()));
    }

    hash.addData("EGRESS");
    for (const auto &it : d->accessModes) {
        hash.addData(QMetaEnum::fromType<IndividualTransport::Mode>().valueToKey(it.mode()));
        hash.addData(QMetaEnum::fromType<IndividualTransport::Qualifier>().valueToKey(it.qualifier()));
    }

    return QString::fromUtf8(hash.result().toHex());
}

#include "moc_journeyrequest.cpp"
