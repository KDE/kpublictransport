/*
    SPDX-FileCopyrightText: 2024 Jonah Brüchert <jbb@kaidan.im>
    SPDX-FileCopyrightText: 2024 Stefan Vesovic <asphyxia@spline.de>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include "backends/abstractbackend.h"

#include <QPointer>

#include <unordered_map>

namespace KPublicTransport {


struct SrbStation {
    QString name;
    float longitude = NAN;
    float latitude = NAN;
    int id;
};

class SrbijavozBackend : public AbstractBackend
{
public:
    SrbijavozBackend();

    static constexpr const char* type() { return "srbijavoz"; }

    Capabilities capabilities() const override;
    [[nodiscard]] Location::Types supportedLocationTypes() const override;

    /** Returns whether or not a location query has to be performed for the given
     *  Location before doing departure or journey queries for it.
     */
    bool needsLocationQuery(const Location &loc, QueryType type) const override;

    /** Perform a journey query.
     *  @return @c true if performing an async operation, @c false otherwise.
     */
    bool queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const override;

    /** Perform a location query.
     *  @return @c true if performing an async operation, @c false otherwise.
     */
    bool queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const override;

private:
    void loadAuxData();
    void applyStationQuirks();

    AsyncTask<void> *downloadStationData(Reply *reply, QNetworkAccessManager *nam);

    QDateTime parseDateTime(const QString &timeString, const QDate &date, const QDateTime &knownPreviousTime = {}) const;

    Location stationToLocation(const KPublicTransport::SrbStation &station) const;

    QString makeSearchableName(QString name) const;

    QString identifierName() const;

    std::unordered_map<int, std::shared_ptr<SrbStation>> m_stationsById;
    std::unordered_map<QString, std::shared_ptr<SrbStation>> m_stationsBySearchName;

    QPointer<AsyncTask<void>> m_fetchStationsTask = nullptr;
};

}
