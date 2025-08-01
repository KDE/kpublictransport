/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "manager.h"
#include "assetrepository_p.h"
#include "backends/srbijavozbackend.h"
#include "journeyreply.h"
#include "journeyrequest.h"
#include "requestcontext_p.h"
#include "locationreply.h"
#include "locationrequest.h"
#include "logging.h"
#include "standardpaths_p.h"
#include "stopoverreply.h"
#include "stopoverrequest.h"
#include "tripreply.h"
#include "triprequest.h"
#include "vehiclelayoutrequest.h"
#include "vehiclelayoutreply.h"
#include "datatypes/attributionutil_p.h"
#include "datatypes/backend.h"
#include "datatypes/backend_p.h"
#include "datatypes/disruption.h"
#include "datatypes/json_p.h"
#include "geo/geojson_p.h"
#include "update/updatejob_p.h"
#include "update/updatestate_p.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include "backends/accessibilitycloudbackend.h"
#include "backends/cache.h"
#include "backends/deutschebahnbackend.h"
#include "backends/efabackend.h"
#include "backends/hafasmgatebackend.h"
#include "backends/hafasquerybackend.h"
#include "backends/ivvassbackend.h"
#include "backends/motis2backend.h"
#include "backends/navitiabackend.h"
#include "backends/oebbbackend.h"
#include "backends/openjourneyplannerbackend.h"
#include "backends/opentripplannergraphqlbackend.h"
#include "backends/opentripplannerrestbackend.h"
#include "backends/ltglinkbackend.h"
#include "gbfs/gbfsbackend.h"

#include <QCoreApplication>
#include <QDirIterator>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMetaProperty>
#include <QNetworkAccessManager>
#include <QStandardPaths>
#include <QTimer>
#include <QTimeZone>

#include <functional>
#include <unordered_set>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

static inline void initResources() {
    Q_INIT_RESOURCE(asset_attributions);
    Q_INIT_RESOURCE(gbfs);
    Q_INIT_RESOURCE(geometry);
    Q_INIT_RESOURCE(images);
    Q_INIT_RESOURCE(networks);
    Q_INIT_RESOURCE(network_certs);
    Q_INIT_RESOURCE(otp);
    Q_INIT_RESOURCE(stations);
}

namespace KPublicTransport {
class ManagerPrivate {
public:
    [[nodiscard]] QNetworkAccessManager* nam();
    void loadNetworks();
    [[nodiscard]] std::unique_ptr<AbstractBackend> loadNetwork(const QJsonObject &obj);
    template <typename Backend, typename Backend2, typename ...Backends>
    [[nodiscard]] static std::unique_ptr<AbstractBackend> loadNetwork(const QJsonObject &backendType, const QJsonObject &obj);
    template <typename Backend>
    [[nodiscard]] static std::unique_ptr<AbstractBackend> loadNetwork(const QJsonObject &backendType, const QJsonObject &obj);
    template <typename T>
    [[nodiscard]] static std::unique_ptr<AbstractBackend> loadNetwork(const QJsonObject &obj);

    template <typename RequestT>
    [[nodiscard]] bool shouldSkipBackend(const Backend &backend, const RequestT &req) const;

    void resolveLocation(LocationRequest &&locReq, const AbstractBackend *backend, const std::function<void(const Location &loc)> &callback);
    [[nodiscard]] bool queryJourney(const AbstractBackend *backend, const JourneyRequest &req, JourneyReply *reply);
    [[nodiscard]] bool queryStopover(const AbstractBackend *backend, const StopoverRequest &req, StopoverReply *reply);

    template <typename RepT, typename ReqT>
    [[nodiscard]] RepT* makeReply(const ReqT &request);

    void readCachedAttributions();

    [[nodiscard]] int queryLocationOnBackend(const LocationRequest &req, LocationReply *reply, const Backend &backend);

    Manager *q = nullptr;
    QNetworkAccessManager *m_nam = nullptr;
    std::vector<Backend> m_backends;
    std::vector<Attribution> m_attributions;

    // backends that are configured to be off by default, regardless of m_backendsEnabledByDefault
    QStringList m_disabledByDefault;
    // we store both explicitly to have a third state, backends with the enabled state being the "default" (whatever that might eventually be)
    QStringList m_enabledBackends;
    QStringList m_disabledBackends;

    bool m_allowInsecure = false;
    bool m_hasReadCachedAttributions = false;
    bool m_backendsEnabledByDefault = true;

    UpdateResult::Type m_updateResult = UpdateResult::NoError;

private:
    [[nodiscard]] bool shouldSkipBackend(const Backend &backend) const;
};
}

QNetworkAccessManager* ManagerPrivate::nam()
{
    if (!m_nam) {
        m_nam = new QNetworkAccessManager(q);
        m_nam->setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);
        m_nam->setStrictTransportSecurityEnabled(true);
        m_nam->enableStrictTransportSecurityStore(true, QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + "/org.kde.kpublictransport/hsts/"_L1);
    }
    return m_nam;
}


void ManagerPrivate::loadNetworks()
{
    if (!m_backends.empty()) {
        return;
    }

    const auto searchDirs = StandardPaths::dataSearchPaths();
    std::vector<Attribution> attributions;
    std::unordered_set<QString> loadedBackends;
    for (const auto &searchDir : searchDirs) {
        QDirIterator it(searchDir + "/networks"_L1, {u"*.json"_s}, QDir::Files);
        while (it.hasNext()) {
            it.next();
            const auto id = it.fileInfo().baseName();
            if (loadedBackends.contains(id)) {
                // already loaded from an earlier location
                continue;
            }

            QFile f(it.filePath());
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
            const auto obj = doc.object();

            if (!obj.value("active"_L1).toBool(true)) {
                // disabled in configuration, also skip all later instances of this then!
                qCDebug(Log) << "Not loading deactivated backend:" << it.fileName();
                loadedBackends.insert(id);
                continue;
            }

            auto net = loadNetwork(obj);
            if (net) {
                net->setBackendId(id);
                net->init();
                if (!net->attribution().isEmpty()) {
                    attributions.push_back(net->attribution());
                }

                auto b = BackendPrivate::fromJson(doc.object());
                BackendPrivate::setImpl(b, std::move(net));
                m_backends.push_back(std::move(b));
                loadedBackends.insert(id);
                if (!obj.value("enabled"_L1).toBool(true)) {
                    m_disabledByDefault.push_back(id);
                }
            } else {
                qCWarning(Log) << "Failed to load public transport network configuration config:" << it.fileName();
            }
        }
    }

    std::ranges::stable_sort(m_backends, [](const auto &lhs, const auto &rhs) {
        return lhs.identifier() < rhs.identifier();
    });
    std::ranges::sort(m_disabledByDefault);

    AttributionUtil::sort(attributions);
    if (m_attributions.empty()) {
        // first load
        m_attributions = std::move(attributions);
    } else {
        // reload
        AttributionUtil::merge(m_attributions, attributions);
    }

    qCDebug(Log) << m_backends.size() << "public transport network configurations loaded";
}

std::unique_ptr<AbstractBackend> ManagerPrivate::loadNetwork(const QJsonObject &obj)
{
    const auto type = obj.value("type"_L1).toObject();
    // backends need to be topologically sorted according to their preference/priority here
    return loadNetwork<
        NavitiaBackend,
        OpenTripPlannerGraphQLBackend,
        OpenTripPlannerRestBackend,
        DeutscheBahnBackend,
        OebbBackend,
        HafasMgateBackend,
        HafasQueryBackend,
        EfaBackend,
        IvvAssBackend,
        OpenJourneyPlannerBackend,
        Motis2Backend,
        GBFSBackend,
        AccessibilityCloudBackend,
        LTGLinkBackend,
        SrbijavozBackend
    >(type, obj);
}

template <typename Backend, typename Backend2, typename ...Backends>
std::unique_ptr<AbstractBackend> ManagerPrivate::loadNetwork(const QJsonObject &backendType, const QJsonObject &obj)
{
    if (backendType.value(QLatin1String(Backend::type())).toBool()) {
        return loadNetwork<Backend>(obj);
    }
    return loadNetwork<Backend2, Backends...>(backendType, obj);
}

template <typename Backend>
std::unique_ptr<AbstractBackend> ManagerPrivate::loadNetwork(const QJsonObject &backendType, const QJsonObject &obj)
{
    if (backendType.value(QLatin1String(Backend::type())).toBool()) {
        return ManagerPrivate::loadNetwork<Backend>(obj);
    }
    qCWarning(Log) << "Unknown backend type:" << backendType;
    return {};
}

static void applyBackendOptions(AbstractBackend *backend, const QMetaObject *mo, const QJsonObject &obj)
{
    const auto opts = obj.value("options"_L1).toObject();
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
            const auto a = it.value().toArray();
            if (mp.userType() == QMetaType::QStringList) {
                QStringList l;
                l.reserve(a.size());
                std::transform(a.begin(), a.end(), std::back_inserter(l), [](const auto &v) { return v.toString(); });
                mp.writeOnGadget(backend, l);
            } else {
                mp.writeOnGadget(backend, it.value().toArray());
            }
        } else {
            mp.writeOnGadget(backend, it.value().toVariant());
        }
    }

    const auto attrObj = obj.value("attribution"_L1).toObject();
    const auto attr = Attribution::fromJson(attrObj);
    backend->setAttribution(attr);

    const auto tzId = obj.value("timezone"_L1).toString();
    if (!tzId.isEmpty()) {
        QTimeZone tz(tzId.toUtf8());
        if (tz.isValid()) {
            backend->setTimeZone(tz);
        } else {
            qCWarning(Log) << "Invalid timezone:" << tzId;
        }
    }

    const auto langArray = obj.value("supportedLanguages"_L1).toArray();
    QStringList langs;
    langs.reserve(langArray.size());
    std::transform(langArray.begin(), langArray.end(), std::back_inserter(langs), [](const auto &v) { return v.toString(); });
    backend->setSupportedLanguages(langs);
}

template<typename T> std::unique_ptr<AbstractBackend> ManagerPrivate::loadNetwork(const QJsonObject &obj)
{
    std::unique_ptr<AbstractBackend> backend(new T);
    applyBackendOptions(backend.get(), &T::staticMetaObject, obj);
    return backend;
}

bool ManagerPrivate::shouldSkipBackend(const Backend &backend) const
{
    if (!backend.isSecure() && !m_allowInsecure) {
        qCDebug(Log) << "Skipping insecure backend:" << backend.identifier();
        return true;
    }
    return !q->isBackendEnabled(backend.identifier());
}

template <typename RequestT>
bool ManagerPrivate::shouldSkipBackend(const Backend &backend, const RequestT &req) const
{
    if (!req.backendIds().isEmpty() && !req.backendIds().contains(backend.identifier())) {
        //qCDebug(Log) << "Skipping backend" << backend.identifier() << "due to explicit request";
        return true;
    }
    return shouldSkipBackend(backend);
}

// IMPORTANT callback must not be called directly, but only via queued invocation,
// our callers rely on that to not mess up sync/async response handling
void ManagerPrivate::resolveLocation(LocationRequest &&locReq, const AbstractBackend *backend, const std::function<void(const Location&)> &callback)
{
    // apply all changes to locReq *before* we call cacheKey() on it!
    locReq.setMaximumResults(1);

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
    if ((backend->supportedLocationTypes() & locReq.types()) && backend->queryLocation(locReq, locReply, nam())) {
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

static Location::Types locationTypesForJourneyRequest(const JourneyRequest &req)
{
    Location::Types t = Location::Place;
    if (req.modes() & JourneySection::PublicTransport) {
        t |= Location::Stop;
    }
    if (req.modes() & JourneySection::RentedVehicle) {
        t |= Location::RentedVehicleStation;
    }
    return t;
}

bool ManagerPrivate::queryJourney(const AbstractBackend* backend, const JourneyRequest &req, JourneyReply *reply)
{
    auto cache = Cache::lookupJourney(backend->backendId(), req.cacheKey());
    switch (cache.type) {
        case CacheHitType::Negative:
            qCDebug(Log) << "Negative cache hit for backend" << backend->backendId();
            return false;
        case CacheHitType::Positive:
            qCDebug(Log) << "Positive cache hit for backend" << backend->backendId();
            reply->addAttributions(std::move(cache.attributions));
            reply->addResult(backend, std::move(cache.data));
            return false;
        case CacheHitType::Miss:
            qCDebug(Log) << "Cache miss for backend" << backend->backendId();
            break;
    }

    // resolve locations if needed
    if (backend->needsLocationQuery(req.from(), AbstractBackend::QueryType::Journey)) {
        LocationRequest fromReq(req.from());
        fromReq.setTypes(locationTypesForJourneyRequest(req));
        resolveLocation(std::move(fromReq), backend, [reply, backend, req, this](const Location &loc) {
            auto jnyRequest = req;
            const auto fromLoc = Location::merge(jnyRequest.from(), loc);
            jnyRequest.setFrom(fromLoc);

            if (backend->needsLocationQuery(jnyRequest.to(), AbstractBackend::QueryType::Journey)) {
                LocationRequest toReq(jnyRequest.to());
                toReq.setTypes(locationTypesForJourneyRequest(req));
                resolveLocation(std::move(toReq), backend, [jnyRequest, reply, backend, this](const Location &loc) {
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
        LocationRequest toReq(req.to());
        toReq.setTypes(locationTypesForJourneyRequest(req));
        resolveLocation(std::move(toReq), backend, [req, toReq, reply, backend, this](const Location &loc) {
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

bool ManagerPrivate::queryStopover(const AbstractBackend *backend, const StopoverRequest &req, StopoverReply *reply)
{
    auto cache = Cache::lookupStopover(backend->backendId(), req.cacheKey());
    switch (cache.type) {
        case CacheHitType::Negative:
            qCDebug(Log) << "Negative cache hit for backend" << backend->backendId();
            return false;
        case CacheHitType::Positive:
            qCDebug(Log) << "Positive cache hit for backend" << backend->backendId();
            reply->addAttributions(std::move(cache.attributions));
            reply->addResult(backend, std::move(cache.data));
            return false;
        case CacheHitType::Miss:
            qCDebug(Log) << "Cache miss for backend" << backend->backendId();
            break;
    }

    // check if we first need to resolve the location first
    if (backend->needsLocationQuery(req.stop(), AbstractBackend::QueryType::Departure)) {
        qCDebug(Log) << "Backend needs location query first:" << backend->backendId();
        LocationRequest locReq(req.stop());
        locReq.setTypes(Location::Stop); // Stopover can never refer to other location types
        locReq.setMaximumDistance(250);
        resolveLocation(std::move(locReq), backend, [reply, req, backend, this](const Location &loc) {
            const auto depLoc = Location::merge(req.stop(), loc);
            auto depRequest = req;
            depRequest.setStop(depLoc);
            if (!backend->queryStopover(depRequest, reply, nam())) {
                reply->addError(Reply::NotFoundError, {});
            }
        });
        return true;
    }

    return backend->queryStopover(req, reply, nam());
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

    if (!AssetRepository::instance()) {
        auto assetRepo = new AssetRepository(this);
        assetRepo->setNetworkAccessManagerProvider(std::bind(&ManagerPrivate::nam, d.get()));
    }

    Cache::expire();
    UpdateState::purgeObsoleteFiles();
    d->m_updateResult = UpdateState::isEnabled() ? UpdateResult::NoError : UpdateResult::UpdatesDisabled;

    QCoreApplication::instance()->installEventFilter(this);
}

Manager::~Manager() = default;

void Manager::setNetworkAccessManager(QNetworkAccessManager *nam)
{
    if (d->m_nam == nam) {
        return;
    }

    if (d->m_nam && d->m_nam->parent() == this) {
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
    Q_EMIT configurationChanged();
}

JourneyReply* Manager::queryJourney(const JourneyRequest &req) const
{
    auto reply = d->makeReply<JourneyReply>(req);
    int pendingOps = 0;

    // validate input
    req.validate();
    if (!req.isValid()) {
        reply->addError(Reply::InvalidRequest, {});
        reply->setPendingOps(pendingOps);
        return reply;
    }

    d->loadNetworks();

    // first time/direct query
    if (req.contexts().empty()) {
        QSet<QString> triedBackends;
        bool foundSymmetricNonGlobalCoverage = false;
        for (const auto coverageType : { CoverageArea::Realtime, CoverageArea::Regular, CoverageArea::Any }) {
            const auto checkBackend = [&](const Backend &backend, bool bothLocationMatch) {
                if (triedBackends.contains(backend.identifier()) || d->shouldSkipBackend(backend, req)) {
                    return;
                }
                const auto coverage = backend.coverageArea(coverageType);
                if (coverage.isEmpty()) {
                    return;
                }

                if (bothLocationMatch) {
                    if (!backend.coversLocation(req.from(), coverageType) || !backend.coversLocation(req.to(), coverageType)) {
                        return;
                    }
                } else {
                    if (!backend.coversLocation(req.from(), coverageType) && !backend.coversLocation(req.to(), coverageType)) {
                        return;
                    }
                }

                triedBackends.insert(backend.identifier());
                foundSymmetricNonGlobalCoverage |= !coverage.isGlobal() && bothLocationMatch;

                if (d->queryJourney(BackendPrivate::impl(backend), req, reply)) {
                    ++pendingOps;
                }
            };

            // look for coverage areas which contain both locations first
            for (const auto &backend: d->m_backends) {
                checkBackend(backend, true);
            }
            if (pendingOps && foundSymmetricNonGlobalCoverage) {
                break;
            }

            // if we didn't find one, try with just a single one
            for (const auto &backend: d->m_backends) {
                checkBackend(backend, false);
            }
            if (pendingOps && foundSymmetricNonGlobalCoverage) {
                break;
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

    if (req.downloadAssets()) {
        reply->addAttributions(AssetRepository::instance()->attributions());
    }

    // FIXME this is not correct for negative cache hits!
    //if (pendingOps == 0) {
    //    reply->addError(Reply::NoBackend, u"No viable backend found."_s);
    //}
    reply->setPendingOps(pendingOps);
    return reply;
}

StopoverReply* Manager::queryStopover(const StopoverRequest &req) const
{
    auto reply = d->makeReply<StopoverReply>(req);
    int pendingOps = 0;

    // validate input
    if (!req.isValid()) {
        reply->addError(Reply::InvalidRequest, {});
        reply->setPendingOps(pendingOps);
        return reply;
    }

    d->loadNetworks();

    // first time/direct query
    if (req.contexts().empty()) {
        QSet<QString> triedBackends;
        bool foundNonGlobalCoverage = false;
        for (const auto coverageType : { CoverageArea::Realtime, CoverageArea::Regular, CoverageArea::Any }) {
            for (const auto &backend: d->m_backends) {
                if (triedBackends.contains(backend.identifier()) || d->shouldSkipBackend(backend, req)) {
                    continue;
                }
                if (req.mode() == StopoverRequest::QueryArrival && (BackendPrivate::impl(backend)->capabilities() & AbstractBackend::CanQueryArrivals) == 0) {
                    qCDebug(Log) << "Skipping backend due to not supporting arrival queries:" << backend.identifier();
                    continue;
                }
                const auto coverage = backend.coverageArea(coverageType);
                if (coverage.isEmpty() || !coverage.coversLocation(req.stop())) {
                    continue;
                }
                triedBackends.insert(backend.identifier());
                foundNonGlobalCoverage |= !coverage.isGlobal();

                if (d->queryStopover(BackendPrivate::impl(backend), req, reply)) {
                    ++pendingOps;
                }
            }

            if (pendingOps && foundNonGlobalCoverage) {
                break;
            }
        }

    // subsequent earlier/later query
    } else {
        for (const auto &context : req.contexts()) {
            // backend supports this itself
            if ((context.type == RequestContext::Next && context.backend->hasCapability(AbstractBackend::CanQueryNextDeparture))
              ||(context.type == RequestContext::Previous && context.backend->hasCapability(AbstractBackend::CanQueryPreviousDeparture)))
            {
                if (d->queryStopover(context.backend, req, reply)) {
                    ++pendingOps;
                    continue;
                }
            }

            // backend doesn't support this, let's try to emulate
            if (context.type == RequestContext::Next) {
                auto r = req;
                r.setDateTime(context.dateTime);
                if (d->queryStopover(context.backend, r, reply)) {
                    ++pendingOps;
                    continue;
                }
            }
        }
    }

    if (req.downloadAssets()) {
        reply->addAttributions(AssetRepository::instance()->attributions());
    }

    // FIXME this is not correct for negative cache hits!
    //if (pendingOps == 0) {
    //    reply->addError(Reply::NoBackend, u"No viable backend found."_s);
    //}
    reply->setPendingOps(pendingOps);
    return reply;
}

int ManagerPrivate::queryLocationOnBackend(const LocationRequest &req, LocationReply *reply, const Backend &backend)
{
    auto cache = Cache::lookupLocation(backend.identifier(), req.cacheKey());
    switch (cache.type) {
        case CacheHitType::Negative:
            qCDebug(Log) << "Negative cache hit for backend" << backend.identifier();
            break;
        case CacheHitType::Positive:
            qCDebug(Log) << "Positive cache hit for backend" << backend.identifier();
            reply->addAttributions(std::move(cache.attributions));
            reply->addResult(std::move(cache.data));
            break;
        case CacheHitType::Miss:
            qCDebug(Log) << "Cache miss for backend" << backend.identifier();
            reply->addAttribution(BackendPrivate::impl(backend)->attribution());
            if (BackendPrivate::impl(backend)->queryLocation(req, reply, nam())) {
                return 1;
            }
            break;
    }

    return 0;
}

LocationReply* Manager::queryLocation(const LocationRequest &req) const
{
    auto reply = d->makeReply<LocationReply>(req);
    int pendingOps = 0;

    // validate input
    if (!req.isValid()) {
        reply->addError(Reply::InvalidRequest, {});
        reply->setPendingOps(pendingOps);
        return reply;
    }

    d->loadNetworks();

    QSet<QString> triedBackends;
    const auto loc = req.location();
    Location::Types queriedTypes = {};

    // try first to find a country-wide coverage at any level for country-limited name-based searches
    if (!loc.hasCoordinate() && !loc.country().isEmpty() && loc.region().isEmpty()) {
        for (const auto coverageType : { CoverageArea::Realtime, CoverageArea::Regular, CoverageArea::Any }) {
            for (const auto &backend : d->m_backends) {
                if (triedBackends.contains(backend.identifier()) || d->shouldSkipBackend(backend, req)) {
                    continue;
                }
                const auto backendTypes = BackendPrivate::impl(backend)->supportedLocationTypes() & req.types();
                if (backendTypes == 0) {
                    continue;
                }
                const auto coverage = backend.coverageArea(coverageType);
                if (coverage.isEmpty() || !coverage.hasNationWideCoverage(loc.country()) || !coverage.coversLocation(loc) || !coverage.coversArea(req.viewbox())) {
                    continue;
                }

                triedBackends.insert(backend.identifier());
                queriedTypes |= backendTypes;
                pendingOps += d->queryLocationOnBackend(req, reply, backend);
            }
            if (pendingOps && queriedTypes == req.types()) {
                break;
            }
        }
    }

    // search for highest-quality coverage match otherwise
    for (const auto coverageType : { CoverageArea::Realtime, CoverageArea::Regular, CoverageArea::Any }) {
        if (pendingOps && queriedTypes == req.types()) {
            break;
        }
        for (const auto &backend : d->m_backends) {
            if (triedBackends.contains(backend.identifier()) || d->shouldSkipBackend(backend, req)) {
                continue;
            }
            const auto backendTypes = BackendPrivate::impl(backend)->supportedLocationTypes() & req.types();
            if (backendTypes == 0) {
                continue;
            }
            const auto coverage = backend.coverageArea(coverageType);
            if (coverage.isEmpty() || !coverage.coversLocation(loc) || !coverage.coversArea(req.viewbox())) {
                continue;
            }

            triedBackends.insert(backend.identifier());
            queriedTypes |= backendTypes;
            pendingOps += d->queryLocationOnBackend(req, reply, backend);
        }
    }

    // FIXME this is not correct for negative cache hits!
    //if (pendingOps == 0) {
    //    reply->addError(Reply::NoBackend, u"No viable backend found."_s);
    //}
    reply->setPendingOps(pendingOps);
    return reply;
}

// Check whether a given JourneySection matches a trip request in fallback journey query mode
// This is essentially the same as JourneySection::isSame, with a few special cases:
// * accepting all specialized modes for an requested generic mode. Line::isSame takes care of most of this
//   on its own already, we just need to handle all rail-based modes explicitly here.
// * being more tolerant towards moved departure times if the route is assumed to be unique during a day
[[nodiscard]] static bool isSameTrip(KPublicTransport::JourneySection req, const KPublicTransport::JourneySection &res)
{
    if (req.route().line().mode() == Line::Train && Line::modeIsRailBound(res.route().line().mode())) {
        auto route = req.route();
        auto line = route.line();
        line.setMode(res.route().line().mode());
        route.setLine(line);
        req.setRoute(route);
    }
    if (Route::isSame(req.route(), res.route()) && res.route().line().mode() == Line::Mode::LongDistanceTrain) {
        const auto depDelta = std::abs(req.scheduledDepartureTime().secsTo(res.scheduledDepartureTime()));
        if (depDelta < 30l * 60) {
            req.setScheduledDepartureTime(res.scheduledDepartureTime());
        }
    }
    return JourneySection::isSame(req, res);
}

TripReply* Manager::queryTrip(const TripRequest &req) const
{
    auto reply = d->makeReply<TripReply>(req);
    int pendingOps = 0;

    // validate input
    if (!req.isValid()) {
        reply->addError(Reply::InvalidRequest, {});
        reply->setPendingOps(pendingOps);
        return reply;
    }

    d->loadNetworks();

    // no need for coverage-based checks here, queryTrip() is identifier-based
    // we only need coverage-based backend selection for the journey query fallback,
    // but queryJourney as called below does that for us
    if (req.hasIdentifiers()) {
        for (const auto &backend : d->m_backends) {
            if (d->shouldSkipBackend(backend, req)) {
                continue;
            }
            if (BackendPrivate::impl(backend)->queryTrip(req, reply, d->nam())) {
                ++pendingOps;
            }
        }
    }

    // emulate a trip query via a journey query
    if (pendingOps == 0 && req.journeySection().mode() != JourneySection::Invalid) {
        JourneyRequest jnyReq(req.journeySection().from(), req.journeySection().to());
        // start searching slightly earlier, so leading walking section because our coordinates
        // aren't exactly at the right spot wont make the routing service consider the train we
        // are looking for as impossible to reach on time
        jnyReq.setDateTime(req.journeySection().scheduledDepartureTime().addSecs(-600));
        jnyReq.setDateTimeMode(JourneyRequest::Departure);
        jnyReq.setIncludeIntermediateStops(true);
        jnyReq.setIncludePaths(true);
        jnyReq.setModes(JourneySection::PublicTransport);
        jnyReq.setBackendIds(req.backendIds());
        auto jnyReply = queryJourney(jnyReq);
        jnyReply->setParent(reply);
        connect(jnyReply, &Reply::finished, reply, [jnyReply, reply]() {
            jnyReply->deleteLater();
            if (jnyReply->error() != Reply::NoError) {
                reply->addError(jnyReply->error(), jnyReply->errorString());
                return;
            }
            for (const auto &journey : jnyReply->result()) {
                if (std::ranges::count_if(journey.sections(), [](const auto &sec) { return sec.mode() == JourneySection::PublicTransport; }) != 1) {
                    continue;
                }
                const auto it = std::ranges::find_if(journey.sections(), [](const auto &sec) {
                    return sec.mode() == JourneySection::PublicTransport;
                });
                assert(it != journey.sections().end());
                qCDebug(Log) << "Got journey information:" << (*it).route().line().name() << (*it).scheduledDepartureTime();
                if (isSameTrip(reply->request().journeySection(), *it)) {
                    qCDebug(Log) << "Found journey information:" << (*it).route().line().name() << (*it).expectedDeparturePlatform() << (*it).expectedDepartureTime();
                    reply->addAttributions(jnyReply->attributions());
                    reply->addResult(nullptr, JourneySection(*it));
                    return;
                }
            }

            reply->addError(Reply::NotFoundError, u"Not found."_s);
        });

        reply->setPendingOps(1);
    } else {
        reply->setPendingOps(pendingOps);
    }

    return reply;
}

VehicleLayoutReply* Manager::queryVehicleLayout(const VehicleLayoutRequest &req) const
{
    auto reply = d->makeReply<VehicleLayoutReply>(req);
    int pendingOps = 0;
    int cacheHit = 0;

    // validate input
    if (!req.isValid()) {
        reply->addError(Reply::InvalidRequest, {});
        reply->setPendingOps(pendingOps);
        return reply;
    }

    d->loadNetworks();

    for (const auto coverageType : { CoverageArea::Realtime, CoverageArea::Regular }) {
        for (const auto &backend : d->m_backends) {
            if (d->shouldSkipBackend(backend, req)) {
                continue;
            }
            const auto coverage = backend.coverageArea(coverageType);
            if (coverage.isEmpty() || !coverage.coversLocation(req.stopover().stopPoint())) {
                continue;
            }
            reply->addAttribution(BackendPrivate::impl(backend)->attribution());

            auto cache = Cache::lookupVehicleLayout(backend.identifier(), req.cacheKey());
            switch (cache.type) {
                case CacheHitType::Negative:
                    ++cacheHit;
                    qCDebug(Log) << "Negative cache hit for backend" << backend.identifier();
                    break;
                case CacheHitType::Positive:
                    ++cacheHit;
                    qCDebug(Log) << "Positive cache hit for backend" << backend.identifier();
                    if (cache.data.size() == 1) {
                        reply->addAttributions(std::move(cache.attributions));
                        reply->addResult(cache.data[0]);
                        break;
                    }
                    [[fallthrough]];
                case CacheHitType::Miss:
                    qCDebug(Log) << "Cache miss for backend" << backend.identifier();
                    if (BackendPrivate::impl(backend)->queryVehicleLayout(req, reply, d->nam())) {
                        ++pendingOps;
                    }
                    break;
            }
        }
        if (pendingOps) {
            break;
        }
    }

    if (pendingOps == 0 && cacheHit == 0) {
        reply->addError(Reply::NoBackend, u"No viable backend found."_s);
    }
    reply->setPendingOps(pendingOps);
    return reply;
}

void Manager::reload()
{
    if (d->m_backends.empty()) { // not loaded yet, nothing to do
        return;
    }
    d->m_backends.clear();
    d->loadNetworks();
    Q_EMIT backendsChanged();
}

const std::vector<Attribution>& Manager::attributions() const
{
    d->loadNetworks();
    d->readCachedAttributions();
    return d->m_attributions;
}

QVariantList Manager::attributionsVariant() const
{
    d->loadNetworks();
    d->readCachedAttributions();
    QVariantList l;
    l.reserve(d->m_attributions.size());
    std::transform(d->m_attributions.begin(), d->m_attributions.end(), std::back_inserter(l), [](const auto &attr) { return QVariant::fromValue(attr); });
    return l;
}

const std::vector<Backend>& Manager::backends() const
{
    d->loadNetworks();
    return d->m_backends;
}

bool Manager::isBackendEnabled(const QString &backendId) const
{
    d->loadNetworks();

    // ### should be std::ranges::binary_search, but that produces wrong results with Android NDK r26...
    if (std::binary_search(d->m_disabledBackends.cbegin(), d->m_disabledBackends.cend(), backendId)) {
        return false;
    }
    if (std::binary_search(d->m_enabledBackends.cbegin(), d->m_enabledBackends.cend(), backendId)) {
        return true;
    }

    return d->m_backendsEnabledByDefault && !std::binary_search(d->m_disabledByDefault.cbegin(), d->m_disabledByDefault.cend(), backendId);
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
    Q_EMIT configurationChanged();
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

bool Manager::backendsEnabledByDefault() const
{
    return d->m_backendsEnabledByDefault;
}

void Manager::setBackendsEnabledByDefault(bool byDefault)
{
    d->m_backendsEnabledByDefault = byDefault;

    Q_EMIT configurationChanged();
}

bool Manager::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::LanguageChange && object == QCoreApplication::instance() && !QCoreApplication::closingDown()) {
        reload();
    }

    return QObject::eventFilter(object, event);
}

void Manager::checkForUpdates(bool force)
{
    if (d->m_updateResult == UpdateResult::InProgress) {
        return;
    }

    if (!force && UpdateState::lastUpdate().addDays(1) > QDateTime::currentDateTimeUtc()) {
        d->m_updateResult = UpdateResult::NoUpdate;
        Q_EMIT updateResultChanged();
        return;
    }

    d->m_updateResult = UpdateResult::InProgress;
    Q_EMIT updateResultChanged();

    auto job = new UpdateJob(this);
    job->start(d->nam());
    connect(job, &UpdateJob::finished, this, [this, job]() {
        job->deleteLater();
        qCDebug(Log) << job->result();
        d->m_updateResult = job->result();
        if (job->result() == UpdateResult::UpdateSuccessful) {
            reload();
        }
        Q_EMIT updateResultChanged();
    });
}

UpdateResult::Type Manager::updateResult() const
{
    return d->m_updateResult;
}

#include "moc_manager.cpp"
