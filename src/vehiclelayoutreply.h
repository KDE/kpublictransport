/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef KPUBLICTRANSPORT_VEHICLELAYOUTREPLY_H
#define KPUBLICTRANSPORT_VEHICLELAYOUTREPLY_H

#include "reply.h"

namespace KPublicTransport {

class AbstractBackend;
class Departure;
class Platform;
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

    /** Vehicle layout information found by this query. */
    Vehicle vehicle() const;
    /** Platform layout information found by this query. */
    Platform platoform() const;
    /** Departure information the layout is valid for. */
    Departure departure() const;

private:
    friend class Manager;
    friend class ManagerPrivate;
    explicit VehicleLayoutReply(const VehicleLayoutRequest &req, QObject *parent = nullptr);

    friend class AbstractBackend;
    Q_DECL_HIDDEN void addResult(const Vehicle &vehicle, const Platform &platoform, const Departure &departure);
    using Reply::addError;
    Q_DECL_HIDDEN void addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg);

    Q_DECLARE_PRIVATE(VehicleLayoutReply)
};

}

#endif // KPUBLICTRANSPORT_VEHICLELAYOUTREPLY_H
