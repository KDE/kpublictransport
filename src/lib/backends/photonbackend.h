/*
    SPDX-FileCopyrightText: 2026 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_PHOTONBACKEND_H
#define KPUBLICTRANSPORT_PHOTONBACKEND_H

#include "abstractbackend.h"

namespace KPublicTransport {
class PhotonBackend : public AbstractBackend
{
    Q_GADGET

    Q_PROPERTY(QUrl url MEMBER m_url)

public:
    static constexpr const char *type() { return "photon"; }

    [[nodiscard]] Capabilities capabilities() const override;
    [[nodiscard]] bool queryLocation(const LocationRequest &request,
                                     LocationReply *reply,
                                     QNetworkAccessManager *nam) const override;
    [[nodiscard]] Location::Types supportedLocationTypes() const override;

private:
    QUrl m_url;
};
} // namespace KPublicTransport

#endif // KPUBLICTRANSPORT_PHOTONBACKEND_H
