/*
    SPDX-FileCopyrightText: 2024 Jonah Brüchert <jbb@kaidan.im>
    SPDX-FileCopyrightText: 2024 Stefan Vesovic <asphyxia@spline.de>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "srbijavozbackend.h"

#include "datatypes/location.h"
#include "datatypes/stopover.h"
#include "locationrequest.h"
#include "logging.h"
#include "localbackendutils.h"
#include "locationreply.h"
#include "locationrequest.h"
#include "journeyreply.h"
#include "standardpaths_p.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

#include <memory>

using namespace Qt::Literals::StringLiterals;

using namespace KPublicTransport;

SrbijavozBackend::SrbijavozBackend() = default;

AbstractBackend::Capabilities SrbijavozBackend::capabilities() const
{
    return Secure;
}

bool SrbijavozBackend::needsLocationQuery(const Location &loc, QueryType type) const
{
    Q_UNUSED(type);
    return loc.identifier(identifierName()).isEmpty();
}

bool SrbijavozBackend::queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    // Ignore requests for which we don't have the needed identifier
    if (request.from().identifier(identifierName()).isEmpty() || request.to().identifier(identifierName()).isEmpty()) {
        return false;
    }

    if (m_stationsById.empty()) {
        if (!m_fetchStationsTask) {
            auto mutThis = const_cast<SrbijavozBackend *>(this);
            mutThis->m_fetchStationsTask = mutThis->downloadStationData(reply, nam);
        }

        QObject::connect(m_fetchStationsTask, &AbstractAsyncTask::finished, reply, [=, this]() {
            queryJourney(request, reply, nam);
        });

        return true;
    }

    QUrl url(u"https://webapi1.srbvoz.rs/ekarta/api/listavozova/ListaVozova_Web"_s);

    QUrlQuery query;
    query.addQueryItem(u"stanicaod"_s, request.from().identifier(identifierName()));
    query.addQueryItem(u"stanicado"_s, request.to().identifier(identifierName()));
    query.addQueryItem(u"datum"_s, request.dateTime().date().toString(QStringLiteral("MM-dd-yyyy")));
    query.addQueryItem(u"brojputnika"_s, QString::number(1));
    query.addQueryItem(u"razred"_s, QString::number(2));

    url.setQuery(query);

    auto netReply = nam->get(QNetworkRequest(url));
    QObject::connect(netReply, &QNetworkReply::finished, reply, [=, this] {
        auto bytes = netReply->readAll();
        auto connections = QJsonDocument::fromJson(bytes).array();

        std::vector<Journey> journeys;
        for (auto train : connections) {
            int startId = train[u"odsifra"].toInt();
            int endId = train[u"dosifra"].toInt();
            QString departureTimeString = train[u"vremep"].toString();
            QString arrivalTimeString = train[u"vremed"].toString();
            int trainNumber = train[u"brvoz"].toInt();

            QString notes;
            if (preferredLanguage() == u"sr") {
                notes = train[u"napomena"].toString().trimmed();
            } else {
                notes = train[u"napomenaE"].toString().trimmed();
            }

            auto departureTime = parseDateTime(departureTimeString, request.dateTime().date());
            auto arrivalTime = parseDateTime(arrivalTimeString, request.dateTime().date(), departureTime);

            const auto stops = train[u"etTrasaVoza"].toArray();

            if (!LocalBackendUtils::isInSelectedTimeframe(departureTime, arrivalTime, request)) {
                continue;
            }

            Line line;
            line.setName(QString::number(trainNumber));
            line.setMode(Line::Train);

            Route route;
            route.setLine(line);

            if (!stops.empty()) {
                if (auto destinationId = stops.last()[u"sifrA_STANICE"].toInt(); m_stationsById.contains(destinationId)) {
                    route.setDestination(stationToLocation(*m_stationsById.at(destinationId)));
                }
            }

            Journey journey;

            JourneySection journeySection;
            journeySection.setFrom(stationToLocation(*m_stationsById.at(startId)));
            journeySection.setTo(stationToLocation(*m_stationsById.at(endId)));
            journeySection.setScheduledDepartureTime(departureTime);
            journeySection.setScheduledArrivalTime(arrivalTime);
            journeySection.setMode(JourneySection::PublicTransport);

            if (!notes.isEmpty()) {
                journeySection.setNotes(QList<QString>{notes});
            }

            std::vector<Stopover> stopovers;

            bool inRoute = false;
            QDateTime mostRecentTime = departureTime;
            for (const auto &stopover : stops) {
                int stationId = stopover[u"sifrA_STANICE"].toInt();

                if (stationId == endId) {
                    inRoute = false;
                }

                if (inRoute) {
                    Stopover stop;

                    auto arrivalTime = parseDateTime(stopover[u"vremE_DOLASKA"].toString(), request.dateTime().date(), mostRecentTime);
                    mostRecentTime = arrivalTime;
                    auto departureTime = parseDateTime(stopover[u"vremE_POLASKA"].toString(), request.dateTime().date(), mostRecentTime);
                    mostRecentTime = departureTime;

                    stop.setScheduledArrivalTime(arrivalTime);
                    stop.setScheduledDepartureTime(arrivalTime);
                    stop.setStopPoint(stationToLocation(*m_stationsById.at(stationId)));
                    stopovers.push_back(std::move(stop));
                }

                if (stationId == startId) {
                    inRoute = true;
                }
            }

            journeySection.setIntermediateStops(std::move(stopovers));
            journeySection.setRoute(route);

            journey.setSections({journeySection});

            journeys.push_back(std::move(journey));
        }

        bool isEmpty = journeys.empty();

        addResult(reply, this, std::move(journeys));

        if (!isEmpty) {
            Attribution osmAttribution;
            osmAttribution.setLicense(QStringLiteral("ODbL"));
            osmAttribution.setLicenseUrl(QUrl(QStringLiteral("https://opendatacommons.org/licenses/odbl/")));
            osmAttribution.setName(QStringLiteral("OpenStreetMap®"));
            osmAttribution.setUrl(QUrl(QStringLiteral("https://www.openstreetmap.org")));

            Attribution attribution;
            attribution.setName(QStringLiteral("Srbija Voz"));
            attribution.setUrl(QUrl(QStringLiteral("https://srbijavoz.rs")));

            addAttributions(reply, {attribution, osmAttribution});
        }
    });

    QObject::connect(netReply, &QNetworkReply::errorOccurred, reply, [=, this]() {
        addError(reply, Reply::NetworkError, netReply->errorString());
    });

    return true;
}

bool SrbijavozBackend::queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if (m_stationsById.empty()) {
        if (!m_fetchStationsTask) {
            auto mutThis = const_cast<SrbijavozBackend *>(this);
            mutThis->m_fetchStationsTask = mutThis->downloadStationData(reply, nam);
        }

        QObject::connect(m_fetchStationsTask, &AbstractAsyncTask::finished, reply, [=, this]() {
            queryLocation(request, reply, nam);
        });

        return true;
    }

    std::vector<Location> locations;

    const auto searchableName = makeSearchableName(request.name());
    for (const auto &[name, station] : m_stationsBySearchName) {
        if (name == searchableName) {
            auto location = stationToLocation(*station);

            // Skip stations that we don't have an identifier for
            // Those would be coming from OSM data when a station is either not used by Srb Voz,
            // or not correctly matched
            if (!location.identifier(identifierName()).isEmpty()) {
                locations.push_back(std::move(location));
            }
        }
    }

    addResult(reply, std::move(locations));

    return false;
}

void SrbijavozBackend::loadAuxData()
{
    QFile file(StandardPaths::locateFile(u"networks/stations/me-rs.json"_s));
    if (!file.open(QFile::ReadOnly)) {
        qCWarning(Log) << file.errorString();
        qFatal("The bundled station data of KPublicTransport can not be read. This is a bug.");
    }

    const auto stationsJson = QJsonDocument::fromJson(file.readAll()).array();
    std::unordered_map<int, std::shared_ptr<SrbStation>> stationsById;
    std::unordered_map<QString, std::shared_ptr<SrbStation>> stationsBySearchName;
    for (const auto &stationJson : stationsJson) {
        auto stationJsonObject = stationJson.toObject();

        // OSM name tags in different languages.
        // They will be tried from first to last.
        std::vector<QString> keyPrecedence = {
            u"name:" % preferredLanguage(),
            u"int_name"_s,
            u"name:en"_s,
            u"alt_name:en"_s,
            u"name:sr-Latn"_s,
            u"name"_s,
            u"alt_name"_s,
            u"name:sr"_s
        };

        auto findName = [=]() {
            for (const auto &key : keyPrecedence) {
                if (stationJsonObject.contains(key)) {
                    if (auto name = stationJsonObject[key].toString(); !name.isEmpty()) {
                        return name;
                    }
                }
            }

            return QString();
        };

        auto stationName = findName();

        SrbStation station {
            .name = stationName,
            .longitude = float(stationJson[u"latitude"].toDouble()),
            .latitude = float(stationJson[u"longitude"].toDouble()),
            .id = -1
        };

        auto sharedStation = std::make_shared<SrbStation>(std::move(station));

        // Add search links for all considered languages
        for (const auto &key : keyPrecedence) {
            if (stationJsonObject.contains(key)) {
                stationsBySearchName.insert({makeSearchableName(stationJsonObject[key].toString()), sharedStation});
            }
        }
    }

    m_stationsBySearchName = std::move(stationsBySearchName);
}

void SrbijavozBackend::applyStationQuirks()
{
    auto addMapping = [&](const QString &from, QString to) {
        to = makeSearchableName(to);
        if (!m_stationsBySearchName.contains(to)) {
            qCWarning(Log) << "srbijavoz: Error in manual mapping from" << from << "to" << to;
            return;
        }

        auto station = m_stationsBySearchName.at(to);
        m_stationsBySearchName.insert({makeSearchableName(from), station});
    };

    // Stations of which we can't easily normalize the spelling
    addMapping(u"Kos Mitrovica Sever"_s, u"Kosovska Mitrovica Sever"_s);
    addMapping(u"Ban.milosevo Polje"_s, u"Banatsko Milosevo"_s);
    addMapping(u"Subotica Predgrade"_s, u"Subotica predgrađe"_s);
    addMapping(u"Skenderovo"_s, u"Skenderevo"_s);
    addMapping(u"Gugalj"_s, u"Гугаљ"_s);
    addMapping(u"Donje Jerinje"_s, u"Jarinjë"_s);
    addMapping(u"Jerina"_s, u"Jarinjë"_s);
    addMapping(u"Brvenik"_s, u"Brevnik"_s);
    addMapping(u"Palanka"_s, u"Smederevska Palanka"_s);
    addMapping(u"Petrovac-glozan"_s, u"Bački Petrovac - Gložan"_s);
    addMapping(u"Osipaonica Stajali."_s, u"Osipaonica staјalište"_s);
    addMapping(u"Pancevo Gl.stanica"_s, u"Pančevo glavna"_s);
    addMapping(u"Resnik Kragujev."_s, u"Resnik Kragujevački"_s);
    addMapping(u"Karlovacki Vinograd"_s, u"Karlovački vinogradi"_s);

    // That one station that I'm not sure enough to add it to OSM
    m_stationsBySearchName.insert({makeSearchableName(u"Subotica Javna Skl."_s), std::make_shared<SrbStation>(SrbStation {
        .name = u"Subotica Javna Skladista"_s,
        .longitude = 19.696104,
        .latitude = 46.094215,
        .id = -1
    })});
}

AsyncTask<void> *SrbijavozBackend::downloadStationData(Reply *reply, QNetworkAccessManager *nam)
{
    loadAuxData();
    applyStationQuirks();

    auto *task = new AsyncTask<void>(reply);

    const QUrl url(u"https://webapi1.srbvoz.rs/ekarta/api/stanica"_s);
    auto netReply = nam->get(QNetworkRequest(url));
    QObject::connect(netReply, &QNetworkReply::finished, reply, [=, this] {
        auto bytes = netReply->readAll();

        auto stationsJson = QJsonDocument::fromJson(bytes).array();
        for (auto stationJson : stationsJson) {
            QString stationName = stationJson[u"naziv"].toString();
            uint32_t stationId = stationJson[u"sifra"].toInt();

            QString searchName = makeSearchableName(stationName);
            if (!m_stationsBySearchName.contains(searchName)) {
                qCWarning(Log) << "Missing station data for" << stationName << ".";
                qCWarning(Log) << "To fix this, look for the station on OpenStreetMap,"
                               << "fix its properties and regenerate the data in lib/networks/stations/";
                qCWarning(Log) << "Usually, the issue is a name mismatch. If the name used by Srbijavoz can not be added"
                                  "to OSM, you can add a mapping in the backend.";

                SrbStation station;
                station.id = int(stationId);
                station.name = stationName;

                auto sharedStation = std::make_shared<SrbStation>(std::move(station));
                m_stationsBySearchName.insert({searchName, sharedStation});
                m_stationsById.insert({station.id, sharedStation});

                continue;
            }

            auto &station = m_stationsBySearchName.at(searchName);
            station->id = int(stationId);

            m_stationsById.insert({int(stationId), station});
        }

        task->reportFinished();
    });

    return task;
}

Location SrbijavozBackend::stationToLocation(const SrbStation &station) const
{
    Location loc;
    if (station.latitude != NAN && station.longitude != NAN) {
        loc.setLatitude(station.latitude);
        loc.setLongitude(station.longitude);
    } else {
        // So we have at least some knowledge of the position
        loc.setCountry(u"Serbia"_s);
    }
    loc.setName(station.name);
    loc.setType(Location::Stop);

    if (station.id != -1) {
        loc.setIdentifier(identifierName(), QString::number(station.id));
    }

    return loc;
}

QString SrbijavozBackend::makeSearchableName(QString name) const
{
    auto out = LocalBackendUtils::makeSearchableName(
        name.replace(QRegularExpression(QStringLiteral("station|halt")), QString()));

    auto normalizeEnd = [&](QStringView end, QStringView normalizedEnd) {
        if (out.endsWith(end)) {
            out = out.mid(0, out.size() - end.size()) % normalizedEnd;
        }
    };

    normalizeEnd(u"ce", u"ca");
    normalizeEnd(u"ci", u"c");
    normalizeEnd(u"je", u"ja");
    normalizeEnd(u".", u"");

    return out;
}

QString SrbijavozBackend::identifierName() const
{
    return u"srbvozid"_s;
}

QDateTime SrbijavozBackend::parseDateTime(const QString &timeString, const QDate &date, const QDateTime &knownPreviousTime) const
{
    auto time = QTime::fromString(timeString.trimmed());

    auto dateTime = date.startOfDay();
    dateTime.setTime(time);
    dateTime.setTimeZone(QTimeZone("Europe/Belgrade"));

    if (!knownPreviousTime.isNull() && dateTime < knownPreviousTime) {
        dateTime.setDate(dateTime.date().addDays(1));
    }

    return dateTime;
}
