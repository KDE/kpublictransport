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
#include <KPublicTransport/TripReply>
#include <KPublicTransport/TripRequest>

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

Location::Types Motis2Backend::supportedLocationTypes() const
{
    return Location::Stop | Location::Address;
}

bool Motis2Backend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    if (type == QueryType::Journey) {
        return (!loc.hasCoordinate() || !m_supportsStreetRouting) && !loc.hasIdentifier(m_locationIdentifierType);
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
    QUrlQuery query;
    QNetworkReply *netReply = nullptr;

    if (req.hasCoordinate() && (req.types() & Location::Stop) && (req.types() & Location::Address) == 0) {
        const auto dlat = req.maximumDistance() / Location::distance(req.latitude(), 0.0, req.latitude(), 1.0);
        const auto dlon = req.maximumDistance() / Location::distance(0.0, req.longitude(), 1.0, req.longitude());
        query.addQueryItem(u"min"_s, QString::number(req.latitude() - dlat) + ','_L1 + QString::number(req.longitude() - dlon));
        query.addQueryItem(u"max"_s, QString::number(req.latitude() + dlat) + ','_L1 + QString::number(req.longitude() + dlon));

        netReply = makeRequest(req, reply, "v1/map/stops"_L1, query, nam);
        QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply]() {
            netReply->deleteLater();
            const auto data = netReply->readAll();
            logReply(reply, netReply, data);

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
        if (req.types() == Location::Stop) {
            query.addQueryItem(u"type"_s, u"STOP"_s);
        } else if (req.types() == Location::Address) {
            query.addQueryItem(u"type"_s, u"ADDRESS"_s);
        }
        netReply = makeRequest(req, reply, "v1/reverse-geocode"_L1, query, nam);
    } else {
        query.addQueryItem(u"text"_s, req.name());
        query.addQueryItem(u"language"_s, preferredLanguage());
        if (req.types() == Location::Stop) {
            query.addQueryItem(u"type"_s, u"STOP"_s);
        } else if (req.types() == Location::Address) {
            query.addQueryItem(u"type"_s, u"ADDRESS"_s);
        }
        if (req.viewbox().isValid()) {
            query.addQueryItem(u"place"_s, QString::number(req.viewbox().center().y()) + ','_L1 + QString::number(req.viewbox().center().x()));
        }

        netReply = makeRequest(req, reply, "v1/geocode"_L1, query, nam);
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

    auto netReply = makeRequest(req, reply, "v4/stoptimes"_L1, query, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply, req]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        Motis2Parser p(m_locationIdentifierType);
        auto result = p.parseStopTimes(data, reply->request().mode() == StopoverRequest::QueryArrival);
        if (netReply->error() == QNetworkReply::NoError) {
            setNextRequestContext(reply, p.m_nextPageCursor);
            setPreviousRequestContext(reply, p.m_previousPageCursor);

            // MOTIS has no support for doing mode filtering on the server
            if (!req.lineModes().empty()) {
                auto it = std::remove_if(result.begin(), result.end(), [req](const auto &s) {
                    return !std::binary_search(req.lineModes().begin(), req.lineModes().end(), s.route().line().mode());
                });
                result.erase(it, result.end());
            }

            addResult(reply, this, std::move(result));
        } else {
            addError(reply, Reply::NetworkError, netReply->errorString() + ' '_L1 + QString::fromUtf8(data));
        }
    });

    return true;
}

QString Motis2Backend::encodeLocation(const Location &loc) const
{
    if (loc.hasCoordinate() && m_supportsStreetRouting) {
        return QString::number(loc.latitude()) + ','_L1 + QString::number(loc.longitude()) + ','_L1 + QString::number(loc.hasFloorLevel() ? loc.floorLevel() : 0);
    }
    return loc.identifier(m_locationIdentifierType);
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
    { Line::Funicular, "FUNICULAR" },
    { Line::LocalTrain, "REGIONAL_FAST_RAIL" },
    { Line::LocalTrain, "REGIONAL_RAIL" },
    { Line::LongDistanceTrain, "HIGHSPEED_RAIL" },
    { Line::LongDistanceTrain, "LONG_DISTANCE" },
    { Line::LongDistanceTrain, "NIGHT_RAIL" },
    { Line::Metro, "SUBWAY" },
    { Line::RailShuttle, "RAIL" },
    { Line::RapidTransit, "SUBURBAN" },
    { Line::Shuttle, "BUS" },
    { Line::Shuttle, "COACH" },
    { Line::Taxi, "FLEXIBLE" },
    { Line::Taxi, "CAR_HAILING" },
    { Line::Train, "RAIL" },
    { Line::Tramway, "TRAM" },
    { Line::Tramway, "CABLE_CAR" },
    { Line::RideShare, "CAR_SHARING" },
    { Line::AerialLift, "AERIAL_LIFT" },
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
    // { IndividualTransport::Bike, IndividualTransport::Park, "BIKE_TO_PARK", nullptr }, // TODO removed in later v2 versions again
    { IndividualTransport::Bike, IndividualTransport::None, "BIKE", nullptr },
    { IndividualTransport::Car, IndividualTransport::Rent, "RENTAL", "CAR" },
    { IndividualTransport::Car, IndividualTransport::Park, "CAR_PARKING", nullptr },
    // { IndividualTransport::Car, IndividualTransport::Pickup, "CAR_PICKUP", nullptr }, // TODO removed in later v2 versions again
    { IndividualTransport::Car, IndividualTransport::Dropoff, "CAR_DROPOFF", nullptr },
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
    query.addQueryItem(u"fromPlace"_s, encodeLocation(req.from()));
    query.addQueryItem(u"toPlace"_s, encodeLocation(req.to()));
    query.addQueryItem(u"time"_s, req.dateTime().toUTC().toString(Qt::ISODate));
    query.addQueryItem(u"detailedTransfers"_s, req.includePaths() ? u"true"_s : u"false"_s);

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
        QStringList accessModes({u"WALK"_s});
        QStringList accessFormFactors;
        mapIndividualTransportModes(req.accessModes(), accessModes);
        mapIndividualTransportFormFactors(req.accessModes(), accessFormFactors);
        accessModes.removeDuplicates();
        accessFormFactors.removeDuplicates();
        query.addQueryItem(u"preTransitModes"_s, accessModes.join(','_L1));
        if (!accessFormFactors.empty()) {
            query.addQueryItem(u"preTransitRentalFormFactors"_s, accessFormFactors.join(','_L1));
        }
    }
    {
        QStringList egressModes({u"WALK"_s});
        QStringList egressFormFactors;
        mapIndividualTransportModes(req.egressModes(), egressModes);
        mapIndividualTransportFormFactors(req.egressModes(), egressFormFactors);
        egressModes.removeDuplicates();
        egressFormFactors.removeDuplicates();
        query.addQueryItem(u"postTransitModes"_s, egressModes.join(','_L1));
        if (!egressFormFactors.empty()) {
            query.addQueryItem(u"postTransitRentalFormFactors"_s, egressFormFactors.join(','_L1));
        }
    }

    query.addQueryItem(u"numItineraries"_s, QString::number(req.maximumResults()));
    if (const auto pageCursor = requestContextData(req).toString(); !pageCursor.isEmpty()) {
        query.addQueryItem(u"pageCursor"_s, pageCursor);
    }
    query.addQueryItem(u"arriveBy"_s, req.dateTimeMode() == JourneyRequest::Arrival ? u"true"_s : u"false"_s);

    auto netReply = makeRequest(req, reply, "v4/plan"_L1, query, nam);
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

bool Motis2Backend::queryTrip(const TripRequest &req, TripReply *reply, QNetworkAccessManager *nam) const
{
    const auto tripId = req.identifier(m_locationIdentifierType);
    if (tripId.isEmpty()) {
        return false;
    }

    QUrlQuery query;
    query.addQueryItem(u"tripId"_s, tripId);
    auto netReply = makeRequest(req, reply, "v4/trip"_L1, query, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString() + ' '_L1 + QString::fromUtf8(data));
            return;
        }

        Motis2Parser p(m_locationIdentifierType);
        auto result = p.parseItinerary(QJsonDocument::fromJson(data).object());
        if (result.sections().size() != 1 || result.sections()[0].mode() != JourneySection::PublicTransport) {
            addError(reply, Reply::NotFoundError, {});
        } else {
            addResult(reply, this, JourneySection(result.sections()[0]));
        }
    });
    return true;
}

template <typename Request>
QNetworkReply* Motis2Backend::makeRequest(const Request &req, QObject *parent, QLatin1StringView command, const QUrlQuery &query, QNetworkAccessManager *nam) const
{
    auto url = m_endpoint;
    url.setPath("/api/"_L1 + command);
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
