/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_CACHE_H
#define KPUBLICTRANSPORT_CACHE_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Attribution>

#include <chrono>
#include <vector>

class QString;

namespace KPublicTransport {

class Journey;
class Location;
class Stopover;
class VehicleLayoutResult;

enum class CacheHitType {
    Miss,
    Positive,
    Negative
};

template <typename T> struct CacheEntry
{
    CacheEntry() = default;
    CacheEntry(CacheEntry&&) = default;
    CacheEntry(const CacheEntry&) = delete;
    ~CacheEntry() = default;
    CacheEntry& operator=(CacheEntry&&) = default;
    CacheEntry& operator=(const CacheEntry&) = delete;

    std::vector<T> data;
    std::vector<Attribution> attributions;
    CacheHitType type = CacheHitType::Miss;
};

/** C++20 forward compatibility */
namespace chrono {
    typedef std::chrono::duration<std::chrono::seconds::rep, std::ratio<86400>> days;
}

/** Query result caching functions.
 *  @internal exported for unit tests only
 */
namespace Cache
{
    /** Add data and corresponding attribution information to the cache. */
    KPUBLICTRANSPORT_EXPORT void addLocationCacheEntry(const QString &backendId, const QString &cacheKey, const std::vector<Location> &data, const std::vector<Attribution> &attributions, std::chrono::seconds ttl = chrono::days(30));
    /** Add negative cache entry for location queries, ie. remember a result could not be found. */
    KPUBLICTRANSPORT_EXPORT void addNegativeLocationCacheEntry(const QString &backendId, const QString &cacheKey, std::chrono::seconds ttl = chrono::days(30));
    /** Perform cache lookup for location results. */
    KPUBLICTRANSPORT_EXPORT CacheEntry<Location> lookupLocation(const QString &backendId, const QString &cacheKey);

    /** Add negative cache entry for departure queries, ie. remember a result could not be found. */
    void addNegativeDepartureCacheEntry(const QString &backendId, const QString &cacheKey, std::chrono::seconds ttl = chrono::days(30));
    /** Perform cache lookup for departure results. */
    CacheEntry<Stopover> lookupDeparture(const QString &backendId, const QString &cacheKey);

    /** Add negative cache entry for departure queries, ie. remember a result could not be found. */
    void addNegativeJourneyCacheEntry(const QString &backendId, const QString &cacheKey, std::chrono::seconds ttl = chrono::days(30));
    /** Perform cache lookup for departure results. */
    CacheEntry<Journey> lookupJourney(const QString &backendId, const QString &cacheKey);

    /** Add a positive cache entry for a vehicle layout query. */
    void addVehicleLayoutCacheEntry(const QString &backendId, const QString &cacheKey, const VehicleLayoutResult &data, const std::vector<Attribution> &attributions, std::chrono::seconds ttl = std::chrono::minutes(1));
    /** Add negative cache entry for vehicle layout queries. */
    void addNegativeVehicleLayoutCacheEntry(const QString &backendId, const QString &cacheKey, std::chrono::seconds ttl = chrono::days(30));
    /** Perform cache lookup for vehicle layout results. */
    CacheEntry<VehicleLayoutResult> lookupVehicleLayout(const QString &backendId, const QString &cacheKey);

    /** Returns all cached attribution information.
     *  The result is inserted in the assumed to be sorted @p attrs and deduplicated.
     */
    KPUBLICTRANSPORT_EXPORT void allCachedAttributions(std::vector<Attribution> &attrs);

    /** Expire old cache entries. */
    void KPUBLICTRANSPORT_EXPORT expire();
}

}

#endif // KPUBLICTRANSPORT_CACHE_H
