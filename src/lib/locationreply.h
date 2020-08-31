/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LOCATIONREPLY_H
#define KPUBLICTRANSPORT_LOCATIONREPLY_H

#include "reply.h"

#include <vector>

namespace KPublicTransport {

class AbstractBackend;
class Location;
class LocationRequest;
class LocationReplyPrivate;

/** Location query reply. */
class KPUBLICTRANSPORT_EXPORT LocationReply : public Reply
{
    Q_OBJECT
public:
    ~LocationReply();

    /** The request this is the reply for. */
    LocationRequest request() const;

    /** Returns the found locations. */
    const std::vector<Location>& result() const;
    /** Returns the found locations for moving elsewhere. */
    std::vector<Location>&& takeResult();

private:
    friend class Manager;
    friend class ManagerPrivate;
    explicit LocationReply(const LocationRequest &req, QObject *parent = nullptr);

    friend class AbstractBackend;
    Q_DECL_HIDDEN void addResult(std::vector<Location> &&res);
    using Reply::addError;
    Q_DECL_HIDDEN void addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg);


    Q_DECLARE_PRIVATE(LocationReply)
};

}

#endif // KPUBLICTRANSPORT_LOCATIONREPLY_H
