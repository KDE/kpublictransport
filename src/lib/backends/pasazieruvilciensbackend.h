/*
    SPDX-FileCopyrightText: 2023 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include "abstractbackend.h"
#include "datatypes/stopover.h"
#include "datatypes/journey.h"

namespace KPublicTransport {

struct Station {
    qint64 id;
    QString name;
    QString searchableName;
    float latitude;
    float longitude;
};

class PendingQuery : public QObject {
    Q_OBJECT

public:
    Q_SIGNAL void finished();

    std::optional<std::vector<Journey>> results;

    void reportFinished(std::vector<Journey> &&journeys) {
        results = std::move(journeys);
        Q_EMIT finished();
    }
};


class PasazieruVilciensBackend : public QObject, public AbstractBackend {
    Q_OBJECT

public:
    PasazieruVilciensBackend();

    static inline constexpr const char* type() { return "pv"; }
    Capabilities capabilities() const override;
    bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    bool queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const override;
    bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;

    Q_SIGNAL void newStationData();

private:
    void downloadStationData(Reply *reply, QNetworkAccessManager *nam);

    /// Single-line trips
    std::shared_ptr<PendingQuery> fetchTrip(const JourneyRequest &req, QNetworkAccessManager *nam) const;

    /// trips containing transfers
    std::shared_ptr<PendingQuery> fetchJoinedTrip(const JourneyRequest &req, QNetworkAccessManager *nam) const;

    static Location stationToLocation(const Station &station);
    Location lookupStation(int pvint) const;

    /// parses stopovers from json objects
    std::vector<Stopover> parseStopovers(std::vector<QJsonObject> &&stops, const QDateTime &startTime) const;

    /// filters unsupported objects and drops stops that are
    /// before the departure station or after the destination
    std::vector<QJsonObject> prepareStops(QJsonArray &&data) const;

    /// Splits the list of json stops at the transfer point
    std::tuple<std::vector<QJsonObject>, std::vector<QJsonObject>> splitJoinedSections(QJsonArray &&data) const;

    /// Parses a time from "12:30" into a QDateTime, given a date
    QDateTime parseDateTime(const QString &time, const QDate &date) const;

    /// Removes all accents from a string, and converts it to lowercase
    static QString makeSearchableName(const QString &name);

    std::map<int, Station> m_stations;
};

}
