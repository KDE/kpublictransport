/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFSBACKEND_H
#define KPUBLICTRANSPORT_GBFSBACKEND_H

#include <backends/abstractbackend.h>

namespace KPublicTransport {

/** Generic GBFS backend.
 *  This only supports "location" searches, which is the way to find docks and floating vehicles.
 */
class GBFSBackend : public AbstractBackend
{
    Q_GADGET
public:
    explicit GBFSBackend();
    ~GBFSBackend() override;

    static  constexpr const char* type() { return "gbfs"; }
    [[nodiscard]] Capabilities capabilities() const override;
    [[nodiscard]] Location::Types supportedLocationTypes() const override;
    [[nodiscard]] bool queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const override;

private:
};

}

#endif // KPUBLICTRANSPORT_GBFSBACKEND_H
