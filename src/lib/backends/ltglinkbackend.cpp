/*
    SPDX-FileCopyrightText: 2023 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "ltglinkbackend.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTimeZone>

#include "journeyrequest.h"
#include "journeyreply.h"
#include "locationrequest.h"
#include "locationreply.h"
#include "datatypes/journey.h"

#include "localbackendutils.h"

using namespace KPublicTransport;

AbstractBackend::Capabilities LTGLinkBackend::capabilities() const
{
    return Secure;
}

bool LTGLinkBackend::needsLocationQuery(const Location &loc, QueryType type) const
{
    Q_UNUSED(type);
    return loc.identifier(QStringLiteral("ltglinkint")).isEmpty();
}

bool LTGLinkBackend::queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const
{
    if (m_stations.empty()) {
        QObject::disconnect(this, &LTGLinkBackend::newStationData, nullptr, nullptr);
        QObject::connect(this, &LTGLinkBackend::newStationData, this, [=, this]() {
                queryJourney(req, reply, nam);
            }, Qt::SingleShotConnection);
        const_cast<LTGLinkBackend *>(this)->downloadStationData(reply, nam);

        return true;
    }

    QUrl url(QStringLiteral("https://bilietas.ltglink.lt/api/v2021/en-gb/journeys/search"));
    QUrlQuery urlQuery;
    urlQuery.addQueryItem(QStringLiteral("departureDate"), req.dateTime().date().toString(Qt::ISODate));
    urlQuery.addQueryItem(QStringLiteral("currencyId"), QStringLiteral("CURRENCY.EUR"));
    urlQuery.addQueryItem(QStringLiteral("Passengers"), QStringLiteral("BONUS_SCHEME_GROUP.ADULT%2C1"));
    urlQuery.addQueryItem(QStringLiteral("OriginStopId"), req.from().identifier(QStringLiteral("ltglinkint")));
    urlQuery.addQueryItem(QStringLiteral("DestinationStopId"), req.to().identifier(QStringLiteral("ltglinkint")));
    url.setQuery(urlQuery);

    auto netReply = nam->get(QNetworkRequest(url));
    connect(netReply, &QNetworkReply::finished, this, [=, this]() {
        const auto bytes = netReply->readAll();

        auto jsonValue = QJsonDocument::fromJson(bytes);

        const auto journeysJson = jsonValue[u"Journeys"].toArray();
        std::vector<Journey> journeys;
        for (const auto &j : journeysJson) {
            auto sectionsJson = j[u"Legs"].toArray();

            std::vector<JourneySection> sections;
            for (const auto sectionJson : sectionsJson) {
                auto originId = sectionJson[u"Origin"][u"Stop"][u"Id"].toInt();
                auto originTimeZone = QTimeZone(sectionJson[u"Origin"][u"TimeZone"].toString().toUtf8());

                auto actualDepartureTime = QDateTime::fromString(sectionJson[u"Origin"][u"ActualDepartureDateTime"].toString(), Qt::ISODate);
                actualDepartureTime.setTimeZone(originTimeZone);
                auto scheduledDepartureTime = QDateTime::fromString(sectionJson[u"Origin"][u"PlannedDepartureDateTime"].toString(), Qt::ISODate);
                scheduledDepartureTime.setTimeZone(originTimeZone);

                auto destinationId = sectionJson[u"Destination"][u"Stop"][u"Id"].toInt();
                auto destinationTimeZone = QTimeZone(sectionJson[u"Destination"][u"TimeZone"].toString().toUtf8());

                auto actualArrivalTime = QDateTime::fromString(sectionJson[u"Destination"][u"ActualArrivalDateTime"].toString(), Qt::ISODate);
                actualArrivalTime.setTimeZone(destinationTimeZone);
                auto scheduledArrivalTime = QDateTime::fromString(sectionJson[u"Destination"][u"PlannedArrivalDateTime"].toString(), Qt::ISODate);
                scheduledArrivalTime.setTimeZone(destinationTimeZone);

                // Filter out results that don't match the selected time frame
                if (!LocalBackendUtils::isInSelectedTimeframe(actualDepartureTime, actualArrivalTime, req)) {
                    continue;
                }

                auto lineNumber = sectionJson[u"Line"][u"Number"].toString();
                auto transportationType = sectionJson[u"Line"][u"TransportationType"][u"Id"].toString();

                Line line;
                line.setName(lineNumber);
                line.setMode(transportationType == u"LINE_TRANSPORTATION_TYPE.TRAIN" ? Line::Mode::Train : Line::Mode::Unknown);

                Route route;
                route.setLine(line);

                JourneySection section;
                section.setFrom(lookupStation(originId));
                section.setTo(lookupStation(destinationId));
                section.setScheduledDepartureTime(scheduledDepartureTime);
                section.setExpectedDepartureTime(actualDepartureTime);
                section.setScheduledArrivalTime(scheduledArrivalTime);
                section.setExpectedArrivalTime(actualArrivalTime);
                section.setMode(JourneySection::PublicTransport);
                section.setRoute(route);

                sections.push_back(std::move(section));
            }

            Journey journey;
            journey.setSections(std::move(sections));

            journeys.push_back(std::move(journey));
        }

        addResult(reply, this, std::move(journeys));

        netReply->deleteLater();
    });

    return true;
}

bool LTGLinkBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if (m_stations.empty()) {
        QObject::disconnect(this, &LTGLinkBackend::newStationData, nullptr, nullptr);
        QObject::connect(this, &LTGLinkBackend::newStationData, this, [=, this]() {
                queryLocation(req, reply, nam);
            }, Qt::SingleShotConnection);
        const_cast<LTGLinkBackend *>(this)->downloadStationData(reply, nam);

        return true;
    }

    std::vector<Location> locations;
    QString name = LocalBackendUtils::makeSearchableName(req.name());

    for (auto [id, station] : std::as_const(m_stations)) {
        if (station.searchableName.contains(name)) {
            auto loc = stationToLocation(station);
            locations.push_back(std::move(loc));
        }
    }

    addResult(reply, std::move(locations));

    return false;
}

void LTGLinkBackend::downloadStationData(Reply *reply, QNetworkAccessManager *nam)
{
    QUrl url(QStringLiteral("https://cms.ltglink.turnit.com/api/turnit/search"));
    QUrlQuery urlQuery;
    urlQuery.addQueryItem(QStringLiteral("locale"), QLocale::languageToCode(QLocale().language()));
    url.setQuery(urlQuery);

    auto *netReply = nam->get(QNetworkRequest(url));
    QObject::connect(netReply, &QNetworkReply::finished, this, [=, this]() {
        const auto bytes = netReply->readAll();

        logReply(reply, netReply, bytes);

        if (!m_stations.empty()) {
            return;
        }

        const auto jsonValue = QJsonDocument::fromJson(bytes);

        const auto countries = jsonValue[u"Stops"][u"Countries"].toArray();
        for (const auto &country : countries) {
            const auto cities = country[u"Cities"].toArray();
            for (const auto &city : cities) {
                const auto stations = city[u"BusStops"].toArray();

                for (const auto &station : stations) {
                    m_stations.insert({
                        station[u"BusStopId"].toInt(),
                        LTGLink::Station {
                            .id = station[u"BusStopId"].toInt(),
                            .name = station[u"BusStopName"].toString(),
                            .searchableName = LocalBackendUtils::makeSearchableName(station[u"BusStopName"].toString()),
                            .latitude = float(station[u"Coordinates"][u"Latitude"].toDouble()),
                            .longitude = float(station[u"Coordinates"][u"Longitude"].toDouble())
                        }
                    });
                }
            }
        }

        Q_EMIT newStationData();
    });
}

Location LTGLinkBackend::stationToLocation(const LTGLink::Station &station)
{
    Location loc;
    loc.setCoordinate(station.latitude, station.longitude);
    loc.setIdentifier(QStringLiteral("ltglinkint"), QString::number(station.id));
    loc.setName(station.name);
    loc.setType(Location::Stop);
    return loc;
}

Location LTGLinkBackend::lookupStation(int ltglinkint) const
{
    const auto &station = m_stations.at(ltglinkint);
    return stationToLocation(station);
}
