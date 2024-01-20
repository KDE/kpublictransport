/*
    SPDX-FileCopyrightText: 2024 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "zpcgbackend.h"

#include <QUrl>
#include <QUrlQuery>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>

#include <array>

#include "datatypes/location.h"
#include "datatypes/stopover.h"
#include "locationrequest.h"
#include "locationreply.h"
#include "journeyreply.h"
#include "journeyrequest.h"
#include "localbackendutils.h"
#include "networkreplycollection.h"
#include "logging.h"

using namespace KPublicTransport::LocalBackendUtils;
using namespace KPublicTransport;

AbstractBackend::Capabilities ZPCGBackend::capabilities() const
{
    return Secure;
}

bool KPublicTransport::ZPCGBackend::needsLocationQuery(const Location &loc, QueryType type) const
{
    Q_UNUSED(type);
    return loc.identifier(identifierName()).isEmpty();
}

bool KPublicTransport::ZPCGBackend::queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    // Ignore requests for which we don't have the needed identifier
    if (request.from().identifier(identifierName()).isEmpty() || request.to().identifier(identifierName()).isEmpty()) {
        return false;
    }

    if (m_stations.empty()) {
        if (!m_fetchStationsTask) {
            auto mutThis = const_cast<ZPCGBackend *>(this);
            mutThis->m_fetchStationsTask = mutThis->downloadStationData(reply, nam);
        }

        connect(m_fetchStationsTask, &AbstractAsyncTask::finished, reply, [=, this]() {
            queryJourney(request, reply, nam);
        });

        return true;
    }

    QUrl url = baseUrl();
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("r"), QStringLiteral("api/search"));
    query.addQueryItem(QStringLiteral("from"), request.from().identifier(identifierName()));
    query.addQueryItem(QStringLiteral("to"), request.to().identifier(identifierName()));
    query.addQueryItem(QStringLiteral("date"), request.dateTime().date().toString(QStringLiteral("yyyy-MM-dd")));
    url.setQuery(query);

    auto netReply = nam->get(QNetworkRequest(url));
    connect(netReply, &QNetworkReply::finished, reply, [=, this]() {
        auto data = netReply->readAll();
        auto doc = QJsonDocument::fromJson(data);
        const auto journeysJson = doc.array();

        logReply(reply, netReply, data);

        if (journeysJson.empty()) {
            addResult(reply, this, std::vector<Journey>());
        }

        std::vector<QNetworkReply *> replies;
        auto journeys = std::make_shared<std::vector<Journey>>();

        for (const auto &journeyJson : journeysJson) {
            const QString from = journeyJson[u"f"].toString();
            const QString to = journeyJson[u"t"].toString();

            const auto journeyJsonArray = journeyJson[u"s"].toArray();
            for (const auto &something : journeyJsonArray) {
                const QString timetableId = something[u"i"].toString();
                const QString trainNumber = something[u"n"].toString();
                const QString trainType = something[u"t"].toString();

                auto departureTime = parseDateTime(something[u"d"].toString(), request.dateTime().date());
                auto arrivalTime = parseDateTime(something[u"a"].toString(), request.dateTime().date(), departureTime);

                if (!LocalBackendUtils::isInSelectedTimeframe(departureTime, arrivalTime, request)) {
                    continue;
                }

                QUrl url = baseUrl();
                QUrlQuery query;
                query.addQueryItem(QStringLiteral("r"), QStringLiteral("api/details"));
                query.addQueryItem(QStringLiteral("timetable"), timetableId);
                query.addQueryItem(QStringLiteral("locale"), preferredLanguage());
                url.setQuery(query);

                auto netReply = nam->get(QNetworkRequest(url));
                replies.push_back(netReply);

                connect(netReply, &QNetworkReply::finished, reply, [=, this]() {
                    auto data = netReply->readAll();
                    auto doc = QJsonDocument::fromJson(data);
                    const auto detailsJson = doc.array();

                    logReply(reply, netReply, data);

                    for (const auto &resultJson : detailsJson) {
                        const auto routeJson = resultJson[u"d"].toArray();

                        Journey journey;

                        Line line;
                        line.setName(trainNumber);
                        line.setMode(matchTrainType(trainType));

                        Route route;
                        route.setLine(line);

                        if (!routeJson.empty()) {
                            route.setDestination(stationToLocation(routeJson.last()[u"s"].toString()));
                        }

                        JourneySection section;
                        section.setMode(JourneySection::PublicTransport);
                        section.setFrom(stationToLocation(from));
                        section.setTo(stationToLocation(to));
                        section.setRoute(route);

                        std::vector<Stopover> stopovers;


                        bool inRoute = false;

                        QDateTime previousDateTime;
                        for (const auto &stopoverJson : routeJson) {
                            const auto name = stopoverJson[u"s"].toString();

                            if (name == to) {
                                auto arrivalTime = parseDateTime(stopoverJson[u"a"].toString(), request.dateTime().date(), previousDateTime);
                                previousDateTime = arrivalTime;
                                section.setScheduledArrivalTime(arrivalTime);
                                inRoute = false;
                            }

                            if (inRoute) {
                                auto location = stationToLocation(name);

                                auto arrivalTime = parseDateTime(stopoverJson[u"a"].toString(), request.dateTime().date(), previousDateTime);
                                previousDateTime = arrivalTime;
                                auto departureTime = parseDateTime(stopoverJson[u"d"].toString(), request.dateTime().date(), previousDateTime);
                                previousDateTime = departureTime;

                                Stopover stopover;
                                stopover.setStopPoint(location);
                                stopover.setScheduledArrivalTime(arrivalTime);
                                stopover.setScheduledDepartureTime(departureTime);

                                stopovers.push_back(std::move(stopover));
                            }

                            if (name == from) {
                                auto departureTime = parseDateTime(stopoverJson[u"d"].toString(), request.dateTime().date());
                                previousDateTime = departureTime;
                                section.setScheduledDepartureTime(departureTime);
                                inRoute = true;
                            }
                        }

                        section.setIntermediateStops(std::move(stopovers));
                        journey.setSections({section});
                        journeys->push_back(std::move(journey));
                    }
                });
            }
        }

        auto *allReplies = new NetworkReplyCollection(replies);
        connect(allReplies, &NetworkReplyCollection::allFinished, reply, [=, this]() {
            allReplies->deleteLater();

            addResult(reply, this, std::move(*journeys));

            Attribution osmAttribution;
            osmAttribution.setLicense(QStringLiteral("ODbL"));
            osmAttribution.setLicenseUrl(QUrl(QStringLiteral("https://opendatacommons.org/licenses/odbl/")));
            osmAttribution.setName(QStringLiteral("OpenStreetMap®"));
            osmAttribution.setUrl(QUrl(QStringLiteral("https://www.openstreetmap.org")));

            Attribution attribution;
            attribution.setName(QStringLiteral("ŽPCG"));
            attribution.setUrl(QUrl(QStringLiteral("https://www.zcg-prevoz.me")));

            addAttributions(reply, {attribution, osmAttribution});
        });
        connect(allReplies, &NetworkReplyCollection::errorOccured, reply, [=, this]() {
            addError(reply, Reply::NetworkError, netReply->errorString());
        });
    });

    connect(netReply, &QNetworkReply::errorOccurred, reply, [=, this]() {
        addError(reply, Reply::NetworkError, netReply->errorString());
    });

    return true;
}

bool KPublicTransport::ZPCGBackend::queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if (m_stations.empty()) {
        if (!m_fetchStationsTask) {
            auto mutThis = const_cast<ZPCGBackend *>(this);
            mutThis->m_fetchStationsTask = mutThis->downloadStationData(reply, nam);
        }

        connect(m_fetchStationsTask, &AbstractAsyncTask::finished, reply, [=, this]() {
            queryLocation(request, reply, nam);
        });

        return true;
    }

    std::vector<Location> locations;

    const auto searchableName = makeSearchableName(request.name());
    for (const auto &[name, station] : m_stations) {
        if (name.contains(searchableName) && !station->idName.isEmpty()) {
            auto location = stationToLocation(name);
            locations.push_back(std::move(location));
        }
    }

    addResult(reply, std::move(locations));

    return false;
}

QDateTime KPublicTransport::ZPCGBackend::parseDateTime(const QString &timeString, const QDate &date, const QDateTime &knownPreviousTime) const
{
    auto time = QTime::fromString(timeString);

    auto dateTime = date.startOfDay();
    dateTime.setTime(time);
    dateTime.setTimeZone(QTimeZone("Europe/Podgorica"));

    if (!knownPreviousTime.isNull() && dateTime < knownPreviousTime) {
        dateTime.setDate(dateTime.date().addDays(1));
    }

    return dateTime;
}

std::map<QString, std::shared_ptr<ZPCG::Station>> KPublicTransport::ZPCGBackend::loadAuxStationData()
{
    QFile file(QStringLiteral(":/org.kde.kpublictransport/networks/stations/me-rs.json"));
    if (!file.open(QFile::ReadOnly)) {
        qCWarning(Log) << file.errorString();
        qFatal("The bundled station data of KPublicTransport can not be read. This is a bug.");
    }

    const auto stationsJson = QJsonDocument::fromJson(file.readAll()).array();
    std::map<QString, std::shared_ptr<ZPCG::Station>> stations;
    for (const auto &stationJson : stationsJson) {
        auto stationJsonObject = stationJson.toObject();

        // OSM name tags in different languages.
        // They will be tried from first to last.
        std::vector<QString> keyPrecedence = {
            QString(u"name:" % preferredLanguage()),
            QStringLiteral(u"name:en"),
            QStringLiteral(u"alt_name:en"),
            QStringLiteral(u"name:sr-Latn"),
            QStringLiteral(u"name"),
            QStringLiteral(u"alt_name"),
            QStringLiteral(u"name:sr")
        };

        auto findName = [=]() {
            for (const auto &key : keyPrecedence) {
                if (stationJsonObject.contains(key)) {
                    return stationJsonObject[key].toString();
                }
            }

            return QString();
        };

        auto stationName = findName();

        ZPCG::Station station {
            .name = stationName,
            .idName = QString(), // Will be replaced with timetable names after http request finishes
            .latitude = float(stationJson[u"longitude"].toDouble()),
            .longitude = float(stationJson[u"latitude"].toDouble())
        };

        auto sharedStation = std::make_shared<ZPCG::Station>(std::move(station));

        // Add search links for all considered languages
        for (const auto &key : keyPrecedence) {
            if (stationJsonObject.contains(key)) {
                stations.insert({makeSearchableName(stationJsonObject[key].toString()), sharedStation});
            }
        }
    }

    return stations;
}

KPublicTransport::AsyncTask<void> *KPublicTransport::ZPCGBackend::downloadStationData(Reply *reply, QNetworkAccessManager *nam)
{
    auto task = new AsyncTask<void>(this);

    QUrl url = baseUrl();
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("r"), QStringLiteral("api/stations"));
    query.addQueryItem(QStringLiteral("locale"), QStringLiteral("sr"));
    url.setQuery(query);

    auto netReply = nam->get(QNetworkRequest(url));
    connect(netReply, &QNetworkReply::finished, reply, [=, this]() {
        const auto array = QJsonDocument::fromJson(netReply->readAll()).array();

        m_stations = loadAuxStationData();

        for (const auto &nameJson : array) {
            const auto searchName = makeSearchableName(nameJson.toString());

            if (m_stations.contains(searchName)) {
                m_stations.at(searchName)->idName = nameJson.toString(); // Use the official names
            } else {
                qCWarning(Log) << "Missing station data for" << searchName << ".";
                qCWarning(Log) << "To fix this, look for the station on OpenStreetMap,"
                               << "fix its properties and regenerate the data in lib/networks/stations/";
                qCWarning(Log) << "Usually, the issue is a name mismatch, or the railway=station property being set"
                               << "on the station building instead of as a point";
            }
        }

        task->reportFinished();
    });

    return task;
}

KPublicTransport::Location KPublicTransport::ZPCGBackend::stationToLocation(const QString &name) const
{
    auto searchableName = makeSearchableName(name);

    Location loc;

    if (m_stations.contains(searchableName)) {
        auto station = m_stations.at(searchableName);

        loc.setName(station->name);
        loc.setLatitude(station->latitude);
        loc.setLongitude(station->longitude);
        if (!station->idName.isEmpty()) {
            loc.setIdentifier(identifierName(), station->idName);
        }
    } else {
        loc.setName(name);
        loc.setIdentifier(identifierName(), name);
    }

    loc.setType(Location::Stop);

    return loc;
}

KPublicTransport::Line::Mode KPublicTransport::ZPCGBackend::matchTrainType(QStringView trainType)
{
    if (trainType == u"fast") {
        return Line::LongDistanceTrain;
    } else if (trainType == u"local") {
        return Line::LocalTrain;
    }

    return Line::Train;
}

QUrl KPublicTransport::ZPCGBackend::baseUrl() const
{
    return QUrl(QStringLiteral("https://zpcg.me/"));
}

QString KPublicTransport::ZPCGBackend::identifierName() const
{
    return QStringLiteral("zpcgname");
}
