/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_EFABACKEND_H
#define KPUBLICTRANSPORT_EFABACKEND_H

#include "abstractbackend.h"

#include <memory>

class QUrlQuery;

namespace KPublicTransport {

class EfaParser;

/** Backend for EFA public transport systems. */
class EfaBackend : public AbstractBackend
{
    Q_GADGET
    /** Base URL for EFA API calls. */
    Q_PROPERTY(QString endpoint MEMBER m_endpoint)
    /** Identifier type used for stations. Default is backendId(). */
    Q_PROPERTY(QString locationIdentifierType MEMBER m_locationIdentifierType)
    /** Backend is using compact XML responses. */
    Q_PROPERTY(bool compactXmlRepsonse MEMBER  m_compactXmlResponse)

    /** Additional "mId" argument value, needed by some instances. */
    Q_PROPERTY(QString mId MEMBER m_mId)

    /** Override for commands send to the server.
     *  Defaults are usually fine, only change this for bizarre backends.
     */
    Q_PROPERTY(QString stopfinderRequestCommand MEMBER m_stopfinderRequestCommand)
    Q_PROPERTY(QString dmRequestCommand MEMBER m_dmRequestCommand)
    Q_PROPERTY(QString tripRequestCommand MEMBER m_tripRequestCommand)

public:
    EfaBackend();
    ~EfaBackend();

    static inline constexpr const char* type() { return "efa"; }
    Capabilities capabilities() const override;
    bool needsLocationQuery(const Location  &loc, AbstractBackend::QueryType type) const override;
    bool queryLocation(const LocationRequest &request, LocationReply *reply, QNetworkAccessManager *nam) const override;
    bool queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    bool queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const override;

private:
    QString locationIdentifierType() const;
    std::unique_ptr<EfaParser> make_parser() const;
    QUrlQuery commonQuery() const;

    QString m_endpoint;
    QString m_locationIdentifierType;
    bool m_compactXmlResponse = false;

    QString m_mId;
    QString m_stopfinderRequestCommand;
    QString m_dmRequestCommand;
    QString m_tripRequestCommand;
};

}

#endif // KPUBLICTRANSPORT_EFABACKEND_H
