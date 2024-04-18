/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_MOTISBACKEND_H
#define KPUBLICTRANSPORT_MOTISBACKEND_H

#include "abstractbackend.h"

#include <QUrl>

class QNetworkRequest;

namespace KPublicTransport {

class IndividualTransport;
class MotisPathQueryTask;

/** Backend for Motis-based providers. */
class MotisBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QUrl endpoint MEMBER m_endpoint)
    Q_PROPERTY(QString locationIdentifierType MEMBER m_locationIdentifierType)
    /** Intermodal journey modes supported by this instance
     *  Defaults to @c true.
     */
    Q_PROPERTY(QStringList supportedModes MEMBER m_supportedModes)

public:
    explicit MotisBackend();
    ~MotisBackend() override;

    static inline constexpr const char* type() { return "motis"; }
    [[nodiscard]] Capabilities capabilities() const override;
    [[nodiscard]] bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    [[nodiscard]] bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const override;

private:
    friend class MotisPathQueryTask;

    template <typename Request>
    QNetworkReply* makeRequest(const Request &req, QObject *parent, const QJsonObject &query, QNetworkAccessManager *nam) const;

    /** Convert QDateTime to the MOTIS time format. */
    [[nodiscard]] static qint64 encodeTime(const QDateTime &dt);
    /** Generate intermodal journey request arguments. */
    [[nodiscard]] QJsonArray ivModes(const std::vector<IndividualTransport> &ivs) const;

    QUrl m_endpoint;
    QString m_locationIdentifierType;
    QStringList m_supportedModes;
};

}

#endif
