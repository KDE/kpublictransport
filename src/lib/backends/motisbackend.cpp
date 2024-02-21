/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "motisbackend.h"
#include "abstractbackend.h"
#include "cache.h"
#include "motisparser.h"

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

using namespace KPublicTransport;
using namespace Qt::Literals::StringLiterals;

MotisBackend::MotisBackend() = default;
MotisBackend::~MotisBackend() = default;

AbstractBackend::Capabilities MotisBackend::capabilities() const
{
    auto c = AbstractBackend::CanQueryArrivals
        | AbstractBackend::CanQueryNextDeparture | AbstractBackend::CanQueryPreviousDeparture
        | AbstractBackend::CanQueryNextJourney | AbstractBackend::CanQueryPreviousJourney;
    if (m_endpoint.scheme() == "https"_L1) {
        c |= AbstractBackend::Secure;
    }
    return c;
}

bool MotisBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    if (type == QueryType::Journey && m_intermodal) {
        return !loc.hasCoordinate() && !loc.hasIdentifier(m_locationIdentifierType);
    }
    return !loc.hasIdentifier(m_locationIdentifierType);
}

bool MotisBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if ((req.types() & Location::Stop) == 0) {
        // only stop search is supported so far
        return false;
    }

    QJsonObject query;
    if (req.hasCoordinate()) {
        query = QJsonObject{
            {"destination"_L1, QJsonObject{
                {"type"_L1, "Module"_L1},
                {"target"_L1, "/lookup/geo_station"_L1}
            }},
            {"content_type"_L1, "LookupGeoStationRequest"_L1},
            {"content"_L1, QJsonObject{
                {"pos"_L1, QJsonObject{
                    {"lat"_L1, req.latitude()},
                    {"lng"_L1, req.longitude()},
                }},
                {"max_radius"_L1, req.maximumDistance()},
            }}
        };
    } else {
        query = QJsonObject{
            {"destination"_L1, QJsonObject{
                {"type"_L1, "Module"_L1},
                {"target"_L1, "/guesser"_L1}
            }},
            {"content_type"_L1, "StationGuesserRequest"_L1},
            {"content"_L1, QJsonObject{
                {"input"_L1, req.name()},
                {"guess_count"_L1, req.maximumResults()}
            }}
        };
    }

    auto netReply = makeRequest(req, reply, query, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        qDebug().noquote() << data << netReply->error();
        MotisParser p(m_locationIdentifierType);
        auto result = p.parseStations(data);
        if (netReply->error() == QNetworkReply::NoError && !p.hasError()) {
            Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), result, {});
            addResult(reply, std::move(result));
        } else if (p.hasError()) {
            addError(reply, Reply::InvalidRequest, p.errorMessage());
        } else {
            addError(reply, Reply::NetworkError, netReply->errorString());
        }
    });

    return true;
}

[[nodiscard]] static bool filterStopover(StopoverRequest::Mode mode, const Stopover &stop)
{
    switch (mode) {
        case StopoverRequest::QueryDeparture:
            return !stop.scheduledDepartureTime().isValid();
        case StopoverRequest::QueryArrival:
            return !stop.scheduledArrivalTime().isValid();
    }
    return false;
}

bool MotisBackend::queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    const auto context = requestContext(req);
    QDateTime dt;
    switch (context.type) {
        case RequestContext::Normal:
            dt = req.dateTime();
            break;
        case RequestContext::Next:
        case RequestContext::Previous:
            dt = context.dateTime;
            break;
    }

    QJsonObject query{
        {"destination"_L1, QJsonObject{
            {"type"_L1, "Module"_L1},
            {"target"_L1, "/railviz/get_station"_L1}
        }},
        {"content_type"_L1, "RailVizStationRequest"_L1},
        {"content"_L1, QJsonObject{
            {"time"_L1, encodeTime(dt)},
            {"direction"_L1, requestContext(req).type == RequestContext::Previous ? "EARLIER"_L1 : "LATER"_L1},
            {"station_id"_L1, req.stop().identifier(m_locationIdentifierType)},
            {"event_count"_L1, req.maximumResults()},
        }}
    };

    auto netReply = makeRequest(req, reply, query, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        qDebug().noquote() << data << netReply->error();
        MotisParser p(m_locationIdentifierType);
        auto result = p.parseEvents(data);
        if (netReply->error() == QNetworkReply::NoError && !p.hasError()) {
            // we get arrival/departure, arrival-only and departure-only results here
            // filter out the ones not requested
            const auto mode = reply->request().mode();
            result.erase(std::remove_if(result.begin(), result.end(), [mode](const auto &stop) { return filterStopover(mode, stop); }), result.end());
            addResult(reply, this, std::move(result));
        } else if (p.hasError()) {
            addError(reply, Reply::InvalidRequest, p.errorMessage());
        } else {
            addError(reply, Reply::NetworkError, netReply->errorString());
        }
    });

    return true;
}

[[nodiscard]] static QJsonArray ivModes(const std::vector<IndividualTransport> &ivs)
{
    // TODO allow external configuration of the duration limits and PPR profiles
    QJsonArray modes;
    for (const auto &iv : ivs) {
        if (iv.mode() == IndividualTransport::Walk) {
            modes.push_back(QJsonObject{
                {"mode_type"_L1, "FootPPR"_L1},
                {"mode"_L1, QJsonObject{
                    {"search_options"_L1, QJsonObject{
                        {"profile"_L1, "default"_L1},
                        {"duration_limit"_L1, 900},
                    }},
                }}
            });
        }
        if (iv.mode() == IndividualTransport::Bike && iv.qualifier() != IndividualTransport::Rent) {
            // TODO neither bike parking nor taking the bike on public transport is explicitly supported
            modes.push_back(QJsonObject{
                {"mode_type"_L1, "Bike"_L1},
                {"mode"_L1, QJsonObject{
                    {"max_duration"_L1, 900}, // TODO docs and fbs disagree on this
                }}
            });
        }
        if (iv.mode() == IndividualTransport::Car && iv.qualifier() != IndividualTransport::Park && iv.qualifier() != IndividualTransport::Rent) {
            modes.push_back(QJsonObject{
                {"mode_type"_L1, "Car"_L1},
                {"mode"_L1, QJsonObject{
                    {"max_duration"_L1, 900}, // TODO docs and fbs disagree on this
                }}
            });
        }
        if (iv.mode() == IndividualTransport::Car && iv.qualifier() == IndividualTransport::Park) {
            modes.push_back(QJsonObject{
                {"mode_type"_L1, "CarParking"_L1},
                {"mode"_L1, QJsonObject{
                    {"max_car_duration"_L1, 900},
                    {"ppr_search_options"_L1, QJsonObject{
                        {"profile"_L1, "default"_L1},
                        {"duration_limit"_L1, 900},
                    }},
                }}
            });
        }
    }
    return modes;
}

[[nodiscard]] static QJsonObject encodeLocation(const Location &loc, const QString &locationIdentifierType, bool intermodal)
{
    if (loc.hasCoordinate() && intermodal) {
        return QJsonObject({
            {"lat"_L1, loc.latitude()},
            {"lng"_L1, loc.longitude()}
        });
    }
    return QJsonObject({
        {"id"_L1, loc.identifier(locationIdentifierType)},
        {"name"_L1, loc.name()}
    });
}

bool MotisBackend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    // see https://motis-project.de/docs/api/endpoint/intermodal.html

    // backward search for MOTIS is really backward, so we need to swap everything
    const auto from = req.dateTimeMode() == JourneyRequest::Departure ? req.from() : req.to();
    const auto to = req.dateTimeMode() == JourneyRequest::Departure ? req.to() : req.from();
    const auto &startModes = req.dateTimeMode() == JourneyRequest::Departure ? req.accessModes() : req.egressModes();
    const auto &destModes = req.dateTimeMode() == JourneyRequest::Departure ? req.egressModes() : req.accessModes();

    // determine search time window
    qint64 beginTime = 0, endTime = 0;
    bool expandEarlier = false, expandLater = false;
    constexpr auto SEARCH_TIME_INTERVAL = 1800; // TODO does that make sense?
    const auto context = requestContext(req);
    switch (context.type) {
        case RequestContext::Normal:
            if (req.dateTimeMode() == JourneyRequest::Departure) {
                beginTime = encodeTime(req.dateTime());
                endTime = beginTime + SEARCH_TIME_INTERVAL;
            } else {
                endTime = encodeTime(req.dateTime());
                beginTime = endTime - SEARCH_TIME_INTERVAL;
            }
            // ### see https://motis-project.de/docs/api/endpoint/intermodal.html#intermodal-pretrip-start
            // this says we need to enable expansion in both directiony for min_connection_count to work
            expandEarlier = true; // req.dateTimeMode() == JourneyRequest::Arrival;
            expandLater = true; // req.dateTimeMode() == JourneyRequest::Departure;
            break;
        case RequestContext::Next:
            beginTime = context.backendData.toLongLong();
            endTime = beginTime + SEARCH_TIME_INTERVAL;
            expandEarlier = false;
            expandLater = true;
            break;
        case RequestContext::Previous:
            endTime = context.backendData.toLongLong();
            beginTime = endTime - SEARCH_TIME_INTERVAL;
            expandEarlier = true;
            expandLater = false;
            break;
    }

    const auto fromIntermodel = m_intermodal && !from.hasIdentifier(m_locationIdentifierType);
    const auto toIntermodal = m_intermodal && !to.hasIdentifier(m_locationIdentifierType);

    // ### HACK in this request the JSON key order matters!!
    // see https://github.com/motis-project/motis/issues/433
    // thefore the '!' prefix hack and post-processing below...
    // can be removed once the fix hits the Motis demo server
    QJsonObject query{
        {"destination"_L1, QJsonObject{
            {"type"_L1, "Module"_L1},
            {"target"_L1, "/intermodal"_L1}
        }},
        {"content_type"_L1, "IntermodalRoutingRequest"_L1},
        {"content"_L1, QJsonObject{
            // TODO how can we make the ontrip start options available? OntripTrainStart in particular
            {"!start_type"_L1, fromIntermodel ? "IntermodalPretripStart"_L1 : "PretripStart"_L1},
            {"!start"_L1, QJsonObject{
                {fromIntermodel ? "position"_L1: "station"_L1, encodeLocation(from, m_locationIdentifierType, fromIntermodel)},
                {"interval"_L1, QJsonObject{
                    {"begin"_L1, beginTime},
                    {"end"_L1, endTime},
                }},
                {"min_connection_count"_L1, req.maximumResults()},
                {"extend_interval_earlier"_L1, expandEarlier},
                {"extend_interval_later"_L1, expandLater},
            }},
            {"!start_modes"_L1, ivModes(startModes)},
            {"destination_type"_L1, toIntermodal ? "InputPosition"_L1 : "InputStation"_L1},
            {"destination"_L1, encodeLocation(to, m_locationIdentifierType, toIntermodal)},
            {"destination_modes"_L1, ivModes(destModes)},
            {"search_type"_L1, "Default"_L1},
            {"search_dir"_L1, req.dateTimeMode() == JourneyRequest::Departure ? "Forward"_L1 : "Backward"_L1},
            {"router"_L1, ""_L1}
        }}
    };

    auto netReply = makeRequest(req, reply, query, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        qDebug().noquote() << data << netReply->error();
        MotisParser p(m_locationIdentifierType);
        auto result = p.parseConnections(data);
        if (netReply->error() == QNetworkReply::NoError && !p.hasError()) {
            setPreviousRequestContext(reply, result.begin);
            setNextRequestContext(reply, result.end);
            addResult(reply, this, std::move(result.journeys));
        } else if (p.hasError()) {
            addError(reply, Reply::InvalidRequest, p.errorMessage());
        } else {
            addError(reply, Reply::NetworkError, netReply->errorString());
        }

    });

    return true;
}

template <typename Request>
QNetworkReply* MotisBackend::makeRequest(const Request &req, Reply *reply, const QJsonObject &query, QNetworkAccessManager *nam) const
{
    QNetworkRequest netReq(m_endpoint);
    applySslConfiguration(netReq);
    applyUserAgent(netReq);
    netReq.setHeader(QNetworkRequest::ContentTypeHeader, "application/json"_L1);
    auto postData = QJsonDocument(query).toJson(QJsonDocument::Compact);
    // ### HACK see above
    postData = postData.replace("\"!", "\"");
    logRequest(req, netReq, postData);
    qDebug().noquote() << QJsonDocument(query).toJson();
    auto netReply = nam->post(netReq, postData);
    netReply->setParent(reply);
    return netReply;
}

qint64 MotisBackend::encodeTime(const QDateTime &dt)
{
    // MOTIS uses 0 offset UNIX time stamps
    return dt.toTimeZone(QTimeZone::fromSecondsAheadOfUtc(0)).toSecsSinceEpoch();
}

#include "moc_motisbackend.cpp"
