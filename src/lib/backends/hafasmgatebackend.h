/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_HAFASMGATEBACKEND_H
#define KPUBLICTRANSPORT_HAFASMGATEBACKEND_H

#include "hafasbackend.h"
#include "hafasmgateparser.h"

#include <QString>

class QJsonObject;
class QNetworkReply;

namespace KPublicTransport {

class LocationRequest;

/** Backend for the Hafas mgate.exe interface. */
class HafasMgateBackend : public HafasBackend
{
    Q_GADGET
    /** The auth data block in every request. */
    Q_PROPERTY(QJsonObject auth WRITE setAuthObject)
    /** The client data sent in every request. */
    Q_PROPERTY(QJsonObject client MEMBER m_client)
    Q_PROPERTY(QString ext MEMBER m_extParam)
    Q_PROPERTY(QString ver MEMBER m_version)
    /** Salt for request mic/mac parameters, hex-encoded. */
    Q_PROPERTY(QString micMacSalt WRITE setMicMacSalt)
    /** Salt for the request checksum parameter, hex-encoded. */
    Q_PROPERTY(QString checksumSalt WRITE setChecksumSalt)
    /** Supports the stbFltrEquiv parameter for departure queries (default @c true). */
    Q_PROPERTY(bool supportsStbFltrEquiv MEMBER m_supportsStbFltrEquiv)

public:
    HafasMgateBackend();
    ~HafasMgateBackend();

    void init() override;
    static inline constexpr const char* type() { return "hafasMgate"; }
    Capabilities capabilities() const override;
    bool needsLocationQuery(const Location &loc, AbstractBackend::QueryType type) const override;
    bool queryJourney(const JourneyRequest &request, JourneyReply *reply, QNetworkAccessManager *nam) const override;
    bool queryStopover(const StopoverRequest &request, StopoverReply *reply, QNetworkAccessManager *nam) const override;
    bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;

private:
    QNetworkRequest makePostRequest(const QJsonObject &svcReq, QByteArray &postData) const;
    bool queryJourney(JourneyReply *reply, const QString &fromId, QNetworkAccessManager *nam) const;
    bool queryJourney(JourneyReply *reply, const QString &fromId, const QString &toId, QNetworkAccessManager *nam) const;
    void setAuthObject(const QJsonObject &obj);
    void setMicMacSalt(const QString &salt);
    void setChecksumSalt(const QString &salt);
    QJsonObject locationToJson(const Location &loc) const;

    mutable HafasMgateParser m_parser;

    QJsonObject m_auth;
    QJsonObject m_client;
    QString m_extParam;
    QString m_version;
    QByteArray m_micMacSalt;
    QByteArray m_checksumSalt;
    bool m_supportsStbFltrEquiv = true;
};

}

#endif // KPUBLICTRANSPORT_HAFASMGATEBACKEND_H
