/*
    SPDX-FileCopyrightText: 2023 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include "abstractbackend.h"
#include "datatypes/stopover.h"

namespace KPublicTransport {

struct Station {
    qint64 id;
    QString name;
    float latitude;
    float longitude;
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

    static Location stationToLocation(Station &&station);

    std::vector<Stopover> parseStopovers(std::vector<QJsonObject> &&stops, const QDateTime &startTime) const;

    std::map<int, Station> m_stations;
};

}
