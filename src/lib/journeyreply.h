/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
    ~JourneyReply() override;

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
    /** Returns a request object for querying journeys preceding the ones returned by this reply.
     *  The returned request is empty if querying earlier journeys is not possible/supported.
     */
    JourneyRequest previousRequest() const;

private:
    friend class Manager;
    friend class ManagerPrivate;
    explicit JourneyReply(const JourneyRequest &req, QObject *parent = nullptr);

    friend class AbstractBackend;
    Q_DECL_HIDDEN void addResult(const AbstractBackend *backend, std::vector<Journey> &&res);
    using Reply::addError;
    Q_DECL_HIDDEN void addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg);

    Q_DECL_HIDDEN void setNextContext(const AbstractBackend *backend, const QVariant &data);
    Q_DECL_HIDDEN void setPreviousContext(const AbstractBackend *backend, const QVariant &data);

    Q_DECLARE_PRIVATE(JourneyReply)
};

}

#endif // KPUBLICTRANSPORT_JOURNEYREPLY_H
