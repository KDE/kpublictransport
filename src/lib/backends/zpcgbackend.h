/*
    SPDX-FileCopyrightText: 2024 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QObject>
#include <QPointer>

#include <unordered_map>

#include "backends/abstractbackend.h"
#include "datatypes/journey.h"


namespace KPublicTransport {

namespace ZPCG {
struct Station {
    QString name;
    QString idName;

    float latitude;
    float longitude;
};
}

class ZPCGBackend : public QObject, public AbstractBackend
{
    Q_OBJECT

public:
    static inline constexpr const char* type() { return "zpcg"; }

    Capabilities capabilities() const override;

    bool needsLocationQuery(const Location &loc, QueryType type) const override;

    bool queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const override;

    bool queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const override;

    QDateTime parseDateTime(const QString &timeString, const QDate &date, const QDateTime &knownPreviousTime = {}) const;

private:
    std::unordered_map<QString, std::shared_ptr<ZPCG::Station>> loadAuxStationData();

    /// Download the official station data, and use it to filter the local data.
    AsyncTask<void> *downloadStationData(Reply *reply, QNetworkAccessManager *nam);

    Location stationToLocation(const QString &searchableName) const;

    static Line::Mode matchTrainType(QStringView trainType);

    QUrl baseUrl() const;
    QString identifierName() const;

    std::unordered_map<QString, std::shared_ptr<ZPCG::Station>> m_stations;
    QPointer<AsyncTask<void>> m_fetchStationsTask = nullptr;
};

}
