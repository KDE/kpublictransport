/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_ACCESSIBILITYCLOUDBACKEND_H
#define KPUBLICTRANSPORT_ACCESSIBILITYCLOUDBACKEND_H

#include "abstractbackend.h"

namespace KPublicTransport {

/** Backend for querying equipment status from accessibility.cloud. */
class AccessibilityCloudBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QString token MEMBER m_token)
public:
    explicit AccessibilityCloudBackend();
    ~AccessibilityCloudBackend();

    static inline constexpr const char* type() { return "a11y_cloud"; }
    Capabilities capabilities() const override;
    bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;

private:
    QString m_token;
};

}

#endif // KPUBLICTRANSPORT_ACCESSIBILITYCLOUDBACKEND_H
