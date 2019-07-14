/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_JOURNEYREPLY_H
#define KPUBLICTRANSPORT_JOURNEYREPLY_H

#include "reply.h"

#include <vector>

namespace KPublicTransport {

class Journey;
class JourneyReplyPrivate;
class JourneyRequest;

/** Journey query response. */
class KPUBLICTRANSPORT_EXPORT JourneyReply : public Reply
{
    Q_OBJECT
public:
    ~JourneyReply();

    /** The request this is the reply for. */
    JourneyRequest request() const;

    /** Returns the retrieved journeys. */
    const std::vector<Journey>& result() const;
    /** Returns the retrieved journeys for moving elsewhere. */
    std::vector<Journey>&& takeResult();

    /** Returns a request object for querying journeys following the ones returned by this reply.
     *  The returned request is empty if querying later journeys is not possible/supported.
     */
    JourneyRequest nextRequest() const;
    /** Returns a request object for querying journeys preceeding the ones returned by this reply.
     *  The returned request is empty if querying earlier journeys is not possible/supported.
     */
    JourneyRequest previousRequest() const;

private:
    friend class ManagerPrivate;
    explicit JourneyReply(const JourneyRequest &req, QObject *parent = nullptr);

    friend class AbstractBackend;
    void addResult(const AbstractBackend *backend, std::vector<Journey> &&res);

    Q_DECL_HIDDEN void setNextContext(const AbstractBackend *backend, const QVariant &data);
    Q_DECL_HIDDEN void setPreviousContext(const AbstractBackend *backend, const QVariant &data);

    Q_DECLARE_PRIVATE(JourneyReply)
};

}

#endif // KPUBLICTRANSPORT_JOURNEYREPLY_H
