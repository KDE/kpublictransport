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

/** Backend for Motis-based providers. */
class MotisBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QUrl endpoint MEMBER m_endpoint)
    Q_PROPERTY(QString locationIdentifierType MEMBER m_locationIdentifierType)
    /** Intermodal journey search is functional on this instance.
     *  Defaults to @c true.
     */
    Q_PROPERTY(bool intermodal MEMBER m_intermodal)

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
    template <typename Request>
    QNetworkReply* makeRequest(const Request &req, Reply *reply, const QJsonObject &query, QNetworkAccessManager *nam) const;

    QUrl m_endpoint;
    QString m_locationIdentifierType;
    bool m_intermodal = true;
};

}

#endif
