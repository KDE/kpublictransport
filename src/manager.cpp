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
#include "journeyrequestcontext_p.h"
#include "locationreply.h"
#include "locationrequest.h"
#include "logging.h"

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

    void resolveLocation(const LocationRequest &locReq, const AbstractBackend *backend, const std::function<void(const Location &loc)> &callback);
    bool queryJourney(const AbstractBackend *backend, const JourneyRequest &req, JourneyReply *reply);

    Manager *q = nullptr;
    QNetworkAccessManager *m_nam = nullptr;
    std::vector<std::unique_ptr<AbstractBackend>> m_backends;
    std::vector<Attribution> m_attributions;
    bool m_allowInsecure = false;
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
            m_backends.push_back(std::move(net));
        } else {
            qCWarning(Log) << "Failed to load public transport network configuration config:" << it.fileName();
        }
    }

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
    if (backend->isLocationExcluded(req.from()) && backend->isLocationExcluded(req.to())) {
        qCDebug(Log) << "Skipping backend based on location filter:" << backend->backendId();
        return false;
    }
    if (!backend->hasCapability(AbstractBackend::Secure) && !m_allowInsecure) {
        qCDebug(Log) << "Skipping insecure backend:" << backend->backendId();
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
        resolveLocation(toReq, backend, [reply, backend, this](const Location &loc) {
            const auto toLoc = Location::merge(reply->request().to(), loc);
            auto jnyRequest = reply->request();
            jnyRequest.setTo(toLoc);
            if (!backend->queryJourney(jnyRequest, reply, nam())) {
                reply->addError(Reply::NotFoundError, {});
            }
        });
        return true;
    }

    return backend->queryJourney(req, reply, nam());
}


Manager::Manager(QObject *parent)
    : QObject(parent)
    , d(new ManagerPrivate)
{
    initResources();
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

void Manager::setAllowInsecureBackends(bool insecure)
{
    d->m_allowInsecure = insecure;
}

JourneyReply* Manager::queryJourney(const JourneyRequest &req) const
{
    auto reply = new JourneyReply(req, const_cast<Manager*>(this));
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
            if ((context.type == JourneyRequestContext::Next && context.backend->hasCapability(AbstractBackend::CanQueryNextJourney))
              ||(context.type == JourneyRequestContext::Previous && context.backend->hasCapability(AbstractBackend::CanQueryPreviousJourney)))
            {
                if (d->queryJourney(context.backend, req, reply)) {
                    ++pendingOps;
                    continue;
                }
            }

            // backend doesn't support this, let's try to emulate
            if (context.type == JourneyRequestContext::Next && req.dateTimeMode() == JourneyRequest::Departure) {
                auto r = req;
                r.setDepartureTime(context.dateTime);
                if (d->queryJourney(context.backend, r, reply)) {
                    ++pendingOps;
                    continue;
                }
            }
            // TODO support previous arrival
        }
    }

    reply->setPendingOps(pendingOps);
    return reply;
}

DepartureReply* Manager::queryDeparture(const DepartureRequest &req) const
{
    auto reply = new DepartureReply(req, const_cast<Manager*>(this));
    int pendingOps = 0;
    for (const auto &backend : d->m_backends) {
        if (backend->isLocationExcluded(req.stop())) {
            qCDebug(Log) << "Skipping backend based on location filter:" << backend->backendId();
            continue;
        }
        if (!backend->hasCapability(AbstractBackend::Secure) && !d->m_allowInsecure) {
            qCDebug(Log) << "Skipping insecure backend:" << backend->backendId();
            continue;
        }
        reply->addAttribution(backend->attribution());

        // check if we first need to resolve the location first
        if (backend->needsLocationQuery(req.stop(), AbstractBackend::QueryType::Departure)) {
            qCDebug(Log) << "Backend needs location query first:" << backend->backendId();
            ++pendingOps;
            LocationRequest locReq;
            locReq.setCoordinate(req.stop().latitude(), req.stop().longitude());
            locReq.setName(req.stop().name());
            d->resolveLocation(locReq, backend.get(), [reply, &backend, this](const Location &loc) {
                const auto depLoc = Location::merge(reply->request().stop(), loc);
                auto depRequest = reply->request();
                depRequest.setStop(depLoc);
                if (!backend->queryDeparture(depRequest, reply, d->nam())) {
                    reply->addError(Reply::NotFoundError, {});
                }
            });
            continue;
        }

        if (backend->queryDeparture(req, reply, d->nam())) {
            ++pendingOps;
        }
    }
    reply->setPendingOps(pendingOps);
    return reply;
}

LocationReply* Manager::queryLocation(const LocationRequest &req) const
{
    auto reply = new LocationReply(req, const_cast<Manager*>(this));
    int pendingOps = 0;
    for (const auto &backend : d->m_backends) {
        if (req.hasCoordinate() && backend->isCoordinateExcluded(req.latitude(), req.longitude())) {
            qCDebug(Log) << "Skipping backend based on location filter:" << backend->backendId();
            continue;
        }
        if (!backend->hasCapability(AbstractBackend::Secure) && !d->m_allowInsecure) {
            qCDebug(Log) << "Skipping insecure backend:" << backend->backendId();
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
    return d->m_attributions;
}

QVariantList Manager::attributionsVariant() const
{
    QVariantList l;
    l.reserve(d->m_attributions.size());
    std::transform(d->m_attributions.begin(), d->m_attributions.end(), std::back_inserter(l), [](const auto &attr) { return QVariant::fromValue(attr); });
    return l;
}
