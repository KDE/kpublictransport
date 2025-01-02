/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "motis2backend.h"
#include "cache.h"
#include "motis2parser.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopoverReply>
#include <KPublicTransport/StopoverRequest>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrlQuery>

using namespace KPublicTransport;
using namespace Qt::Literals::StringLiterals;

Motis2Backend::Motis2Backend() = default;
Motis2Backend::~Motis2Backend() = default;

AbstractBackend::Capabilities Motis2Backend::capabilities() const
{
    auto c = AbstractBackend::CanQueryArrivals
        | AbstractBackend::CanQueryNextDeparture | AbstractBackend::CanQueryPreviousDeparture
        | AbstractBackend::CanQueryNextJourney | AbstractBackend::CanQueryPreviousJourney;
    if (m_endpoint.scheme() == "https"_L1) {
        c |= AbstractBackend::Secure;
    }
    return c;
}

bool Motis2Backend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    if (type == QueryType::Journey) {
        return !loc.hasCoordinate() && !loc.hasIdentifier(m_locationIdentifierType);
    }
    return !loc.hasIdentifier(m_locationIdentifierType);
}

static void filterLocations(std::vector<Location> &locations, Location::Types types)
{
    if ((types & Location::Address) || types == Location::Place) {
        return;
    }
    auto it = std::remove_if(locations.begin(), locations.end(), [types](const auto &loc) {
        return (loc.type() & types) == 0;
    });
    locations.erase(it, locations.end());
}

bool Motis2Backend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if ((req.types() & (Location::Stop|Location::Address)) == 0) {
        // only stop and address searches are supported
        return false;
    }

    QUrlQuery query;
    QNetworkReply *netReply = nullptr;

    if (req.hasCoordinate() && (req.types() & Location::Stop) && (req.types() & Location::Address) == 0) {
        const auto dlat = req.maximumDistance() / Location::distance(req.latitude(), 0.0, req.latitude(), 1.0);
        const auto dlon = req.maximumDistance() / Location::distance(0.0, req.longitude(), 1.0, req.longitude());
        query.addQueryItem(u"min"_s, QString::number(req.latitude() - dlat) + ','_L1 + QString::number(req.longitude() - dlon));
        query.addQueryItem(u"max"_s, QString::number(req.latitude() + dlat) + ','_L1 + QString::number(req.longitude() + dlon));

        netReply = makeRequest(req, reply, "map/stops"_L1, query, nam);
        QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
            netReply->deleteLater();
            const auto data = netReply->readAll();
            logReply(reply, netReply, data);
            qDebug().noquote() << data << netReply->error();

            Motis2Parser p(m_locationIdentifierType);
            auto result = p.parseMapStops(data);

            if (netReply->error() == QNetworkReply::NoError) {
                if (result.empty()) {
                    Cache::addNegativeLocationCacheEntry(backendId(), reply->request().cacheKey(), std::chrono::days(m_cacheDays));
                } else {
                    Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), result, {}, std::chrono::days(m_cacheDays));
                }
                addResult(reply, std::move(result));
            } else {
                addError(reply, Reply::NetworkError, netReply->errorString() + ' '_L1 + QString::fromUtf8(data));
            }
        });
        return true;
    }

    if (req.hasCoordinate()) {
        query.addQueryItem(u"place"_s, QString::number(req.latitude()) + ','_L1 + QString::number(req.longitude()));
        netReply = makeRequest(req, reply, "reverse-geocode"_L1, query, nam);
    } else {
        query.addQueryItem(u"text"_s, req.name());
        query.addQueryItem(u"language"_s, preferredLanguage());
        netReply = makeRequest(req, reply, "geocode"_L1, query, nam);
    }

    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        Motis2Parser p(m_locationIdentifierType);
        auto result = p.parseLocations(data);
        filterLocations(result, reply->request().types());

        if (netReply->error() == QNetworkReply::NoError) {
            if (result.empty()) {
                Cache::addNegativeLocationCacheEntry(backendId(), reply->request().cacheKey(), std::chrono::days(m_cacheDays));
            } else {
                Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), result, {}, std::chrono::days(m_cacheDays));
            }
            addResult(reply, std::move(result));
        } else {
            addError(reply, Reply::NetworkError, netReply->errorString() + ' '_L1 + QString::fromUtf8(data));
        }
    });
    return true;
}

bool Motis2Backend::queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    const auto stopId = req.stop().identifier(m_locationIdentifierType);
    if (stopId.isEmpty()) {
        return false;
    }

    QUrlQuery query;
    query.addQueryItem(u"time"_s, req.dateTime().toUTC().toString(Qt::ISODate));
    query.addQueryItem(u"stopId"_s, stopId);
    query.addQueryItem(u"n"_s, QString::number(req.maximumResults()));
    query.addQueryItem(u"arriveBy"_s, req.mode() == StopoverRequest::QueryArrival ? u"true"_s : u"false"_s);
    if (const auto pageCursor = requestContextData(req).toString(); !pageCursor.isEmpty()) {
        query.addQueryItem(u"pageCursor"_s, pageCursor);
    }
    query.addQueryItem(u"radius"_s, u"200"_s);

    auto netReply = makeRequest(req, reply, "stoptimes"_L1, query, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        Motis2Parser p(m_locationIdentifierType);
        auto result = p.parseStopTimes(data);
        if (netReply->error() == QNetworkReply::NoError) {
            setNextRequestContext(reply, p.m_nextPageCursor);
            setPreviousRequestContext(reply, p.m_previousPageCursor);
            addResult(reply, this, std::move(result));
        } else {
            addError(reply, Reply::NetworkError, netReply->errorString() + ' '_L1 + QString::fromUtf8(data));
        }
    });

    return true;
}

[[nodiscard]] static QString encodeLocation(const Location &loc, const QString &locationIdentifierType)
{
    if (loc.hasCoordinate()) {
        return QString::number(loc.latitude()) + ','_L1 + QString::number(loc.longitude()) + ','_L1 + QString::number(loc.hasFloorLevel() ? loc.floorLevel() : 0);
    }
    return loc.identifier(locationIdentifierType);
}

struct {
    Line::Mode mode;
    const char *name;
} static constexpr const transit_mode_map[] = {
    { Line::Air, "AIRPLANE" },
    { Line::Boat, "FERRY" },
    { Line::Bus, "BUS" },
    { Line::Coach, "COACH" },
    { Line::Ferry, "FERRY" },
    { Line::Funicular, "OTHER" },
    { Line::LocalTrain, "REGIONAL_FAST_RAIL" },
    { Line::LocalTrain, "REGIONAL_RAIL" },
    { Line::LongDistanceTrain, "HIGHSPEED_RAIL" },
    { Line::LongDistanceTrain, "LONG_DISTANCE" },
    { Line::LongDistanceTrain, "NIGHT_RAIL" },
    { Line::Metro, "SUBWAY" },
    { Line::RailShuttle, "RAIL" },
    { Line::RapidTransit, "METRO" },
    { Line::Shuttle, "BUS" },
    { Line::Shuttle, "COACH" },
    { Line::Taxi, "FLEXIBLE" },
    { Line::Taxi, "CAR_HAILING" },
    { Line::Train, "RAIL" },
    { Line::Tramway, "TRAM" },
    { Line::RideShare, "CAR_SHARING" },
    { Line::AerialLift, "OTHER" },
};

struct {
    IndividualTransport::Mode mode;
    IndividualTransport::Qualifier qualifier;
    const char *modeName;
    const char *formFactorName;
} static constexpr const iv_mode_map[] = {
    { IndividualTransport::Walk, IndividualTransport::None, "WALK", nullptr },
    { IndividualTransport::Bike, IndividualTransport::Rent, "RENTAL", "BICYCLE" },
    // { IndividualTransport::Bike, IndividualTransport::Rent, "RENTAL", "SCOOTER_STANDING" }, // TODO not modelled correctly, not implemented in current MOTISv2 deployment
    { IndividualTransport::Bike, IndividualTransport::Park, "BIKE_TO_PARK", nullptr },
    { IndividualTransport::Bike, IndividualTransport::None, "BIKE", nullptr },
    { IndividualTransport::Car, IndividualTransport::Rent, "RENTAL", "CAR" },
    { IndividualTransport::Car, IndividualTransport::Park, "CAR_TO_PARK", nullptr },
    { IndividualTransport::Car, IndividualTransport::Pickup, "CAR_PICKUP", nullptr },
    { IndividualTransport::Car, IndividualTransport::None, "CAR", nullptr },
};

static void mapIndividualTransportModes(const std::vector<IndividualTransport> &ivModes, QStringList &modes)
{
    for (const auto &iv : ivModes) {
        for (const auto &m :iv_mode_map) {
            if (m.mode == iv.mode() && m.qualifier == iv.qualifier()) {
                modes.push_back(QLatin1StringView(m.modeName));
            }
        }
    }
}

static void mapIndividualTransportFormFactors(const std::vector<IndividualTransport> &ivModes, QStringList &formFactors)
{
    for (const auto &iv : ivModes) {
        for (const auto &m :iv_mode_map) {
            if (m.mode == iv.mode() && m.qualifier == iv.qualifier() && m.formFactorName) {
                formFactors.push_back(QLatin1StringView(m.formFactorName));
            }
        }
    }
}

bool Motis2Backend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    QUrlQuery query;
    query.addQueryItem(u"fromPlace"_s, encodeLocation(req.from(), m_locationIdentifierType));
    query.addQueryItem(u"toPlace"_s, encodeLocation(req.to(), m_locationIdentifierType));
    query.addQueryItem(u"time"_s, req.dateTime().toUTC().toString(Qt::ISODate));

    QStringList transitModes, directModes;
    QStringList directModeFormFactors;
    if (req.modes() & JourneySection::Walking) {
        directModes.push_back(u"WALK"_s);
    }
    if (req.modes() & JourneySection::PublicTransport) {
        if (req.lineModes().empty()) {
            transitModes.push_back(u"TRANSIT"_s);
        } else {
            for (auto mode : req.lineModes()) {
                for (const auto &m : transit_mode_map) {
                    if (mode == m.mode) {
                        transitModes.push_back(QLatin1StringView(m.name));
                    }
                }
            }
        }
        if (req.requiresBikeTransport()) {
            query.addQueryItem(u"requireBikeTransport"_s, u"true"_s);
        }
    }
    if (req.modes() & JourneySection::IndividualTransport) {
        mapIndividualTransportModes(req.individualTransportModes(), directModes);
        mapIndividualTransportFormFactors(req.individualTransportModes(), directModeFormFactors);
    }
    if (req.modes() & JourneySection::RentedVehicle) {
        // TODO we actually lack more detailed qualifiers for this?
        directModes.push_back(u"RENTAL"_s);
    }

    transitModes.removeDuplicates();
    query.addQueryItem(u"transitModes"_s, transitModes.join(','_L1));

    directModes.removeDuplicates();
    directModeFormFactors.removeDuplicates();
    if (!directModes.empty()) {
        query.addQueryItem(u"directModes"_s, directModes.join(','_L1));
    }
    if (!directModeFormFactors.empty()) {
        query.addQueryItem(u"directRentalFormFactors"_s, directModeFormFactors.join(','_L1));
    }

    {
        QStringList accessModes;
        QStringList accessFormFactors;
        mapIndividualTransportModes(req.accessModes(), accessModes);
        mapIndividualTransportFormFactors(req.accessModes(), accessFormFactors);
        accessModes.removeDuplicates();
        accessFormFactors.removeDuplicates();
        if (!accessModes.empty()) {
            query.addQueryItem(u"preTransitModes"_s, accessModes.join(','_L1));
        }
        if (!accessFormFactors.empty()) {
            query.addQueryItem(u"preTransitRentalFormFactors"_s, accessFormFactors.join(','_L1));
        }
    }
    {
        QStringList egressModes;
        QStringList egressFormFactors;
        mapIndividualTransportModes(req.egressModes(), egressModes);
        mapIndividualTransportFormFactors(req.egressModes(), egressFormFactors);
        egressModes.removeDuplicates();
        egressFormFactors.removeDuplicates();
        if (!egressModes.empty()) {
            query.addQueryItem(u"postTransitModes"_s, egressModes.join(','_L1));
        }
        if (!egressFormFactors.empty()) {
            query.addQueryItem(u"postTransitRentalFormFactors"_s, egressFormFactors.join(','_L1));
        }
    }

    query.addQueryItem(u"numItineraries"_s, QString::number(req.maximumResults()));
    if (const auto pageCursor = requestContextData(req).toString(); !pageCursor.isEmpty()) {
        query.addQueryItem(u"pageCursor"_s, pageCursor);
    }
    query.addQueryItem(u"arriveBy"_s, req.dateTimeMode() == JourneyRequest::Arrival ? u"true"_s : u"false"_s);

    auto netReply = makeRequest(req, reply, "plan"_L1, query, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        Motis2Parser p(m_locationIdentifierType);
        auto result = p.parseItineraries(data);
        if (netReply->error() == QNetworkReply::NoError) {
            setPreviousRequestContext(reply, p.m_previousPageCursor);
            setNextRequestContext(reply, p.m_nextPageCursor);
            addResult(reply, this, std::move(result));
        } else {
            addError(reply, Reply::NetworkError, netReply->errorString() + ' '_L1 + QString::fromUtf8(data));
        }

    });

    return true;
}

template <typename Request>
QNetworkReply* Motis2Backend::makeRequest(const Request &req, QObject *parent, QLatin1StringView command, const QUrlQuery &query, QNetworkAccessManager *nam) const
{
    auto url = m_endpoint;
    url.setPath("/api/v1/"_L1 + command);
    url.setQuery(query);
    QNetworkRequest netReq(url);
    applySslConfiguration(netReq);
    applyUserAgent(netReq);
    logRequest(req, netReq);
    qDebug() << url;
    auto netReply = nam->get(netReq);
    netReply->setParent(parent);
    return netReply;
}

#include "moc_motis2backend.cpp"
