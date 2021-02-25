/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_IVVASSBACKEND_H
#define KPUBLICTRANSPORT_IVVASSBACKEND_H

#include "abstractbackend.h"

namespace KPublicTransport {

/** Backend for IVV AuskunftServiceSystem (ASS) based providers. */
class IvvAssBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QUrl endpoint MEMBER m_endpoint)

public:
    static inline constexpr const char* type() { return "ivvass"; }

    Capabilities capabilities() const override;
    bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;
    bool queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    bool queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const override;

private:
    QUrl m_endpoint;
};

}

#endif // KPUBLICTRANSPORT_IVVASSBACKEND_H
