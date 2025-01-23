/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "opentripplannergraphqlbackend.h"
#include "opentripplannerparser.h"
#include "cache.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/RentalVehicle>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopoverReply>
#include <KPublicTransport/StopoverRequest>
#include <KPublicTransport/TripReply>
#include <KPublicTransport/TripRequest>

#include <kgraphql.h>

#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QNetworkRequest>
#include <QUrl>

using namespace Qt::Literals;
using namespace KPublicTransport;

OpenTripPlannerGraphQLBackend::OpenTripPlannerGraphQLBackend() = default;
OpenTripPlannerGraphQLBackend::~OpenTripPlannerGraphQLBackend() = default;

AbstractBackend::Capabilities OpenTripPlannerGraphQLBackend::capabilities() const
{
    return (m_endpoint.startsWith(QLatin1String("https://")) ? Secure : NoCapability)
        |  (m_apiVersion == QLatin1String("otp2") ? (CanQueryNextJourney | CanQueryPreviousJourney) : NoCapability);
}

bool OpenTripPlannerGraphQLBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    Q_UNUSED(type);
    return !loc.hasCoordinate();
}

bool OpenTripPlannerGraphQLBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if ((req.types() & (Location::Stop | Location::RentedVehicle | Location::RentedVehicleStation)) == 0) {
        return false;
    }

    auto gqlReq = graphQLRequest();
    if (req.hasCoordinate()) {
        gqlReq.setQueryFromFile(graphQLPath(QStringLiteral("stationByCoordinate.graphql")));
        gqlReq.setVariable(QStringLiteral("lat"), req.latitude());
        gqlReq.setVariable(QStringLiteral("lon"), req.longitude());
        gqlReq.setVariable(QStringLiteral("radius"), req.maximumDistance());
        gqlReq.setVariable(QStringLiteral("maxResults"), req.maximumResults());
        QJsonArray placeTypeFilter;
        if (req.types() & Location::Stop) {
            placeTypeFilter.push_back(m_apiVersion == QLatin1String("entur") ? QStringLiteral("stopPlace") : QStringLiteral("STOP"));
        }
        if (req.types() & (Location::RentedVehicleStation | Location::RentedVehicle)) {
            placeTypeFilter.push_back(m_apiVersion == QLatin1String("entur") ? QStringLiteral("bicycleRent") : QStringLiteral("BICYCLE_RENT"));
        }
        // TODO: also supports BIKE_PARK, CAR_PARK
        gqlReq.setVariable(QStringLiteral("placeType"), placeTypeFilter);
    } else {
        gqlReq.setQueryFromFile(graphQLPath(QStringLiteral("stationByName.graphql")));
        gqlReq.setVariable(QStringLiteral("name"), req.name());
    }

    if (isLoggingEnabled()) {
        logRequest(req, gqlReq.networkRequest(), gqlReq.rawData());
    }
    KGraphQL::query(gqlReq, nam, [this, req, reply](const KGraphQLReply &gqlReply) {
        logReply(reply, gqlReply.networkReply(), gqlReply.rawData());
        if (gqlReply.error() != KGraphQLReply::NoError) {
            addError(reply, Reply::NetworkError, gqlReply.errorString());
            return;
        }

        OpenTripPlannerParser p(backendId(), m_ifoptPrefix);
        p.setKnownRentalVehicleNetworks(m_rentalNetworks);
        std::vector<Location> res;
        if (req.hasCoordinate()) {
            res = p.parseLocationsByCoordinate(gqlReply.data());
        } else {
            res = p.parseLocationsByName(gqlReply.data());
        }
        // only cache results if there is no realtime data involved
        if ((req.types() & (Location::RentedVehicle | Location::RentedVehicleStation)) == 0) {
            Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), res, {});
        }
        addResult(reply, std::move(res));
    }, reply);

    return true;
}

struct {
    const char *otpMode;
    const char *enturMode;
    Line::Mode mode;
} static constexpr const otp_mode_map[] = {
    { "AIRPLANE", "air", Line::Air },
    { "BUS", "bus", Line::Bus },
    { "CABLE_CAR", "cableway", Line::AerialLift },
    { "CARPOOL", nullptr, Line::RideShare },
    { "COACH", "coach", Line::Coach },
    { "FERRY", "water", Line::Ferry },
    { "FUNICULAR", "funicular", Line::Funicular },
    { "GONDOLA", "lift", Line::AerialLift },
    { "RAIL", "rail", Line::LongDistanceTrain },
    { "RAIL", "rail", Line::Train },
    { "RAIL", "rail", Line::LocalTrain },
    { "RAIL", "rail", Line::RapidTransit },
    { "SUBWAY", "metro", Line::Metro },
    { "TRAM", "tram", Line::Tramway },
};

bool OpenTripPlannerGraphQLBackend::queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    if (!req.stop().hasCoordinate()) {
        return false;
    }

    auto gqlReq = graphQLRequest();
    gqlReq.setQueryFromFile(graphQLPath(QStringLiteral("departure.graphql")));
    gqlReq.setVariable(QStringLiteral("lat"), req.stop().latitude());
    gqlReq.setVariable(QStringLiteral("lon"), req.stop().longitude());
    auto dt = req.dateTime();
    if (timeZone().isValid()) {
        dt = dt.toTimeZone(timeZone());
    }
    gqlReq.setVariable(QStringLiteral("startTime"), dt.toSecsSinceEpoch());
    gqlReq.setVariable(QStringLiteral("startDateTime"), dt.toString(Qt::ISODate));
    gqlReq.setVariable(QStringLiteral("maxResults"), req.maximumResults());
    // TODO arrival/departure selection?

    // for unconstrained searches we need all modes, the "TRANSIT" special mode results in an empty result...
    const auto isEntur = m_apiVersion == QLatin1String("entur");
    QStringList modes;
    for (const auto &m : otp_mode_map) {
        if ((!isEntur || m.enturMode) && (req.lineModes().empty() || std::binary_search(req.lineModes().begin(), req.lineModes().end(), m.mode))) {
            modes.push_back(QLatin1String(isEntur ? m.enturMode : m.otpMode));
        }
    }
    modes.removeDuplicates();
    QJsonArray modesArray;
    std::copy(modes.begin(), modes.end(), std::back_inserter(modesArray));
    gqlReq.setVariable(QStringLiteral("modes"), modesArray);

    if (isLoggingEnabled()) {
        logRequest(req, gqlReq.networkRequest(), gqlReq.rawData());
    }
    KGraphQL::query(gqlReq, nam, [this, reply](const KGraphQLReply &gqlReply) {
        logReply(reply, gqlReply.networkReply(), gqlReply.rawData());
        if (gqlReply.error() != KGraphQLReply::NoError) {
            addError(reply, Reply::NetworkError, gqlReply.errorString());
        } else {
            OpenTripPlannerParser p(backendId(), m_ifoptPrefix);
            addResult(reply, this, p.parseDepartures(gqlReply.data()));
        }
    }, reply);

    return true;
}

static QString modeName(IndividualTransport::Mode mode)
{
    switch (mode) {
        case IndividualTransport::Walk: return QStringLiteral("WALK");
        case IndividualTransport::Bike: return QStringLiteral("BICYCLE");
        case IndividualTransport::Car: return QStringLiteral("CAR");
    }
    return {};
}

static QString qualifierName(IndividualTransport::Qualifier qualifier)
{
    switch (qualifier) {
        case IndividualTransport::None: return {};
        case IndividualTransport::Park: return QStringLiteral("PARK");
        case IndividualTransport::Rent: return QStringLiteral("RENT");
        case IndividualTransport::Dropoff: return QStringLiteral("DROPOFF");
        case IndividualTransport::Pickup: return QStringLiteral("PICKUP");
    }
    return {};
}

// ### Entur v3 only supports a single access/egress/direct mode
[[nodiscard]] static QLatin1StringView enturMode(std::vector<IndividualTransport> its)
{
    // walking is always implied for all other modes
    its.erase(std::remove_if(its.begin(), its.end(), [](const auto &it) { return it.mode() == IndividualTransport::Walk; }), its.end());

    if (its.size() == 1) {
        const auto it = its[0];
        // TODO scooter_rental
        switch (it.mode()) {
            case IndividualTransport::Bike:
                switch (it.qualifier()) {
                    case IndividualTransport::None:
                        return "bicycle"_L1;
                    case IndividualTransport::Park:
                        return "bike_park"_L1;
                    case IndividualTransport::Pickup:
                    case IndividualTransport::Dropoff:
                        break; // not applicable to bikes
                    case IndividualTransport::Rent:
                        return "bike_rental"_L1;
                }
                break;
            case IndividualTransport::Car:
                switch (it.qualifier()) {
                    case IndividualTransport::None:
                        return "car"_L1;
                    case IndividualTransport::Park:
                        return "car_park"_L1;
                    case IndividualTransport::Pickup:
                    case IndividualTransport::Dropoff:
                        return "car_pickup"_L1;
                    case IndividualTransport::Rent:
                        return "car_rental"_L1;
                }
                break;
            case IndividualTransport::Walk:
                break;
        }
    }

    return "foot"_L1;
}

bool OpenTripPlannerGraphQLBackend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    if (!req.from().hasCoordinate() || !req.to().hasCoordinate()) {
        return false;
    }

    auto gqlReq = graphQLRequest();
    gqlReq.setQueryFromFile(graphQLPath(QStringLiteral("journey.graphql")));
    gqlReq.setVariable(QStringLiteral("fromLat"), req.from().latitude());
    gqlReq.setVariable(QStringLiteral("fromLon"), req.from().longitude());
    gqlReq.setVariable(QStringLiteral("toLat"), req.to().latitude());
    gqlReq.setVariable(QStringLiteral("toLon"), req.to().longitude());

    auto dt = req.dateTime();
    const auto context = requestContextData(req).value<OpenTripPlannerRequestContext>();
    if (context.dateTime.isValid()) {
        dt = context.dateTime;
    }
    if (timeZone().isValid()) {
        dt = dt.toTimeZone(timeZone());
    }

    gqlReq.setVariable(QStringLiteral("date"), dt.toString(QStringLiteral("yyyy-MM-dd")));
    gqlReq.setVariable(QStringLiteral("time"), dt.toString(QStringLiteral("hh:mm:ss")));
    gqlReq.setVariable(QStringLiteral("dateTime"), dt.toString(Qt::ISODate));
    gqlReq.setVariable(QStringLiteral("arriveBy"), req.dateTimeMode() == JourneyRequest::Arrival);
    gqlReq.setVariable(QStringLiteral("maxResults"), req.maximumResults());
    gqlReq.setVariable(QStringLiteral("lang"), preferredLanguage());
    gqlReq.setVariable(QStringLiteral("withIntermediateStops"), req.includeIntermediateStops());
    gqlReq.setVariable(QStringLiteral("withPaths"), req.includePaths());
    // TODO set context.searchWindow?

    if (m_apiVersion == "entur"_L1) {
        gqlReq.setVariable(u"allowBikeRental"_s, (req.modes() & JourneySection::RentedVehicle) != 0);

        QJsonObject modesObj;
        modesObj.insert("accessMode"_L1, enturMode(req.accessModes()));
        modesObj.insert("egressMode"_L1, enturMode(req.egressModes()));
        if (!req.individualTransportModes().empty()) {
            modesObj.insert("directMode"_L1, enturMode(req.individualTransportModes()));
        }

        if ((req.modes() & JourneySection::PublicTransport) && !req.lineModes().empty()) {
            QStringList modes;
            for (const auto &m : otp_mode_map) {
                if (m.enturMode && std::binary_search(req.lineModes().begin(), req.lineModes().end(), m.mode)) {
                    modes.push_back(QLatin1StringView(m.enturMode));
                }
            }
            modes.removeDuplicates();
            QJsonArray modesArray;
            std::ranges::transform(modes, std::back_inserter(modesArray), [](const auto &mode){ return QJsonObject({{"transportMode"_L1, mode}}); });
            modesObj.insert("transportModes"_L1, modesArray);
        }

        gqlReq.setVariable(u"modes"_s, modesObj);
    } else {
        struct Mode {
            QString mode;
            QString qualifier;
        };
        std::vector<Mode> modes;

        if (req.modes() & JourneySection::PublicTransport) {
            if (req.lineModes().empty()) {
                for (const auto &mode : m_supportedTransitModes) {
                    modes.push_back({ mode, {} });
                }
            } else {
                for (const auto &m : otp_mode_map) {
                    if (std::binary_search(req.lineModes().begin(), req.lineModes().end(), m.mode)) {
                        modes.push_back({ QLatin1String(m.otpMode), {} });
                    }
                }
            }
        }
        if (req.modes() & JourneySection::RentedVehicle) {
            for (const auto &mode : m_supportedRentalModes) {
                modes.push_back({ mode, QStringLiteral("RENT") });
            }
        }
        for (const auto &it : req.accessModes()) {
            modes.push_back({ modeName(it.mode()), qualifierName(it.qualifier()) });
        }
        const auto modeLessThan = [](const Mode &lhs, const Mode &rhs) {
            if (lhs.mode == rhs.mode) {
                return lhs.qualifier < rhs.qualifier;
            }
            return lhs.mode < rhs.mode;
        };
        const auto modeEqual = [](const Mode &lhs, const Mode &rhs) {
            return lhs.mode == rhs.mode && lhs.qualifier == rhs.qualifier;
        };
        std::sort(modes.begin(), modes.end(), modeLessThan);
        modes.erase(std::unique(modes.begin(), modes.end(), modeEqual), modes.end());

        QJsonArray modesArray;
        for (const auto &mode : modes) {
            QJsonObject modeObj;
            modeObj.insert(QLatin1String("mode"), mode.mode);
            if (!mode.qualifier.isEmpty()) {
                modeObj.insert(QLatin1String("qualifier"), mode.qualifier);
            }
            modesArray.push_back(modeObj);
        }
        gqlReq.setVariable(QStringLiteral("modes"), modesArray);
    }

    if (isLoggingEnabled()) {
        logRequest(req, gqlReq.networkRequest(), gqlReq.rawData());
    }
    KGraphQL::query(gqlReq, nam, [this, reply](const KGraphQLReply &gqlReply) {
        logReply(reply, gqlReply.networkReply(), gqlReply.rawData());
        if (gqlReply.error() != KGraphQLReply::NoError) {
            addError(reply, Reply::NetworkError, gqlReply.errorString());
        } else {
            OpenTripPlannerParser p(backendId(), m_ifoptPrefix);
            p.setKnownRentalVehicleNetworks(m_rentalNetworks);
            addResult(reply, this, p.parseJourneys(gqlReply.data()));
            if (p.m_nextJourneyContext.dateTime.isValid()) {
                setNextRequestContext(reply, p.m_nextJourneyContext);
            }
            if (p.m_prevJourneyContext.dateTime.isValid()) {
                setPreviousRequestContext(reply, p.m_prevJourneyContext);
            }
        }
    }, reply);

    return true;
}

bool OpenTripPlannerGraphQLBackend::queryTrip(const TripRequest &req, TripReply *reply, QNetworkAccessManager *nam) const
{
    const auto tripId = req.journeySection().identifier(backendId());
    if (tripId.isEmpty()) {
        return false;
    }

    auto gqlReq = graphQLRequest();
    if (const auto &f = graphQLPath(u"trip.graphql"_s); !f.isEmpty()) {
        gqlReq.setQueryFromFile(f);
    } else {
        // Not supported by this API flavor
        return false;
    }
    gqlReq.setVariable(u"id"_s, tripId);
    gqlReq.setVariable(u"serviceDate"_s, req.journeySection().scheduledDepartureTime().date().toString("yyyyMMdd"_L1));
    if (isLoggingEnabled()) {
        logRequest(req, gqlReq.networkRequest(), gqlReq.rawData());
    }

    KGraphQL::query(gqlReq, nam, [this, reply](const KGraphQLReply &gqlReply) {
        logReply(reply, gqlReply.networkReply(), gqlReply.rawData());
        if (gqlReply.error() != KGraphQLReply::NoError) {
            addError(reply, Reply::NetworkError, gqlReply.errorString());
        } else {
            OpenTripPlannerParser p(backendId(), m_ifoptPrefix);
            addResult(reply, this, p.parseTrip(gqlReply.data()));
        }
    }, reply);

    return true;
}

KGraphQLRequest OpenTripPlannerGraphQLBackend::graphQLRequest() const
{
    KGraphQLRequest req(graphQLEndpoint());
    for (const auto &header : m_extraHeaders) {
        req.networkRequest().setRawHeader(header.first, header.second);
    }
    applySslConfiguration(req.networkRequest());
    return req;
}

QUrl OpenTripPlannerGraphQLBackend::graphQLEndpoint() const
{
    if (m_apiVersion == QLatin1String("entur")) {
        return QUrl(m_endpoint);
    }
    return QUrl(m_endpoint + QLatin1String("index/graphql"));
}

constexpr inline auto GRAPHQL_BASE_PATH = ":/org.kde.kpublictransport/otp/"_L1;

QString OpenTripPlannerGraphQLBackend::graphQLPath(const QString &fileName) const
{
    if (!m_apiVersion.isEmpty()) {
        const QString versionedPath = GRAPHQL_BASE_PATH + m_apiVersion + QLatin1Char('/') + fileName;
        if (QFile::exists(versionedPath)) {
            return versionedPath;
        }
    }

    const QString path = GRAPHQL_BASE_PATH + fileName;
    return QFile::exists(path) ? path : QString();
}

void OpenTripPlannerGraphQLBackend::setExtraHttpHeaders(const QJsonValue &v)
{
    const auto headers = v.toArray();
    m_extraHeaders.reserve(headers.size());
    for (const auto &header : headers) {
        const auto headerObj = header.toObject();
        const auto name = headerObj.value(QLatin1String("name")).toString().toUtf8();
        const auto val = headerObj.value(QLatin1String("value")).toString().toUtf8();
        if (name.isEmpty() || val.isEmpty()) {
            continue;
        }
        m_extraHeaders.push_back(std::make_pair(name, val));
    }
}

void OpenTripPlannerGraphQLBackend::setRentalVehicleNetworks(const QJsonObject &obj)
{
    m_rentalNetworks.reserve(obj.size());
    for (auto it = obj.begin(); it != obj.end(); ++it) {
        auto n = RentalVehicleNetwork::fromJson(it.value().toObject());
        m_rentalNetworks.insert(it.key(), std::move(n));
    }
}
