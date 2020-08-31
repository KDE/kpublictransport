/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_NAVITIABACKEND_H
#define KPUBLICTRANSPORT_NAVITIABACKEND_H

#include "abstractbackend.h"

#include <QString>

class QNetworkReply;

namespace KPublicTransport {

class LocationRequest;

/** Backend for Navitia-based providers. */
class NavitiaBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QString endpoint MEMBER m_endpoint)
    Q_PROPERTY(QString coverage MEMBER m_coverage)
    Q_PROPERTY(QString authorization MEMBER m_auth)

public:
    NavitiaBackend();

    static inline constexpr const char* type() { return "navitia"; }
    Capabilities capabilities() const override;
    bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    bool queryJourney(const JourneyRequest &req, JourneyReply *reply, QNetworkAccessManager *nam) const override;
    bool queryStopover(const StopoverRequest &req, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;

private:
    QString m_endpoint;
    QString m_coverage;
    QString m_auth;
};

}

#endif // KPUBLICTRANSPORT_NAVITIABACKEND_H
