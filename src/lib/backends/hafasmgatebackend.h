/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_HAFASMGATEBACKEND_H
#define KPUBLICTRANSPORT_HAFASMGATEBACKEND_H

#include "kpublictransport_export.h"

#include "hafasbackend.h"
#include "hafasmgateparser.h"

#include <KPublicTransport/IndividualTransport>

#include <QString>

class QJsonArray;
class QJsonObject;

namespace KPublicTransport {

class LocationRequest;

/** Backend for the Hafas mgate.exe interface.
 *  @internal exported for tooling only
 */
class KPUBLICTRANSPORT_EXPORT HafasMgateBackend : public HafasBackend
{
    Q_GADGET
    /** The auth data block in every request. */
    Q_PROPERTY(QJsonObject auth MEMBER m_auth)
    /** The client data sent in every request. */
    Q_PROPERTY(QJsonObject client MEMBER m_client)
    Q_PROPERTY(QString ext MEMBER m_extParam)
    Q_PROPERTY(QString ver MEMBER m_version)
    /** Salt for request mic/mac parameters, hex-encoded. */
    Q_PROPERTY(QString micMacSalt WRITE setMicMacSalt)
    /** Salt for the request checksum parameter, hex-encoded. */
    Q_PROPERTY(QString checksumSalt WRITE setChecksumSalt)

    /** Supported journey filter conGroup arguments and their corresponding mapping to
     *  our transport modes.
     */
    Q_PROPERTY(QJsonArray conGroups WRITE setConGroups)

    /** Products (as numerical Hafas ids) for which we should prefer the line number over the line name.
     *  This is useful to strip non-canonical prefixes.
     */
    Q_PROPERTY(QJsonArray preferLineNumberProducts WRITE setPreferLineNumberProducts)

public:
    HafasMgateBackend();
    ~HafasMgateBackend() override;

    void init() override;
    static inline constexpr const char* type() { return "hafasMgate"; }
    Capabilities capabilities() const override;
    bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    bool queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const override;
    bool queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;

    QNetworkRequest makePostRequest(const QJsonObject &svcReq, QByteArray &postData) const;

private:
    bool queryJourney(JourneyReply *reply, const QString &fromId, QNetworkAccessManager *nam) const;
    bool queryJourney(JourneyReply *reply, const QString &fromId, const QString &toId, QNetworkAccessManager *nam) const;
    void setMicMacSalt(const QString &salt);
    void setChecksumSalt(const QString &salt);
    void setConGroups(const QJsonArray &conGroups);
    void setPreferLineNumberProducts(const QJsonArray &lineNumberProduducts);
    QJsonObject locationToJson(const Location &loc) const;

    mutable HafasMgateParser m_parser;

    QJsonObject m_auth;
    QJsonObject m_client;
    QString m_extParam;
    QString m_version;
    QByteArray m_micMacSalt;
    QByteArray m_checksumSalt;

    struct ConGroup {
        IndividualTransport access;
        IndividualTransport egress;
        QString group;
    };
    std::vector<ConGroup> m_conGroups;
    std::vector<int> m_lineNumberProducts;
};

}

#endif // KPUBLICTRANSPORT_HAFASMGATEBACKEND_H
