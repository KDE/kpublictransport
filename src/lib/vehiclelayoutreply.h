/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_VEHICLELAYOUTREPLY_H
#define KPUBLICTRANSPORT_VEHICLELAYOUTREPLY_H

#include "reply.h"

namespace KPublicTransport {

class AbstractBackend;
class Platform;
class Stopover;
class Vehicle;
class VehicleLayoutRequest;
class VehicleLayoutReplyPrivate;

/** Reply to a vehicle layout query. */
class KPUBLICTRANSPORT_EXPORT VehicleLayoutReply : public Reply
{
    Q_OBJECT
public:
    ~VehicleLayoutReply();

    /** The request this is the reply for. */
    VehicleLayoutRequest request() const;

    /** The requested Stopover information, including the vehicle and platform layout. */
    Stopover stopover() const;

private:
    friend class Manager;
    friend class ManagerPrivate;
    explicit VehicleLayoutReply(const VehicleLayoutRequest &req, QObject *parent = nullptr);

    friend class AbstractBackend;
    Q_DECL_HIDDEN void addResult(const Stopover &stopover);
    using Reply::addError;
    Q_DECL_HIDDEN void addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg);

    Q_DECLARE_PRIVATE(VehicleLayoutReply)
};

}

#endif // KPUBLICTRANSPORT_VEHICLELAYOUTREPLY_H
