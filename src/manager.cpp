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

#include "manager.h"
#include "departurereply.h"
#include "departurerequest.h"
#include "journeyreply.h"
#include "journeyrequest.h"
#include "requestcontext_p.h"
#include "locationreply.h"
#include "locationrequest.h"
#include "logging.h"
#include "datatypes/attributionutil_p.h"
#include "datatypes/backend.h"
#include "datatypes/disruption.h"

#include <KPublicTransport/Location>

#include "backends/cache.h"
#include "backends/efabackend.h"
#include "backends/hafasmgatebackend.h"
#include "backends/hafasquerybackend.h"
#include "backends/navitiabackend.h"

#include <QDirIterator>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMetaProperty>
#include <QNetworkAccessManager>
#include <QStandardPaths>
#include <QTimer>

#include <functional>

using namespace KPublicTransport;

enum {
    DefaultBackendState = true
};

static inline void initResources() {
    Q_INIT_RESOURCE(networks);
}

namespace KPublicTransport {
class ManagerPrivate {
public:
    QNetworkAccessManager* nam();
    void loadNetworks();
    std::unique_ptr<AbstractBackend> loadNetwork(const QJsonObject &obj);
    template <typename T> std::unique_ptr<AbstractBackend> loadNetwork(const QJsonObject &obj);

    template <typename RequestT> bool shouldSkipBackend(const AbstractBackend *backend, const RequestT &req) const;

    void resolveLocation(const LocationRequest &locReq, const AbstractBackend *backend, const std::function<void(const Location &loc)> &callback);
    bool queryJourney(const AbstractBackend *backend, const JourneyRequest &req, JourneyReply *reply);
    bool queryDeparture(const AbstractBackend *backend, const DepartureRequest &req, DepartureReply *reply);

    template <typename RepT, typename ReqT> RepT* makeReply(const ReqT &request);

    void readCachedAttributions();

    Manager *q = nullptr;
    QNetworkAccessManager *m_nam = nullptr;
    std::vector<std::unique_ptr<AbstractBackend>> m_backends;
    std::vector<Attribution> m_attributions;
    std::vector<Backend> m_backendMetaData;

    // we store both explicitly to have a third state, backends with the enabled state being the "default" (whatever that might eventually be)
    QStringList m_enabledBackends;
    QStringList m_disabledBackends;

    bool m_allowInsecure = false;
    bool m_hasReadCachedAttributions = false;

private:
    bool shouldSkipBackend(const AbstractBackend *backend) const;
};
}

QNetworkAccessManager* ManagerPrivate::nam()
{
    if (!m_nam) {
        m_nam = new QNetworkAccessManager(q);
        m_nam->setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);
        m_nam->setStrictTransportSecurityEnabled(true);
        m_nam->enableStrictTransportSecurityStore(true, QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.kpublictransport/hsts/"));
    }
    return m_nam;
}

static QString translatedValue(const QJsonObject &obj, const QString &key)
{
    auto languageWithCountry = QLocale().name();
    auto it = obj.constFind(key + QLatin1Char('[') + languageWithCountry + QLatin1Char(']'));
    if (it != obj.constEnd()) {
        return it.value().toString();
    }
    const auto language = languageWithCountry.midRef(0, languageWithCountry.indexOf(QLatin1Char('_')));
    it = obj.constFind(key + QLatin1Char('[') + language + QLatin1Char(']'));
    if (it != obj.constEnd()) {
        return it.value().toString();
    }
    return obj.value(key).toString();
}


void ManagerPrivate::loadNetworks()
{
    QDirIterator it(QStringLiteral(":/org.kde.pim/kpublictransport/networks"));
    while (it.hasNext()) {
        QFile f(it.next());
        if (!f.open(QFile::ReadOnly)) {
            qCWarning(Log) << "Failed to open public transport network configuration:" << f.errorString();
            continue;
        }

        QJsonParseError error;
        const auto doc = QJsonDocument::fromJson(f.readAll(), &error);
        if (error.error != QJsonParseError::NoError) {
            qCWarning(Log) << "Failed to parse public transport network configuration:" << error.errorString() << it.fileName();
            continue;
        }

        auto net = loadNetwork(doc.object());
        if (net) {
            net->setBackendId(it.fileInfo().baseName());
            net->init();
            if (!net->attribution().isEmpty()) {
                m_attributions.push_back(net->attribution());
            }

            Backend metaData;
            metaData.setIdentifier(net->backendId());
            const auto jsonMetaData = doc.object().value(QLatin1String("KPlugin")).toObject();
            metaData.setName(translatedValue(jsonMetaData, QStringLiteral("Name")));
            metaData.setDescription(translatedValue(jsonMetaData, QStringLiteral("Description")));
            metaData.setIsSecure(net->capabilities() & AbstractBackend::Secure);

            m_backendMetaData.push_back(std::move(metaData));
            m_backends.push_back(std::move(net));
        } else {
            qCWarning(Log) << "Failed to load public transport network configuration config:" << it.fileName();
        }
    }

    AttributionUtil::sort(m_attributions);
    qCDebug(Log) << m_backends.size() << "public transport network configurations loaded";
}

std::unique_ptr<AbstractBackend> ManagerPrivate::loadNetwork(const QJsonObject &obj)
{
    const auto type = obj.value(QLatin1String("type")).toString();
    if (type == QLatin1String("navitia")) {
        return loadNetwork<NavitiaBackend>(obj);
    }
    if (type == QLatin1String("hafas_mgate")) {
        return loadNetwork<HafasMgateBackend>(obj);
    }
    if (type == QLatin1String("hafas_query")) {
        return loadNetwork<HafasQueryBackend>(obj);
    }
    if (type == QLatin1String("efa")) {
        return loadNetwork<EfaBackend>(obj);
    }

    qCWarning(Log) << "Unknown backend type:" << type;
    return {};
}

static void applyBackendOptions(AbstractBackend *backend, const QMetaObject *mo, const QJsonObject &obj)
{
    const auto opts = obj.value(QLatin1String("options")).toObject();
    for (auto it = opts.begin(); it != opts.end(); ++it) {
        const auto idx = mo->indexOfProperty(it.key().toUtf8().constData());
        if (idx < 0) {
            qCWarning(Log) << "Unknown backend setting:" << it.key();
            continue;
        }
        const auto mp = mo->property(idx);
        if (it.value().isObject()) {
            mp.writeOnGadget(backend, it.value().toObject());
        } else if (it.value().isArray()) {
            mp.writeOnGadget(backend, it.value().toArray());
        } else {
            mp.writeOnGadget(backend, it.value().toVariant());
        }
    }

    const auto filter = obj.value(QLatin1String("filter")).toObject();
    const auto geoFilter = filter.value(QLatin1String("geo")).toArray();
    if (!geoFilter.isEmpty()) {
        QPolygonF poly;
        poly.reserve(geoFilter.size());
        for (const auto &coordV : geoFilter) {
            const auto coordA = coordV.toArray();
            poly.push_back({coordA[0].toDouble(), coordA[1].toDouble()});
        }
        backend->setGeoFilter(poly);
    }

    const auto attrObj = obj.value(QLatin1String("attribution")).toObject();
    const auto attr = Attribution::fromJson(attrObj);
    backend->setAttribution(attr);
}

template<typename T> std::unique_ptr<AbstractBackend> ManagerPrivate::loadNetwork(const QJsonObject &obj)
{
    std::unique_ptr<AbstractBackend> backend(new T);
    applyBackendOptions(backend.get(), &T::staticMetaObject, obj);
    return backend;
}

bool ManagerPrivate::shouldSkipBackend(const AbstractBackend *backend) const
{
    if (!backend->hasCapability(AbstractBackend::Secure) && !m_allowInsecure) {
        qCDebug(Log) << "Skipping insecure backend:" << backend->backendId();
        return true;
    }
    return !q->isBackendEnabled(backend->backendId());
}

template <typename RequestT>
bool ManagerPrivate::shouldSkipBackend(const AbstractBackend *backend, const RequestT &req) const
{
    if (!req.backendIds().isEmpty() && !req.backendIds().contains(backend->backendId())) {
        qCDebug(Log) << "Skipping backend" << backend->backendId() << "due to explicit request";
        return true;
    }
    return shouldSkipBackend(backend);
}

// IMPORTANT callback must not be called directly, but only via queued invocation,
// our callers rely on that to not mess up sync/async response handling
void ManagerPrivate::resolveLocation(const LocationRequest &locReq, const AbstractBackend *backend, const std::function<void(const Location&)> &callback)
{
    // check if this location query is cached already
    const auto cacheEntry = Cache::lookupLocation(backend->backendId(), locReq.cacheKey());
    switch (cacheEntry.type) {
        case CacheHitType::Negative:
            QTimer::singleShot(0, q, [callback]() { callback({}); });
            return;
        case CacheHitType::Positive:
            if (!cacheEntry.data.empty()) {
                const auto loc = cacheEntry.data[0];
                QTimer::singleShot(0, q, [callback, loc]() { callback(loc); });
                return;
            }
            break;
        case CacheHitType::Miss:
            break;
    }

    // actually do the location query
    auto locReply = new LocationReply(locReq, q);
    if (backend->queryLocation(locReq, locReply, nam())) {
        locReply->setPendingOps(1);
    } else {
        locReply->setPendingOps(0);
    }
    QObject::connect(locReply, &Reply::finished, q, [callback, locReply]() {
        locReply->deleteLater();
        if (locReply->result().empty()) {
            callback({});
        } else {
            callback(locReply->result()[0]);
        }
    });
}

bool ManagerPrivate::queryJourney(const AbstractBackend* backend, const JourneyRequest &req, JourneyReply *reply)
{
    if (shouldSkipBackend(backend, req)) {
        return false;
    }
    if (backend->isLocationExcluded(req.from()) && backend->isLocationExcluded(req.to())) {
        qCDebug(Log) << "Skipping backend based on location filter:" << backend->backendId();
        return false;
    }
    reply->addAttribution(backend->attribution());

    // resolve locations if needed
    if (backend->needsLocationQuery(req.from(), AbstractBackend::QueryType::Journey)) {
        LocationRequest fromReq;
        fromReq.setCoordinate(req.from().latitude(), req.from().longitude());
        fromReq.setName(req.from().name());
        resolveLocation(fromReq, backend, [reply, backend, req, this](const Location &loc) {
            auto jnyRequest = req;
            const auto fromLoc = Location::merge(jnyRequest.from(), loc);
            jnyRequest.setFrom(fromLoc);

            if (backend->needsLocationQuery(jnyRequest.to(), AbstractBackend::QueryType::Journey)) {
                LocationRequest toReq;
                toReq.setCoordinate(jnyRequest.to().latitude(), jnyRequest.to().longitude());
                toReq.setName(jnyRequest.to().name());
                resolveLocation(toReq, backend, [jnyRequest, reply, backend, this](const Location &loc) {
                    auto jnyReq = jnyRequest;
                    const auto toLoc = Location::merge(jnyRequest.to(), loc);
                    jnyReq.setTo(toLoc);
                    if (!backend->queryJourney(jnyReq, reply, nam())) {
                        reply->addError(Reply::NotFoundError, {});
                    }
                });

                return;
            }

            if (!backend->queryJourney(jnyRequest, reply, nam())) {
                reply->addError(Reply::NotFoundError, {});
            }
        });

        return true;
    }

    if (backend->needsLocationQuery(req.to(), AbstractBackend::QueryType::Journey)) {
        LocationRequest toReq;
        toReq.setCoordinate(req.to().latitude(), req.to().longitude());
        toReq.setName(req.to().name());
        resolveLocation(toReq, backend, [req, toReq, reply, backend, this](const Location &loc) {
            const auto toLoc = Location::merge(req.to(), loc);
            auto jnyRequest = req;
            jnyRequest.setTo(toLoc);
            if (!backend->queryJourney(jnyRequest, reply, nam())) {
                reply->addError(Reply::NotFoundError, {});
            }
        });
        return true;
    }

    return backend->queryJourney(req, reply, nam());
}

bool ManagerPrivate::queryDeparture(const AbstractBackend *backend, const DepartureRequest &req, DepartureReply *reply)
{
    if (shouldSkipBackend(backend, req)) {
        return false;
    }
    if (backend->isLocationExcluded(req.stop())) {
        qCDebug(Log) << "Skipping backend based on location filter:" << backend->backendId();
        return false;
    }
    reply->addAttribution(backend->attribution());

    // check if we first need to resolve the location first
    if (backend->needsLocationQuery(req.stop(), AbstractBackend::QueryType::Departure)) {
        qCDebug(Log) << "Backend needs location query first:" << backend->backendId();
        LocationRequest locReq;
        locReq.setCoordinate(req.stop().latitude(), req.stop().longitude());
        locReq.setName(req.stop().name());
        resolveLocation(locReq, backend, [reply, req, backend, this](const Location &loc) {
            const auto depLoc = Location::merge(req.stop(), loc);
            auto depRequest = req;
            depRequest.setStop(depLoc);
            if (!backend->queryDeparture(depRequest, reply, nam())) {
                reply->addError(Reply::NotFoundError, {});
            }
        });
        return true;
    }

    return backend->queryDeparture(req, reply, nam());
}

void ManagerPrivate::readCachedAttributions()
{
    if (m_hasReadCachedAttributions) {
        return;
    }

    Cache::allCachedAttributions(m_attributions);
    m_hasReadCachedAttributions = true;
}

template<typename RepT, typename ReqT>
RepT* ManagerPrivate::makeReply(const ReqT &request)
{
    auto reply = new RepT(request, q);
    QObject::connect(reply, &Reply::finished, q, [this, reply]() {
        AttributionUtil::merge(m_attributions, reply->attributions());
    });
    return reply;
}



Manager::Manager(QObject *parent)
    : QObject(parent)
    , d(new ManagerPrivate)
{
    initResources();
    qRegisterMetaType<Disruption::Effect>();
    d->q = this;
    d->loadNetworks();

    Cache::expire();
}

Manager::~Manager() = default;

void Manager::setNetworkAccessManager(QNetworkAccessManager *nam)
{
    if (d->m_nam == nam) {
        return;
    }

    if (d->m_nam->parent() == this) {
        delete d->m_nam;
    }

    d->m_nam = nam;
}

bool Manager::allowInsecureBackends() const
{
    return d->m_allowInsecure;
}

void Manager::setAllowInsecureBackends(bool insecure)
{
    if (d->m_allowInsecure == insecure) {
        return;
    }
    d->m_allowInsecure = insecure;
    emit configurationChanged();
}

JourneyReply* Manager::queryJourney(const JourneyRequest &req) const
{
    auto reply = d->makeReply<JourneyReply>(req);
    int pendingOps = 0;

    // first time/direct query
    if (req.contexts().empty()) {
        for (const auto &backend : d->m_backends) {
            if (d->queryJourney(backend.get(), req, reply)) {
                ++pendingOps;
            }
        }

    // subsequent earlier/later query
    } else {
        for (const auto &context : req.contexts()) {
            // backend supports this itself
            if ((context.type == RequestContext::Next && context.backend->hasCapability(AbstractBackend::CanQueryNextJourney))
              ||(context.type == RequestContext::Previous && context.backend->hasCapability(AbstractBackend::CanQueryPreviousJourney)))
            {
                if (d->queryJourney(context.backend, req, reply)) {
                    ++pendingOps;
                    continue;
                }
            }

            // backend doesn't support this, let's try to emulate
            if (context.type == RequestContext::Next && req.dateTimeMode() == JourneyRequest::Departure) {
                auto r = req;
                r.setDepartureTime(context.dateTime);
                if (d->queryJourney(context.backend, r, reply)) {
                    ++pendingOps;
                    continue;
                }
            } else if (context.type == RequestContext::Previous && req.dateTimeMode() == JourneyRequest::Departure) {
                auto r = req;
                r.setArrivalTime(context.dateTime);
                if (d->queryJourney(context.backend, r, reply)) {
                    ++pendingOps;
                    continue;
                }
            }
        }
    }

    reply->setPendingOps(pendingOps);
    return reply;
}

DepartureReply* Manager::queryDeparture(const DepartureRequest &req) const
{
    auto reply = d->makeReply<DepartureReply>(req);
    int pendingOps = 0;

    // first time/direct query
    if (req.contexts().empty()) {
        for (const auto &backend : d->m_backends) {
            if (d->queryDeparture(backend.get(), req, reply)) {
                ++pendingOps;
            }
        }

    // subsequent earlier/later query
    } else {
        for (const auto &context : req.contexts()) {
            // backend supports this itself
            if ((context.type == RequestContext::Next && context.backend->hasCapability(AbstractBackend::CanQueryNextDeparture))
              ||(context.type == RequestContext::Previous && context.backend->hasCapability(AbstractBackend::CanQueryPreviousDeparture)))
            {
                if (d->queryDeparture(context.backend, req, reply)) {
                    ++pendingOps;
                    continue;
                }
            }

            // backend doesn't support this, let's try to emulate
            if (context.type == RequestContext::Next && req.mode() == DepartureRequest::QueryDeparture) {
                auto r = req;
                r.setDateTime(context.dateTime);
                if (d->queryDeparture(context.backend, r, reply)) {
                    ++pendingOps;
                    continue;
                }
            }
        }
    }

    reply->setPendingOps(pendingOps);
    return reply;
}

LocationReply* Manager::queryLocation(const LocationRequest &req) const
{
    auto reply = d->makeReply<LocationReply>(req);
    int pendingOps = 0;
    for (const auto &backend : d->m_backends) {
        if (d->shouldSkipBackend(backend.get(), req)) {
            continue;
        }
        if (req.hasCoordinate() && backend->isCoordinateExcluded(req.latitude(), req.longitude())) {
            qCDebug(Log) << "Skipping backend based on location filter:" << backend->backendId();
            continue;
        }
        reply->addAttribution(backend->attribution());

        auto cache = Cache::lookupLocation(backend->backendId(), req.cacheKey());
        switch (cache.type) {
            case CacheHitType::Negative:
                qCDebug(Log) << "Negative cache hit for backend" << backend->backendId();
                break;
            case CacheHitType::Positive:
                qCDebug(Log) << "Positive cache hit for backend" << backend->backendId();
                reply->addAttributions(std::move(cache.attributions));
                reply->addResult(std::move(cache.data));
                break;
            case CacheHitType::Miss:
                qCDebug(Log) << "Cache miss for backend" << backend->backendId();
                if (backend->queryLocation(req, reply, d->nam())) {
                    ++pendingOps;
                }
                break;
        }
    }
    reply->setPendingOps(pendingOps);
    return reply;
}

const std::vector<Attribution>& Manager::attributions() const
{
    d->readCachedAttributions();
    return d->m_attributions;
}

QVariantList Manager::attributionsVariant() const
{
    d->readCachedAttributions();
    QVariantList l;
    l.reserve(d->m_attributions.size());
    std::transform(d->m_attributions.begin(), d->m_attributions.end(), std::back_inserter(l), [](const auto &attr) { return QVariant::fromValue(attr); });
    return l;
}

const std::vector<Backend>& Manager::backends() const
{
    return d->m_backendMetaData;
}

bool Manager::isBackendEnabled(const QString &backendId) const
{
    if (std::binary_search(d->m_disabledBackends.cbegin(), d->m_disabledBackends.cend(), backendId)) {
        return false;
    }
    if (std::binary_search(d->m_enabledBackends.cbegin(), d->m_enabledBackends.cend(), backendId)) {
        return true;
    }

    return DefaultBackendState;
}

static void sortedInsert(QStringList &l, const QString &value)
{
    const auto it = std::lower_bound(l.begin(), l.end(), value);
    if (it == l.end() || (*it) != value) {
        l.insert(it, value);
    }
}

static void sortedRemove(QStringList &l, const QString &value)
{
    const auto it = std::lower_bound(l.begin(), l.end(), value);
    if (it != l.end() && (*it) == value) {
        l.erase(it);
    }
}

void Manager::setBackendEnabled(const QString &backendId, bool enabled)
{
    if (enabled) {
        sortedInsert(d->m_enabledBackends, backendId);
        sortedRemove(d->m_disabledBackends, backendId);
    } else {
        sortedRemove(d->m_enabledBackends, backendId);
        sortedInsert(d->m_disabledBackends, backendId);
    }
    emit configurationChanged();
}

QStringList Manager::enabledBackends() const
{
    return d->m_enabledBackends;
}

void Manager::setEnabledBackends(const QStringList &backendIds)
{
    QSignalBlocker blocker(this); // no change signals during settings restore
    for (const auto &backendId : backendIds) {
        setBackendEnabled(backendId, true);
    }
}

QStringList Manager::disabledBackends() const
{
    return d->m_disabledBackends;
}

void Manager::setDisabledBackends(const QStringList &backendIds)
{
    QSignalBlocker blocker(this); // no change signals during settings restore
    for (const auto &backendId : backendIds) {
        setBackendEnabled(backendId, false);
    }
}
