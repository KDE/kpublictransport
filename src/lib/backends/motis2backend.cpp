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
        qDebug().noquote() << data << netReply->error();

        Motis2Parser p(m_locationIdentifierType);
        auto result = p.parseLocations(data);
        filterLocations(result, reply->request().types());

        if (netReply->error() == QNetworkReply::NoError) {
            // TODO handle result.empty()?
            // Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), result, {});
            addResult(reply, std::move(result));
        } else {
            addError(reply, Reply::NetworkError, netReply->errorString());
        }
    });
    return true;
}

bool Motis2Backend::queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const
{
    QUrlQuery query;
    query.addQueryItem(u"date"_s, req.dateTime().toUTC().date().toString(u"MM-dd-yyyy"));
    query.addQueryItem(u"time"_s, req.dateTime().toUTC().time().toString(u"hh:mm"));
    query.addQueryItem(u"stopId"_s, req.stop().identifier(m_locationIdentifierType));
    query.addQueryItem(u"n"_s, QString::number(req.maximumResults()));
    query.addQueryItem(u"arriveBy"_s, req.mode() == StopoverRequest::QueryArrival ? u"true"_s : u"false"_s);
    if (const auto pageCursor = requestContextData(req).toString(); !pageCursor.isEmpty()) {
        query.addQueryItem(u"pageCursor"_s, pageCursor);
    }

    auto netReply = makeRequest(req, reply, "stoptimes"_L1, query, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        qDebug().noquote() << data << netReply->error();
        Motis2Parser p(m_locationIdentifierType);
        auto result = p.parseStopTimes(data);
        if (netReply->error() == QNetworkReply::NoError) {
            setNextRequestContext(reply, p.m_nextPageCursor);
            setPreviousRequestContext(reply, p.m_previousPageCursor);
            addResult(reply, this, std::move(result));
        } else {
            addError(reply, Reply::NetworkError, netReply->errorString());
        }
    });

    return true;
}

#if 0
QJsonArray Motis2Backend::ivModes(const std::vector<IndividualTransport> &ivs) const
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
#endif

[[nodiscard]] static QString encodeLocation(const Location &loc, const QString &locationIdentifierType)
{
    if (loc.hasCoordinate()) {
        return QString::number(loc.latitude()) + ','_L1 + QString::number(loc.longitude()) + ",0"_L1; // TODO level
    }
    return loc.identifier(locationIdentifierType);
}

bool Motis2Backend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
#if 0
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
#endif

    QUrlQuery query;
    query.addQueryItem(u"fromPlace"_s, encodeLocation(req.from(), m_locationIdentifierType));
    query.addQueryItem(u"toPlace"_s, encodeLocation(req.to(), m_locationIdentifierType));
    query.addQueryItem(u"date"_s, req.dateTime().toUTC().date().toString(u"MM-dd-yyyy"));
    query.addQueryItem(u"time"_s, req.dateTime().toUTC().time().toString(u"hh:mm"));
    // TODO mode
    query.addQueryItem(u"numItineraries"_s, QString::number(req.maximumResults()));
    if (const auto pageCursor = requestContextData(req).toString(); !pageCursor.isEmpty()) {
        query.addQueryItem(u"pageCursor"_s, pageCursor);
    }
    query.addQueryItem(u"arriveBy"_s, req.dateTimeMode() == JourneyRequest::Arrival ? u"true"_s : u"false"_s);

    auto netReply = makeRequest(req, reply, "plan"_L1, query, nam);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply, nam]() {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        qDebug().noquote() << data << netReply->error();
        Motis2Parser p(m_locationIdentifierType);
        auto result = p.parseItineraries(data);
        if (netReply->error() == QNetworkReply::NoError) {
            setPreviousRequestContext(reply, p.m_previousPageCursor);
            setNextRequestContext(reply, p.m_nextPageCursor);
            addResult(reply, this, std::move(result));
        } else {
            addError(reply, Reply::NetworkError, netReply->errorString());
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

#if 0
qint64 Motis2Backend::encodeTime(const QDateTime &dt)
{
    // MOTIS uses 0 offset UNIX time stamps
    return dt.toTimeZone(QTimeZone::fromSecondsAheadOfUtc(0)).toSecsSinceEpoch();
}

MotisPathQueryTask::MotisPathQueryTask(std::vector<Journey> &&journey, const Motis2Backend *backend, QNetworkAccessManager *nam, QObject *parent)
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
#endif

#include "moc_motis2backend.cpp"
