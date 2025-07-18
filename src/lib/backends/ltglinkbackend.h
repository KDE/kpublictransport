/*
    SPDX-FileCopyrightText: 2023 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QPointer>

#include "abstractbackend.h"

#include <map>

namespace KPublicTransport {

namespace LTGLink {
struct Station {
    int id;
    QString name;
    QString searchableName;
    float latitude;
    float longitude;
};
}

class LTGLinkBackend : public QObject, public AbstractBackend
{
    Q_OBJECT

public:
    static constexpr const char* type() { return "ltglink"; }
    [[nodiscard]] Capabilities capabilities() const override;
    [[nodiscard]] Location::Types supportedLocationTypes() const override;
    [[nodiscard]] bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    [[nodiscard]] bool queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;

private:
    AsyncTask<void> *downloadStationData(Reply *reply, QNetworkAccessManager *nam);

    static Location stationToLocation(const LTGLink::Station &station);
    [[nodiscard]] Location lookupStation(int ltglinkint) const;

    std::map<int, LTGLink::Station> m_stations;
    QPointer<AsyncTask<void>> m_stationDataTask = nullptr;
};

}
