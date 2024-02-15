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
    // TODO
    // - CanQueryNextJourney?
    // - CanQueryPreviousJourney?
    // - CanQueryNextDeparture?
    // - CanQueryPreviousDeparture?
    // - CanQueryArrivals?
    return (m_endpoint.scheme() == "https"_L1) ? AbstractBackend::Secure : AbstractBackend::NoCapability;
}

bool MotisBackend::needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const
{
    if (type == QueryType::Journey && m_intermodal) {
        return !loc.hasCoordinate() && loc.identifier(m_locationIdentifierType).isEmpty();
    }
    return loc.identifier(m_locationIdentifierType).isEmpty();
}

bool MotisBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
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

bool MotisBackend::queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    // TODO arrival/departure filtering needs to be done on the result
    QJsonObject query{
        {"destination"_L1, QJsonObject{
            {"type"_L1, "Module"_L1},
            {"target"_L1, "/railviz/get_station"_L1}
        }},
        {"content_type"_L1, "RailVizStationRequest"_L1},
        {"content"_L1, QJsonObject{
            {"time"_L1, encodeTime(req.dateTime())},
            {"direction"_L1, "BOTH"_L1}, // TODO paging?
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
            // TODO caching?
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
    // TODO allow external configuration of the durection limits and PPR profiles
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
    // backward search for MOTIS is really backward, so we need to swap everything
    const auto from = req.dateTimeMode() == JourneyRequest::Departure ? req.from() : req.to();
    const auto to = req.dateTimeMode() == JourneyRequest::Departure ? req.to() : req.from();
    const auto &startModes = req.dateTimeMode() == JourneyRequest::Departure ? req.accessModes() : req.egressModes();
    const auto &destModes = req.dateTimeMode() == JourneyRequest::Departure ? req.egressModes() : req.accessModes();

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
            {"!start_type"_L1, from.hasCoordinate() && m_intermodal ? "IntermodalPretripStart"_L1 : "PretripStart"_L1},
            {"!start"_L1, QJsonObject{
                {from.hasCoordinate() && m_intermodal ? "position"_L1: "station"_L1, encodeLocation(from, m_locationIdentifierType, m_intermodal)},
                {"interval"_L1, QJsonObject{
                    {"begin"_L1, encodeTime(req.dateTime())},
                    {"end"_L1, encodeTime(req.dateTime()) + 1800}, // TODO configure this
                }},
                {"min_connection_count"_L1, req.maximumResults()},
                {"extend_interval_earlier"_L1, true}, // TODO paging support
                {"extend_interval_later"_L1, true},
            }},
            {"!start_modes"_L1, ivModes(startModes)},
            {"destination_type"_L1, to.hasCoordinate() && m_intermodal ? "InputPosition"_L1 : "InputStation"_L1},
            {"destination"_L1, encodeLocation(to, m_locationIdentifierType, m_intermodal)},
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

        // TODO result caching?
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
    netReq.setHeader(QNetworkRequest::ContentTypeHeader, "application/json"_L1);
    // TODO user agent
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
