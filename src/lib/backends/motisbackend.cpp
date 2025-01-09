/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "motisbackend.h"
#include "backends/networkreplycollection.h"
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

/** Resolve intermodal paths for a set of journeys. */
namespace KPublicTransport {
class MotisPathQueryTask : public AsyncTask<void>
{
public:
    explicit MotisPathQueryTask(std::vector<Journey> &&journeys, const MotisBackend *backend, QNetworkAccessManager *nam, QObject *parent);
    void start();

    std::vector<Journey> m_journeys;

private:
    void queryNext();
    void applyPath(const Path &path, JourneySection::Mode mode, IndividualTransport::Mode ivMode);

    const MotisBackend *m_backend = nullptr;
    QNetworkAccessManager *m_nam = nullptr;

    std::size_t m_jnyIdx = 0;
    std::size_t m_secIdx = 0;
};
}

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
    if (type == QueryType::Journey && !m_supportedModes.empty()) {
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

    QNetworkReply *adrNetReply = nullptr;
    qWarning() << req.types();
    if (req.types() & Location::Address) {
        QJsonObject adrQuery = {
            {"destination"_L1, QJsonObject{
                {"type"_L1, "Module"_L1},
                {"target"_L1, "/address"_L1}
            }},
            {"content_type"_L1, "AddressRequest"_L1},
            {"content"_L1, QJsonObject{
                {"input"_L1, req.name()}
            }}
        };
        adrNetReply = makeRequest(req, reply, adrQuery, nam);
    }

    auto netReply = makeRequest(req, reply, query, nam);

    NetworkReplyCollection *replies = new NetworkReplyCollection({netReply, adrNetReply});
    QObject::connect(replies, &NetworkReplyCollection::allFinished, [this, netReply, adrNetReply, reply, replies]() {
        netReply->deleteLater();
        replies->deleteLater();

        MotisParser p(m_locationIdentifierType);

        const auto data = netReply->readAll();
        logReply(reply, netReply, data);
        auto result = p.parseStations(data);

        if (adrNetReply) {
            adrNetReply->deleteLater();

            const auto adrData = adrNetReply->readAll();
            logReply(reply, adrNetReply, adrData);
            auto adrResult = p.parseLocations(adrData);

            result.resize(adrResult.size() + result.size());
            std::copy(adrResult.begin(), adrResult.end(), std::back_inserter(result));
        }

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
            {"by_schedule_time"_L1, false},
        }}
    };

    auto netReply = makeRequest(req, reply, query, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

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

QJsonArray MotisBackend::ivModes(const std::vector<IndividualTransport> &ivs) const
{
    // TODO allow external configuration of the duration limits and PPR profiles
    QJsonArray modes;
    for (const auto &iv : ivs) {
        if (iv.mode() == IndividualTransport::Walk && m_supportedModes.contains("FootPPR"_L1)) {
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
        if (iv.mode() == IndividualTransport::Bike && iv.qualifier() != IndividualTransport::Rent && m_supportedModes.contains("Bike"_L1)) {
            // TODO neither bike parking nor taking the bike on public transport is explicitly supported
            modes.push_back(QJsonObject{
                {"mode_type"_L1, "Bike"_L1},
                {"mode"_L1, QJsonObject{
                    {"max_duration"_L1, 900}, // TODO docs and fbs disagree on this
                }}
            });
        }
        if (iv.mode() == IndividualTransport::Car && iv.qualifier() != IndividualTransport::Park && iv.qualifier() != IndividualTransport::Rent && m_supportedModes.contains("Car"_L1)) {
            modes.push_back(QJsonObject{
                {"mode_type"_L1, "Car"_L1},
                {"mode"_L1, QJsonObject{
                    {"max_duration"_L1, 900}, // TODO docs and fbs disagree on this
                }}
            });
        }
        if (iv.mode() == IndividualTransport::Car && iv.qualifier() == IndividualTransport::Park && m_supportedModes.contains("CarParking"_L1)) {
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

struct {
    Line::Mode mode;
    uint8_t clasz;
} static constexpr const class_table[] = {
    { Line::Mode::Air, 0 },
    { Line::Mode::Boat, 11 },
    { Line::Mode::Bus, 10 },
    { Line::Mode::Coach, 3 },
    { Line::Mode::Ferry, 11 },
    { Line::Mode::Funicular, 9 },
    { Line::Mode::Funicular, 6 },
    { Line::Mode::LocalTrain, 6 },
    { Line::Mode::LocalTrain, 5 },
    { Line::Mode::LongDistanceTrain, 1 },
    { Line::Mode::LongDistanceTrain, 2 },
    { Line::Mode::LongDistanceTrain, 4 },
    { Line::Mode::Metro, 8 },
    { Line::Mode::RailShuttle, 6 },
    { Line::Mode::RapidTransit, 7 },
    { Line::Mode::Shuttle, 6 },
    { Line::Mode::Taxi, 12 },
    { Line::Mode::Train, 5 },
    { Line::Mode::Tramway, 9 },
    { Line::Mode::RideShare, 12 },
};

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

    const auto fromIntermodel = !m_supportedModes.empty() && !from.hasIdentifier(m_locationIdentifierType);
    const auto toIntermodal = !m_supportedModes.empty() && !to.hasIdentifier(m_locationIdentifierType);

    QJsonObject content{
        // TODO how can we make the ontrip start options available? OntripTrainStart in particular
        {"start_type"_L1, fromIntermodel ? "IntermodalPretripStart"_L1 : "PretripStart"_L1},
        {"start"_L1, QJsonObject{
            {fromIntermodel ? "position"_L1: "station"_L1, encodeLocation(from, m_locationIdentifierType, fromIntermodel)},
            {"interval"_L1, QJsonObject{
                {"begin"_L1, beginTime},
                {"end"_L1, endTime},
            }},
            {"min_connection_count"_L1, req.maximumResults()},
            {"extend_interval_earlier"_L1, expandEarlier},
            {"extend_interval_later"_L1, expandLater},
        }},
        {"start_modes"_L1, ivModes(startModes)},
        {"destination_type"_L1, toIntermodal ? "InputPosition"_L1 : "InputStation"_L1},
        {"destination"_L1, encodeLocation(to, m_locationIdentifierType, toIntermodal)},
        {"destination_modes"_L1, ivModes(destModes)},
        {"search_type"_L1, "Default"_L1},
        {"search_dir"_L1, req.dateTimeMode() == JourneyRequest::Departure ? "Forward"_L1 : "Backward"_L1},
        {"router"_L1, ""_L1}
    };

    if (const auto &lineModes = req.lineModes(); !lineModes.empty()) {
        std::vector<uint8_t> classes;
        classes.reserve(lineModes.size());
        for (auto lineMode : lineModes) {
            for (auto m : class_table) {
                if (m.mode == lineMode) {
                    classes.push_back(m.clasz);
                }
            }
        }

        std::sort(classes.begin(), classes.end());
        classes.erase(std::unique(classes.begin(), classes.end()), classes.end());
        QJsonArray a;
        std::copy(classes.begin(), classes.end(), std::back_inserter(a));
        content.insert("allowed_claszes"_L1, a);
    }

    QJsonObject query{
        {"destination"_L1, QJsonObject{
            {"type"_L1, "Module"_L1},
            {"target"_L1, "/intermodal"_L1}
        }},
        {"content_type"_L1, "IntermodalRoutingRequest"_L1},
        {"content"_L1, content}
    };

    auto netReply = makeRequest(req, reply, query, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply, nam]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        MotisParser p(m_locationIdentifierType);
        auto result = p.parseConnections(data);
        if (netReply->error() == QNetworkReply::NoError && !p.hasError()) {
            setPreviousRequestContext(reply, result.begin);
            setNextRequestContext(reply, result.end);
            if (!reply->request().includePaths()) {
                addResult(reply, this, std::move(result.journeys));
            } else {
                auto task = new MotisPathQueryTask(std::move(result.journeys), this, nam, reply);
                QObject::connect(task, &AbstractAsyncTask::finished, reply, [this, reply, task]() {
                    task->deleteLater();
                    addResult(reply, this, std::move(task->m_journeys));
                });
                task->start();
            }
        } else if (p.hasError()) {
            addError(reply, Reply::InvalidRequest, p.errorMessage());
        } else {
            addError(reply, Reply::NetworkError, netReply->errorString());
        }

    });

    return true;
}

template <typename Request>
QNetworkReply* MotisBackend::makeRequest(const Request &req, QObject *parent, const QJsonObject &query, QNetworkAccessManager *nam) const
{
    QNetworkRequest netReq(m_endpoint);
    applySslConfiguration(netReq);
    applyUserAgent(netReq);
    netReq.setHeader(QNetworkRequest::ContentTypeHeader, "application/json"_L1);
    const auto postData = QJsonDocument(query).toJson(QJsonDocument::Compact);
    logRequest(req, netReq, postData);
    auto netReply = nam->post(netReq, postData);
    netReply->setParent(parent);
    return netReply;
}

qint64 MotisBackend::encodeTime(const QDateTime &dt)
{
    // MOTIS uses 0 offset UNIX time stamps
    return dt.toTimeZone(QTimeZone::fromSecondsAheadOfUtc(0)).toSecsSinceEpoch();
}

MotisPathQueryTask::MotisPathQueryTask(std::vector<Journey> &&journey, const MotisBackend *backend, QNetworkAccessManager *nam, QObject *parent)
    : AsyncTask<void>(parent)
    , m_journeys(std::move(journey))
    , m_backend(backend)
    , m_nam(nam)
{
}

void MotisPathQueryTask::start()
{
    queryNext();
}

void MotisPathQueryTask::queryNext()
{
    for (; m_jnyIdx < m_journeys.size(); ++m_jnyIdx) {
        for (; m_secIdx < m_journeys[m_jnyIdx].sections().size(); ++m_secIdx) {
            const auto &section = m_journeys[m_jnyIdx].sections()[m_secIdx];
            if (!section.path().isEmpty() || section.distance() <= 10) {
                continue;
            }
            if (section.mode() == JourneySection::Walking && m_backend->m_supportedModes.contains("FootPPR"_L1)) {
                QJsonObject query{
                    {"destination"_L1, QJsonObject{
                        {"type"_L1, "Module"_L1},
                        {"target"_L1, "/ppr/route"_L1}
                    }},
                    {"content_type"_L1, "FootRoutingRequest"_L1},
                    {"content"_L1, QJsonObject{
                        {"start"_L1, QJsonObject{
                            {"lat"_L1, section.from().latitude()},
                            {"lng"_L1, section.from().longitude()},
                        }},
                        {"destinations"_L1, QJsonArray{{
                            QJsonObject{
                                {"lat"_L1, section.to().latitude()},
                                {"lng"_L1, section.to().longitude()},
                            },
                        }}},
                        {"include_edges"_L1, true}, // ### this doesn't actually seem to work?
                        {"include_path"_L1, true},
                        {"include_steps"_L1, true},
                        {"search_options"_L1, QJsonObject{
                            {"duration_limit"_L1, 1800}, // TODO
                            {"profile"_L1, "default"_L1}, // TODO
                        }},
                    }}
                };

                auto netReply = m_backend->makeRequest(JourneyRequest{}, this, query, m_nam);
                QObject::connect(netReply, &QNetworkReply::finished, this, [this, netReply]() {
                    const auto data = netReply->readAll();
                    m_backend->logReply(this, netReply, data);
                    MotisParser p(m_backend->m_locationIdentifierType);
                    const auto path = p.parsePPRPath(data);
                    if (netReply->error() == QNetworkReply::NoError && !p.hasError()) {
                        applyPath(path, JourneySection::Walking, IndividualTransport::Walk);
                        queryNext();
                    } else {
                        reportFinished();
                    }
                });
                return;
            }
            if (section.mode() == JourneySection::IndividualTransport) {
                const auto iv = section.individualTransport();
                if ((iv.mode() != IndividualTransport::Bike && iv.mode() != IndividualTransport::Car)
                 || (iv.mode() == IndividualTransport::Bike && !m_backend->m_supportedModes.contains("Bike"_L1))
                 || (iv.mode() == IndividualTransport::Car && !m_backend->m_supportedModes.contains("Car"_L1))) {
                     continue;
                }

                QJsonObject query{
                    {"destination"_L1, QJsonObject{
                        {"type"_L1, "Module"_L1},
                        {"target"_L1, "/osrm/via"_L1}
                    }},
                    {"content_type"_L1, "OSRMViaRouteRequest"_L1},
                    {"content"_L1, QJsonObject{
                        {"waypoints"_L1, QJsonArray{{
                            QJsonObject{
                                {"lat"_L1, section.from().latitude()},
                                {"lng"_L1, section.from().longitude()},
                            },
                            QJsonObject{
                                {"lat"_L1, section.to().latitude()},
                                {"lng"_L1, section.to().longitude()},
                            },
                        }}},
                        {"profile"_L1, iv.mode() == IndividualTransport::Bike ? "bike"_L1 : "car"_L1},
                    }}
                };

                auto netReply = m_backend->makeRequest(JourneyRequest{}, this, query, m_nam);
                QObject::connect(netReply, &QNetworkReply::finished, this, [this, netReply, iv]() {
                    const auto data = netReply->readAll();
                    m_backend->logReply(this, netReply, data);
                    MotisParser p(m_backend->m_locationIdentifierType);
                    const auto path = p.parseOSRMPath(data);
                    if (netReply->error() == QNetworkReply::NoError && !p.hasError()) {
                        applyPath(path, JourneySection::IndividualTransport, iv.mode());
                        queryNext();
                    } else {
                        reportFinished();
                    }
                });
                return;
            }
        }
        m_secIdx = 0;
    }

    reportFinished();
}

void MotisPathQueryTask::applyPath(const Path &path, JourneySection::Mode mode, IndividualTransport::Mode ivMode)
{
    // apply to the current section regardless, so we are guaranteed to progress here
    {
        auto &jny = m_journeys[m_jnyIdx];
        auto sections = std::move(jny.takeSections());
        auto &section = sections[m_secIdx];
        section.setPath(path);
        jny.setSections(std::move(sections));
        ++m_secIdx;
    }

    // apply to all exactly matching sections
    auto j = m_secIdx;
    for (auto i = m_jnyIdx; i <m_journeys.size(); ++i) {
        auto &jny = m_journeys[i];
        for (; j < jny.sections().size(); ++j) {
            if (jny.sections()[j].mode() == mode && (mode != JourneySection::IndividualTransport || jny.sections()[j].individualTransport().mode() == ivMode)
             && Location::distance(jny.sections()[j].from().latitude(), jny.sections()[j].from().longitude(), path.startPoint().y(), path.startPoint().x()) < 10
             && Location::distance(jny.sections()[j].to().latitude(), jny.sections()[j].to().longitude(), path.endPoint().y(), path.endPoint().x()) < 10) {
                auto sections = std::move(jny.takeSections());
                auto &section = sections[j];
                section.setPath(path);
                jny.setSections(std::move(sections));
            }
        }
        j = 0;
    }
}

#include "moc_motisbackend.cpp"
