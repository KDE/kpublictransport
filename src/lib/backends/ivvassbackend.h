/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_IVVASSBACKEND_H
#define KPUBLICTRANSPORT_IVVASSBACKEND_H

#include "abstractbackend.h"
#include <QUrl>

namespace KPublicTransport {

/** Backend for IVV AuskunftServiceSystem (ASS) based providers. */
class IvvAssBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QUrl endpoint MEMBER m_endpoint)
    Q_PROPERTY(QJsonObject extraArguments MEMBER m_extraArgs)

public:
    [[nodiscard]] static inline constexpr const char* type() { return "ivvass"; }

    [[nodiscard]] Capabilities capabilities() const override;
    [[nodiscard]] bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    [[nodiscard]] bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    [[nodiscard]] bool queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const override;

private:
    QNetworkRequest makeRequest(QUrlQuery &&query) const;

    QUrl m_endpoint;
    QJsonObject m_extraArgs;
};

}

#endif // KPUBLICTRANSPORT_IVVASSBACKEND_H
